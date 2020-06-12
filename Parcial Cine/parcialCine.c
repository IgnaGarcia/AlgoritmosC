#include <stdio.h>
#include <stdlib.h>
main()
{
	int peli,s1=0,s2=0,s3=0,s4=0,vp1,Ev,Tv;

	printf("\n Ingrese numero de pelicula: ");
	scanf ("%i",&peli);
	
	while(s1<41||s2<41||s3<41||s4<41)
	{
		
		switch (peli)
		{
		
			case 1:
				if (s1<41)s1++;
				else printf("\n SIN STOCK");
				break;
			
			case 2:
				if (s2<41)s2++;
				else printf("\n SIN STOCK");
				break;
			
			case 3:
				if (s3<41)s3++;
				else printf("\n SIN STOCK");
				break;
			
			case 4:
				if (s4<41)s4++;
				else printf("\n SIN STOCK");
				break;	
			
			default: printf("\n NO VALIDO");
				
		}
		
		printf("\n Ingrese numero de pelicula: ");
		scanf ("%i",&peli);
		system("cls");

	}
	
	vp1=s1*150;
	Ev=s1+s2+s3+s4;
	Tv=Ev*150;
	
	if (s1>s2&&s1>s3&&s1>s4) printf("\n P1 vendio mas entradas");
	else if (s2>s1&&s2>s3&&s2>s4) printf("\n P2 vendio mas entradas");
	else if (s3>s2&&s3>s1&&s3>s4) printf("\n P3 vendio mas entradas");
	else printf("\n P4 vendio mas entradas");
	
	if (s1<s2&&s1<s3&&s1<s4) printf("\n P1 vendio menos entradas");
	else if (s2<s1&&s2<s3&&s2<s4) printf("\n P2 vendio menos entradas");
	else if (s3<s2&&s3<s1&&s3<s4) printf("\n P3 vendio menos entradas");
	else printf("\n P4 vendio menos entradas");
	
	printf("\nEntradas vendidas: %i",Ev);
	printf("\nTotal recaudado: %i",Tv);
	printf("\nRecaudado con P1: %i",vp1);
			
	getchar();	
	
}
