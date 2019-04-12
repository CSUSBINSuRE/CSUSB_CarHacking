#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":images_root/coyote_crop.png"));
    splash->show();

    MainWindow w;
    w.setFixedSize(1200,700);
    w.setWindowIcon(QIcon(":images_root/coyote_crop.ico"));
    QTimer::singleShot(4000,splash,SLOT(close()));
    QTimer::singleShot(4000,&w,SLOT(show()));
    //w.show();

    return a.exec();
}
