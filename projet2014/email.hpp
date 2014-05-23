/*
 * email.hpp
 *
 *  Created on: 20 mai 2014
 *      Author: xxx
 */

#ifndef EMAIL_HPP_
#define EMAIL_HPP_


using namespace std;

class email {
public:
	email();
	virtual ~email();
	int connection(void);
	int connectionSocket(void);
    int envoimail(char* CMail, char* CPhrase);
	int authentification(void);
    void fermerConnection(void);

private:

};

#endif /* EMAIL_HPP_ */
