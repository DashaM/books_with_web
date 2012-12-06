#include "main.h"
#include <QObject>
#include <QtGui/QApplication>
#include "qmlapplicationviewer.h"



MainClick::MainClick(QWidget *parent) :
    QMainWindow(parent)
{
    // �������� ��� QML
    ui = new QDeclarativeView;
     ui->setSource(QUrl("qrc:/main.qml"));
     setCentralWidget(ui);
     ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    // ������� �������� �������
     Root = ui->rootObject();
     //��������� C++ � QML, ����� ������� ������� �++ ����� ������� window
     ui->rootContext()->setContextProperty("window", this);
}




MainClick::~MainClick()
{
    //������� QML
    delete ui;
}

void MainClick::FunctionClick()
{
    view_->setMainQmlFile(QLatin1String("qml/qmlBooks/main2.qml"));
}
