#include "esfera.h"

Esfera::Esfera()
{
    sphere = gluNewQuadric();
    gluQuadricOrientation(sphere, GLU_LINE);
}

void Esfera::draw(float deltaTime){
    glLoadIdentity();                                       // Reset The Current Modelview Matrix

    glTranslatef(Position.x(), Position.y(), Position.z());

    Rotate(deltaTime);

    glPushMatrix();
        glColor3f(0.0f,1.0f,0.0f);                          // Set The Color To Blue
        gluSphere(sphere, 1.0, 10, 10);
    glPopMatrix();
}
