#ifndef QRCODE_H
#define QRCODE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QPixmap>


class QRCode : public QGraphicsItem
{
public:
    QRCode();
    QRCode(int _id, QString *_name, int _x,int _y);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;
    void setGeometry(int x, int y);
    ~QRCode();
    friend QDebug operator<<(QDebug stream, const QRCode &QRCode);
    void setImage(QString path);

//private:
    int id;
    QString *name;
    int x;
    int y;
    int height{20};
    int width{20};
    QPixmap pix;
};

#endif // QRCODE_H
