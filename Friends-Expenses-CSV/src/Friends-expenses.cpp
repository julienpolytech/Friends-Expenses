//============================================================================
// Name        : main.cpp
// Author      : Salim
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"
#include "mailsender.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <cstdlib>
#include <iomanip>
#include <QPushButton>
#include <QFile>
#include <QList>
#include <QString>
#include <QRadioButton>
#include <QMessageBox>

#include <QFileDialog>

#include "Friends-expenses.hpp"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString title = QString("");
    title = "Friends Expenses v1.0";
    setWindowTitle( title );

    connect(ui->PushButton_run, SIGNAL(clicked()), this, SLOT(FriendsExpenses()));
    connect(ui->pushButton_browse, SIGNAL(clicked()), this, SLOT(Browse()));
    connect(ui->radioButton_Autoatique, SIGNAL(clicked()), this, SLOT(Automatic()));
    connect(ui->radioButton_Manuel, SIGNAL(clicked()), this, SLOT(Manual()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(Clear()));

}

Widget::~Widget()
{
    delete ui;
}


using namespace std;

vector<Group> Groups; // creation du groupe de groupes

void Widget::Clear(){

    ui->textEdit->clear();
    ui->lineEditConfigurationFilePath->clear();
    ui->lineEditConfigurationFilePath->setEnabled(true);
    ui->lineEdit_depenses1->setEnabled(true);
    ui->lineEdit_depenses1->clear();
    ui->lineEdit_depenses2->setEnabled(true);
    ui->lineEdit_depenses2->clear();
    ui->lineEdit_depenses3->setEnabled(true);
    ui->lineEdit_depenses3->clear();
    ui->lineEdit_depenses4->setEnabled(true);
    ui->lineEdit_depenses4->clear();
    ui->lineEdit_mail1->setEnabled(true);
    ui->lineEdit_mail1->clear();
    ui->lineEdit_mail2->setEnabled(true);
    ui->lineEdit_mail2->clear();
    ui->lineEdit_mail3->setEnabled(true);
    ui->lineEdit_mail3->clear();
    ui->lineEdit_mail4->setEnabled(true);
    ui->lineEdit_mail4->clear();
    ui->lineEdit_Telephone1->setEnabled(true);
    ui->lineEdit_Telephone1->clear();
    ui->lineEdit_Telephone2->setEnabled(true);
    ui->lineEdit_Telephone2->clear();
    ui->lineEdit_Telephone3->setEnabled(true);
    ui->lineEdit_Telephone3->clear();
    ui->lineEdit_Telephone4->setEnabled(true);
    ui->lineEdit_Telephone4->clear();
    ui->lineEdit_Prenom1->setEnabled(true);
    ui->lineEdit_Prenom1->clear();
    ui->lineEdit_Prenom2->setEnabled(true);
    ui->lineEdit_Prenom2->clear();
    ui->lineEdit_Prenom3->setEnabled(true);
    ui->lineEdit_Prenom3->clear();
    ui->lineEdit_Prenom4->setEnabled(true);
    ui->lineEdit_Prenom4->clear();
    ui->lineEdit_DPrenom1->setEnabled(true);
    ui->lineEdit_DPrenom1->clear();
    ui->lineEdit_DTelephone1->setEnabled(true);
    ui->lineEdit_DTelephone1->clear();
    ui->lineEdit_DDon1->setEnabled(true);
    ui->lineEdit_DDon1->clear();
    ui->lineEdit_DMail1->setEnabled(true);
    ui->lineEdit_DMail1->clear();
    ui->lineEdit_DPrenom2->setEnabled(true);
    ui->lineEdit_DPrenom2->clear();
    ui->lineEdit_DTelephone2->setEnabled(true);
    ui->lineEdit_DTelephone2->clear();
    ui->lineEdit_DDon2->setEnabled(true);
    ui->lineEdit_DDon2->clear();
    ui->lineEdit_DMail2->setEnabled(true);
    ui->lineEdit_DMail2->clear();
    ui->lineEdit_DPrenom1->setEnabled(true);

    ui->lineEdit_Nombre_de_personnes->setEnabled(true);
    ui->lineEdit_Nombre_de_personnes->clear();

    ui->lineEdit_NomGroupe->setEnabled(true);
    ui->lineEdit_NomGroupe->clear();

    ui->pushButton_browse->setEnabled(1);
    ui->pushButton_saveAs->setEnabled(1);
    ui->radioButton_Donateur1->setEnabled(1); // PAS GRISER
    ui->radioButton_Donateur2->setEnabled(1);

    ui->radioButton_Manuel->setEnabled(1);
    ui->radioButton_Autoatique->setEnabled(1);


    ui->radioButton_Donateur1->setChecked(false); // pas checker
    ui->radioButton_Donateur2->setChecked(false);
    ui->radioButton_Autoatique->setChecked(false);
    ui->radioButton_Manuel->setChecked(false);
    ui->radioButton_Mail->setChecked(false);
}


void Widget::Automatic()
{
    ui->lineEditConfigurationFilePath->setEnabled(true);
    ui->lineEdit_depenses1->setEnabled(false);
    ui->lineEdit_depenses2->setEnabled(false);
    ui->lineEdit_depenses3->setEnabled(false);
    ui->lineEdit_depenses4->setEnabled(false);
    ui->lineEdit_mail1->setEnabled(false);
    ui->lineEdit_mail2->setEnabled(false);
    ui->lineEdit_mail3->setEnabled(false);
    ui->lineEdit_mail4->setEnabled(false);
    ui->lineEdit_Telephone1->setEnabled(false);
    ui->lineEdit_Telephone2->setEnabled(false);
    ui->lineEdit_Telephone3->setEnabled(false);
    ui->lineEdit_Telephone4->setEnabled(false);
    ui->lineEdit_Prenom1->setEnabled(false);
    ui->lineEdit_Prenom2->setEnabled(false);
    ui->lineEdit_Prenom3->setEnabled(false);
    ui->lineEdit_Prenom4->setEnabled(false);
    ui->lineEdit_DPrenom1->setEnabled(false);
    ui->lineEdit_DTelephone1->setEnabled(false);
    ui->lineEdit_DDon1->setEnabled(false);
    ui->lineEdit_DMail1->setEnabled(false);
    ui->lineEdit_DPrenom2->setEnabled(false);
    ui->lineEdit_DTelephone2->setEnabled(false);
    ui->lineEdit_DDon2->setEnabled(false);
    ui->lineEdit_DMail2->setEnabled(false);
    ui->lineEdit_DPrenom1->setEnabled(false);
    ui->lineEdit_DTelephone1->setEnabled(false);
    ui->lineEdit_DDon1->setEnabled(false);
    ui->lineEdit_NomGroupe->setEnabled(false);
    ui->lineEdit_Nombre_de_personnes->setEnabled(false);
    ui->radioButton_Donateur1->setEnabled(0);
    ui->radioButton_Donateur2->setEnabled(0);
    ui->pushButton_browse->setEnabled(1);
    ui->pushButton_saveAs->setEnabled(0);

    return;
}

void Widget::Manual()
{
    ui->lineEditConfigurationFilePath->setEnabled(false);
    ui->lineEdit_depenses1->setEnabled(true);
    ui->lineEdit_depenses2->setEnabled(true);
    ui->lineEdit_depenses3->setEnabled(true);
    ui->lineEdit_depenses4->setEnabled(true);
    ui->lineEdit_mail1->setEnabled(true);
    ui->lineEdit_mail2->setEnabled(true);
    ui->lineEdit_mail3->setEnabled(true);
    ui->lineEdit_mail4->setEnabled(true);
    ui->lineEdit_Telephone1->setEnabled(true);
    ui->lineEdit_Telephone2->setEnabled(true);
    ui->lineEdit_Telephone3->setEnabled(true);
    ui->lineEdit_Telephone4->setEnabled(true);
    ui->lineEdit_Prenom1->setEnabled(true);
    ui->lineEdit_Prenom2->setEnabled(true);
    ui->lineEdit_Prenom3->setEnabled(true);
    ui->lineEdit_Prenom4->setEnabled(true);
    ui->lineEdit_DPrenom1->setEnabled(true);
    ui->lineEdit_DTelephone1->setEnabled(true);
    ui->lineEdit_DDon1->setEnabled(true);
    ui->lineEdit_DMail1->setEnabled(true);
    ui->lineEdit_DPrenom2->setEnabled(true);
    ui->lineEdit_DTelephone2->setEnabled(true);
    ui->lineEdit_DDon2->setEnabled(true);
    ui->lineEdit_DMail2->setEnabled(true);
    ui->lineEdit_DPrenom1->setEnabled(true);
    ui->lineEdit_DTelephone1->setEnabled(true);
    ui->lineEdit_DDon1->setEnabled(true);
    ui->lineEdit_NomGroupe->setEnabled(true);
    ui->lineEdit_Nombre_de_personnes->setEnabled(true);
    ui->radioButton_Donateur1->setEnabled(1);
    ui->radioButton_Donateur2->setEnabled(1);
    ui->pushButton_browse->setEnabled(0);
    ui->pushButton_saveAs->setEnabled(1);

    return;
}


void Widget::Browse()
{

    QString configurationFile = QFileDialog::getOpenFileName(this,
                                                             "Open configuration file to proceed",
                                                             QDir::currentPath(),
                                                             "file (*.csv)");

    if ( !configurationFile.isEmpty() )
    {

        QFileInfo fileinfo( configurationFile);

        ui->lineEditConfigurationFilePath->setText( configurationFile);
        m_configurationFilePath = configurationFile;


        ui->textEdit->appendPlainText( "" );
        ui->textEdit->appendPlainText( "Selected configuration file: " );
        ui->textEdit->appendPlainText( m_configurationFilePath );

    }


    c= m_configurationFilePath.toStdString().c_str();
    ifstream filecsv(c); // ouverture du fichier

    if (!filecsv){ // Le fichier demande n'est pas trouve
        ui->textEdit->appendPlainText("Error opening");
        return;
    }


    string temp,line;
    vector <string> tableau;

    getline(filecsv, line); // recupere la 1ere ligne du fichier

    stringstream ss(line);

    while(getline(ss, temp, ',')){ // decompose les diferente cases de la ligne
        tableau.push_back(temp);
    }

    int aname,aphone,aexpense,agname;
    int i=0;

    for (vector<string>::iterator it = tableau.begin() ; it != tableau.end(); ++it)// Je verifie l'ordre des éléments
    {

        if (it->compare("Name") == 0){
            aname = i;
        }
        if (it->compare("Phone Number") == 0){
            aphone = i;
        }
        if (it->compare("Expenses") == 0){
            aexpense = i;
        }
        if (it->compare("Group Name") == 0){
            agname = i;
        }

        i++;
    }



    while (1){ // tant que mon fichier .csv n'est pas fini

        vector <string> person;

        getline(filecsv, line); // recupere une ligne du fichier

        stringstream ss(line);

        if ( filecsv.eof() )
        {
            break;
        }

        while(getline(ss, temp, ',')){ // decompose les diferente cases de la ligne
            person.push_back(temp);
        }


        float expen = atof((char*)person[aexpense].c_str()); // string to float pour les depenses


        bool GroupEx = 0;

        for (vector<Group>::iterator it = Groups.begin() ; it != Groups.end(); ++it)// Je test si mon groupe existe deja
        {
            if(person[agname].compare(it->getName()) == 0){ // Est ce que le nom du groupe correspond

                GroupEx = 1;
                Person aPerson(person[aname],person[aphone],expen,&*it); // creation de ma personne
                it->push_back(aPerson);
                it->setNbPers(((it->getNbPers()) + 1));
                break;
            }

        }

        if (!GroupEx){ // Si le groupe n'existait pas

            Person aPerson(person[aname],person[aphone],expen);
            Group aGroup(person[agname]); // On creait le nouveau groupe
            aGroup.push_back(aPerson); // On y insert la personne
            aGroup[0].setLink(&aGroup); // On ajoute le pointeur du groupe qu'on a cree
            Groups.push_back(aGroup); // On ajoute notre groupe a notre vecteur de groupe
        }


    }

    filecsv.close();


    return;
}



int Widget::FriendsExpenses() {


    /********************************************************
     ****************  En mode automatique ! ****************
     ********************************************************/

    if(ui->radioButton_Autoatique->isChecked())
    {
        if(ui->lineEditConfigurationFilePath->text() != "")
        {
            ui->textEdit->appendPlainText("");


            /*
             *  Prepare the output
             */

            for (vector<Group>::iterator it = Groups.begin() ; it != Groups.end(); ++it)
            {

                ui->textEdit->appendPlainText("-----------------------------------");

                const string name = it->getName();
                QString QName = QString(name.c_str());
                ui->textEdit->appendPlainText(QString("Nom du groupe : ") + QName);

                float Total_expenses = it->totalExpenses();
                QString QTotal_expenses;
                QTotal_expenses.setNum(Total_expenses);
                ui->textEdit->appendPlainText(QString("Depenses totales : ") + QTotal_expenses);

                float Expenses_per_person = it->expensesPerPerson();
                QString QExpenses_per_person;
                QExpenses_per_person.setNum(Expenses_per_person);
                ui->textEdit->appendPlainText(QString("Depenses par personnes : ") + QExpenses_per_person);
                ui->textEdit->appendPlainText("");

                Group tmpGroup = *it;
                for (size_t i=0; i < tmpGroup.size(); ++i)
                {
                    // operate the payback first
                    tmpGroup[i].operatePayback(tmpGroup.expensesPerPerson());
                    // display the values

                    string Name;
                    Name = tmpGroup[i].getName();
                    QString QName = QString(Name.c_str());
                    ui->textEdit->appendPlainText(QString("Nom : ") + QName);

                    string Num;
                    Num = tmpGroup[i].getPhone();
                    QString QNum = QString(Num.c_str());
                    ui->textEdit->appendPlainText(QString("Numero : ") + QNum);

                    float Expenses;
                    Expenses = tmpGroup[i].getExpenses();
                    QString QExpenses;
                    QExpenses.setNum(Expenses);
                    ui->textEdit->appendPlainText(QString("Depenses : ") + QExpenses + " euros");

                    float Payback;
                    Payback = tmpGroup[i].getPayback();
                    QString QPayback;
                    QPayback.setNum(Payback);
                    ui->textEdit->appendPlainText(QString("Dette : ") + QPayback + " euros");

                    ui->textEdit->appendPlainText("");
                }
            }
        }
        else{
            ui->textEdit->appendPlainText("Selectionne un fichier");
        }
    }

    /********************************************************
     *********************  En mode manuel ! ****************
     ********************************************************/

    else if (ui->radioButton_Manuel->isChecked())
    {
        if (ui->lineEdit_Nombre_de_personnes->text() != ""){

            /*
         *  Recuperation des QString
         */
            QString NbrePersonnes = ui->lineEdit_Nombre_de_personnes->text();
            float fNbrePersonnes = NbrePersonnes.toFloat();

            /* on check ce qu'on donne les donateur */

            float fDonTotal;


            if(ui->radioButton_Donateur1->isChecked() && ui->radioButton_Donateur2->isChecked())
            {
                if(ui->lineEdit_DPrenom1->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom doneur1 a renseigner.\n"));
                }

                else if(ui->lineEdit_DPrenom2->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom doneur2 a renseigner.\n"));
                }

                else{
                    if(ui->lineEdit_DDon1->text() == ""){
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Montant don1 a renseigner.\n"));
                    }

                    else if(ui->lineEdit_DDon2->text() == ""){
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Montant don2 a renseigner.\n"));
                    }
                    else
                    {


                        QString DPrenom1 = ui->lineEdit_DPrenom1->text();
                        QString DTelephone1 = ui->lineEdit_DTelephone1->text();
                        QString Don1 = ui->lineEdit_DDon1->text();
                        QString DMail1 = ui->lineEdit_DMail1->text();

                        QString DPrenom2 = ui->lineEdit_DPrenom2->text();
                        QString DTelephone2 = ui->lineEdit_DTelephone2->text();
                        QString Don2 = ui->lineEdit_DDon2->text();
                        QString DMail2 = ui->lineEdit_DMail2->text();

                        float fDon1 = Don1.toFloat();
                        float fDon2 = Don2.toFloat();

                        fDonTotal = fDon1 + fDon2;
                    }
                }
            }
            else if(ui->radioButton_Donateur1->isChecked())
            {
                if(ui->lineEdit_DPrenom1->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom doneur1 a renseigner.\n"));
                }
                else
                {
                    if(ui->lineEdit_DDon1->text() == ""){
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Montant don1 a renseigner.\n"));
                    }
                    else{
                        ui->radioButton_Donateur2->setEnabled(0);
                        ui->lineEdit_DPrenom2->setEnabled(false);
                        ui->lineEdit_DTelephone2->setEnabled(false);
                        ui->lineEdit_DDon2->setEnabled(false);
                        ui->lineEdit_DMail2->setEnabled(false);

                        QString DPrenom1 = ui->lineEdit_DPrenom1->text();
                        QString DTelephone1 = ui->lineEdit_DTelephone1->text();
                        QString Don1 = ui->lineEdit_DDon1->text();
                        QString DMail1 = ui->lineEdit_DMail1->text();

                        fDonTotal = Don1.toFloat();

                    }
                }
            }
            else if(ui->radioButton_Donateur2->isChecked())
            {
                if(ui->lineEdit_DPrenom2->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom doneur2 a renseigner.\n"));
                }
                else
                {
                    if(ui->lineEdit_DDon2->text() == ""){
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Montant don2 a renseigner.\n"));
                    }
                    else{
                        ui->radioButton_Donateur1->setEnabled(0);
                        ui->lineEdit_DPrenom1->setEnabled(false);
                        ui->lineEdit_DTelephone1->setEnabled(false);
                        ui->lineEdit_DDon1->setEnabled(false);
                        ui->lineEdit_DMail1->setEnabled(false);

                        QString DPrenom2 = ui->lineEdit_DPrenom2->text();
                        QString DTelephone2 = ui->lineEdit_DTelephone2->text();
                        QString Don2 = ui->lineEdit_DDon2->text();
                        QString DMail2 = ui->lineEdit_DMail2->text();

                        fDonTotal = Don2.toFloat();

                    }
                }

            }
            else
            {

                fDonTotal = 0;

            }

            if (NbrePersonnes == "2"){



                if(ui->lineEdit_Prenom1->text() == "")
                {
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom1 a renseigner.\n"));
                }
                else if(ui->lineEdit_Prenom2->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom2 a renseigner.\n"));
                }
                else{

                    if(ui->lineEdit_depenses1->text() == "")
                    {
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Depense1 a renseigner.\n"));
                    }
                    else if (ui->lineEdit_depenses2->text() == "")
                    {
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Depense2 a renseigner.\n"));
                    }
                    else
                    {
                        ui->lineEdit_Prenom3->setEnabled(false);
                        ui->lineEdit_Telephone3->setEnabled(false);
                        ui->lineEdit_depenses3->setEnabled(false);
                        ui->lineEdit_mail3->setEnabled(false);

                        ui->lineEdit_Prenom4->setEnabled(false);
                        ui->lineEdit_Telephone4->setEnabled(false);
                        ui->lineEdit_depenses4->setEnabled(false);
                        ui->lineEdit_mail4->setEnabled(false);


                        /*recuperation des infos*/

                        QString GroupName = ui->lineEdit_NomGroupe->text();

                        QString Prenom1 = ui->lineEdit_Prenom1->text();
                        QString Expenses1 = ui->lineEdit_depenses1->text();
                        QString Telephone1 = ui->lineEdit_Telephone1->text();
                        QString Mail1 = ui->lineEdit_mail1->text();

                        QString Prenom2 = ui->lineEdit_Prenom2->text();
                        QString Telephone2 = ui->lineEdit_Telephone2->text();
                        QString Expenses2 = ui->lineEdit_depenses2->text();
                        QString Mail2 = ui->lineEdit_mail2->text();

                        /*calcul des dettes*/

                        float fExpenses1 = Expenses1.toFloat();
                        float fExpenses2 = Expenses2.toFloat();


                        float fDette = (fExpenses1 + fExpenses2 - fDonTotal) / fNbrePersonnes;
                        QString Dette;
                        Dette.setNum(fDette);

                        float fDette1 = fDette - fExpenses1;
                        QString Dette1;
                        Dette1.setNum(fDette1);

                        float fDette2 = fDette - fExpenses2;
                        QString Dette2;
                        Dette2.setNum(fDette2);

                        /*display*/

                        ui->textEdit->appendPlainText("-----------------------------------");

                        ui->textEdit->appendPlainText(GroupName);
                        ui->textEdit->appendPlainText("Depenses par personnes : " + QString(Dette) + " euros");

                        ui->textEdit->appendPlainText("");

                        if(ui->lineEdit_Telephone1->text() == ""){
                            Telephone1 = "Non renseigne";
                            ui->lineEdit_Telephone1->setText("Non renseigne");
                        }

                        if(ui->lineEdit_mail1->text() == ""){
                            Mail1 = "Non renseigne";
                            ui->lineEdit_mail1->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom1));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone1));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses1));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail1));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette1) + " euros");

                        ui->textEdit->appendPlainText("");


                        if(ui->lineEdit_Telephone2->text() == ""){
                            Telephone2 = "Non renseigne";
                            ui->lineEdit_Telephone2->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail2->text() == ""){
                            Mail2 = "Non renseigne";
                            ui->lineEdit_mail2->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom2));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone2));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses2));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail2));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette2) + " euros");

                        if(fDonTotal == 0){

                            ui->radioButton_Donateur1->setEnabled(0);
                            ui->lineEdit_DPrenom1->setEnabled(false);
                            ui->lineEdit_DTelephone1->setEnabled(false);
                            ui->lineEdit_DDon1->setEnabled(false);
                            ui->lineEdit_DMail1->setEnabled(false);

                            ui->radioButton_Donateur2->setEnabled(0);
                            ui->lineEdit_DPrenom2->setEnabled(false);
                            ui->lineEdit_DTelephone2->setEnabled(false);
                            ui->lineEdit_DDon2->setEnabled(false);
                            ui->lineEdit_DMail2->setEnabled(false);
                        }
                        ui->textEdit->appendPlainText("");
                    }
                }
            }
            else if (NbrePersonnes == "3"){


                if(ui->lineEdit_Prenom1->text() == "")
                                   {
                                       QMessageBox::warning(this, tr("Champs vide"),
                                                            tr("Prenom1 a renseigner.\n"));
                                   }
                                   else if (ui->lineEdit_Prenom2->text() == "")
                                   {
                                       QMessageBox::warning(this, tr("Champs vide"),
                                                            tr("Prenom2 a renseigner.\n"));
                                   }
                                   else if(ui->lineEdit_Prenom3->text() == ""){
                                       QMessageBox::warning(this, tr("Champs vide"),
                                                            tr("Prenom3 a renseigner.\n"));
                                   }

                else{

                    if(ui->lineEdit_depenses1->text() == "")
                    {
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Depense1 a renseigner.\n"));
                    }
                    else if(ui->lineEdit_depenses2->text() == ""){
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Depense2 a renseigner.\n"));
                    }
                    else if(ui->lineEdit_depenses3->text() == ""){
                        QMessageBox::warning(this, tr("Champs vide"),
                                             tr("Depense3 a renseigner.\n"));
                    }
                    else
                    {
                        ui->lineEdit_Prenom4->setEnabled(false);
                        ui->lineEdit_Telephone4->setEnabled(false);
                        ui->lineEdit_depenses4->setEnabled(false);
                        ui->lineEdit_mail4->setEnabled(false);


                        /*recuperation des infos*/

                        QString GroupName = ui->lineEdit_NomGroupe->text();

                        QString Prenom1 = ui->lineEdit_Prenom1->text();
                        QString Expenses1 = ui->lineEdit_depenses1->text();
                        QString Telephone1 = ui->lineEdit_Telephone1->text();
                        QString Mail1 = ui->lineEdit_mail1->text();

                        QString Prenom2 = ui->lineEdit_Prenom2->text();
                        QString Telephone2 = ui->lineEdit_Telephone2->text();
                        QString Expenses2 = ui->lineEdit_depenses2->text();
                        QString Mail2 = ui->lineEdit_mail2->text();

                        QString Prenom3 = ui->lineEdit_Prenom3->text();
                        QString Expenses3 = ui->lineEdit_depenses3->text();
                        QString Telephone3 = ui->lineEdit_Telephone3->text();
                        QString Mail3 = ui->lineEdit_mail3->text();


                        /*calcul des dettes*/

                        float fExpenses1 = Expenses1.toFloat();
                        float fExpenses2 = Expenses2.toFloat();
                        float fExpenses3 = Expenses3.toFloat();

                        float fDette = (fExpenses1 + fExpenses2 + fExpenses3 - fDonTotal) / fNbrePersonnes;
                        QString Dette;
                        Dette.setNum(fDette);

                        float fDette1 = fDette - fExpenses1;
                        QString Dette1;
                        Dette1.setNum(fDette1);

                        float fDette2 = fDette - fExpenses2;
                        QString Dette2;
                        Dette2.setNum(fDette2);


                        float fDette3 = fDette - fExpenses3;
                        QString Dette3;
                        Dette3.setNum(fDette3);

                        /*display*/

                        ui->textEdit->appendPlainText("-----------------------------------");

                        ui->textEdit->appendPlainText(GroupName);
                        ui->textEdit->appendPlainText("Depenses par personnes : " + QString(Dette) + " euros");

                        ui->textEdit->appendPlainText("");


                        if(ui->lineEdit_Telephone1->text() == ""){
                            Telephone1 = "Non renseigne";
                            ui->lineEdit_Telephone1->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail1->text() == ""){
                            Mail1 = "Non renseigne";
                            ui->lineEdit_mail1->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom1));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone1));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses1));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail1));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette1) + " euros");

                        ui->textEdit->appendPlainText("");

                        if(ui->lineEdit_Telephone2->text() == ""){
                            Telephone2 = "Non renseigne";
                            ui->lineEdit_Telephone2->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail2->text() == ""){
                            Mail2 = "Non renseigne";
                            ui->lineEdit_mail2->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom2));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone2));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses2));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail2));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette2) + " euros");

                        ui->textEdit->appendPlainText("");

                        if(ui->lineEdit_Telephone3->text() == ""){
                            Telephone3 = "Non renseigne";
                            ui->lineEdit_Telephone3->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail3->text() == ""){
                            Mail3 = "Non renseigne";
                            ui->lineEdit_mail3->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom3));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone3));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses3));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail3));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette3) + " euros");

                        if (fDonTotal == 0){
                            ui->radioButton_Donateur1->setEnabled(0);
                            ui->lineEdit_DPrenom1->setEnabled(false);
                            ui->lineEdit_DTelephone1->setEnabled(false);
                            ui->lineEdit_DDon1->setEnabled(false);
                            ui->lineEdit_DMail1->setEnabled(false);

                            ui->radioButton_Donateur2->setEnabled(0);
                            ui->lineEdit_DPrenom2->setEnabled(false);
                            ui->lineEdit_DTelephone2->setEnabled(false);
                            ui->lineEdit_DDon2->setEnabled(false);
                            ui->lineEdit_DMail2->setEnabled(false);
                        }

                        ui->textEdit->appendPlainText("");

                    }
                }
            }

            else if (NbrePersonnes == "4"){

                if(ui->lineEdit_Prenom1->text() == "")
                {
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom1 a renseigner.\n"));
                }
                else if (ui->lineEdit_Prenom2->text() == "")
                {
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom2 a renseigner.\n"));
                }
                else if(ui->lineEdit_Prenom3->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom3 a renseigner.\n"));

                }


                else if(ui->lineEdit_Prenom4->text() == ""){
                    QMessageBox::warning(this, tr("Champs vide"),
                                         tr("Prenom4 a renseigner.\n"));

                }
                else{

                    if(ui->lineEdit_depenses1->text() == "")
                 {
                     QMessageBox::warning(this, tr("Champs vide"),
                                          tr("Depense1 a renseigner.\n"));
                 }
                 else if(ui->lineEdit_depenses2->text() == ""){
                     QMessageBox::warning(this, tr("Champs vide"),
                                          tr("Depense2 a renseigner.\n"));
                 }
                 else if(ui->lineEdit_depenses3->text() == ""){
                     QMessageBox::warning(this, tr("Champs vide"),
                                          tr("Depense3 a renseigner.\n"));
                 }
                 else if(ui->lineEdit_depenses4->text() == ""){
                     QMessageBox::warning(this, tr("Champs vide"),
                                          tr("Depense4 a renseigner.\n"));
                 }

                    else
                    {


                        /*recuperation des infos*/

                        QString GroupName = ui->lineEdit_NomGroupe->text();

                        QString Prenom1 = ui->lineEdit_Prenom1->text();
                        QString Expenses1 = ui->lineEdit_depenses1->text();
                        QString Telephone1 = ui->lineEdit_Telephone1->text();
                        QString Mail1 = ui->lineEdit_mail1->text();

                        QString Prenom2 = ui->lineEdit_Prenom2->text();
                        QString Telephone2 = ui->lineEdit_Telephone2->text();
                        QString Expenses2 = ui->lineEdit_depenses2->text();
                        QString Mail2 = ui->lineEdit_mail2->text();

                        QString Prenom3 = ui->lineEdit_Prenom3->text();
                        QString Expenses3 = ui->lineEdit_depenses3->text();
                        QString Telephone3 = ui->lineEdit_Telephone3->text();
                        QString Mail3 = ui->lineEdit_mail3->text();

                        QString Prenom4 = ui->lineEdit_Prenom4->text();
                        QString Expenses4 = ui->lineEdit_depenses4->text();
                        QString Telephone4 = ui->lineEdit_Telephone4->text();
                        QString Mail4 = ui->lineEdit_mail4->text();


                        /*calcul des dettes*/

                        float fExpenses1 = Expenses1.toFloat();
                        float fExpenses2 = Expenses2.toFloat();
                        float fExpenses3 = Expenses3.toFloat();
                        float fExpenses4 = Expenses4.toFloat();

                        float fDette = (fExpenses1 + fExpenses2 + fExpenses3 + fExpenses4 - fDonTotal) / fNbrePersonnes;
                        QString Dette;
                        Dette.setNum(fDette);

                        float fDette1 = fDette - fExpenses1;
                        QString Dette1;
                        Dette1.setNum(fDette1);

                        float fDette2 = fDette - fExpenses2;
                        QString Dette2;
                        Dette2.setNum(fDette2);

                        float fDette3 = fDette - fExpenses3;
                        QString Dette3;
                        Dette3.setNum(fDette3);

                        float fDette4 = fDette - fExpenses4;
                        QString Dette4;
                        Dette4.setNum(fDette4);

                        /*display*/

                        ui->textEdit->appendPlainText("-----------------------------------");

                        ui->textEdit->appendPlainText(GroupName);
                        ui->textEdit->appendPlainText("Depenses par personnes : " + QString(Dette) + " euros");

                        ui->textEdit->appendPlainText("");


                        if(ui->lineEdit_Telephone1->text() == ""){
                            Telephone1 = "Non renseigne";
                            ui->lineEdit_Telephone1->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail1->text() == ""){
                            Mail1 = "Non renseigne";
                            ui->lineEdit_mail1->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom1));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone1));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses1));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail1));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette1) + " euros");

                        ui->textEdit->appendPlainText("");

                        if(ui->lineEdit_Telephone2->text() == ""){
                            Telephone2 = "Non renseigne";
                            ui->lineEdit_Telephone2->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail2->text() == ""){
                            Mail2 = "Non renseigne";
                            ui->lineEdit_mail2->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom2));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone2));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses2));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail2));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette2) + " euros");

                        ui->textEdit->appendPlainText("");

                        if(ui->lineEdit_Telephone3->text() == ""){
                            Telephone3 = "Non renseigne";
                            ui->lineEdit_Telephone3->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail3->text() == ""){
                            Mail3 = "Non renseigne";
                            ui->lineEdit_mail3->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom3));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone3));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses3));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail3));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette3) + " euros");

                        ui->textEdit->appendPlainText("");

                        if(ui->lineEdit_Telephone4->text() == ""){
                            Telephone4 = "Non renseigne";
                            ui->lineEdit_Telephone4->setText("Non renseigne");

                        }

                        if(ui->lineEdit_mail4->text() == ""){
                            Mail4 = "Non renseigne";
                            ui->lineEdit_mail4->setText("Non renseigne");
                        }

                        ui->textEdit->appendPlainText("Prenom : " + QString(Prenom4));
                        ui->textEdit->appendPlainText("Telephone : " + QString(Telephone4));
                        ui->textEdit->appendPlainText("Depenses : " + QString(Expenses4));
                        ui->textEdit->appendPlainText("Mail : " + QString(Mail4));
                        ui->textEdit->appendPlainText("Dette : " + QString(Dette4) + " euros");

                        if (fDonTotal == 0){
                            ui->radioButton_Donateur1->setEnabled(0);
                            ui->lineEdit_DPrenom1->setEnabled(false);
                            ui->lineEdit_DTelephone1->setEnabled(false);
                            ui->lineEdit_DDon1->setEnabled(false);
                            ui->lineEdit_DMail1->setEnabled(false);

                            ui->radioButton_Donateur2->setEnabled(0);
                            ui->lineEdit_DPrenom2->setEnabled(false);
                            ui->lineEdit_DTelephone2->setEnabled(false);
                            ui->lineEdit_DDon2->setEnabled(false);
                            ui->lineEdit_DMail2->setEnabled(false);
                        }

                        ui->textEdit->appendPlainText("");

                    }
                }

            }
            else{
                ui->textEdit->appendPlainText("Nombre de personnes invalides.\nChoisir entre 2 et 4 personnes !");
                ui->textEdit->appendPlainText("");
            }
        }
        else{
            ui->textEdit->appendPlainText("Selectionne un nombre de personnes");
            ui->textEdit->appendPlainText("");
        }

    }

    else{
        ui->textEdit->appendPlainText("Selection un mode Automatique ou Manuel");
        ui->textEdit->appendPlainText("");
    }

    return 0;
}
