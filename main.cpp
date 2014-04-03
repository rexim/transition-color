#include <QApplication>

#include "./timerwithdeltatime.hpp"
#include "./colortransitor.hpp"
#include "./colorwidget.hpp"
#include "./mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TimerWithDeltaTime timer;
    ColorTransitor colorTransitor;
    MainWindow mainWindow;

    QObject::connect(&timer,
                     SIGNAL(timeout(int)),
                     &colorTransitor,
                     SLOT(tick(int)));
    QObject::connect(&colorTransitor,
                     SIGNAL(currentColorChanged(const QColor&)),
                     mainWindow.getMainColorWidget(),
                     SLOT(changeBackgroundColor(const QColor&)));
    QObject::connect(&mainWindow,
                     SIGNAL(transitionTargetConfirmed(const QColor&, int)),
                     &colorTransitor,
                     SLOT(transitionTo(const QColor&, int)));

    timer.start(30);
    mainWindow.show();


    return app.exec();
}
