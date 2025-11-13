/********************************************************************************
** Form generated from reading UI file 'StartupDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTUPDIALOG_H
#define UI_STARTUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartupDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *subtitleLabel;
    QSpacerItem *verticalSpacer;
    QPushButton *createButton;
    QPushButton *loadButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *StartupDialog)
    {
        if (StartupDialog->objectName().isEmpty())
            StartupDialog->setObjectName("StartupDialog");
        StartupDialog->resize(400, 200);
        verticalLayout = new QVBoxLayout(StartupDialog);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(StartupDialog);
        titleLabel->setObjectName("titleLabel");

        verticalLayout->addWidget(titleLabel);

        subtitleLabel = new QLabel(StartupDialog);
        subtitleLabel->setObjectName("subtitleLabel");

        verticalLayout->addWidget(subtitleLabel);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        createButton = new QPushButton(StartupDialog);
        createButton->setObjectName("createButton");

        verticalLayout->addWidget(createButton);

        loadButton = new QPushButton(StartupDialog);
        loadButton->setObjectName("loadButton");

        verticalLayout->addWidget(loadButton);

        cancelButton = new QPushButton(StartupDialog);
        cancelButton->setObjectName("cancelButton");

        verticalLayout->addWidget(cancelButton);


        retranslateUi(StartupDialog);

        QMetaObject::connectSlotsByName(StartupDialog);
    } // setupUi

    void retranslateUi(QDialog *StartupDialog)
    {
        StartupDialog->setWindowTitle(QCoreApplication::translate("StartupDialog", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\226\320\262 - \320\237\320\276\321\207\320\260\321\202\320\276\320\272 \321\200\320\276\320\261\320\276\321\202\320\270", nullptr));
        titleLabel->setText(QCoreApplication::translate("StartupDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#4a6fa5;\">\320\233\320\260\321\201\320\272\320\260\320\262\320\276 \320\277\321\200\320\276\321\201\320\270\320\274\320\276!</span></p></body></html>", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("StartupDialog", "<html><head/><body><p align=\"center\"><span style=\" color:#666666;\">\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\264\321\226\321\216 \320\264\320\273\321\217 \320\277\320\276\321\207\320\260\321\202\320\272\321\203 \321\200\320\276\320\261\320\276\321\202\320\270</span></p></body></html>", nullptr));
        createButton->setText(QCoreApplication::translate("StartupDialog", "\342\236\225 \320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\275\320\276\320\262\321\203 \321\202\320\260\320\261\320\273\320\270\321\206\321\216", nullptr));
#if QT_CONFIG(tooltip)
        createButton->setToolTip(QCoreApplication::translate("StartupDialog", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\277\320\276\321\200\320\276\320\266\320\275\321\216 \321\202\320\260\320\261\320\273\320\270\321\206\321\216 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\226\320\262", nullptr));
#endif // QT_CONFIG(tooltip)
        loadButton->setText(QCoreApplication::translate("StartupDialog", "\360\237\223\202 \320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\267 \321\204\320\260\320\271\320\273\321\203", nullptr));
#if QT_CONFIG(tooltip)
        loadButton->setToolTip(QCoreApplication::translate("StartupDialog", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\264\320\260\320\275\321\226 \320\267 \321\202\320\265\320\272\321\201\321\202\320\276\320\262\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\321\203", nullptr));
#endif // QT_CONFIG(tooltip)
        cancelButton->setText(QCoreApplication::translate("StartupDialog", "\342\235\214 \320\222\320\270\320\271\321\202\320\270 \320\267 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270", nullptr));
#if QT_CONFIG(tooltip)
        cancelButton->setToolTip(QCoreApplication::translate("StartupDialog", "\320\227\320\260\320\272\321\200\320\270\321\202\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\321\203", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class StartupDialog: public Ui_StartupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTUPDIALOG_H
