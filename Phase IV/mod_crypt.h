#ifndef _MOD_CRYPT_
#define _MOD_CRYPT_

#include "mod_outils.h"

#include <ctype.h>      /* isalpha */

#define ASCII_a 97		/* Code ASCII du a pour decalage */

/*
 (SP8) CRYPT_GENERER_ALPHABET

    Genere un tableau qui contient les codes ASCII de l'alphabet en minuscules.

 PARAMETRES :

	 - tab_alphabet : Alphabet ASCII en minuscules (type: unsigned char*).

 VALEUR DE RETOUR :

	  - Aucune.
    
*/
void CRYPT_generer_alphabet(unsigned char* tab_alphabet);

/* Procedure de test pour CRYPT_GENERER_ALPHABET. */
void test_CRYPT_generer_alphabet(void);

/*
 (SP10) CRYPT_GENERER_CLE

    Genere une cle aleatoire pour l'encodage.

 PARAMETRES :

     - cle : Cle aleatoire pour l'encodage (type: unsigned char*).

 VALEUR DE RETOUR :

    - Aucune.
*/
void CRYPT_generer_cle(unsigned char* cle);

/*
 (SP11) CRYPT_ENCRYPTER

    Encode un message a partir d'une cle recue.

 PARAMETRES :

     - message : Message a encoder (type: unsigned char*).
     - taille  : Taille du message a encoder (type: unsigned int).
     - cle     : Cle aleatoire pour l'encodage (type: unsigned char*).

 VALEUR DE RETOUR :

    - Aucune.
*/
void CRYPT_encrypter(unsigned char*       message, 
                     const unsigned int   taille, 
                     const unsigned char* cle);

/*
 (SP12) CRYPT_DECRYPTER

    Decode un message a partir d'une cle recue.

 PARAMETRES :

     - message : Message a encoder (type: unsigned char*).
     - taille  : Taille du message a encoder (type: unsigned int).
     - cle     : Cle aleatoire pour l'encodage (type: unsigned char*).

 VALEUR DE RETOUR :

    - Aucune.
*/
void CRYPT_decrypter(unsigned char*       message, 
                     const unsigned int   taille, 
                     const unsigned char* cle);

#endif
