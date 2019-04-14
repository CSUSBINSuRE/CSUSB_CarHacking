#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include "turnsignal.h"
#include "datatextone.h"
#include "datatextonered.h"
#include "datatextonewhite.h"
#include "infotext.h"
#include "datatextonec.h"
#include "endredone.h"
#include "backgrounditem.h"
#include "datatexttwo.h"
#include "datatexttwowhite.h"
#include "datatexttwored.h"
#include "datatexttwoc.h"
#include "endredtwo.h"

#include "datatextthree.h"
#include "datatextthreec.h"
#include "datatextthreewhite.h"
#include "datatextthreered.h"
#include "endredthree.h"
#include "leftblinkeranimation.h"
#include "rightblinkeranimation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

private slots:
    void AnimateDataOne();
    void AnimateDataTwo();
    void AnimateDataThree();
    void on_On_Off_One_clicked();
    void on_On_Off_Two_clicked();
    void on_On_Off_Three_clicked();
    void on_On_Off_Four_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timerOne;
    QTimer *timerTwo;
    QTimer *timerThree;

    QGraphicsScene *instrumentClusterScene;
    QGraphicsScene *dataScene;
    TurnSignal *turnSignal;

    DataTextOne *dataTextOne;
    DataTextOneC *dataTextOneC;
    EndRedOne *endRedOne;
    DataTextOneRed *dataTextOneRed;
    DataTextOneWhite *dataTextOneWhite;
    InfoText *infoText;

    DataTextTwo *dataTextTwo;
    DataTextTwoWhite *dataTextTwoWhite;
    DataTextTwoRed *dataTextTwoRed;
    DataTextTwoC *dataTextTwoC;
    EndRedTwo *endRedTwo;

    DataTextThree *dataTextThree;
    DataTextThreeC *dataTextThreeC;
    DataTextThreeWhite *dataTextThreeWhite;
    DataTextThreeRed *dataTextThreeRed;
    EndRedThree *endRedThree;

    LeftBlinkerAnimation *leftBlinkerAnimation;
    RightBlinkerAnimation *rightBlinkerAnimation;


    BackgroundItem *lTurn;
    BackgroundItem *rTurn;
    BackgroundItem *speed;
    BackgroundItem *engine;
    BackgroundItem *tpms;
    BackgroundItem *tcontrol;
    BackgroundItem *hBeam;
    BackgroundItem *abs;

    bool toggleOn;
    bool toggleOnTwo;

    bool isRed;
    bool isWhite;
    bool isRedTwo;
    bool isWhiteTwo;
    bool isWhiteThree;
    bool isRedThree;
    bool dataThreeActive;
    int *itemCount;
};

#endif // MAINWINDOW_H
