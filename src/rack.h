#ifndef RACK_H
#define RACK_H

#include <QGraphicsItem>
#include <QPainter>
#include <QString>
#include <QDebug>


class Rack : public QGraphicsItem
{
public:
    Rack();
    Rack(int _id, QString *_name, int _x,int _y, int _height, int _width, int _shelves, int _places);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void setGeometry(int x, int y);
    ~Rack();
    friend QDebug operator<<(QDebug stream, const Rack &rack);

private:
    int id;
    QString *name;
    int x;
    int y;
    int height{50};
    int width{50};
    int shelves;
    int places;
};

#endif // RACK_H
