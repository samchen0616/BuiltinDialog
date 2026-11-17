
#include "tcpfileserver.h"
#include "ui_tcpfileserver.h"

#include <QHostAddress>
#include <QMessageBox>
#include <QPushButton>
#include <QTcpSocket>

TcpFileServer::TcpFileServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TcpFileServer)
    , tcpServer(new QTcpServer(this))
{
    ui->setupUi(this);

    // 設定視窗標題與初始狀態
    setWindowTitle("TCP Server - 監聽程式");
    ui->statusLabel->setText("伺服器尚未監聽");

    // 功能一：按下「開始監聽」
    connect(ui->listenButton, &QPushButton::clicked,
            this, [this]() {

                // 避免重複啟動監聽
                if (tcpServer->isListening()) {
                    QMessageBox::information(
                        this, "提示", "伺服器已經在監聽中！");
                    return;
                }

                // 開始監聽 TCP Port 16689
                bool success = tcpServer->listen(
                    QHostAddress::AnyIPv4, 16689);

                if (success) {
                    ui->statusLabel->setText(
                        "監聽中... Port: 16689");

                    ui->listenButton->setEnabled(false);
                }
                else {
                    QMessageBox::warning(
                        this,
                        "監聽失敗",
                        tcpServer->errorString()
                        );
                }
            });

    // 有客戶端連線時顯示狀態
    connect(tcpServer, &QTcpServer::newConnection,
            this, [this]() {

                while (tcpServer->hasPendingConnections()) {

                    QTcpSocket *client =
                        tcpServer->nextPendingConnection();

                    ui->statusLabel->setText(
                        "已接收客戶端連線，持續監聽中...");

                    // 這次作業不需要傳送檔案
                    client->disconnectFromHost();
                    client->deleteLater();
                }
            });

    // 功能二：按下「離開」
    connect(ui->exitButton, &QPushButton::clicked,
            this, &QDialog::accept);
}

TcpFileServer::~TcpFileServer()
{
    // 關閉 TCP Server
    if (tcpServer->isListening()) {
        tcpServer->close();
    }

    delete ui;
}
