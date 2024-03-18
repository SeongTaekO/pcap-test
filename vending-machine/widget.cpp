#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
// "": search from current directory
// <>: search from system directory

//int money{0};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    check_left(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::check_left(int left){
    ui -> pbCoffee -> setEnabled(left >= 100);
    ui -> pbTea -> setEnabled(left >= 200);
    ui -> pbTang -> setEnabled(left >= 300);
    ui -> pbReset -> setEnabled(left > 0);
}

void Widget::changeMoney(int left) {
    money += left;
    ui -> lcdNumber -> display(money);
    check_left(money);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbTang_clicked()
{
    changeMoney(-300);
}

void Widget::on_pbReset_clicked()
{
    exchange(money);
}

void Widget::exchange(int left) {
    int left500, left100, left50, left10;
    QString msg;

    left500 = left / 500;
    left = left % 500;
    left100 = left / 100;
    left = left % 100;
    left50 = left / 50;
    left = left % 50;
    left10 = left / 10;

    if (left500 > 0) {
        msg += "500: "+QString::number(left500)+"\t";
    }

    if (left100 > 0) {
        msg += "100: "+QString::number(left100)+"\t";
    }

    if (left50 > 0) {
        msg += "50: "+QString::number(left50)+"\t";
    }

    if (left10 > 0) {
        msg += "10: "+QString::number(left10)+"\t";
    }

    QMessageBox mb = QMessageBox();
    mb.information(nullptr, "title", msg);
}
