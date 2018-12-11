/*

Av: Oskar Wahlqvist
datum: 28/10-2017
Miniräknare med ett antal standard funktioner.
Skolprojekt i syfte på att bli en bättre programmerare. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#include "minifunk.h"									//inkluderar filen minifunk.h				


void skriv(double t1, char *v, double t2, double r)		//Funktionen Skriv
{// Kod från https://www.programiz.com/c-programming/examples/write-file									
														//Skriver in uträkningarna i textfilen minir.txt
	FILE *fp;											//(fptr = fopen("minir.txt") Öppnar filen minir.txt 		
	fp = fopen("minir.txt", "a");						//"a" finns filen så lägger den till från slutet, så inget skrivs över
	
	if(fp == NULL){										//Kollar om filen hittas
	printf("Error, , kan inte hitta filen ");			//Error om filen inte finns
	exit(1);											//Finns inte filen avslutas funktionen	
	}													//
	fprintf(fp,"\n %.1f %s %.1f = %.1f",t1, v, t2, r);	//Vad som ska skrivas in i filen(Tal1, val av funktion, Tal2, Resultat)
	fclose(fp);											//Stänger filen
}// Kod från https://www.programiz.com/c-programming/examples/write-file

char print(char *s)										//Funktionen Print
{	//Kod från "C från början", Av: Jan Skansholm
														//Skriver ut det som finns i minir.txt 	
	FILE *fil;											//
	fil	= fopen("minir.txt", "r");						//Öppnar filen minir.txt	("r" betyder läsa (read))	
	if (fil == NULL) {									//Kollar om filen hittas
		printf("Error, kan inte hitta filen ");			//Error om filen inte finns
		exit(1);										//Finns inte filen avslutas funktionen
	}													//
	while(fgets(s, 500, fil) != NULL)					//Skriver ut 500 tecken från filen
	printf("%s", s);									//Skriver ut 500 tecken från filen
	return s[500];										//Skriver ut 500 tecken från filen
}	//Kod från "C från början", Av: Jan Skansholm



int main () {
	
	
	system("COLOR 2"); 		//Kod som sätter textfärgen till grön i kommandotolken.
							//Koden är tagen från länken under
	//http://blockofcodes.blogspot.se/2013/06/how-to-change-text-color-of-cc-console.html

	double tal1 = 0;		//Variabler för programmet
	double tal2 = 0;
	double radien = 0;
	double resultat = 0;
	
	double *pt1;			//Pointer till tal 1
	pt1 = &tal1;
	
	double *pt2;			//Pointer till tal 2
	pt2 = &tal2;
	
	char val[15]; 			//Den som väljer if sats, senare i programmet.
	char las[500];			//Läs till printfunktionen (500 tecken)

	while (1){				//Upprepar denna kod.
	
	tal1 = 0;				//Rensar värderna så man kan köra om 
	tal2 = 0;				//programmet utan att behöva starta om det.
	val[15] = 0;			//
	
	
		printf("\nSkriv in tal 1: ");		//Skriver in tal 1
		scanf("%lf", &tal1);				////Läser in tal 1
		
		printf("     ______________ Miniraknare _______________");				// Miniräknaren 
		printf("\n    |   1.  +  plus      |   2.  -  minus      |    ");		//Skriver ut valen man har (1-10)
		printf("\n    |   3.  *  ganger    |   4.  /  delatmed   |    ");		//
		printf("\n    |   5.     PI        |   6.    rotenur     |	  ");		//
		printf("\n    |   7. omkretscirkel |   8.   areancirkel  |    ");		//
	 	printf("\n    |   9. las fil       |                     |    ");		//
		printf("\n    |________________ 10. Exit ________________|\n\n");		//
		
		scanf("%s", &val);														//Skannar in valet
		
		if ((strcmp(val, "1") == 0) || (strcmp(val, "+") == 0) || (strcmp(val,"plus") == 0))	//If sats, plus 
		{
			printf("\nSkriv in tal 2: ");										//Skriver tal 2
			scanf("%lf", &tal2);												//Läser in tal 2
			printf("\n%.1lf + %.1lf = %.1lf \n",tal1, tal2, plus(tal1, tal2));  //Skriver ut uträkningen på skärmen
			resultat = plus(tal1, tal2);										//
			skriv(tal1, val, tal2, resultat);									//kör skriv funktionen	
		}
		
		else if ((strcmp(val, "2") == 0) || (strcmp(val, "-") == 0) || (strcmp(val, "minus") ==0))	//If sats, minus
		{
			printf("\nSkriv in tal 2: ");											//Skriver tal 2
			scanf("%lf", &tal2);													//Läser in tal 2
			printf("\n%.1lf - %.1lf = %.1lf \n", tal1, tal2, minus(tal1, tal2));	//Skriver ut uträkningen på skärmen
			resultat = minus(tal1, tal2);
			skriv(tal1, val, tal2, resultat);										//kör skriv funktionen		
		}
		
		else if ((strcmp(val, "3") == 0) || (strcmp(val, "*") == 0) || (strcmp(val, "ganger") ==0))	//If sats, ganger
		{
			printf("\nSkriv in tal 2: ");											//Skriver tal 2
			scanf("%lf", &tal2);													//Läser in tal 2
			printf("\n%.1lf * %.1lf = %.1lf \n",*pt1, *pt2, ganger(*pt1, *pt2));	//Skriver ut uträkningen på skärmen
			resultat = ganger(*pt1, *pt2);
			skriv(*pt1, val, *pt2, resultat);										//kör skriv funktionen		
		}
		
		else if ((strcmp(val, "4") == 0) || (strcmp(val, "/") == 0) || (strcmp(val, "delatmed") ==0) || (strcmp(val, "delat") ==0))	//If sats, delat med
		{
			printf("\nSkriv in tal 2: ");											//Skriver tal 2	
			scanf("%lf", &tal2);													//Läser in tal 2
			printf("\n%.1lf / %.1lf = %.1lf \n",*pt1, *pt2, delat(*pt1, *pt2));		//Skriver ut uträkningen på skärmen
			resultat = delat(*pt1, *pt2);
			skriv(*pt1, val, *pt2, resultat);										//kör skriv funktionen		
		}
		
		else if ((strcmp(val, "5") == 0) || (strcmp(val, "pi") == 0) || (strcmp(val, "PI") ==0))	//If sats, PI
		{
			printf("%.1lf * PI = %.1lf", tal1, t1pi(tal1));							//Skriver ut uträkningen på skärmen
		}
		
		else if ((strcmp(val, "6") == 0) || (strcmp(val, "rotenur") ==0) || (strcmp(val, "roten") == 0 ))
		{
			printf("Roten ur %.1lf = %.1lf", tal1, rotenur(tal1));					//Skriver ut uträkningen på skärmen
		}
		
		else if ((strcmp(val, "7") == 0) || (strcmp(val, "omkrets") == 0) || (strcmp(val, "omkretscirkel") ==0))	//If sats, omkrets cirkel
		{
			printf("\nSkriv in radien: ");
			scanf("%lf", &radien);
			printf("\n2 * PI * %.1lf = %.1lf \n", radien, omkrets_cirkel(radien)); 	//Skriver ut uträkningen på skärmen
		}
		
		else if ((strcmp(val, "8") == 0) || (strcmp(val, "arean") == 0) || (strcmp(val, "areancirkel") ==0))		//If sats, arean cirkel
		{
			printf("\nSkriv in radien: ");
			scanf("%lf", &radien);
			printf("\n%.1lf * %.1lf * PI = %.1lf \n", radien, radien, arean_cirkel(radien));	//Skriver ut uträkningen på skärmen
		}
		
		else if ((strcmp(val, "9") == 0) || (strcmp(val, "las") ==0) || (strcmp(val, "fil") ==0) || (strcmp(val, "lasfil") == 0 ))	//If sats, val
		{
			print(las);				//kör print funktionen	
			printf("\n");			//ger en ny tom rad.
		}
		
		else if ((strcmp(val, "10") == 0) || (strcmp(val, "stop") ==0) || (strcmp(val, "break") ==0) || (strcmp(val, "exit") ==0))  //If sats, exit 
		{
									//Sätter bakgrundsfärgen till 0 (svart) och skrivfärgen till 7 (vit) i kommandotolken (standard färger)
			system("COLOR 07"); 	//Koden är tagen från länken under
									//http://blockofcodes.blogspot.se/2013/06/how-to-change-text-color-of-cc-console.html



			exit(1);				//Avslutar programmet
		}
		
		else 
		{
			printf(" \n Error, fel inmatning \n");	//Om det blir fel vid inmatningen kommer ett Error meddelande.
		}
		
	}	
	
}










































































