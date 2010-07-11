#include "esfera.h"

Esfera::Esfera()
{
    sphere = gluNewQuadric();
    gluQuadricOrientation(sphere, GLU_LINE);
    this->setText("Esfera");
}

void Esfera::draw(float deltaTime){
    glLoadIdentity();                                       // Reset The Current Modelview Matrix

    glTranslatef(Position.x(), Position.y(), Position.z());

    Rotate(deltaTime);

    glPushMatrix();
        glColor3f(colorR,colorG,colorB);              // Set The Color
        gluSphere(sphere, 1.0, 10, 10);
    glPopMatrix();
}
