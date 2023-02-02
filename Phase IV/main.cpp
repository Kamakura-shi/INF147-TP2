/****************************************************************************************

Auteur(e) : Hani Ouali
Derniere Modification : 3 novembre 2022
Fichier :

Ecrire description ici: Décryptage d'un message

*****************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/* Librairies du projet */
#include "mod_outils.h"
#include "mod_crypt.h"
#include "mod_pirater.h"

/****************************************************************************************
*                           DEFINTION DU PRGORAMME PRINCIPAL                            *
****************************************************************************************/

int main(void)
{

	/* Message a decrypter + afficher */
	unsigned char message[] = "\tqlyaql hl xlykbaqacgl ejwlmgljml lex jbl yabexgxjpbxl hj mlelpj  \n"
							  "\thl qjbgrlmegxl hj fjlsly lqql lex ewlygpqgell hpbe qp mlyklmykl  \n"
							  "\tlb clbgl lx ql xmpbevlmx xlykbaqacgfjl lqql vamzl hle gbclbgljme \n"
						      "\tlx hle yklmykljme lx lqql lbxmlxglbx jb wpmxlbpmgpx lxmagx prly  \n"
							  "\tql zgqglj hle pvvpgmle lx qgbhjexmgl xpbx prly qle cmpbhle	      \n"
						      "\tlbxmlwmgele fjl prly qle wlxgxle lx zaolbble lbxmlwmgele		  \n";

	int taille = sizeof(message) / sizeof(char) - 1;

	printf("MESSAGE ENCRYPTE:\n\n%s\n", message);

	/* Decoder + afficher */
	PIRATER_attaque_frequences(message, taille);
	PIRATER_permuter_lettres(message, taille, 'r', 'l');
	PIRATER_permuter_lettres(message, taille, 'o', 'c');
	PIRATER_permuter_lettres(message, taille, 'a', 't');
	PIRATER_permuter_lettres(message, taille, 'h', 'p');
	PIRATER_permuter_lettres(message, taille, 'a', 'i');
	PIRATER_permuter_lettres(message, taille, 'r', 'u');
	PIRATER_permuter_lettres(message, taille, 'm', 'p');
	PIRATER_permuter_lettres(message, taille, 'a', 'r');
	PIRATER_permuter_lettres(message, taille, 'f', 'q');
	PIRATER_permuter_lettres(message, taille, 'x', 'b');
	PIRATER_permuter_lettres(message, taille, 'x', 'f');
	PIRATER_permuter_lettres(message, taille, 'x', 'm');
	PIRATER_permuter_lettres(message, taille, 'x', 'y');

	PIRATER_permuter_lettres(message, taille, 'm', 'c');
	PIRATER_permuter_lettres(message, taille, 'd', 'o');
	PIRATER_permuter_lettres(message, taille, 'm', 'd');
	PIRATER_permuter_lettres(message, taille, 'm', 'h');
	PIRATER_permuter_lettres(message, taille, 'r', 'n');
	PIRATER_permuter_lettres(message, taille, 'v', 'g');
	PIRATER_permuter_lettres(message, taille, 'a', 'u');
	PIRATER_permuter_lettres(message, taille, 'f', 'q');
	PIRATER_permuter_lettres(message, taille, 'm', 'f');

	printf("MESSAGE DECRYPTE:\n\n%s\n", message);

	system("pause");
	return EXIT_SUCCESS;

}