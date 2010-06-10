
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
    Objeto();
    virtual void draw(float a);

    void setRotation(QVector3D rot) ;
    QVector3D getRotation() const;

};

#endif // OBJETO_H
