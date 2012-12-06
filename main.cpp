#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"
#include <QTimerEvent>
#include <QObject>


#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec> // подключение класса кодека текста
#include <QtGui/QApplication>
#include <QDeclarativeView>
#include <QUrl>
#include <QDeclarativeContext>


class MyTimer: public QObject
{
public:
    MyTimer(QmlApplicationViewer* view):
        view_(view),
        firstPage(true)
    {
        startTimer(10000);
    }
protected:
    void timerEvent(QTimerEvent *event)
    {
        Q_UNUSED(event);

        firstPage = !firstPage;

        if(firstPage)
            view_->setMainQmlFile(QLatin1String("qml/qmlBooks/main.qml"));
        else
            view_->setMainQmlFile(QLatin1String("qml/qmlBooks/main2.qml"));

    }

private:

    QmlApplicationViewer* view_;
    bool firstPage;

private slots:
    void read();//считать нажатие на кнопку

};





Q_DECL_EXPORT int main(int argc, char *argv[])
{


    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("qml/qmlBooks/main.qml"));
    viewer.showExpanded();

    MyTimer timer(&viewer);

    //

      QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251")); //изменени€
      QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251")); //изменени€
      QTextCodec::setCodecForTr(QTextCodec::codecForName("Windows-1251")); //изменени€

      QTextCodec *utfcodec = QTextCodec::codecForName("Windows-1251");

      QTextCodec::setCodecForTr(utfcodec);
      QTextCodec::setCodecForCStrings(utfcodec);

     // MainWindow w;
      //w.show();
    //

    return app->exec();

}
