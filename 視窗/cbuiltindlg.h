#ifndef CBUILTINDLG_H
#define CBUILTINDLG_H

#include <QDialog>
#include <QtWidgets>

class CBuiltinDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CBuiltinDlg(QWidget *parent = nullptr);
    ~CBuiltinDlg() override;
private:
    QTextEdit* displayTextEdit;
    QPushButton* colorPushBtn;
    QPushButton* errorPushBtn;
    QPushButton* filePushBtn;
    QPushButton* fontPushBtn;
    QPushButton* inputPushBtn;
    QPushButton* pagePushBtn;
    QPushButton* progressPushBtn;
    QPushButton* printPushBtn;
    QPushButton* setTextColorPushBtn;
private slots:
    void doPushBtn();
};
#endif // CBUILTINDLG_H
