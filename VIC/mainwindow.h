#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <QProcess>

#include "datatext.h"
#include "leftblinkeranimation.h"
#include "rightblinkeranimation.h"
#include "backgrounditem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void AnimateDataOne();
    void AnimateDataTwo();
    void AnimateDataThree();
    void AnimateDataFour();
    void AnimateDataFive();

    void on_On_Off_One_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timerOne;
    QTimer *timerTwo;
    QTimer *timerThree;
    QTimer *timerFour;
    QTimer *timerFive;

    QGraphicsScene *instrumentClusterScene;

    DataText *dataTextOne;
    DataText *dataTextOneC;
    DataText *dataTextOneWhite;
    DataText *dataTextOneRed;
    DataText *endRedOne;

    DataText *dataTextTwo;
    DataText *dataTextTwoC;
    DataText *dataTextTwoWhite;
    DataText *dataTextTwoRed;
    DataText *endRedTwo;

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

    bool isWhite;
    bool isRed;

    bool isRedTwo;
    bool isWhiteTwo;

    bool isWhiteThree;
    bool isRedThree;

    bool isWhiteFour;
    bool isRedFour;

    bool toggleOn;
    bool toggleOnTwo;
    bool toggleOnThree;
    bool toggleOnFour;

    bool dataThreeActive;
    bool dataFourActive;
    bool dataFiveActive;

    int itemCount;
};

#endif // MAINWINDOW_H
