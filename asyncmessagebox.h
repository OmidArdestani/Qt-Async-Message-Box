#ifndef ASYNCMESSAGEBOX_H
#define ASYNCMESSAGEBOX_H

#include "qmutex.h"
#include <QMap>
#include <QMessageBox>
#include <QObject>
#include <QWaitCondition>

class AsyncMessageBox : public QObject
{
    Q_OBJECT
public:
    explicit AsyncMessageBox();

    int WaitForDone();
    void ShowAsyncMessageBox();

    void setText(const QString &text);
    void setInformativeText(const QString &text);
#if QT_CONFIG(textedit)
    void setDetailedText(const QString &text);
#endif
    void setWindowTitle(const QString &title);
    void setWindowModality(Qt::WindowModality windowModality);
    void setStandardButtons(QMessageBox::StandardButtons buttons);

private:
    QWaitCondition LocalWaitCondition;
    QMutex LocalMutex;
    QMap<QString,QVariant> LocalProperties;
    int result = -1;

public slots:
    void ShowAsyncMessageBoxSlot();

signals:
    void __ShowAsyncMessageBox();
};

#endif // ASYNCMESSAGEBOX_H
