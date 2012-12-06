#include "main.h"
#include <QObject>
#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"



MainClick::MainClick(QWidget *parent) :
    QMainWindow(parent)
{
    // Включаем наш QML
    ui = new QDeclarativeView;
     ui->setSource(QUrl("qrc:/main.qml"));
     setCentralWidget(ui);
     ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    // Находим корневой элемент
     Root = ui->rootObject();
     //Соединяем C++ и QML, делая видимым функции С++ через элемент window
     ui->rootContext()->setContextProperty("window", this);
}




MainClick::~MainClick()
{
    //Удаляем QML
    delete ui;
}

void MainClick::FunctionClick()
{
    view_->setMainQmlFile(QLatin1String("qml/qmlBooks/main2.qml"));
}
