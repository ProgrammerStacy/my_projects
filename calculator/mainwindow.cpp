#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->B0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->B_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->B_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->B_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->B_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->B_multiplication, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->B_division, SIGNAL(clicked()), this, SLOT(math_operations()));

    ui->B_plus->setCheckable(true);
    ui->B_division->setCheckable(true);
    ui->B_minus->setCheckable(true);
    ui->B_multiplication->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::digit_numbers()
{
    QPushButton * button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;
    if (ui->result_show->text().contains(".") && button->text() == "0")
    {
        new_label = ui ->result_show->text() + button->text();
    }
    else
    {
    all_numbers = (ui->result_show->text() + button->text()).toDouble();
    new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->result_show->setText(new_label);
}

void MainWindow::on_B_dot_clicked()
{
    if (!(ui->result_show->text().contains(".")))
    ui->result_show->setText(ui->result_show->text() + ".");
}
void MainWindow::operations()
{
    QPushButton * button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= -1;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    }
    else if(button->text() == "%") {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers *= 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    }

}

void MainWindow::on_B_AC_clicked()
{
    ui->B_division->setChecked(false);
    ui->B_plus->setChecked(false);
    ui->B_minus->setChecked(false);
    ui->B_multiplication->setChecked(false);

    ui->result_show->setText("0");
}


void MainWindow::on_B_enter_clicked()

{
    double labelNumber, num_second;
    QString new_label;
    num_second = ui->result_show->text().toDouble();
    if(ui->B_plus->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->B_plus->setChecked(false);
    }
    else if(ui->B_multiplication->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->B_multiplication->setChecked(false);
    }
    else if(ui->B_division->isChecked())
    {
        if (num_second == 0)
        {
            ui->result_show->setText("0");
        }
        else {
        labelNumber = num_first / num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);

        }
        ui->B_division->setChecked(false);
    }
    else if(ui->B_minus->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->result_show->setText(new_label);
        ui->B_minus->setChecked(false);
    }
}
void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();
    num_first = ui->result_show->text().toDouble();
    ui->result_show->setText("");
    button->setChecked(true);
}

