#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char **argv){

    QApplication app(argc, argv);
    QLabel ola("<h1><center>Meu primeiro programa com Qt e C++");
    ola.setWindowTitle("Título da minha janela");
    ola.resize(600,400);
    ola.show();
    return app.exec();
}

/*
sudo apt install qtcreator build-essential qt5-qmake qtbase5-dev
qmake -project
QT += gui widgets
qmake
make
*/

