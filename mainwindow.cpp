#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filedl.h"

#define VERSION "0.4.4.0"
#define WINRAR "v5.71.0"
#define SZIP "v19.0.0"
#define UPX "v3.9.5"
#define PXD "v64"
#define PX "v179fix5"
#define CMIX "v17"
#define BCM "v1.30"
#define KANZI "v1.6 build 20190714g"

static QUrl checkVerUrl("http://www.omgg.ga/ver.txt");
//static QUrl checkVerUrl("https://cloud.allsync.com/s/A2f8QCD4NB5i5NZ/download");
static QString latestVer;

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent), ui(new Ui::MainWindow)
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    ui->setupUi(this);
    setAcceptDrops(true);  //允許拖放檔案
    on_rar5_rb_pressed(); //初始化RAR5字典檔大小
    ui->sysFreeRAM->setText(QString::number(GetFreeRAM())); //視窗顯示前先更新一次空閒記憶體
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateFreeRAM()));
    timer->start(1000); //1秒執行一次

    QFile::copy(":/plugins/rar.exe", "C:/Windows/Temp/rar.exe");
    QFile::copy(":/plugins/RarFiles.lst", "C:/Windows/Temp/RarFiles.lst");
    QFile::copy(":/plugins/rarreg.key", "C:/Windows/Temp/rarreg.key");
    QFile::copy(":/plugins/7z.exe", "C:/Windows/Temp/7z.exe");
    QFile::copy(":/plugins/upx.exe", "C:/Windows/Temp/upx.exe");
    QFile::copy(":/plugins/pxd.exe", "C:/Windows/Temp/pxd.exe");
    QFile::copy(":/plugins/px.exe", "C:/Windows/Temp/px.exe");
    QFile::copy(":/plugins/cmix.exe", "C:/Windows/Temp/cmix.exe");
    QFile::copy(":/plugins/english.dic", "C:/Windows/Temp/english.dic");
    QFile::copy(":/plugins/english.exp", "C:/Windows/Temp/english.exp");
    QFile::copy(":/plugins/english.emb", "C:/Windows/Temp/english.emb");
    QFile::copy(":/plugins/bcm.exe", "C:/Windows/Temp/bcm.exe");
    QFile::copy(":/plugins/kkazni.exe", "C:/Windows/Temp/kkazni.exe");
}
MainWindow::~MainWindow(){delete ui;}

//檔案下載 (檢查更新)
FileDL::FileDL(QUrl fileUrl, QObject *parent) : QObject(parent) {
    connect(&m_WebCtrl, SIGNAL (finished(QNetworkReply*)), this, SLOT (fileDownloaded(QNetworkReply*)));
    QNetworkRequest request(fileUrl);
    m_WebCtrl.get(request);
}
FileDL::~FileDL(){}
void FileDL::fileDownloaded(QNetworkReply* pReply) {
    m_DownloadedData = pReply->readAll();
    pReply->deleteLater();
    emit downloaded();
}
QByteArray FileDL::downloadedData() const { return m_DownloadedData; }
//檔案下載 (檢查更新)

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

//------------------------------通用設定-------------------------------//
void MainWindow::delay_1ms() //不凍結UI延遲1毫秒
{
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while( QTime::currentTime() < dieTime ) QCoreApplication::processEvents(QEventLoop::AllEvents, 1000);
}
void MainWindow::delay_1s() //不凍結UI延遲1秒
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while( QTime::currentTime() < dieTime ) QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

quint64 MainWindow::GetFreeRAM(){ //取得可用記憶體空間
    MEMORYSTATUSEX memory_status;
    ZeroMemory(&memory_status, sizeof(MEMORYSTATUSEX));
    memory_status.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memory_status)) {
       return (memory_status.ullAvailPhys / (1024 * 1024));
    } else return 0;
}

void MainWindow::updateFreeRAM() { ui->sysFreeRAM->setText(QString::number(GetFreeRAM())); }

void MainWindow::runCmd(QString cmd){ //靜默執行
    cmd += "\n\r";
    encodedString = codec->fromUnicode(cmd);
    process = new QProcess(this);
    process->start("cmd");
    process->write (encodedString.data());
    process->write ("exit\n\r");
    process->waitForFinished();
    process->close();
}

void MainWindow::runCmdForCompOrDecomp(QString cmd){ //可輸出執行過程
    findString = false;
    cmd += "\n\r";
    encodedString = codec->fromUnicode(cmd);
    useRAR = use7Z = useUPX = usePAQ = false;
    switch (encodedString.data()[17]) {
    case 'a':useRAR=true; break;
    case 'z': use7Z=true; break;
    case 'p': useUPX=true; break;
    case 'c': //bcm
    case 'k': //kkanzi = kanzi
    case 'm': //cmix
    case 'x': usePAQ=true; break;
    }
    process = new QProcess(this);
    process->start("cmd");
    process->write (encodedString.data());
    connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(RealTimeReadOut()));
    connect(process, SIGNAL(readyReadStandardError()), this, SLOT(RealTimeReadOut()));
    process->write ("exit\n\r");    
}

void MainWindow::RealTimeReadOut(){ //輸出執行過程
    QProcess *p = dynamic_cast<QProcess *>( sender() );
    if (p) {
        if(useRAR) {
            ui->rar_cmdOutput->append(QString::fromLocal8Bit(p->readAllStandardOutput()));
            ui->rar_cmdOutput->append(QString::fromLocal8Bit(p->readAllStandardError()));
        }
        else if(use7Z) {
            ui->sz_cmdOutput->append(QString::fromLocal8Bit(p->readAllStandardOutput()));
            ui->sz_cmdOutput->append(QString::fromLocal8Bit(p->readAllStandardError()));
        }
        else if(usePAQ) {
            if(ui->tabWidget->currentIndex() == 3 && ui->tab_paq->currentIndex() == 1){
                ui->paq_viewFileList->append(QString::fromLocal8Bit(p->readAllStandardOutput()));
                ui->paq_viewFileList->append(QString::fromLocal8Bit(p->readAllStandardError()));
            }
            else {
                ui->paq_cmdOutput->append(QString::fromLocal8Bit(p->readAllStandardOutput()));
                ui->paq_cmdOutput->append(QString::fromLocal8Bit(p->readAllStandardError()));
            }
        }
    }
}

QString deleteFileName(QString path){ //刪除檔名，取得當前目錄路徑
    int cnt=0;
    for(int i = path.length()-1; i > 1; i--){
        ++cnt;
        if(path[i] == "\\") {path.chop(cnt); break;}
    }
    return path;
}
QString getFileExt(QString path){ //取得副檔名
    int cnt=0;
    for(int i = path.length()-1; i > 2; i--){
        ++cnt;
        if(path[i] == ".") {return path.right(path.length()-i);}
    }
    return "";
}
QString getFileName(QString path){ //取得檔名+副檔名
    int cnt=0;
    for(int i = path.length()-1; i > 2; i--){
        ++cnt;
        if(path[i] == "\\") {return path.right(path.length()-i-1);}
    }
    return "";
}

qint64 Getfilesize(QString path){ //取得檔案大小
    qint64 sizex = 0;
    if(path[path.length()-2] != '.' && path[path.length()-3] != '.' && path[path.length()-4] != '.' && path[path.length()-5] != '.') {
        QDir dir(path);
        QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs |  QDir::Hidden | QDir::NoSymLinks | QDir::NoDotAndDotDot);
        for (int i = 0; i < list.size(); ++i) {
            QFileInfo fileInfo = list.at(i);
            if(fileInfo.isDir()) sizex += Getfilesize(fileInfo.absoluteFilePath());
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

//判斷是否為支援的格式
bool isArchive_7Zip(QString path){
    path = path.toLower();
    QString format = path.right(9);
    if(format.right(2) == ".z" || format.right(3) == ".7z" || format.right(3) == ".xz" || format.right(3) == ".gz"
             || format.right(4) == ".zip" || format.right(4) == ".rar" || format.right(4) == ".001" || format.right(4) == ".cab" || format.right(4) == ".msi"
             || format.right(4) == ".apk" || format.right(4) == ".dot" || format.right(4) == ".ppt" || format.right(4) == ".pps" || format.right(4) == ".sfx"
             || format.right(4) == ".iso" || format.right(4) == ".txz" || format.right(4) == ".xls" || format.right(4) == ".pot" || format.right(4) == ".qdz"
             || format.right(4) == ".tar" || format.right(4) == ".bz2" || format.right(4) == ".doc" || format.right(4) == ".xlt"
             || format.right(4) == ".tbz" || format.right(4) == ".tgz" || format.right(4) == ".tpz" || format.right(4) == ".taz"
             || format.right(4) == ".lzh" || format.right(4) == ".lha" || format.right(4) == ".rpm" || format.right(4) == ".deb"
             || format.right(4) == ".arj" || format.right(4) == ".vhd" || format.right(4) == ".wim" || format.right(4) == ".swm"
             || format.right(4) == ".fat" || format.right(4) == ".dmg" || format.right(4) == ".hfs" || format.right(4) == ".xar"
             || format.right(4) == ".exe" || format.right(5) == ".lzma" || format.right(5) == ".cpio" || format.right(5) == ".tbz2" || format.right(5) == ".vsix"
             || format.right(5) == ".docx" || format.right(5) == ".dotx" || format.right(5) == ".xlsx" || format.right(5) == ".gzip"
             || format.right(5) == ".pptx" || format.right(5) == ".ppsx" || format.right(5) == ".xltx"
             || format.right(5) == ".ntfs" || format == ".squashfs") return true;
    else return false;
}
bool isArchive_WinRAR(QString path){
    path = path.toLower();
    QString format = path.right(5);
    if(format.right(2) == ".z" || format.right(3) == ".7z" || format.right(3) == ".xz" || format.right(3) == ".gz"
             || format.right(3) == ".lz" || format.right(4) == ".zip" || format.right(4) == ".rar" || format.right(4) == ".cab"
             || format.right(4) == ".dot" || format.right(4) == ".ppt" || format.right(4) == ".pps" || format.right(4) == ".xls"
             || format.right(4) == ".pot" || format.right(4) == ".doc" || format.right(4) == ".xlt" || format.right(5) == ".pptx"
             || format.right(4) == ".iso" || format.right(4) == ".tar" || format.right(4) == ".bz2" || format.right(4) == ".apk"
             || format.right(4) == ".lzh" || format.right(4) == ".uue" || format.right(4) == ".jar"
             || format.right(4) == ".arj" || format.right(4) == ".001" || format.right(5) == ".zipx" || format.right(5) == ".ppsx"
             || format.right(5) == ".xltx" || format.right(5) == ".docx" || format.right(5) == ".dotx" || format.right(5) == ".xlsx"
             || format.right(5) == ".vsix" || format.right(4) == ".qdz") return true;
    else return false;
}
bool isArchive_UPX(QString path){
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
bool isArchive_pxd2(QString path){
    path = path.toLower();
    if(path.right(2) == ".1") return true;
    else return false;
}
bool isArchive_PX(QString path){
    path = path.toLower();
    if(path.right(2) == ".2") return true;
    else return false;
}
bool isArchive_cmix(QString path){
    path = path.toLower();
    if(path.right(5) == ".cmix") return true;
    else return false;
}
bool isArchive_dic_cmix(QString path){
    path = path.toLower();
    if(path.right(9) == ".dic.cmix") return true;
    else return false;
}
bool isArchive_BCM(QString path){
    path = path.toLower();
    if(path.right(4) == ".bcm") return true;
    else return false;
}
bool isArchive_Kanzi(QString path){
    path = path.toLower();
    if(path.right(4) == ".knz") return true;
    else return false;
}
bool isSplit(QString path){
    path = path.toLower();
    if(path.right(4) == ".001" || path.right(10) == ".part1.rar") return true;
    else return false;
}
//判斷是否為支援的格式

//拖放設定
void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
    if(event->mimeData()->hasUrls()) event->acceptProposedAction();
}
void MainWindow::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasUrls()){
        QList<QUrl> urls = event->mimeData()->urls();
        if(urls.isEmpty()) return;
        inpath = urls.first().toLocalFile();
        if(inpath.isEmpty()) return;
        ui->lineEdit->setText(inpath.replace("/","\\"));
    }
}
//拖放設定

void MainWindow::on_pushButton_clicked() //開啟檔案
{
    if(ui->tabWidget->currentIndex() == 2){ //限制UPX開啟格式
        inpath = QFileDialog::getOpenFileName(this, QStringLiteral("選擇檔案"), "/", "Executable File (*.exe);;Dynamic-link library (*.dll)"
                                                                                 ";;Executable File (*.com);;Device Drivers (*.sys)");
    }
    else if(ui->tabWidget->currentIndex() == 3 && ui->tab_paq->currentIndex() == 1){ //限制其他工具解壓開啟格式
        inpath = QFileDialog::getOpenFileName(this, QStringLiteral("選擇檔案"), "/", "pxd (*.1);;px (*.2);;cmix (*.cmix);;bcm (*.bcm);;kanzi (*.knz)");
    }
    else inpath = QFileDialog::getOpenFileName(this, QStringLiteral("選擇檔案"), "/", "All Files (*.*)");
    ui->lineEdit->setText(inpath.replace("/","\\"));
    if(ui->lineEdit->text()=="") ui->lineEdit->setText(QStringLiteral("可直接拖曳檔案或資料夾至此"));
}
void MainWindow::on_pushButton_4_clicked() //輸出檔案
{
    switch (ui->tabWidget->currentIndex()) {
    case 0: //WinRAR
        switch (ui->tab_winrar->currentIndex()) {
        case 0: outpath = QFileDialog::getSaveFileName(this, QStringLiteral("建立壓縮檔"), "/", QStringLiteral("RAR/RAR5 (*.rar)")); break;
        case 1: outpath = QFileDialog::getExistingDirectory(this, QStringLiteral("選擇輸出位置"), "/"); break;
        } break;
    case 1: //7-Zip
        switch (ui->tab_7z->currentIndex()) {
        case 0: outpath = QFileDialog::getSaveFileName(this, QStringLiteral("建立壓縮檔"), "/",
                                                           QStringLiteral("7-Zip (*.7z);;Bzip2 (*.bz2);;Gzip (*.gz)"
                                                                          ";;GNU tar (*.tar);;Windows 映像格式 (*.wim);;XZ (*.xz);;Zip (*.zip)")); break;
        case 1: outpath = QFileDialog::getExistingDirectory(this, QStringLiteral("選擇輸出位置"), "/"); break;
        } break;
    case 2: //UPX
        switch (ui->tab_upx->currentIndex()) {
        case 0: outpath = QFileDialog::getSaveFileName(this, QStringLiteral("執行檔加殼壓縮"), "/",
                                                           QStringLiteral("Executable File (*.exe);;Dynamic-link library (*.dll)"
                                                                          ";;Executable File (*.com);;Device Drivers (*.sys)")); break;
        case 1: outpath = QFileDialog::getExistingDirectory(this, QStringLiteral("選擇輸出位置"), "/"); break;
        } break;
    case 3: //其他
        switch (ui->tab_paq->currentIndex()) {
        case 0: outpath = QFileDialog::getSaveFileName(this, QStringLiteral("建立壓縮檔"), "/", QStringLiteral("pxd (*.1);;px (*.2);;cmix (*.cmix);;bcm (*.bcm);;kanzi (*.knz)")); break;
        case 1: outpath = QFileDialog::getExistingDirectory(this, QStringLiteral("選擇輸出位置"), "/"); break;
        } break;
    }
    ui->lineEdit_2->setText(outpath.replace("/","\\"));
}

//menuBar
void MainWindow::on_version_triggered() //查看版本資訊
{
    QMessageBox *msg = new QMessageBox(QMessageBox::Information,QStringLiteral("About QtCompressor"),
                                       QStringLiteral("<font size='6' color='black'><b>QtCompressor Version：</b>%1<br>"
                                                      "----------------------------------------------------<br>"
                                                      "<b>Plugins：</b> 1. WinRAR %2<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "2. 7-Zip %3<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "3. UPX %4<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "4. Paq8pxd %5<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "5. Paq8px %6<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "6. cmix %7<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "7. BCM %8<br>"
                                                      "&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;&#160;"
                                                      "8. Kanzi %9"
                                                      "</font>").arg(VERSION).arg(WINRAR).arg(SZIP).arg(UPX).arg(PXD).arg(PX).arg(CMIX).arg(BCM).arg(KANZI));
    //強制調整MessageBox大小
    QSpacerItem* horizontalSpacer = new QSpacerItem(600, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)msg->layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    msg->exec();
}
void MainWindow::on_checkUpdate_triggered() //檢查更新
{
    m_FileCtrl = new FileDL(checkVerUrl, this);
    connect(m_FileCtrl, SIGNAL (downloaded()), this, SLOT (loadFile()));
    while(latestVer.length() != 7) delay_1ms(); //等待下載完成，且讀取完畢
    QMessageBox *msg = new QMessageBox(QMessageBox::Information,QStringLiteral("訊息"),
                                       QStringLiteral("<font size='6' color='red'><b>最新版本：%1</b></font><br>"
                                                      "<font size='6' color='black'><b>當前版本：%2</b></font>").arg(latestVer).arg(VERSION));
    msg->exec();
}
//menuBar

void MainWindow::loadFile() //下載檔案，並讀取版本號
{
    latestVer.clear();

    QFile wfile("C:\\Windows\\Temp\\checkver.txt");
    wfile.open(QIODevice::WriteOnly);
    QTextStream out(&wfile);
    out << QTextCodec::codecForMib(106)->toUnicode(m_FileCtrl->downloadedData()); //轉編碼為UTF-8
    wfile.flush();
    wfile.close();

    QFile rfile("C:\\Windows\\Temp\\checkver.txt");
    if(!rfile.open(QFile::ReadOnly|QFile::Text)) return;
    QTextStream in(&rfile);
    latestVer = in.readAll();
    rfile.close();
}

void MainWindow::on_no_TipMsg_stateChanged(int state) //提醒開關
{
    if(state==0) TipMsg = true;
    else TipMsg = false;
}
void MainWindow::on_no_WarningMsg_stateChanged(int state) //警告開關
{
    if(state==0) WarningMsg = true;
    else WarningMsg = false;
}

void MainWindow::on_tabWidget_currentChanged(int index) //切換壓縮工具時
{
    meaningless = index; //無意義，防止編譯提醒
    ui->lineEdit->setText(QStringLiteral("可直接拖曳檔案或資料夾至此"));
    ui->lineEdit_2->setText(QStringLiteral("選擇輸出位置"));
}
void MainWindow::on_tab_winrar_currentChanged(int index) //切換WinRAR內的tab時
{
    if(index == 0 || index == 1 || index == 2){
        ui->lineEdit->setText(QStringLiteral("可直接拖曳檔案或資料夾至此"));
        ui->lineEdit_2->setText(QStringLiteral("選擇輸出位置"));
    }
}
void MainWindow::on_tab_7z_currentChanged(int index) //切換7-Zip內的tab時
{
    if(index == 0 || index == 1){
        ui->lineEdit->setText(QStringLiteral("可直接拖曳檔案或資料夾至此"));
        ui->lineEdit_2->setText(QStringLiteral("選擇輸出位置"));
    }
}
void MainWindow::on_tab_paq_currentChanged(int index) //切換測試區內的tab時
{
    if(index == 0 || index == 1){
        ui->lineEdit->setText(QStringLiteral("可直接拖曳檔案或資料夾至此"));
        ui->lineEdit_2->setText(QStringLiteral("選擇輸出位置"));
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &path) //當開啟檔案路徑改變時
{
    inpath = path;
    bool ok = true;
    QString line;
    if(path != QStringLiteral("可直接拖曳檔案或資料夾至此") && path != ""){
        if(ui->tabWidget->currentIndex() == 0 && ui->tab_winrar->currentIndex() == 1){ //限制WinRAR解壓開啟格式
            ok = isArchive_WinRAR(path);
            if(!ok){
                QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"), QStringLiteral("非WinRAR支援的解壓縮格式"));
                msg->exec();
            }
            else {
                if(isArchive_7Zip(path)){
                    int delUseless = 0;
                    //輸出檔案清單txt
                    QString cmd = sz + " l \"" + path + "\" -bso1 >" + " C:\\Windows\\Temp\\list.txt";
                    runCmd(cmd);
                    //輸出檔案清單txt

                    ui->rar_viewFileList->clear();

                    //讀取txt並寫入textEdit
                    bool write = false;
                    QFile file("C:\\Windows\\Temp\\list.txt");
                    if(!file.open(QFile::ReadOnly|QFile::Text)) return;
                    QTextStream in(&file);
                    if(isSplit(path)){
                        while (!in.atEnd()){
                            line = in.readLine();
                            if(line == "Type = Split") { write = true; line.replace("Type",trType); }
                            else if(line.left(4) == "Type") {
                                write = true;
                                ui->rar_viewFileList->setText(ui->rar_viewFileList->toPlainText()+
                                                              QStringLiteral("--------------------------合併分割檔後--------------------------")+"\n");
                                line.replace("Type",trType);
                            }
                            else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                            else if(line.left(9) == "There are") write = false;
                            else if(line.left(13) == "Physical Size") { write = true; line.replace("Physical Size",trPhysical_Size); }
                            else if(line.left(4) == "Size") line.replace("Size",trPacked_Size);
                            else if(line.left(11) == "Packed Size") write = false;
                            else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                            else if(line.left(9) == "Code Page") line.replace("Code Page",trCodePage);
                            else if(line.left(6) == "Method") line.replace("Method",trMethod);
                            else if(line.left(12) == "Cluster Size") line.replace("Cluster Size",trCluster_Size);
                            else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                            else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                            else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                            else if(line.left(7) == "Streams") line.replace("Streams",trStreams);
                            else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                            else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                            else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                            else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                            else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                            else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                            else if(line.left(7) == "Comment") { write = true; line.replace("Comment",trComment); }
                            else if(line.left(7) == "Version") line.replace("Version",trVersion);
                            else if(line.left(6) == "Volume") line.replace("Volume",trVolume);
                            else if(line.left(6) == "Images") line.replace("Images",trImages);
                            else if(line.left(7) == "   Date") {
                                line.replace("   Date      Time",trDateTime);
                                line.replace("Attr",trAttr);
                                line.replace("     Size",trSize);
                                line.replace("Compressed",trCompressed);
                                line.replace("Name",trName);
                            }
                            else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                            else if(line == "") { delUseless++; if(delUseless == 6) break; }
                            if(write) ui->rar_viewFileList->setText(ui->rar_viewFileList->toPlainText()+line+"\n");
                            if(line.left(5) == QStringLiteral("總物理大小")) {
                                if(inpath.right(10) == ".part1.rar") write = true;
                                else write = false;
                            }
                            else if(line.left(11) == "Packed Size") write = true;
                            else if(line.left(4) == QStringLiteral("叢集大小")) write = false;
                        }
                    }
                    else{
                        while (!in.atEnd()){
                            line = in.readLine();
                            if(line.left(4) == "Type") {
                                write = true;
                                line.replace("Type",trType);
                            }
                            else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                            else if(line.left(9) == "There are") write = false;
                            else if(line.left(13) == "Physical Size") {
                                write = true;
                                line.replace("Physical Size",trPhysical_Size);
                            }
                            else if(line.left(8) == "Embedded") line.replace("Embedded Stub Size",trEmbedded_Stub_Size);
                            else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                            else if(line.left(6) == "Method") line.replace("Method",trMethod);
                            else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                            else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                            else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                            else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                            else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                            else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                            else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                            else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                            else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                            else if(line.left(7) == "Comment") line.replace("Comment",trComment);
                            else if(line.left(7) == "   Date") {
                                line.replace("   Date      Time",trDateTime);
                                line.replace("Attr",trAttr);
                                line.replace("     Size",trSize);
                                line.replace("Compressed",trCompressed);
                                line.replace("Name",trName);
                            }
                            else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                            else if(line == "") { delUseless++; if(delUseless == 6) break; }
                            if(write) ui->rar_viewFileList->setText(ui->rar_viewFileList->toPlainText()+line+"\n");
                        }
                    }
                    file.close();
                    //讀取txt並寫入textEdit
                    runCmd("del /f /q C:\\Windows\\Temp\\list.txt"); //使用完畢後刪除txt
                    if(ui->rar_viewFileList->toPlainText() == "") ui->rar_viewFileList->setPlainText(QStringLiteral("錯誤，可能的原因有以下幾種：\n"
                                                                                                                    "1. 檔案損毀\n2. 非支援的檔案標頭\n3. 該檔案正在使用中"));
                }
                else ui->rar_viewFileList->setPlainText(QStringLiteral("必須為WinRAR和7-Zip都支援的壓縮檔格式才能查看"));
            }
        }
        else if(ui->tabWidget->currentIndex() == 1 && ui->tab_7z->currentIndex() == 1){ //限制7-Zip解壓開啟格式
            ok = isArchive_7Zip(path);
            if(!ok){
                QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"), QStringLiteral("非7-Zip支援的解壓縮格式"));
                msg->exec();
            }
            else {
                int delUseless = 0;
                //輸出檔案清單txt
                QString cmd = sz + " l \"" + path + "\" -bso1 >" + " C:\\Windows\\Temp\\list.txt";
                runCmd(cmd);
                //輸出檔案清單txt

                ui->sz_viewFileList->clear();

                //讀取txt並寫入textEdit
                bool write = false;
                QFile file("C:\\Windows\\Temp\\list.txt");
                if(!file.open(QFile::ReadOnly|QFile::Text)) return;
                QTextStream in(&file);
                if(isSplit(path)){
                    while (!in.atEnd()){
                        line = in.readLine();
                        if(line == "Type = Split") { write = true; line.replace("Type",trType); }
                        else if(line.left(4) == "Type") {
                            write = true;
                            ui->sz_viewFileList->setText(ui->sz_viewFileList->toPlainText()+
                                                          QStringLiteral("--------------------------合併分割檔後--------------------------")+"\n");
                            line.replace("Type",trType);
                        }
                        else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                        else if(line.left(9) == "There are") write = false;
                        else if(line.left(13) == "Physical Size") { write = true; line.replace("Physical Size",trPhysical_Size); }
                        else if(line.left(4) == "Size") line.replace("Size",trPacked_Size);
                        else if(line.left(11) == "Packed Size") write = false;
                        else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                        else if(line.left(9) == "Code Page") line.replace("Code Page",trCodePage);
                        else if(line.left(6) == "Method") line.replace("Method",trMethod);
                        else if(line.left(12) == "Cluster Size") line.replace("Cluster Size",trCluster_Size);
                        else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                        else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                        else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                        else if(line.left(7) == "Streams") line.replace("Streams",trStreams);
                        else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                        else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                        else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                        else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                        else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                        else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                        else if(line.left(7) == "Comment") { write = true; line.replace("Comment",trComment); }
                        else if(line.left(7) == "Version") line.replace("Version",trVersion);
                        else if(line.left(6) == "Volume") line.replace("Volume",trVolume);
                        else if(line.left(6) == "Images") line.replace("Images",trImages);
                        else if(line.left(7) == "   Date") {
                            line.replace("   Date      Time",trDateTime);
                            line.replace("Attr",trAttr);
                            line.replace("     Size",trSize);
                            line.replace("Compressed",trCompressed);
                            line.replace("Name",trName);
                        }
                        else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                        else if(line == "") { delUseless++; if(delUseless == 6) break; }
                        if(write) ui->sz_viewFileList->setText(ui->sz_viewFileList->toPlainText()+line+"\n");
                        if(line.left(5) == QStringLiteral("總物理大小")) {
                            if(inpath.right(10) == ".part1.rar") write = true;
                            else write = false;
                        }
                        else if(line.left(11) == "Packed Size") write = true;
                        else if(line.left(4) == QStringLiteral("叢集大小")) write = false;
                    }
                }
                else{
                    while (!in.atEnd()){
                        line = in.readLine();
                        if(line.left(4) == "Type") {
                            write = true;
                            line.replace("Type",trType);
                        }
                        else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                        else if(line.left(9) == "There are") write = false;
                        else if(line.left(13) == "Physical Size") {
                            write = true;
                            line.replace("Physical Size",trPhysical_Size);
                        }
                        else if(line.left(8) == "Embedded") line.replace("Embedded Stub Size",trEmbedded_Stub_Size);
                        else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                        else if(line.left(6) == "Method") line.replace("Method",trMethod);
                        else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                        else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                        else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                        else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                        else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                        else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                        else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                        else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                        else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                        else if(line.left(7) == "Comment") line.replace("Comment",trComment);
                        else if(line.left(7) == "   Date") {
                            line.replace("   Date      Time",trDateTime);
                            line.replace("Attr",trAttr);
                            line.replace("     Size",trSize);
                            line.replace("Compressed",trCompressed);
                            line.replace("Name",trName);
                        }
                        else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                        else if(line == "") { delUseless++; if(delUseless == 6) break; }
                        if(write) ui->sz_viewFileList->setText(ui->sz_viewFileList->toPlainText()+line+"\n");
                    }
                }
                file.close();
                //讀取txt並寫入textEdit
                runCmd("del /f /q C:\\Windows\\Temp\\list.txt"); //使用完畢後刪除txt
                if(ui->sz_viewFileList->toPlainText() == "") ui->sz_viewFileList->setPlainText(QStringLiteral("錯誤，可能的原因有以下幾種：\n"
                                                                                                                "1. 檔案損毀\n2. 非支援的檔案標頭\n3. 該檔案正在使用中"));
            }
        }
        else if(ui->tabWidget->currentIndex() == 3 && ui->tab_paq->currentIndex() == 1){ //限制其他解壓開啟格式

        }
    }
    if(!ok) ui->lineEdit->setText(QStringLiteral("可直接拖曳檔案或資料夾至此"));
}
void MainWindow::on_lineEdit_2_textChanged(const QString &path) //當輸出檔案路徑改變時
{
    if(path == "") ui->lineEdit_2->setText(QStringLiteral("選擇輸出位置"));
    else if(path != "" && path != QStringLiteral("選擇輸出位置")) outpath = path;
}

void MainWindow::closeEvent(QCloseEvent *event) { //關閉事件 (刪除plugins)
    event->ignore();
    QMessageBox msgbox;
    msgbox.setText(QStringLiteral("<font size='8' color='black'><b>確定關閉？</b></font>"));
    msgbox.setWindowTitle(QStringLiteral("Quit?"));
    msgbox.setIcon(QMessageBox::Information);
    //強制調整MessageBox大小
    QSpacerItem* horizontalSpacer = new QSpacerItem(200, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)msgbox.layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
    QPushButton *quitbtn = msgbox.addButton(QStringLiteral("確定"),QMessageBox::ActionRole);
    QPushButton *abortbtn = msgbox.addButton(QStringLiteral("取消"),QMessageBox::ActionRole);
    msgbox.exec();
    if(msgbox.clickedButton()==quitbtn){
        timer->stop();
        runCmd("del /f /q C:\\Windows\\Temp\\rar.exe\n"
               "del /f /q C:\\Windows\\Temp\\RarFiles.lst\n"
               "del /f /q C:\\Windows\\Temp\\rarreg.key\n"
               "del /f /q C:\\Windows\\Temp\\7z.exe\n"
               "del /f /q C:\\Windows\\Temp\\upx.exe\n"
               "del /f /q C:\\Windows\\Temp\\pxd.exe\n"
               "del /f /q C:\\Windows\\Temp\\px.exe\n"
               "del /f /q C:\\Windows\\Temp\\cmix.exe\n"
               "del /f /q C:\\Windows\\Temp\\bcm.exe\n"
               "del /f /q C:\\Windows\\Temp\\english.exp\n"
               "del /f /q C:\\Windows\\Temp\\english.dic\n"
               "del /f /q C:\\Windows\\Temp\\english.emb\n"
               "del /f /q C:\\Windows\\Temp\\kkanzi.exe\n"
               "del /f /q C:\\Windows\\Temp\\comment.txt\n"
               "del /f /q C:\\Windows\\Temp\\checkver.txt");
        event->accept();
    }
    else if(msgbox.clickedButton()==abortbtn){}
}

//------------------------------通用設定-------------------------------//

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

//------------------------------WinRAR-------------------------------//
//壓縮設定
void MainWindow::on_pushButton_2_clicked() //執行壓縮指令
{
    QString cmd, unit;
    int splitsize = ui->rar_splitsize->value();
    int splitnum = ui->rar_splitnum->value();
    bool stop = false, setpwd = false;

    ui->statusBar->clearMessage(); //清除statusBar
    ui->rar_cmdOutput->clear(); //清除命令執行進度

    if(!pwd.isEmpty()){ //設定密碼
        QFile mfile("pwd.txt");
        if(!mfile.open(QFile::WriteOnly|QFile::Text)) return;
        QTextStream out(&mfile);
        out<<pwd;
        mfile.flush();
        mfile.close();
        setpwd = true;
    }

    cmd = rar + " a -ep1 -r ";

    if(splitnum != 0 && splitsize != 0) stop = true; //避免分割檔設定衝突
    else if(splitsize != 0) { //指定分割大小設定
        switch (ui->rar_splitunit->currentIndex()) {
        case 0: unit = "b ";  break;
        case 1: unit = "k ";  break;
        case 2: unit = "m ";  break;
        case 3: unit = "g ";  break;
        }
        cmd += "-v" + QString::number(splitsize) + unit;
    }
    else if(splitnum != 0) { //指定分割數設定
        cmd += "-v" + QString::number(Getfilesize(inpath) / splitnum +1) + "b ";
    }

    if(ui->rar_rb->isChecked()) { //使用RAR4格式壓縮
        cmd += "-ma4 -md";
        switch (ui->rar_dictsize->currentIndex()){ //RAR4字典檔大小
        case 0: cmd += "64k "; break;
        case 1: cmd += "128k "; break;
        case 2: cmd += "256k "; break;
        case 3: cmd += "512k "; break;
        case 4: cmd += "1 "; break;
        case 5: cmd += "2 "; break;
        case 6: cmd += "4 "; break;
        }
    }
    else {
        cmd += "-md";
        switch (ui->rar_dictsize->currentIndex()){ //RAR5字典檔大小
        case 0: cmd += "128k "; break;
        case 1: cmd += "256k "; break;
        case 2: cmd += "512k "; break;
        case 3: cmd += "1 "; break;
        case 4: cmd += "2 "; break;
        case 5: cmd += "4 "; break;
        case 6: cmd += "8 "; break;
        case 7: cmd += "16 "; break;
        case 8: cmd += "32 "; break;
        case 9: cmd += "64 "; break;
        case 10: cmd += "128 "; break;
        case 11: cmd += "256 "; break;
        case 12: cmd += "512 "; break;
        case 13: cmd += "1g "; break;
        }
    }
    cmd += "-m" + QString::number(ui->rar_complv->currentIndex()) + " "; //設定壓縮等級
    cmd += "-ri" + QString::number(ui->rar_other_ri->value()) + " "; //設定優先權
    //細項設定
    if(ui->rar_other_df->isChecked()) cmd += "-df "; //壓縮完將原檔案刪除
    if(ui->rar_other_dw->isChecked()) cmd += "-dw "; //壓縮完將原檔案抹除
    if(ui->rar_other_t->isChecked()) cmd += "-t "; //壓縮完測試壓縮檔
    if(ui->rar_other_s->isChecked()) cmd += "-s "; //建立結實壓縮檔
    if(ui->rar_other_k->isChecked()) cmd += "-k "; //鎖定壓縮檔
    if(ui->rar_other_ed->isChecked()) cmd += "-ed "; //不加入空資料夾
    if(ui->rar_other_ioff->currentIndex() == 1) cmd += "-ioff "; //操作完畢關閉電腦
    else if(ui->rar_other_ioff->currentIndex() == 2) cmd += "-ioff2 "; //操作完畢休眠電腦
    else if(ui->rar_other_ioff->currentIndex() == 3) cmd += "-ioff3 "; //操作完畢睡眠電腦
    if(ui->rar_other_ms->isChecked()) cmd += "-ms "; //略過已壓縮的檔案
    if(ui->rar_other_vp->isChecked()) cmd += "-vp "; //每次分割檔案之前暫停
    if(ui->rar_other_qo->isChecked()) cmd += "-qo+ "; //加入快速開啟資訊
    if(ui->rar_other_qo_2->isChecked()) cmd += "-qo- "; //完全排除快速開啟資訊
    if(ui->rar_other_oc->isChecked()) cmd += "-oc "; //設定 NTFS 壓縮屬性
    if(ui->rar_other_mt->currentIndex() != 0) { //設定執行緒
        cmd += "-mt" + QString::number(ui->rar_other_mt->currentIndex()) + " ";
    }
    //細項設定

    if(!stop) {
        if(ui->lineEdit->text() == QStringLiteral("可直接拖曳檔案或資料夾至此")) {
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇欲壓縮的檔案或資料夾！"));
            msg->exec();
        }
        else if(ui->lineEdit_2->text() == QStringLiteral("選擇輸出位置")) {
            QMessageBox *msg = new QMessageBox;
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle(QStringLiteral("訊息"));
            msg->setText(QStringLiteral("未選擇輸出位置，是否輸出到當前目錄？"));
            QPushButton *ok = msg->addButton(QStringLiteral("是"),QMessageBox::ActionRole);
            QPushButton *no = msg->addButton(QStringLiteral("否"),QMessageBox::ActionRole);
            msg->exec();
            if(msg->clickedButton() == ok){
                outpath = deleteFileName(inpath) + "\\output.rar";
                //------------加入密碼------------
                if(setpwd) {
                    if(ui->rar_Encryption1->isChecked()) cmd += "-p \"" + outpath + "\" \"" + inpath + "\" < pwd.txt";
                    else if(ui->rar_Encryption2->isChecked()) cmd += "-hp \"" + outpath + "\" \"" + inpath + "\" < pwd.txt";
                }
                else cmd += "\"" + outpath + "\" \"" + inpath + "\"";
                //------------加入密碼------------
                runCmdForCompOrDecomp(cmd);
                ui->tab_winrar->setCurrentIndex(3); //跳到命令執行進度畫面
                //等待壓縮完成才取得檔案大小
                while(!ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("完成"))) delay_1ms();
                ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                          "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath)).arg((Getfilesize(outpath)*100)/Getfilesize(inpath)));
            }
            else if(msg->clickedButton() == no){}
        }
        else {
            //------------加入密碼------------
            if(setpwd) {
                if(ui->rar_Encryption1->isChecked()) cmd += "-p " + outpath + " " + inpath + " < pwd.txt";
                else if(ui->rar_Encryption2->isChecked()) cmd += "-hp " + outpath + " " + inpath + " < pwd.txt";
            }
            else cmd += "\"" + outpath + "\" \"" + inpath + "\"";
            //------------加入密碼------------
            runCmdForCompOrDecomp(cmd);
            ui->tab_winrar->setCurrentIndex(3); //跳到命令執行進度畫面
            //等待壓縮完成才取得檔案大小
            while(!ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("完成"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                      "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath)).arg((Getfilesize(outpath)*100)/Getfilesize(inpath)));
        }
    }
    else { //顯示執行錯誤訊息
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤！"),
                                           QStringLiteral("分割方式只能擇一\n請將指定大小或分割數設為0   \n\n操作已中斷"));
        msg->exec();
    }
}
void MainWindow::on_pushButton_6_clicked() //加入or編輯註解至選擇的壓縮檔
{
    QString input = ui->commenttext->toPlainText();
    QFile mfile("C:\\Windows\\Temp\\comment.txt");
    if(!mfile.open(QFile::WriteOnly|QFile::Text)) return;
    QTextStream out(&mfile);
    out<<input;
    mfile.flush();
    mfile.close();

    QString cmd = rar + " c -zC:\\Windows\\Temp\\comment.txt \"" + inpath + "\"";
    runCmd(cmd);
}
void MainWindow::on_pushButton_9_clicked() //讀取壓縮檔註解
{
    QString line;
    QString cmd = rar + " cw \"" + inpath + "\" C:\\Windows\\Temp\\readcomm.txt";
    runCmd(cmd);

    ui->commenttext_2->clear();

    QFile file("C:\\Windows\\Temp\\readcomm.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text)) return;
    QTextStream in(&file);
    while (!in.atEnd()){
        line = in.readLine();
        ui->commenttext_2->setText(ui->commenttext_2->toPlainText()+line+"\n");
    }
    file.close();

    runCmd("del /f /q C:\\Windows\\Temp\\readcomm.txt");
}
void MainWindow::on_rar_comm_outpath_btn_clicked() //輸出註解為文字檔
{
    QString cmd = rar + " cw ";
    QString output = QFileDialog::getSaveFileName(this, QStringLiteral("輸出註解為文字檔"), "/", QStringLiteral("文字檔 (*.txt)"));
    if(output != "") {
        if(ui->rar_scfc->isChecked()) cmd += "-scfc ";
        else if(ui->rar_scuc->isChecked()) cmd += "-scuc ";
        else if(ui->rar_scac->isChecked()) cmd += "-scac ";
        else cmd += "-scoc ";
        cmd += "\"" + inpath  + "\" \"" + output + "\"";
        runCmd(cmd);
    }
}
void MainWindow::on_rar_setpwd_btn_clicked() //加入壓縮檔密碼
{
    bool ok;
    QString text = QInputDialog::getText(this,QStringLiteral("請輸入"),QStringLiteral("請輸入密碼："),QLineEdit::Password,"",&ok);
    if (ok && !text.isEmpty()) pwd = text;
}
void MainWindow::on_rar_rb_pressed() //RAR4專用設定配置
{
    ui->rar_other_oc->setEnabled(true);
    ui->rar_other_dw->setEnabled(true);
    ui->rar_other_k->setEnabled(true);
    ui->rar_other_s->setEnabled(true);
    ui->rar_other_qo->setEnabled(false);
    ui->rar_other_qo_2->setEnabled(false);
    ui->rar_Encryption2->setDisabled(false);
    ui->rar_dictsize->clear();
    ui->rar_dictsize->insertItem(0,"64 KB");
    ui->rar_dictsize->insertItem(1,"128 KB");
    ui->rar_dictsize->insertItem(2,"256 KB");
    ui->rar_dictsize->insertItem(3,"512 KB");
    ui->rar_dictsize->insertItem(4,"1024 KB");
    ui->rar_dictsize->insertItem(5,"2048 KB");
    ui->rar_dictsize->insertItem(6,"4096 KB");
    ui->rar_dictsize->setCurrentIndex(6);
}
void MainWindow::on_rar5_rb_pressed() //RAR5專用設定配置
{
    ui->rar_other_oc->setEnabled(true);
    ui->rar_other_dw->setEnabled(true);
    ui->rar_other_k->setEnabled(true);
    ui->rar_other_s->setEnabled(true);
    ui->rar_other_qo->setEnabled(true);
    ui->rar_other_qo_2->setEnabled(true);
    ui->rar_Encryption2->setDisabled(false);
    ui->rar_dictsize->clear();
    ui->rar_dictsize->insertItem(0,"128 KB");
    ui->rar_dictsize->insertItem(1,"256 KB");
    ui->rar_dictsize->insertItem(2,"512 KB");
    ui->rar_dictsize->insertItem(3,"1 MB");
    ui->rar_dictsize->insertItem(4,"2 MB");
    ui->rar_dictsize->insertItem(5,"4 MB");
    ui->rar_dictsize->insertItem(6,"8 MB");
    ui->rar_dictsize->insertItem(7,"16 MB");
    ui->rar_dictsize->insertItem(8,"32 MB");
    ui->rar_dictsize->insertItem(9,"64 MB");
    ui->rar_dictsize->insertItem(10,"128 MB");
    ui->rar_dictsize->insertItem(11,"256 MB");
    ui->rar_dictsize->insertItem(12,"512 MB");
    ui->rar_dictsize->insertItem(13,"1 GB");
    ui->rar_dictsize->setCurrentIndex(8);
}
//壓縮設定

//解壓設定
void MainWindow::on_unrar_btn_clicked() //解壓
{
    ui->statusBar->clearMessage(); //清除statusBar
    ui->rar_cmdOutput->clear(); //清除命令執行進度
    QString cmd = rar + " x ";
    if(ui->unrar_noComm->isChecked()) cmd += "-c- ";
    if(ui->unrar_kb->isChecked()) cmd += "-kb ";
    if(ui->unrar_ad->isChecked()) cmd += "-ad ";
    if(ui->unrar_oni->isChecked()) cmd += "-oni ";
    if(ui->unrar_or->isChecked()) cmd += "-or ";
    if(ui->unrar_ep->isChecked()) cmd += "-ep ";
    switch (ui->unrar_o->currentIndex()) { //設定覆寫模式
    case 0: cmd += "-o+ "; break;
    case 1: cmd += "-o- "; break;
    }
    cmd += "\"" + inpath + "\" \"";
    if(ui->lineEdit->text() == QStringLiteral("可直接拖曳檔案或資料夾至此")) {
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇欲解壓縮的檔案！"));
        msg->exec();
    }
    else if(ui->lineEdit_2->text() == QStringLiteral("選擇輸出位置")) {
        if(!isArchive_WinRAR(inpath)){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇正確的壓縮檔！"));
            msg->exec();
        }
        else {
            QMessageBox *msg = new QMessageBox;
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle(QStringLiteral("訊息"));
            msg->setText(QStringLiteral("未選擇輸出位置，是否輸出到當前目錄？"));
            QPushButton *ok = msg->addButton(QStringLiteral("是"),QMessageBox::ActionRole);
            QPushButton *no = msg->addButton(QStringLiteral("否"),QMessageBox::ActionRole);
            msg->exec();
            if(msg->clickedButton() == ok){
                cmd += "\"" + deleteFileName(inpath) + "\"";
                runCmdForCompOrDecomp(cmd);
                ui->tab_winrar->setCurrentIndex(3); //跳到命令執行進度畫面
                //等待解壓縮完成
                while(1) {
                    delay_1ms();
                    if(ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("全部確認"))) {
                        ui->statusBar->showMessage(QStringLiteral("指令執行成功！"));
                        break;
                    }
                   else if(ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("沒有要解壓縮的檔案"))) {
                        ui->statusBar->showMessage(QStringLiteral("指令執行失敗！"));
                        break;
                    }
                }
            }
            else if(msg->clickedButton() == no){}
        }
    }
    else {
        if(!isArchive_WinRAR(inpath)){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇正確的壓縮檔！"));
            msg->exec();
        }
        else {
            cmd += outpath + "\"";
            runCmdForCompOrDecomp(cmd);
            ui->tab_winrar->setCurrentIndex(3); //跳到命令執行進度畫面
            //等待解壓縮完成
            while(1) {
                delay_1ms();
                if(ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("全部確認"))) {
                    ui->statusBar->showMessage(QStringLiteral("指令執行成功！"));
                    break;
                }
               else if(ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("沒有要解壓縮的檔案"))) {
                    ui->statusBar->showMessage(QStringLiteral("指令執行失敗！"));
                    break;
                }
            }
        }
    }
}
void MainWindow::on_unrar_viewbtn_clicked() //查看壓縮檔內容
{
    QString line;
    int delUseless = 0;

    if(isArchive_WinRAR(inpath) && isArchive_7Zip(inpath)){
        //輸出檔案清單txt
        QString cmd = sz + " l \"" + inpath + "\" -bso1 >" + " C:\\Windows\\Temp\\list.txt";
        runCmd(cmd);
        //輸出檔案清單txt

        ui->rar_viewFileList->clear();

        //讀取txt並寫入textEdit
        bool write = false;
        QFile file("C:\\Windows\\Temp\\list.txt");
        if(!file.open(QFile::ReadOnly|QFile::Text)) return;
        QTextStream in(&file);
        if(isSplit(inpath)){
            while (!in.atEnd()){
                line = in.readLine();
                if(line == "Type = Split") { write = true; line.replace("Type",trType); }
                else if(line.left(4) == "Type") {
                    write = true;
                    ui->rar_viewFileList->setText(ui->rar_viewFileList->toPlainText()+
                                                  QStringLiteral("--------------------------合併分割檔後--------------------------")+"\n");
                    line.replace("Type",trType);
                }
                else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                else if(line.left(9) == "There are") write = false;
                else if(line.left(13) == "Physical Size") { write = true; line.replace("Physical Size",trPhysical_Size); }
                else if(line.left(4) == "Size") line.replace("Size",trPacked_Size);
                else if(line.left(11) == "Packed Size") write = false;
                else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                else if(line.left(9) == "Code Page") line.replace("Code Page",trCodePage);
                else if(line.left(6) == "Method") line.replace("Method",trMethod);
                else if(line.left(12) == "Cluster Size") line.replace("Cluster Size",trCluster_Size);
                else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                else if(line.left(7) == "Streams") line.replace("Streams",trStreams);
                else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                else if(line.left(7) == "Comment") { write = true; line.replace("Comment",trComment); }
                else if(line.left(7) == "Version") line.replace("Version",trVersion);
                else if(line.left(6) == "Volume") line.replace("Volume",trVolume);
                else if(line.left(6) == "Images") line.replace("Images",trImages);
                else if(line.left(7) == "   Date") {
                    line.replace("   Date      Time",trDateTime);
                    line.replace("Attr",trAttr);
                    line.replace("     Size",trSize);
                    line.replace("Compressed",trCompressed);
                    line.replace("Name",trName);
                }
                else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                else if(line == "") { delUseless++; if(delUseless == 6) break; }
                if(write) ui->rar_viewFileList->setText(ui->rar_viewFileList->toPlainText()+line+"\n");
                if(line.left(5) == QStringLiteral("總物理大小")) {
                    if(inpath.right(10) == ".part1.rar") write = true;
                    else write = false;
                }
                else if(line.left(11) == "Packed Size") write = true;
                else if(line.left(4) == QStringLiteral("叢集大小")) write = false;
            }
        }
        else{
            while (!in.atEnd()){
                line = in.readLine();
                if(line.left(4) == "Type") {
                    write = true;
                    line.replace("Type",trType);
                }
                else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                else if(line.left(9) == "There are") write = false;
                else if(line.left(13) == "Physical Size") {
                    write = true;
                    line.replace("Physical Size",trPhysical_Size);
                }
                else if(line.left(8) == "Embedded") line.replace("Embedded Stub Size",trEmbedded_Stub_Size);
                else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                else if(line.left(6) == "Method") line.replace("Method",trMethod);
                else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                else if(line.left(7) == "Comment") line.replace("Comment",trComment);
                else if(line.left(7) == "   Date") {
                    line.replace("   Date      Time",trDateTime);
                    line.replace("Attr",trAttr);
                    line.replace("     Size",trSize);
                    line.replace("Compressed",trCompressed);
                    line.replace("Name",trName);
                }
                else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                else if(line == "") { delUseless++; if(delUseless == 6) break; }
                if(write) ui->rar_viewFileList->setText(ui->rar_viewFileList->toPlainText()+line+"\n");
            }
        }
        file.close();
        //讀取txt並寫入textEdit

        if(ui->rar_viewFileList->toPlainText() == "") ui->rar_viewFileList->setPlainText(QStringLiteral("錯誤，可能的原因有以下幾種：\n"
                                                                                                        "1. 檔案損毀\n2. 非支援的檔案標頭\n3. 該檔案正在使用中"));
    }
    else ui->rar_viewFileList->setPlainText(QStringLiteral("必須為WinRAR和7-Zip都支援的壓縮檔格式才能查看"));

    runCmd("del /f /q C:\\Windows\\Temp\\list.txt"); //使用完畢後刪除txt
}
//解壓設定

//快速功能
void MainWindow::on_unrar_1click_clicked() //一鍵解壓到當前資料夾
{
    ui->statusBar->clearMessage(); //清除statusBar
    ui->rar_cmdOutput->clear(); //清除命令執行進度
    QString cmd = rar + " x ";
    if(ui->unrar_noComm->isChecked()) cmd += "-c- ";
    if(ui->unrar_kb->isChecked()) cmd += "-kb ";
    if(ui->unrar_ad->isChecked()) cmd += "-ad ";
    if(ui->unrar_oni->isChecked()) cmd += "-oni ";
    if(ui->unrar_or->isChecked()) cmd += "-or ";
    if(ui->unrar_ep->isChecked()) cmd += "-ep ";
    switch (ui->unrar_o->currentIndex()) { //設定覆寫模式
    case 0: cmd += "-o+ "; break;
    case 1: cmd += "-o- "; break;
    }
    cmd += "\"" + inpath + "\" \"" + deleteFileName(inpath) + "\"";
    if(ui->lineEdit->text() == QStringLiteral("可直接拖曳檔案或資料夾至此")) {
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇欲解壓縮的檔案！"));
        msg->exec();
    }
    else {
        if(!isArchive_WinRAR(inpath)){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇正確的壓縮檔！"));
            msg->exec();
        }
        else {
            runCmdForCompOrDecomp(cmd);
            //等待壓縮完成才取得檔案大小
            while(!ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("完成"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("指令執行完畢！"));
        }
    }
}
//快速功能

//設定提醒通知
void MainWindow::on_rar_other_df_clicked() //壓縮完將原檔案刪除
{
    if(ui->rar_other_dw->isChecked() && ui->rar_other_df->isChecked()){
        if(WarningMsg){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤！"),QStringLiteral("刪除和抹除只能二擇一"));
            msg->exec();
        }
        ui->rar_other_df->setChecked(false);
    }
}
void MainWindow::on_rar_other_dw_clicked() //壓縮完將原檔案抹除
{
    if(ui->rar_other_dw->isChecked()){
        if(ui->rar_other_df->isChecked()){
            if(WarningMsg){
                QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤！"),QStringLiteral("刪除和抹除只能二擇一"));
                msg->exec();
            }
            ui->rar_other_dw->setChecked(false);
        }
        else if(TipMsg) {
            QMessageBox *msg = new QMessageBox(QMessageBox::Information,QStringLiteral("注意！"),QStringLiteral("此選項只適用於機械式硬碟(HDD)"));
            msg->exec();
        }

    }
}
void MainWindow::on_rar_other_ms_clicked() //略過已壓縮的檔案
{
    if(ui->rar_other_ms->isChecked() && TipMsg){
        QMessageBox *msg = new QMessageBox(QMessageBox::Information,QStringLiteral("功能介紹"),
                                           QStringLiteral("此設定會將已壓縮的檔案用\"儲存\"的方式加入壓縮檔\n"
                                                          "這有助於提高壓縮速度，不會有明顯的壓縮比損失\n\n"
                                                          "不會被壓縮的檔案類型有以下幾種：\n"
                                                          "7z、ace、arj、bz2、cab、gz、jpeg、jpg、lha、lz\n"
                                                          "lzh、mp3、rar、taz、tgz、xz、z、zip、zipx"));
        msg->exec();
    }
}
void MainWindow::on_rar_other_qo_clicked() //加入快速開啟資訊
{
    if(ui->rar_other_qo->isChecked() && ui->rar_other_qo_2->isChecked()){
        ui->rar_other_qo->setChecked(false);
        if(WarningMsg){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),
                                               QStringLiteral("加入或排除只能擇一選用"));
            msg->exec();
        }
    }
}
void MainWindow::on_rar_other_qo_2_clicked() //完全排除快速開啟資訊
{
    if(ui->rar_other_qo->isChecked() && ui->rar_other_qo_2->isChecked()){
        ui->rar_other_qo_2->setChecked(false);
        if(WarningMsg){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),
                                               QStringLiteral("加入或排除只能擇一選用"));
            msg->exec();
        }
    }
}
void MainWindow::on_unrar_oni_stateChanged(int state) //允許潛在不相容名稱
{
    if(state != 0 && TipMsg){
        QMessageBox *msg = new QMessageBox(QMessageBox::Information,QStringLiteral("功能介紹"),
                                           QStringLiteral("由於NTFS檔案系統允許檔名後面存在空格及小數點，\n"
                                                          "而非常多的Windows程式無法正確處理這類檔案。\n"
                                                          "如果沒有啟用此選項將會移除檔名後面的空格及小數點。"));
        msg->exec();
    }
}
void MainWindow::on_rar_dictsize_currentIndexChanged(int index) //提醒字典檔設定及功能
{
    if(ui->rar5_rb->isChecked() && index > 10 && TipMsg){
        QString freeRAM, status, neededRAM;
        freeRAM = QString::number(GetFreeRAM());
        if(index == 11) neededRAM = QString::number(256*6);
        else if(index == 12) neededRAM = QString::number(512*6);
        else if(index == 13) neededRAM = QString::number(1024*6);
        if(freeRAM.toInt() <= neededRAM.toInt()) status = QStringLiteral("記憶體不足！請降低字典檔大小");
        else status = QStringLiteral("記憶體充足！");

        QMessageBox msgbox;
        msgbox.setWindowTitle(QStringLiteral("功能介紹"));
        msgbox.setInformativeText(QStringLiteral("<font size='7' color='black'><b>注意：</b></font><br>"
                                                 "<font size='6' color='black'>"
                                                 "執行操作前請務必確保有足夠的記憶體供WinRAR使用<br>"
                                                 "需占用的記憶體：<font size='6' color='blue'><b>%1MB</b></font><br>"
                                                 "空閒記憶體：<font size='6' color='blue'><b>%2MB</b></font><br>"
                                                 "狀態：<font size='6' color='red'><b>%3</b></font><br><br></font>"
                                                 "<font size='7' color='black'><b>關於字典檔：</b></font><br>"
                                                 "<font size='6' color='black'>"
                                                 "字典檔是用來尋找和壓縮重複資料特徵的記憶體<br>"
                                                 "增加字典檔大小能些微提高壓縮率<br>"
                                                 "但也會造成壓縮速度降低以及記憶體的使用量增加<br>"
                                                 "RAR格式進行壓縮時會占用約指定字典檔大小6倍的記憶體<br>"
                                                 "解壓縮時占用的記憶體則略大於指定字典檔大小<br></font>").arg(neededRAM).arg(freeRAM).arg(status));
        msgbox.setIcon(QMessageBox::Warning);
        msgbox.setStandardButtons(QMessageBox::Ok);
        //強制調整MessageBox大小
        QSpacerItem* horizontalSpacer = new QSpacerItem(700, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        QGridLayout* layout = (QGridLayout*)msgbox.layout();
        layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
        msgbox.exec();
    }
}
void MainWindow::on_rar_splitsize_valueChanged(int value) //警告分割檔設定衝突
{
    if(ui->rar_splitnum->value() != 0 && value != 0 && WarningMsg){
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤！"),
                                           QStringLiteral("分割方式只能擇一\n請先將指定分割數設為0   "));
        msg->exec();
    }
}
void MainWindow::on_rar_splitnum_valueChanged(int value) //警告分割檔設定衝突
{
    if(value != 0 && ui->rar_splitsize->value() != 0 && WarningMsg){
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤！"),
                                           QStringLiteral("分割方式只能擇一\n請先將指定大小設為0   "));
        msg->exec();
    }
}

//設定提醒通知

//------------------------------WinRAR-------------------------------//

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

//------------------------------7-Zip---------------------------------//


//解壓設定
void MainWindow::on_sz_viewbtn_clicked() //查看壓縮檔內容
{
    QString line;
    int delUseless = 0;

    if(isArchive_7Zip(inpath)){
        //輸出檔案清單txt
        QString cmd = sz + " l \"" + inpath + "\" -bso1 >" + " C:\\Windows\\Temp\\list.txt";
        runCmd(cmd);
        //輸出檔案清單txt

        ui->sz_viewFileList->clear();

        //讀取txt並寫入textEdit
        bool write = false;
        QFile file("C:\\Windows\\Temp\\list.txt");
        if(!file.open(QFile::ReadOnly|QFile::Text)) return;
        QTextStream in(&file);
        if(isSplit(inpath)){
            while (!in.atEnd()){
                line = in.readLine();
                if(line == "Type = Split") { write = true; line.replace("Type",trType); }
                else if(line.left(4) == "Type") {
                    write = true;
                    ui->sz_viewFileList->setText(ui->sz_viewFileList->toPlainText()+
                                                  QStringLiteral("--------------------------合併分割檔後--------------------------")+"\n");
                    line.replace("Type",trType);
                }
                else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                else if(line.left(9) == "There are") write = false;
                else if(line.left(13) == "Physical Size") { write = true; line.replace("Physical Size",trPhysical_Size); }
                else if(line.left(4) == "Size") line.replace("Size",trPacked_Size);
                else if(line.left(11) == "Packed Size") write = false;
                else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                else if(line.left(9) == "Code Page") line.replace("Code Page",trCodePage);
                else if(line.left(6) == "Method") line.replace("Method",trMethod);
                else if(line.left(12) == "Cluster Size") line.replace("Cluster Size",trCluster_Size);
                else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                else if(line.left(7) == "Streams") line.replace("Streams",trStreams);
                else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                else if(line.left(7) == "Comment") { write = true; line.replace("Comment",trComment); }
                else if(line.left(7) == "Version") line.replace("Version",trVersion);
                else if(line.left(6) == "Volume") line.replace("Volume",trVolume);
                else if(line.left(6) == "Images") line.replace("Images",trImages);
                else if(line.left(7) == "   Date") {
                    line.replace("   Date      Time",trDateTime);
                    line.replace("Attr",trAttr);
                    line.replace("     Size",trSize);
                    line.replace("Compressed",trCompressed);
                    line.replace("Name",trName);
                }
                else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                else if(line == "") { delUseless++; if(delUseless == 6) break; }
                if(write) ui->sz_viewFileList->setText(ui->sz_viewFileList->toPlainText()+line+"\n");
                if(line.left(5) == QStringLiteral("總物理大小")) {
                    if(inpath.right(10) == ".part1.rar") write = true;
                    else write = false;
                }
                else if(line.left(11) == "Packed Size") write = true;
                else if(line.left(4) == QStringLiteral("叢集大小")) write = false;
            }
        }
        else{
            while (!in.atEnd()){
                line = in.readLine();
                if(line.left(4) == "Type") {
                    write = true;
                    line.replace("Type",trType);
                }
                else if(line.left(9) == "WARNINGS:") line.replace("WARNINGS:",trWARNINGS);
                else if(line.left(9) == "There are") write = false;
                else if(line.left(13) == "Physical Size") {
                    write = true;
                    line.replace("Physical Size",trPhysical_Size);
                }
                else if(line.left(8) == "Embedded") line.replace("Embedded Stub Size",trEmbedded_Stub_Size);
                else if(line.left(12) == "Headers Size") line.replace("Headers Size",trHeaders_Size);
                else if(line.left(6) == "Method") line.replace("Method",trMethod);
                else if(line.left(9) == "Tail Size") line.replace("Tail Size",trTail_Size);
                else if(line.left(15) == "Characteristics") line.replace("Characteristics",trCharacteristics);
                else if(line.left(5) == "Solid") line.replace("Solid",trSolid);
                else if(line.left(6) == "Blocks") line.replace("Blocks",trBlocks);
                else if(line.left(9) == "Encrypted") line.replace("Encrypted",trEncrypted);
                else if(line.left(11) == "Multivolume") line.replace("Multivolume",trMultivolume);
                else if(line.left(7) == "Volumes") line.replace("Volumes",trVolumes);
                else if(line.left(12) == "Volume Index") line.replace("Volume Index",trVolumeIndex);
                else if(line.left(19) == "Total Physical Size") line.replace("Total Physical Size",trTotal_Physical_Size);
                else if(line.left(7) == "Comment") line.replace("Comment",trComment);
                else if(line.left(7) == "   Date") {
                    line.replace("   Date      Time",trDateTime);
                    line.replace("Attr",trAttr);
                    line.replace("     Size",trSize);
                    line.replace("Compressed",trCompressed);
                    line.replace("Name",trName);
                }
                else if(line.left(20) == "------------------- ") line.replace("------------------- ","--------------------- ");
                else if(line == "") { delUseless++; if(delUseless == 6) break; }
                if(write) ui->sz_viewFileList->setText(ui->sz_viewFileList->toPlainText()+line+"\n");
            }
        }
        file.close();
        //讀取txt並寫入textEdit

        if(ui->sz_viewFileList->toPlainText() == "") ui->sz_viewFileList->setPlainText(QStringLiteral("錯誤，可能的原因有以下幾種：\n"
                                                                                                        "1. 檔案損毀\n2. 非支援的檔案標頭\n3. 該檔案正在使用中"));
    }
    else ui->sz_viewFileList->setPlainText(QStringLiteral("必須為7-Zip支援的壓縮檔格式才能查看"));

    runCmd("del /f /q C:\\Windows\\Temp\\list.txt"); //使用完畢後刪除txt
}
//解壓設定

//------------------------------7-Zip---------------------------------//

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

//------------------------------UPX---------------------------------//



//------------------------------UPX---------------------------------//

//000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000

//------------------------------其他工具---------------------------//
//壓縮設定
void MainWindow::on_paq_compRunCmd_clicked()
{
    QString cmd;
    QString secFileExt;
    QString compLv =  QString::number(ui->paq_compLv->value());
    QString threads =  QString::number(ui->paq_threads->currentIndex()+1);
    QString px_switch;
    QString temp;
    //用於警告壓縮注意事項
    QMessageBox *msg2 = new QMessageBox;
    QPushButton *ok2 = msg2->addButton(QStringLiteral("繼續"),QMessageBox::ActionRole);
    QPushButton *no2 = msg2->addButton(QStringLiteral("取消"),QMessageBox::ActionRole);

    int tool = ui->others_tool->currentIndex();

    secFileExt = "lv" + compLv; //輸出後改檔名為[*.lv5.1] or [*.lv9.2]依此類推

    ui->paq_cmdOutput->clear(); //清除命令執行進度

    if(ui->lineEdit->text() == QStringLiteral("可直接拖曳檔案或資料夾至此")) {
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇欲壓縮的檔案或資料夾！"));
        msg->exec();
    }
    else if(ui->lineEdit_2->text() == QStringLiteral("選擇輸出位置")) {
        QMessageBox *msg = new QMessageBox;
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle(QStringLiteral("訊息"));
        msg->setText(QStringLiteral("未選擇輸出位置，是否輸出到當前目錄？"));
        QPushButton *ok = msg->addButton(QStringLiteral("是"),QMessageBox::ActionRole);
        QPushButton *no = msg->addButton(QStringLiteral("否"),QMessageBox::ActionRole);
        msg->exec();

        if(msg->clickedButton() == ok){
            outpath = deleteFileName(inpath) + "\\output.";
            temp = outpath;
            switch (tool) {
            case 0: //pxd
                cmd = pxd_new + " -s" + compLv + ":" + threads + " \"" + outpath + secFileExt + "\" \"" + inpath + "\"";
                runCmdForCompOrDecomp(cmd); //開始執行
                ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
                //等待壓縮完成才取得檔案大小
                while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("共花費"))) delay_1ms();
                ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                          "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath + secFileExt + ".1")).arg((Getfilesize(outpath + secFileExt + ".1")*100)/Getfilesize(inpath)));
                break;
            case 1: //px
                if(ui->px_switch_a->isChecked()) px_switch += "a";
                if(ui->px_switch_b->isChecked()) px_switch += "b";
                if(ui->px_switch_e->isChecked()) px_switch += "e";
                if(ui->px_switch_s->isChecked()) px_switch += "s";
                if(ui->paq_dic->currentIndex() == 1) px_switch += "t";

                cmd = px + " -" + compLv + px_switch + " \"" + inpath + "\" \"" + outpath + secFileExt + ".2\"";
                runCmdForCompOrDecomp(cmd); //開始執行
                ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
                //等待壓縮完成才取得檔案大小
                while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("共花費"))) delay_1ms();
                ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                          "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath + secFileExt + ".2")).arg((Getfilesize(outpath + secFileExt + ".2")*100)/Getfilesize(inpath)));
                break;
            case 2: //cmix
                msg2->setIcon(QMessageBox::Warning);
                msg2->setWindowTitle(QStringLiteral("注意！"));
                msg2->setText(QStringLiteral("主記憶體+虛擬記憶體至少需要32GB以上的空間，否則將發生不可預期錯誤"));
                msg2->exec();
                if(msg2->clickedButton() == ok2){}
                else if(msg2->clickedButton() == no2){ break; }

                //歸檔 *.tar
                temp += "tar";
                cmd = sz + " a -ttar -mx0 -sccUTF-8 -bb0 \"-w" + deleteFileName(inpath) + "\" \"" + temp + "\" \"" + inpath + "\"";
                runCmdForCompOrDecomp(cmd); //開始執行歸檔
                //等待歸檔完成才繼續執行後續壓縮
                while(!ui->sz_cmdOutput->toPlainText().contains(QStringLiteral("Everything"))) delay_1ms();
                ui->sz_cmdOutput->clear(); //清除命令執行進度

                outpath = temp;
                outpath.chop(3); //chop "tar"
                //加入字典
                if(ui->paq_dic->currentIndex() == 1) {
                    outpath += "dic.cmix";
                    cmd = cmix + " -c \"" + dic + "\" \"" + temp + "\" \"" + outpath + "\"";
                }
                else {
                    outpath += "cmix";
                    cmd = cmix + " -c" + " \"" + temp + "\" \"" + outpath + "\"";
                }

                runCmdForCompOrDecomp(cmd); //開始執行壓縮
                ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
                //等待壓縮完成才取得檔案大小
                while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("cross entropy"))) delay_1ms();
                ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                          "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath)).arg((Getfilesize(outpath)*100)/Getfilesize(inpath)));
                //刪除tar暫存檔
                delFile = new QFile(temp);
                delFile->remove();
                break;
            case 3: //bcm
                //歸檔 *.tar
                temp += "tar";
                cmd = sz + " a -ttar -mx0 -sccUTF-8 -bb0 \"-w" + deleteFileName(inpath) + "\" \"" + temp + "\" \"" + inpath + "\"";
                runCmdForCompOrDecomp(cmd); //開始執行歸檔
                //等待歸檔完成才繼續執行後續壓縮
                while(!ui->sz_cmdOutput->toPlainText().contains(QStringLiteral("Everything"))) delay_1ms();
                ui->sz_cmdOutput->clear(); //清除命令執行進度

                outpath = temp;
                outpath.chop(3);
                outpath += "bcm";
                cmd = bcm + " -b" + compLv + " -f" + " \"" + temp + "\" \"" + outpath + "\"";

                runCmdForCompOrDecomp(cmd);//開始執行
                ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
                //等待壓縮完成才取得檔案大小
                while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("耗時"))) delay_1ms();
                ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                          "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath)).arg((Getfilesize(outpath)*100)/Getfilesize(inpath)));
                //刪除tar暫存檔
                delFile = new QFile(temp);
                delFile->remove();
                break;
            case 4: //kanzi

                break;
            }
        }
        else if(msg->clickedButton() == no){}
    }
    else {
        switch (tool) {
        case 0: //pxd
            if(!isArchive_pxd2(outpath)) {
                QMessageBox* msg;
                msg = new QMessageBox(QMessageBox::Critical,QStringLiteral("錯誤！"), QStringLiteral("輸出檔案的副檔名請選擇pxd (*.1)"));
                msg->exec();
                break;
            }
            else outpath.chop(1); //先刪除副檔名

            cmd = pxd_new + " -s" + compLv + ":" + threads + " \"" + outpath + secFileExt + "\" \"" + inpath + "\"";
            runCmdForCompOrDecomp(cmd); //開始執行
            ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
            //等待壓縮完成才取得檔案大小
            while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("共花費"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                      "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath + secFileExt + ".1")).arg((Getfilesize(outpath + secFileExt + ".1")*100)/Getfilesize(inpath)));
            break;
        case 1: //px
            if(!isArchive_PX(outpath)) {
                QMessageBox* msg;
                msg = new QMessageBox(QMessageBox::Critical,QStringLiteral("錯誤！"), QStringLiteral("輸出檔案的副檔名請選擇px (*.2)"));
                msg->exec();
                break;
            }
            else outpath.chop(1); //先刪除副檔名

            if(ui->px_switch_a->isChecked()) px_switch += "a";
            if(ui->px_switch_b->isChecked()) px_switch += "b";
            if(ui->px_switch_e->isChecked()) px_switch += "e";
            if(ui->px_switch_s->isChecked()) px_switch += "s";
            if(ui->paq_dic->currentIndex() == 1) px_switch += "t";

            cmd = px + " -" + compLv + px_switch + " \"" + inpath + "\" \"" + outpath + secFileExt + ".2\"";
            runCmdForCompOrDecomp(cmd); //開始執行
            ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
            //等待壓縮完成才取得檔案大小
            while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("共花費"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                      "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath + secFileExt + ".2")).arg((Getfilesize(outpath + secFileExt + ".2")*100)/Getfilesize(inpath)));
            break;
        case 2: //cmix
            if(!isArchive_cmix(outpath)) {
                QMessageBox* msg;
                msg = new QMessageBox(QMessageBox::Critical,QStringLiteral("錯誤！"), QStringLiteral("輸出檔案的副檔名請選擇cmix (*.cmix)"));
                msg->exec();
                break;
            }
            else outpath.chop(4); //先刪除副檔名
            temp = outpath; //這時outpath的格式為 [X:\demo\file.]

            msg2->setIcon(QMessageBox::Warning);
            msg2->setWindowTitle(QStringLiteral("注意！"));
            msg2->setText(QStringLiteral("主記憶體+虛擬記憶體至少需要32GB以上的空間，否則將發生不可預期錯誤"));
            msg2->exec();
            if(msg2->clickedButton() == ok2){}
            else if(msg2->clickedButton() == no2){ break; }

            //歸檔 *.tar
            temp += "tar";
            cmd = sz + " a -ttar -mx0 -sccUTF-8 -bb0 \"-w" + deleteFileName(inpath) + "\" \"" + temp + "\" \"" + inpath + "\"";
            runCmdForCompOrDecomp(cmd); //開始執行歸檔
            //等待歸檔完成才繼續執行後續壓縮
            while(!ui->sz_cmdOutput->toPlainText().contains(QStringLiteral("Everything"))) delay_1ms();
            ui->sz_cmdOutput->clear(); //清除命令執行進度

            outpath = temp;
            outpath.chop(3);
            //加入字典
            if(ui->paq_dic->currentIndex() == 1) {
                outpath += "dic.cmix";
                cmd = cmix + " -c \"" + dic + "\" \"" + temp + "\" \"" + outpath + "\"";
            }
            else {
                outpath += "cmix";
                cmd = cmix + " -c" + " \"" + temp + "\" \"" + outpath + "\"";
            }

            runCmdForCompOrDecomp(cmd); //開始執行壓縮
            ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
            //等待壓縮完成才取得檔案大小
            while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("cross entropy"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                      "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath)).arg((Getfilesize(outpath)*100)/Getfilesize(inpath)));
            //刪除tar暫存檔
            delFile = new QFile(temp);
            delFile->remove();
            break;
        case 3: //bcm
            if(!isArchive_BCM(outpath)) {
                QMessageBox* msg;
                msg = new QMessageBox(QMessageBox::Critical,QStringLiteral("錯誤！"), QStringLiteral("輸出檔案的副檔名請選擇bcm (*.bcm)"));
                msg->exec();
                break;
            }
            else outpath.chop(3); //先刪除副檔名
            temp = outpath; //這時outpath的格式為 [X:\demo\file.]

            //歸檔 *.tar
            temp += "tar";
            cmd = sz + " a -ttar -mx0 -sccUTF-8 -bb0 \"-w" + deleteFileName(inpath) + "\" \"" + temp + "\" \"" + inpath + "\"";
            runCmdForCompOrDecomp(cmd); //開始執行歸檔
            //等待歸檔完成才繼續執行後續壓縮
            while(!ui->sz_cmdOutput->toPlainText().contains(QStringLiteral("Everything"))) delay_1ms();
            ui->sz_cmdOutput->clear(); //清除命令執行進度

            outpath = temp;
            outpath.chop(3);
            outpath += "bcm";
            cmd = bcm + " -b" + compLv + " -f" + " \"" + temp + "\" \"" + outpath + "\"";

            runCmdForCompOrDecomp(cmd); //開始執行
            ui->tab_paq->setCurrentIndex(2); //跳到命令執行進度畫面
            //等待壓縮完成才取得檔案大小
            while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("耗時"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("壓縮成功！大小變化(Bytes)：%1 → %2，"
                                                      "壓縮率：%3%").arg(Getfilesize(inpath)).arg(Getfilesize(outpath)).arg((Getfilesize(outpath)*100)/Getfilesize(inpath)));
            //刪除tar暫存檔
            delFile = new QFile(temp);
            delFile->remove();
            break;
        case 4: //kanzi
            if(!isArchive_Kanzi(outpath)) {
                QMessageBox* msg;
                msg = new QMessageBox(QMessageBox::Critical,QStringLiteral("錯誤！"), QStringLiteral("輸出檔案的副檔名請選擇kanzi (*.knz)"));
                msg->exec();
                break;
            }
            else outpath.chop(3); //先刪除副檔名

            break;
        }
    }
}
void MainWindow::on_others_tool_currentIndexChanged(int index) //各工具專用設定配置
{
    switch (index) {
    case 0://pxd
        ui->paq_threads->setEnabled(true);
        ui->paq_compLv->setEnabled(true);
        ui->paq_dic->setEnabled(false);
        ui->px_switch_a->setEnabled(false);
        ui->px_switch_b->setEnabled(false);
        ui->px_switch_e->setEnabled(false);
        ui->px_switch_s->setEnabled(false);

        ui->paq_compLv->setMinimum(0);
        ui->paq_compLv->setMaximum(15);
        ui->paq_compLv->setValue(1);
        break;
    case 1://px
        ui->paq_threads->setEnabled(false);
        ui->paq_compLv->setEnabled(true);
        ui->paq_dic->setEnabled(true);
        ui->px_switch_a->setEnabled(true);
        ui->px_switch_b->setEnabled(true);
        ui->px_switch_e->setEnabled(true);
        ui->px_switch_s->setEnabled(true);

        ui->paq_compLv->setMinimum(0);
        ui->paq_compLv->setMaximum(9);
        ui->paq_compLv->setValue(1);
        break;
    case 2://cmix
        ui->paq_threads->setEnabled(false);
        ui->paq_compLv->setEnabled(false);
        ui->paq_dic->setEnabled(true);
        ui->px_switch_a->setEnabled(false);
        ui->px_switch_b->setEnabled(false);
        ui->px_switch_e->setEnabled(false);
        ui->px_switch_s->setEnabled(false);

        ui->paq_compLv->setMinimum(999);
        ui->paq_compLv->setMaximum(999);
        ui->paq_compLv->setValue(999);
        break;
    case 3://bcm
        ui->paq_threads->setEnabled(false);
        ui->paq_compLv->setEnabled(true);
        ui->paq_dic->setEnabled(false);
        ui->px_switch_a->setEnabled(false);
        ui->px_switch_b->setEnabled(false);
        ui->px_switch_e->setEnabled(false);
        ui->px_switch_s->setEnabled(false);

        ui->paq_compLv->setMinimum(1);
        ui->paq_compLv->setMaximum(2047);
        ui->paq_compLv->setValue(1);
        break;
    case 4://kanzi
        ui->paq_threads->setEnabled(true);
        ui->paq_compLv->setEnabled(true);
        ui->paq_dic->setEnabled(false);
        ui->px_switch_a->setEnabled(false);
        ui->px_switch_b->setEnabled(false);
        ui->px_switch_e->setEnabled(false);
        ui->px_switch_s->setEnabled(false);

        ui->paq_compLv->setMinimum(0);
        ui->paq_compLv->setMaximum(8);
        ui->paq_compLv->setValue(1);

        break;
    }
}
//壓縮設定

//解壓設定
void MainWindow::on_decomp_1click_clicked() //解壓縮至當前資料夾
{
    ui->statusBar->clearMessage(); //清除statusBar
    ui->paq_cmdOutput->clear(); //清除命令執行進度
    QString cmd;
    if(ui->lineEdit->text() == QStringLiteral("可直接拖曳檔案或資料夾至此")) {
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇欲解壓縮的檔案！"));
        msg->exec();
    }
    else if(isArchive_pxd2(inpath)){
        cmd = pxd_new + " -d \"" + inpath + "\"";
        runCmdForCompOrDecomp(cmd);
        //等待執行完成才顯示訊息
        while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("共花費"))) delay_1ms();
        ui->statusBar->showMessage(QStringLiteral("指令執行完畢！"));
    }
    else if(isArchive_PX(inpath)){
        cmd = px + " -d \"" + inpath + "\"";
        runCmdForCompOrDecomp(cmd);
        //等待執行完成才顯示訊息
        while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("Time"))) delay_1ms();
        ui->statusBar->showMessage(QStringLiteral("指令執行完畢！"));
    }
    else if(isArchive_cmix(inpath)){

    }
    else if(isArchive_dic_cmix(inpath)){

    }
    else if(isArchive_BCM(inpath)){

    }
    else {
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇正確的壓縮檔！"));
        msg->exec();
    }
}
void MainWindow::on_decomp_btn_clicked() //解壓縮至指定資料夾
{
    int tool = ui->decomp_tool->currentIndex();
    ui->statusBar->clearMessage(); //清除statusBar
    ui->paq_cmdOutput->clear(); //清除命令執行進度
    QString cmd;
    switch (tool) {
    case 0: //pxd
        cmd = pxd_new + " -d \"" + inpath + "\"";
        break;
    case 1: //px
        cmd = px + " -d \"" + inpath + "\"";
        break;
    case 2: //cmix
        cmd = cmix + " -d \"" + inpath + "\"";
        break;
    case 3: //bcm
        cmd = bcm + " -d \"" + inpath + "\"";
        break;
    case 4: //kanzi
        cmd = kanzi + " -d -i  \"" + inpath + "\"";
        break;
    }
    if(ui->lineEdit->text() == QStringLiteral("可直接拖曳檔案或資料夾至此")) {
        QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇欲解壓縮的檔案！"));
        msg->exec();
    }
    else if(ui->lineEdit_2->text() == QStringLiteral("選擇輸出位置")) {
        /*
        if(!isArchive_PAQ(inpath)){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇正確的壓縮檔！"));
            msg->exec();
        }
        else {
            QMessageBox *msg = new QMessageBox;
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle(QStringLiteral("訊息"));
            msg->setText(QStringLiteral("未選擇輸出位置，是否輸出到當前目錄？"));
            QPushButton *ok = msg->addButton(QStringLiteral("是"),QMessageBox::ActionRole);
            QPushButton *no = msg->addButton(QStringLiteral("否"),QMessageBox::ActionRole);
            msg->exec();
            if(msg->clickedButton() == ok){
                runCmdForCompOrDecomp(cmd);
                //等待執行完成才顯示訊息
                while(!ui->rar_cmdOutput->toPlainText().contains(QStringLiteral("完成"))) delay_1ms();
                ui->statusBar->showMessage(QStringLiteral("指令執行完畢！"));
            }
            else if(msg->clickedButton() == no){}
        }
        */
    }
    else {
        /*
        if(!isArchive_PAQ(inpath)){
            QMessageBox *msg = new QMessageBox(QMessageBox::Warning,QStringLiteral("錯誤"),QStringLiteral("請選擇正確的壓縮檔！"));
            msg->exec();
        }
        else {
            cmd += " \"" + outpath + "\"";
            runCmdForCompOrDecomp(cmd);
            //等待執行完成才顯示訊息
            while(!ui->paq_cmdOutput->toPlainText().contains(QStringLiteral("共花費"))) delay_1ms();
            ui->statusBar->showMessage(QStringLiteral("指令執行完畢！"));
        }
        */
    }
}
void MainWindow::on_other_viewbtn_clicked() //查看壓縮檔內容
{
    ui->paq_viewFileList->clear();
    //QString line;
    if(isArchive_pxd2(inpath)) runCmdForCompOrDecomp(pxd_new + " -l \"" + inpath + "\"");
    else if(isArchive_PX(inpath)) runCmdForCompOrDecomp(px + " -l \"" + inpath + "\"");
    else ui->paq_viewFileList->setPlainText(QStringLiteral("必須為支援的壓縮檔格式且檔案標頭符合才能查看"));
}
//解壓設定


//------------------------------其他工具---------------------------//













