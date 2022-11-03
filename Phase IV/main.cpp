/****************************************************************************************

Auteur(e) :
Derniere Modification :
Fichier :

Ecrire description ici:

*****************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/* Librairies du projet */
#include "mod_outils.h"
#include "mod_crypt.h"
#include "mod_pirater.h"

/****************************************************************************************
*                               DEFINTION DES CONSTANTES                                *
****************************************************************************************/

/* Espace brouillon */
#define BROUILLON 0

/* Phases du projet */
#define PHASE_4   1
#define PHASE_6   0

/****************************************************************************************
*                           DEFINTION DU PRGORAMME PRINCIPAL                            *
****************************************************************************************/

#if BROUILLON

	int main(void)
	{

		/* Espace brouillon */
		
		/* Fonctionne */
		/*test_PIRATER_calculer_frequences();*/

		/* Fonctionne */
		unsigned char tableau_alphabet_frequences[TAILLE_ALPHABET];
		PIRATER_generer_alphabet_reference(tableau_alphabet_frequences);

		/* Fonctionne */
		test_PIRATER_generer_alphabet_reference;

		/* Fonctionne */
		test_OUTILS_tri_decroissant_etendu_dbl_uchar();

		/* Fonctionne */
		unsigned char tableau[TAILLE_ALPHABET];
		CRYPT_generer_alphabet(tableau);

		/* Fonctionne */
		test_CRYPT_generer_alphabet();


		system("pause");
		return EXIT_SUCCESS;

	}

#elif PHASE_1

	int main(void)
	{
		
		/* Aucun decalage */
		unsigned char cle_0[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_0, 13);
		printf("cle_0 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_0, TAILLE_ALPHABET);

		/* Meme chose que -1 */
		unsigned char cle_1[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_1, -27);
		printf("cle_1 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_1, TAILLE_ALPHABET);

		/* Meme chose que 0 */
		unsigned char cle_2[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_2, -26);
		printf("cle_2 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_2, TAILLE_ALPHABET);

		unsigned char cle_3[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_3, 1);
		printf("cle_3 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_3, TAILLE_ALPHABET);

		unsigned char cle_4[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_4, 25);
		printf("cle_4 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_4, TAILLE_ALPHABET);

		/* Meme chose que 0 */
		unsigned char cle_5[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_5, 26);
		printf("cle_5 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_5, TAILLE_ALPHABET);

		/* Meme chose que +1 */
		unsigned char cle_6[TAILLE_ALPHABET];
		CESAR_generer_cle(cle_6, 27);
		printf("cle_6 : ");
		OUTILS_afficher_tableau_1D_uchar(cle_6, TAILLE_ALPHABET);

		/* Tests d'encryption et de decryption */
		printf("\n");

		/* Message a encoder et decrypter */
		unsigned char message[] = "ecole de technologie superieure";
		int taille = sizeof(message) / sizeof(char) - 1;
		int decalage = 13;

		/* Afficher message original */
		printf("MESSAGE ORIGINAL: %s\n", message);

		/* encoder + afficher */
		CESAR_encrypter(message, taille, decalage);
		printf("MESSAGE ENCRYPTE: %s\n", message);

		/* Decoder + afficher */
		CESAR_decrypter(message, taille, decalage);
		printf("MESSAGE DECRYPTE: %s\n\n", message);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif PHASE_2

	int main(void)
	{

		/* Chaîne a decrypter */
		unsigned char message[] = "rpbyr qr grpuabybtvr fhcrevrher";
		int taille = sizeof(message) / sizeof(char) - 1;

		/* Afficher message original */
		printf("MESSAGE ENCRYPTE: %s\n", message);

		/* Pirater + afficher */
		PIRATER_dechiffrer_cesar(message, taille);
		printf("MESSAGE DECRYPTE: %s\n", message);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif PHASE_3

	int main(void)
	{

		/* Cle d'encryption */
		unsigned char cle[TAILLE_ALPHABET];
		CRYPT_generer_cle(cle);

		/* Chaîne a encoder */
		unsigned char message[] = "ecole de technologie superieure";
		int taille = sizeof(message) / sizeof(char) - 1;

		/* Afficher message original */
		printf("MESSAGE ORIGINAL: %s\n", message);

		/* Encoder + afficher */
		CRYPT_encrypter(message, taille, cle);
		printf("MESSAGE ENCRYPTE: %s\n", message);

		/* Decrypter + afficher */
		CRYPT_decrypter(message, taille, cle);
		printf("MESSAGE DECRYPTE: %s\n", message);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif PHASE_4

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

		printf("MESSAGE DECRYPTE:\n\n%s\n", message);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif PHASE_5

	int main(void)
	{

		/* Declarer et initialiser message a encoder + stocker taille */
		unsigned char message[] = "personne";
		int taille = sizeof(message) / sizeof(unsigned char) - 1;

		/* Declarer et initialiser cle pour encryption */
		unsigned char une_cle[] = "jour";
		unsigned int taille_cle = sizeof(une_cle) / sizeof(unsigned char) - 1;

		/* Afficher message original */
		printf("ORIGINAL: %s\n", message);

		/* Encoder message + afficher */
		VIGENERE_encrypter(message, taille, une_cle, taille_cle);
		printf("ENCRYPTE: %s\n", message);

		/* Decrypter message + afficher */
		VIGENERE_decrypter(message, taille, une_cle, taille_cle);
		printf("DECRYPTE: %s\n", message);

		system("pause");
		return EXIT_SUCCESS;

	}

#elif PHASE_6

	/* Poser une hypothese sur la taille de la cle */
	#define TAILLE_CLE 4

	int main(void)
	{

		/* Declarer et initialiser message a decoder */
		unsigned char message[] = "\tnoqenmvi hfhuwsqxksopg cx epoocus gi hfhuwsqggg hwv iqi oswlqrh			\n"
								  "\thg qucrhdrczbwg rrrv zd hggfvkdwmqb oe rzxw cbfmgbqi ggw vgoomush			\n"
								  "\ttcf dp - mwqhk ox mzs vmgqoi gzoi ecqwkgwi c saeowqit zd jtstygbfi			\n"
								  "\tfsv pghwvgg hqrzrcgsv hcbv yp ahwuoji evljhfh gghwi oswlqrh iuh			\n"
								  "\tivgexioahrv iwmnwvig dryt rhgqrhv fsv qggveisv gjwijtsv tcf				\n"
								  "\tvydgwmviwmqb gsph xr glhqrzh xtsv wkaspg svx ns flktivg rh gggdv			\n"
								  "\tnoqenmvi hfhuwsqxksopg svx dovig gxv ns iekh tyg rdru qkesih				\n"
								  "\tpcbjyg qhvvolrgg oivhuiu cx gqaempolwqbv hg zhxvfhw cdsetolwusqx			\n"
								  "\tcjhg wbh ggfwekbh jtstygbfi rou izsptns hr hfdrþcwv pg s hwv zd			\n"
								  "\tpghwvg zd tniv yvwomush wwwymg rx e gh gy u wqzgfviosqx ns z iuh			\n"
								  "\tsiw iwmnwvi esv mptrvoowmqbv tgfpivhhrv oxb efbtvoqenmvxgg gi				\n"
								  "\tholvg rhw jmssvvhwgg vyt zh xglwi ezdmt o fsprlxkcq uws					\n"
								  "\toenurvkhkqg rh gjwijtspiph fspghvxs oe tssethlxkcq hgg ivgexipqhw			\n"
								  "\tes tyk svx ns feu dryt rhw uiewvwwyvwrru arrqootjoeivwtygg hx				\n"
								  "\trcocczslcphxkexiu iqi fsxbkspi ecqhkhlsp bhgggvekfh tqiu					\n"
								  "\terdomsihv eswxg hhgjbluws hwv zd pqbjygiu hw qucrhrktopqg sq				\n"
								  "\tihthx wb wizhh xtcs gqiux ps uihzhxg ddw qpomiowskfhqgbw pc				\n"
								  "\tfhtcfwmvwrr isqitooi fsv jtstygbfiu rhw nswxtsv hg doyu gl pc qoi			\n"
								  "\tggw hg zd qgah pqbjygiu uws oi osvwcuh mn bh tqiuvc m dzqwu hg				\n"
								  "\tfhtghlxkcq hg zhxvfh iv zdrczbwg tuisihrvwhpns gixwhrffd modrwuwepg		\n";

		/* Stocker taille */
		unsigned int taille = sizeof(message) / sizeof(char) - 1;

		/* Initialiser la cle */
		unsigned char cle[TAILLE_CLE];

		/* Afficher message original */
		printf("MESSAGE ORIGINAL:\n\n%s\n", message);

		/* Extraire cle */
		PIRATER_extraire_cle_vigenere(message, taille, cle, TAILLE_CLE);

		/* Afficher cle */
		printf("CLE EXTRAITE : \"");
		for (int i = 0; i < TAILLE_CLE; i++)
		{
			printf("%c", cle[i]);
		}
		printf("\"\n\n");

		/* Decoder message et afficher */
		VIGENERE_decrypter(message, taille, cle, TAILLE_CLE);
		printf("MESSAGE DECRYPTE:\n\n%s\n", message);

	}

#endif