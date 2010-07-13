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

    luz = GL_LIGHT0;

    glWidget = new GLWidget;
    ui->gridLayout_2->addWidget(glWidget, 0, 0);//->insertWidget(0, glWidget);
/*
    Cubo *c1 = new Cubo;
    Esfera *e1 = new Esfera;
    Luz *l = new Luz(nextLight()), *l2 = new Luz(nextLight());

    l->setPosition(QVector3D(0, -5, -7.5));
    l2->setPosition(QVector3D(1, 4, -7.5));

    c1->setPosition(QVector3D(2, 3, -6));
    c1->setRotVelocity(QVector3D(45, 0, 0));

    e1->setPosition(QVector3D(0, -3, -13));
    e1->setRotVelocity(QVector3D(45, 0, 100));

    repo->insert(c1);
    repo->insert(e1);
    repo->insert(l);
    repo->insert(l2);

    ui->listWidget->addItem(c1);
    ui->listWidget->addItem(l2);
    ui->listWidget->insertItem(0, e1);
    ui->listWidget->insertItem(0, l);*/

    connect(ui->checkBox, SIGNAL(toggled(bool)), glWidget, SLOT(setWireFrame(bool)));
    connect(ui->listWidget, SIGNAL(itemSelectionChanged()), this, SLOT(onListChanged()));

    connect(ui->XAxis, SIGNAL(sliderMoved(int)), this, SLOT(slideMoved(int)));
    connect(ui->YAxis, SIGNAL(sliderMoved(int)), this, SLOT(slideMoved(int)));
    connect(ui->ZAxis, SIGNAL(sliderMoved(int)), this, SLOT(slideMoved(int)));
    connect(ui->XRot, SIGNAL(valueChanged(double)), this, SLOT(rotChanged(double)));

    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(addObject()));
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
          //  cout<<o->text().toStdString()<<" "<<o->getPosition().x()<<endl;
            o->operator +=(QVector3D(-0.1, 0, 0));
            break;

    case Qt::Key_Right:
        //cout<<o->text().toStdString()<<" "<<o->getPosition().x()<<endl;
        o->operator +=(QVector3D(0.1, 0, 0));
        break;

    case Qt::Key_Down:
        //cout<<o->text().toStdString()<<" "<<o->getPosition().y()<<endl;
        o->operator +=(QVector3D(0, -0.1, 0));
        break;

    case Qt::Key_Up:
        //cout<<o->text().toStdString()<<" "<<o->getPosition().y()<<endl;
        o->operator +=(QVector3D(0, 0.1, 0));
        break;

    case Qt::Key_PageUp:
        //cout<<o->text().toStdString()<<" "<<o->getPosition().z()<<endl;
        o->operator +=(QVector3D(0, 0, 0.1));
        break;

    case Qt::Key_PageDown:
        //cout<<o->text().toStdString()<<" "<<o->getPosition().z()<<endl;
        o->operator +=(QVector3D(0, 0, -0.1));
        break;
    }    

    ui->XAxis->setValue((int)(o->getPosition().x()*10));
    ui->YAxis->setValue((int)(o->getPosition().y()*10));
    ui->ZAxis->setValue((int)(-o->getPosition().z()*10));
}

void MainWindow::on_colorButton_clicked(bool checked)
{
    QColorDialog *colorDialog = new QColorDialog();
    colorDialog->open(this, SLOT(cambiarColor(QColor)));
}

void MainWindow::cambiarColor(const QColor &color)
{
    ((Objeto *)ui->listWidget->currentItem())->cambiarColor(color);
}

void MainWindow::onListChanged(){
    Objeto *obj = (Objeto *)ui->listWidget->currentItem();
    repo->setSelected(obj->text());

    ui->checkBox->setChecked(obj->getWired());

    ui->XAxis->setValue((int)(obj->getPosition().x()*10));
    ui->YAxis->setValue((int)(obj->getPosition().y()*10));
    ui->ZAxis->setValue((int)(-obj->getPosition().z()*10));

    ui->XRot->setValue(obj->getRotVelocity().x());
    ui->YRot->setValue(obj->getRotVelocity().y());
    ui->ZRot->setValue(obj->getRotVelocity().z());
}

void MainWindow::addObject(){
    Objeto *obj = NULL;

    if(ui->comboBox->currentText() == "Cubo")
        obj = new Cubo;
    else if(ui->comboBox->currentText() == "Esfera")
        obj = new Esfera;
    else if(ui->comboBox->currentText() == "Luz")
        obj = new Luz(nextLight());

    if(!obj) return;

    obj->setPosition(QVector3D(1, 0, -15));

    repo->insert(obj);
    ui->listWidget->addItem(obj);
}

GLenum MainWindow::nextLight(){
    cout<<GL_LIGHT0<<" "<<GL_LIGHT1<<endl;

    return ++luz;
}
void MainWindow::rotChanged(double value){    
    repo->getSelected()->setRotVelocity(
            QVector3D(
                ui->XRot->value(),
                ui->YRot->value(),
                ui->ZRot->value()
            ));
}

void MainWindow::slideMoved(int value){
    repo->getSelected()->setPosition(
            QVector3D(
                ui->XAxis->value()/10,
                ui->YAxis->value()/10,
                -ui->ZAxis->value()/10
            ));
}
