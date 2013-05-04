CFLAGS = -Wall -g -O3 -ansi -pedantic -D_XOPEN_SOURCE -D_SVID_SOURCE -Wno-unused-result -pthread
CSERVEUR = serveur.c criminel.c carte.c connexion.c

all: doc serveur client

client : client.c
	gcc client.c -o client $(CFLAGS)

serveur: serveur.c criminel.c carte.c connexion.c
	gcc $(CSERVEUR) -o serveur $(CFLAGS)

indent: *.c *.h
	indent *.c -kr
	indent *.h -kr

doc:
	rm -rf ../doc
	doxygen doxygen.ini
	clear

clean:
	rm -f client serveur client.exe serveur.exe
	rm -f *.o
	rm -f *~
	rm -f *.stackdump

