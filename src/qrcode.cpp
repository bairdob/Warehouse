#include "qrcode.h"

QRCode::QRCode()
{

}


QRCode::QRCode(int _id, QString *_name, int _x,int _y)
{
    id = _id;
    x = _x;
    y = _y;
    name = _name;
}


QRectF QRCode::boundingRect() const{
    return QRectF(0, 0, width, height);
}


void QRCode::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(item);
    Q_UNUSED(widget);

    //draw QRCode rectangle + qrcode_id text
    painter->drawRoundedRect(x, y, height, width, 5, 5);
    painter->setPen(Qt::darkYellow );
    painter->drawText(x,y, "qr_id=" + QVariant(id).toString());
    painter->drawPixmap(x, y, height, width, pix);

}


void QRCode::setGeometry(int x, int y){
    height = x;
    width = y;
}


void QRCode::setImage(QString path){
    pix.load(path);
}


QRCode::~QRCode(){

}


QDebug operator<<(QDebug stream, const QRCode &QRCode) {
    stream << QRCode.id << *QRCode.name << QRCode.x << QRCode.y << QRCode.height << QRCode.width;
    return stream;
 }
