#include <QtOpenGL>
#include <QVector3D>
#include <QWidget>

#ifndef OBJETO_H
#define OBJETO_H

class Objeto : public QListWidgetItem
{
protected:
    QVector3D Position;
    QVector3D Rotation; // vector con el valor de rotacion en cada eje (en grados)
    QVector3D RotVelocity; // velocidad con la que rotara en cada eje (en grados)
    float colorR;
    float colorG;
    float colorB;
    bool wired;

    void Rotate(float deltaTime); // deltaTime es para calcular el valor que debe tener el angulo de rotacion nuevo

public:
    Objeto();
    virtual void draw(float dt);

    void setRotation(QVector3D rot);
    QVector3D getRotation() const;

    void setRotVelocity(QVector3D vel);
    QVector3D getRotVelocity() const;

    void setPosition(QVector3D pos);
    QVector3D getPosition() const;

    bool getWired() const;
    void setWired(bool w);

    void operator+= (QVector3D);

    void cambiarColor(const QColor &color);

};

#endif // OBJETO_H
