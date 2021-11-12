#include "container.h"

Container::Container()
{

}

Container::Container(int _id, QString *_name, int _rack_id, int _shelve, int _place){
    id = _id;
    name = _name;
    rack_id = _rack_id;
    shelve = _shelve;
    place = _place;

    QSqlQuery query;
    query.prepare("SELECT * FROM rack WHERE rack_id = :id;");
    query.bindValue(":id", _rack_id);
    query.exec();
    query.first();

    //находим размеры контейнера, чтобы вписать в место
    height =  query.value(4).toInt();
    width = query.value(5).toInt() / query.value(7).toInt();

    //смещаем к центру места
    x = query.value(2).toInt();
    //if (place > 1) place -=1;
//    double step = query.value(5).toInt() / _place;
//    qDebug() << step;
    y = query.value(3).toInt()*place;
    //y = query.value(3).toInt() + step * place;
}


QRectF Container::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Container::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget){
    Q_UNUSED(item);
    Q_UNUSED(widget);

    //draw container rectangle + container_id text
    painter->setPen(Qt::red );
    painter->drawRoundedRect(x, y, height, width, 5, 5);
    painter->drawText(x, y+10, "c_id=" + QVariant(id).toString());

}


QDebug operator<<(QDebug stream, const Container &Container) {
    stream << Container.id << *Container.name << Container.rack_id <<Container.shelve << Container.place <<
              Container.x << Container.y << Container.height << Container.width ;
    return stream;
}


Container::~Container(){

}
