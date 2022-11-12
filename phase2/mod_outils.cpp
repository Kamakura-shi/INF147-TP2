#include "mod_outils.h"

#include <stdio.h>


void OUTILS_afficher_tableau_1D_uchar(unsigned char* tableau, unsigned int taille_tableau)
{
	for (int i = 0; i < taille_tableau; i++)
	{
		
		printf("%c ", tableau[i]); 
	}	
	printf("\n");
}


unsigned int OUTILS_obtenir_position_max_dbl(const double* tableau,
                                             const unsigned int taille) 
{
    unsigned int i_max = 0;

    for (int i = 1; i < taille; i++)
    {
        if (tableau[i] > tableau[i_max])
        i_max = i;        
    }
    return i_max;
}


void test_OUTILS_obtenir_position_max_dbl(void)
{

	printf("TEST_OUTILS_OBTENIR_POSITION_MAX_DBL :: [-1., 1., 10., 0.]\n\n");

	double tableau[] = {-1., 1., 10., 0.};
	unsigned int taille = sizeof(tableau) / sizeof(double);

	unsigned int valeur_attendue = 2;
	unsigned int valeur_obtenue = OUTILS_obtenir_position_max_dbl(tableau, taille);
	
	printf("\tValeur attendue : %u\n", valeur_attendue);
	printf("\tValeur obtenue  : %u\n", valeur_obtenue);

}


//void test_OUTILS_tri_decroissant_etendu_dbl_uchar(void)
//{
//
//	printf("TEST_OUTILS_OBTENIR_POSITION_MAX_DBL :: [0.02848, 0.07278, 0.01582, 0.00000]\n");
//	printf("                                        [97     , 98     , 99     , 100    ]\n\n");
//
//	double tableau_principal[] = { 0.02848, 0.07278, 0.01582, 0.00000 };
//	unsigned char tableau_secondaire[] = { 97, 98, 99, 100 };
//	unsigned int taille_tableaux = sizeof(tableau_principal) / sizeof(double);
//
//	OUTILS_tri_decroissant_etendu_dbl_uchar(tableau_principal,
//											tableau_secondaire,
//											taille_tableaux);
//
//	printf("\tValeur attendue : [0.07278, 0.02848, 0.01582, 0.00000]\n");
//	printf("\t                  [98     , 97     , 99     , 100    ]\n\n");
//	
//	printf("\tValeur obenue :   [%.5lf, %.5lf, %.5lf, %.5lf]\n", 
//			tableau_principal[0],
//			tableau_principal[1],
//			tableau_principal[2],
//			tableau_principal[3]);
//	
//	printf("\t                  [%u     , %u     , %u     , %u    ]\n",
//			tableau_secondaire[0],
//			tableau_secondaire[1],
//			tableau_secondaire[2],
//			tableau_secondaire[3]);
//
//}