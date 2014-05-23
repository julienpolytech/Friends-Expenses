//============================================================================
// Name        : main.cpp
// Author      : Julien Salim Charles
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Application to manage friends expenses
//============================================================================

#include "Person.hpp"
#include "Group.hpp"
#include "email.hpp"


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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

#include "widget.h"
#include "ui_widget.h"


char mode;


Widget::Widget(QWidget *parent) :
               QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QString title = QString("");
    title = "Friends Expenses v1.0";

    setWindowTitle( title );

    /*******************************************déclaration des signaux************************************************/

    connect(ui->pushButton_run, SIGNAL(clicked()), this, SLOT(FriendsExpenses()));
    connect(ui->pushButton_group, SIGNAL(clicked()), this, SLOT(GroupNumber()));
    connect(ui->pushButton_next, SIGNAL(clicked()), this, SLOT(Manu()));
    connect(ui->pushButton_browse, SIGNAL(clicked()), this, SLOT(Browse()));
    connect(ui->radioButton_Autoatique, SIGNAL(clicked()), this, SLOT(Automatic()));
    connect(ui->radioButton_Manuel, SIGNAL(clicked()), this, SLOT(Manual()));
    connect(ui->pushButton_clear, SIGNAL(clicked()), this, SLOT(Clear()));
    connect(ui->pushButton_saveAs, SIGNAL(clicked()), this, SLOT(SaveAs()));
    connect(ui->pushButton_mails, SIGNAL(clicked()), this, SLOT(SendMails()));
    connect(ui->pushButton_aide, SIGNAL(clicked()), this, SLOT(Aide()));

    ui->radioButton_Autoatique->setChecked(true); // initialisation par defaut au mode manuel

    /**************************************initialisation des variables************************************************/

    mode = 1;
    numberOfGroup = 0;
    numberOfPersons = 0;

    /********************************************initialisation des champs*********************************************/

    ui->lineEditConfigurationFilePath->setEnabled(true);
    ui->pushButton_browse->setEnabled(1);

    ui->lineEdit_depenses->setEnabled(false);
    ui->lineEdit_mail->setEnabled(false);
    ui->lineEdit_telephone->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->comboBox_statut->setEnabled(0);
    ui->pushButton_next->setEnabled(0);

    ui->lineEdit_NomGroupe->setEnabled(false);
    ui->lineEdit_NbPersonnes->setEnabled(false); 
    ui->pushButton_group->setEnabled(0);

    ui->pushButton_mails->setEnabled(0);
    ui->pushButton_saveAs->setEnabled(0);
    ui->pushButton_clear->setEnabled(0);    
    ui->pushButton_run->setEnabled(0);

}



Widget::~Widget()
{
    delete ui;
}


using namespace std;

vector<Group> Groups; // creation du groupe de groupes

/*************************************************************************** CLEAR ***************************************************************************/

void Widget::Clear(){

    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->lineEditConfigurationFilePath->clear();
    ui->lineEdit_depenses->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_NbPersonnes->clear();
    ui->lineEdit_NomGroupe->clear();

    ui->lineEdit_NbPersonnes->setStyleSheet("");
    ui->lineEdit_NomGroupe->setStyleSheet("");
    ui->lineEdit_prenom->setStyleSheet("");
    ui->lineEdit_depenses->setStyleSheet("");

    ui->pushButton_clear->setEnabled(0);
    ui->pushButton_mails->setEnabled(0);
    ui->pushButton_run->setEnabled(0);
    ui->pushButton_aide->setEnabled(1);
    ui->pushButton_saveAs->setEnabled(0);
    ui->comboBox_statut->setEnabled(0);
    ui->pushButton_next->setEnabled(0);

    ui->lineEdit_mail->setEnabled(false);
    ui->lineEdit_telephone->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_depenses->setEnabled(false);


    Groups.clear(); // ********* Remise a zero des groupes

    if(mode==1)         //  Mode Automatique
    {
        ui->lineEditConfigurationFilePath->setEnabled(true);
        ui->lineEdit_NomGroupe->setEnabled(false);
        ui->lineEdit_NbPersonnes->setEnabled(false);
        ui->pushButton_browse->setEnabled(1);
        ui->pushButton_group->setEnabled(0);
    }
    else                //  Mode Manuel
    {
        ui->lineEditConfigurationFilePath->setEnabled(false);
        ui->lineEdit_NomGroupe->setEnabled(true);
        ui->lineEdit_NbPersonnes->setEnabled(true);
        ui->pushButton_browse->setEnabled(0);
        ui->pushButton_group->setEnabled(1);
    }
}

/*********************************************************************** AUTOMATIQUE *************************************************************************/

void Widget::Automatic()
{
    mode = 1;

    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->lineEditConfigurationFilePath->clear();
    ui->lineEdit_depenses->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_NbPersonnes->clear();
    ui->lineEdit_NomGroupe->clear();

    ui->lineEdit_NbPersonnes->setStyleSheet("");
    ui->lineEdit_NomGroupe->setStyleSheet("");
    ui->lineEdit_prenom->setStyleSheet("");
    ui->lineEdit_depenses->setStyleSheet("");

    ui->pushButton_clear->setEnabled(0);
    ui->pushButton_mails->setEnabled(0);
    ui->pushButton_run->setEnabled(0);
    ui->pushButton_aide->setEnabled(1);
    ui->pushButton_saveAs->setEnabled(0);
    ui->comboBox_statut->setEnabled(0);
    ui->pushButton_next->setEnabled(0);

    ui->lineEdit_mail->setEnabled(false);
    ui->lineEdit_telephone->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_depenses->setEnabled(false);

    ui->lineEditConfigurationFilePath->setEnabled(true);
    ui->lineEdit_NomGroupe->setEnabled(false);
    ui->lineEdit_NbPersonnes->setEnabled(false);
    ui->pushButton_browse->setEnabled(1);
    ui->pushButton_group->setEnabled(0);

    ui->radioButton_Autoatique->setChecked(true);
    ui->radioButton_Manuel->setChecked(false);

    ui->lineEdit_depenses->setEnabled(false);
    ui->lineEdit_mail->setEnabled(false);
    ui->lineEdit_telephone->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_NomGroupe->setEnabled(false);
    ui->lineEdit_NbPersonnes->setEnabled(false);

    ui->pushButton_browse->setEnabled(1);

    return;
}

/*********************************************************************** MANUEL *************************************************************************/

void Widget::Manual()
{
    mode = 0;

    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();
    ui->lineEditConfigurationFilePath->clear();
    ui->lineEdit_depenses->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_prenom->clear();
    ui->lineEdit_NbPersonnes->clear();
    ui->lineEdit_NomGroupe->clear();

    ui->lineEdit_NbPersonnes->setStyleSheet("");
    ui->lineEdit_NomGroupe->setStyleSheet("");
    ui->lineEdit_prenom->setStyleSheet("");
    ui->lineEdit_depenses->setStyleSheet("");

    ui->pushButton_clear->setEnabled(0);
    ui->pushButton_mails->setEnabled(0);
    ui->pushButton_run->setEnabled(0);
    ui->pushButton_aide->setEnabled(1);
    ui->pushButton_saveAs->setEnabled(0);
    ui->comboBox_statut->setEnabled(0);
    ui->pushButton_next->setEnabled(0);

    ui->lineEdit_mail->setEnabled(false);
    ui->lineEdit_telephone->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_depenses->setEnabled(false);

    ui->lineEditConfigurationFilePath->setEnabled(false);
    ui->lineEdit_NomGroupe->setEnabled(true);
    ui->lineEdit_NbPersonnes->setEnabled(true);
    ui->pushButton_browse->setEnabled(0);
    ui->pushButton_group->setEnabled(1);

    ui->radioButton_Autoatique->setChecked(0);
    ui->radioButton_Manuel->setChecked(1);

    ui->lineEdit_depenses->setEnabled(false);
    ui->lineEdit_mail->setEnabled(false);
    ui->lineEdit_telephone->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_NomGroupe->setEnabled(1);
    ui->lineEdit_NbPersonnes->setEnabled(1);

    ui->pushButton_browse->setEnabled(0);

    return;
}

/*********************************************************************** MANUEL ******************************************************************************/

void Widget::Manu(){
    static int i=0;

    static Group aGroup;

    QString Qprenom ;
    QString Qexpenses;
    QString Qtelephone;
    QString Qmail;
    QString Qstatut;

    QString QGroupe = ui->lineEdit_NomGroupe->text();
    string Groupe = QGroupe.toUtf8().constData();


    if(ui->lineEdit_prenom->text() == "")
    {
        ui->lineEdit_prenom->setStyleSheet( QString("background-color: red"));
        QMessageBox::warning(this, tr("Champs vide"),
                             tr("Prenom à renseigner.\n"));
        return;

    }
    else if(ui->lineEdit_depenses->text() == "")
    {
        ui->lineEdit_depenses->setStyleSheet( QString("background-color: red"));

        QMessageBox::warning(this, tr("Champs vide"),
                             tr("Depenses à renseigner.\n"));;
        return;

    }
    else                /*recuperation des infos*/
    {

        Qprenom = ui->lineEdit_prenom->text();
        string Prenon = Qprenom.toUtf8().constData();

        Qexpenses = ui->lineEdit_depenses->text();
        string Expenses = Qexpenses.toUtf8().constData();
        float expen = atof((char*)Expenses.c_str()); // string to float pour les depenses


        Qtelephone = ui->lineEdit_telephone->text();
        string Telephone = Qtelephone.toUtf8().constData();

        Qmail = ui->lineEdit_mail->text();
        string Mail = Qmail.toUtf8().constData();

        Qstatut = ui->comboBox_statut->currentText();
        string Statut = Qstatut.toUtf8().constData();



        Person aPerson(Prenon,Telephone,Mail,expen,Statut.compare(Dona));

        aGroup.push_back(aPerson);

        ui->textEdit_2->appendPlainText( "" );
        ui->textEdit_2->appendPlainText( QString("Prénom : ") + Qprenom );
        ui->textEdit_2->appendPlainText( QString("Dépenses : ") + Qexpenses);

        if (ui->lineEdit_telephone->text() == "" ){

            ui->textEdit_2->appendPlainText("Telephone : Non renseigné");
        }
        else{
            ui->textEdit_2->appendPlainText( QString("Telephone : ") + Qtelephone);
        }

        if (ui->lineEdit_mail->text() == "" ){

            ui->textEdit_2->appendPlainText("Mail : Non renseigné");
        }
        else{
             ui->textEdit_2->appendPlainText( QString("Mail : ") + Qmail);
        }


        ui->textEdit_2->appendPlainText( QString("Statut : ") + Qstatut);
        ui->textEdit_2->appendPlainText( "" );

        i++;
    }

    if(i >= numberOfPersons){

        ui->textEdit_2->appendPlainText( "----------------------------------------------" );

        aGroup.setName(Groupe);  // ************** Ajout du nom du Groupe
        Groups.push_back(aGroup);
        aGroup.clear();			// *************** Remise a zero du groupe pour l'ajout d'un suivant
        i=0;
        numberOfPersons=0;

        ui->textEdit_2->appendPlainText("Indiquez le nom d'un nouveau groupe ou démarrer");

        ui->lineEdit_NbPersonnes->setStyleSheet("");
        ui->lineEdit_NomGroupe->setStyleSheet("");

        ui->lineEdit_depenses->clear();
        ui->lineEdit_mail->clear();
        ui->lineEdit_telephone->clear();
        ui->lineEdit_prenom->clear();
        ui->lineEdit_NbPersonnes->clear();
        ui->lineEdit_NomGroupe->clear();
        ui->pushButton_group->setEnabled(1);

        ui->lineEdit_depenses->setEnabled(false);
        ui->lineEdit_mail->setEnabled(false);
        ui->lineEdit_telephone->setEnabled(false);
        ui->lineEdit_prenom->setEnabled(false);
        ui->comboBox_statut->setEnabled(0);


        ui->pushButton_next->setEnabled(0);

        ui->lineEdit_NomGroupe->setEnabled(true);
        ui->lineEdit_NbPersonnes->setEnabled(true);

        ui->pushButton_run->setEnabled(1);
        ui->pushButton_saveAs->setEnabled(1);

    }
    else
    {

    ui->lineEdit_depenses->setStyleSheet("");
    ui->lineEdit_prenom->setStyleSheet("");

    ui->lineEdit_depenses->clear();
    ui->lineEdit_mail->clear();
    ui->lineEdit_telephone->clear();
    ui->lineEdit_prenom->clear();
    ui->comboBox_statut->setCurrentIndex(0);
    }


}

/*********************************************************************** GROUP ******************************************************************************/

void Widget::GroupNumber(){


    QString QgroupName = ui->lineEdit_NomGroupe->text();
    GroupName = QgroupName.toUtf8().constData();

    QString QnbOfPersons = ui->lineEdit_NbPersonnes->text();
    string nbOfPersons = QnbOfPersons.toUtf8().constData();
    numberOfPersons = atoi((char*)nbOfPersons.c_str());


    if(ui->lineEdit_NomGroupe->text() == "")
    {
        ui->lineEdit_NomGroupe->setStyleSheet( QString("background-color: red"));
        ui->lineEdit_NbPersonnes->setStyleSheet( QString("background-color: white"));

        QMessageBox::warning(this, tr("Champs vide"),
                     tr("Nom du groupe à renseigner.\n"));

        return;
    }

    if(ui->lineEdit_NbPersonnes->text() == "")
    {
        ui->lineEdit_NbPersonnes->setStyleSheet( QString("background-color: red"));

        QMessageBox::warning(this, tr("Champs vide"),
                             tr("Nombre de personnes à renseigner.\n"));
        return;
    }

    if(numberOfPersons<2){

        ui->lineEdit_NomGroupe->setStyleSheet( QString("background-color: white"));
        ui->lineEdit_NbPersonnes->setStyleSheet( QString("background-color: red"));
        ui->lineEdit_NbPersonnes->clear();

        QMessageBox::warning(this, tr("Nombre de personnes trop faible"),
                             tr("Veuillez indiquer au moins 2 personnes.\n"));
        return;
    }

    ui->lineEdit_NbPersonnes->setStyleSheet("");
    ui->lineEdit_NomGroupe->setStyleSheet("");

    ui->textEdit_2->appendPlainText( "----------------------------------------------" );
    ui->textEdit_2->appendPlainText( "Groupe : " + QString(GroupName.c_str()));
    ui->textEdit_2->appendPlainText(QnbOfPersons + " personnes");

    ui->lineEdit_depenses->setEnabled(true);
    ui->lineEdit_mail->setEnabled(true);
    ui->lineEdit_telephone->setEnabled(true);
    ui->lineEdit_prenom->setEnabled(true);
    ui->comboBox_statut->setEnabled(1);
    ui->lineEdit_NomGroupe->setEnabled(false);
    ui->lineEdit_NbPersonnes->setEnabled(false);

    ui->pushButton_clear->setEnabled(1);
    ui->pushButton_group->setEnabled(0);
    ui->pushButton_next->setEnabled(1);
    ui->pushButton_run->setEnabled(0);
    ui->pushButton_saveAs->setEnabled(0);
}

/*********************************************************************** OUVRIR ******************************************************************************/

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


        ui->textEdit_2->appendPlainText( "" );
        ui->textEdit_2->appendPlainText( "Selected configuration file: " );
        ui->textEdit_2->appendPlainText( m_configurationFilePath );

        ui->pushButton_clear->setEnabled(1);

    }


    c= m_configurationFilePath.toStdString().c_str();
    ifstream filecsv(c); // ouverture du fichier

    if (!filecsv){ // Affichage que
    ui->textEdit_2->appendPlainText("Error opening");
    ui->pushButton_clear->setEnabled(1);
    return;
    }


    string temp,line;
    vector <string> tableau;

    getline(filecsv, line); // recupere la 1ere ligne du fichier

    stringstream ss(line);

    while(getline(ss, temp, ',')){ // decompose les diferente cases de la ligne
        tableau.push_back(temp);
    }

    int aname = 20,aphone = 20,aexpense = 20,agname = 20,amail = 20,adonateur = 20;
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
        if (it->compare("Type") == 0){
            adonateur = i;
        }
        if (it->compare("Mail") == 0){
            amail = i;
        }

        i++;
    }


    if((aname <20) && (aexpense<20) && (agname<20)){ // Le fichier CSV contient les infos minimum

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
					Person aPerson(person[aname],expen); // creation de ma personne
					if(aphone<20){						// Ajout du Telephone si existant
						aPerson.setPhone(person[aphone]);
					}
					if(amail<20){						// Ajout du mail si existant
						aPerson.setMail(person[amail]);
					}
					if(adonateur<20){					// Ajout du type si existant, membre par defaut
						aPerson.setStatut(person[adonateur].compare("Donateur"));
					}
					it->push_back(aPerson);
					it->setNbPers(((it->getNbPers()) + 1));
					break;
				}

			}

			if (!GroupEx){ // Si le groupe n'existait pas

					Person aPerson(person[aname],expen); // creation de ma personne
					if(aphone<20){
						aPerson.setPhone(person[aphone]);
					}
					if(amail<20){
						aPerson.setMail(person[amail]);
					}
					if(adonateur<20){
						aPerson.setStatut(person[adonateur].compare("Donateur"));
					}
					Group aGroup(person[agname]); // On creait le nouveau groupe
					aGroup.push_back(aPerson); // On y insert la personne
					aGroup[0].setLink(&aGroup); // On ajoute le pointeur du groupe qu'on a cree
					Groups.push_back(aGroup); // On ajoute notre groupe a notre vecteur de groupe

			}


		}

		filecsv.close();

		ui->pushButton_run->setEnabled(1);
		ui->pushButton_clear->setEnabled(1);
		ui->pushButton_browse->setEnabled(0);
		ui->lineEditConfigurationFilePath->setEnabled(false);
	}
	else{
		 ui->textEdit_2->appendPlainText( "Le fichier CSV doit contenir au minimum :" );
		 ui->textEdit_2->appendPlainText( "Nom | Dépenses | Groupe" );
	}

}

/******************************************************************* SAUVEGARDE ******************************************************************************/

void Widget::SaveAs()
{
    // Choix du chemin d'enregistrement
    QString file = QFileDialog::getSaveFileName(this,"Enregister", QString(), ".csv");

    // Enregistrement
    QFile saveCSV(file +".csv");

    if (saveCSV.open(QFile::WriteOnly))
    {
        QTextStream out(&saveCSV);

        QString PhoneNumber = "Phone Number";
        QString GroupName = "Group Name";

        out << "Name" << "," << PhoneNumber << ","  << "Expenses" << "," << GroupName << "," << "Mail" << "," << "Type" << "\n";

        for (vector<Group>::iterator it = Groups.begin() ; it != Groups.end(); ++it)
        {

            Group tmpGroup = *it;

            for (size_t i=0; i < tmpGroup.size(); ++i) {

                // operate the payback first
                tmpGroup[i].operatePayback(tmpGroup.expensesPerPerson());
                // display the values


                string Name = tmpGroup[i].getName();
                string Phone = tmpGroup[i].getPhone();
                float Expenses = tmpGroup[i].getExpenses();
                string GroupName = it->getName();
                string Mail = tmpGroup[i].getMail();
                int Statut = tmpGroup[i].getStatut();

                QString QName = QString(Name.c_str());
                QString QPhone = QString(Phone.c_str());
                QString QExpenses;
                QExpenses.setNum(Expenses);
                QString QGroupName = QString(GroupName.c_str());
                QString QMail = QString(Mail.c_str());

                QString QStatut;

                if (Statut == 0){

                    QStatut = "Donnateur";

                }
                else{
                    QStatut = "Membre";
                }


                out << QName << "," << QPhone << "," << QExpenses << "," << QGroupName << "," << QMail << "," << QStatut << "\n";

            }


        }
    }
}

/*********************************************************************** AIDE ********************************************************************************/

void Widget::Aide(){

    QMessageBox::information(this,"Aide",
     "Etape 1 : Selection du mode \r\n\nMode Automatique :\nL'application s'éxécute à partir de la lecture d'un fichier Csv\r\nMode Manuel :\nL'application s'éxécute à partir des données dûment remplies\r\n\nEtape 2 : Configurer l'application\r\n\nMode automatique :\n\n   - Rechercher le fichier à éxécuter à l'aide du bouton Ouvrir\r\n   - Lancer le calcul à l'aide du bouton Démarer\r\n   - Appuyer Envoi mails pour envoyer le recapitulatif des\n     dépenses par mail\n\nMode automatique :\n\n   - Renseigner le nom de groupe et le nombre de personne\n   - Selectionner OK pour créer le groupe\n   - Renseigner les différents champs\n   - Valider la personne avec suivant\n   - Répéter l'opération pour chaque personne\n   -Une fois le groupe remplit sélectionner Démarer ou créer un\n     nouveau groupe\n   - Appuyer Envoi mails pour envoyer le recapitulatif des\n     dépenses par mail\n\n " );
    return;
}

/*********************************************************************** DEMARER ******************************************************************************/

int Widget::FriendsExpenses() {



    for (vector<Group>::iterator it = Groups.begin() ; it != Groups.end(); ++it)
    {

        ui->textEdit->appendPlainText("-----------------------------------");

        const string name = it->getName();
        QString QName = QString(name.c_str());
        ui->textEdit->appendPlainText(QString("Groupe : ") + QName);

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
            if (tmpGroup[i].getStatut()){
                tmpGroup[i].operatePayback(tmpGroup.expensesPerPerson());
            }
            // display the values


            string Name;
            Name = tmpGroup[i].getName();
            QString QName = QString(Name.c_str());

            ui->textEdit->appendPlainText(QString("Nom : ") + QName);

            string Num;
            Num = tmpGroup[i].getPhone();
            QString QNum = QString(Num.c_str());
            ui->textEdit->appendPlainText(QString("Numero : ") + QNum);

            string Mail;
            Mail = tmpGroup[i].getMail();
            QString QMail = QString(Mail.c_str());
            ui->textEdit->appendPlainText(QString("Mail : ") + QMail);

            if(tmpGroup[i].getStatut()){
                ui->textEdit->appendPlainText(QString("Type : Membre"));
            }
            else{
                ui->textEdit->appendPlainText(QString("Type : Donnateur"));
            }

            float Expenses;
            Expenses = tmpGroup[i].getExpenses();
            QString QExpenses;
            QExpenses.setNum(Expenses);
            ui->textEdit->appendPlainText(QString("Depenses : ") + QExpenses + " euros");

            float Payback;  // ************ Gestion Dette ou Avoir
            Payback = tmpGroup[i].getPayback();
            if(Payback){
				QString QPayback;
				QPayback.setNum(Payback);
				ui->textEdit->appendPlainText(QString("Dette : ") + QPayback + " euros");
			}
			else if (Payback == 0){
                ui->textEdit->appendPlainText(QString("Ne doit rien"));
			}
			else {
				Expenses = -(Expenses);
				QString QPayback;
				QPayback.setNum(Payback);
				ui->textEdit->appendPlainText(QString("Avoir : ") + QPayback + " euros");
			}
				
            ui->textEdit->appendPlainText("-----------------------------------");
            ui->textEdit->appendPlainText("");

        }
    }

     ui->lineEdit_NbPersonnes->clear();
     ui->lineEdit_NomGroupe->clear();

     ui->pushButton_mails->setEnabled(1); // activation du bouton envoi mail

     ui->lineEdit_NbPersonnes->setStyleSheet("");
     ui->lineEdit_NomGroupe->setStyleSheet("");

     ui->lineEdit_NomGroupe->setEnabled(false);
     ui->lineEdit_NbPersonnes->setEnabled(false);

     ui->pushButton_group->setEnabled(false);
     ui->pushButton_run->setEnabled(false);

     return 0;

}

/*********************************************************************** ENVOI MAIL ******************************************************************************/


string float2string(float f)
{
  ostringstream os;
  os << f;
  return os.str();
}

void Widget::SendMails(){

        email a;
        int authentificationOK;
        int mailOK=0;
        int socketOK=0;
        int connectionOK=0;

        cout << "tentative de conexion\n" << endl;

        connectionOK=a.connection();

        switch(connectionOK)
        {

        case 0:
        cout << "echec initialisation connection\n" << endl;
        mailOK=0;
        break;

        case 1:
        cout << "Connection initialisee\n" << endl;
        socketOK=a.connectionSocket();

            switch(socketOK)
            {

            case 0:
            cout << "echec conection au socket\n" << endl;
            mailOK=0;
            break;

            case 1:
            cout << "Connecte au socket\n" << endl;
            authentificationOK=a.authentification();

                switch(authentificationOK)
                {
                    case 0:
                        cout << "Probleme connexion internet\n" << endl;
                        mailOK=0;
                        break;

                    case 1:
                        mailOK=1;
                        break;

                    case 2:
                        cout << "trop de connections\n" << endl;
                        mailOK=0;
                        break;
                }

            break;

            }
        break;
        }


        for (vector<Group>::iterator it = Groups.begin() ; it != Groups.end(); ++it)
        {


            Group tmpGroup = *it;
            for (size_t i=0; i < tmpGroup.size(); ++i)
            {
                float Expenses;
                Expenses = tmpGroup[i].getExpenses();
                string sExpenses;
                sExpenses = float2string(Expenses);

                float Payback;
                Payback = tmpGroup[i].getPayback();
                string sPayback;

                string Mail;
                Mail = tmpGroup[i].getMail();

                string Name;
                Name = tmpGroup[i].getName();
                QString QName = QString(Name.c_str());
                string Phrase;

                if (Payback >= 0){

                    sPayback = float2string(Payback);
                    Phrase = "Bonjour " + Name + ",\n" + "Tu as dépensé pendant tes vacances " + sExpenses + " euros\n" + "Tu dois " + sPayback + " euros.\n\n" + "L'application Friends Expenses" ;

                }
                else{

                    Payback = Payback + 2*Payback;
                    sPayback = float2string(Payback);
                    Phrase = "Bonjour " + Name + ",\n" + "Tu as dépensé pendant tes vacances " + sExpenses + " euros.\n" + "Tes collèguent te doivent " + sPayback + " euros.\n\n" + "L'application Friends Expenses" ;

                }

                char* CPhrase = (char*)Phrase.c_str();


                string AMail = "RCPT TO: <" + Mail + ">\r\n";
                char* CMail = (char*)AMail.c_str();

                if(mailOK==1)
                {

                    mailOK=a.envoimail(CMail, CPhrase);

                    switch(mailOK)
                    {
                    case 0:
                        ui->textEdit_3->appendPlainText(QString("Le mail à ") + QName + QString(" n'a pas été envoyé"));
                        break;

                    case 1:
                        ui->textEdit_3->appendPlainText(QString("Le mail à ") + QName + QString(" a été envoyé"));

                        break;
                    }

                    mailOK=1;

                }
                else
                {
                 ui->textEdit_3->appendPlainText(QString("Le mail à ") + QName + QString(" n'a pas été envoyé"));
                }

            }

        }

        a.fermerConnection();
  }




