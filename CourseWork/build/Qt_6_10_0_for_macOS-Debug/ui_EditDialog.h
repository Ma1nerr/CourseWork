/********************************************************************************
** Form generated from reading UI file 'EditDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelBrand;
    QLineEdit *brandEdit;
    QLabel *labelColor;
    QLineEdit *colorEdit;
    QLabel *labelPrice;
    QLineEdit *priceEdit;
    QLabel *labelPower;
    QLineEdit *powerEdit;
    QHBoxLayout *hButtons;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(360, 220);
        verticalLayout = new QVBoxLayout(EditDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        labelBrand = new QLabel(EditDialog);
        labelBrand->setObjectName("labelBrand");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, labelBrand);

        brandEdit = new QLineEdit(EditDialog);
        brandEdit->setObjectName("brandEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, brandEdit);

        labelColor = new QLabel(EditDialog);
        labelColor->setObjectName("labelColor");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, labelColor);

        colorEdit = new QLineEdit(EditDialog);
        colorEdit->setObjectName("colorEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, colorEdit);

        labelPrice = new QLabel(EditDialog);
        labelPrice->setObjectName("labelPrice");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, labelPrice);

        priceEdit = new QLineEdit(EditDialog);
        priceEdit->setObjectName("priceEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, priceEdit);

        labelPower = new QLabel(EditDialog);
        labelPower->setObjectName("labelPower");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, labelPower);

        powerEdit = new QLineEdit(EditDialog);
        powerEdit->setObjectName("powerEdit");

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, powerEdit);


        verticalLayout->addLayout(formLayout);

        hButtons = new QHBoxLayout();
        hButtons->setObjectName("hButtons");
        okButton = new QPushButton(EditDialog);
        okButton->setObjectName("okButton");

        hButtons->addWidget(okButton);

        cancelButton = new QPushButton(EditDialog);
        cancelButton->setObjectName("cancelButton");

        hButtons->addWidget(cancelButton);


        verticalLayout->addLayout(hButtons);


        retranslateUi(EditDialog);

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\321\202\320\270 \320\260\320\262\321\202\320\276\320\274\320\276\320\261\321\226\320\273\321\214", nullptr));
        labelBrand->setText(QCoreApplication::translate("EditDialog", "\320\234\320\260\321\200\320\272\320\260", nullptr));
        labelColor->setText(QCoreApplication::translate("EditDialog", "\320\232\320\276\320\273\321\226\321\200", nullptr));
        labelPrice->setText(QCoreApplication::translate("EditDialog", "\320\246\321\226\320\275\320\260", nullptr));
        labelPower->setText(QCoreApplication::translate("EditDialog", "\320\237\320\276\321\202\321\203\320\266\320\275\321\226\321\201\321\202\321\214", nullptr));
        okButton->setText(QCoreApplication::translate("EditDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("EditDialog", "\320\241\320\272\320\260\321\201\321\203\320\262\320\260\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
