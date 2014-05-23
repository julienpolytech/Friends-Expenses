/*
 * Person.cpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Salim
 */

#include "Person.hpp"

/*
Person::Person() :
    _expenses(0),
    _payback(0) {

}
*/

Person::Person() :
    _expenses(0),
    _payback(0),
    _donateur(1)
{
}

Person::Person(const string& iName,float iExpenses) :
                _name(iName),
                _phone(""),
                _mail(""),
                _expenses(iExpenses),
                _donateur(1),
                _payback(0)
{
}

Person::Person(const string& iName,const string& iPhone,const string& iMail,float iExpenses,int iDonateur) :
                _name(iName),
                _phone(iPhone),
                _mail(iMail),
                _expenses(iExpenses),
                _donateur(iDonateur),
                _payback(0)
{
}


void Person::setName(const string& iName){
        _name = iName;
}

void Person::setMail(const string& iMail){
        _mail = iMail;
}

void Person::setLink(const Group* iLink){
        _link = iLink;
}

void Person::setPhone(const string& iPhone){
        _phone = iPhone;
}

void Person::setExpenses(float iExpenses){
        _expenses = iExpenses;
}

void Person::setStatut(int iDonateur){
        _donateur = iDonateur;
}

void Person::setPayback(float iPayback){
        _payback = iPayback;
}



const string& Person::getName(){
        return _name;
}

const string& Person::getMail(){
        return _mail;
}

const Group* Person::getLink(){
        return _link;
}

const string& Person::getPhone(){
        return _phone;
}

float Person::getExpenses() const{
        return _expenses;
}

float Person::getPayback(){
        return _payback;
}

int Person::getStatut() const{
        return _donateur;
}





void Person::operatePayback(const float iExpensesPerPerson) {
    _payback = _expenses - iExpensesPerPerson;
}


Person::~Person() {

}
