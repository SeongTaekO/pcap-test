#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    int money{0};
    void check_left(int left);
    void changeMoney(int left);
    void exchange(int left);

    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pbCoin10_clicked();

    void on_pbCoin50_clicked();

    void on_pbCoin100_clicked();

    void on_pbCoin500_clicked();

    void on_pbCoffee_clicked();

    void on_pbTea_clicked();

    void on_pbTang_clicked();

    void on_pbReset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
