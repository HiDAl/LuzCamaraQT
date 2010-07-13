#include <QtGui>
#include <QtOpenGL>
#include <iostream>

using namespace std;

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    rot = 0.0;
    wireFrame = false;
    qTime.start();
    lastTime = qTime.elapsed();

    repo = RepositorioObjetos::instance();

}

GLWidget::~GLWidget(){
}

QSize GLWidget::minimumSizeHint() const { return QSize(100,100); };
QSize GLWidget::sizeHint() const { return QSize(800,800); };

void GLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);						// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
    glClearDepth(1.0f);							// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);						// The Type Of Depth Testing To Do
    glEnable(GL_COLOR_MATERIAL );
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glEnable(GL_LIGHTING);

    glCullFace(GL_BACK); //No dibujamos las caras traseras

    glEnable(GL_CULL_FACE);

    resizeGL(this->width(), this->height());
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
    glLoadIdentity();
    QMap<QString, Objeto*>::const_iterator i = repo->constBegin();

    while(i != repo->constEnd()){
        if(i.value()->getWired())
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        else
            glPolygonMode(GL_FRONT, GL_FILL);

        i.value()->draw((qTime.elapsed() - lastTime + 1)/1000.0);

        ++i;
    }

    lastTime = qTime.elapsed();
    QTimer::singleShot(1000/21, this, SLOT(repaint()));
}

void GLWidget::resizeGL(int width, int height)
{

    glViewport(0,0,width,height);	// Reset The Current Viewport
/*
    glMatrixMode(GL_PROJECTION);	// Select The Projection Matrix
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();*/

    glClearDepth(1.0);
    glDepthFunc(GL_LEQUAL);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, width/height   , 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt( 0.0f, 0.0f, 3.0f, //Desde donde miro
               0.0f, 0.0f, 0.0f,  //Hacia donde miro.
               0.0f, 1.0f, 0.0f   //Hacia arriba
                         );
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    setFocus(Qt::MouseFocusReason);
}

void GLWidget::setWireFrame(bool val)
{
    wireFrame = val;

    RepositorioObjetos::instance()->getSelected()->setWired(val);
}
