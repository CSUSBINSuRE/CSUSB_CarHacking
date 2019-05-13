#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QSerialPort>
#include <QCanBus>
#include <QCanBusDevice>
#include <QDebug>
#include <QTextEdit>
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

    lTurn = new BackgroundItem(QPixmap(":images_root/turn_left.png"));
    lTurn->setPos(585,130);
    instrumentClusterScene->addItem(lTurn);

    rTurn = new BackgroundItem(QPixmap(":images_root/turn_right.png"));
    rTurn->setPos(735,130);
    instrumentClusterScene->addItem(rTurn);

    engine = new BackgroundItem(QPixmap(":images_root/engine.png"));
    engine->setPos(1012,346);
    instrumentClusterScene->addItem(engine);

    speed = new BackgroundItem(QPixmap(":images_root/speed.png"));
    speed->setPos(1022,140);
    instrumentClusterScene->addItem(speed);

    hBeam = new BackgroundItem(QPixmap(":images_root/high_beam.png"));
    hBeam->setPos(595,340);
    instrumentClusterScene->addItem(hBeam);

    abs = new BackgroundItem(QPixmap(":images_root/abs.png"));
    abs->setPos(725,346);
    instrumentClusterScene->addItem(abs);

    tpms = new BackgroundItem(QPixmap(":images_root/tpms.png"));
    tpms->setPos(877,345);
    instrumentClusterScene->addItem(tpms);

    tcontrol = new BackgroundItem(QPixmap(":images_root/t_control.png"));
    tcontrol->setPos(870,135);
    instrumentClusterScene->addItem(tcontrol);

    infoText = new InfoText();
    infoText->setPos(43,145);
    instrumentClusterScene->addItem(infoText);

    dataTextOne = new DataTextOne();
    dataTextOne->setPos(45,170);
    instrumentClusterScene->addItem(dataTextOne);

    dataTextOneC = new DataTextOneC();
    dataTextOneC->setPos(45,170);

    dataTextOneWhite = new DataTextOneWhite();
    dataTextOneWhite->setPos(385,170);
    instrumentClusterScene->addItem(dataTextOneWhite);

    dataTextOneRed = new DataTextOneRed();
    dataTextOneRed->setPos(385,170);

    endRedOne = new EndRedOne();
    endRedOne->setPos(463,170);

    dataTextTwo = new DataTextTwo();
    dataTextTwo->setPos(45,200);
    instrumentClusterScene->addItem(dataTextTwo);

    dataTextTwoC = new DataTextTwoC();
    dataTextTwoC->setPos(45,200);

    dataTextTwoWhite = new DataTextTwoWhite();
    dataTextTwoWhite->setPos(325,200);
    instrumentClusterScene->addItem(dataTextTwoWhite);

    dataTextTwoRed = new DataTextTwoRed();
    dataTextTwoRed->setPos(325,200);

    endRedTwo = new EndRedTwo();
    endRedTwo->setPos(495,200);

    dataTextThree = new DataTextThree();
    dataTextThreeC = new DataTextThreeC();
    dataTextThreeWhite = new DataTextThreeWhite();
    dataTextThreeRed = new DataTextThreeRed();
    endRedThree = new EndRedThree();

    dataTextFour = new DataTextFour();
    dataTextFourC = new DataTextFourC();
    dataTextFourWhite = new DataTextFourWhite();
    dataTextFourRed = new DataTextFourRed();
    endRedFour = new EndRedFour();

    dataTextFive = new DataTextFive();

    //Left Turn signal animation
    leftBlinkerAnimation = new LeftBlinkerAnimation();
    leftBlinkerAnimation->setPos(597,145);

    //Left Turn signal animation
    rightBlinkerAnimation = new RightBlinkerAnimation();
    rightBlinkerAnimation->setPos(746,145);

    speedAnimation = new SpeedAnimation();
    speedAnimation->setPos(1022,140);

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
/*
    QProcess process;
    process.start("/home/equati0n/Desktop/hello.sh");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    qDebug() << output;
    QString err = process.readAllStandardError();
    qDebug() << err;

    QProcess *openTerminal = new QProcess();
    QString programPath = "/usr/bin/gnome-terminal";
    QStringList arguments;
    arguments << "--working-directory=/usr/bin/cansniffer" <<"-e" <<"cansniffer";
    openTerminal->start(programPath,arguments);


    QProcess process;
    process.start("/usr/bin/cansniffer");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    qDebug() << output;
    QString err = process.readAllStandardError();
    qDebug() << err;

*/

    QProcess *openTerminal = new QProcess();
    QString programPath = "/usr/bin/gnome-terminal";
    QStringList arguments;
    arguments <<"--working-directory=/Home" <<"-e" <<"ls";
    openTerminal->start(programPath,arguments);


    QString output = openTerminal->readAllStandardOutput();
    qDebug() << output;
    QString err = openTerminal->readAllStandardError();
    qDebug() << err;


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
    if(itemCount == 1){
        dataTextThree->setPos(45,230);
        dataTextThreeC->setPos(45,230);
        dataTextThreeWhite->setPos(384,230);
        dataTextThreeRed->setPos(384,230);
        endRedThree->setPos(463,230);

    }
    else if(itemCount == 2 && dataFourActive){
        dataTextFour->setPos(45,260);
        dataTextFourC->setPos(45,260);
        dataTextFourWhite->setPos(384,260);
        dataTextFourRed->setPos(384,260);
        endRedFour->setPos(463,260);

        dataTextThree->setPos(45,230);
        dataTextThreeC->setPos(45,230);
        dataTextThreeWhite->setPos(384,230);
        dataTextThreeRed->setPos(384,230);
        endRedThree->setPos(463,230);
    }
    else if(itemCount == 2 && dataFiveActive){
        dataTextFive->setPos(45,260);

        dataTextThree->setPos(45,230);
        dataTextThreeC->setPos(45,230);
        dataTextThreeWhite->setPos(384,230);
        dataTextThreeRed->setPos(384,230);
        endRedThree->setPos(463,230);

    }
    else if(itemCount == 3 && dataFourActive && dataFiveActive){
        dataTextFour->setPos(45,260);
        dataTextFourC->setPos(45,260);
        dataTextFourWhite->setPos(384,260);
        dataTextFourRed->setPos(384,260);
        endRedFour->setPos(463,260);

         dataTextFive->setPos(45,290);

         dataTextThree->setPos(45,230);
         dataTextThreeC->setPos(45,230);
         dataTextThreeWhite->setPos(384,230);
         dataTextThreeRed->setPos(384,230);
         endRedThree->setPos(463,230);
    }

    if(!dataThreeActive){
        instrumentClusterScene->addItem(dataTextThree);
        instrumentClusterScene->addItem(dataTextThreeWhite);
        dataThreeActive = true;
        isWhiteThree = true;
    }
    else if(isWhiteThree){
        instrumentClusterScene->removeItem(dataTextThree);
        instrumentClusterScene->removeItem(dataTextThreeWhite);
        instrumentClusterScene->addItem(dataTextThreeC);
        instrumentClusterScene->addItem(dataTextThreeRed);
        instrumentClusterScene->addItem(endRedThree);
        isWhiteThree = false;
        isRedThree = true;
    }
    else if(isRedThree){
        instrumentClusterScene->removeItem(dataTextThreeC);
        instrumentClusterScene->removeItem(dataTextThreeRed);
        instrumentClusterScene->removeItem(endRedThree);
        instrumentClusterScene->addItem(dataTextThree);
        instrumentClusterScene->addItem(dataTextThreeWhite);
        isWhiteThree = true;
        isRedThree = false;
    }else{
        return;
    }
}

void MainWindow::AnimateDataFour(){
    if(itemCount == 1){
        dataTextFour->setPos(45,230);
        dataTextFourC->setPos(45,230);
        dataTextFourWhite->setPos(384,230);
        dataTextFourRed->setPos(384,230);
        endRedFour->setPos(463,230);
    }
    else if(itemCount == 2 && dataThreeActive){
        dataTextFour->setPos(45,260);
        dataTextFourC->setPos(45,260);
        dataTextFourWhite->setPos(384,260);
        dataTextFourRed->setPos(384,260);
        endRedFour->setPos(463,260);
    }
    else if(itemCount == 2 && dataFiveActive){
            dataTextFive->setPos(45,260);

            dataTextFour->setPos(45,230);
            dataTextFourC->setPos(45,230);
            dataTextFourWhite->setPos(384,230);
            dataTextFourRed->setPos(384,230);
            endRedFour->setPos(463,230);
        }
    else if(itemCount == 3 && dataThreeActive && dataFiveActive){

        dataTextFive->setPos(45,290);

        dataTextFour->setPos(45,260);
        dataTextFourC->setPos(45,260);
        dataTextFourWhite->setPos(384,260);
        dataTextFourRed->setPos(384,260);
        endRedFour->setPos(463,260);

        dataTextThree->setPos(45,230);
        dataTextThreeC->setPos(45,230);
        dataTextThreeWhite->setPos(384,230);
        dataTextThreeRed->setPos(384,230);
        endRedThree->setPos(463,230);
    }

    if(!dataFourActive){
        instrumentClusterScene->addItem(dataTextFour);
        instrumentClusterScene->addItem(dataTextFourWhite);
        dataFourActive = true;
        isWhiteFour = true;
    }
    else if(isWhiteFour){
        instrumentClusterScene->removeItem(dataTextFour);
        instrumentClusterScene->removeItem(dataTextFourWhite);
        instrumentClusterScene->addItem(dataTextFourC);
        instrumentClusterScene->addItem(dataTextFourRed);
        instrumentClusterScene->addItem(endRedFour);
        isWhiteFour = false;
        isRedFour = true;
    }
    else if(isRedFour){
        instrumentClusterScene->removeItem(dataTextFourC);
        instrumentClusterScene->removeItem(dataTextFourRed);
        instrumentClusterScene->removeItem(endRedFour);
        instrumentClusterScene->addItem(dataTextFour);
        instrumentClusterScene->addItem(dataTextFourWhite);
        isWhiteFour = true;
        isRedFour = false;
    }else{
        return;
    }
}

void MainWindow::AnimateDataFive(){
    if(itemCount == 1){
        dataTextFive->setPos(45,230);

    }
    else if(itemCount == 2 && dataThreeActive){

        dataTextFive->setPos(45,260);

    }
    else if(itemCount == 2 && dataFourActive){
        dataTextFive->setPos(45,260);

        dataTextFour->setPos(45,230);
        dataTextFourC->setPos(45,230);
        dataTextFourWhite->setPos(384,230);
        dataTextFourRed->setPos(384,230);
        endRedFour->setPos(463,230);
    }
    else if(itemCount == 3 && dataThreeActive && dataFourActive){
        dataTextFive->setPos(45,290);

    }

    if(!dataFiveActive){
        instrumentClusterScene->addItem(dataTextFive);
        dataFiveActive = true;
    }
    else{
        return;
    }
}

void MainWindow::on_On_Off_One_clicked(){
    toggleOn = !toggleOn;

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
}

void MainWindow::on_On_Off_Two_clicked(){
    toggleOnTwo = !toggleOnTwo;

    if (toggleOnTwo){
    instrumentClusterScene->removeItem(rTurn);
    instrumentClusterScene->addItem(rightBlinkerAnimation);
    }
    else if (!toggleOnTwo){
        instrumentClusterScene->removeItem(rightBlinkerAnimation);
        instrumentClusterScene->addItem(rTurn);
    }
}

void MainWindow::on_On_Off_Three_clicked(){
    toggleOnThree = !toggleOnThree;

    if (toggleOnThree){
        itemCount++;
        timerFive->start(800);
         qDebug()<< itemCount;

    }
    else if (!toggleOnThree){
        timerFive->stop();
        itemCount--;
         qDebug()<< itemCount;
         instrumentClusterScene->removeItem(dataTextFive);
         dataFiveActive = false;
    }

}

void MainWindow::on_On_Off_Four_clicked(){
    toggleOnFour = !toggleOnFour;

    if (toggleOnFour){

        itemCount++;
        timerFour->start(700);

        qDebug()<< itemCount;
        instrumentClusterScene->removeItem(speed);
        instrumentClusterScene->addItem(speedAnimation);
    }
    else if(!toggleOnFour){
        timerFour->stop();
        itemCount--;
        qDebug()<< itemCount;
        instrumentClusterScene->removeItem(speedAnimation);
        instrumentClusterScene->addItem(speed);

        if(isWhiteFour){
            instrumentClusterScene->removeItem(dataTextFour);
            instrumentClusterScene->removeItem(dataTextFourWhite);
            dataFourActive = false;
            isRedFour = false;
            isWhiteFour =false;
        }
        else if(isRedFour){
            instrumentClusterScene->removeItem(dataTextFourC);
            instrumentClusterScene->removeItem(dataTextFourRed);
            instrumentClusterScene->removeItem(endRedFour);
            dataFourActive = false;
            isRedFour = false;
            isWhiteFour =false;
        }
    }
}

void MainWindow::on_send_Button_clicked(){
    QString canFrameData = ui->lineEdit->text();
    QString ArbitrationId = ui->lineEdit_2->text();
    QString dataTextFour = "AB FG HE XA YB FS F4 FF";
    QString dataTextFourArbId = "215";

    if(canFrameData == dataTextFour && dataTextFourArbId == ArbitrationId){
        on_On_Off_Four_clicked();
    }
}

void MainWindow::on_actionVirtual_IC_triggered(){
    aboutVIC = new AboutVIC();
    aboutVIC->show();
}

void MainWindow::on_actionTerminal_triggered(){
       QProcess *openTerminal = new QProcess();
       QString programPath = "/usr/bin/gnome-terminal";
       QStringList arguments;
       arguments << "--working-directory=/Home";
       openTerminal->start(programPath,arguments);
}
