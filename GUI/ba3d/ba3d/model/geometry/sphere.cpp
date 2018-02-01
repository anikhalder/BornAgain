// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/model/geometry/sphere.cpp
//! @brief     Implements utility functions in ba3d namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "../geometry.h"
#include <qmath.h>

namespace ba3d {
//------------------------------------------------------------------------------

// cut: 0..1 - how much is cut off off the bottom
Geometry::mesh_t Geometry::meshSphere(float cut) {
  if (1 <= cut)
    return mesh_t();
  cut = qMax(0.f, cut);
  Q_ASSERT(0 <= cut && cut < 1);

  // 'rings' is 1 less than actual rings (due to poles)
  int rings, slices = SLICES;
  float minPh, phRge;

  if (cut > 0) {
    minPh = asinf(2*cut - 1);
    phRge = float(M_PI_2) - minPh;
    rings = qMax(1, qCeil(qreal(RINGS * phRge) / M_PI));
  } else {
    rings = RINGS - 1;
    minPh = float(M_PI) / rings - float(M_PI_2);
    phRge = float(M_PI_2) - minPh;
  }

  Q_ASSERT(qAbs(minPh) < float(M_PI_2));
  Q_ASSERT(1 <= rings && 2 <= slices);

  // meshes of vertices and normals, without poles, _[ring][slice]
  QVector<xyz_vec> vs_(rings), ns_(rings);
  for (auto& ring: vs_)
    ring.resize(slices);
  for (auto& ring: ns_)
    ring.resize(slices);

  float const R = .5f;

  for(int r=0; r < rings; ++r) {
    float ph = minPh + phRge * r/rings;
    float cp = cosf(ph), sp = sinf(ph);

    for(int s=0; s < slices; ++s) {
      float th = float(2*M_PI*s/slices);
      xyz v(R*cp*cosf(th), R*cp*sinf(th), R*sp);
      vs_[r][s] = v;
      ns_[r][s] = v.normalized();
    }
  }

  // make into triangles
  int const nv = 6*(rings)*slices;
  xyz_vec vs; vs.reserve(nv);
  xyz_vec ns; ns.reserve(nv);

  for(int r=0; r < rings; ++r) {
    auto &vr = vs_.at(r), &nr = ns_.at(r);

    for(int s=0; s < slices; ++s) {
      int s0 = s, s1 = (s+1) % slices;

      auto &v0 = vr.at(s0), &v1 = vr.at(s1);
      auto &n0 = nr.at(s0), &n1 = nr.at(s1);

      if (r == 0) { // south pole
        xyz vp, n0, n1, np(-xyz::_z);
        if (cut > 0) {
          vp = xyz(0, 0, v0.z);
          n0 = n1 = np;
        } else {
          vp = xyz(0,0,-R);
          n0 = nr.at(s0); n1 = nr.at(s1);
        }
        vs.addTrig(v0, vp, v1);
        ns.addTrig(n0, np, n1);
      }

      if (r+1 == rings) {  // north pole
        xyz vp(0, 0, +R), np(xyz::_z);
        vs.addTrig(v0, v1, vp);
        ns.addTrig(n0, n1, np);
      } else if (1 < rings) { // in between poles
        auto &vr1 = vs_.at(r+1), &nr1 = ns_.at(r+1);
        auto &n2 = nr1.at(s1), &n3 = nr1.at(s0);
        vs.addQuad(v0, v1, vr1.at(s1), vr1.at(s0));
        ns.addQuad(n0, n1, n2, n3);
      }
    }
  }

  return makeMesh(vs, ns);
}

//------------------------------------------------------------------------------
}
