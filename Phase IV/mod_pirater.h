#ifndef _MOD_PIRATER_
#define _MOD_PIRATER_

#include <stdio.h>
#include <ctype.h>	/* isalpha */

/* Librairies du projet */
#include "mod_outils.h"
//#include "mod_cesar.h"
#include "mod_crypt.h"

#define ASCII_a 97			/* Code ASCII du a pour decalage     */
#define TAILLE_ALPHABET 26	/* Nombre de lettres dans l'alphabet */

#define SUCCESS 1			/* valeur booleenne pour une execution reussite */
#define ECHEC 0				/* valeur booleenne pour une execution ignoree */

/*
 (SP5) PIRATER_CALCULER_FREQUENCES

	Calculer les frequences d'apparition relatives des lettres de l'alphabet dans un message encode.

 PARAMETRES :

	 - tab_frequences  : Tableau de taille 26 des frequences relatives calculees (type: double*).
	 - message         : Message a decoder (type: unsigned char*).
	 - taille          : Taille du message a decoder (type: unsigned int).

 VALEUR DE RETOUR :

	 - Aucune.
	
*/
void PIRATER_calculer_frequences(double*               tab_frequences, 
	                             const unsigned char*  message, 
	                             const unsigned int    taille);

/* Procedure de test pour PIRATER_calculer_frequences. */
void test_PIRATER_calculer_frequences(void);

/*
 (SP13) PIRATER_GENERER_ALPHABET_REFERENCE

	Genere l'alphabet trie en ordre decroissant de frequences d'apparition.

 PARAMETRES :

	 - Aucuns.

 VALEUR DE RETOUR :

	- tab_alphabet_ref : Alphabet trie en ordre croissant des frequences
	                     d'apparition (type: unsigned char*).
*/
void PIRATER_generer_alphabet_reference(unsigned char* tab_alphabet_ref);

/* Procedure de test pour PIRATER_generer_alphabet_reference */
void test_PIRATER_generer_alphabet_reference(void);

/*
 (SP15) PIRATER_EXTRAIRE_CLE

	Extrait la cle en utilisant l'analyse frequentielle et la preservation des rangs.

 PARAMETRES :

     - cle      : Cle d'encodage resultante (type: unsigned char*).
	 - messsage : Message encode (type: unsigned char*).
	 - taille   : Taille du message encode (type: unsigned int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void PIRATER_extraire_cle(unsigned char*     cle,
						  unsigned char*     message,
	  					  const unsigned int taille);
  
/*
 (SP16) PIRATER_ATTAQUE_FREQUENCES

	Implemente une attaque basee sur l'analyse frequentielle.

 PARAMETRES :

	 - message : Message a decoder (type: unsigned char*).
	 - taille  : Taille du message a decoder (type: unsigned int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void PIRATER_attaque_frequences(unsigned char*     message,
	                            const unsigned int taille);

/*
 (SP17) PIRATER_PERMUTER_LETTRES

	Remplace une lettre par une autre et vice-versa dans un message.

 PARAMETRES :

	 - message         : Message a decoder (type: unsigned char*).
	 - taille          : Taille du message a decoder (type: unsigned int).
	 - premiere_lettre : La premiere lettre a permuter (type: unsigned char).
	 - deuxieme_lettre : La deuxieme lettre a permuter (type: unsigned char).

 VALEUR DE RETOUR :

	- Aucune.
*/
void PIRATER_permuter_lettres(unsigned char*      message, 
	                          const unsigned int  taille, 
	                          const unsigned char premiere_lettre, 
	                          const unsigned char deuxieme_lettre);

/*
 (SP21) PIRATER_EXTRAIRE_CLE_VIGENERE

	Extrait la cle par analyse frequentielle et l'insere dans un tableau recu en parametre.

 PARAMETRES :

	 - message	      : Message a encoder (type: unsigned char*).
	 - taille_message : Taille du message a encoder (type: unsigned int).
	 - cle            : Cle pour l'encodage (type: unsigned char*).
	 - taille_cle     : Taille de la cle (type: unsigned int).

 VALEUR DE RETOUR :

	- Aucune.
*/
void PIRATER_extraire_cle_vigenere(unsigned char*     message,
	                               const unsigned int taille_message,
	                               unsigned char*     cle,
	                               const unsigned int taille_cle);

#endif
