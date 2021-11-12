#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <rack.h>
#include <qrcode.h>
#include <container.h>

class Scene : public QOpenGLWidget
{
public:
    Scene(QWidget *parent = nullptr);

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void initQVectorQRCode();



    QVector<Rack*> vRack;
    QVector<QRCode*> vQRCode;
    QVector<Container*> vContainer;
};

#endif // SCENE_H
