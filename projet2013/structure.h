#ifndef STRUCTURE_H
#define STRUCTURE_H


/* ***************************************************************************
	STRUCTURES ET TYPEDEF
*************************************************************************** */

/**
 * Contient les informations d'un criminel
*/
typedef struct {
  /** Nom du criminel */
    char *nom;
  /** Prénom du criminel */
    char *prenom;
  /** Prime du criminel */
    long prime;
} criminel_t;


/**
 * Représente une carte d'une ville
*/
typedef struct {
  /** Tableau de int à deux dimensions */
    int **grille;
  /** Notre tableau de mutex à deux dimensions */
    pthread_mutex_t *mutex;
} test_t;

/**
  * Types d'évènement flash
*/
typedef enum event_serveur {
    ECHAPPE = 0,
    ARRESTATION = 1,
    DETECTION = 2
} e_serveur_t;


/**
  * Types d'évènement joueur
*/
typedef enum event_joueur {
    DECONNEXION = 1,
    AJOUT = 2,
    RETRAIT = 3
} e_joueur_t;

/**
  * Coordonnée
*/
typedef struct {
    int x;
    int y;
} coord_t;


/**
  * Ordre d'un client au serveur
*/
typedef struct {
    e_joueur_t event;
    coord_t position;
} ordre_t;

/**
 * Contient les informations du serveur de connexion
*/
typedef struct {
  /** Adresse ip du socket */
    char *adresse;
  /** Port du socket */
    int port;
} serveur_t;


/**
 * Identifiant de socket
*/
typedef int SOCKET;


/**
 * Contient les informations d'une socket
*/
typedef struct sockaddr_in SOCKADDR_IN;


/**
 * Contient les informations d'adressage d'une socket
*/
typedef struct sockaddr SOCKADDR;


/**
 * Contient les informations d'une adresse ip
*/
typedef struct in_addr IN_ADDR;




#endif
