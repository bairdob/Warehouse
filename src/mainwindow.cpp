#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    database.connect();

    if (database.open()){
          //refreshContainerData();
    }
    else {
        QMessageBox::information(this, "failed", "Connection failed");
    }

    ui->label_7->setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
    ui->label_8->setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
    ui->label_9->setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 10, 560, 250);

//    initQVectorQRCode();
//    foreach(auto it, vQRCode){
//        qDebug() << it->x << it->y;
//    }

    on_pushButton2D_clicked(); //emulate scene
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initQVectorRack(){
    QSqlTableModel model;
    model.setTable("rack");
    model.select();
    for (int i = 0; i < model.rowCount(); ++i) {
        int id = model.record(i).value("rack_id").toInt();
        QString name = model.record(i).value("rack_name").toString();
        int x = model.record(i).value("rack_position_x").toInt();
        int y = model.record(i).value("rack_position_y").toInt();
        int height = model.record(i).value("rack_height").toInt();
        int width = model.record(i).value("rack_width").toInt();
        int shelves = model.record(i).value("rack_shelves").toInt();
        int places = model.record(i).value("rack_places").toInt();
        Rack *temp = new Rack(id, &name, x, y, height, width, shelves, places);
//        qDebug() << *temp;
        vRack.push_back(temp);
    }
}


void MainWindow::initQVectorQRCode(){
    QSqlTableModel model;
    model.setTable("qrcode");
    model.select();
    for (int i = 0; i < model.rowCount(); ++i) {
        int id = model.record(i).value("qrcode_id").toInt();
        QString name = model.record(i).value("qrcode_name").toString();
        int x = model.record(i).value("qrcode_position_x").toInt();
        int y = model.record(i).value("qrcode_position_y").toInt();
        QRCode *temp = new QRCode(id, &name, x, y);
        temp->setImage(":/pic/pic/QRCode.png");
//        qDebug() << *temp;
        vQRCode.push_back(temp);
    }
}

void MainWindow::initQVectorContainer(){
    QSqlTableModel model;
    model.setTable("container");
    model.select();
    for (int i = 0; i < model.rowCount(); ++i) {
        int id = model.record(i).value("container_id").toInt();
        QString name = model.record(i).value("container_name").toString();
        int rack_id = model.record(i).value("rack_id").toInt();
        int shelve = model.record(i).value("container_shelve").toInt();
        int place = model.record(i).value("container_place").toInt();
        Container *temp = new Container(id, &name, rack_id, shelve, place);
        qDebug() << *temp;
        vContainer.push_back(temp);
    }
}


void MainWindow::on_toolButtonMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    this->setWindowTitle("MainWindow");
    on_pushButton2D_clicked();
}


void MainWindow::on_toolButtonContainer_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->setWindowTitle("Container");
    refreshContainerData();
}


void MainWindow::on_toolButtonQRCode_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    this->setWindowTitle("QRCode");
    refreshQRCodeData();
}


void MainWindow::on_toolButtonClose_clicked()
{
    close();
}


void MainWindow::on_toolButtonRack_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    this->setWindowTitle("Rack");
    refreshRackData();
}


void MainWindow::on_pushButton3D_clicked()
{
//    QPixmap pix(":/pic/pic/3Dplan.png");
//    scene->clear();
//    scene->addPixmap(pix);
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton2D_clicked()
{
    vQRCode.clear();
    vRack.clear();
    vContainer.clear();
    scene->clear();

    initQVectorRack();
    foreach(auto it, vRack){
        scene->addItem(it);
    }

    initQVectorQRCode();
    foreach(auto it, vQRCode){
        scene->addItem(it);
    }

    initQVectorContainer();
    foreach(auto it, vContainer){
        scene->addItem(it);
    }
}


void MainWindow::refreshContainerData(){
    tableModel = new QSqlTableModel();
    tableModel->setTable("container");
    tableModel->setSort(0, Qt::AscendingOrder);
    tableModel->select();
    tableModel->setHeaderData(0, Qt::Horizontal, tr("container_id"));
    tableModel->setHeaderData(1, Qt::Horizontal, tr("name"));
    tableModel->setHeaderData(2, Qt::Horizontal, tr("rack_id"));
    tableModel->setHeaderData(3, Qt::Horizontal, tr("shelve"));
    tableModel->setHeaderData(4, Qt::Horizontal, tr("place"));

    ui->tableViewContainer->setModel(tableModel);
    ui->tableViewContainer->resizeRowsToContents();
    ui->tableViewContainer->resizeColumnsToContents();

    queryModel = new QSqlQueryModel();
    queryModel->setQuery("SELECT rack_id FROM rack;");
    ui->comboBoxContainerRackNumber->setPlaceholderText(QStringLiteral("(rack id)"));
    ui->comboBoxContainerRackNumber->setModel(queryModel);
    //ui->comboBoxContainerRackNumber->setCurrentIndex(-1);
}


void MainWindow::refreshQRCodeData(){
    tableModel = new QSqlTableModel();
    tableModel->setTable("qrcode");
    tableModel->setSort(0, Qt::AscendingOrder);
    tableModel->select();
    tableModel->setHeaderData(0, Qt::Horizontal, tr("qrcode_id"));
    tableModel->setHeaderData(1, Qt::Horizontal, tr("name"));
    tableModel->setHeaderData(2, Qt::Horizontal, tr("positionX"));
    tableModel->setHeaderData(3, Qt::Horizontal, tr("positionY"));

    ui->tableViewQRCode->setModel(tableModel);
    ui->tableViewQRCode->resizeRowsToContents();
    ui->tableViewQRCode->resizeColumnsToContents();
}


void MainWindow::refreshRackData(){
    tableModel = new QSqlTableModel();
    tableModel->setTable("rack");
    tableModel->setSort(0, Qt::AscendingOrder);
    tableModel->select();
    tableModel->setHeaderData(0, Qt::Horizontal, tr("rack_id"));
    tableModel->setHeaderData(1, Qt::Horizontal, tr("name"));
    tableModel->setHeaderData(2, Qt::Horizontal, tr("positionX"));
    tableModel->setHeaderData(3, Qt::Horizontal, tr("positionY"));
    tableModel->setHeaderData(4, Qt::Horizontal, tr("height"));
    tableModel->setHeaderData(5, Qt::Horizontal, tr("width"));
    tableModel->setHeaderData(6, Qt::Horizontal, tr("shelves"));
    tableModel->setHeaderData(7, Qt::Horizontal, tr("places"));

    ui->tableViewRack->setModel(tableModel);
    ui->tableViewRack->resizeRowsToContents();
    ui->tableViewRack->resizeColumnsToContents();
}


void MainWindow::on_toolButtonQRCodeSave_clicked()
{
    refreshQRCodeData();
}


void MainWindow::on_toolButtonContainerSave_clicked()
{
    refreshContainerData();
}


void MainWindow::on_tableViewContainer_pressed(const QModelIndex &index)
{
    selectStr = index.sibling(index.row(),0).data().toString();
    QString selectName = index.sibling(index.row(),1).data().toString();
    QString selectRack = index.sibling(index.row(),2).data().toString();
    QString selectShelf = index.sibling(index.row(),3).data().toString();
    QString selectPosition = index.sibling(index.row(),4).data().toString();
    //qDebug() << selectName << selectRack << selectShelf << selectPosition;

    ui->lineEditContainerName->setText(selectName);
    ui->comboBoxContainerRackNumber->setCurrentIndex(ui->comboBoxContainerRackNumber->findText(selectRack));
    ui->comboBoxContainerShelfNumber->setCurrentIndex(ui->comboBoxContainerShelfNumber->findText(selectShelf));
    ui->comboBoxContainerPositionNumber->setCurrentIndex(ui->comboBoxContainerPositionNumber->findText(selectPosition));
}


void MainWindow::on_tableViewQRCode_pressed(const QModelIndex &index)
{
    selectStr = index.sibling(index.row(),0).data().toString();
    QString selectName = index.sibling(index.row(),1).data().toString();
    QString selectPositionX = index.sibling(index.row(),2).data().toString();
    QString selectPositionY = index.sibling(index.row(),3).data().toString();
    //qDebug() << selectName << selectPositionX << selectPositionY;

    ui->lineEditQRCodeName->setText(selectName);
    ui->lineEditQRCodeHorizontalPosition->setText(selectPositionX);
    ui->lineEditQRCodeVerticalPostion->setText(selectPositionY);
}


void MainWindow::on_tableViewRack_pressed(const QModelIndex &index)
{
    selectStr = index.sibling(index.row(),0).data().toString();
    QString selectName = index.sibling(index.row(),1).data().toString();
    QString selectPositionX = index.sibling(index.row(),2).data().toString();
    QString selectPositionY = index.sibling(index.row(),3).data().toString();
    QString selectHeight = index.sibling(index.row(),4).data().toString();
    QString selectWidth = index.sibling(index.row(),5).data().toString();
    QString selectShelves = index.sibling(index.row(),6).data().toString();
    QString selectPlaces = index.sibling(index.row(),7).data().toString();

//    qDebug() << selectName << selectPositionX << selectPositionY
//    << selectHeight << selectWidth << selectShelves << selectShelves;

    ui->lineEditRackName->setText(selectName);
    ui->lineEditRackHorizontalPosition->setText(selectPositionX);
    ui->lineEditRackVerticalPosition->setText(selectPositionY);
    ui->lineEditRackHeight->setText(selectHeight);
    ui->lineEditRackWidth->setText(selectWidth);
    ui->lineEditRackNumberShelves->setText(selectShelves);
    ui->lineEditRackNumberPlaces->setText(selectPlaces);
}


void MainWindow::on_comboBoxContainerRackNumber_currentIndexChanged(int index) //smart choice for shelve and place
{
    Q_UNUSED(index);
    ui->comboBoxContainerShelfNumber->clear();
    ui->comboBoxContainerPositionNumber->clear();

    QSqlQuery query;
    query.prepare("SELECT * FROM rack WHERE rack_id = :id;");
    query.bindValue(":id", ui->comboBoxContainerRackNumber->currentText().toInt());
    query.exec();
    query.first();

    int rack_shelves = query.value(6).toInt();
    int rack_places = query.value(7).toInt();
//    qDebug() <<  query.value(6).toInt() << query.value(7).toInt();

    for (int i = 1; i <= rack_shelves; i++){
        ui->comboBoxContainerShelfNumber->addItem(QString::number(i));
    }

    for (int i = 1; i <= rack_places; i++){
        ui->comboBoxContainerPositionNumber->addItem(QString::number(i));
    }
    //ui->comboBoxContainerRackNumber->model()->sort(0, Qt::DescendingOrder);
}


void MainWindow::on_toolButtonContainerAdd_clicked()
{
    if (ui->lineEditContainerName->text() != ""){
        qDebug() << ui->lineEditContainerName->text() << ui->comboBoxContainerRackNumber->currentText() <<
                    ui->comboBoxContainerShelfNumber->currentText() << ui->comboBoxContainerPositionNumber->currentText();
        QSqlQuery query;
        query.prepare("INSERT INTO container(container_name, rack_id, container_shelve, container_place) \
                      VALUES (:name, :rack_id, :shelf, :place);");
        query.bindValue(":name", ui->lineEditContainerName->text());
        query.bindValue(":rack_id", ui->comboBoxContainerRackNumber->currentText());
        query.bindValue(":shelf", ui->comboBoxContainerShelfNumber->currentText());
        query.bindValue(":place", ui->comboBoxContainerPositionNumber->currentText());
        query.exec();
        refreshContainerData();
    }
}


void MainWindow::on_toolButtonContainerDelete_clicked(){
        QSqlQuery query;
        query.prepare("DELETE FROM container WHERE container_id = :id;");
        query.bindValue(":id", selectStr);
        query.exec();

        refreshContainerData();
}


void MainWindow::on_toolButtonQRCodeAdd_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO qrcode(qrcode_name, qrcode_position_x, qrcode_position_y) \
                          VALUES (:name, :position_x, :position_y);");
//    qDebug() << ui->lineEditQRCodeName->text() << ui->lineEditQRCodeHorizontalPosition->text() <<
//                    ui->lineEditQRCodeVerticalPostion->text();

    if (ui->lineEditQRCodeName->text() != ""){
        query.bindValue(":name", ui->lineEditQRCodeName->text());
    }
    if (ui->lineEditQRCodeHorizontalPosition->text() != ""){
            query.bindValue(":position_x", ui->lineEditQRCodeHorizontalPosition->text());
    }
    if (ui->lineEditQRCodeVerticalPostion->text() != ""){
            query.bindValue(":position_y", ui->lineEditQRCodeVerticalPostion->text());
    }

    query.exec();

    refreshQRCodeData();
}


void MainWindow::on_toolButtonQRCodeDelete_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM qrcode WHERE qrcode_id = :id;");
    query.bindValue(":id", selectStr);
    query.exec();

    refreshQRCodeData();
}


void MainWindow::on_toolButtonRackDelete_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM rack WHERE rack_id = :id;");
    query.bindValue(":id", selectStr);
    query.exec();

    refreshRackData();
}


void MainWindow::on_toolButtonRackAdd_clicked()
{
    QSqlQuery query;
    query.prepare("INSERT INTO rack (rack_name, rack_position_x, rack_position_y, \
                               rack_height, rack_width,rack_shelves, rack_places)  \
                   VALUES (:name, :position_x, :position_y, :height, :width, :shelves, :places);");
//    qDebug() << ui->lineEditRackName->text() << ui->lineEditRackHorizontalPosition->text() <<
//                    ui->lineEditRackVerticalPosition->text() << ui->lineEditRackNumberShelves->text() <<
//                    ui->lineEditRackNumberPlaces->text();

    if (ui->lineEditRackName->text() != ""){
        query.bindValue(":name", ui->lineEditRackName->text());
    }
    if (ui->lineEditRackHorizontalPosition->text() != ""){
        query.bindValue(":position_x", ui->lineEditRackHorizontalPosition->text());
    }
    if (ui->lineEditRackVerticalPosition->text() != ""){
        query.bindValue(":position_y", ui->lineEditRackVerticalPosition->text());
    }
    if (ui->lineEditRackHeight->text()!= ""){
        query.bindValue(":height", ui->lineEditRackHeight->text());
    }
    if (ui->lineEditRackWidth->text() != ""){
        query.bindValue(":width", ui->lineEditRackWidth->text());
    }
    if (ui->lineEditRackNumberShelves->text()!= ""){
        query.bindValue(":shelves", ui->lineEditRackNumberShelves->text());
    }
    if (ui->lineEditRackNumberPlaces->text() != ""){
        query.bindValue(":places", ui->lineEditRackNumberPlaces->text());
    }

    query.exec();
    refreshRackData();
}
