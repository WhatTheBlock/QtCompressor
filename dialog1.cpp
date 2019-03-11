#include "dialog1.h"
#include "ui_dialog1.h"
#include "mainwindow.h"

Dialog1::Dialog1(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    setAcceptDrops(true);  //允許拖放檔案

    QMessageBox msgbox;
    msgbox.setWindowTitle(QStringLiteral("ReadMe！"));
    msgbox.setInformativeText(QStringLiteral("<font size='7' color='black'><b>測試方式：</b></font><br>"
                                             "<font size='6' color='black'>"
                                             "1.生成各格式的壓縮檔並比較大小<br>"
                                             "2.提供3種模式可選</font><br>"
                                             "-----------------------------------------------------------------------------------------------------------------------------------------------------<br>"
                                             "<font size='7' color='black'><b>注意事項：</b></font><br>"
                                             "<font size='6' color='black'>"
                                             "1.測試過程可能會佔用大量的記憶體，請盡量減少背景程式的執行<br>"
                                             "2.測試過程出現主程式無回應為正常現象<br>"
                                             "3.請務必在暫存檔存放位置保留測試檔兩倍大小以上的空間<br>"
                                             "4.測試耗時和壓縮算法、檔案大小、磁碟存取速度、CPU運算速度有關<br>"
                                             "5.測試完畢會列出最佳的壓縮參數設定供您參考</font>"));
    msgbox.setIcon(QMessageBox::Information);
    msgbox.setStandardButtons(QMessageBox::Ok);
    //強制調整MessageBox大小
    QSpacerItem* horizontalSpacer = new QSpacerItem(810, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)msgbox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    msgbox.exec();

    QMessageBox msgbox2;
    msgbox2.setWindowTitle(QStringLiteral("ReadMe！"));
    msgbox2.setInformativeText(QStringLiteral("<font size='7' color='black'><b>模式介紹：</b></font><br>"
                                              "<font size='6' color='black'>"
                                              "1.標準模式：<br>"
                                              "&#160;&#160;&#160;使用WinRAR、7-Zip、UPX測試<br>"
                                              "&#160;&#160;&#160;僅使用常規高參數壓縮，如壓縮等級、字典檔大小<br>"
                                              "2.進階模式：<br>"
                                              "&#160;&#160;&#160;使用WinRAR、7-Zip、UHARC、UPX測試<br>"
                                              "&#160;&#160;&#160;在標準參數的基礎上加入部分細項設定<br>"
                                              "3.極限模式：<br>"
                                              "&#160;&#160;&#160;目前共3種可選的極限壓縮工具供測試<br><br>"
                                              "<font size='6' color='red'>注意！極限模式與進階模式的測試耗時將相差<b>數十倍甚至百倍以上</b>！<br>"
                                              "若無必要請選擇標準模式或進階模式即可。</font><br>"
                                              "</font>"));
    msgbox2.setIcon(QMessageBox::Information);
    msgbox2.setStandardButtons(QMessageBox::Ok);
    //強制調整MessageBox大小
    QSpacerItem* horizontalSpacer2 = new QSpacerItem(785, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout2 = (QGridLayout*)msgbox2.layout();
    layout2->addItem(horizontalSpacer2, layout2->rowCount(), 0, 1, layout2->columnCount());
    msgbox2.exec();
}

Dialog1::~Dialog1(){delete ui;}

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

void Dialog1::runCmd(QString cmd){
    cmd += "\n\r";
    EncodedString = Codec->fromUnicode(cmd);
    process = new QProcess(this);
    process->start("cmd");
    process->write (EncodedString.data());
    process->write ("exit\n\r");
    process->waitForFinished();
    process->close();
}

void Dialog1::delay_1MS() //全局延遲1毫秒
{
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
}
void Dialog1::delay_1S() //全局延遲1秒
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

quint64 Dialog1::getFreeRAM(){ //取得可用記憶體空間
    MEMORYSTATUSEX memory_status;
    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memory_status)) {
       return (memory_status.ullAvailPhys / (1024 * 1024));
    } else return 0;
}

qint64 getfilesize(QString path){ //取得檔案大小
    path.remove("\"");
    qint64 sizex = 0;
    if(path[path.length()-2] != '.' && path[path.length()-3] != '.' && path[path.length()-4] != '.' && path[path.length()-5] != '.') {
        QDir dir(path);
        QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs |  QDir::Hidden | QDir::NoSymLinks | QDir::NoDotAndDotDot);
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if(fileInfo.isDir()) sizex += getfilesize(fileInfo.absoluteFilePath());
            else sizex += fileInfo.size();
        }
    }
    else {
        QFile file(path);
        if (file.open(QIODevice::ReadOnly)){
            sizex = file.size(); file.close();
        }
    }
    return sizex;
}

void Dialog1::delTestFile(QString delpath){ runCmd("del /f /q " + delpath); } //刪除測試檔案

//判斷是否為支援的格式
bool isArchive__UPX(QString path){
    path = path.toLower();
    QString format = path.right(9);
    if(format.right(2) == ".o" || format.right(3) == ".ax" || format.right(3) == ".so" || format.right(3) == ".sh" || format.right(3) == ".ko"
             || format.right(4) == ".exe" || format.right(4) == ".sys" || format.right(4) == ".tos" || format.right(4) == ".obj" || format.right(4) == ".ocx"
             || format.right(4) == ".acm" || format.right(4) == ".com" || format.right(4) == ".dll" || format.right(4) == ".elf" || format.right(4) == ".prx"
             || format.right(4) == ".cpl" || format.right(4) == ".drv" || format.right(4) == ".efi" || format.right(4) == ".mui" || format.right(4) == ".mod"
             || format.right(4) == ".scr" || format.right(4) == ".tsp" || format.right(4) == ".axf" || format.right(4) == ".bin"
             || format.right(5) == ".puff" || format.right(6) == ".dylib" || format.right(6) == ".shell" || format.right(7) == ".bundle") return true;
    else return false;
}
//判斷是否為支援的格式

//拖放設定
void Dialog1::dragEnterEvent(QDragEnterEvent *event) {
    __super::dragEnterEvent(event);
    if(event->mimeData()->hasUrls()) event->acceptProposedAction();
}
void Dialog1::dropEvent(QDropEvent *event) {
    __super::dropEvent(event);
    if (event->mimeData()->hasUrls()){
        QList<QUrl> urls = event->mimeData()->urls();
        if(urls.isEmpty()) return;
        QString path = urls.first().toLocalFile();
        if(path.isEmpty()) return;
        ui->lineEdit->setText(path.replace("/","\\"));
    }
}
//拖放設定

void Dialog1::on_pushButton_4_clicked() //開啟檔案
{
    QString inpath = QFileDialog::getOpenFileName(this, QStringLiteral("選擇檔案"), "/", "All Files (*.*)");
    ui->lineEdit->setText(inpath.replace("/","\\"));
    if(ui->lineEdit->text()=="") ui->lineEdit->setText(QStringLiteral("可直接拖曳測試檔案或資料夾至此"));
}
void Dialog1::on_pushButton_3_clicked() //輸出位置
{
    QString outpath = QFileDialog::getExistingDirectory(this, QStringLiteral("選擇輸出位置"), "/");
    ui->lineEdit_2->setText(outpath.replace("/","\\"));
    if(ui->lineEdit_2->text()=="") ui->lineEdit_2->setText(QStringLiteral("選擇輸出暫存檔位置"));
}

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

void Dialog1::on_pushButton_2_clicked() //開始測試
{
    bool stop=false;
    QString inpath = ui->lineEdit->text();
    QString outpath = ui->lineEdit_2->text();

    if(inpath == QStringLiteral("可直接拖曳測試檔案或資料夾至此") || outpath == QStringLiteral("選擇輸出暫存檔位置")){
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請設定測試的檔案路徑和輸出路徑！"));
        msg->exec();
    }
    else {
        QString cmd, clearpath = outpath;
        quint64 minsize, tempsize;
        QMessageBox *msg;
        int BestSetting, cnt = 2, total;

        ui->log->clear();

        if(ui->mode1->isChecked()){  //標準模式測試
            if(isArchive__UPX(inpath)) total = 10;
            else total = 5;

            QProgressDialog progress(QStringLiteral("準備測試項目1 (共%1項)").arg(total),QStringLiteral("取消"),0,total,this);
            progress.setWindowTitle(QStringLiteral("測試進度"));
            progress.setWindowModality(Qt::WindowModal); //設定成模態對話框
            progress.show();
            delay_1S();

            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 開始執行項目1\n"));

            outpath += "\\temp1.rar5.rar";
            cmd = rar + " a -r -m5 -md1024m \"" + outpath + "\" \"" + inpath + "\"";
            EncodedString = Codec->fromUnicode(cmd);
            system (EncodedString.data());

            minsize = getfilesize(outpath);
            BestSetting = 1;

            delTestFile(outpath); //刪除測試檔案

            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                     QStringLiteral(" → 完成，項目1大小為:") + QString::number(getfilesize(outpath)) + "\n");
            progress.setValue(1);
            progress.setLabelText(QStringLiteral("完成測試項目1 (共%1項)").arg(total));
            delay_1S();delay_1S();

            progress.setLabelText(QStringLiteral("準備測試項目2 (共%1項)").arg(total));
            QCoreApplication::processEvents();
            delay_1S();delay_1S();
            if(progress.wasCanceled()){
                msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),QStringLiteral("取消測試！"));
                msg->exec();
                stop=true;
                ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 使用者已中斷測試\n"));
            }
            while(!stop){
                ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 開始執行項目%1\n").arg(cnt));

                switch (cnt) {
                case 2: outpath = clearpath + "\\temp2.rar";
                    cmd = rar + " a -r -ma4 -m5 -md4m \"" + outpath + "\" \"" + inpath + "\"";
                    break;
                case 3: outpath = clearpath + "\\temp3.7z";

                    break;
                case 4: outpath = clearpath + "\\temp4.7z.zip";

                    break;
                case 5: outpath = clearpath + "\\temp5.xz";

                    break;
                case 6: outpath = clearpath + "\\temp6.upx+rar5.rar";

                    break;
                case 7: outpath = clearpath + "\\temp7.upx.rar";

                    break;
                case 8: outpath = clearpath + "\\temp8.upx.7z";

                    break;
                case 9: outpath = clearpath + "\\temp9.upx+7z.zip";

                    break;
                case 10: outpath = clearpath + "\\temp10.upx+7z.xz";

                    break;
                }
                EncodedString = Codec->fromUnicode(cmd);
                system (EncodedString.data());

                //比較檔案大小
                tempsize = getfilesize(outpath);
                if(tempsize<=minsize) {minsize = tempsize; BestSetting = cnt;}
                //比較檔案大小

                delTestFile(outpath); //刪除測試檔案

                ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                         QStringLiteral(" → 完成，項目%1大小為:").arg(cnt) + QString::number(getfilesize(outpath)) + "\n");
                progress.setValue(cnt);
                progress.setLabelText(QStringLiteral("完成測試項目%1 (共%2項)").arg(cnt).arg(total));
                delay_1S();delay_1S();

                if(cnt<=total){
                    progress.setLabelText(QStringLiteral("準備測試項目%1 (共%2項)").arg(cnt+1).arg(total));
                    QCoreApplication::processEvents();
                    stop = false;
                    delay_1S();delay_1S();
                    if(progress.wasCanceled()){
                        msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),QStringLiteral("取消測試！"));
                        msg->exec();
                        stop = true;
                        ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 使用者已中斷測試\n"));
                    }
                    cnt++;
                }
                else break;
            }
            if(!stop){ //如果沒有取消測試則顯示最佳壓縮參數
                switch (BestSetting) {
                case 1:
                    msg = new QMessageBox(QMessageBox::Information,QStringLiteral("最佳壓縮參數"),
                                                       QStringLiteral("壓縮工具：WinRAR\n壓縮格式：RAR5\n壓縮等級：壓縮最佳 (慢)　　\n"
                                                                      "字典檔大小：1 GB\n")); break;
                case 2:
                    msg = new QMessageBox(QMessageBox::Information,QStringLiteral("最佳壓縮參數"),
                                                       QStringLiteral("壓縮工具：WinRAR\n壓縮格式：RAR\n壓縮等級：壓縮最佳 (慢)　　\n"
                                                                      "字典檔大小：4096 KB\n")); break;

                }
                msg->exec();
            }
        }

        //ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ

        if(ui->mode2->isChecked()){  //進階模式測試
            if(isArchive__UPX(inpath)) total = 14;
            else total = 7;

            QProgressDialog progress(QStringLiteral("準備測試項目1 (共%1項)").arg(total),QStringLiteral("取消"),0,total,this);
            progress.setWindowTitle(QStringLiteral("測試進度"));
            progress.setWindowModality(Qt::WindowModal); //設定成模態對話框
            progress.show();
            delay_1S();

            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 開始執行項目1\n"));

            outpath += "\\temp1.rar5.rar";
            cmd = rar + " a -r -m5 -md1024m -s -qo- -mt1 \"" + outpath + "\" \"" + inpath + "\"";
            EncodedString = Codec->fromUnicode(cmd);
            system (EncodedString.data());

            minsize = getfilesize(outpath);
            BestSetting = 1;

            delTestFile(outpath); //刪除測試檔案

            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                     QStringLiteral(" → 完成，項目1大小為:") + QString::number(getfilesize(outpath)) + "\n");
            progress.setValue(1);
            progress.setLabelText(QStringLiteral("完成測試項目1 (共%1項)").arg(total));
            delay_1S();delay_1S();

            progress.setLabelText(QStringLiteral("準備測試項目2 (共%1項)").arg(total));
            QCoreApplication::processEvents();
            delay_1S();delay_1S();
            if(progress.wasCanceled()){
                msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),QStringLiteral("取消測試！"));
                msg->exec();
                stop=true;
                ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 使用者已中斷測試\n"));
            }
            while(!stop){
                ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 開始執行項目%1\n").arg(cnt));

                switch (cnt) {
                case 2: outpath = clearpath + "\\temp2.rar";
                    cmd = rar + " a -r -ma4 -m5 -md4m -s -mt1 \"" + outpath + "\" \"" + inpath + "\"";
                    break;
                case 3: outpath = clearpath + "\\temp3.7z";

                    break;
                case 4: outpath = clearpath + "\\temp4.7z.zip";

                    break;
                case 5: outpath = clearpath + "\\temp5.xz";

                    break;
                case 6: outpath = clearpath + "\\temp6.alz3.uha";

                    break;
                case 7: outpath = clearpath + "\\temp7.ppm.uha";

                    break;
                case 8: outpath = clearpath + "\\temp8.upx+rar5.rar";

                    break;
                case 9: outpath = clearpath + "\\temp9.upx.rar";

                    break;
                case 10: outpath = clearpath + "\\temp10.upx.7z";

                    break;
                case 11: outpath = clearpath + "\\temp11.upx+7z.zip";

                    break;
                case 12: outpath = clearpath + "\\temp12.upx+7z.xz";

                    break;
                case 13: outpath = clearpath + "\\temp13.upx+alz3.uha";

                    break;
                case 14: outpath = clearpath + "\\temp14.upx+ppm.uha";

                    break;
                }
                EncodedString = Codec->fromUnicode(cmd);
                system (EncodedString.data());

                //比較檔案大小
                tempsize = getfilesize(outpath);
                if(tempsize<=minsize) {minsize = tempsize; BestSetting = cnt;}
                //比較檔案大小

                delTestFile(outpath); //刪除測試檔案

                ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                         QStringLiteral(" → 完成，項目%1大小為:").arg(cnt) + QString::number(getfilesize(outpath)) + "\n");
                progress.setValue(cnt);
                progress.setLabelText(QStringLiteral("完成測試項目%1 (共%2項)").arg(cnt).arg(total));
                delay_1S();delay_1S();

                if(cnt<=total){
                    progress.setLabelText(QStringLiteral("準備測試項目%1 (共%2項)").arg(cnt+1).arg(total));
                    QCoreApplication::processEvents();
                    stop = false;
                    delay_1S();delay_1S();
                    if(progress.wasCanceled()){
                        msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),QStringLiteral("取消測試！"));
                        msg->exec();
                        stop = true;
                        ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 使用者已中斷測試\n"));
                    }
                    cnt++;
                }
                else break;
            }
            if(!stop){ //如果沒有取消測試則顯示最佳壓縮參數
                switch (BestSetting) {
                case 1:
                    msg = new QMessageBox(QMessageBox::Information,QStringLiteral("最佳壓縮參數"),
                                                       QStringLiteral("壓縮工具：WinRAR\n壓縮格式：RAR5\n壓縮等級：壓縮最佳 (慢)　　\n"
                                                                      "字典檔大小：1 GB\n其他設定：勾選4、11\n執行緒：1")); break;
                case 2:
                    msg = new QMessageBox(QMessageBox::Information,QStringLiteral("最佳壓縮參數"),
                                                       QStringLiteral("壓縮工具：WinRAR\n壓縮格式：RAR\n壓縮等級：壓縮最佳 (慢)　　\n"
                                                                      "字典檔大小：4096 KB\n其他設定：勾選4\n執行緒：1")); break;

                }
                msg->exec();
            }
        }

        //ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ

        if(ui->mode3->isChecked()){  //極限模式測試
            int lv;
            quint64 RAM = getFreeRAM();

            if(RAM > 32000) lv = 15;
            else if(RAM > 23000) lv = 14;
            else if(RAM > 15000) lv = 13;
            else if(RAM > 12000) lv = 12;
            else if(RAM > 10000) lv = 11;
            else if(RAM > 8000) lv = 10;
            else if(RAM > 5100) lv = 9;
            else if(RAM > 3000) lv = 8;
            else if(RAM > 2000) lv = 7;
            else if(RAM > 1460) lv = 6;
            else if(RAM > 1200) lv = 5;
            else if(RAM > 1100) lv = 4;
            else if(RAM > 500) lv = 3;

            total = lv-2;

            ui->log->insertPlainText(QStringLiteral("可用系統記憶體：%1 MB\n測試項目共%2項\n------------------------------\n").arg(RAM).arg(total));

            QProgressDialog progress(QStringLiteral("準備測試項目1 (共%1項)").arg(total), QStringLiteral("取消"), 0, total, this);
            progress.setWindowTitle(QStringLiteral("測試進度"));
            progress.setWindowModality(Qt::WindowModal); //設定成模態對話框
            progress.show();
            delay_1S();

            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 開始執行項目1\n"));
            outpath += "\\temp" + QString::number(lv);
            cmd = pxd_new + " -s" + QString::number(lv) + " \"" + outpath + "\" \"" + inpath + "\"";
            EncodedString = Codec->fromUnicode(cmd);
            system (EncodedString.data());

            minsize = getfilesize(outpath + ".pqc2");
            BestSetting = lv;

            if(ui->delTestFile->isChecked()){ delTestFile(outpath + ".pqc2"); }//刪除當前的測試檔案

            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                     QStringLiteral(" → 完成，項目1大小為:") + QString::number(minsize) + "\n");
            progress.setValue(1);
            progress.setLabelText(QStringLiteral("完成測試項目1 (共%1項)").arg(total));
            delay_1S();delay_1S();

            if(total>1){
                progress.setLabelText(QStringLiteral("準備測試項目2 (共%1項)").arg(total));
                QCoreApplication::processEvents();
                delay_1S();delay_1S();
                if(progress.wasCanceled()){
                    msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),QStringLiteral("取消測試！"));
                    msg->exec();
                    stop=true;
                    ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 使用者已中斷測試\n"));
                }

                while(!stop){ //若超過1項測試則進入此迴圈，直到完成所有測試項目
                    ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 開始執行項目%1\n").arg(cnt));

                    //更新暫存檔名
                    if(outpath[outpath.length()-2] == 'p') outpath.chop(1);
                    else outpath.chop(2);
                    outpath += QString::number(lv);
                    //更新暫存檔名

                    cmd = pxd_new + " -s" + QString::number(lv) + " \"" + outpath + "\" \"" + inpath + "\"";
                    EncodedString = Codec->fromUnicode(cmd);
                    system (EncodedString.data());

                    //比較檔案大小
                    tempsize = getfilesize(outpath + ".pqc2");
                    if(tempsize<=minsize) {
                        minsize = tempsize;
                        if(ui->keepTestFile->isChecked()){
                            runCmd("del /f /q " + clearpath + "\\temp" + QString::number(BestSetting) + ".pqc2"); //刪除上一個最小的測試檔案
                        }
                        BestSetting = lv;
                    }
                    //比較檔案大小

                    if(ui->delTestFile->isChecked() || (!ui->keepAllTestFile->isChecked() && (!ui->keepTestFile->isChecked() || minsize != tempsize))){
                        delTestFile(outpath + ".pqc2"); //刪除當前的測試檔案
                    }

                    ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") +
                                             QStringLiteral(" → 完成，項目%1大小為:").arg(cnt) + QString::number(tempsize) + "\n");
                    progress.setValue(cnt);
                    progress.setLabelText(QStringLiteral("完成測試項目%1 (共%2項)").arg(cnt).arg(total));
                    delay_1S();delay_1S();

                    if(cnt<total){
                        progress.setLabelText(QStringLiteral("準備測試項目%1 (共%2項)").arg(cnt+1).arg(total));
                        QCoreApplication::processEvents();
                        stop = false;
                        delay_1S();delay_1S();
                        if(progress.wasCanceled()){
                            msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),QStringLiteral("取消測試！"));
                            msg->exec();
                            stop = true;
                            ui->log->insertPlainText(QDateTime::currentDateTime().toString("hh:mm:ss") + QStringLiteral(" → 使用者已中斷測試\n"));
                        }
                        lv--;
                        cnt++;
                    }
                    else break;
                }
            }
            if(!stop){ //如果沒有取消測試則顯示最佳壓縮參數
                msg = new QMessageBox(QMessageBox::Information,QStringLiteral("最佳壓縮參數"),
                                                   QStringLiteral("<font size='6' color='black'>壓縮速度：非常慢<br>壓縮等級：%1<br>執行緒：1</font>").arg(BestSetting));
                //強制調整MessageBox大小
                QSpacerItem* horizontalSpacer = new QSpacerItem(210, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
                QGridLayout* layout = (QGridLayout*)msg->layout();
                layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
                msg->exec();
            }
        }
    }
}
