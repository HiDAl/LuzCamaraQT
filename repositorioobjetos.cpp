#include "repositorioobjetos.h"

RepositorioObjetos *RepositorioObjetos::inst = 0;

RepositorioObjetos::RepositorioObjetos()
{
}

RepositorioObjetos *RepositorioObjetos::instance(){
    if(!inst){
        inst = new RepositorioObjetos;
    }

    return inst;
}

