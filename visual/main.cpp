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
1-- Instalar o qtcreator
sudo apt install qtcreator build-essential qt5-qmake qtbase5-dev

2-- Criar o projeto
qmake -project

3-- Adicionar essa linha no arquivo *.pro, logo abaixo de INCLUDEPATH
QT += gui widgets

4-- Executar o qmake
qmake

5-- Compilar o programa
make

6-- Executar o programa e ver se a janela aparece
*/
