#ifndef ESFERA_H
#define ESFERA_H

#include "objeto.h"

class Esfera : public Objeto
{
public:
    Esfera();
    void draw(float dt);

private:
  GLUquadricObj *sphere;
};

#endif // ESFERA_H
