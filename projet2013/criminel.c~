#include "criminel.h"


void genererCriminel(char *nomFichier)
{
    char tamponNom[255], tamponPrenom[255], continuer;
    int tailleNom, taillePrenom, fd, nbCriminel = 0;
    long prime;

    fd = open(nomFichier, O_CREAT | O_WRONLY, 0777);

    lseek(fd, sizeof(int), SEEK_SET);

    do {
	printf("\nNom du criminel : ");
	scanf("%s", tamponNom);
	tailleNom = strlen(tamponNom);

	printf("Prenom du criminel : ");
	scanf("%s", tamponPrenom);
	taillePrenom = strlen(tamponPrenom);

	printf("Prime de %s %s : ", tamponNom, tamponPrenom);
	scanf("%ld", &prime);

	write(fd, &tailleNom, sizeof(int));
	write(fd, &taillePrenom, sizeof(int));
	write(fd, tamponNom, sizeof(char) * tailleNom);
	write(fd, tamponPrenom, sizeof(char) * taillePrenom);
	write(fd, &prime, sizeof(long));

	while (getchar() != '\n');
	nbCriminel++;

	printf("\nContinuer (O ou N) : ");
	scanf("%c", &continuer);
    } while (continuer == 'O' || continuer == 'o');
    lseek(fd, 0, SEEK_SET);
    write(fd, &nbCriminel, sizeof(int));
}


criminel_t *lireCriminels(char *nomFichier)
{
    criminel_t *criminels;
    int fd, tailleNom, taillePrenom, nbCriminel, i;
    fd = open(nomFichier, O_RDONLY, 0);
    read(fd, &nbCriminel, sizeof(int));
    printf("%d \n", nbCriminel);
    criminels = (criminel_t *) malloc(sizeof(criminel_t) * nbCriminel);
    for (i = 0; i < nbCriminel; i++) {

	read(fd, &tailleNom, sizeof(int));
	read(fd, &taillePrenom, sizeof(int));
	criminels[i].nom = (char *) malloc(sizeof(char) * tailleNom);
	criminels[i].prenom = (char *) malloc(sizeof(char) * taillePrenom);
	read(fd, criminels[i].nom, sizeof(char) * tailleNom);
	read(fd, criminels[i].prenom, sizeof(char) * taillePrenom);
	read(fd, &criminels[i].prime, sizeof(long));
    }
    return criminels;
}
