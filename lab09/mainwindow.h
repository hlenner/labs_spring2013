#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>

#include "bouncingrectangle.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

using namespace std;
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    void show();
    int counter;
    vector <BouncingRectangle*> rectangles;
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    BouncingRectangle *item;
    QPushButton *button;

public slots:
    void handleTimer();
    void handleButton();
};

#endif // MAINWINDOW_H
