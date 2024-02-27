#include "asyncmessagebox.h"
#include "qapplication.h"
#include "qvariant.h"

#include <QMessageBox>
#include <QMutexLocker>
#include <QThread>
#include <QTimer>
#include <QDebug>

AsyncMessageBox::AsyncMessageBox()
    : QObject{}
{
    this->moveToThread(qApp->thread());

    connect(this, &AsyncMessageBox::__ShowAsyncMessageBox, this, &AsyncMessageBox::ShowAsyncMessageBoxSlot, Qt::UniqueConnection);
}

int AsyncMessageBox::WaitForDone()
{
    QMutexLocker locker(&LocalMutex);
    LocalWaitCondition.wait(&LocalMutex);

    return result;
}

void AsyncMessageBox::ShowAsyncMessageBox()
{
    emit __ShowAsyncMessageBox();
}

void AsyncMessageBox::setText(const QString &text)
{
    LocalProperties.insert("Text", text);
}

void AsyncMessageBox::setInformativeText(const QString &text)
{
    LocalProperties.insert("InformativeText", text);
}

void AsyncMessageBox::setWindowTitle(const QString &title)
{
    LocalProperties.insert("WindowTitle", title);
}

void AsyncMessageBox::setWindowModality(Qt::WindowModality windowModality)
{
    LocalProperties.insert("WindowModality", int(windowModality));
}

void AsyncMessageBox::setStandardButtons(QMessageBox::StandardButtons buttons)
{
    LocalProperties.insert("StandardButtons", int(buttons));
}

void AsyncMessageBox::setDetailedText(const QString &text)
{
    LocalProperties.insert("DetailedText", text);
}

void AsyncMessageBox::ShowAsyncMessageBoxSlot()
{
    QMessageBox msg;

    if(LocalProperties.contains("Text"))
        msg.setText(LocalProperties.value("Text").toString());

    if(LocalProperties.contains("InformativeText"))
        msg.setInformativeText(LocalProperties.value("InformativeText").toString());

    if(LocalProperties.contains("DetailedText"))
        msg.setDetailedText(LocalProperties.value("DetailedText").toString());

    if(LocalProperties.contains("WindowTitle"))
        msg.setWindowTitle(LocalProperties.value("WindowTitle").toString());

    if(LocalProperties.contains("WindowModality"))
        msg.setWindowModality(Qt::WindowModality(LocalProperties.value("WindowModality").toInt()));

    if(LocalProperties.contains("StandardButtons"))
        msg.setStandardButtons(QMessageBox::StandardButtons(LocalProperties.value("StandardButtons").toInt()));

    result = msg.exec();
    LocalWaitCondition.wakeAll();
}
