#ifndef _MOD_OUTILS_
#define _MOD_OUTILS_

#include <stdlib.h>
#include <stdio.h>

#define TAILLE_ALPHABET 26	/* Nombre de lettres dans l'alphabet */

/* Macro-fonction qui permute deux entiers. */
#define SWAP_INT(x,y) { int temp = x; \
                        x = y;        \
                        y = temp; }

/* Macro-fonction qui permute deux rationnels. */
#define SWAP_DBL(x,y) { double temp = x; \
                        x = y;           \
                        y = temp; }

/* Macro-fonction qui genere un nombre aleatoire entre a et b inclusivement. */
#define RANDBETWEEN(a, b) { (a + (unsigned int)rand() % (b - a + 1)) }

/*
 (SP14) OUTILS_TRI_DECROISSANT_ETENDU_DBL_UCHAR

    Trie deux tableaux en etendant le tri du premier aux elements du deuxieme.

 PARAMETRES :

     - tableau_principal  : Tableau de reference (type: double*).
     - tableau_secondaire : Tableau auquel le tri est etendu (type: unsigned char*).
     - taille_tableaux    : Taille des deux tableaux (type: unsigned int).

 VALEUR DE RETOUR :

    - Aucune.
*/
void OUTILS_tri_decroissant_etendu_dbl_uchar(double*            tableau_principal, 
                                             unsigned char*     tableau_secondaire, 
                                             const unsigned int taille_tableaux);

/* Procedure de test pour OUTILS_tri_decroissant_etendu_dbl_uchar. */
void test_OUTILS_tri_decroissant_etendu_dbl_uchar(void);

#endif
