

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTime>

#include "cubo.h"


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

private:
    double rot;
    QTime qTime;
    int lastTime;
    Cubo c;
};

#endif // GLWIDGET_H
