#include "scene.h"
Scene::Scene(QWidget *parent) :
    QOpenGLWidget(parent)
{

}


void Scene::initializeGL(){
    glClearColor(0.1f, 0.1f, 0.2f, 0.1f);
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
}

void Scene::paintGL(){
    // Clear the window with current clearing color
    glClear( GL_COLOR_BUFFER_BIT );
    // Set current drawing color to red
    //		   R	 G	   B
    glColor3f( 1.0f, 0.0f, 0.0f );
    // Draw a filled rectangle with current color
    glRectf( 0, 0, 5, 5);
    glRectf( 11.0f, 5.0f, 13.0f, 7.0f );
    glRectf( 11.0f, 9.0f, 13.0f, 11.0f );
    glRectf( 27.0f, 17.0f, 29.0f, 19.0f );
    glRectf( 31.0f, 5.0f, 33.0f, 7.0f );
    glColor3f( 1.0f, 1.0f, 0.0f );
    glRectf( 5.0f, 3.0f, 10.0f, 12.0f );
    glRectf( 10.0f, 16.0f, 15.0f, 25.0f );
    glRectf( 25.0f, 3.0f, 30.0f, 12.0f );
    glRectf( 20.0f, 16.0f, 25.0f, 25.0f );
}


void Scene::resizeGL(int w, int h){
    // Prevent a divide by zero
        if( h == 0 ) {
            h = 1;
        }

        // Set Viewport to window dimensions
        glViewport( 0, 0, w, h );

        // Reset coordinate system
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();

        // Establish clipping volume (left, right, bottom, top, near, far)
        GLfloat aspectRatio = ( GLfloat )w / ( GLfloat )h;
        if ( w <= h ) {
            glOrtho( -100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio,
                      1.0, -1.0);
        } else {
            glOrtho( -100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0,
                     1.0, -1.0 );
        }

        //glTranslatef(-200.0, -50.0, 0.0);


        glMatrixMode( GL_MODELVIEW );
        glLoadIdentity();

}

void Scene::initQVectorQRCode(){
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
