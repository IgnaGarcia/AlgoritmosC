#include<stdio.h>
#include<stdlib.h>

char PreguntaInicial();		//Prototipos
void MenuDeVino();
int Ingresos();
int MayVenta(int,int);

main()
{
	int Total,Band=0,Mayor,Pedidos=0,AcumVentas=0;
	
	while(PreguntaInicial()=='S') //bucle para muchas compras
	{
		system("cls"); //limpia pantalla
		
		Pedidos++; //contador de pedidos
		
		MenuDeVino();	//lammado al menu de vino y precio

		Total=Ingresos(); // llamado a la funcion de ingresos y calculo de total
		
		system("cls"); //limpia pantalla
		
		AcumVentas+=Total; //acumulador 
		
		Mayor=MayVenta(Total,Band); //llamado a la funcion de calculo de mayor
	}
	
	system("cls");
	
	printf("\n\t La mayor venta fue de un monto de: %i",Mayor);
	
	printf("\n\n\t Hubo %i pedidos",Pedidos);					//Informes finales
	
	printf("\n\n\t Se acumulo un total de: %i",AcumVentas);
	
	printf("\n\n\t");
	
	system("pause");
	
}


char PreguntaInicial() //Pregunta si realiza una venta
{
	char seleccion;
	
	printf("\n\t S-SI\n\t N-NO\n\t Desea realizar una compra?: \t");
	fflush(stdin);
	scanf("%c",&seleccion);
	
	return(seleccion);
}

void MenuDeVino() //Muestra el menu
{
	printf("\n VINOS:\n\t T-Tinto\n\t B-Blanco\n\t R-Rosado\n\n\t");
	
	printf("1-Por botella $200\n\t2-Por caja de botellas $1000");
}

int Ingresos() //Ingreso de datos
{
	char TVino[2];
	int Envase,Cantidad,Total;
	
	printf("\n\n Seleccione tipo de vino: ");
	scanf("%s",&TVino);

	
		
	printf("\n\n Seleccione forma de venta: ");
	scanf("%i",&Envase);
		
	printf("\n\n Ingrese cantidad deseada: ");
	scanf("%i",&Cantidad);
	
	if(Envase==1) Total=200*Cantidad;
	else if (Envase==2) Total=1000*Cantidad;
	
	system("cls");
	
	printf("\n\t Se vendieron %i %s de la manera %i\n\t El total es: %i",Cantidad,TVino,Envase,Total);	
	
	printf("\n\n");
	
	system("pause");
	
	return (Total);
}
	
int MayVenta(int Total,int Band) //Calculo de mayor venta
{
	int MayorVenta=0;
	
	if (Band=0) MayorVenta=Total;
	else if (Total>MayorVenta) MayorVenta=Total;
	
	return(MayorVenta);
}
