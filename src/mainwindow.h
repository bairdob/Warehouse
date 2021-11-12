#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QGraphicsScene>
#include <database.h>
#include <rack.h>
#include <qrcode.h>
#include <container.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //navigation
    void on_toolButtonMain_clicked();
    void on_toolButtonContainer_clicked();
    void on_toolButtonQRCode_clicked();
    void on_toolButtonRack_clicked();
    void on_toolButtonClose_clicked();
    void on_pushButton3D_clicked();
    void on_pushButton2D_clicked();

    //tab container
    void on_toolButtonContainerAdd_clicked();
    void on_toolButtonContainerSave_clicked();
    void on_toolButtonContainerDelete_clicked();
    void on_tableViewContainer_pressed(const QModelIndex &index);
    void on_comboBoxContainerRackNumber_currentIndexChanged(int index); //smart choice for shelve and place

    //tab qrcode
    void on_toolButtonQRCodeAdd_clicked();
    void on_toolButtonQRCodeSave_clicked();
    void on_toolButtonQRCodeDelete_clicked();
    void on_tableViewQRCode_pressed(const QModelIndex &index);

    //tab rack
    void on_toolButtonRackAdd_clicked();
    void on_toolButtonRackDelete_clicked();
    void on_tableViewRack_pressed(const QModelIndex &index);

    void refreshContainerData();
    void refreshQRCodeData();
    void refreshRackData();

public:
    //2d draw
    void initQVectorRack();
    void initQVectorQRCode();
    void initQVectorContainer();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *tableModel;
    QSqlQueryModel *queryModel;
    Database database;
    QString selectStr;

    QGraphicsScene *scene;
    QVector<Rack*> vRack;
    QVector<QRCode*> vQRCode;
    QVector<Container*> vContainer;
};

#endif // MAINWINDOW_H
