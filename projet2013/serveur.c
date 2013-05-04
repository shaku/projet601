#include "serveur.h"


int main(int argc, char **argv)
{

    char *fichier, tampon[255];
    int choix = 1, largeur, hauteur, shm_id, msg_id[2];
    pthread_t connexion, principale;
    serveur_t serveur;


    while (choix != 0) {
	system("clear");
	if (choix > 3 || choix < 1) {
	    printf("Choix non disponible\n");
	}
	printf("====== MENU ======\n");
	printf("1. Lancer le jeu.\n");
	printf("2. Créer une liste de criminel.\n");
	printf("3. Créer une carte aléatoirement.\n");
	printf("0. Quitter le jeu.\n");
	printf("Choix : ");
	while (!scanf("%d", &choix)) {
	    while (getchar() != '\n');
	    printf("Vous devez saisir un entier.\n");
	    printf("Choix : ");
	}
	switch (choix) {
	case 1:
	    /* création mémoire partagée
	       création file de message
	       création thread programme principale
	       création thread connexion */
	    /* MEMOIRE PARTAGEE */
	    shm_id = 0;
	    shm_id = shm_id;
	    /* FILE DE MESSAGE */
	    if ((msg_id[0] = msgget(CLE_MSG_CS, 0777 | IPC_CREAT)) == -1) {
		printf
		    ("Erreur lors de la création de la file de message.\n");
		break;
	    }
	    if ((msg_id[1] = msgget(CLE_MSG_SC, 0777 | IPC_CREAT)) == -1) {
		printf
		    ("Erreur lors de la création de la file de message.\n");
		break;
	    }
	    /*Création thread connexion */
	    printf("Adresse ip : ");
	    scanf("%s", tampon);
	    serveur.adresse = malloc(sizeof(char) * strlen(tampon));
	    strcpy(serveur.adresse, tampon);
	    printf("Port : ");
	    scanf("%d", &serveur.port);
	    pthread_create(&connexion, NULL, routine_connexion, &serveur);
	    /* Création thread principale 
	       pthread_create(*principale,NULL,(void *)routine_principale,0); */
	    choix = 0;
	    pthread_join(connexion, 0);
	    printf("Jeux en cours.\n");
	    break;
	case 2:
	    printf("Nom du fichier à créer : ");
	    scanf("%s", tampon);
	    fichier = malloc(sizeof(char) * strlen(tampon));
	    strcpy(fichier, tampon);
	    genererCriminel(fichier);
	    break;
	case 3:
	    printf("Nom du fichier à créer : ");
	    scanf("%s", tampon);
	    fichier = malloc(sizeof(char) * strlen(tampon));
	    strcpy(fichier, tampon);
	    printf("Hauteur : ");
	    scanf("%d", &hauteur);
	    printf("Largeur : ");
	    scanf("%d", &largeur);
	    generateurCarte(fichier, hauteur, largeur);
	    break;
	case 0:
	    break;
	default:
	    break;
	}
    }
    return 0;
}
