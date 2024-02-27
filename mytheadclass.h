#ifndef MYTHEADCLASS_H
#define MYTHEADCLASS_H

#include <AsyncMessageBox.h>
#include <QObject>

class MyTheadClass : public QObject
{
    Q_OBJECT
public:
    explicit MyTheadClass();

private:
    QScopedPointer<QThread> LocalThread;

private slots:
    void ThreadStarted();
};

#endif // MYTHEADCLASS_H
