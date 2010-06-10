#include "cubo.h"

Cubo::Cubo()
{
}


void Cubo::draw(float angle){
    glLoadIdentity();					// Reset The Current Modelview Matrix
    glTranslatef(1.5f,0.0f,-6.0f);				// Move Right 1.5 Units And Into The Screen 6.0

    //glRotatef(angle, Rotation.x(),          0.0,         0.0 );
    glRotatef(angle,          0.0, Rotation.y(),          0.0);
    glRotatef(angle,          0.0,          0.0, Rotation.z());

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

            glVertex3f(-1.0f, 1.0f, 1.0f);			// Top Right Of The Quad (Left)
            glVertex3f(-1.0f, 1.0f,-1.0f);			// Top Left Of The Quad (Left)
            glVertex3f(-1.0f,-1.0f,-1.0f);			// Bottom Left Of The Quad (Left)
            glVertex3f(-1.0f,-1.0f, 1.0f);			// Bottom Right Of The Quad (Left)

            glVertex3f( 1.0f, 1.0f,-1.0f);			// Top Right Of The Quad (Right)
            glVertex3f( 1.0f, 1.0f, 1.0f);			// Top Left Of The Quad (Right)
            glVertex3f( 1.0f,-1.0f, 1.0f);			// Bottom Left Of The Quad (Right)
            glVertex3f( 1.0f,-1.0f,-1.0f);			// Bottom Right Of The Quad (Right)
    glEnd();

    glPopMatrix();
}
