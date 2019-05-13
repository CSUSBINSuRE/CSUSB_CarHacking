#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

#include <QProcess>
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
#include "datatextfour.h"
#include "datatextfourc.h"
#include "datatextfourwhite.h"
#include "datatextfourred.h"
#include "endredfour.h"

#include "datatextthree.h"
#include "datatextthreec.h"
#include "datatextthreewhite.h"
#include "datatextthreered.h"
#include "endredthree.h"
#include "leftblinkeranimation.h"
#include "rightblinkeranimation.h"
#include "speedanimation.h"
#include "aboutvic.h"
#include "datatextfive.h"

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
    void AnimateDataFour();
    void AnimateDataFive();
    void on_On_Off_One_clicked();
    void on_On_Off_Two_clicked();
    void on_On_Off_Three_clicked();
    void on_On_Off_Four_clicked();
    void on_send_Button_clicked();
    void on_actionVirtual_IC_triggered();

    void on_actionTerminal_triggered();

private:
    Ui::MainWindow *ui;
    QTimer *timerOne;
    QTimer *timerTwo;
    QTimer *timerThree;
    QTimer *timerFour;
    QTimer *timerFive;

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

    DataTextFour *dataTextFour;
    DataTextFourC *dataTextFourC;
    DataTextFourWhite *dataTextFourWhite;
    DataTextFourRed *dataTextFourRed;
    EndRedFour *endRedFour;

    DataTextFive *dataTextFive;

    LeftBlinkerAnimation *leftBlinkerAnimation;
    RightBlinkerAnimation *rightBlinkerAnimation;
    SpeedAnimation *speedAnimation;


    BackgroundItem *lTurn;
    BackgroundItem *rTurn;
    BackgroundItem *speed;
    BackgroundItem *engine;
    BackgroundItem *tpms;
    BackgroundItem *tcontrol;
    BackgroundItem *hBeam;
    BackgroundItem *abs;

    AboutVIC *aboutVIC;

    bool toggleOn;
    bool toggleOnTwo;
    bool toggleOnThree;
    bool toggleOnFour;

    bool isRed;
    bool isWhite;

    bool isRedTwo;
    bool isWhiteTwo;

    bool isWhiteThree;
    bool isRedThree;

    bool isWhiteFour;
    bool isRedFour;

    bool dataThreeActive;
    bool dataFourActive;
    bool dataFiveActive;

    int itemCount;
};

#endif // MAINWINDOW_H
