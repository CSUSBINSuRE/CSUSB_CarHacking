#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    timerOne = new QTimer();
    connect(timerOne, SIGNAL(timeout()), this, SLOT(AnimateDataOne()));
    timerOne->start(1200);

    timerTwo = new QTimer();
    connect(timerTwo, SIGNAL(timeout()), this, SLOT(AnimateDataTwo()));
    timerTwo->start(1000);

    timerThree = new QTimer();
    connect(timerThree, SIGNAL(timeout()), this, SLOT(AnimateDataThree()));

    timerFour = new QTimer();
    connect(timerFour, SIGNAL(timeout()), this, SLOT(AnimateDataFour()));

    timerFive = new QTimer();
    connect(timerFive, SIGNAL(timeout()), this, SLOT(AnimateDataFive()));

    instrumentClusterScene = new QGraphicsScene();
    instrumentClusterScene->setSceneRect(0,0,1200,700);
    ui->graphicsView->setScene(instrumentClusterScene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    lTurn = new BackgroundItem(QPixmap(":images/turn_left.png"));
    lTurn->setPos(585,130);
    instrumentClusterScene->addItem(lTurn);

    rTurn = new BackgroundItem(QPixmap(":images/turn_right.png"));
    rTurn->setPos(735,130);
    instrumentClusterScene->addItem(rTurn);

    engine = new BackgroundItem(QPixmap(":images/engine.png"));
    engine->setPos(1012,346);
    instrumentClusterScene->addItem(engine);

    speed = new BackgroundItem(QPixmap(":images/speed.png"));
    speed->setPos(1022,140);
    instrumentClusterScene->addItem(speed);

    hBeam = new BackgroundItem(QPixmap(":images/high_beam.png"));
    hBeam->setPos(595,340);
    instrumentClusterScene->addItem(hBeam);

    abs = new BackgroundItem(QPixmap(":images/abs.png"));
    abs->setPos(725,346);
    instrumentClusterScene->addItem(abs);

    tpms = new BackgroundItem(QPixmap(":images/tpms.png"));
    tpms->setPos(877,345);
    instrumentClusterScene->addItem(tpms);

    tcontrol = new BackgroundItem(QPixmap(":images/t_control.png"));
    tcontrol->setPos(870,135);
    instrumentClusterScene->addItem(tcontrol);

    dataTextOne = new DataText();
    dataTextOne->DataTextOne();
    dataTextOne->setPos(45,170);
    instrumentClusterScene->addItem(dataTextOne);

    dataTextOneC = new DataText();
    dataTextOneC->DataTextOneC();
    dataTextOneC->setPos(45,170);

    dataTextOneWhite = new DataText();
    dataTextOneWhite->DataTextOneWhite();
    dataTextOneWhite->setPos(385,170);
    instrumentClusterScene->addItem(dataTextOneWhite);

    dataTextOneRed = new DataText();
    dataTextOneRed->DataTextOneRed();
    dataTextOneRed->setPos(385,170);

    endRedOne = new DataText();
    endRedOne->EndRedOne();
    endRedOne->setPos(463,170);

    dataTextTwo = new DataText();
    dataTextTwo->DataTextTwo();
    dataTextTwo->setPos(45,200);
    instrumentClusterScene->addItem(dataTextTwo);

    dataTextTwoC = new DataText();
    dataTextTwoC->DataTextTwoC();
    dataTextTwoC->setPos(45,200);

    dataTextTwoWhite = new DataText();
    dataTextTwoWhite->DataTextTwoWhite();
    dataTextTwoWhite->setPos(325,200);
    instrumentClusterScene->addItem(dataTextTwoWhite);

    dataTextTwoRed = new DataText();
    dataTextTwoRed->DataTextTwoRed();
    dataTextTwoRed->setPos(325,200);

    endRedTwo = new DataText();
    endRedTwo->EndRedTwo();
    endRedTwo->setPos(495,200);

    //Left Turn signal animation
    leftBlinkerAnimation = new LeftBlinkerAnimation();
    leftBlinkerAnimation->setPos(597,145);

    //Left Turn signal animation
    rightBlinkerAnimation = new RightBlinkerAnimation();
    rightBlinkerAnimation->setPos(746,145);

    toggleOn = false;
    toggleOnTwo = false;
    toggleOnThree = false;
    toggleOnFour = false;

    isWhite = true;
    isRed = false;

    isWhiteTwo = true;
    isRedTwo = false;

    dataThreeActive = false;
    isWhiteThree = false;
    isRedThree = false;

    itemCount = 0;

    dataFourActive = false;
    isWhiteFour= true;
    isRedFour = false;

    dataFiveActive = false;
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::AnimateDataOne(){

    if(isWhite){
        instrumentClusterScene->removeItem(dataTextOne);
        instrumentClusterScene->removeItem(dataTextOneWhite);
        instrumentClusterScene->addItem(dataTextOneC);
        instrumentClusterScene->addItem(dataTextOneRed);
        instrumentClusterScene->addItem(endRedOne);
        isWhite = false;
        isRed = true;
    }
    else if(isRed){
        instrumentClusterScene->removeItem(dataTextOneC);
        instrumentClusterScene->removeItem(dataTextOneRed);
        instrumentClusterScene->removeItem(endRedOne);
        instrumentClusterScene->addItem(dataTextOne);
        instrumentClusterScene->addItem(dataTextOneWhite);
        isWhite = true;
        isRed = false;
    }else{
        return;
    }
}

void MainWindow::AnimateDataTwo(){

    if(isWhiteTwo){
        instrumentClusterScene->removeItem(dataTextTwo);
        instrumentClusterScene->removeItem(dataTextTwoWhite);
        instrumentClusterScene->addItem(dataTextTwoC);
        instrumentClusterScene->addItem(dataTextTwoRed);
        instrumentClusterScene->addItem(endRedTwo);
        isWhiteTwo = false;
        isRedTwo = true;
    }
    else if(isRedTwo){
        instrumentClusterScene->removeItem(dataTextTwoC);
        instrumentClusterScene->removeItem(dataTextTwoRed);
        instrumentClusterScene->removeItem(endRedTwo);
        instrumentClusterScene->addItem(dataTextTwo);
        instrumentClusterScene->addItem(dataTextTwoWhite);
        isWhiteTwo = true;
        isRedTwo = false;
    }else{
        return;
    }
}

void MainWindow::AnimateDataThree(){

}

void MainWindow::AnimateDataFour(){

}

void MainWindow::AnimateDataFive(){

}

void MainWindow::on_On_Off_One_clicked(){
/*
    if (toggleOn){
        itemCount++;
        timerThree->start(500);
        qDebug()<< itemCount;
        instrumentClusterScene->removeItem(lTurn);
        instrumentClusterScene->addItem(leftBlinkerAnimation);
    }
    else if(!toggleOn){
        timerThree->stop();
        itemCount--;
        qDebug()<< itemCount;
        instrumentClusterScene->removeItem(leftBlinkerAnimation);
        instrumentClusterScene->addItem(lTurn);

        if(isWhiteThree){
            instrumentClusterScene->removeItem(dataTextThree);
            instrumentClusterScene->removeItem(dataTextThreeWhite);
            dataThreeActive = false;
            isRedThree = false;
            isWhiteThree =false;
        }
        else if(isRedThree){
            instrumentClusterScene->removeItem(dataTextThreeC);
            instrumentClusterScene->removeItem(dataTextThreeRed);
            instrumentClusterScene->removeItem(endRedThree);
            dataThreeActive = false;
            isRedThree = false;
            isWhiteThree =false;
        }
    }
    */
}
