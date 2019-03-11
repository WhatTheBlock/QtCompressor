/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QTextEdit *log;
    QPushButton *pushButton_4;
    QLabel *label;
    QGroupBox *groupBox;
    QRadioButton *mode3;
    QRadioButton *mode1;
    QRadioButton *mode2;
    QFrame *line;
    QGroupBox *groupBox_2;
    QRadioButton *delTestFile;
    QRadioButton *keepTestFile;
    QRadioButton *keepAllTestFile;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QString::fromUtf8("Dialog1"));
        Dialog1->setEnabled(true);
        Dialog1->resize(800, 609);
        Dialog1->setMinimumSize(QSize(789, 347));
        Dialog1->setMaximumSize(QSize(7899, 3477));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        font.setPointSize(10);
        Dialog1->setFont(font);
        Dialog1->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/rank.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog1->setWindowIcon(icon);
        Dialog1->setWindowOpacity(0.970000000000000);
        pushButton_2 = new QPushButton(Dialog1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(580, 490, 201, 101));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/fire.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(64, 64));
        lineEdit = new QLineEdit(Dialog1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(150, 20, 631, 31));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        lineEdit->setFont(font2);
        lineEdit->setAlignment(Qt::AlignCenter);
        lineEdit->setDragEnabled(true);
        lineEdit->setReadOnly(true);
        lineEdit_2 = new QLineEdit(Dialog1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setEnabled(true);
        lineEdit_2->setGeometry(QRect(150, 60, 631, 31));
        lineEdit_2->setFont(font2);
        lineEdit_2->setAlignment(Qt::AlignCenter);
        lineEdit_2->setReadOnly(true);
        pushButton_3 = new QPushButton(Dialog1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 60, 121, 31));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_3->setFont(font3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(24, 24));
        log = new QTextEdit(Dialog1);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(20, 160, 541, 431));
        QFont font4;
        font4.setPointSize(15);
        log->setFont(font4);
        log->setAcceptDrops(false);
        log->setReadOnly(true);
        pushButton_4 = new QPushButton(Dialog1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 20, 121, 31));
        pushButton_4->setFont(font3);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/open-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(24, 24));
        label = new QLabel(Dialog1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 120, 61, 31));
        QFont font5;
        font5.setPointSize(17);
        font5.setBold(true);
        font5.setWeight(75);
        label->setFont(font5);
        groupBox = new QGroupBox(Dialog1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(580, 145, 201, 161));
        groupBox->setFont(font5);
        mode3 = new QRadioButton(groupBox);
        mode3->setObjectName(QString::fromUtf8("mode3"));
        mode3->setGeometry(QRect(10, 125, 171, 21));
        QFont font6;
        font6.setPointSize(15);
        font6.setBold(false);
        font6.setWeight(50);
        mode3->setFont(font6);
        mode1 = new QRadioButton(groupBox);
        mode1->setObjectName(QString::fromUtf8("mode1"));
        mode1->setGeometry(QRect(10, 45, 151, 21));
        mode1->setFont(font6);
        mode1->setIconSize(QSize(20, 20));
        mode1->setChecked(true);
        mode2 = new QRadioButton(groupBox);
        mode2->setObjectName(QString::fromUtf8("mode2"));
        mode2->setGeometry(QRect(10, 85, 161, 21));
        mode2->setFont(font6);
        line = new QFrame(Dialog1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 103, 791, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(Dialog1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 320, 201, 151));
        groupBox_2->setFont(font5);
        delTestFile = new QRadioButton(groupBox_2);
        delTestFile->setObjectName(QString::fromUtf8("delTestFile"));
        delTestFile->setGeometry(QRect(10, 38, 181, 31));
        delTestFile->setFont(font6);
        delTestFile->setChecked(true);
        keepTestFile = new QRadioButton(groupBox_2);
        keepTestFile->setObjectName(QString::fromUtf8("keepTestFile"));
        keepTestFile->setGeometry(QRect(10, 78, 181, 31));
        keepTestFile->setFont(font6);
        keepAllTestFile = new QRadioButton(groupBox_2);
        keepAllTestFile->setObjectName(QString::fromUtf8("keepAllTestFile"));
        keepAllTestFile->setGeometry(QRect(10, 118, 181, 31));
        keepAllTestFile->setFont(font6);

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "QtCompressor - \346\270\254\350\251\246\346\252\224\346\241\210\345\243\223\347\270\256\346\245\265\351\231\220", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("Dialog1", "\351\226\213\345\247\213\346\270\254\350\251\246 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+S)", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButton_2->setWhatsThis(QApplication::translate("Dialog1", "\351\226\213\345\247\213\346\270\254\350\251\246 (\345\277\253\346\215\267\351\215\265\357\274\232Ctrl+S)", nullptr));
#endif // QT_NO_WHATSTHIS
        pushButton_2->setText(QString());
#ifndef QT_NO_SHORTCUT
        pushButton_2->setShortcut(QApplication::translate("Dialog1", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        lineEdit->setText(QApplication::translate("Dialog1", "\345\217\257\347\233\264\346\216\245\346\213\226\346\233\263\346\270\254\350\251\246\346\252\224\346\241\210\346\210\226\350\263\207\346\226\231\345\244\276\350\207\263\346\255\244", nullptr));
        lineEdit_2->setText(QApplication::translate("Dialog1", "\351\201\270\346\223\207\350\274\270\345\207\272\346\232\253\345\255\230\346\252\224\344\275\215\347\275\256", nullptr));
        pushButton_3->setText(QApplication::translate("Dialog1", "\350\274\270\345\207\272\344\275\215\347\275\256", nullptr));
#ifndef QT_NO_TOOLTIP
        log->setToolTip(QApplication::translate("Dialog1", "\345\210\227\345\207\272\350\251\263\347\264\260\345\237\267\350\241\214\351\201\216\347\250\213", nullptr));
#endif // QT_NO_TOOLTIP
        pushButton_4->setText(QApplication::translate("Dialog1", "\351\201\270\346\223\207\346\252\224\346\241\210", nullptr));
        label->setText(QApplication::translate("Dialog1", "Log:", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog1", "\346\250\241\345\274\217\351\201\270\346\223\207", nullptr));
#ifndef QT_NO_TOOLTIP
        mode3->setToolTip(QApplication::translate("Dialog1", "\344\275\277\347\224\250PAQ8PXD\346\270\254\350\251\246", nullptr));
#endif // QT_NO_TOOLTIP
        mode3->setText(QApplication::translate("Dialog1", "\346\245\265\351\231\220\346\250\241\345\274\217 (\346\205\216\347\224\250)", nullptr));
#ifndef QT_NO_TOOLTIP
        mode1->setToolTip(QApplication::translate("Dialog1", "\344\275\277\347\224\250WinRAR\343\200\2017-Zip\343\200\201UPX\346\270\254\350\251\246", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        mode1->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        mode1->setText(QApplication::translate("Dialog1", "\346\250\231\346\272\226\346\250\241\345\274\217", nullptr));
#ifndef QT_NO_TOOLTIP
        mode2->setToolTip(QApplication::translate("Dialog1", "\344\275\277\347\224\250WinRAR\343\200\2017-Zip\343\200\201UHARC\343\200\201UPX\346\270\254\350\251\246", nullptr));
#endif // QT_NO_TOOLTIP
        mode2->setText(QApplication::translate("Dialog1", "\351\200\262\351\232\216\346\250\241\345\274\217", nullptr));
        groupBox_2->setTitle(QString());
        delTestFile->setText(QApplication::translate("Dialog1", "\344\270\215\344\277\235\347\225\231\346\270\254\350\251\246\346\252\224\346\241\210", nullptr));
#ifndef QT_NO_TOOLTIP
        keepTestFile->setToolTip(QApplication::translate("Dialog1", "\350\274\270\345\207\272\344\275\215\347\275\256\351\240\210\344\277\235\347\225\231\350\207\263\345\260\2212\345\200\215\346\270\254\350\251\246\346\252\224\346\241\210\345\244\247\345\260\217\344\273\245\344\270\212", nullptr));
#endif // QT_NO_TOOLTIP
        keepTestFile->setText(QApplication::translate("Dialog1", "\344\277\235\347\225\231\346\234\200\345\260\217\346\270\254\350\251\246\346\252\224\346\241\210", nullptr));
#ifndef QT_NO_TOOLTIP
        keepAllTestFile->setToolTip(QApplication::translate("Dialog1", "\350\274\270\345\207\272\344\275\215\347\275\256\351\240\210\344\277\235\347\225\231\350\207\263\345\260\22113\345\200\215\346\270\254\350\251\246\346\252\224\346\241\210\345\244\247\345\260\217\344\273\245\344\270\212", nullptr));
#endif // QT_NO_TOOLTIP
        keepAllTestFile->setText(QApplication::translate("Dialog1", "\344\277\235\347\225\231\346\211\200\346\234\211\346\270\254\350\251\246\346\252\224\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
