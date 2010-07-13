#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
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
    GLenum luz;
    GLenum nextLight();

private slots:
    void on_colorButton_clicked(bool checked);
    void cambiarColor(const QColor &color);
    void onListChanged();
    void slideMoved(int value);
    void rotChanged(double value);
    void addObject();
};

#endif // MAINWINDOW_H
