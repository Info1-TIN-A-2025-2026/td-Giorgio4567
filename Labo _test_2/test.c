/*
Feedback – Labo test 2 (analyse signal binaire)

Points positifs :
- max_length_high() et max_length_low() : solution simple, lisible
  et correcte (compteur courant + maximum), complexité O(n).
- count_rising_edge() : logique correcte (compte signal[0]==1
  comme front montant + transitions 0→1), complexité O(n).

Points à corriger / améliorer :
- rle() : l’idée de produire l’affichage sans utiliser de tableau
  intermédiaire est bonne, mais l’implémentation contient des
  erreurs de cas limites.
  - Cas num_samples == 1 : la boucle ne s’exécute pas et le test
    final accède à signal[num_samples-2], ce qui provoque un accès
    mémoire invalide (signal[-1]).
  - Le dernier run peut être compté deux fois : une longueur est
    affichée dans la boucle quand i == num_samples-1, puis une
    nouvelle longueur ",1" peut être ajoutée après la boucle.
    Cela fausse le codage RLE, le nombre de symboles et le taux
    de compression (ex. signal alterné 010101...).
  - La variable count_compression est utilisée de façon confuse :
    elle mélange le comptage des runs et un incrément final lors
    de l’affichage. On attend clairement :
      num_symbols = 1 + nombre de runs.
  - Il manque un retour à la ligne final après l’affichage du
    taux de compression pour correspondre exactement au format
    attendu par les tests.

Conseil :
- Traiter explicitement les cas num_samples == 0 et num_samples == 1.
- Gérer l’affichage du dernier run une seule fois (dans la boucle
  ou après, mais pas les deux).
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned long max_length_high(const char *signal, const unsigned long num_samples) 
{
    unsigned long count = 0;
    unsigned long max_count = 0;
    for(unsigned long i = 0; i < num_samples; i++)
    {
        if (signal[i] == 1)
            count++;
        else
            count = 0;
        
        if (count > max_count)
        {
            max_count = count;
        }
    }
    return max_count;
}

unsigned long max_length_low(const char *signal, const unsigned long num_samples) 
{
    unsigned long count = 0;
    unsigned long max_count = 0;
    for(unsigned long i = 0; i < num_samples; i++)
    {
        if (signal[i] == 0)
            count++;
        else
            count = 0;
        
        if (count > max_count)
        {
            max_count = count;
        }
    }
    return max_count;
}

unsigned long count_rising_edge(const char *signal, const unsigned long num_samples) 
{
    unsigned long Nb_rising_edge = 0;
    for(unsigned long i = 0; i < num_samples; i++)
    {   
        if (i == 0)
        {
            if (signal[i] == 1)
                Nb_rising_edge++;
        }
        else
        {
            if((signal[i] == 1) && (signal[i-1] == 0))
                Nb_rising_edge++;
        }
    } 
    return Nb_rising_edge;
}

void rle(const char *signal, const unsigned long num_samples) 
{

	if (num_samples == 0)
	{
		printf("rle: 0");
        printf("\nnum symbols in rle: 0");
    	printf("compression rate: x0");
		return;
	}

	unsigned int rle_1 = signal[0];
	printf("rle: %u",rle_1);
	unsigned long count = 1;
	double count_compression = 1;

	if (num_samples == 1)
	{
		printf(",%u",1);
        count_compression++;
	}
	else
	{
		for(unsigned long i = 1; i < num_samples; i++)
		{  
			if (signal[i] == signal[i-1])
				count++;

			if (( signal[i] != signal[i-1]) || (i == (num_samples-1)))
			{
				printf(",%lu",count);
				count_compression++;
				count = 1;
			}
			
		}
		if (signal[num_samples-1] != signal[num_samples-2])
		{
			printf(",%u",1);
			count_compression++;
		}
	}

    printf("\nnum symbols in rle: %.0lf\n",(count_compression));
    printf("compression rate: x%1.1lf\n",(num_samples/count_compression));
}
