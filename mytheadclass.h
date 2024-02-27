#ifndef MYTHEADCLASS_H
#define MYTHEADCLASS_H

#include <AsyncMessageBox.h>
#include <QObject>

class MyTheadClass : public QObject
{
    Q_OBJECT
public:
    explicit MyTheadClass(AsyncMessageBox* async);

private:
    QScopedPointer<QThread> LocalThread;
    AsyncMessageBox* amsg;

private slots:
    void ThreadStarted();
};

#endif // MYTHEADCLASS_H
