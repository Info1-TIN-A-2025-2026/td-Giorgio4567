
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("Bad argument(s).\n");
		return 1;
	}

	double volume_cm3 = atof(argv[1]);
	int qualite = atoi(argv[2]);
	int couleur = atoi(argv[3]);
	if ((volume_cm3 <= 0) || ((qualite != 0) && (qualite != 1) && (qualite != 2)) || ((couleur != 0) && (couleur != 1)))
	{
		printf("Invalid value.\n");
		return 2;
	}
	double prix_HT = 0., prix_TVA = 0., prix_TTC = 0., qualite_prix = 0.;
	const double PRIX_MATIERE_CM3 = 0.05, QUALITE_DRAFT = 0.8, QUALITE_SD = 1., QUALITE_HAUTE = 1.3, SUPP_COULEUR = 5., TVA = 0.08;

	char nom_qualite[50];
	switch (qualite)
	{
		case 0 :
			qualite_prix = QUALITE_DRAFT;
			strcpy(nom_qualite, "draft");
			break;
		case 1 :
			qualite_prix = QUALITE_SD;
			strcpy(nom_qualite, "standard");
			break;
		case 2 :
			qualite_prix = QUALITE_HAUTE;
			strcpy(nom_qualite, "high");
			break;
	}
	prix_HT = (couleur == 1) ? (volume_cm3 * PRIX_MATIERE_CM3 * qualite_prix + SUPP_COULEUR) : volume_cm3 * PRIX_MATIERE_CM3 * qualite_prix;
	prix_TVA = prix_HT * TVA;
	prix_TTC = prix_HT + prix_TVA;

	char nom_couleur[50];
	if (couleur == 1)
		strcpy(nom_couleur, "color");
	else
		strcpy(nom_couleur, "white");

	printf("Volume [cm3]  :%10.2lf\n", volume_cm3);
	printf("Quality       :%10s\n", nom_qualite);
	printf("Color         :%10s\n", nom_couleur);
	printf("-----------------------------------\n");
	printf("Price (HT)    :%10.2lf\n", prix_HT);
	printf("TVA (8%%)      :%10.2lf\n", prix_TVA);	
	printf("Total (TTC)   :%10.2lf\n", prix_TTC);
}
#endif


