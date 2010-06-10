#include <QtOpenGL>
#include "objeto.h"

#ifndef CUBO_H
#define CUBO_H

class Cubo : public Objeto
{
public:
    Cubo();
    void draw(float angle);
};

#endif // CUBO_H
