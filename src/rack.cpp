#include "rack.h"


Rack::Rack()
{

}


Rack::Rack(int _id, QString *_name, int _x,int _y, int _height, int _width, int _shelves, int _places)
{
    id = _id;
    x = _x;
    y = _y;
    name = _name;
    height = _height;
    width = _width;
    shelves = _shelves;
    places = _places;
}


QRectF Rack::boundingRect() const{
    return QRectF(0, 0, width, height);
}


void Rack::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(item);
    Q_UNUSED(widget);

    //draw rack rectangle + container_id text
    painter->drawRoundedRect(x, y, height, width, 5, 5);
    painter->drawText(x,y, "r_id=" + QVariant(id).toString());

    //draw place lines
    int step = width / places;
    for (int i = 1; i < places; i++){
        painter->drawLine(x, y + step*i, x + height, y + step*i);
    }
}


void Rack::setGeometry(int x, int y){
    height = x;
    width = y;
}


Rack::~Rack(){

}


QDebug operator<<(QDebug stream, const Rack &rack) {
    stream << rack.id << *rack.name << rack.x << rack.y << rack.height << rack.width << rack.shelves << rack.places;
    return stream;
}
