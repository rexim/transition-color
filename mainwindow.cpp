#include "./colorwidget.hpp"
#include "./mainwindow.hpp"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::targetColorChanged()
{
    QColor backgroundColor(ui->redSlider->value(),
                           ui->greenSlider->value(),
                           ui->blueSlider->value());
    ui->previewColorWidget->changeBackgroundColor(backgroundColor);
}

void MainWindow::goButtonClicked()
{
    QColor backgroundColor = ui->previewColorWidget->getBackgroundColor();
    emit transitionTargetConfirmed(backgroundColor, 1000);
}

ColorWidget *MainWindow::getMainColorWidget() const
{
    return ui->mainColorWidget;
}
