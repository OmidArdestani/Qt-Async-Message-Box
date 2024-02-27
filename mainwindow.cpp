#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytheadclass.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    new MyTheadClass(new AsyncMessageBox());
}

MainWindow::~MainWindow()
{
    delete ui;
}

