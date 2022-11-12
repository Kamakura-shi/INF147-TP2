#include "mod_pirater.h"

#include <ctype.h>         /*  Librairie pour isalpha  */


/*  Calculer les frequences d'apparition relatives des lettres de l'alphabet dans un message encode.  */
void PIRATER_calculer_frequences(double* tab_frequences,
	                             const unsigned char* message,
	                             const unsigned int    taille)
{
	unsigned int nb_caracteres = 0;               /* nombre de caracteres du message */
	
	/* Compter le nombre d'apparitions de chacune des lettres du message avec le truc msg[i] - 'a' */

	for (int i = 0; i < taille; i++)
	{
		if (isalpha(message[i])) 
		{
			tab_frequences[message[i] - 'a']++;   /* nombre d'apparitions d'un caractere*/
			nb_caracteres++;
		}				
	}	
	for (int i = 0; i < TAILLE_ALPHABET; i++)    /* Parcourir le tableau d'apparition des caracteres*/
	{
		tab_frequences[i] /= nb_caracteres;     /* Calcul de la fréquence d'apparition des caracteres */
	}		
}


/*  Implemente une attaque basee sur l'analyse frequentielle sur le code de Cesar.  */
void PIRATER_dechiffrer_cesar(unsigned char* message,
							  const unsigned int taille)
{	
	//Initialisation du tableau de fréquences des caractetres
	double tab_frequences[TAILLE_ALPHABET] = { 0 };
	
	/* Appel de sous programme  */
	PIRATER_calculer_frequences(tab_frequences, message, taille);                 

	/*  Stockage de la valeur de retour i_max */
	unsigned int i_max = OUTILS_obtenir_position_max_dbl(tab_frequences, taille);   
	
	/*Calcul du décalage avec i_max*/
	int decalage = ('a' + i_max) - 'e';   
	
	CESAR_decrypter(message, taille, -decalage);	
}


void test_PIRATER_calculer_frequences(void)
{
	unsigned char message[] = "abracadabra! s'exclama-t-il";
	unsigned int taille = sizeof(message) / sizeof(char);

	double tab_frequences[TAILLE_ALPHABET] = { 0.0 };
	PIRATER_calculer_frequences(tab_frequences, message, taille);

	for (int i = 0; i < TAILLE_ALPHABET; i = i + 2)
	{
		printf("%c -> %.4lf\t%c -> %.4lf\n", 'a' + i, tab_frequences[i], 'a' + i + 1, tab_frequences[i + 1]);
	}
}


//
//
//void test_PIRATER_generer_alphabet_reference(void)
//{
//	unsigned char tab_alphabet_ref[TAILLE_ALPHABET];
//	PIRATER_generer_alphabet_reference(tab_alphabet_ref);
//}