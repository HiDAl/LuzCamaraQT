#include "objeto.h"

Objeto::Objeto(){
    this->setText("ObjetoGenerico");
}

void Objeto::draw(float a) {
    a;
}

// Se hacen las revisiones de que sean distinto de cero para evitar una multiplicacion matricial
void Objeto::Rotate(float deltaTime){

    // Se aumenta el angulo de rotacion en cada eje)
    // rotvelocity*deltatime es la cantidad que se aumentara (se aumenta rotvelocity grados por segundo)
    Rotation.setX( Rotation.x() +  RotVelocity.x()*deltaTime);
    Rotation.setY( Rotation.y() +  RotVelocity.y()*deltaTime);
    Rotation.setZ( Rotation.z() +  RotVelocity.z()*deltaTime);

    if(Rotation.x() != 0.0){
        glRotatef(Rotation.x(), 1.0, 0.0, 0.0 );
    }

    if(Rotation.y() != 0.0){
        glRotatef(Rotation.y(), 0.0, 1.0, 0.0);
    }

    if(Rotation.z() != 0.0){
        glRotatef(Rotation.z(), 0.0, 0.0, 1.0);
    }
}


void Objeto::setRotVelocity(QVector3D vel){
    RotVelocity = vel;
}

QVector3D Objeto::getRotVelocity() const {
    return RotVelocity;
}

void Objeto::setRotation(QVector3D rot){
    Rotation = rot;
}

QVector3D Objeto::getRotation() const {
    return Rotation;
}

void Objeto::setPosition(QVector3D pos){
    Position = pos;
}

QVector3D Objeto::getPosition() const {
    return Position;
}

void Objeto::operator+= (QVector3D pos){
    Position += pos;
}
