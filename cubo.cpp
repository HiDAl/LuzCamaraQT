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
            glColor3f(0.0f,1.0f,0.0f);                          // Set The Color To Blue
            glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Top)
            glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Top)
            glVertex3f(-1.0f, 1.0f, 1.0f);			// Bottom Left Of The Quad (Top)    
            glVertex3f( 1.0f, 1.0f, 1.0f);			// Bottom Right Of The Quad (Top)

            glVertex3f( 1.0f,-1.0f, 1.0f);			// Top Right Of The Quad (Bottom)
            glVertex3f(-1.0f,-1.0f, 1.0f);			// Top Left Of The Quad (Bottom)
            glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Bottom)
            glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Bottom)

            glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Front)
            glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Front)
            glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Front)
            glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Front)

            glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Back)
            glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Back)
            glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Back)
            glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Back)


            glColor3f(0.0f, 0.0f,1.0f);                          // Set The Color To Blue
            glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Left)
            glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Left)
            glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Left)
            glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Left)

            glColor3f(1.0f, 0.0f,0.0f);                          // Set The Color To Blue
            glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Right)
            glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Right)
            glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Right)
            glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Right)
    glEnd();

    glPopMatrix();
}
