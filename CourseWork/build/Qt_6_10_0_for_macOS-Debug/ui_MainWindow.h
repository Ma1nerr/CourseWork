/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *topControls;
    QLineEdit *searchText;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *editButton;
    QPushButton *deleteButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *operationsButton;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        topControls = new QHBoxLayout();
        topControls->setObjectName("topControls");
        searchText = new QLineEdit(centralwidget);
        searchText->setObjectName("searchText");
        searchText->setMaximumSize(QSize(300, 16777215));

        topControls->addWidget(searchText);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topControls->addItem(horizontalSpacer);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        topControls->addWidget(addButton);

        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");

        topControls->addWidget(editButton);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");

        topControls->addWidget(deleteButton);

        loadButton = new QPushButton(centralwidget);
        loadButton->setObjectName("loadButton");

        topControls->addWidget(loadButton);

        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        topControls->addWidget(saveButton);

        operationsButton = new QPushButton(centralwidget);
        operationsButton->setObjectName("operationsButton");

        topControls->addWidget(operationsButton);


        verticalLayout->addLayout(topControls);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setAlternatingRowColors(true);

        verticalLayout->addWidget(tableWidget);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\226\320\262", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\342\236\225 \320\224\320\276\320\264\320\260\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        addButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\275\320\276\320\262\320\270\320\271 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        editButton->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 \320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        editButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \320\276\320\261\321\200\320\260\320\275\320\270\320\271 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 \320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        deleteButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\260\320\273\320\270\321\202\320\270 \320\276\320\261\321\200\320\260\320\275\320\270\320\271 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\214", nullptr));
#endif // QT_CONFIG(tooltip)
        loadButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\202 \320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        loadButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\262\320\260\320\275\321\202\320\260\320\266\320\270\321\202\320\270 \320\264\320\260\320\275\321\226 \320\267 \321\204\320\260\320\271\320\273\321\203", nullptr));
#endif // QT_CONFIG(tooltip)
        saveButton->setText(QCoreApplication::translate("MainWindow", "\360\237\222\276 \320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270", nullptr));
#if QT_CONFIG(tooltip)
        saveButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\264\320\260\320\275\321\226 \321\203 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(tooltip)
        operationsButton->setText(QCoreApplication::translate("MainWindow", "\342\232\231\357\270\217 \320\236\320\277\320\265\321\200\320\260\321\206\321\226\321\227", nullptr));
#if QT_CONFIG(tooltip)
        operationsButton->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\272\321\200\320\270\321\202\320\270 \320\262\321\226\320\272\320\275\320\276 \320\276\320\277\320\265\321\200\320\260\321\206\321\226\320\271 \320\267 \320\264\320\260\320\275\320\270\320\274\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
