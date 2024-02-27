#include "mytheadclass.h"

#include <AsyncMessageBox.h>
#include <QThread>
#include <QDebug>
#include <QApplication>

MyTheadClass::MyTheadClass()
    : QObject{}
{
    LocalThread.reset(new QThread());

    this->moveToThread(LocalThread.data());
    LocalThread->start();

    connect(LocalThread.data(),SIGNAL(started()),this,SLOT(ThreadStarted()));

}

void MyTheadClass::ThreadStarted()
{
    AsyncMessageBox amsg;
    amsg.setText("Erorr");
    amsg.setDetailedText("This is my error message from thread.");
    amsg.ShowAsyncMessageBox();
    auto r = amsg.WaitForDone();
    qDebug()<<Q_FUNC_INFO<<r;
}
