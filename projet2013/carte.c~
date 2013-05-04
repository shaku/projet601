#include "carte.h"


int verifValiditeMap(int i, int j, int **tab, int **marque, int largeur,
		     int hauteur)
{
    if (i >= 0 && j >= 0 && j < largeur && i < hauteur) {
	if (tab[i][j] == VIDE) {
	    if (marque[i][j] == 0) {
		marque[i][j] = 1;
		return 1 + verifValiditeMap(i + 1, j, tab, marque, largeur,
					    hauteur) + verifValiditeMap(i,
									j +
									1,
									tab,
									marque,
									largeur,
									hauteur)
		    + verifValiditeMap(i + 1, j + 1, tab, marque, largeur,
				       hauteur) + verifValiditeMap(i - 1,
								   j, tab,
								   marque,
								   largeur,
								   hauteur)
		    + verifValiditeMap(i, j - 1, tab, marque, largeur,
				       hauteur) + verifValiditeMap(i - 1,
								   j - 1,
								   tab,
								   marque,
								   largeur,
								   hauteur);
	    } else
		return 0;
	} else
	    return 0;
    } else
	return 0;
}


void generateurCarte(char *nomFichier, int hauteur, int largeur)
{

    int **grille, **marque, random, nbMur = 0, caselibre, i, j, fd;
    fd = open(nomFichier, O_CREAT | O_WRONLY, 0777);
    marque = malloc(sizeof(int *) * hauteur);
    grille = malloc(sizeof(int *) * hauteur);
    for (i = 0; i < hauteur; i++) {
	marque[i] = malloc(sizeof(int) * largeur);
	grille[i] = malloc(sizeof(int) * largeur);
    }
    for (i = 0; i < hauteur; i++) {
	for (j = 0; j < largeur; j++)
	    grille[i][j] = 0;
    }


    srand(time(NULL));
    do {
	for (i = 0; i < hauteur; i++) {
	    for (j = 0; j < largeur; j++) {
		random = (int) rand() % 1000;
		if (random >= RANDOM_MUR_MIN && random <= RANDOM_MUR_MAX)
		    grille[i][j] = 1;
		else if (random >= RANDOM_PRISON)
		    grille[i][j] = 2;
		nbMur = (grille[i][j] == 1
			 || grille[i][j] == 2) ? nbMur + 1 : nbMur;
		marque[i][j] = 0;
	    }
	}
	caselibre =
	    verifValiditeMap(0, 0, grille, marque, largeur, hauteur);
    } while ((caselibre + nbMur) == (largeur * hauteur));
    write(fd, &hauteur, sizeof(int));
    write(fd, &largeur, sizeof(int));
    for (i = 0; i < hauteur; i++) {
	for (j = 0; j < largeur; j++) {
	    write(fd, &grille[i][j], sizeof(int));
	}
    }
    system("clear");
    afficherCarte(grille, hauteur, largeur);
    while (getchar() != '\n');
    printf("Appuyez sur entrée pour retourner au menu.\n");
    getchar();
}


int **lireCarte(char *nomFichier)
{
    int i, j, hauteur, largeur, **grille;
    int fd = open(nomFichier, O_RDONLY, 0);
    read(fd, &hauteur, sizeof(int));
    read(fd, &largeur, sizeof(int));
    grille = malloc(sizeof(int *) * hauteur);
    for (i = 0; i < hauteur; i++) {
	grille[i] = malloc(sizeof(int) * largeur);
    }
    for (i = 0; i < hauteur; i++) {
	for (j = 0; j < largeur; j++) {
	    read(fd, &grille[i][j], sizeof(int));
	}
    }
    return grille;
}


void afficherCarte(int **grille, int hauteur, int largeur)
{
    int i, j;
    printf("       ");
    for (i = 0; i < largeur + 2; i++) {
	printf("Q");
    }
    printf("\n");
    for (i = 0; i < hauteur; i++) {
	printf("%.3d  : Q", i);
	for (j = 0; j < largeur; j++) {
	    switch (grille[i][j]) {
	    case 0:
		printf(" ");
		break;
	    case 1:
		printf("O");
		break;
	    case 2:
		printf("P");
		break;
	    default:
		break;
	    }
	}
	printf("Q\n");
    }
    printf("       ");
    for (i = 0; i < largeur + 2; i++) {
	printf("Q");
    }
    printf("\n");

}
