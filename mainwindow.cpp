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
    ui->previewColorWidget->changeBackgroundColor(
        QColor(ui->redSlider->value(),
               ui->greenSlider->value(),
               ui->blueSlider->value()));
}

void MainWindow::goButtonClicked()
{
    emit transitionTargetConfirmed(
        ui->previewColorWidget->getBackgroundColor(), 1000);
}

ColorWidget *MainWindow::getMainColorWidget() const
{
    return ui->mainColorWidget;
}
