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


    Q_INVOKABLE void FunctionC();//������� C++ ���������� �� QML


private slots:
    void readHTML(); // �������, ����������� html ��� �������� �� ��������� ��������
    void loadProgress(int progress);  // �������, ���������� ������� ��������� �������� (�� 0 �� 100)



private:
    QDeclarativeView *ui;
    QObject *Root;//�������� ������� QML ������
    QWebPage page;


};

QApplication *createApplication(int &argc, char **argv);



#endif // MAINWINDOW_H
