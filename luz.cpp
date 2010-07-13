#include "luz.h"

Luz::Luz(GLenum l)
{
    sphere = gluNewQuadric();
    gluQuadricOrientation(sphere, GLU_LINE);
    this->setText("Luz");
    luz = l;
}

void Luz::draw(float deltaTime){
    glLoadIdentity();                                       // Reset The Current Modelview Matrix

    glDisable(luz);

    glTranslatef(Position.x(), Position.y(), Position.z());

    Rotate(deltaTime);

    glPushMatrix();
        glColor3f(colorR,colorG,colorB);              // Set The Color
        gluSphere(sphere, .1, 10, 10);
    glPopMatrix();

    GLfloat ambientlight[]  =	{colorR , colorG, colorB, 1.0f};
    GLfloat difuselight[]   =	{colorR , colorG, colorB, 1.0f};
    GLfloat specularlight[] =	{colorR , colorG, colorB, 1.0f};
    GLfloat position[] =        {Position.x(), Position.y(), Position.z(), 1.0f};

    glLightfv(luz, GL_AMBIENT,  ambientlight);
    glLightfv(luz, GL_DIFFUSE,  difuselight);
    glLightfv(luz, GL_SPECULAR, specularlight);
    glLightfv(luz, GL_POSITION, position);

    glEnable(luz);
}
