#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void handleNetFinished(QNetworkReply* reply);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* mNetManager;

};
#endif // MAINWINDOW_H
