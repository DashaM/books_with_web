#ifndef MAIN_H
#define MAIN_H
#include <QMainWindow>
#include <QtDeclarative/QDeclarativeView>
#include <QGraphicsObject>
#include <QtGui>
#include <QDeclarativeContext>

#include <QtWebKit/QWebPage>
#include <QtWebKit/QWebFrame>
#include <QDebug>

#include <QDeclarativeItem>
#include <QTextEdit>
#include <QGraphicsProxyWidget>
#include <QString>

#include <QDeclarativeView>

#include "qmlapplicationviewer.h"

namespace Ui {
    class MainClick;
}

class MainClick : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainClick(QWidget *parent = 0);
    ~MainClick();


    Q_INVOKABLE void FunctionClick();//Функция C++ вызываемая из QML



private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели
    QWebPage page;
     QmlApplicationViewer* view_;


};

QApplication *createApplication(int &argc, char **argv);


#endif // MAIN_H
