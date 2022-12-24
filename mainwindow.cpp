#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first, w, q;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    connect(ui->pushButton_plusmin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_proc,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_del,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_umn,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_kor,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_nkor,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_sin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_cos,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_tg,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_ln,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_log2,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_logn,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_e,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_vkv,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_mod,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_fact,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_dB,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_Np,SIGNAL(clicked()),this,SLOT(math_operations()));



    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_del->setCheckable(true);
    ui->pushButton_umn->setCheckable(true);
    ui->pushButton_nkor->setCheckable(true);
    ui->pushButton_logn->setCheckable(true);
    ui->pushButton_dB->setCheckable(true);
    ui->pushButton_Np->setCheckable(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
   QPushButton *button = (QPushButton *)sender();

   double all_numbers;
   QString new_label;

   if(ui->label->text().contains(".") && button->text() == "0"){

        new_label = ui->label->text() + button->text();

   } else {

   all_numbers = (ui->label->text() + button->text()).toDouble();
   new_label = QString::number(all_numbers, 'g', 15);
   q=all_numbers;
}

   ui->label->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
       if(!(ui->label->text().contains('.')))
       ui->label->setText(ui->label->text() + ".");
}

void MainWindow::operations()
{
   QPushButton *button = (QPushButton *)sender();

   double all_numbers,n;
   QString new_label, oshibka;
oshibka="не определен";
   if(button->text() == "+/-"){
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_label = QString::number(all_numbers, 'g', 15);

        ui->label->setText(new_label);
    } else if(button->text() == "%"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = all_numbers * 0.01;
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "sin"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = sin(all_numbers * 3.14159265359 /180);
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "cos"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = cos(all_numbers * 3.14159265359 /180);
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "tg"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = tan(all_numbers * 3.14159265359 /180);
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "√"){
       all_numbers = (ui->label->text()).toDouble();
          if (all_numbers > 0){
       all_numbers = sqrt(all_numbers);
       new_label = QString::number(all_numbers, 'g', 15);}
         else  {new_label = oshibka;}
    } else if(button->text() == "ln"){
       all_numbers = (ui->label->text()).toDouble();
       if (all_numbers > 0){
       all_numbers = log(all_numbers);
       new_label = QString::number(all_numbers, 'g', 15);}
              else  {new_label = oshibka;}
    } else if(button->text() == "log2"){
       all_numbers = (ui->label->text()).toDouble();
       if(all_numbers > 0){
       all_numbers = log2(all_numbers);
       new_label = QString::number(all_numbers, 'g', 15);}
       else  {new_label = oshibka;}
    } else if(button->text() == "e"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = all_numbers - all_numbers + 2.71828182846 ;
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "x^2"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = all_numbers * all_numbers ;
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "|x|"){
       all_numbers = (ui->label->text()).toDouble();
       all_numbers = sqrt(all_numbers * all_numbers );
       new_label = QString::number(all_numbers, 'g', 15);
    } else if(button->text() == "!"){

      all_numbers = (ui->label->text()).toDouble();

      if (all_numbers > 0)
      {
int rez= 1;
      for (int i=1; i <= all_numbers; i++ )
          rez = rez * i;
all_numbers = rez;
      new_label = QString::number(all_numbers, 'g', 15);}
else {new_label = oshibka;}

   }ui->label->setText(new_label);

}


void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = ui->label->text().toDouble();
    ui->label->setText("");
    button->setChecked(true);

}


void MainWindow::on_pushButton_rav_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked()){
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_minus->isChecked()){
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_dB->isChecked()){//тут сделать проверку
        if (( num_second > 0 &&  num_first > 0) || (num_second < 0 &&  num_first < 0))
        {labelNumber = 10*log(num_first / num_second);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_dB->setChecked(false);}
        else {ui->label->setText("не определен");}
    } else if(ui->pushButton_Np->isChecked()){//тут сделать проверку
        if (( num_second > 0 &&  num_first > 0) || (num_second < 0 &&  num_first < 0))
       { labelNumber = log(num_first / num_second);
        new_label = QString::number(labelNumber, 'g', 15);
        ui->label->setText(new_label);}
        else  ui->label->setText("не определен");
        ui->pushButton_Np->setChecked(false);
    } else if(ui->pushButton_nkor->isChecked()){
        if ( num_first < 0 || num_second < 1)
             {ui->label->setText("не определен");}
else {double a = 1/ num_second;
labelNumber = pow(num_first,a);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);}
        ui->pushButton_nkor->setChecked(false);

    } else if(ui->pushButton_logn->isChecked()){
        if( num_second < 0 || num_second == 1 || num_first < 0)
        {ui->label->setText("не определен");}else{
        labelNumber = log(num_first) / log(num_second);
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
        ui->pushButton_logn->setChecked(false);}


    } else if(ui->pushButton_del->isChecked()){

        if(num_second == 0){

            ui->label->setText("не определен");}
        else {

                 labelNumber = num_first / num_second;
                 new_label = QString::number(labelNumber, 'g', 15);

                 ui->label->setText(new_label);}
                  ui->pushButton_del->setChecked(false);
    } else if(ui->pushButton_umn->isChecked()){

        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);

        ui->label->setText(new_label);
    }
}

void MainWindow::on_pushButton_ster_clicked()
{
     ui->pushButton_plus->setChecked(false);
     ui->pushButton_minus->setChecked(false);
     ui->pushButton_del->setChecked(false);
     ui->pushButton_umn->setChecked(false);
     ui->pushButton_nkor->setChecked(false);
     ui->pushButton_logn->setChecked(false);


       ui->label->setText("0");
}
