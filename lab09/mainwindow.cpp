#include "mainwindow.h"
#include <stdlib.h>
#include <iostream>
#include <vector>

void MainWindow::handleTimer() {
    //item->move( WINDOW_MAX_X, WINDOW_MAX_Y );
    counter++;
    int w = rand() % 20 +5;
    int h = rand() % 20+5;
    double y= rand()% 100;
    double x = rand()% 100;
    double vx = rand() % 5 + 1;
    double vy = rand() % 5 + 1;
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QBrush yellowBrush(Qt::yellow);
    for (int i=0; i<rectangles.size(); i++){
    	rectangles[i]->move(WINDOW_MAX_X, WINDOW_MAX_Y);
    	}
   // std::cout << counter << std::endl;
    if (counter%50==0){
    	BouncingRectangle *p = new BouncingRectangle( x, y, w, h, vx, vy );
    	rectangles.push_back(p);
    	
    int i = rand() % 4;
    if (i==0){
    p->setBrush( redBrush );
    }
    if (i==1){
    p->setBrush( blueBrush );
    }
    if (i==2){
    p->setBrush( greenBrush );
    }
    if (i==3){
    p->setBrush( yellowBrush );
     }	
     scene->addItem( p); 
    }
    
    
}
void MainWindow::handleButton(){

    if (timer->isActive()==true){
    	timer->stop();
    	button->setText("Start");
    }
    else {
	timer->start();
    	button->setText("Stop");
     }
}
MainWindow::MainWindow()  {
    counter=0;
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
    
    
    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QBrush yellowBrush(Qt::yellow);

    //First 2 arguments are the x, y, of the upper left of the rectangle.
    //The second 2 arguments are the width and height
    //The last 2 arguments are the velocity in the x, and y, directions
   
   
    item = new BouncingRectangle( 11, 73, 20, 20, 2, 3 );
    	
    int i = rand() % 4;
    if (i==0){
    item->setBrush( redBrush );
    }
    if (i==1){
    item->setBrush( blueBrush );
    }
    if (i==2){
    item->setBrush( greenBrush );
    }
    if (i==3){
    item->setBrush( yellowBrush );
    }
    scene->addItem( item );
    
    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    timer = new QTimer(this);
    timer->setInterval(5);

    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    button = new QPushButton(view);
    button->setText("Start");
    button->setGeometry(225, 450, 60, 40);
    
    connect(button, SIGNAL(clicked()), this, SLOT(handleButton()));
    timer->start();
    //button->show();
}
void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    //This is how we get our view displayed.
    view->show();
}
MainWindow::~MainWindow()
{
    timer->stop();
    delete timer;
    delete item;
    delete scene;
    delete view;
}
