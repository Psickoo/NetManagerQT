#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mNetManager = new QNetworkAccessManager(this);
    connect(mNetManager, SIGNAL (finished(QNetworkReply*)),
            this , SLOT(handleNetFinished(QNetworkReply*)));
    ui -> lineEdit -> setText("https://s3.tradingview.com/m/mtTyK4bf_mid.png");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleNetFinished(QNetworkReply *reply)
{
    if (reply -> error() == QNetworkReply::NoError)
    {
        QByteArray data = reply -> readAll();
//        qDebug() << data;
        QImage image;
        image.loadFromData(data);
        ui -> label_2 -> setPixmap(QPixmap :: fromImage(image));
        ui -> label_2 -> setScaledContents(true);
    }

    else
        qDebug() << "Network Error : " << reply->errorString();

}


void MainWindow::on_pushButton_clicked()
{
    mNetManager -> get(QNetworkRequest(QUrl(ui->lineEdit->text())));
}

