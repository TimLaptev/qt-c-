#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>

double num;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     setFixedSize(280,320);
    connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plucormin,SIGNAL(clicked()),this,SLOT(oper()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_ympoz,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->pushButton_sq,SIGNAL(clicked()),this,SLOT(sq()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_ympoz->setCheckable(true);
    ui->pushButton_del->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers(){//обработка нажатия
    QPushButton *button =(QPushButton*)sender();
    QString a;
    double b;
    if(ui->label->text().contains(".")&&button->text()=='0')
        a=ui->label->text()+button->text();
    else{
    b=(ui->label->text()+button->text()).toDouble();
    a=QString::number(b,'g',15);
    }
    ui->label->setText(a);
}

void MainWindow::oper(){//плюс-минус
    QPushButton *button =(QPushButton*)sender();
    QString a;
    double b;
    if(button->text()=="+/-"){//?
    b=(ui->label->text()).toDouble();
    b*=(-1);
    a=QString::number(b,'g',15);}
    ui->label->setText(a);
}
void MainWindow::on_pushButton_zap_clicked()//добавление точки
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text()+'.');
}
void MainWindow::math(){//обработка матем.опера

    QPushButton *button =(QPushButton*)sender();//это общее
    num=ui->label->text().toDouble();//первое число берем
    ui->label->setText("");
    button->setChecked(true);

}
void MainWindow::on_pushButton_rafens_clicked()//если нажали равно
{

    QString nl;
    double l,n;
    n=ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
       l=num+n;
       nl=QString::number(l,'g',15);
       ui->label->setText(nl);
       ui->pushButton_plus->setChecked(false);

     }
    else if (ui->pushButton_minus->isChecked()) {
        l=num-n;
        nl=QString::number(l,'g',15);
        ui->label->setText(nl);
        ui->pushButton_minus->setChecked(false);
    }
    else if(ui->pushButton_del->isChecked()){


        l=num/n;
        nl=QString::number(l,'g',15);
        ui->label->setText(nl);
        ui->pushButton_del->setChecked(false);

    }
    else if(ui->pushButton_ympoz->isChecked()){
        l=n*num;
        nl=QString::number(l,'g',15);
        ui->label->setText(nl);
        ui->pushButton_ympoz->setChecked(false);
    }

}


void MainWindow::on_pushButton_ac_clicked()
{
 ui->pushButton_plus->setChecked(false);
 ui->pushButton_minus->setChecked(false);
 ui->pushButton_del->setChecked(false);
 ui->pushButton_ympoz->setChecked(false);
 ui->label->setText("0");
}

void MainWindow::sq(){//корень

    QString a;
    double b;
    b=(ui->label->text()).toDouble();
    b=sqrt(b);
    a=QString::number(b,'g',15);
    ui->label->setText(a);


}

void MainWindow::on_comboBox_activated(int index)
{
    QString a;
    double b;
    b=(ui->label->text()).toDouble();
    if(index==0){
    b=sin(b);
    }
    else if(index==1){
        b=cos(b);
    }
    else if(index==2){
        b=tan(b);
    }
    else if(index==3){
        b=1/tan(b);
    }
    a=QString::number(b,'g',15);
    ui->label->setText(a);


}

