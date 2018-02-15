/*
 * init_server.c
 *
 *  Created on: 13 févr. 2018
 *      Author: Clement
 */

#include <stdio.h>
#include <stdlib.h>
#include "init_server.h"
#include "struct.h"

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define closesocket(s) close(s)
typedef int SOCKET;

void	init_server(){

	int PORT = 30000;
	int MAXCLIENTALLOWED = 5;
	SOCKET socks = socket(AF_INET, SOCK_STREAM, 0);

	printf("---------->Montage du serveur<----------\n");

	printf("---------->Montage d'une structure de type TCP/IP<----------\n");

	if(socks == INVALID_SOCKET)
	{
		perror("socket()");
		exit(errno);
	}

	printf("---------->Definition d'un port sur une(toutes) les entrees reseau<----------\n");

	SOCKADDR_IN sin = { 0 };
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);

	printf("---------->Tentative d'affectation du port<----------\n");

	if(bind (socks, (SOCKADDR *) &sin, sizeof sin) == SOCKET_ERROR)
	{
		perror("bind()");
		exit(errno);
	}
	else {
		printf("bind reussi sur port %d\n",PORT);
	}


	printf("---------->Demarrage du listener<----------\n");

	if(listen(socks, MAXCLIENTALLOWED) == SOCKET_ERROR){
		perror("listen()");
		exit(errno);
	}
	else {
		printf("listener lance, nb clients autorise %d \n",MAXCLIENTALLOWED);
	}

	/* on peut verifier par  : netstat -an | grep 30000 */

	printf("---------->Now creating liste chainee de stack/ip vide des clients potentiels<----------\n");

	listechaineclient *vg = (listechaineclient *) malloc(sizeof(listechaineclient));;

	sockclient *c1 = (sockclient *)malloc(sizeof(sockclient));
	sockclient *c2 = (sockclient *)malloc(sizeof(sockclient));
	sockclient *c3 = (sockclient *)malloc(sizeof(sockclient));
	sockclient *c4 = (sockclient *)malloc(sizeof(sockclient));
	sockclient *c5 = (sockclient *)malloc(sizeof(sockclient));

	vg->next = (sockclient *)c1;
	c1->next = (sockclient *)c2;
	c2->next = (sockclient *)c3;
	c3->next = (sockclient *)c4;
	c4->next = (sockclient *)c5;
	c5->next = (sockclient *)c1;

	c1->init = 1;
	c2->init = 0;
	c3->init = 0;
	c4->init = 0;
	c5->init = 0;
}
