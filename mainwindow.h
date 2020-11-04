#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyVector.h"

#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// начало
class CShape{
public:
    virtual void draw(QWidget *parent){};
    virtual ~CShape(){};

    virtual int getx(){};
    virtual int gety(){};
    virtual int getR(){};
};

class CCircle: public CShape{ // Создание круга
private:
    int x;
    int y;
    int R = 50;
    QPainter *p;
public:
    CCircle (){
        x = y = 0;
        p = NULL;
    }
    CCircle (CCircle *x){
        this->x = x->x;
        this->y = x->y;
        this->R = x->R;
        this->p = x->p;
    }
    CCircle(int x, int y){
        this->x = x;
        this->y = y;
    }
    virtual int getx(){ return this->x; }
    virtual int gety(){ return this->y; }
    virtual int getR(){ return this->R; }
    virtual void draw(QWidget *parent){
        p = new QPainter(parent);
        p->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
        p->setBrush(QBrush(Qt::white, Qt::SolidPattern));
        p->drawEllipse(x - R, y - R, 2 * R, 2 * R);
    }
    virtual ~CCircle(){};
};
/*
class CAllocate: public CShape{ // Выделение круга
private:
    CShape *shape;
    QPainter *border;
};
*/
// конец

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    SimpleVector<CShape*> stor; // Хранилище кругов под глазами
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *);
protected:
    void mousePressEvent(QMouseEvent *e); // по нажатию мыши чето происходит
};

#endif // MAINWINDOW_H
