#ifndef REPOSITORIOOBJETOS_H
#define REPOSITORIOOBJETOS_H

#include <QMap>
#include "objeto.h"

// Esta es la clase que se encarga de gestionar los objetos
// es singleton para no tener problemas de agregacion
// hereda de QMap, para asignarle un hash a cada objeto y sea
// reconocible desde la interfaz por su hash
class RepositorioObjetos : public QMap<QString, Objeto *>
{
protected:
    RepositorioObjetos();

public:
    static RepositorioObjetos *instance();
    ~RepositorioObjetos();

    void insert(Objeto *obj);

private:
    static RepositorioObjetos *inst;
    int count;

};

#endif // REPOSITORIOOBJETOS_H
