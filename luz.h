#ifndef LUZ_H
#define LUZ_H

#include "objeto.h"

class Luz : public Objeto {
public:
    Luz(GLenum l);
    void draw(float dt);

private:
    GLUquadricObj *sphere;
    GLenum luz;
};

#endif // LUZ_H
