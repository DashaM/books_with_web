#include "mainwindow.h"
//#include "proxytextedit.h"
//#include "all.h"
#include "qmlapplicationviewer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // �������� ��� QML
    ui = new QDeclarativeView;
     ui->setSource(QUrl("qrc:/qml/qmlBooks/main2.qml"));
     setCentralWidget(ui);
     ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    // ������� �������� �������
     Root = ui->rootObject();
     //��������� C++ � QML, ����� ������� ������� �++ ����� ������� window
     ui->rootContext()->setContextProperty("window", this);
}

MainWindow::~MainWindow()
{
    //������� QML
    delete ui;
}

void MainWindow::FunctionC()
{

    //������ ������ �����
    QObject* textinput = Root->findChild<QObject*>("textinput");

    QString str;//�������� ����� ��������� ����������

    //������� ���������� �� ������ ����� ����� �������� text
    str=(textinput->property("text")).toString();


    page.mainFrame()->load(str);
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(readHTML())); // ������ loadFinished ���������� �� ��������� �������� �������� ��������
    connect(&page, SIGNAL(loadProgress(int)), this, SLOT(loadProgress(int))); // ������ loadProgress ���������� ��� ������ ��������� ��������� ��������

    //
}

void MainWindow::loadProgress(int progress)
{
    qDebug() << "progress = " << progress; // ������� ������� ��������� �������� � qDebug()
}




void MainWindow::readHTML()
{


    qDebug() << page.mainFrame()->toHtml();//.toUtf8(); // ������� html ��� ��������

    QString str = page.mainFrame()->toHtml();//.toUtf8();
    QStringList List;
    QString s;


    QRegExp rx("<b>([^A-z]*)</b>");
            rx.setMinimal(true);

            int j=0;
             int pos = 0;
             while ((pos = rx.indexIn(str, pos)) != -1)
             {
                 pos += rx.matchedLength();

                 if (rx.cap(1).contains("("))
                 {
                     qDebug() << rx.cap(1);
                     s = rx.cap(1);
                     s=s.simplified();
                     s.chop(3);
                     List << s;

                 }

             }

                 qDebug() << List.join("\n");
                ui->rootContext()->setContextProperty("model2",QVariant::fromValue(List));


}

