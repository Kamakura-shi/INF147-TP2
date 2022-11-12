#include "mod_cesar.h"

void CESAR_generer_cle(unsigned char* cle,const int decalage)
{
	/* Pour un décalage avec une valeur positive */
	if (decalage < 0)
	{
		/* Parcours l'alphapet au complet */
		for (int i = 0; i < TAILLE_ALPHABET; i++)
		{
			/* On change la séquence de la cle par décalage */
			cle[i] = ASCII_a + (i - decalage) % TAILLE_ALPHABET;
		}
	}

	else
	{
		/* Pour un décalage avec une valeur négative */
		for (int i = 0; i < TAILLE_ALPHABET; i++)
		{
			cle[i] = ASCII_a + (i + decalage) % TAILLE_ALPHABET;
		}
	}
}


void CESAR_encrypter(unsigned char* message,
	const unsigned int taille,
	const int         decalage)
{
	int position;
	unsigned char cle[TAILLE_ALPHABET];
	CESAR_generer_cle(cle, decalage);
	
	for (int i = 0; i < taille; i++)
	{
		/* S'assure qu'on encode des caratères alphabétiques */
		if (isalpha(message[i]) != 0)
		{
			/* Interchange chaque caractère du message avec celle de la cle */
			position = message[i] - ASCII_a;
			message[i] = cle[position];
		}
	}
}

void CESAR_decrypter(unsigned char* message,
	const unsigned int taille,
	const int          decalage)
{
	CESAR_encrypter(message, taille, decalage);
}
