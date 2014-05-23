/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *radioButton_Autoatique;
    QRadioButton *radioButton_Manuel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_browse;
    QLineEdit *lineEditConfigurationFilePath;
    QPlainTextEdit *textEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *textEdit_3;
    QPushButton *pushButton_mails;
    QHBoxLayout *horizontalLayout_30;
    QSpacerItem *horizontalSpacer_37;
    QPushButton *pushButton_saveAs;
    QPushButton *pushButton_run;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_aide;
    QSpacerItem *horizontalSpacer_10;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_14;
    QLineEdit *lineEdit_NomGroupe;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_15;
    QLineEdit *lineEdit_NbPersonnes;
    QSpacerItem *horizontalSpacer_24;
    QPushButton *pushButton_group;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_26;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_19;
    QHBoxLayout *horizontalLayout_49;
    QLabel *label_43;
    QLineEdit *lineEdit_prenom;
    QHBoxLayout *horizontalLayout_50;
    QLabel *label_44;
    QLineEdit *lineEdit_telephone;
    QHBoxLayout *horizontalLayout_51;
    QLabel *label_45;
    QLineEdit *lineEdit_depenses;
    QComboBox *comboBox_statut;
    QHBoxLayout *horizontalLayout_52;
    QLabel *label_46;
    QLineEdit *lineEdit_mail;
    QPushButton *pushButton_next;
    QPlainTextEdit *textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(928, 781);
        Widget->setMaximumSize(QSize(1677, 1000));
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        verticalLayout_2->addWidget(groupBox);

        radioButton_Autoatique = new QRadioButton(Widget);
        radioButton_Autoatique->setObjectName(QStringLiteral("radioButton_Autoatique"));

        verticalLayout_2->addWidget(radioButton_Autoatique);

        radioButton_Manuel = new QRadioButton(Widget);
        radioButton_Manuel->setObjectName(QStringLiteral("radioButton_Manuel"));

        verticalLayout_2->addWidget(radioButton_Manuel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_browse = new QPushButton(Widget);
        pushButton_browse->setObjectName(QStringLiteral("pushButton_browse"));

        horizontalLayout_2->addWidget(pushButton_browse);

        lineEditConfigurationFilePath = new QLineEdit(Widget);
        lineEditConfigurationFilePath->setObjectName(QStringLiteral("lineEditConfigurationFilePath"));
        lineEditConfigurationFilePath->setEnabled(true);

        horizontalLayout_2->addWidget(lineEditConfigurationFilePath);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        textEdit_2 = new QPlainTextEdit(Widget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout_3->addWidget(textEdit_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textEdit_3 = new QPlainTextEdit(Widget);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));

        horizontalLayout_4->addWidget(textEdit_3);

        pushButton_mails = new QPushButton(Widget);
        pushButton_mails->setObjectName(QStringLiteral("pushButton_mails"));

        horizontalLayout_4->addWidget(pushButton_mails);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_37);

        pushButton_saveAs = new QPushButton(Widget);
        pushButton_saveAs->setObjectName(QStringLiteral("pushButton_saveAs"));

        horizontalLayout_30->addWidget(pushButton_saveAs);

        pushButton_run = new QPushButton(Widget);
        pushButton_run->setObjectName(QStringLiteral("pushButton_run"));

        horizontalLayout_30->addWidget(pushButton_run);

        pushButton_clear = new QPushButton(Widget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        horizontalLayout_30->addWidget(pushButton_clear);

        pushButton_aide = new QPushButton(Widget);
        pushButton_aide->setObjectName(QStringLiteral("pushButton_aide"));

        horizontalLayout_30->addWidget(pushButton_aide);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_30->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_30);


        horizontalLayout_5->addLayout(verticalLayout_3);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_7->addWidget(label_14);

        lineEdit_NomGroupe = new QLineEdit(groupBox_3);
        lineEdit_NomGroupe->setObjectName(QStringLiteral("lineEdit_NomGroupe"));

        horizontalLayout_7->addWidget(lineEdit_NomGroupe);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_17->addWidget(label_15);

        lineEdit_NbPersonnes = new QLineEdit(groupBox_3);
        lineEdit_NbPersonnes->setObjectName(QStringLiteral("lineEdit_NbPersonnes"));

        horizontalLayout_17->addWidget(lineEdit_NbPersonnes);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_24);


        verticalLayout->addLayout(horizontalLayout_17);

        pushButton_group = new QPushButton(groupBox_3);
        pushButton_group->setObjectName(QStringLiteral("pushButton_group"));

        verticalLayout->addWidget(pushButton_group);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_25);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_26);

        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(4000, 16777215));
        horizontalLayout_3 = new QHBoxLayout(groupBox_6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setSpacing(6);
        horizontalLayout_49->setObjectName(QStringLiteral("horizontalLayout_49"));
        label_43 = new QLabel(groupBox_6);
        label_43->setObjectName(QStringLiteral("label_43"));

        horizontalLayout_49->addWidget(label_43);

        lineEdit_prenom = new QLineEdit(groupBox_6);
        lineEdit_prenom->setObjectName(QStringLiteral("lineEdit_prenom"));

        horizontalLayout_49->addWidget(lineEdit_prenom);


        verticalLayout_19->addLayout(horizontalLayout_49);

        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setSpacing(6);
        horizontalLayout_50->setObjectName(QStringLiteral("horizontalLayout_50"));
        label_44 = new QLabel(groupBox_6);
        label_44->setObjectName(QStringLiteral("label_44"));

        horizontalLayout_50->addWidget(label_44);

        lineEdit_telephone = new QLineEdit(groupBox_6);
        lineEdit_telephone->setObjectName(QStringLiteral("lineEdit_telephone"));

        horizontalLayout_50->addWidget(lineEdit_telephone);


        verticalLayout_19->addLayout(horizontalLayout_50);

        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setSpacing(6);
        horizontalLayout_51->setObjectName(QStringLiteral("horizontalLayout_51"));
        label_45 = new QLabel(groupBox_6);
        label_45->setObjectName(QStringLiteral("label_45"));

        horizontalLayout_51->addWidget(label_45);

        lineEdit_depenses = new QLineEdit(groupBox_6);
        lineEdit_depenses->setObjectName(QStringLiteral("lineEdit_depenses"));

        horizontalLayout_51->addWidget(lineEdit_depenses);


        verticalLayout_19->addLayout(horizontalLayout_51);

        comboBox_statut = new QComboBox(groupBox_6);
        comboBox_statut->setObjectName(QStringLiteral("comboBox_statut"));

        verticalLayout_19->addWidget(comboBox_statut);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(6);
        horizontalLayout_52->setObjectName(QStringLiteral("horizontalLayout_52"));
        label_46 = new QLabel(groupBox_6);
        label_46->setObjectName(QStringLiteral("label_46"));

        horizontalLayout_52->addWidget(label_46);

        lineEdit_mail = new QLineEdit(groupBox_6);
        lineEdit_mail->setObjectName(QStringLiteral("lineEdit_mail"));

        horizontalLayout_52->addWidget(lineEdit_mail);


        verticalLayout_19->addLayout(horizontalLayout_52);


        horizontalLayout_3->addLayout(verticalLayout_19);


        verticalLayout->addWidget(groupBox_6);

        pushButton_next = new QPushButton(groupBox_3);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));

        verticalLayout->addWidget(pushButton_next);

        pushButton_group->raise();
        groupBox_6->raise();
        pushButton_next->raise();

        horizontalLayout_5->addWidget(groupBox_3);


        verticalLayout_4->addLayout(horizontalLayout_5);

        textEdit = new QPlainTextEdit(Widget);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_4->addWidget(textEdit);


        gridLayout_2->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Friends Expenses", 0));
        groupBox->setTitle(QApplication::translate("Widget", "Mode", 0));
        radioButton_Autoatique->setText(QApplication::translate("Widget", "Automatique", 0));
        radioButton_Manuel->setText(QApplication::translate("Widget", "Manuel", 0));
        pushButton_browse->setText(QApplication::translate("Widget", "Ouvrir", 0));
        pushButton_mails->setText(QApplication::translate("Widget", "Envoi mails", 0));
        pushButton_saveAs->setText(QApplication::translate("Widget", "Sauvegarder", 0));
        pushButton_run->setText(QApplication::translate("Widget", "D\303\251marrer", 0));
        pushButton_clear->setText(QApplication::translate("Widget", "Effacer", 0));
        pushButton_aide->setText(QApplication::translate("Widget", "Aide", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "Groupe ", 0));
        label_14->setText(QApplication::translate("Widget", "Nom du groupe*", 0));
        label_15->setText(QApplication::translate("Widget", "Nombre de personne dans le groupe*", 0));
        pushButton_group->setText(QApplication::translate("Widget", "OK", 0));
        groupBox_6->setTitle(QApplication::translate("Widget", "Personne", 0));
        label_43->setText(QApplication::translate("Widget", "Pr\303\251nom*", 0));
        label_44->setText(QApplication::translate("Widget", "T\303\251l\303\251phone", 0));
        label_45->setText(QApplication::translate("Widget", "D\303\251penses*", 0));
        comboBox_statut->clear();
        comboBox_statut->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Membre", 0)
         << QApplication::translate("Widget", "Donnateur", 0)
        );
#ifndef QT_NO_TOOLTIP
        comboBox_statut->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_46->setText(QApplication::translate("Widget", "E-Mail", 0));
        pushButton_next->setText(QApplication::translate("Widget", "Suivant", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
