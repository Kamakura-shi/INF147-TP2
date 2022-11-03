#include "mod_outils.h"


void OUTILS_tri_decroissant_etendu_dbl_uchar(double tableau_principal[], 
											 unsigned char tableau_secondaire[], 
											 const unsigned int taille_tableau)
{
	unsigned int i_min;

	for (unsigned int i = 0; i < taille_tableau - 1; i++)
	{
		/* Assumer que le min est la valeur de gauche */
		i_min = i;

		/* Parcourir la sequence de droite */
		for (unsigned j = i + 1; j < taille_tableau; j++)
		{
			/* Si la valeur courante est plus petite que la reference, je permute */
			if (tableau_principal[j] > tableau_principal[i_min])
			{
				i_min = j;
			}

			/* Permuter la valeur a gauche completement avec la plus petite trouvee */
			SWAP_DBL(tableau_principal[i], tableau_principal[i_min])
			SWAP_INT(tableau_secondaire[i], tableau_secondaire[i_min])
		}
	}
}

void test_OUTILS_tri_decroissant_etendu_dbl_uchar(void)
{

	printf("TEST_OUTILS_OBTENIR_POSITION_MAX_DBL :: [0.02848, 0.07278, 0.01582, 0.00000]\n");
	printf("                                        [97     , 98     , 99     , 100    ]\n\n");

	double tableau_principal[] = { 0.02848, 0.07278, 0.01582, 0.00000 };
	unsigned char tableau_secondaire[] = { 97, 98, 99, 100 };
	unsigned int taille_tableaux = sizeof(tableau_principal) / sizeof(double);

	OUTILS_tri_decroissant_etendu_dbl_uchar(tableau_principal,
											tableau_secondaire,
											taille_tableaux);

	printf("\tValeur attendue : [0.07278, 0.02848, 0.01582, 0.00000]\n");
	printf("\t                  [98     , 97     , 99     , 100    ]\n\n");
	
	printf("\tValeur obenue :   [%.5lf, %.5lf, %.5lf, %.5lf]\n", 
			tableau_principal[0],
			tableau_principal[1],
			tableau_principal[2],
			tableau_principal[3]);
	
	printf("\t                  [%u     , %u     , %u     , %u    ]\n",
			tableau_secondaire[0],
			tableau_secondaire[1],
			tableau_secondaire[2],
			tableau_secondaire[3]);

}