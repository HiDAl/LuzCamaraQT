#include <QtGui>
#include <QtOpenGL>
#include <iostream>

using namespace std;

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    rot = 0.0;
    qTime.start();
    lastTime = qTime.elapsed();
    c.setRotation(QVector3D(0, 0.5, 1));
}

GLWidget::~GLWidget(){

}

QSize GLWidget::minimumSizeHint() const { return QSize(100,100); };
QSize GLWidget::sizeHint() const { return QSize(400, 400); };

void GLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);						// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
    glClearDepth(1.0f);							// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);						// The Type Of Depth Testing To Do
    glEnable ( GL_COLOR_MATERIAL );
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    resizeGL(this->width(), this->height());
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();

    c.draw(rot);

    rot += (rot > 360.0)  ? -360.0 : 45*(qTime.elapsed() - lastTime + 1) / 1000.0;

    lastTime = qTime.elapsed();
    QTimer::singleShot(100, this, SLOT(repaint()));
}

void GLWidget::resizeGL(int width, int height)
{
    glViewport(0,0,width,height);	// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);	// Select The Projection Matrix
    glLoadIdentity();		// Reset The Projection Matrix

    // Calculate The Aspect Ratio Of The Window
    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);     // Select The Modelview Matrix
    glLoadIdentity();
}
