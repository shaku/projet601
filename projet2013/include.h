#ifndef INCLUDE_H
#define INCLUDE_H

/* ***************************************************************************
	INCLUDES
*************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#include <pthread.h>

#include "structure.h"


/* ***************************************************************************
	DEFINES
*************************************************************************** */

#define CLE_MSG_CS 1337		/* Ecriture : Client / Lecture : Serveur */
#define CLE_MSG_SC 3007		/* Ecriture : Serveur / Lecture : Client */
#define CLE_SHM 1007

#define MAX_JOUEUR 16
#define MAX_DETECTIVE 10

#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
#define MAX_PLAYER_REACHED -1


#endif
