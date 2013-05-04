#ifndef CONNEXION_H
#define CONNEXION_H


/* ***************************************************************************
	INCLUDES
*************************************************************************** */

#include "include.h"


/* ***************************************************************************
	DECLARATIONS
*************************************************************************** */

SOCKET socket_serveur;		/* socket serveur */
pthread_t joueurs[MAX_JOUEUR];	/* Processus pour les joueurs */
SOCKADDR_IN in_socket_client[MAX_JOUEUR];	/* interface client */
SOCKET socket_client[MAX_JOUEUR];	/* socket client */
SOCKADDR_IN in_socket_serveur;	/* interface serveur */
socklen_t taille[MAX_JOUEUR];	/* taille interface */
int statut_joueur[MAX_JOUEUR];



/**
 * Routine de gestion des demandes de connexion des clients
 * @param *s Structure serveur_t
 * @return EXIT_SUCCESS : Arrêt normal du programme.
 * @return errno : Arrêt anormal du programme.
 */
void *routine_connexion(void *s);


/**
 * Routine de thread qui s'occupe d'un client après que celui-ci se soit connecté
 * @param *arg Identifiant du client à connaître
 * @return EXIT_SUCCESS : Arrêt normal du programme.
 * @return errno : Arrêt anormal du programme.
 */
void *routine_connexion_client(void *arg);


/**
 * Retourne un identifiant libre de joueur
 * @param *statut_joueur Liste des statuts des joueurs
 * @return int : Un identifiant inutilisé dans la liste
 * @return MAX_PLAYER_REACHED : Erreur, tous les identifiants sont actuellement utilisés
 */
int getId();


/**
 * Modifie le statut d'un joueur
 * @param id Identifiant du joueur
 * @param etat Etat cible du joueur
 * @param *statutJoueur Liste des statuts des joueurs
 */
void setStatut(int id, int etat);


/**
 * Obtient le statut d'un joueur
 * @param id Identifiant du joueur à vérifier
 * @param *statut_joueur Liste des statuts des joueurs
 * @return statutJoueur : Statut du joueur
 */
int getStatut(int id);


#endif
