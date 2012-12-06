#include "mainwindow.h"
//#include "proxytextedit.h"
//#include "all.h"
#include "qmlapplicationviewer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    // Включаем наш QML
    ui = new QDeclarativeView;
     ui->setSource(QUrl("qrc:/qml/qmlBooks/main2.qml"));
     setCentralWidget(ui);
     ui->setResizeMode(QDeclarativeView::SizeRootObjectToView);

    // Находим корневой элемент
     Root = ui->rootObject();
     //Соединяем C++ и QML, делая видимым функции С++ через элемент window
     ui->rootContext()->setContextProperty("window", this);
}

MainWindow::~MainWindow()
{
    //Удаляем QML
    delete ui;
}

void MainWindow::FunctionC()
{

    //Найдем строку ввода
    QObject* textinput = Root->findChild<QObject*>("textinput");

    QString str;//Создадим новую строковую переменную

    //Считаем информацию со строки ввода через свойство text
    str=(textinput->property("text")).toString();


    page.mainFrame()->load(str);
    connect(&page, SIGNAL(loadFinished(bool)), this, SLOT(readHTML())); // сигнал loadFinished вызывается по окончании загрузки интернет страницы
    connect(&page, SIGNAL(loadProgress(int)), this, SLOT(loadProgress(int))); // сигнал loadProgress вызывается при каждом изменении состоянии загрузки

    //
}

void MainWindow::loadProgress(int progress)
{
    qDebug() << "progress = " << progress; // выводим текущее состояние загрузки в qDebug()
}




void MainWindow::readHTML()
{


    qDebug() << page.mainFrame()->toHtml();//.toUtf8(); // выводим html код страницы

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

