

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTime>

#include "cubo.h"
#include "esfera.h"
#include "luz.h"
#include "repositorioobjetos.h"


class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const ;
    QSize sizeHint() const ;

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);

private:
    double rot;
    bool wireFrame;
    QTime qTime;
    int lastTime;
    RepositorioObjetos *repo;

private slots:
    void setWireFrame(bool val);
};

#endif // GLWIDGET_H
