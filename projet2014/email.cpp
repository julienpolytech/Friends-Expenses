/*
 * email.cpp
 *
 *  Created on: 20 mai 2014
 *      Author: xxx
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include "email.hpp"

using namespace std;
int my_socket;
char tmp;
char buffer[4096];
int ret;

struct sockaddr_in my_addr;

void snd(char *s)
{
	send(my_socket, s, strlen(s), 0);
}


email::email(){
	// TODO Auto-generated constructor stub

}

email::~email() {
	// TODO Auto-generated destructor stub
}

int email::connection(void){

my_addr.sin_family = AF_INET;
my_addr.sin_port = htons(25);
my_addr.sin_addr.s_addr = inet_addr("193.251.214.114");//laposte.net
memset(&(my_addr.sin_zero), '\0', 8);


my_socket = socket(AF_INET, SOCK_STREAM, 0);

	if(my_socket == -1)
	tmp=0;
	else
	tmp=1;

return tmp;

}


int email::connectionSocket(void){

	ret= connect(my_socket, (const struct sockaddr *)&my_addr, sizeof(my_addr));

    if(ret != 1)
    tmp=1;
	else
	tmp = 0;

    return tmp;

}

int email::authentification(void){
tmp=5;

while(tmp==5)
  		    {

  		        ret = recv(my_socket, buffer, 4096, 0);

				if(ret != -1 && ret!= 0)
				{

					buffer[ret] = '\0';

					if(strstr(buffer, "421") == buffer)
					{
						tmp = 2;
					}

					if(strstr(buffer, "220") == buffer)
					{
						cout << "connecter a internet\n" << endl;
						snd("EHLO localhost\r\n");
						cout << "connecter au serveur smtp\n" << endl;
					}

					if(strstr(buffer, "334") == buffer)
					{
						snd("AGZyaWVuZHNleHBlbnNlcwBGcmllbmRzMA==\r\n");
					}

					if(strstr(buffer, "250") == buffer)
					{
							cout << "AUTH PLAIN\n" << endl;
							snd("AUTH PLAIN\r\n");

					}
					if(strstr(buffer, "235") == buffer)
					{
						cout << "sucess\n" << endl;
						tmp=1;
					}
  		        }
  		       else
  		        {
  		            tmp= 0;
  		        }
  		    }
	return tmp;

}

int email::envoimail(char* CMail, char* CPhrase){

    int stage = 0;
    tmp=5;

    snd("MAIL FROM: <friendsexpenses@laposte.net>\r\n");

	 while(tmp==5)
		    {

		        ret = recv(my_socket, buffer, 4096, 0);

		        if(ret != -1 && ret != 0)
		        {

					buffer[ret] = '\0';


					if(strstr(buffer, "250") == buffer)
					{
							switch(stage)
							{

							case 0:
								cout << "expediteur ok\n" << endl;
                                snd(CMail);
								stage++;
								break;


							case 1:
								cout << "destinataire ok\n" << endl;
								snd("data\r\n");
								stage++;
								break;

							case 2:
                                tmp= 1;
								break;
							}
					}

					if(strstr(buffer, "354") == buffer)
					{
						snd("Subject: RECAPITULATIF DEPENSES\r\n");
                        snd(CPhrase);
						snd("\r\n.\r\n");
					}

			   }
			   else
				{
					tmp = 0;
				}

		    }

	 	 return tmp;

}


void email::fermerConnection(void){

    snd("QUIT\r\n");
}
