#ifndef CONTAINER_H
#define CONTAINER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QSqlQuery>


class Container : public QGraphicsItem
{
public:
    Container();
    Container(int _id, QString *_name, int _rack_id, int _shelve, int _place);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    ~Container();
    friend QDebug operator<<(QDebug stream, const Container &Container);

private:
    int id;
    QString *name;
    int rack_id;
    int shelve;
    int place;
    int x{0};
    int y{0};
    int height{50};
    int width{50};
};

#endif // CONTAINER_H
