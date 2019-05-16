#ifndef DATATEXT_H
#define DATATEXT_H
#include <QGraphicsTextItem>
#include <QFont>

class DataText: public QGraphicsTextItem{

public:
    DataText(QGraphicsItem * parent=nullptr);

    void DataTextOne();
    void DataTextOneC();
    void DataTextOneWhite();
    void DataTextOneRed();
    void EndRedOne();

    void DataTextTwo();
    void DataTextTwoC();
    void DataTextTwoWhite();
    void DataTextTwoRed();
    void EndRedTwo();

public slots:


private:

};

#endif // DATATEXT_H
