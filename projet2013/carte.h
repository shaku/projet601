#ifndef CARTE_H
#define CARTE_H

/* ***************************************************************************
	INCLUDES
*************************************************************************** */

#include "include.h"


/* ***************************************************************************
	DEFINES
*************************************************************************** */

#define VIDE 0
#define MUR 1
#define PRISON 2

#define RANDOM_PRISON 975
#define RANDOM_MUR_MIN 850
#define RANDOM_MUR_MAX 975


/* ***************************************************************************
	DECLARATIONS
*************************************************************************** */

int verifValiditeMap(int i, int j, int **tab, int **marque, int largeur,
		     int hauteur);

void generateurCarte(char *nomFichier, int hauteur, int largeur);

int **lireCarte(char *nomFichier);

void afficherCarte(int **grille, int hauteur, int largeur);


#endif
