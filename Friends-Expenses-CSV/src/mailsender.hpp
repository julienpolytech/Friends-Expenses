/*
 * mailsender.hpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Salim
 */

#ifndef MAILSENDER_HPP
#define MAILSENDER_HPP

#include <QTcpSocket>

class MailSender
{

public:
    MailSender();
/*
signals:
    void status( const QString &);

public slots:
    void stateChanged(QTcpSocket::SocketState socketState);
    void errorReceived(QTcpSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();

private:
    void stateChanged(QTcpSocket::SocketState socketState);
    void errorReceived(QTcpSocket::SocketError socketError);
    void disconnected();
    void connected();
    void readyRead();
*/
};

#endif // MAILSENDER_HPP
