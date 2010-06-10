#include "objeto.h"

Objeto::Objeto(){
}

void Objeto::draw(float a) {
}


void Objeto::setRotation(QVector3D rot){
    Rotation = rot;
}

QVector3D Objeto::getRotation() const {
    return Rotation;
}
