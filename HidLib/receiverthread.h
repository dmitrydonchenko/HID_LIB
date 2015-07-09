#ifndef RECEIVERTHREAD_H
#define RECEIVERTHREAD_H

#include "hidlib_global.h"
#include "hidreceiver.h"
#include "receiverdata.h"
#include <QThread>
#include <QApplication>

class HIDLIBSHARED_EXPORT ReceiverThread : public QThread
{
    Q_OBJECT
public:
    ReceiverThread(HidReceiver receiver);

    void run();

private:
    HidReceiver receiver;
    bool reconnectToReceiver();

signals:
    void newMessage(ReceiverData receiverData);
    void receiverDisconnected(HidReceiver receiver);
};

#endif // RECEIVERTHREAD_H
