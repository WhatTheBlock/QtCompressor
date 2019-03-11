#ifndef DIALOG1_H
#define DIALOG1_H

#include<Windows.h>
//QtWidgets
#include<QWidget>
#include<QMessageBox>
#include<QFileDialog>
#include<QSpacerItem>
#include<QGridLayout>
#include <QProgressDialog>
#include <QDialog>
//QtGui
#include<QDragEnterEvent>
//QtCore
#include<QMimeData>
#include<QDebug>
#include<QDateTime>
#include<QTime>
#include<QThread>
#include<QProcess>
#include<QTextCodec>
#include<QByteArray>

namespace Ui {class Dialog1;}

class Dialog1 : public QDialog{
    Q_OBJECT
public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

private:
    Ui::Dialog1 *ui;

    void starttest();

    void delay_1S();

    void delay_1MS();

    void delTestFile(QString);

    quint64 getFreeRAM();

    QProcess *process;

    //統一命令編碼
    QTextCodec *Codec = QTextCodec::codecForName("Big5");
    QByteArray EncodedString;
    //統一命令編碼

    void runCmd(QString);

    //plugins
    QString rar = "C:\\Windows\\Temp\\rar.exe";
    QString winrar = "C:\\Windows\\Temp\\winrar.exe";
    QString sz = "C:\\Windows\\Temp\\7z.exe";
    QString upx = "C:\\Windows\\Temp\\upx.exe";
    QString uharc = "C:\\Windows\\Temp\\uharc.exe";
    QString pxd_old = "C:\\Windows\\Temp\\pxd40.exe";
    QString pxd_new = "C:\\Windows\\Temp\\pxd54.exe";
    QString px = "C:\\Windows\\Temp\\px161.exe";
    QString cmix = "C:\\Windows\\Temp\\cmix.exe";
    QString dic = "C:\\Windows\\Temp\\english.dic";
    QString bcm = "C:\\Windows\\Temp\\bcm.exe";
    //plugins
};

#endif // DIALOG1_H
