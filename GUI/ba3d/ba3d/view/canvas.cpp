// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/model/canvas.cpp
//! @brief     Implements Canvas class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "canvas.h"
#include "buffer.h"
#include "camera.h"
#include "program.h"
#include "../model/geometry.h"
#include "../model/model.h"

#include <QMouseEvent>
#include <qmath.h>

namespace ba3d {
//------------------------------------------------------------------------------

Canvas::Canvas()
: aspectRatio(1), colorBgR(1), colorBgG(1), colorBgB(1)
, camera(nullptr), program(nullptr), model(nullptr) {
  connect(&geometryStore(), &GeometryStore::deletingGeometry,
          this, &Canvas::releaseBuffer);
}

Canvas::~Canvas() {
  releaseBuffers();
}

void Canvas::setBgColor(QColor const& c) {
  colorBgR = float(c.redF());
  colorBgG = float(c.greenF());
  colorBgB = float(c.blueF());
  update();
}

void Canvas::setCamera(Camera* c) {
  camera = c;
  setCamera();
}

void Canvas::setProgram(Program* p) {
  program = p;
  if (program)
    program->needsInit();
  update();
}

void Canvas::setModel(Model* m) {
  releaseBuffers();

  disconnect(modelUpdated);
  model = m;
  modelUpdated = connect(model, &Model::updated, [this](bool withEye) {
    if (withEye)
      setCamera();
    else
      update();
  });

  setCamera();
}

Model* Canvas::getModel() {
  return model;
}

void Canvas::setCamera(bool full) {
  if (camera) {
    camera->setAspectRatio(aspectRatio);
    if (full && model)
      camera->lookAt(model->defCamPos);
  }

  update();
}

void Canvas::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
}

void Canvas::resizeGL(int w, int h) {
  int w1 = qMax(1, w), h1 = qMax(1, h);
  viewport.setRect(0, 0, w1, h1);
  aspectRatio = float(w1) / float(h1);
  setCamera(false);
}

void Canvas::paintGL() {
  glClearColor(colorBgR, colorBgG, colorBgB, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  if (camera && program && model) {
    program->init();
    program->bind();
    program->set(*camera);

    // opaque objects
    model->draw(*this);

    // transparent objects
    glEnable(GL_BLEND); glDepthMask(false);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    model->drawBlend(*this);
    glDisable(GL_BLEND); glDepthMask(true);

    program->release();
  }
}

QVector3D Canvas::unproject(QPoint const& p) {
  float x = p.x(), y = viewport.height() - p.y();
  return QVector3D(x, y, 1).unproject(matModel, matProj, viewport);
}

void Canvas::mousePressEvent(QMouseEvent* e) {
  switch (e->button())  {
  case Qt::LeftButton:
    mouseButton = btnTURN;
    break;
  case Qt::RightButton:
    mouseButton = btnZOOM;
    break;
  default:
    mouseButton = btnNONE;
    break;
  }

  if (camera) {
    matModel = camera->matModel;
    matProj  = camera->matProj;
    lastV    = unproject(e->pos());
    lastY    = e->y();
  }
}

void Canvas::mouseMoveEvent(QMouseEvent* e) {
  if (camera) {
    auto v = unproject(e->pos());
    switch (mouseButton) {
    case btnTURN:
      camera->turnBy(QQuaternion::rotationTo(v, lastV));
      break;
    case btnZOOM: {
      float d = (e->y() - lastY) / float(viewport.height());
      camera->zoomBy(1+d);
      break;
    }
    default:
      break;
    }

    update();
  }
}

void Canvas::mouseReleaseEvent(QMouseEvent*) {
  if (camera) {
    camera->endTransform(true);
    update();
  }
}

void Canvas::releaseBuffer(Geometry const* g) {
  delete buffers.take(g);
}

void Canvas::releaseBuffers() {
  for (auto b: buffers.values())
    delete b;
  buffers.clear();
}

void Canvas::draw(QColor const& color, QMatrix4x4 const& mat, Geometry const& geo) {
  auto it = buffers.find(&geo);
  Buffer* buf;
  if (buffers.end() == it)
    buffers.insert(&geo, buf = new Buffer(geo));  // created on demand
  else
    buf = *it;

  Q_ASSERT(program);
  program->set(color);
  program->set(mat);
  buf->draw();
}

//------------------------------------------------------------------------------
}
