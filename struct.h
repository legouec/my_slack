/*
** struct.h
**
** Created on: 8 fevr. 2018
** Author: Clement
*/

#ifndef	STRUCT_H_
#define	STRUCT_H_

typedef struct sockclient {

	SOCKADDR_IN csin;
	SOCKET csock;
	int numero;
	char name[100];
	char uuid[64];
	struct sockclient *next;
	int init;

} sockclient;

typedef	struct	s_user;
struct	s_user{
	SOCKADDR_IN		csin;
	SOCKET			csock;
	char			*pseudo;
	uint8_t			id;
	struct	s_user	*next;
	struct	s_user	*prev;
};

typedef struct s_salon;
struct s_salon{
	struct	s_salon	*next;
	struct	s_salon	*prev;
	struct	s_user 	*first;
	struct	s_user 	*last;
};

typedef struct s_chat;
struct s_chat{
	struct	s_salon	*first;
	struct	s_salon	*last;
};

#endif /* STRUCT_H_ */
