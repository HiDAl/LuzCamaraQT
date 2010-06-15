#include <QtGui>
#include <iostream>

using namespace std;

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    repo = RepositorioObjetos::instance();

    /* Esta es la forma de agregar el Custom Widget (el de OGL), se
       debe agregar al layout que se aplicando (aca puse un verticalLayout como
       ejemplo no mas)
    */
    ui->horizontalLayout->insertWidget(0, new GLWidget);

    Cubo *c1 = new Cubo;
    Esfera *e1 = new Esfera;
    c1->setPosition(QVector3D(2, 3, -13));
    c1->setRotVelocity(QVector3D(45, 0, 0));

    e1->setPosition(QVector3D(0, -3, -13));
    e1->setRotVelocity(QVector3D(45, 0, 100));

    repo->insert(c1);
    repo->insert(e1);

    ui->listWidget->addItem(c1);
    ui->listWidget->insertItem(0, e1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    Objeto *o = (Objeto *)ui->listWidget->currentItem();

    if(!o) return;

    switch(event->key()){
        case Qt::Key_Left:
            cout<<o->text().toStdString()<<" "<<o->getPosition().x()<<endl;
            o->operator +=(QVector3D(-0.1, 0, 0));
            break;

    case Qt::Key_Right:
        cout<<o->text().toStdString()<<" "<<o->getPosition().x()<<endl;
        o->operator +=(QVector3D(0.1, 0, 0));
        break;

    case Qt::Key_Down:
        cout<<o->text().toStdString()<<" "<<o->getPosition().y()<<endl;
        o->operator +=(QVector3D(0, -0.1, 0));
        break;

    case Qt::Key_Up:
        cout<<o->text().toStdString()<<" "<<o->getPosition().y()<<endl;
        o->operator +=(QVector3D(0, 0.1, 0));
        break;

    case Qt::Key_PageUp:
        cout<<o->text().toStdString()<<" "<<o->getPosition().z()<<endl;
        o->operator +=(QVector3D(0, 0, 0.1));
        break;

    case Qt::Key_PageDown:
        cout<<o->text().toStdString()<<" "<<o->getPosition().z()<<endl;
        o->operator +=(QVector3D(0, 0, -0.1));
        break;
    }
}
