#include "mod_crypt.h"

void CRYPT_generer_alphabet(unsigned char* tab_alphabet)
{
	for (int i = 0; i < TAILLE_ALPHABET; i++)
	{
		tab_alphabet[i] = i + 'a';
	}

}

void test_CRYPT_generer_alphabet(void)
{

	unsigned char tab_alphabet[TAILLE_ALPHABET];
	CRYPT_generer_alphabet(tab_alphabet);

}