#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"
#include "repositorioobjetos.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    GLWidget *glWidget;
    RepositorioObjetos * repo;
};

#endif // MAINWINDOW_H
