#include <QApplication>
#include "./transitioncolorwidget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TransitionColorWidget transitionColorWidget(Qt::blue, Qt::red, 500);
    transitionColorWidget.resize(800, 600);
    transitionColorWidget.show();

    return app.exec();
}
