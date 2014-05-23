/*
 * Person.hpp
 *
 *  Created on: Mar 13, 2014
 *      Author: Salim
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>

//forward declaration
class Group;

using namespace std;

class Person {
public :
    Person();
    Person(const string& iName,float iExpenses);
    Person(const string& iName,const string& iPhone,const string& iMail, float iExpenses,int iDonateur);

    void setName(const string& iName);
    void setMail(const string& iMail);
    void setLink(const Group* iLink);
    void setStatut(int iDonateur);
    void setPhone(const string& iPhone);
    void setExpenses(float iExpenses);
    void setPayback(float iPayback);

    const string& getName();
    const string& getMail();
    const string& getPhone();
    float getExpenses() const;
    const Group* getLink();
    float getPayback();
    int getStatut() const;

    void operatePayback(const float iExpensesPerPerson);

    virtual ~Person();

private :
    string _name;
    string _phone;
    string _mail;
    const Group* _link;
    float _expenses;
    float _payback;
    int _donateur;
};

#endif /* PERSON_HPP_ */
