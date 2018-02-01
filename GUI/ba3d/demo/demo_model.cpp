// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/demo/demo_model.cpp
//! @brief     Implements DemoModel class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "demo_model.h"
#include <ba3d/model/layer.h>
#include <QApplication>
#include <thread>
#include <qmath.h>

//------------------------------------------------------------------------------

using namespace ba3d;

DemoModel::DemoModel() {
  setCameraSide();
}

void DemoModel::switchBack() {
  switch (back) {
  case backNONE:
    addSubstrate(); back = backSUBSTRATE;
    break;
  case backSUBSTRATE:
    addLayer(); back = backLAYER;
    break;
  case backLAYER:
    super::clearBlend(); back = backNONE;
    break;
  }

  snooze(false);
}

void DemoModel::switchFront() {
  switch (front) {
  case frontNONE:
    one(); front = frontONE;
    break;
  case frontONE:
    super::clearOpaque(); kind = ba3d::particle::kind::None;
    front = frontSQUARELOW; szSample = 400; square(0);
    break;
  case frontSQUARELOW:
    super::clearOpaque(); ps.clear(); kind = ba3d::particle::kind::None;
    front = frontSQUAREHIGH; szSample = 800; square(0);
    break;
  case frontSQUAREHIGH:
    super::clearOpaque(); ps.clear(); kind = ba3d::particle::kind::None;
    front = frontSQUAREINSANE; szSample = 2000; square(0);
    break;
  case frontSQUAREINSANE:
    super::clearOpaque(); ps.clear(); front = frontNONE;
    break;
  }

  snooze(false);
}

void DemoModel::switchOne() {
  if (frontONE == front)
    one();
}

void DemoModel::square(float sigma) {
  if (frontSQUARELOW != front && frontSQUAREHIGH != front && frontSQUAREINSANE != front)
    return;

  uint n = qFloor(szSample / spacing / 2 - 1);
  auto mesh = squareLattice(n, sigma);
  for (auto& m: mesh)
    m = m  * spacing + xyz(0, 0, -20);

  if (ps.empty()) { // first time - init
    ps.resize(mesh.count());
    for (auto& p: ps) {
      add((p = new particle::TruncatedSphere(R, R)));
      p->color = QColor(170, 0, 0);
#ifdef Q_OS_OSX
      p->color = QColor(70, 0, 0);
#endif
    }
    activeMesh.clear();
  }

  Q_ASSERT(ps.count() == mesh.count());

  if (activeMesh.empty()) {
    activeMesh = mesh;
    for (uint i=0; i < uint(ps.count()); ++i)
      ps.at(i)->transform(xyz::_0, activeMesh.at(i));

    int const steps = 20;
    for(int s=0; s < steps + 1; ++s) {
      for (uint i=0; i < uint(ps.count()); ++i)
        ps.at(i)->fancy(xyz::_0, float(s) / steps);
      snooze(false);
    }
  } else {
    // back
    auto home = squareLattice(n, 0), from = activeMesh;
    for (auto& m: home)
      m = m  * spacing + xyz(0, 0, -20);
    int const steps = 30;
    for(int s=0; s < steps + 1; ++s) {
      for (uint i=0; i < uint(ps.count()); ++i)
        ps.at(i)->transform(xyz::_0, from.at(i).interpolateTo(home.at(i), float(s)/steps));
      snooze(false);
    }

    activeMesh = home;

    float const step = .2; bool go = true;
    while (go) {
      go = false;
      for (uint i=0; i < uint(ps.count()); ++i) {
        auto& p = ps.at(i);
        auto& newPos = mesh.at(i);
        auto& pos = activeMesh[i];
        auto np = pos + (newPos - pos).normalized() * step;
        // neigbours
        auto hasSpace = [&](int xi, int yi) -> bool {
          int n = activeMesh.n;
          if (xi < -n || n <= xi || yi < -n || n <= yi)
            return true;
          auto p = activeMesh.at(activeMesh.index(xi,yi));
          return (np-p).length() > 2*R;
        };

        int xi = activeMesh.ix(i), yi = activeMesh.iy(i);
        if (hasSpace(xi-1, yi-1) && hasSpace(xi-1, yi-0) && hasSpace(xi-1, yi+1)
         && hasSpace(xi+1, yi-1) && hasSpace(xi+1, yi-0) && hasSpace(xi+1, yi+1)
         && hasSpace(xi-0, yi-1) && hasSpace(xi-0, yi+1)
         && (newPos - np).length() > step*1.001) {
            go = true;
            pos = np;
            p->transform(xyz::_0, pos);
        }
      }

      snooze(false);
    }
  }

  snooze(false);
}

void DemoModel::one() {
  using eKind = ba3d::particle::kind;
  if (kind != eKind::None)
    oneOut();
  if (kind == eKind::AnisoPyramid)
    kind = eKind::None;
  else
    oneIn((kind = eKind(int(kind) + 1)));
}

void DemoModel::oneOut() {
  int const steps = 40;
  for(int i=0; i<steps+1; ++i) {
    float a = 360.f / steps * i / 3;
    p->fancy(xyz(a, a, a), float(steps-i) / steps);
    snooze(false);
  }
  rem(p);
}

void DemoModel::oneIn(particle::kind kind) {
  add((p = newParticle(kind, R)));
#ifdef Q_OS_OSX
  p->color = QColor(70,0,0);
#endif
  p->transform(xyz::_0, xyz(0, 0, -hgtLayer));

  int const steps = 140;
  for(int i=0; i<steps+1; ++i) {
    float a = 360.f / steps * i;
    p->fancy(xyz(a*2, a, a), float(i) / steps);
    snooze(false);
  }
}

void DemoModel::setCameraTop(bool animate) {
  setCamera(Camera::pos_t(xyz(0, 0, szSample), xyz(0, 0, -20), xyz::_y), animate);
}

void DemoModel::setCameraSide(bool animate) {
  setCamera(Camera::pos_t(xyz(-10, -szSample*1.1, 2*hgtLayer), xyz(0, 0, -20), xyz::_z), animate);
}

void DemoModel::setCameraOne(bool animate) {
  setCamera(Camera::pos_t(xyz(0, 0, spacing), xyz(0, 0, -20), xyz::_y), animate);
}

void DemoModel::setCamera(Camera::pos_t::rc to, bool animate) {
  if (animate) {
    auto from = camPos;

    int const frames = 45;
    for(int i=0; i<frames+1; ++i) {
      defCamPos = from.interpolateTo(to, float(i) / frames);
      snooze(true);
    }
  } else {
    defCamPos = to;
    snooze(true);
  }
}

void DemoModel::cameraUpdated(DemoModel::Camera const& cam) {
  camPos = cam.getPos();
}

void DemoModel::addSubstrate() {
  QColor clr = Qt::lightGray;
  addLayer(dr(-hgtLayer, -hgtLayer - hgtSubstrate), clr);
}

void DemoModel::addLayer() {
  QColor clr = QColor(0, 100, 0);
  addLayer(dr(0, -hgtLayer), clr);
}

void DemoModel::addLayer(dr z, QColor clr) {
  float s2 = szSample / 2;
  auto l = new Layer(dxyz(dr(-s2,+s2), dr(-s2,+s2), z));
  clr.setAlphaF(.3);
  l->color = clr;
  addBlend(l);
}

void DemoModel::snooze(bool withEye) {
  emit updated(withEye);
  qApp->processEvents();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
}

//------------------------------------------------------------------------------
