/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *version;
    QAction *checkUpdate;
    QAction *ImportProfile;
    QAction *ExportProfile;
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tab_winrar;
    QWidget *tab_4;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QRadioButton *rar_rb;
    QRadioButton *rar5_rb;
    QLabel *label_2;
    QComboBox *rar_complv;
    QLabel *label_3;
    QComboBox *rar_dictsize;
    QGroupBox *groupBox_2;
    QRadioButton *rar_Encryption1;
    QRadioButton *rar_Encryption2;
    QPushButton *rar_setpwd_btn;
    QGroupBox *groupBox_3;
    QComboBox *rar_splitunit;
    QLabel *label_4;
    QLabel *label_6;
    QSpinBox *rar_splitnum;
    QSpinBox *rar_splitsize;
    QGroupBox *groupBox_4;
    QCheckBox *rar_other_df;
    QCheckBox *rar_other_t;
    QCheckBox *rar_other_k;
    QCheckBox *rar_other_s;
    QCheckBox *rar_other_dw;
    QCheckBox *rar_other_ed;
    QCheckBox *rar_other_qo_2;
    QCheckBox *rar_other_qo;
    QCheckBox *rar_other_ms;
    QCheckBox *rar_other_vp;
    QComboBox *rar_other_ioff;
    QGroupBox *groupBox_5;
    QLabel *label_7;
    QSpinBox *rar_other_ri;
    QLabel *label_8;
    QComboBox *rar_other_mt;
    QCheckBox *rar_other_oc;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_11;
    QFrame *line_13;
    QWidget *tab_5;
    QPushButton *unrar_1click;
    QGroupBox *groupBox_10;
    QComboBox *unrar_o;
    QCheckBox *unrar_kb;
    QCheckBox *unrar_oni;
    QCheckBox *unrar_or;
    QCheckBox *unrar_ad;
    QCheckBox *unrar_noComm;
    QCheckBox *unrar_ep;
    QPushButton *unrar_btn;
    QGroupBox *groupBox_11;
    QTextEdit *rar_viewFileList;
    QPushButton *unrar_viewbtn;
    QFrame *line_14;
    QFrame *line_15;
    QWidget *tab_8;
    QGroupBox *groupBox_7;
    QPushButton *rar_comm_outpath_btn;
    QLabel *label_9;
    QRadioButton *rar_scfc;
    QRadioButton *rar_scuc;
    QRadioButton *rar_scac;
    QRadioButton *rar_scoc;
    QGroupBox *groupBox_8;
    QTextEdit *commenttext;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_9;
    QTextEdit *commenttext_2;
    QPushButton *pushButton_9;
    QFrame *line_16;
    QFrame *line_17;
    QWidget *tab_19;
    QTextEdit *rar_cmdOutput;
    QWidget *tab_2;
    QTabWidget *tab_7z;
    QWidget *tab_6;
    QWidget *tab_7;
    QGroupBox *groupBox_12;
    QTextEdit *sz_viewFileList;
    QPushButton *sz_viewbtn;
    QWidget *tab_18;
    QTextEdit *sz_cmdOutput;
    QWidget *tab_3;
    QTabWidget *tab_upx;
    QWidget *tab_14;
    QWidget *tab_15;
    QWidget *tab_11;
    QTabWidget *tab_paq;
    QWidget *tab_16;
    QPushButton *paq_compRunCmd;
    QFrame *line_4;
    QGroupBox *groupBox_13;
    QComboBox *others_tool;
    QLabel *label_32;
    QSpinBox *paq_compLv;
    QLabel *label_26;
    QGroupBox *groupBox_15;
    QComboBox *paq_threads;
    QLabel *label_31;
    QComboBox *paq_dic;
    QLabel *label_33;
    QCheckBox *px_switch_b;
    QCheckBox *px_switch_s;
    QCheckBox *px_switch_a;
    QCheckBox *px_switch_e;
    QWidget *tab_17;
    QPushButton *decomp_1click;
    QPushButton *decomp_btn;
    QPushButton *other_viewbtn;
    QGroupBox *groupBox_19;
    QTextEdit *paq_viewFileList;
    QGroupBox *groupBox_14;
    QComboBox *decomp_tool;
    QFrame *line_18;
    QWidget *tab_20;
    QTextEdit *paq_cmdOutput;
    QFrame *line;
    QCheckBox *no_TipMsg;
    QCheckBox *no_WarningMsg;
    QLabel *sysFreeRAM;
    QLabel *label_35;
    QMenuBar *menuBar;
    QMenu *about;
    QMenu *profile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(749, 733);
        MainWindow->setMinimumSize(QSize(749, 733));
        MainWindow->setMaximumSize(QSize(749, 733));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/compress.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(0.970000000000000);
        MainWindow->setIconSize(QSize(32, 32));
        MainWindow->setTabShape(QTabWidget::Rounded);
        version = new QAction(MainWindow);
        version->setObjectName(QString::fromUtf8("version"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/version.png"), QSize(), QIcon::Normal, QIcon::Off);
        version->setIcon(icon1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        version->setFont(font1);
        version->setMenuRole(QAction::AboutRole);
        checkUpdate = new QAction(MainWindow);
        checkUpdate->setObjectName(QString::fromUtf8("checkUpdate"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        checkUpdate->setIcon(icon2);
        checkUpdate->setFont(font1);
        ImportProfile = new QAction(MainWindow);
        ImportProfile->setObjectName(QString::fromUtf8("ImportProfile"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/import.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImportProfile->setIcon(icon3);
        ImportProfile->setFont(font1);
        ExportProfile = new QAction(MainWindow);
        ExportProfile->setObjectName(QString::fromUtf8("ExportProfile"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/export.png"), QSize(), QIcon::Normal, QIcon::Off);
        ExportProfile->setIcon(icon4);
        ExportProfile->setFont(font1);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setAcceptDrops(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 100, 121, 31));
        QPalette palette;
        QBrush brush(QColor(0, 0, 127, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush2(QColor(0, 0, 0, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        QBrush brush4(QColor(120, 120, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        QBrush brush5(QColor(0, 0, 0, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush5);
#endif
        label->setPalette(palette);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAcceptDrops(false);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setGeometry(QRect(150, 50, 591, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font3.setPointSize(13);
        font3.setBold(true);
        font3.setWeight(75);
        lineEdit_2->setFont(font3);
        lineEdit_2->setMaxLength(32767);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 131, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        pushButton->setFont(font4);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/open-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(24, 24));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(150, 10, 591, 31));
        lineEdit->setFont(font3);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setDragEnabled(true);
        lineEdit->setReadOnly(true);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 50, 131, 31));
        pushButton_4->setFont(font4);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/save-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon6);
        pushButton_4->setIconSize(QSize(24, 24));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 140, 731, 521));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setItalic(false);
        font5.setUnderline(false);
        font5.setWeight(75);
        font5.setKerning(false);
        tabWidget->setFont(font5);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab_winrar = new QTabWidget(tab);
        tab_winrar->setObjectName(QString::fromUtf8("tab_winrar"));
        tab_winrar->setGeometry(QRect(-2, -2, 731, 491));
        QFont font6;
        font6.setPointSize(14);
        tab_winrar->setFont(font6);
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 384, 704, 61));
        QFont font7;
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        pushButton_2->setFont(font7);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/comp.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon7);
        pushButton_2->setIconSize(QSize(48, 48));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 201, 61));
        QFont font8;
        font8.setPointSize(14);
        font8.setBold(true);
        font8.setWeight(75);
        groupBox->setFont(font8);
        rar_rb = new QRadioButton(groupBox);
        rar_rb->setObjectName(QString::fromUtf8("rar_rb"));
        rar_rb->setGeometry(QRect(10, 35, 91, 19));
        QFont font9;
        font9.setPointSize(14);
        font9.setBold(false);
        font9.setWeight(50);
        rar_rb->setFont(font9);
        rar5_rb = new QRadioButton(groupBox);
        rar5_rb->setObjectName(QString::fromUtf8("rar5_rb"));
        rar5_rb->setGeometry(QRect(120, 35, 71, 19));
        rar5_rb->setFont(font9);
        rar5_rb->setChecked(true);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 101, 21));
        label_2->setFont(font8);
        rar_complv = new QComboBox(tab_4);
        rar_complv->addItem(QString());
        rar_complv->addItem(QString());
        rar_complv->addItem(QString());
        rar_complv->addItem(QString());
        rar_complv->addItem(QString());
        rar_complv->addItem(QString());
        rar_complv->setObjectName(QString::fromUtf8("rar_complv"));
        rar_complv->setGeometry(QRect(10, 114, 201, 22));
        QFont font10;
        font10.setPointSize(13);
        font10.setBold(false);
        font10.setWeight(50);
        rar_complv->setFont(font10);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 155, 101, 21));
        label_3->setFont(font8);
        rar_dictsize = new QComboBox(tab_4);
        rar_dictsize->setObjectName(QString::fromUtf8("rar_dictsize"));
        rar_dictsize->setGeometry(QRect(10, 180, 201, 22));
        rar_dictsize->setFont(font9);
        rar_dictsize->setMaxVisibleItems(14);
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(490, 190, 221, 181));
        groupBox_2->setFont(font8);
        rar_Encryption1 = new QRadioButton(groupBox_2);
        rar_Encryption1->setObjectName(QString::fromUtf8("rar_Encryption1"));
        rar_Encryption1->setGeometry(QRect(10, 39, 101, 19));
        rar_Encryption1->setFont(font10);
        rar_Encryption2 = new QRadioButton(groupBox_2);
        rar_Encryption2->setObjectName(QString::fromUtf8("rar_Encryption2"));
        rar_Encryption2->setGeometry(QRect(110, 39, 101, 19));
        rar_Encryption2->setFont(font10);
        rar_setpwd_btn = new QPushButton(groupBox_2);
        rar_setpwd_btn->setObjectName(QString::fromUtf8("rar_setpwd_btn"));
        rar_setpwd_btn->setGeometry(QRect(10, 70, 201, 103));
        rar_setpwd_btn->setFont(font8);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/password.png"), QSize(), QIcon::Normal, QIcon::Off);
        rar_setpwd_btn->setIcon(icon8);
        rar_setpwd_btn->setIconSize(QSize(70, 70));
        groupBox_3 = new QGroupBox(tab_4);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 220, 201, 151));
        groupBox_3->setFont(font8);
        rar_splitunit = new QComboBox(groupBox_3);
        rar_splitunit->addItem(QString());
        rar_splitunit->addItem(QString());
        rar_splitunit->addItem(QString());
        rar_splitunit->addItem(QString());
        rar_splitunit->setObjectName(QString::fromUtf8("rar_splitunit"));
        rar_splitunit->setGeometry(QRect(138, 60, 53, 22));
        rar_splitunit->setFont(font10);
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 35, 111, 21));
        QFont font11;
        font11.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font11.setPointSize(14);
        font11.setBold(false);
        font11.setWeight(50);
        label_4->setFont(font11);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 95, 211, 21));
        label_6->setFont(font9);
        rar_splitnum = new QSpinBox(groupBox_3);
        rar_splitnum->setObjectName(QString::fromUtf8("rar_splitnum"));
        rar_splitnum->setGeometry(QRect(10, 120, 181, 22));
        rar_splitnum->setFont(font10);
        rar_splitnum->setLayoutDirection(Qt::LeftToRight);
        rar_splitnum->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rar_splitnum->setMaximum(9999);
        rar_splitnum->setStepType(QAbstractSpinBox::DefaultStepType);
        rar_splitnum->setDisplayIntegerBase(10);
        rar_splitsize = new QSpinBox(groupBox_3);
        rar_splitsize->setObjectName(QString::fromUtf8("rar_splitsize"));
        rar_splitsize->setGeometry(QRect(10, 60, 128, 22));
        rar_splitsize->setFont(font10);
        rar_splitsize->setLayoutDirection(Qt::RightToLeft);
        rar_splitsize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rar_splitsize->setMaximum(2147483647);
        rar_splitsize->setDisplayIntegerBase(10);
        groupBox_4 = new QGroupBox(tab_4);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(240, 10, 221, 361));
        groupBox_4->setFont(font8);
        rar_other_df = new QCheckBox(groupBox_4);
        rar_other_df->setObjectName(QString::fromUtf8("rar_other_df"));
        rar_other_df->setGeometry(QRect(10, 35, 201, 19));
        rar_other_df->setFont(font10);
        rar_other_t = new QCheckBox(groupBox_4);
        rar_other_t->setObjectName(QString::fromUtf8("rar_other_t"));
        rar_other_t->setGeometry(QRect(10, 95, 201, 19));
        rar_other_t->setFont(font10);
        rar_other_k = new QCheckBox(groupBox_4);
        rar_other_k->setObjectName(QString::fromUtf8("rar_other_k"));
        rar_other_k->setGeometry(QRect(10, 155, 201, 19));
        rar_other_k->setFont(font10);
        rar_other_s = new QCheckBox(groupBox_4);
        rar_other_s->setObjectName(QString::fromUtf8("rar_other_s"));
        rar_other_s->setGeometry(QRect(10, 125, 201, 19));
        rar_other_s->setFont(font10);
        rar_other_dw = new QCheckBox(groupBox_4);
        rar_other_dw->setObjectName(QString::fromUtf8("rar_other_dw"));
        rar_other_dw->setGeometry(QRect(10, 65, 201, 19));
        rar_other_dw->setFont(font10);
        rar_other_ed = new QCheckBox(groupBox_4);
        rar_other_ed->setObjectName(QString::fromUtf8("rar_other_ed"));
        rar_other_ed->setGeometry(QRect(10, 185, 201, 19));
        rar_other_ed->setFont(font10);
        rar_other_qo_2 = new QCheckBox(groupBox_4);
        rar_other_qo_2->setObjectName(QString::fromUtf8("rar_other_qo_2"));
        rar_other_qo_2->setGeometry(QRect(10, 305, 201, 19));
        rar_other_qo_2->setFont(font10);
        rar_other_qo = new QCheckBox(groupBox_4);
        rar_other_qo->setObjectName(QString::fromUtf8("rar_other_qo"));
        rar_other_qo->setGeometry(QRect(10, 275, 201, 19));
        rar_other_qo->setFont(font10);
        rar_other_ms = new QCheckBox(groupBox_4);
        rar_other_ms->setObjectName(QString::fromUtf8("rar_other_ms"));
        rar_other_ms->setGeometry(QRect(10, 215, 201, 19));
        rar_other_ms->setFont(font10);
        rar_other_vp = new QCheckBox(groupBox_4);
        rar_other_vp->setObjectName(QString::fromUtf8("rar_other_vp"));
        rar_other_vp->setGeometry(QRect(10, 245, 201, 19));
        rar_other_vp->setFont(font10);
        rar_other_ioff = new QComboBox(groupBox_4);
        rar_other_ioff->addItem(QString());
        rar_other_ioff->addItem(QString());
        rar_other_ioff->addItem(QString());
        rar_other_ioff->addItem(QString());
        rar_other_ioff->setObjectName(QString::fromUtf8("rar_other_ioff"));
        rar_other_ioff->setGeometry(QRect(10, 330, 201, 22));
        QFont font12;
        font12.setPointSize(12);
        font12.setBold(false);
        font12.setWeight(50);
        rar_other_ioff->setFont(font12);
        rar_other_ioff->setMaxCount(33);
        groupBox_5 = new QGroupBox(tab_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(490, 10, 221, 161));
        groupBox_5->setFont(font8);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 70, 191, 16));
        label_7->setFont(font10);
        rar_other_ri = new QSpinBox(groupBox_5);
        rar_other_ri->setObjectName(QString::fromUtf8("rar_other_ri"));
        rar_other_ri->setGeometry(QRect(10, 90, 201, 22));
        rar_other_ri->setFont(font10);
        rar_other_ri->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        rar_other_ri->setMaximum(15);
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 126, 191, 21));
        label_8->setFont(font10);
        rar_other_mt = new QComboBox(groupBox_5);
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->addItem(QString());
        rar_other_mt->setObjectName(QString::fromUtf8("rar_other_mt"));
        rar_other_mt->setGeometry(QRect(70, 126, 141, 22));
        rar_other_mt->setFont(font12);
        rar_other_mt->setMaxCount(33);
        rar_other_oc = new QCheckBox(groupBox_5);
        rar_other_oc->setObjectName(QString::fromUtf8("rar_other_oc"));
        rar_other_oc->setGeometry(QRect(10, 35, 201, 19));
        rar_other_oc->setFont(font10);
        line_6 = new QFrame(tab_4);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(-3, 70, 229, 20));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(tab_4);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(218, 0, 16, 381));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(tab_4);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(-3, 139, 229, 20));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(tab_4);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(-3, 202, 229, 20));
        QFont font13;
        font13.setPointSize(13);
        line_9->setFont(font13);
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(tab_4);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(-3, 370, 961, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        line_11 = new QFrame(tab_4);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(466, 179, 20, 201));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(tab_4);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(476, 170, 253, 20));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);
        tab_winrar->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        unrar_1click = new QPushButton(tab_5);
        unrar_1click->setObjectName(QString::fromUtf8("unrar_1click"));
        unrar_1click->setGeometry(QRect(10, 310, 241, 61));
        QFont font14;
        font14.setPointSize(16);
        font14.setBold(false);
        font14.setWeight(50);
        unrar_1click->setFont(font14);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/decomp.png"), QSize(), QIcon::Normal, QIcon::Off);
        unrar_1click->setIcon(icon9);
        unrar_1click->setIconSize(QSize(36, 36));
        groupBox_10 = new QGroupBox(tab_5);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 10, 241, 271));
        groupBox_10->setFont(font8);
        unrar_o = new QComboBox(groupBox_10);
        unrar_o->addItem(QString());
        unrar_o->addItem(QString());
        unrar_o->setObjectName(QString::fromUtf8("unrar_o"));
        unrar_o->setGeometry(QRect(10, 40, 221, 31));
        unrar_o->setFont(font10);
        unrar_kb = new QCheckBox(groupBox_10);
        unrar_kb->setObjectName(QString::fromUtf8("unrar_kb"));
        unrar_kb->setGeometry(QRect(10, 86, 201, 19));
        unrar_kb->setFont(font10);
        unrar_oni = new QCheckBox(groupBox_10);
        unrar_oni->setObjectName(QString::fromUtf8("unrar_oni"));
        unrar_oni->setGeometry(QRect(10, 116, 211, 19));
        unrar_oni->setFont(font10);
        unrar_or = new QCheckBox(groupBox_10);
        unrar_or->setObjectName(QString::fromUtf8("unrar_or"));
        unrar_or->setGeometry(QRect(10, 146, 201, 19));
        unrar_or->setFont(font10);
        unrar_ad = new QCheckBox(groupBox_10);
        unrar_ad->setObjectName(QString::fromUtf8("unrar_ad"));
        unrar_ad->setGeometry(QRect(10, 176, 221, 19));
        unrar_ad->setFont(font10);
        unrar_noComm = new QCheckBox(groupBox_10);
        unrar_noComm->setObjectName(QString::fromUtf8("unrar_noComm"));
        unrar_noComm->setGeometry(QRect(10, 206, 201, 19));
        unrar_noComm->setFont(font10);
        unrar_ep = new QCheckBox(groupBox_10);
        unrar_ep->setObjectName(QString::fromUtf8("unrar_ep"));
        unrar_ep->setGeometry(QRect(10, 235, 201, 19));
        unrar_ep->setFont(font10);
        unrar_btn = new QPushButton(tab_5);
        unrar_btn->setObjectName(QString::fromUtf8("unrar_btn"));
        unrar_btn->setGeometry(QRect(10, 377, 154, 61));
        QFont font15;
        font15.setPointSize(16);
        font15.setBold(true);
        font15.setWeight(75);
        unrar_btn->setFont(font15);
        unrar_btn->setIcon(icon9);
        unrar_btn->setIconSize(QSize(40, 40));
        groupBox_11 = new QGroupBox(tab_5);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(280, 10, 431, 436));
        groupBox_11->setFont(font8);
        rar_viewFileList = new QTextEdit(groupBox_11);
        rar_viewFileList->setObjectName(QString::fromUtf8("rar_viewFileList"));
        rar_viewFileList->setGeometry(QRect(0, 24, 431, 411));
        QFont font16;
        font16.setPointSize(10);
        font16.setBold(true);
        font16.setWeight(75);
        rar_viewFileList->setFont(font16);
        rar_viewFileList->setAcceptDrops(false);
        rar_viewFileList->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        rar_viewFileList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        rar_viewFileList->setUndoRedoEnabled(false);
        rar_viewFileList->setLineWrapMode(QTextEdit::NoWrap);
        rar_viewFileList->setReadOnly(true);
        unrar_viewbtn = new QPushButton(tab_5);
        unrar_viewbtn->setObjectName(QString::fromUtf8("unrar_viewbtn"));
        unrar_viewbtn->setGeometry(QRect(170, 377, 81, 61));
        unrar_viewbtn->setFont(font15);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        unrar_viewbtn->setIcon(icon10);
        unrar_viewbtn->setIconSize(QSize(40, 40));
        line_14 = new QFrame(tab_5);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(257, 0, 16, 461));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);
        line_15 = new QFrame(tab_5);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(0, 283, 265, 20));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);
        tab_winrar->addTab(tab_5, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        groupBox_7 = new QGroupBox(tab_8);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 704, 71));
        QFont font17;
        font17.setPointSize(14);
        font17.setBold(true);
        font17.setWeight(75);
        font17.setStyleStrategy(QFont::PreferAntialias);
        groupBox_7->setFont(font17);
        rar_comm_outpath_btn = new QPushButton(groupBox_7);
        rar_comm_outpath_btn->setObjectName(QString::fromUtf8("rar_comm_outpath_btn"));
        rar_comm_outpath_btn->setGeometry(QRect(540, 28, 154, 42));
        rar_comm_outpath_btn->setFont(font17);
        rar_comm_outpath_btn->setIcon(icon6);
        rar_comm_outpath_btn->setIconSize(QSize(32, 32));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 38, 121, 21));
        QFont font18;
        font18.setPointSize(14);
        font18.setBold(false);
        font18.setWeight(50);
        font18.setStyleStrategy(QFont::PreferAntialias);
        label_9->setFont(font18);
        rar_scfc = new QRadioButton(groupBox_7);
        rar_scfc->setObjectName(QString::fromUtf8("rar_scfc"));
        rar_scfc->setGeometry(QRect(220, 38, 141, 19));
        rar_scfc->setFont(font18);
        rar_scfc->setChecked(true);
        rar_scuc = new QRadioButton(groupBox_7);
        rar_scuc->setObjectName(QString::fromUtf8("rar_scuc"));
        rar_scuc->setGeometry(QRect(360, 38, 101, 19));
        rar_scuc->setFont(font18);
        rar_scac = new QRadioButton(groupBox_7);
        rar_scac->setObjectName(QString::fromUtf8("rar_scac"));
        rar_scac->setGeometry(QRect(460, 38, 70, 19));
        rar_scac->setFont(font18);
        rar_scoc = new QRadioButton(groupBox_7);
        rar_scoc->setObjectName(QString::fromUtf8("rar_scoc"));
        rar_scoc->setGeometry(QRect(130, 38, 81, 19));
        rar_scoc->setFont(font18);
        groupBox_8 = new QGroupBox(tab_8);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 110, 332, 341));
        groupBox_8->setFont(font8);
        commenttext = new QTextEdit(groupBox_8);
        commenttext->setObjectName(QString::fromUtf8("commenttext"));
        commenttext->setGeometry(QRect(1, 28, 331, 253));
        commenttext->setFont(font12);
        commenttext->setAcceptDrops(false);
        commenttext->setLineWrapMode(QTextEdit::NoWrap);
        commenttext->setAcceptRichText(false);
        pushButton_6 = new QPushButton(groupBox_8);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(-9, 280, 351, 61));
        pushButton_6->setFont(font8);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/write.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon11);
        pushButton_6->setIconSize(QSize(38, 38));
        groupBox_9 = new QGroupBox(tab_8);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(360, 110, 355, 341));
        groupBox_9->setFont(font8);
        commenttext_2 = new QTextEdit(groupBox_9);
        commenttext_2->setObjectName(QString::fromUtf8("commenttext_2"));
        commenttext_2->setGeometry(QRect(1, 28, 353, 253));
        commenttext_2->setFont(font9);
        commenttext_2->setAcceptDrops(false);
        commenttext_2->setLineWrapMode(QTextEdit::NoWrap);
        commenttext_2->setReadOnly(true);
        commenttext_2->setAcceptRichText(false);
        pushButton_9 = new QPushButton(groupBox_9);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(-6, 280, 371, 61));
        pushButton_9->setFont(font8);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/read.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_9->setIcon(icon12);
        pushButton_9->setIconSize(QSize(38, 38));
        line_16 = new QFrame(tab_8);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(0, 93, 951, 16));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);
        line_17 = new QFrame(tab_8);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(342, 100, 20, 361));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);
        tab_winrar->addTab(tab_8, QString());
        tab_19 = new QWidget();
        tab_19->setObjectName(QString::fromUtf8("tab_19"));
        rar_cmdOutput = new QTextEdit(tab_19);
        rar_cmdOutput->setObjectName(QString::fromUtf8("rar_cmdOutput"));
        rar_cmdOutput->setGeometry(QRect(10, 10, 705, 431));
        rar_cmdOutput->setAcceptDrops(false);
        rar_cmdOutput->setLineWrapMode(QTextEdit::NoWrap);
        rar_cmdOutput->setReadOnly(true);
        tab_winrar->addTab(tab_19, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_7z = new QTabWidget(tab_2);
        tab_7z->setObjectName(QString::fromUtf8("tab_7z"));
        tab_7z->setGeometry(QRect(-2, -2, 956, 491));
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tab_7z->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        groupBox_12 = new QGroupBox(tab_7);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(280, 10, 431, 436));
        groupBox_12->setFont(font8);
        sz_viewFileList = new QTextEdit(groupBox_12);
        sz_viewFileList->setObjectName(QString::fromUtf8("sz_viewFileList"));
        sz_viewFileList->setGeometry(QRect(0, 24, 431, 411));
        QFont font19;
        font19.setPointSize(9);
        font19.setBold(true);
        font19.setWeight(75);
        sz_viewFileList->setFont(font19);
        sz_viewFileList->setAcceptDrops(false);
        sz_viewFileList->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        sz_viewFileList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        sz_viewFileList->setLineWrapMode(QTextEdit::NoWrap);
        sz_viewFileList->setReadOnly(true);
        sz_viewbtn = new QPushButton(tab_7);
        sz_viewbtn->setObjectName(QString::fromUtf8("sz_viewbtn"));
        sz_viewbtn->setGeometry(QRect(170, 377, 81, 61));
        QFont font20;
        font20.setPointSize(11);
        font20.setBold(true);
        font20.setWeight(75);
        sz_viewbtn->setFont(font20);
        sz_viewbtn->setIcon(icon10);
        sz_viewbtn->setIconSize(QSize(40, 40));
        tab_7z->addTab(tab_7, QString());
        tab_18 = new QWidget();
        tab_18->setObjectName(QString::fromUtf8("tab_18"));
        sz_cmdOutput = new QTextEdit(tab_18);
        sz_cmdOutput->setObjectName(QString::fromUtf8("sz_cmdOutput"));
        sz_cmdOutput->setGeometry(QRect(10, 10, 705, 431));
        sz_cmdOutput->setAcceptDrops(false);
        sz_cmdOutput->setLineWrapMode(QTextEdit::NoWrap);
        sz_cmdOutput->setReadOnly(true);
        tab_7z->addTab(tab_18, QString());
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_upx = new QTabWidget(tab_3);
        tab_upx->setObjectName(QString::fromUtf8("tab_upx"));
        tab_upx->setGeometry(QRect(-2, -2, 956, 491));
        tab_14 = new QWidget();
        tab_14->setObjectName(QString::fromUtf8("tab_14"));
        tab_upx->addTab(tab_14, QString());
        tab_15 = new QWidget();
        tab_15->setObjectName(QString::fromUtf8("tab_15"));
        tab_upx->addTab(tab_15, QString());
        tabWidget->addTab(tab_3, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QString::fromUtf8("tab_11"));
        tab_paq = new QTabWidget(tab_11);
        tab_paq->setObjectName(QString::fromUtf8("tab_paq"));
        tab_paq->setGeometry(QRect(-2, -2, 956, 491));
        tab_16 = new QWidget();
        tab_16->setObjectName(QString::fromUtf8("tab_16"));
        paq_compRunCmd = new QPushButton(tab_16);
        paq_compRunCmd->setObjectName(QString::fromUtf8("paq_compRunCmd"));
        paq_compRunCmd->setGeometry(QRect(10, 384, 704, 61));
        paq_compRunCmd->setFont(font7);
        paq_compRunCmd->setIcon(icon7);
        paq_compRunCmd->setIconSize(QSize(48, 48));
        line_4 = new QFrame(tab_16);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(0, 370, 961, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        groupBox_13 = new QGroupBox(tab_16);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(10, 10, 641, 81));
        groupBox_13->setFont(font8);
        others_tool = new QComboBox(groupBox_13);
        others_tool->addItem(QString());
        others_tool->addItem(QString());
        others_tool->addItem(QString());
        others_tool->addItem(QString());
        others_tool->addItem(QString());
        others_tool->setObjectName(QString::fromUtf8("others_tool"));
        others_tool->setGeometry(QRect(110, 40, 111, 31));
        others_tool->setFont(font9);
        label_32 = new QLabel(groupBox_13);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(10, 45, 101, 21));
        label_32->setFont(font9);
        paq_compLv = new QSpinBox(groupBox_13);
        paq_compLv->setObjectName(QString::fromUtf8("paq_compLv"));
        paq_compLv->setGeometry(QRect(350, 40, 61, 31));
        paq_compLv->setFont(font9);
        paq_compLv->setMaximum(15);
        paq_compLv->setValue(1);
        label_26 = new QLabel(groupBox_13);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(250, 44, 101, 21));
        label_26->setFont(font9);
        groupBox_15 = new QGroupBox(tab_16);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(10, 110, 641, 251));
        groupBox_15->setFont(font6);
        paq_threads = new QComboBox(groupBox_15);
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->addItem(QString());
        paq_threads->setObjectName(QString::fromUtf8("paq_threads"));
        paq_threads->setGeometry(QRect(90, 40, 61, 31));
        paq_threads->setFont(font9);
        label_31 = new QLabel(groupBox_15);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(10, 44, 101, 21));
        label_31->setFont(font9);
        paq_dic = new QComboBox(groupBox_15);
        paq_dic->addItem(QString());
        paq_dic->addItem(QString());
        paq_dic->setObjectName(QString::fromUtf8("paq_dic"));
        paq_dic->setEnabled(false);
        paq_dic->setGeometry(QRect(260, 40, 121, 31));
        paq_dic->setFont(font9);
        label_33 = new QLabel(groupBox_15);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(200, 45, 61, 21));
        label_33->setFont(font9);
        px_switch_b = new QCheckBox(groupBox_15);
        px_switch_b->setObjectName(QString::fromUtf8("px_switch_b"));
        px_switch_b->setEnabled(false);
        px_switch_b->setGeometry(QRect(10, 130, 191, 21));
        px_switch_b->setFont(font9);
        px_switch_s = new QCheckBox(groupBox_15);
        px_switch_s->setObjectName(QString::fromUtf8("px_switch_s"));
        px_switch_s->setEnabled(false);
        px_switch_s->setGeometry(QRect(10, 210, 151, 21));
        px_switch_s->setFont(font9);
        px_switch_a = new QCheckBox(groupBox_15);
        px_switch_a->setObjectName(QString::fromUtf8("px_switch_a"));
        px_switch_a->setEnabled(false);
        px_switch_a->setGeometry(QRect(10, 90, 141, 21));
        px_switch_a->setFont(font9);
        px_switch_e = new QCheckBox(groupBox_15);
        px_switch_e->setObjectName(QString::fromUtf8("px_switch_e"));
        px_switch_e->setEnabled(false);
        px_switch_e->setGeometry(QRect(10, 170, 151, 21));
        px_switch_e->setFont(font9);
        tab_paq->addTab(tab_16, QString());
        tab_17 = new QWidget();
        tab_17->setObjectName(QString::fromUtf8("tab_17"));
        decomp_1click = new QPushButton(tab_17);
        decomp_1click->setObjectName(QString::fromUtf8("decomp_1click"));
        decomp_1click->setEnabled(false);
        decomp_1click->setGeometry(QRect(10, 130, 241, 91));
        decomp_1click->setFont(font15);
        decomp_1click->setIcon(icon9);
        decomp_1click->setIconSize(QSize(46, 46));
        decomp_btn = new QPushButton(tab_17);
        decomp_btn->setObjectName(QString::fromUtf8("decomp_btn"));
        decomp_btn->setEnabled(false);
        decomp_btn->setGeometry(QRect(10, 240, 241, 91));
        decomp_btn->setFont(font15);
        decomp_btn->setIcon(icon9);
        decomp_btn->setIconSize(QSize(46, 46));
        other_viewbtn = new QPushButton(tab_17);
        other_viewbtn->setObjectName(QString::fromUtf8("other_viewbtn"));
        other_viewbtn->setGeometry(QRect(10, 350, 241, 91));
        other_viewbtn->setFont(font15);
        other_viewbtn->setIcon(icon10);
        other_viewbtn->setIconSize(QSize(46, 46));
        groupBox_19 = new QGroupBox(tab_17);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(280, 10, 431, 436));
        groupBox_19->setFont(font8);
        paq_viewFileList = new QTextEdit(groupBox_19);
        paq_viewFileList->setObjectName(QString::fromUtf8("paq_viewFileList"));
        paq_viewFileList->setGeometry(QRect(0, 24, 431, 411));
        paq_viewFileList->setFont(font16);
        paq_viewFileList->setAcceptDrops(false);
        paq_viewFileList->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        paq_viewFileList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        paq_viewFileList->setLineWrapMode(QTextEdit::NoWrap);
        paq_viewFileList->setReadOnly(true);
        groupBox_14 = new QGroupBox(tab_17);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(10, 10, 241, 91));
        decomp_tool = new QComboBox(groupBox_14);
        decomp_tool->addItem(QString());
        decomp_tool->addItem(QString());
        decomp_tool->addItem(QString());
        decomp_tool->addItem(QString());
        decomp_tool->addItem(QString());
        decomp_tool->setObjectName(QString::fromUtf8("decomp_tool"));
        decomp_tool->setEnabled(false);
        decomp_tool->setGeometry(QRect(10, 40, 221, 31));
        QFont font21;
        font21.setPointSize(15);
        decomp_tool->setFont(font21);
        line_18 = new QFrame(tab_17);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setGeometry(QRect(257, 0, 16, 461));
        line_18->setFrameShape(QFrame::VLine);
        line_18->setFrameShadow(QFrame::Sunken);
        tab_paq->addTab(tab_17, QString());
        tab_20 = new QWidget();
        tab_20->setObjectName(QString::fromUtf8("tab_20"));
        paq_cmdOutput = new QTextEdit(tab_20);
        paq_cmdOutput->setObjectName(QString::fromUtf8("paq_cmdOutput"));
        paq_cmdOutput->setGeometry(QRect(10, 10, 705, 431));
        paq_cmdOutput->setAcceptDrops(false);
        paq_cmdOutput->setLineWrapMode(QTextEdit::NoWrap);
        paq_cmdOutput->setReadOnly(true);
        tab_paq->addTab(tab_20, QString());
        tabWidget->addTab(tab_11, QString());
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 87, 751, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        no_TipMsg = new QCheckBox(centralWidget);
        no_TipMsg->setObjectName(QString::fromUtf8("no_TipMsg"));
        no_TipMsg->setGeometry(QRect(550, 110, 181, 19));
        no_TipMsg->setFont(font3);
        no_WarningMsg = new QCheckBox(centralWidget);
        no_WarningMsg->setObjectName(QString::fromUtf8("no_WarningMsg"));
        no_WarningMsg->setGeometry(QRect(550, 140, 201, 19));
        no_WarningMsg->setFont(font3);
        sysFreeRAM = new QLabel(centralWidget);
        sysFreeRAM->setObjectName(QString::fromUtf8("sysFreeRAM"));
        sysFreeRAM->setGeometry(QRect(130, 100, 61, 31));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        sysFreeRAM->setPalette(palette1);
        QFont font22;
        font22.setPointSize(15);
        font22.setBold(true);
        font22.setUnderline(true);
        font22.setWeight(75);
        sysFreeRAM->setFont(font22);
        sysFreeRAM->setAlignment(Qt::AlignCenter);
        label_35 = new QLabel(centralWidget);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(190, 100, 47, 31));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        label_35->setPalette(palette2);
        label_35->setFont(font22);
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        lineEdit_2->raise();
        pushButton->raise();
        lineEdit->raise();
        pushButton_4->raise();
        tabWidget->raise();
        line->raise();
        no_WarningMsg->raise();
        no_TipMsg->raise();
        sysFreeRAM->raise();
        label_35->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 749, 21));
        about = new QMenu(menuBar);
        about->setObjectName(QString::fromUtf8("about"));
        about->setCursor(QCursor(Qt::ArrowCursor));
        about->setMouseTracking(true);
        profile = new QMenu(menuBar);
        profile->setObjectName(QString::fromUtf8("profile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(false);
        mainToolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QFont font23;
        font23.setPointSize(12);
        statusBar->setFont(font23);
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(profile->menuAction());
        menuBar->addAction(about->menuAction());
        about->addAction(version);
        about->addAction(checkUpdate);
        profile->addAction(ImportProfile);
        profile->addAction(ExportProfile);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tab_winrar->setCurrentIndex(0);
        rar_complv->setCurrentIndex(3);
        rar_dictsize->setCurrentIndex(-1);
        rar_splitunit->setCurrentIndex(2);
        rar_other_ioff->setCurrentIndex(0);
        rar_other_mt->setCurrentIndex(0);
        tab_7z->setCurrentIndex(1);
        tab_upx->setCurrentIndex(0);
        tab_paq->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QtCompressor", nullptr));
        version->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\350\263\207\350\250\212", nullptr));
#if QT_CONFIG(tooltip)
        version->setToolTip(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\350\263\207\350\250\212", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        version->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        checkUpdate->setText(QCoreApplication::translate("MainWindow", "\346\252\242\346\237\245\346\233\264\346\226\260", nullptr));
#if QT_CONFIG(shortcut)
        checkUpdate->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        ImportProfile->setText(QCoreApplication::translate("MainWindow", "\345\214\257\345\205\245", nullptr));
#if QT_CONFIG(shortcut)
        ImportProfile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        ExportProfile->setText(QCoreApplication::translate("MainWindow", "\345\214\257\345\207\272", nullptr));
#if QT_CONFIG(shortcut)
        ExportProfile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "\347\251\272\351\226\222\350\250\230\346\206\266\351\253\224\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit_2->setToolTip(QCoreApplication::translate("MainWindow", "output file path", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        lineEdit_2->setStatusTip(QCoreApplication::translate("MainWindow", "\351\201\270\346\223\207\350\274\270\345\207\272\344\275\215\347\275\256", nullptr));
#endif // QT_CONFIG(statustip)
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "\351\201\270\346\223\207\350\274\270\345\207\272\344\275\215\347\275\256", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\201\270\346\223\207\346\252\224\346\241\210", nullptr));
#if QT_CONFIG(tooltip)
        lineEdit->setToolTip(QCoreApplication::translate("MainWindow", "drop the file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        lineEdit->setStatusTip(QCoreApplication::translate("MainWindow", "\346\213\226\346\233\263\346\252\224\346\241\210\350\207\263\346\255\244\344\273\245\345\217\226\345\276\227\346\252\224\346\241\210\350\267\257\345\276\221", nullptr));
#endif // QT_CONFIG(statustip)
        lineEdit->setText(QCoreApplication::translate("MainWindow", "\345\217\257\347\233\264\346\216\245\346\213\226\346\233\263\346\252\224\346\241\210\346\210\226\350\263\207\346\226\231\345\244\276\350\207\263\346\255\244", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\350\274\270\345\207\272\344\275\215\347\275\256", nullptr));
#if QT_CONFIG(statustip)
        tabWidget->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(tooltip)
        pushButton_2->setToolTip(QCoreApplication::translate("MainWindow", "RUN!!", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        pushButton_2->setStatusTip(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\345\243\223\347\270\256\346\214\207\344\273\244 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+R)", nullptr));
#endif // QT_CONFIG(statustip)
        pushButton_2->setText(QString());
#if QT_CONFIG(shortcut)
        pushButton_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\346\240\274\345\274\217", nullptr));
        rar_rb->setText(QCoreApplication::translate("MainWindow", "RAR4.X", nullptr));
        rar5_rb->setText(QCoreApplication::translate("MainWindow", "RAR5", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\347\255\211\347\264\232", nullptr));
        rar_complv->setItemText(0, QCoreApplication::translate("MainWindow", "\345\203\205\346\211\223\345\214\205 (\344\270\215\345\243\223\347\270\256)", nullptr));
        rar_complv->setItemText(1, QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\346\234\200\345\277\253", nullptr));
        rar_complv->setItemText(2, QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\345\277\253", nullptr));
        rar_complv->setItemText(3, QCoreApplication::translate("MainWindow", "\344\270\200\350\210\254 (\351\240\220\350\250\255\345\200\274)", nullptr));
        rar_complv->setItemText(4, QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\344\275\263", nullptr));
        rar_complv->setItemText(5, QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\346\234\200\344\275\263 (\346\205\242)", nullptr));

#if QT_CONFIG(tooltip)
        rar_complv->setToolTip(QCoreApplication::translate("MainWindow", "\347\255\211\347\264\232\346\204\210\351\253\230\351\200\237\345\272\246\346\204\210\346\205\242", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\205\270\346\252\224\345\244\247\345\260\217", nullptr));
#if QT_CONFIG(tooltip)
        rar_dictsize->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\232\345\270\270\344\275\277\347\224\250\345\244\247\345\255\227\345\205\270\346\252\224\345\217\257\346\217\220\351\253\230\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206\346\226\271\345\274\217", nullptr));
#if QT_CONFIG(tooltip)
        rar_Encryption1->setToolTip(QCoreApplication::translate("MainWindow", "\347\234\213\347\232\204\345\210\260\345\220\203\344\270\215\345\210\260 ; )", nullptr));
#endif // QT_CONFIG(tooltip)
        rar_Encryption1->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206\346\252\224\346\241\210", nullptr));
#if QT_CONFIG(tooltip)
        rar_Encryption2->setToolTip(QCoreApplication::translate("MainWindow", "\344\274\221\346\203\263\345\201\267\347\234\213!!", nullptr));
#endif // QT_CONFIG(tooltip)
        rar_Encryption2->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206\346\252\224\345\220\215", nullptr));
#if QT_CONFIG(tooltip)
        rar_setpwd_btn->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_setpwd_btn->setStatusTip(QCoreApplication::translate("MainWindow", "\350\250\255\345\256\232\345\257\206\347\242\274 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+P)", nullptr));
#endif // QT_CONFIG(statustip)
        rar_setpwd_btn->setText(QString());
#if QT_CONFIG(shortcut)
        rar_setpwd_btn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\345\210\206\345\211\262\346\252\224 (0 = \344\270\215\345\225\237\347\224\250)", nullptr));
        rar_splitunit->setItemText(0, QCoreApplication::translate("MainWindow", "B", nullptr));
        rar_splitunit->setItemText(1, QCoreApplication::translate("MainWindow", "KB", nullptr));
        rar_splitunit->setItemText(2, QCoreApplication::translate("MainWindow", "MB", nullptr));
        rar_splitunit->setItemText(3, QCoreApplication::translate("MainWindow", "GB", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\346\214\207\345\256\232\345\244\247\345\260\217", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\346\214\207\345\256\232\345\210\206\345\211\262\346\225\270", nullptr));
#if QT_CONFIG(tooltip)
        rar_splitnum->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        rar_splitsize->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\350\213\245\346\254\262\350\274\270\345\205\245\347\232\204\346\225\270\345\255\227\350\266\205\351\201\216 <span style=\" font-weight:600;\">&quot;2147483647&quot; </span>\350\253\213\346\217\233\346\233\264\345\244\247\347\232\204\345\226\256\344\275\215\344\276\206\344\273\243\346\233\277</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\351\200\262\351\232\216\350\250\255\345\256\232", nullptr));
        rar_other_df->setText(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\345\256\214\345\260\207\345\216\237\346\252\224\346\241\210\345\210\252\351\231\244", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_t->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        rar_other_t->setText(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\345\256\214\346\270\254\350\251\246\345\243\223\347\270\256\346\252\224", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_k->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_other_k->setStatusTip(QCoreApplication::translate("MainWindow", "\345\211\265\345\273\272\345\243\223\347\270\256\346\252\224\345\276\214\345\260\207\344\270\215\345\217\257\345\206\215\345\260\215\345\205\266\350\256\212\346\233\264\344\273\273\344\275\225\345\217\203\346\225\270\346\210\226\346\252\224\346\241\210", nullptr));
#endif // QT_CONFIG(statustip)
        rar_other_k->setText(QCoreApplication::translate("MainWindow", "\351\216\226\345\256\232\345\243\223\347\270\256\346\252\224", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_s->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_other_s->setStatusTip(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\345\244\247\351\207\217\347\232\204\345\260\217\346\252\224\346\241\210\350\203\275\346\234\211\346\225\210\346\217\220\351\253\230\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(statustip)
        rar_other_s->setText(QCoreApplication::translate("MainWindow", "\347\265\220\345\257\246\345\243\223\347\270\256\346\252\224", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_dw->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        rar_other_dw->setText(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\345\256\214\345\260\207\345\216\237\346\252\224\346\241\210\346\212\271\351\231\244", nullptr));
        rar_other_ed->setText(QCoreApplication::translate("MainWindow", "\344\270\215\345\212\240\345\205\245\347\251\272\350\263\207\346\226\231\345\244\276", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_qo_2->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_other_qo_2->setStatusTip(QCoreApplication::translate("MainWindow", "\345\246\202\346\236\234\346\202\250\346\203\263\350\246\201\346\234\200\345\260\217\347\232\204\345\243\223\347\270\256\346\252\224\357\274\214\344\270\215\345\234\250\344\271\216\345\243\223\347\270\256\346\252\224\351\226\213\345\225\237\351\200\237\345\272\246\357\274\214\345\217\257\344\273\245\344\275\277\347\224\250\346\255\244\350\250\255\345\256\232\344\276\206\345\256\214\345\205\250\346\216\222\351\231\244\345\277\253\351\200\237\351\226\213\345\225\237\350\263\207\350\250\212\343\200\202", nullptr));
#endif // QT_CONFIG(statustip)
        rar_other_qo_2->setText(QCoreApplication::translate("MainWindow", "\345\256\214\345\205\250\346\216\222\351\231\244\345\277\253\351\200\237\351\226\213\345\225\237\350\263\207\350\250\212", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_qo->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_other_qo->setStatusTip(QCoreApplication::translate("MainWindow", "\345\246\202\346\236\234\346\202\250\345\270\214\346\234\233\347\215\262\345\276\227\346\234\200\345\277\253\351\200\237\351\226\213\345\225\237\345\243\223\347\270\256\346\252\224\347\232\204\351\200\237\345\272\246\357\274\214\344\270\215\345\234\250\344\271\216\345\244\247\345\260\217\357\274\214\346\202\250\345\217\257\344\273\245\344\275\277\347\224\250\346\255\244\350\250\255\345\256\232\344\276\206\345\204\262\345\255\230\346\211\200\346\234\211\346\252\224\346\241\210\347\232\204\346\252\224\351\240\255\343\200\202", nullptr));
#endif // QT_CONFIG(statustip)
        rar_other_qo->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\205\245\345\277\253\351\200\237\351\226\213\345\225\237\350\263\207\350\250\212", nullptr));
        rar_other_ms->setText(QCoreApplication::translate("MainWindow", "\347\225\245\351\201\216\345\267\262\345\243\223\347\270\256\347\232\204\346\252\224\346\241\210", nullptr));
#if QT_CONFIG(statustip)
        rar_other_vp->setStatusTip(QCoreApplication::translate("MainWindow", "\345\273\272\347\253\213\346\257\217\345\200\213\345\210\206\345\211\262\346\252\224\344\271\213\345\211\215\351\203\275\346\234\203\346\217\220\345\207\272\350\251\242\345\225\217\357\274\214\345\234\250\350\251\242\345\225\217\346\230\257\345\220\246\345\273\272\347\253\213\345\210\206\345\211\262\346\252\224\346\231\202\345\217\257\350\207\252\350\241\214\345\260\207\345\267\262\345\273\272\347\253\213\347\232\204\345\210\206\345\211\262\346\252\224\347\247\273\345\210\260\345\210\245\347\232\204\347\243\201\347\242\237\343\200\202", nullptr));
#endif // QT_CONFIG(statustip)
        rar_other_vp->setText(QCoreApplication::translate("MainWindow", "\346\257\217\346\254\241\345\210\206\345\211\262\346\252\224\346\241\210\344\271\213\345\211\215\346\232\253\345\201\234", nullptr));
        rar_other_ioff->setItemText(0, QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\256\214\347\225\242\344\270\215\345\213\225\344\275\234", nullptr));
        rar_other_ioff->setItemText(1, QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\256\214\347\225\242\351\227\234\351\226\211\351\233\273\350\205\246", nullptr));
        rar_other_ioff->setItemText(2, QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\256\214\347\225\242\344\274\221\347\234\240\351\233\273\350\205\246", nullptr));
        rar_other_ioff->setItemText(3, QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\256\214\347\225\242\347\235\241\347\234\240\351\233\273\350\205\246", nullptr));

#if QT_CONFIG(tooltip)
        rar_other_ioff->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\203\346\225\270\347\232\204\346\224\271\350\256\212\346\234\203\347\250\215\345\276\256\345\275\261\351\237\277\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_other_ioff->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\351\200\262\351\232\216\350\250\255\345\256\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\345\204\252\345\205\210\346\254\212 (0 = \351\240\220\350\250\255)", nullptr));
#if QT_CONFIG(tooltip)
        rar_other_ri->setToolTip(QCoreApplication::translate("MainWindow", "\346\225\270\345\255\227\350\266\212\345\244\247\357\274\214\345\204\252\345\205\210\346\254\212\346\204\210\351\253\230", nullptr));
#endif // QT_CONFIG(tooltip)
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\347\267\222:", nullptr));
        rar_other_mt->setItemText(0, QCoreApplication::translate("MainWindow", "\350\207\252\345\213\225\345\201\265\346\270\254 (\346\216\250\350\226\246)", nullptr));
        rar_other_mt->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        rar_other_mt->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        rar_other_mt->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        rar_other_mt->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        rar_other_mt->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        rar_other_mt->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        rar_other_mt->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        rar_other_mt->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        rar_other_mt->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        rar_other_mt->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));
        rar_other_mt->setItemText(11, QCoreApplication::translate("MainWindow", "11", nullptr));
        rar_other_mt->setItemText(12, QCoreApplication::translate("MainWindow", "12", nullptr));
        rar_other_mt->setItemText(13, QCoreApplication::translate("MainWindow", "13", nullptr));
        rar_other_mt->setItemText(14, QCoreApplication::translate("MainWindow", "14", nullptr));
        rar_other_mt->setItemText(15, QCoreApplication::translate("MainWindow", "15", nullptr));
        rar_other_mt->setItemText(16, QCoreApplication::translate("MainWindow", "16", nullptr));
        rar_other_mt->setItemText(17, QCoreApplication::translate("MainWindow", "17", nullptr));
        rar_other_mt->setItemText(18, QCoreApplication::translate("MainWindow", "18", nullptr));
        rar_other_mt->setItemText(19, QCoreApplication::translate("MainWindow", "19", nullptr));
        rar_other_mt->setItemText(20, QCoreApplication::translate("MainWindow", "20", nullptr));
        rar_other_mt->setItemText(21, QCoreApplication::translate("MainWindow", "21", nullptr));
        rar_other_mt->setItemText(22, QCoreApplication::translate("MainWindow", "22", nullptr));
        rar_other_mt->setItemText(23, QCoreApplication::translate("MainWindow", "23", nullptr));
        rar_other_mt->setItemText(24, QCoreApplication::translate("MainWindow", "24", nullptr));
        rar_other_mt->setItemText(25, QCoreApplication::translate("MainWindow", "25", nullptr));
        rar_other_mt->setItemText(26, QCoreApplication::translate("MainWindow", "26", nullptr));
        rar_other_mt->setItemText(27, QCoreApplication::translate("MainWindow", "27", nullptr));
        rar_other_mt->setItemText(28, QCoreApplication::translate("MainWindow", "28", nullptr));
        rar_other_mt->setItemText(29, QCoreApplication::translate("MainWindow", "29", nullptr));
        rar_other_mt->setItemText(30, QCoreApplication::translate("MainWindow", "30", nullptr));
        rar_other_mt->setItemText(31, QCoreApplication::translate("MainWindow", "31", nullptr));
        rar_other_mt->setItemText(32, QCoreApplication::translate("MainWindow", "32", nullptr));

#if QT_CONFIG(tooltip)
        rar_other_mt->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\203\346\225\270\347\232\204\346\224\271\350\256\212\346\234\203\347\250\215\345\276\256\345\275\261\351\237\277\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_other_mt->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        rar_other_oc->setText(QCoreApplication::translate("MainWindow", "\350\250\255\345\256\232NTFS\345\243\223\347\270\256\345\261\254\346\200\247", nullptr));
        tab_winrar->setTabText(tab_winrar->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256", nullptr));
#if QT_CONFIG(statustip)
        unrar_1click->setStatusTip(QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\347\270\256\350\207\263\344\276\206\346\272\220\350\263\207\346\226\231\345\244\276 (\345\277\253\346\215\267\351\215\265\357\274\232Alt+F)", nullptr));
#endif // QT_CONFIG(statustip)
        unrar_1click->setText(QCoreApplication::translate("MainWindow", "\342\206\222 \344\276\206\346\272\220\350\263\207\346\226\231\345\244\276(&F)", nullptr));
        groupBox_10->setTitle(QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\350\250\255\345\256\232", nullptr));
        unrar_o->setItemText(0, QCoreApplication::translate("MainWindow", "\350\246\206\345\257\253\345\205\250\351\203\250\346\252\224\346\241\210", nullptr));
        unrar_o->setItemText(1, QCoreApplication::translate("MainWindow", "\344\270\215\350\246\206\345\257\253\347\217\276\345\255\230\347\232\204\346\252\224\346\241\210", nullptr));

#if QT_CONFIG(tooltip)
        unrar_kb->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        unrar_kb->setText(QCoreApplication::translate("MainWindow", "\344\277\235\347\225\231\344\270\215\345\256\214\346\225\264\347\232\204\346\252\224\346\241\210", nullptr));
#if QT_CONFIG(tooltip)
        unrar_oni->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        unrar_oni->setText(QCoreApplication::translate("MainWindow", "\345\205\201\350\250\261\346\275\233\345\234\250\344\270\215\347\233\270\345\256\271\345\220\215\347\250\261", nullptr));
#if QT_CONFIG(statustip)
        unrar_or->setStatusTip(QCoreApplication::translate("MainWindow", "\345\246\202\346\236\234\347\233\270\345\220\214\346\252\224\345\220\215\345\267\262\347\266\223\345\255\230\345\234\250\345\260\207\350\207\252\345\213\225\351\207\215\346\226\260\345\221\275\345\220\215\350\247\243\345\243\223\347\270\256\347\232\204\346\252\224\346\241\210\357\274\214\351\207\215\346\226\260\345\221\275\345\220\215\347\232\204\346\252\224\346\241\210\346\240\274\345\274\217\347\202\272 \"filename(N).txt\"", nullptr));
#endif // QT_CONFIG(statustip)
        unrar_or->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\213\225\351\207\215\346\226\260\345\221\275\345\220\215\346\252\224\346\241\210", nullptr));
        unrar_ad->setText(QCoreApplication::translate("MainWindow", "\351\231\204\345\212\240\345\243\223\347\270\256\346\252\224\345\220\215\347\250\261\345\210\260\347\233\256\346\250\231\350\267\257\345\276\221", nullptr));
#if QT_CONFIG(tooltip)
        unrar_noComm->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        unrar_noComm->setText(QCoreApplication::translate("MainWindow", "\344\270\215\351\241\257\347\244\272\345\243\223\347\270\256\346\252\224\350\250\273\350\247\243", nullptr));
#if QT_CONFIG(statustip)
        unrar_ep->setStatusTip(QCoreApplication::translate("MainWindow", "\351\226\213\345\225\237\346\255\244\351\201\270\351\240\205\346\234\203\345\277\275\347\225\245\350\247\243\345\243\223\347\270\256\346\252\224\347\232\204\350\267\257\345\276\221\357\274\214\350\256\223\346\211\200\346\234\211\346\252\224\346\241\210\351\203\275\346\224\276\345\234\250\347\233\270\345\220\214\347\233\256\351\214\204\344\270\213\343\200\202", nullptr));
#endif // QT_CONFIG(statustip)
        unrar_ep->setText(QCoreApplication::translate("MainWindow", "\345\277\275\347\225\245\350\267\257\345\276\221", nullptr));
#if QT_CONFIG(statustip)
        unrar_btn->setStatusTip(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\346\250\231\346\272\226\350\247\243\345\243\223\347\270\256\346\214\207\344\273\244 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+D)", nullptr));
#endif // QT_CONFIG(statustip)
        unrar_btn->setText(QString());
#if QT_CONFIG(shortcut)
        unrar_btn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_11->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\345\205\247\345\256\271 (powered by 7-Zip)", nullptr));
        rar_viewFileList->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
#if QT_CONFIG(statustip)
        unrar_viewbtn->setStatusTip(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\345\205\247\345\256\271 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+R)", nullptr));
#endif // QT_CONFIG(statustip)
        unrar_viewbtn->setText(QString());
#if QT_CONFIG(shortcut)
        unrar_viewbtn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        tab_winrar->setTabText(tab_winrar->indexOf(tab_5), QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\347\270\256", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "\350\274\270\345\207\272\350\250\273\350\247\243\345\210\260\346\226\207\345\255\227\346\252\224\357\274\232", nullptr));
#if QT_CONFIG(statustip)
        rar_comm_outpath_btn->setStatusTip(QCoreApplication::translate("MainWindow", "\350\274\270\345\207\272\350\250\273\350\247\243\345\210\260\346\226\207\345\255\227\346\252\224 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+O)", nullptr));
#endif // QT_CONFIG(statustip)
        rar_comm_outpath_btn->setText(QString());
#if QT_CONFIG(shortcut)
        rar_comm_outpath_btn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\226\207\345\255\227\346\252\224\347\267\250\347\242\274\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        rar_scfc->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_scfc->setStatusTip(QCoreApplication::translate("MainWindow", "Alt+\345\272\225\347\267\232\345\255\227\347\254\246\345\217\257\345\277\253\351\200\237\351\201\270\345\217\226\345\224\267!", nullptr));
#endif // QT_CONFIG(statustip)
        rar_scfc->setText(QCoreApplication::translate("MainWindow", "UTF-8 &BOM", nullptr));
#if QT_CONFIG(tooltip)
        rar_scuc->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_scuc->setStatusTip(QCoreApplication::translate("MainWindow", "Alt+\345\272\225\347\267\232\345\255\227\347\254\246\345\217\257\345\277\253\351\200\237\351\201\270\345\217\226\345\224\267!", nullptr));
#endif // QT_CONFIG(statustip)
        rar_scuc->setText(QCoreApplication::translate("MainWindow", "UTF-1&6", nullptr));
#if QT_CONFIG(tooltip)
        rar_scac->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_scac->setStatusTip(QCoreApplication::translate("MainWindow", "Alt+\345\272\225\347\267\232\345\255\227\347\254\246\345\217\257\345\277\253\351\200\237\351\201\270\345\217\226\345\224\267!", nullptr));
#endif // QT_CONFIG(statustip)
        rar_scac->setText(QCoreApplication::translate("MainWindow", "A&NSI", nullptr));
#if QT_CONFIG(tooltip)
        rar_scoc->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        rar_scoc->setStatusTip(QCoreApplication::translate("MainWindow", "Alt+\345\272\225\347\267\232\345\255\227\347\254\246\345\217\257\345\277\253\351\200\237\351\201\270\345\217\226\345\224\267!", nullptr));
#endif // QT_CONFIG(statustip)
        rar_scoc->setText(QCoreApplication::translate("MainWindow", "UTF-&8", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "\345\257\253\345\205\245\350\250\273\350\247\243\357\274\232", nullptr));
        commenttext->setDocumentTitle(QString());
        commenttext->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0055ff;\">\347\267\250\350\274\257\350\246\217\345\211\207\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#0055ff;\">\344\277\235\347\225\231\347\251\272\347\231\275 = \345\210\252\351\231\244\345\243\223\347\270\256\346\252\224\347\232\204\350\250\273\350\247\243</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-"
                        "indent:0; text-indent:0px;\"><span style=\" color:#0055ff;\">\350\274\270\345\205\245\346\226\207\345\255\227 = \350\246\206\350\223\213\345\243\223\347\270\256\346\252\224\347\232\204\350\250\273\350\247\243</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ce4400;\">\345\260\215\345\216\237\346\234\211\347\232\204\350\250\273\350\247\243\351\200\262\350\241\214\344\272\214\346\254\241\347\267\250\350\274\257\350\253\213\346\214\211\347\205\247\344\273\245\344\270\213\346\255\245\351\251\237\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ce4400;\">1.\350\256\200\345\217\226\350\250\273\350\247\243</span></p>\n"
"<p style=\" "
                        "margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ce4400;\">2.\350\244\207\350\243\275\350\256\200\345\217\226\345\205\247\345\256\271\350\207\263\346\255\244\346\226\207\345\255\227\346\226\271\345\241\212</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ce4400;\">3.\347\267\250\350\274\257\345\256\214\345\206\215\345\257\253\345\205\245\345\215\263\345\217\257</span></p></body></html>", nullptr));
#if QT_CONFIG(statustip)
        pushButton_6->setStatusTip(QCoreApplication::translate("MainWindow", "\345\257\253\345\205\245\350\250\273\350\247\243 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+W)", nullptr));
#endif // QT_CONFIG(statustip)
        pushButton_6->setText(QString());
#if QT_CONFIG(shortcut)
        pushButton_6->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_9->setTitle(QCoreApplication::translate("MainWindow", "\350\256\200\345\217\226\350\250\273\350\247\243\357\274\232", nullptr));
        commenttext_2->setDocumentTitle(QString());
        commenttext_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0055ff;\">\346\223\215\344\275\234\350\252\252\346\230\216\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0055ff;\">\350\253\213\346\214\211&quot;</span><span style=\" font-size:12pt; font-weight:600; color:#00557f;\">\351\201\270\346\223\207\346\252\224\346\241\210</span><span style=\" font-size:12pt; color:#0055ff;\">&quot;\351\201\270"
                        "\346\223\207\346\254\262\346\237\245\347\234\213\347\232\204\345\243\223\347\270\256\346\252\224</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0055ff;\">\345\206\215\346\214\211\344\270\213&quot;</span><span style=\" font-size:12pt; font-weight:600; color:#00557f;\">\350\256\200\345\217\226</span><span style=\" font-size:12pt; color:#0055ff;\">&quot;\345\215\263\345\217\257\351\241\257\347\244\272\345\234\250\346\255\244\346\226\207\345\255\227\346\226\271\345\241\212</span></p></body></html>", nullptr));
#if QT_CONFIG(statustip)
        pushButton_9->setStatusTip(QCoreApplication::translate("MainWindow", "\350\256\200\345\217\226\350\250\273\350\247\243 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+R)", nullptr));
#endif // QT_CONFIG(statustip)
        pushButton_9->setText(QString());
#if QT_CONFIG(shortcut)
        pushButton_9->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        tab_winrar->setTabText(tab_winrar->indexOf(tab_8), QCoreApplication::translate("MainWindow", "\347\267\250\350\274\257/\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\350\250\273\350\247\243", nullptr));
        tab_winrar->setTabText(tab_winrar->indexOf(tab_19), QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\221\275\344\273\244\345\237\267\350\241\214\351\200\262\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "WinRAR", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setTabToolTip(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\346\234\200\345\217\227\346\255\241\350\277\216\347\232\204\345\243\223\347\270\256\345\267\245\345\205\267\344\271\213\344\270\200", nullptr));
#endif // QT_CONFIG(tooltip)
        tab_7z->setTabText(tab_7z->indexOf(tab_6), QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256", nullptr));
        groupBox_12->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\345\205\247\345\256\271", nullptr));
        sz_viewFileList->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
#if QT_CONFIG(statustip)
        sz_viewbtn->setStatusTip(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\345\205\247\345\256\271 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+R)", nullptr));
#endif // QT_CONFIG(statustip)
        sz_viewbtn->setText(QString());
#if QT_CONFIG(shortcut)
        sz_viewbtn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        tab_7z->setTabText(tab_7z->indexOf(tab_7), QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\347\270\256", nullptr));
        tab_7z->setTabText(tab_7z->indexOf(tab_18), QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\221\275\344\273\244\345\237\267\350\241\214\351\200\262\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "7-Zip", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\234\200\345\217\227\346\255\241\350\277\216\347\232\204\345\243\223\347\270\256\345\267\245\345\205\267\344\271\213\344\270\200", nullptr));
#endif // QT_CONFIG(tooltip)
        tab_upx->setTabText(tab_upx->indexOf(tab_14), QCoreApplication::translate("MainWindow", "\345\212\240\346\256\274\345\243\223\347\270\256", nullptr));
        tab_upx->setTabText(tab_upx->indexOf(tab_15), QCoreApplication::translate("MainWindow", "\350\204\253\346\256\274", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "UPX", nullptr));
#if QT_CONFIG(tooltip)
        tabWidget->setTabToolTip(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\347\224\250\346\226\274\345\243\223\347\270\256\"\345\217\257\345\237\267\350\241\214\346\252\224\"", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        paq_compRunCmd->setToolTip(QCoreApplication::translate("MainWindow", "RUN!!", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        paq_compRunCmd->setStatusTip(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\345\243\223\347\270\256\346\214\207\344\273\244 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+R)", nullptr));
#endif // QT_CONFIG(statustip)
        paq_compRunCmd->setText(QString());
#if QT_CONFIG(shortcut)
        paq_compRunCmd->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_13->setTitle(QCoreApplication::translate("MainWindow", "\345\237\272\346\234\254\350\250\255\345\256\232", nullptr));
        others_tool->setItemText(0, QCoreApplication::translate("MainWindow", "pxd", nullptr));
        others_tool->setItemText(1, QCoreApplication::translate("MainWindow", "px", nullptr));
        others_tool->setItemText(2, QCoreApplication::translate("MainWindow", "cmix", nullptr));
        others_tool->setItemText(3, QCoreApplication::translate("MainWindow", "bcm", nullptr));
        others_tool->setItemText(4, QCoreApplication::translate("MainWindow", "kanzi", nullptr));

        label_32->setText(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\345\267\245\345\205\267\357\274\232", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256\347\255\211\347\264\232\357\274\232", nullptr));
        groupBox_15->setTitle(QCoreApplication::translate("MainWindow", "\351\200\262\351\232\216\350\250\255\345\256\232", nullptr));
        paq_threads->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        paq_threads->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        paq_threads->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        paq_threads->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        paq_threads->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));
        paq_threads->setItemText(5, QCoreApplication::translate("MainWindow", "6", nullptr));
        paq_threads->setItemText(6, QCoreApplication::translate("MainWindow", "7", nullptr));
        paq_threads->setItemText(7, QCoreApplication::translate("MainWindow", "8", nullptr));
        paq_threads->setItemText(8, QCoreApplication::translate("MainWindow", "9", nullptr));

        label_31->setText(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\347\267\222\357\274\232", nullptr));
        paq_dic->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\215\344\275\277\347\224\250", nullptr));
        paq_dic->setItemText(1, QCoreApplication::translate("MainWindow", "english.dic", nullptr));

        label_33->setText(QCoreApplication::translate("MainWindow", "\345\255\227\345\205\270\357\274\232", nullptr));
#if QT_CONFIG(statustip)
        px_switch_b->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        px_switch_b->setText(QCoreApplication::translate("MainWindow", "\345\274\267\345\210\266\346\252\242\346\270\254Deflate", nullptr));
#if QT_CONFIG(statustip)
        px_switch_s->setStatusTip(QCoreApplication::translate("MainWindow", "\350\213\245\346\254\262\345\243\223\347\270\256\347\232\204\345\205\247\345\256\271\345\220\253\345\244\247\351\207\217\345\234\226\347\211\207\345\260\207\346\245\265\345\244\247\347\232\204\351\231\215\344\275\216\345\243\223\347\270\256\350\200\227\346\231\202\357\274\214\344\275\206\346\234\203\345\275\261\351\237\277\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(statustip)
        px_switch_s->setText(QCoreApplication::translate("MainWindow", "\347\225\245\351\201\216\351\241\217\350\211\262\350\247\243\346\236\220", nullptr));
#if QT_CONFIG(statustip)
        px_switch_a->setStatusTip(QCoreApplication::translate("MainWindow", "\351\200\232\345\270\270\350\203\275\346\224\271\345\226\204\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(statustip)
        px_switch_a->setText(QCoreApplication::translate("MainWindow", "\350\207\252\351\201\251\346\207\211\345\255\270\347\277\222", nullptr));
#if QT_CONFIG(statustip)
        px_switch_e->setStatusTip(QCoreApplication::translate("MainWindow", "\351\200\232\345\270\270\350\203\275\346\224\271\345\226\204\345\243\223\347\270\256\347\216\207", nullptr));
#endif // QT_CONFIG(statustip)
        px_switch_e->setText(QCoreApplication::translate("MainWindow", "\350\250\223\347\267\264exe model", nullptr));
        tab_paq->setTabText(tab_paq->indexOf(tab_16), QCoreApplication::translate("MainWindow", "\345\243\223\347\270\256", nullptr));
#if QT_CONFIG(statustip)
        decomp_1click->setStatusTip(QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\347\270\256\350\207\263\344\276\206\346\272\220\350\263\207\346\226\231\345\244\276 (\345\277\253\346\215\267\351\215\265\357\274\232Alt+F)", nullptr));
#endif // QT_CONFIG(statustip)
        decomp_1click->setText(QCoreApplication::translate("MainWindow", "\342\206\222 \344\276\206\346\272\220\350\263\207\346\226\231\345\244\276(&F)", nullptr));
#if QT_CONFIG(statustip)
        decomp_btn->setStatusTip(QCoreApplication::translate("MainWindow", "\345\237\267\350\241\214\346\250\231\346\272\226\350\247\243\345\243\223\347\270\256\346\214\207\344\273\244 (\345\277\253\346\215\267\351\215\265\357\274\232Alt+D)", nullptr));
#endif // QT_CONFIG(statustip)
        decomp_btn->setText(QCoreApplication::translate("MainWindow", "\342\206\222 \346\214\207\345\256\232\350\263\207\346\226\231\345\244\276(&D)", nullptr));
#if QT_CONFIG(statustip)
        other_viewbtn->setStatusTip(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\345\205\247\345\256\271 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+R)", nullptr));
#endif // QT_CONFIG(statustip)
        other_viewbtn->setText(QCoreApplication::translate("MainWindow", "  \345\210\267\346\226\260", nullptr));
#if QT_CONFIG(shortcut)
        other_viewbtn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        groupBox_19->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\243\223\347\270\256\346\252\224\345\205\247\345\256\271 (\345\217\252\351\231\220PAQ\347\263\273\345\210\227)", nullptr));
        paq_viewFileList->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224'; font-size:10pt; font-weight:600; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p></body></html>", nullptr));
        groupBox_14->setTitle(QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\345\267\245\345\205\267", nullptr));
        decomp_tool->setItemText(0, QCoreApplication::translate("MainWindow", "pxd", nullptr));
        decomp_tool->setItemText(1, QCoreApplication::translate("MainWindow", "px", nullptr));
        decomp_tool->setItemText(2, QCoreApplication::translate("MainWindow", "cmix", nullptr));
        decomp_tool->setItemText(3, QCoreApplication::translate("MainWindow", "bcm", nullptr));
        decomp_tool->setItemText(4, QCoreApplication::translate("MainWindow", "kanzi", nullptr));

        tab_paq->setTabText(tab_paq->indexOf(tab_17), QCoreApplication::translate("MainWindow", "\350\247\243\345\243\223\347\270\256", nullptr));
        tab_paq->setTabText(tab_paq->indexOf(tab_20), QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213\345\221\275\344\273\244\345\237\267\350\241\214\351\200\262\345\272\246", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QCoreApplication::translate("MainWindow", "\345\205\266\344\273\226", nullptr));
#if QT_CONFIG(tooltip)
        no_TipMsg->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        no_TipMsg->setText(QCoreApplication::translate("MainWindow", "\351\227\234\351\226\211\346\217\220\351\206\222\343\200\201\345\212\237\350\203\275\344\273\213\347\264\271", nullptr));
        no_WarningMsg->setText(QCoreApplication::translate("MainWindow", "\351\227\234\351\226\211\351\203\250\345\210\206\351\214\257\350\252\244\350\250\255\345\256\232\350\255\246\345\221\212", nullptr));
        sysFreeRAM->setText(QCoreApplication::translate("MainWindow", "99999", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "MB", nullptr));
        about->setTitle(QCoreApplication::translate("MainWindow", "\351\227\234\346\226\274(&A)", nullptr));
        profile->setTitle(QCoreApplication::translate("MainWindow", "\350\250\255\345\256\232\346\252\224(&S)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
