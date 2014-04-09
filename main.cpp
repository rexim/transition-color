#include <QApplication>

#include "./timerwithdeltatime.hpp"
#include "./transitioncolorengine.hpp"
#include "./colorwidget.hpp"
#include "./mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TimerWithDeltaTime timer;
    TransitionColorEngine transitionColorEngine;
    MainWindow mainWindow;

    QObject::connect(&timer,
                     SIGNAL(timeout(int)),
                     &transitionColorEngine,
                     SLOT(tick(int)));
    QObject::connect(&transitionColorEngine,
                     SIGNAL(currentColorChanged(const QColor&)),
                     mainWindow.getMainColorWidget(),
                     SLOT(changeBackgroundColor(const QColor&)));
    QObject::connect(&mainWindow,
                     SIGNAL(transitionTargetConfirmed(const QColor&, int)),
                     &transitionColorEngine,
                     SLOT(transitionTo(const QColor&, int)));

    timer.start(30);
    mainWindow.show();


    return app.exec();
}
