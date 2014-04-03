#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QWidget>

class ColorWidget;

namespace Ui {
    class MainWindow;
}  // namespace Ui

class MainWindow: public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    ColorWidget *getMainColorWidget() const;

signals:
    void transitionTargetConfirmed(const QColor &targetColor,
                                   int duration);

private slots:
    void targetColorChanged();
    void goButtonClicked();

private:
    Ui::MainWindow *ui;
};

#endif  // MAINWINDOW_HPP_
