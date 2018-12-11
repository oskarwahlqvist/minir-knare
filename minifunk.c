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

#include "minifunk.h"					//inkluderar filen minifunk.h		



double plus(double t1, double t2)		//Funktion Plus		
{										//Skickar tillbaka resultatet av tal1 plus tal2
	return t1 + t2;
}

double minus(double t1, double t2)		//Funktion minus		
{										//Skickar tillbaka resulttet av tal1 minus tal2
	return t1 - t2;
}

double ganger(double t1, double t2)		//Funktion Ganger		
{										//Skickar tillbaka resultatet av tal1 ganger tal2		
	return t1 * t2;
}

double delat(double t1, double t2)		//Funktion Delat		
{										//Skickar tillbaka resultatet av tal1 delat med tal2
	return t1 / t2;
}

double t1pi(double t1)					//Funktion PI			
{										//Skickar tillbaka resultatet av tal1 ganger PI
	return (t1 * PI);
}

double rotenur(double t1)				//Funktion Rotenur	
{										//Skickar tillbaka resultatet av roten ur tal1
	return sqrt(t1);
}

double omkrets_cirkel(double r)			//Funktion Omkretsen Cirkel
{										//Skickar tillbaka omkretsen av en cirkel
	return ((2 * PI) * r); 
}

double arean_cirkel(double r)			//Funktion Arean Cirkel
{										//Skickar tillbaka arean av en cirkel
	return (r * r * PI);
}