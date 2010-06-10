
#include <QVector3D>
#include <QWidget>

#ifndef OBJETO_H
#define OBJETO_H

class Objeto : public QWidget
{
protected:
    QVector3D Position;
    QVector3D Rotation;

public:
    virtual void draw();

    void setRotation(QVector3D rot);
};

#endif // OBJETO_H
