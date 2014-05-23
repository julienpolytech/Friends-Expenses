/*
 * Group.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Salim
 */

#include "Group.hpp"


Group::Group() {

}


Group::Group(const string& iNameg) :
                _name(iNameg),
                _nbPerson(1)
{

}

void Group::setName(const string& iNameg){
        _name = iNameg;
}

void Group::setNbPers(const int iNbPers){
    _nbPerson = iNbPers;
}

const string& Group::getName() const{
        return _name;
}

const int Group::getNbPers(){
    return _nbPerson;
}


float Group::totalExpenses() const {
    float aTotal = 0;
    for (size_t i=0; i < this->size(); i++) {
        if (this->at(i).getStatut() == 0){
            aTotal -= this->at(i).getExpenses();
        }
        else{
            aTotal += this->at(i).getExpenses();
        }

    }
    return aTotal;
}

float Group::expensesPerPerson() const {
    int i,nbpers = 0;
    for (i=0;i<this->size();i++){
        if (this->at(i).getStatut()){
            nbpers ++;
        }
    }
    qDebug()<< nbpers;
    float aExpense = this->totalExpenses() / nbpers;
    qDebug()<< aExpense;
    return aExpense;
}


Group::~Group() {

}
