#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    Q_INVOKABLE void FunctionC();//Функция C++ вызываемая из QML


private slots:
    void readHTML(); // Функция, извлекающая html код страницы по окончании загрузки
    void loadProgress(int progress);  // Функция, получающая текущее состояние загрузки (от 0 до 100)



private:
    QDeclarativeView *ui;
    QObject *Root;//корневой элемент QML модели
    QWebPage page;


};

QApplication *createApplication(int &argc, char **argv);



#endif // MAINWINDOW_H
