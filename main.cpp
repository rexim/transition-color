#include <QApplication>

#include "./timerwithdeltatime.hpp"
#include "./colortransitor.hpp"
#include "./colorwidget.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TimerWithDeltaTime timer;
    ColorTransitor colorTransitor(Qt::red);
    ColorWidget colorWidget;

    QObject::connect(&timer, SIGNAL(timeout(int)),
                     &colorTransitor, SLOT(tick(int)));
    QObject::connect(&colorTransitor, SIGNAL(currentColorChanged(const QColor&)),
                     &colorWidget, SLOT(changeBackgroundColor(const QColor&)));

    timer.start(30);
    colorWidget.show();
    colorTransitor.transitionTo(Qt::blue, 1000);

    return app.exec();
}
