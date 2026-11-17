
#ifndef TCPFILESERVER_H
#define TCPFILESERVER_H

#include <QDialog>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui {
class TcpFileServer;
}
QT_END_NAMESPACE

class TcpFileServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileServer(QWidget *parent = nullptr);
    ~TcpFileServer();

private:
    Ui::TcpFileServer *ui;
    QTcpServer *tcpServer;
};

#endif // TCPFILESERVER_H
