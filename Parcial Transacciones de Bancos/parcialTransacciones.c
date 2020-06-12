#include<stdio.h>

int menu();
int deposito(int,int,int,int);
int extraccion(int,int,int,int);

main()
{
	int nrocu,oper,Mc1=1000,Mc2=1000,Mc3=1000,CC1=0,CC2=0,CC3=0,saldo;
	
	oper=menu();
	
	while (oper!=3)
	{
		printf("\n Ingrese numero de cuenta (bobo, entre 1 y 3): ");
		scanf("%i",&nrocu);	
		
		if (oper==1) saldo=deposito(nrocu,Mc1,Mc2,Mc3);
		else if (oper==2) saldo=extraccion(nrocu,Mc1,Mc2,Mc3);
		
		switch (nrocu)
		{
			case 1: 
				CC1++;
				Mc1=saldo;
				break;
			case 2:
				CC2++;
				Mc2=saldo;
				break;
			case 3:
				CC3++;
				Mc3=saldo;
				break;	
		}
		
		oper=menu();
		
	}
	
	printf("\n La cuenta 1 tuvo %i transacciones y tiene un saldo de %i",CC1,Mc1);
	printf("\n La cuenta 2 tuvo %i transacciones y tiene un saldo de %i",CC2,Mc2);
	printf("\n La cuenta 3 tuvo %i transacciones y tiene un saldo de %i",CC3,Mc3);
	
	getchar();
}

int menu()
{
	int operacion;
	printf("\n 1-Deposito\n 2-Extraer\n 3-Salir\n Seleccione una opcion: ");
	scanf("%i",&operacion);
	return (operacion);
}

int deposito(int nrocu,int Mc1,int Mc2,int Mc3)
{
	int monto,saldo;
	printf("\n Ingrese el monto a depositar: ");
	scanf("%i",&monto);
	switch (nrocu)
		{
			case 1: 
				printf("\n Saldo: %i",Mc1);
				saldo=Mc1+monto;
				break;
			case 2:
				printf("\n Saldo: %i",Mc2);
				saldo=Mc2+monto;
				break;
			case 3:
				printf("\n Saldo: %i",Mc3);
				saldo=Mc3+monto;
				break;	
		}
	printf("\n Saldo: %i",saldo);
	return (saldo);
}

int extraccion(int nrocu,int Mc1,int Mc2,int Mc3)
{
	int monto=0,saldo=0;
	printf("\n Ingrese el monto a retirar: ");
	scanf("%i",&monto);
	switch (nrocu)
		{
			case 1: 
				printf("\n Saldo: %i",Mc1);
				if (monto>Mc1) 
				{
					printf("\n Invalido, seguro fue juan....");
					saldo=Mc1;
				}
				else 
				{
					saldo=Mc1-monto;
					printf("\n Saldo: %i",saldo);
				}
				break;
			case 2:
				printf("\n Saldo: %i",Mc2);
				if (monto>Mc2) 
				{
					printf("\n Invalido, seguro fue juan....");
					saldo=Mc2;
				}
				else 
				{
					saldo=Mc2-monto;
					printf("\n Saldo: %i",saldo);
				}
				break;
			case 3:
				printf("\n Saldo: %i",Mc3);
				if (monto>Mc3) 
				{
					printf("\n Invalido, seguro fue juan....");
					saldo=Mc3;
				}
				else 
				{
					saldo=Mc3-monto;
					printf("\n Saldo: %i",saldo);
				}
				break;	
		}
	return (saldo);
}

