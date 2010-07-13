#include "repositorioobjetos.h"

RepositorioObjetos *RepositorioObjetos::inst = 0;

RepositorioObjetos::RepositorioObjetos()
{
    count = 0;
    selected = "";
}

RepositorioObjetos::~RepositorioObjetos(){
    QMap<QString, Objeto*>::const_iterator i = this->constBegin();

    while(i != this->constEnd()){
        delete i.value();

        ++i;
    }
}

RepositorioObjetos *RepositorioObjetos::instance(){
    if(!inst){
        inst = new RepositorioObjetos;
    }

    return inst;
}

void RepositorioObjetos::insert(Objeto *obj){
    QString hash = "";

    hash += obj->text();
    hash += " ID: " + QString::number(count + 1);

    obj->setText(hash);

    count++;

    ((QMap *)this)->insert(hash, obj);
}


void RepositorioObjetos::setSelected(QString sel){
    selected = sel;
}

Objeto *RepositorioObjetos::getSelected(){
    return ((QMap *)this)->find(selected).value();
}
