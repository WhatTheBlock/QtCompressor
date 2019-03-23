#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filedl.h"
#include<Windows.h>
//QtWidgets
#include <QMainWindow>
#include<QWidget>
#include<QMessageBox>
#include<QSpacerItem>
#include<QGridLayout>
#include<QDialog>
#include<QInputDialog>
#include<QFileDialog>
#include<QStyleFactory>
//QtGui
#include<QDragEnterEvent>
//QtCore
#include<QCoreApplication>
#include<QTime>
#include<QMimeData>
#include<QProcess>
#include<QThread>
#include<QFile>
#include<QFileInfo>
#include<QDebug>
#include<QTextCodec>
#include<QByteArray>
#include<QUrl>
#include<QTimer>

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_rar_setpwd_btn_clicked();

    void on_rar_rb_pressed();

    void on_rar_zip_rb_pressed();

    void on_rar5_rb_pressed();

    void on_rar_splitsize_valueChanged(int arg1);

    void on_rar_splitnum_valueChanged(int arg1);

    void on_rar_dictsize_currentIndexChanged(int index);

    void on_rar_1click_clicked();

    void on_rar5_1click_clicked();

    void on_winrar_zip_1click_clicked();

    void on_rar_other_dw_clicked();

    void on_rar_other_ms_clicked();

    void on_rar_other_qo_clicked();

    void on_rar_other_qo_2_clicked();

    void on_rar_other_df_clicked();

    void on_pushButton_9_clicked();

    void on_rar_comm_outpath_btn_clicked();

    void on_unrar_1click_clicked();

    void on_no_TipMsg_stateChanged(int arg1);

    void on_no_WarningMsg_stateChanged(int arg1);

    void on_unrar_oni_stateChanged(int arg1);

    void on_unrar_btn_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_unrar_viewbtn_clicked();

    void on_sz_viewbtn_clicked();

    void on_version_triggered();

    void on_checkUpdate_triggered();

    void on_paq_threads_currentIndexChanged(int index);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_paq_compRunCmd_clicked();

    void on_unpaq_1click_clicked();

    void on_unpaq_btn_clicked();

    void RealTimeReadOut();

    void on_tab_winrar_currentChanged(int index);

    void on_unpaq_viewbtn_clicked();

    void on_tab_paq_currentChanged(int index);

    void on_tab_7z_currentChanged(int index);

    void on_tab_uharc_currentChanged(int index);

    void loadFile();

    void on_paq_tool_currentIndexChanged(int index);

    void updateFreeRAM();

private:
    Ui::MainWindow *ui;

    QString pwd, inpath, outpath;

    int meaningless; //無意義

    QTimer *timer;

    bool TipMsg = true, WarningMsg = true, TempMsg = true, TempMsg2 = true, TempMsg3 = true;

    int rar_dictsize_indexbak;

    bool useRAR, use7Z, useUHA, useUPX, usePAQ;

    bool findString;

    void delay_1ms();
    void delay_1s();

    QFile *delFile;

    quint64 GetFreeRAM();

    QProcess *process;

    void runCmd(QString);
    void runCmdForCompOrDecomp(QString);

    FileDL *m_FileCtrl;

    //統一命令編碼
    QTextCodec *codec = QTextCodec::codecForName("Big5");
    QByteArray encodedString;
    //統一命令編碼

    //plugins
    QString rar = "C:\\Windows\\Temp\\rar.exe";
    QString winrar = "C:\\Windows\\Temp\\winrar.exe";
    QString sz = "C:\\Windows\\Temp\\7z.exe";
    QString upx = "C:\\Windows\\Temp\\upx.exe";
    QString uharc = "C:\\Windows\\Temp\\uharc.exe";
    QString pxd_old = "C:\\Windows\\Temp\\pxd_old.exe";
    QString pxd_new = "C:\\Windows\\Temp\\pxd.exe";
    QString px = "C:\\Windows\\Temp\\px.exe";
    QString cmix = "C:\\Windows\\Temp\\cmix.exe";
    QString dic = "C:\\Windows\\Temp\\english.dic";
    QString bcm = "C:\\Windows\\Temp\\bcm.exe";
    //plugins

    //壓縮檔資訊翻譯
    QString trType = QStringLiteral("類型");
    QString trWARNINGS = QStringLiteral("警告：有效負載盡頭外還有其他資料");
    QString trPhysical_Size = QStringLiteral("物理大小");
    QString trEmbedded_Stub_Size = QStringLiteral("嵌入式殘端大小");
    QString trPacked_Size= QStringLiteral("封裝前大小");
    QString trTotal_Physical_Size = QStringLiteral("總物理大小");
    QString trHeaders_Size = QStringLiteral("標頭大小");
    QString trMethod = QStringLiteral("壓縮方式");
    QString trCluster_Size = QStringLiteral("叢集大小");
    QString trTail_Size = QStringLiteral("文件尾大小");
    QString trCharacteristics = QStringLiteral("特徵");
    QString trSolid = QStringLiteral("結實壓縮");
    QString trStreams = QStringLiteral("資料流");
    QString trBlocks = QStringLiteral("區塊");
    QString trEncrypted = QStringLiteral("加密");
    QString trMultivolume = QStringLiteral("分割檔");
    QString trVolumes = QStringLiteral("分割數");
    QString trComment = QStringLiteral("註解");
    QString trVersion = QStringLiteral("版本");
    QString trVolume = QStringLiteral("卷");
    QString trVolumeIndex = QStringLiteral("卷索引");
    QString trImages = QStringLiteral("映像");
    QString trCodePage = QStringLiteral("頁面編碼");
    QString trDateTime = QStringLiteral("修改日期　　　　　");
    QString trAttr = QStringLiteral("類型");
    QString trSize = QStringLiteral("檔案大小");
    QString trCompressed = QStringLiteral("    壓縮後大小");
    QString trName = QStringLiteral("檔案名稱");
    //壓縮檔資訊翻譯

protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

};

#endif // MAINWINDOW_H
