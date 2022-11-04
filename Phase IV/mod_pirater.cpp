#include "mod_pirater.h"
#include "mod_crypt.h"

void PIRATER_calculer_frequences(double* tab_frequences,
	const unsigned char* message,
	const unsigned int    taille)
{
	unsigned int nb_caracteres = 0;

	/* Compter le nombre d'apparitions de chacune des lettres du message avec le truc msg[i] - 'a' */

	for (unsigned int i = 0; i < taille; i++)
	{
		if (isalpha(message[i]))
		{
			tab_frequences[message[i] - 'a']++; // nombre de d'apparitions d'un caractere
			nb_caracteres++;
		}
	}
	for (int i = 0; i < TAILLE_ALPHABET; i++)
	{
		tab_frequences[i] /= nb_caracteres; /* ATTENTION : nb_caracteres != taille */
	}
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

void PIRATER_generer_alphabet_reference(unsigned char* tab_alphabet_frequences)
{
	tab_alphabet_frequences[0] = 'e';
	tab_alphabet_frequences[1] = 'a';
	tab_alphabet_frequences[2] = 's';
	tab_alphabet_frequences[3] = 'i';
	tab_alphabet_frequences[4] = 'n';
	tab_alphabet_frequences[5] = 't';
	tab_alphabet_frequences[6] = 'r';
	tab_alphabet_frequences[7] = 'l';
	tab_alphabet_frequences[8] = 'u';
	tab_alphabet_frequences[9] = 'o';
	tab_alphabet_frequences[10] = 'd';
	tab_alphabet_frequences[11] = 'c';
	tab_alphabet_frequences[12] = 'm';
	tab_alphabet_frequences[13] = 'p';
	tab_alphabet_frequences[14] = 'g';
	tab_alphabet_frequences[15] = 'v';
	tab_alphabet_frequences[16] = 'b';
	tab_alphabet_frequences[17] = 'f';
	tab_alphabet_frequences[18] = 'q';
	tab_alphabet_frequences[19] = 'h';
	tab_alphabet_frequences[20] = 'x';
	tab_alphabet_frequences[21] = 'j';
	tab_alphabet_frequences[22] = 'y';
	tab_alphabet_frequences[23] = 'k';
	tab_alphabet_frequences[24] = 'w';
	tab_alphabet_frequences[25] = 'z';
}

void test_PIRATER_generer_alphabet_reference(void)
{
	unsigned char tab_alphabet_ref[TAILLE_ALPHABET];
	PIRATER_generer_alphabet_reference(tab_alphabet_ref);
}

void PIRATER_extraire_cle(unsigned char* cle,
						  unsigned char* message,
						  const unsigned int taille)
{
	double tableau_frequences[TAILLE_ALPHABET] = { 0.0 };
	PIRATER_calculer_frequences(tableau_frequences, message, taille);

	CRYPT_generer_alphabet(cle);

	OUTILS_tri_decroissant_etendu_dbl_uchar(tableau_frequences, cle, TAILLE_ALPHABET);
}

void PIRATER_attaque_frequences(unsigned char* message,
								const unsigned int taille)
{
	unsigned char cle[TAILLE_ALPHABET];
	PIRATER_extraire_cle(cle, message, taille);
	
	unsigned char tab_alphabet_reference[TAILLE_ALPHABET];
	PIRATER_generer_alphabet_reference(tab_alphabet_reference);

	for (unsigned i = 0; i < taille - 1; i++)
	{
		if (isalpha(message[i])) 
		{
			unsigned int execution = ECHEC;
			for (unsigned j = 0; j < TAILLE_ALPHABET && !execution; j++)
			{
				if (message[i] == cle[j]) 
				{
					message[i] = tab_alphabet_reference[j];
					execution = SUCCESS;
				}
			}
		}
	}
}

void PIRATER_permuter_lettres(unsigned char* message,
							  const unsigned int  taille,
							  const unsigned char premiere_lettre,
							  const unsigned char deuxieme_lettre)
{
	for (unsigned i = 0; i < taille - 1; i++)
	{
		if (message[i] == premiere_lettre)
		{
			message[i] = deuxieme_lettre;
		}
		else if (message[i] == deuxieme_lettre)
		{
			message[i] = premiere_lettre;
		}
	}
}