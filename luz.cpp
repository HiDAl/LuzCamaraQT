#include "luz.h"
#include <iostream>

Luz::Luz(GLenum l)
{
    sphere = gluNewQuadric();
    gluQuadricOrientation(sphere, GLU_LINE);
    this->setText("Luz");
    luz = l;

    glEnable(luz);
}

void Luz::draw(float deltaTime){

    bool iluminar = glIsEnabled(GL_LIGHTING) ? true : false;  //*si no hay luz solo dibujar y no hacer nada mas

    glLoadIdentity();                                       // Reset The Current Modelview Matrix

    glTranslatef(Position.x(), Position.y(), Position.z());

    Rotate(deltaTime);

    glDisable(GL_LIGHTING);
    glPushMatrix();
        glColor3f(colorR,colorG,colorB);              // Set The Color
        gluSphere(sphere, .1, 10, 10);
    glPopMatrix();

    if(!iluminar) return;                   //*no iluminar

    glEnable(GL_LIGHTING);

    GLfloat ambientlight[]  =	{colorR , colorG, colorB, 1.0f};
    GLfloat difuselight[]   =	{colorR/3, colorG, colorB, 1.0f};
    GLfloat specularlight[] =	{1.0, 1.0, 1.0, 1.0f};
    GLfloat position[] =        {Position.x(), Position.y(), Position.z(), 1.0f};

    glLightfv(luz, GL_AMBIENT,  ambientlight);
    glLightfv(luz, GL_DIFFUSE,  difuselight);
    glLightfv(luz, GL_SPECULAR, specularlight);
    glLightfv(luz, GL_POSITION, position);
}
