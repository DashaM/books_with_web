#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec> // подключение класса кодека текста
#include <QtGui/QApplication>
#include <QDeclarativeView>
#include <QUrl>
#include <QDeclarativeContext>





int mainmy(int argc, char *argv[])
{   QApplication a(argc, argv);

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251")); //изменения
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251")); //изменения
    QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251")); //изменения

    QTextCodec *utfcodec = QTextCodec::codecForName("Windows-1251");

    QTextCodec::setCodecForTr(utfcodec);
    QTextCodec::setCodecForCStrings(utfcodec);




    MainWindow w;
    w.show();


    return a.exec();
}

