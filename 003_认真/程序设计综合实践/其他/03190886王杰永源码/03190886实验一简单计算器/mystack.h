#ifndef MYSTACK_H
#define MYSTACK_H

#include <QObject>

class MyStack : public QObject
{
    Q_OBJECT
public:
    explicit MyStack(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYSTACK_H