/********************************************************************************
** Form generated from reading UI file 'OperationsWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATIONSWINDOW_H
#define UI_OPERATIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperationsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *sortTab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *sortColorAscButton;
    QPushButton *sortColorDescButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sortPriceAscButton;
    QPushButton *sortPriceDescButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *sortPowerAscButton;
    QPushButton *sortPowerDescButton;
    QSpacerItem *verticalSpacer;
    QWidget *searchTab;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *findBrandButton;
    QPushButton *priceRangeButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *samePriceDiffColorButton;
    QPushButton *brandColorQueriesButton;
    QPushButton *colorMinMaxButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_6;
    QPlainTextEdit *resultsText;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *clearResultsButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *OperationsWindow)
    {
        if (OperationsWindow->objectName().isEmpty())
            OperationsWindow->setObjectName("OperationsWindow");
        OperationsWindow->resize(900, 700);
        OperationsWindow->setMinimumSize(QSize(900, 700));
        verticalLayout = new QVBoxLayout(OperationsWindow);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(OperationsWindow);
        tabWidget->setObjectName("tabWidget");
        sortTab = new QWidget();
        sortTab->setObjectName("sortTab");
        verticalLayout_2 = new QVBoxLayout(sortTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(sortTab);
        groupBox->setObjectName("groupBox");
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName("horizontalLayout");
        sortColorAscButton = new QPushButton(groupBox);
        sortColorAscButton->setObjectName("sortColorAscButton");

        horizontalLayout->addWidget(sortColorAscButton);

        sortColorDescButton = new QPushButton(groupBox);
        sortColorDescButton->setObjectName("sortColorDescButton");

        horizontalLayout->addWidget(sortColorDescButton);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(sortTab);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        sortPriceAscButton = new QPushButton(groupBox_2);
        sortPriceAscButton->setObjectName("sortPriceAscButton");

        horizontalLayout_2->addWidget(sortPriceAscButton);

        sortPriceDescButton = new QPushButton(groupBox_2);
        sortPriceDescButton->setObjectName("sortPriceDescButton");

        horizontalLayout_2->addWidget(sortPriceDescButton);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(sortTab);
        groupBox_3->setObjectName("groupBox_3");
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        sortPowerAscButton = new QPushButton(groupBox_3);
        sortPowerAscButton->setObjectName("sortPowerAscButton");

        horizontalLayout_3->addWidget(sortPowerAscButton);

        sortPowerDescButton = new QPushButton(groupBox_3);
        sortPowerDescButton->setObjectName("sortPowerDescButton");

        horizontalLayout_3->addWidget(sortPowerDescButton);


        verticalLayout_2->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(sortTab, QString());
        searchTab = new QWidget();
        searchTab->setObjectName("searchTab");
        verticalLayout_3 = new QVBoxLayout(searchTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox_4 = new QGroupBox(searchTab);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_4 = new QVBoxLayout(groupBox_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        findBrandButton = new QPushButton(groupBox_4);
        findBrandButton->setObjectName("findBrandButton");

        verticalLayout_4->addWidget(findBrandButton);

        priceRangeButton = new QPushButton(groupBox_4);
        priceRangeButton->setObjectName("priceRangeButton");

        verticalLayout_4->addWidget(priceRangeButton);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(searchTab);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_5 = new QVBoxLayout(groupBox_5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        samePriceDiffColorButton = new QPushButton(groupBox_5);
        samePriceDiffColorButton->setObjectName("samePriceDiffColorButton");

        verticalLayout_5->addWidget(samePriceDiffColorButton);

        brandColorQueriesButton = new QPushButton(groupBox_5);
        brandColorQueriesButton->setObjectName("brandColorQueriesButton");

        verticalLayout_5->addWidget(brandColorQueriesButton);

        colorMinMaxButton = new QPushButton(groupBox_5);
        colorMinMaxButton->setObjectName("colorMinMaxButton");

        verticalLayout_5->addWidget(colorMinMaxButton);


        verticalLayout_3->addWidget(groupBox_5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        tabWidget->addTab(searchTab, QString());

        verticalLayout->addWidget(tabWidget);

        groupBox_6 = new QGroupBox(OperationsWindow);
        groupBox_6->setObjectName("groupBox_6");
        verticalLayout_6 = new QVBoxLayout(groupBox_6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        resultsText = new QPlainTextEdit(groupBox_6);
        resultsText->setObjectName("resultsText");
        resultsText->setReadOnly(true);

        verticalLayout_6->addWidget(resultsText);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        clearResultsButton = new QPushButton(groupBox_6);
        clearResultsButton->setObjectName("clearResultsButton");

        horizontalLayout_4->addWidget(clearResultsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        closeButton = new QPushButton(groupBox_6);
        closeButton->setObjectName("closeButton");

        horizontalLayout_4->addWidget(closeButton);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox_6);


        retranslateUi(OperationsWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(OperationsWindow);
    } // setupUi

    void retranslateUi(QDialog *OperationsWindow)
    {
        OperationsWindow->setWindowTitle(QCoreApplication::translate("OperationsWindow", "\320\236\320\277\320\265\321\200\320\260\321\206\321\226\321\227 \320\267 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\217\320\274\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("OperationsWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217 \320\267\320\260 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274", nullptr));
        sortColorAscButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\274 \320\227\320\260 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 (\320\220-\320\257)", nullptr));
        sortColorDescButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\275 \320\227\320\260 \320\272\320\276\320\273\321\214\320\276\321\200\320\276\320\274 (\320\257-\320\220)", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("OperationsWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217 \320\267\320\260 \321\206\321\226\320\275\320\276\321\216", nullptr));
        sortPriceAscButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\274 \320\227\320\260 \321\206\321\226\320\275\320\276\321\216 (\320\267\321\200\320\276\321\201\321\202\320\260\320\275\320\275\321\217)", nullptr));
        sortPriceDescButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\275 \320\227\320\260 \321\206\321\226\320\275\320\276\321\216 (\321\201\320\277\320\260\320\264\320\260\320\275\320\275\321\217)", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("OperationsWindow", "\320\241\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217 \320\267\320\260 \320\277\320\276\321\202\321\203\320\266\320\275\321\226\321\201\321\202\321\216", nullptr));
        sortPowerAscButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\274 \320\227\320\260 \320\277\320\276\321\202\321\203\320\266\320\275\321\226\321\201\321\202\321\216 (\320\267\321\200\320\276\321\201\321\202\320\260\320\275\320\275\321\217)", nullptr));
        sortPowerDescButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\275 \320\227\320\260 \320\277\320\276\321\202\321\203\320\266\320\275\321\226\321\201\321\202\321\216 (\321\201\320\277\320\260\320\264\320\260\320\275\320\275\321\217)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(sortTab), QCoreApplication::translate("OperationsWindow", "\360\237\223\212 \320\241\320\276\321\200\321\202\321\203\320\262\320\260\320\275\320\275\321\217", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("OperationsWindow", "\320\237\320\276\321\210\321\203\320\272", nullptr));
        findBrandButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\224\216 \320\235\320\260\320\271\320\264\320\265\321\210\320\265\320\262\321\210\320\260 + \320\275\320\260\320\271\320\274\320\265\320\275\321\210 \320\277\320\276\321\202\321\203\320\266\320\275\320\260 (\320\267\320\260 \320\274\320\260\321\200\320\272\320\276\321\216)", nullptr));
        priceRangeButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\223\210 \320\221\321\200\320\265\320\275\320\264\320\270 \320\262 \320\264\321\226\320\260\320\277\320\260\320\267\320\276\320\275\321\226 \321\206\321\226\320\275", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("OperationsWindow", "\320\220\320\275\320\260\320\273\321\226\320\267 \320\264\320\260\320\275\320\270\321\205", nullptr));
        samePriceDiffColorButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\216\250 \320\234\320\260\321\200\320\272\320\270: \320\276\320\264\320\275\320\260\320\272\320\276\320\262\320\260 \321\206\321\226\320\275\320\260, \321\200\321\226\320\267\320\275\321\226 \320\272\320\276\320\273\321\214\320\276\321\200\320\270", nullptr));
        brandColorQueriesButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\232\227 \320\224\320\273\321\217 \320\272\320\276\320\266\320\275\320\276\321\227 \320\274\320\260\321\200\320\272\320\270: \321\207\320\265\321\200\320\262\320\276\320\275\320\260 \320\275\320\260\320\271\320\277\320\276\321\202\321\203\320\266\320\275\321\226\321\210\320\260 & \321\207\320\276\321\200\320\275\320\260 \320\275\320\260\320\271\320\264\320\265\321\210\320\265\320\262\321\210\320\260", nullptr));
        colorMinMaxButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\222\260 \320\224\320\273\321\217 \320\272\320\276\320\266\320\275\320\276\320\263\320\276 \320\272\320\276\320\273\321\214\320\276\321\200\321\203: min & max \321\206\321\226\320\275\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(searchTab), QCoreApplication::translate("OperationsWindow", "\360\237\224\215 \320\237\320\276\321\210\321\203\320\272 \321\202\320\260 \320\260\320\275\320\260\320\273\321\226\320\267", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("OperationsWindow", "\360\237\223\213 \320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\270 \320\276\320\277\320\265\321\200\320\260\321\206\321\226\320\271", nullptr));
        clearResultsButton->setText(QCoreApplication::translate("OperationsWindow", "\360\237\247\271 \320\236\321\207\320\270\321\201\321\202\320\270\321\202\320\270 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\270", nullptr));
        closeButton->setText(QCoreApplication::translate("OperationsWindow", "\342\234\205 \320\227\320\260\320\272\321\200\320\270\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperationsWindow: public Ui_OperationsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATIONSWINDOW_H
