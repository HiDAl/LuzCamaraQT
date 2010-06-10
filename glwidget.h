

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const ;
    QSize sizeHint() const ;

public slots:
    void rePaint();

signals:
    void rePainted();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    double rot;
};

#endif // GLWIDGET_H
