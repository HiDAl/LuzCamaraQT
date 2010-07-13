#include "cubo.h"
#include <iostream>

using namespace std;

Cubo::Cubo()
{
    this->setText("Cubo");
}


void Cubo::draw(float deltaTime){
    glLoadIdentity();                                       // Reset The Current Modelview Matrix

    glTranslatef(Position.x(), Position.y(), Position.z());

    Rotate(deltaTime);

    glPushMatrix();
    glBegin(GL_QUADS);						// Draw A Quad
            glColor3f(colorR,colorG,colorB);
            // Cara de Atras
            glNormal3f( 0.0f, 0.0f,1.0f);      //defino la normal...
            glVertex3f( 1.0f, -1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);

            // Cara de Adelante
            glNormal3f( 0.0f, 0.0f, -1.0f);      //defino la normal...
            glVertex3f( 1.0f, -1.0f, 1.0f);
            glVertex3f( 1.0f,  1.0f, 1.0f);
            glVertex3f(-1.0f,  1.0f, 1.0f);
            glVertex3f(-1.0f, -1.0f, 1.0f);

            // Right face
            glNormal3f( -1.0f, 0.0f, 0.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f, -1.0f, -1.0f);

            // Left Face
            glNormal3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f, -1.0f,  1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);

            // Top Face
            glNormal3f( 0.0f, -1.0f, 0.0f);
            glVertex3f( 1.0f,  1.0f, -1.0f);
            glVertex3f( 1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f,  1.0f);
            glVertex3f(-1.0f,  1.0f, -1.0f);

            // Bottom Face
            glNormal3f( 0.0f, 1.0f, 0.0f);
            glVertex3f(-1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f, -1.0f,  1.0f);
            glVertex3f( 1.0f, -1.0f, -1.0f);
            glVertex3f(-1.0f, -1.0f, -1.0f);
    glEnd();

    glPopMatrix();
}
