#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int CalcCosto(int,int);
int CalcDescuento(int,int);
int TotalClie(int,int,int,int);
int TotalRec(int,int,int,int);
int ValorCalc(int);											//Prototipos
void MayorRecaudador(int,int,int,int,char[]);
void MenorRecaudador(int,int,int,int,char[]);
void MasValorado(int,int,int,int,char[]);
void MenorValorado(int,int,int,int,char[]);
void MayorCliente(int,int,int,int,char[]);
void MenorCliente(int,int,int,int,char[]);
void InformesFin(int,int,int,int,int,int,int,int,int,int,int,int);

main()
{
	
	system("color 70"); //cambiar color pantalla "fondo/letra" 
	
	int SelecPuesto,SelecProducto,Pago,Cantidad,CompraMas;//Ingresadas
	int Rec1=0,Rec2=0,Rec3=0,Rec4=0;		//Recaudados
	int Clie1=0,Clie2=0,Clie3=0,Clie4=0; 		//Clientes
	int costo,descuento; 								//Calculos
	int Opinion,Valoracion1=0,Valoracion2=0,Valoracion3=0,Valoracion4=0; //opiniones
	char nomb[20];
	 
	printf("\n\t1- Puesto 1\n\t2- Puesto 2\n\t3- Puesto 3\n\t4- Puesto 4\n\t0- Salir\n\n\tSeleccione un puesto: ");//Seleccion de Puesto
	scanf("%i",&SelecPuesto);
	
	system("cls");

	while (SelecPuesto!=0) 	//Repeticion del menu
	{
		
		printf("\n\tIngrese su nombre antes de realizar el pedido: "); //ingreso de nombre
		scanf("%s",&nomb);
		
		system("cls");
		
		costo=0; //asignacion a 0 para que no se acumule con los costos de anteriores puestos.
		
		do //bucle por si desea comprar diferentes articulos
		{
			printf("\n\t1- Paty 100\n\t2- Empanada 20\n\t3- Pizza 150\n\n\tSeleccione un producto: "); 	//Seleccion de Producto
			scanf("%i",&SelecProducto);
			
			printf("\n\tIngrese cantidad deseada: "); 		//Cantidad del producto
			scanf("%i",&Cantidad);
			
			costo+=CalcCosto(SelecProducto,Cantidad);  // calculo de costo normal
			
			printf("\n\t0- No\n\t1- Si\n\t \xA8 Desea comprar otro producto ?: "); //condicion para bucle
			scanf("%i",&CompraMas);
			
			system("cls");
		
		}while(CompraMas==1); //comprueba condicion
		
		printf("\n\tCosto: %i",costo);//mostrar costo
		
		printf("\n\n\t1-Efectivo\n\t2-Tarjeta\n\n\tSeleccione medio de pago: "); 	//Medio de pago
		scanf("%i",&Pago);
		
		descuento=CalcDescuento(costo,Pago);		// calculo de costo final
		
		printf("\n\tCosto Final: %i\n\n\t",descuento); //mostrar costo final con descuento aplicado
		
		system("pause");
		system("cls");
		
		printf("\n\t1- Excelente\n\t2- Bueno\n\t3- Malo\n\t4- Pesimo\n\n\tEscriba su opinion sobre el puesto: "); //Opinion
		scanf("%i",&Opinion);
		
		switch (SelecPuesto)  // acumuladores, contadores, y funciones para valoracion
			{
				case 1:
					Valoracion1+=ValorCalc(Opinion); //llamado a funcion para acumular valoracion
					Rec1+=descuento; //acumulador de dinero recaudado
					Clie1++; //contador de clientes
					break;
					
				case 2:
					Valoracion2+=ValorCalc(Opinion); //llamado a funcion para acumular valoracion
					Rec2+=descuento;//acumulador de dinero recaudado
					Clie2++;//contador de clientes
					break;
				case 3:
					
					Valoracion3+=ValorCalc(Opinion); //llamado a funcion para acumular valoracion
					Rec3+=descuento;//acumulador de dinero recaudado
					Clie3++;//contador de clientes
					break;
					
				case 4:
					Valoracion4+=ValorCalc(Opinion); //llamado a funcion para acumular valoracion
					Rec4+=descuento;//acumulador de dinero recaudado
					Clie4 ++;//contador de clientes
					break;
			}
		
		system("cls");
		
		printf("\n\t \xAD %s gracias por tu compra ! \n\n\t", nomb); // muestra nombre por pantalla
		
		system("pause");
		system("cls");
	
		printf("\n\t1-Puesto 1\n\t2-Puesto 2\n\t3-Puesto 3\n\t4-Puesto 4\n\t0-Salir\n\n\tSeleccione un puesto: ");	//Menu, repeticion
		scanf("%i",&SelecPuesto);
		
		system("cls");
		
	}
	
	InformesFin(Clie1,Rec1,Clie2,Rec2,Clie3,Rec3,Clie4,Rec4,Valoracion1,Valoracion2,Valoracion3,Valoracion4);

	
	getchar();
}

int CalcCosto(int SelecProducto,int Cantidad) //Calculo de costo teniendo en cuenta producto y cantidad
{
		int Costo;
		if (SelecProducto==1)Costo=100*Cantidad;			//if para saber el costo del producto			
		else if (SelecProducto==2)Costo=20*Cantidad;					
		else Costo=150*Cantidad;
		return(Costo);
}

int CalcDescuento(int costo,int Pago) //calculo del descuento
{
		int Descuento;
		if (Pago==1)Descuento=costo*0.9; 		//if para saber si paga en efectivo o con tarjeta
		else Descuento=costo*1.1;
		return(Descuento);
}

int TotalRec(int Rec1,int Rec2,int Rec3,int Rec4) //calculo del total recaudado
{
	int TotalRec;
	TotalRec=Rec1+Rec2+Rec3+Rec4; //suma de los totales en cada puesto
	return(TotalRec);
}

int TotalClie(int Clie1,int Clie2,int Clie3,int Clie4) //calculo del total de clientes
{
	int TotalClie;
	TotalClie=Clie1+Clie2+Clie3+Clie4; //suma de los totales en cada puesto
	return(TotalClie);
}                                    

int ValorCalc(int Opinion)	//transformacion de la valoracion
{
	int Valoracion;
	switch(Opinion)  //asignacion de un valor por la opinion dada
	{
		case 1: 
			Valoracion=10;
			break;	
			
		case 2:
			Valoracion=5;
			break;	
			
		case 3:
			Valoracion=3;
			break;	
			
		case 4:
			Valoracion=1;
			break;	
	}
	return (Valoracion);
}

void MasValorado(int Valoracion1,int Valoracion2,int Valoracion3,int Valoracion4,char MejorPuesto[9]) //calculo de mayor valorado
{
	if(Valoracion1>Valoracion2 && Valoracion1>Valoracion3 && Valoracion1>Valoracion4) strcpy(MejorPuesto,"Puesto 1");
	else if(Valoracion2>Valoracion1 && Valoracion2>Valoracion3 && Valoracion2>Valoracion4) strcpy(MejorPuesto,"Puesto 2");
	else if(Valoracion3>Valoracion1 && Valoracion3>Valoracion2 && Valoracion3>Valoracion4) strcpy(MejorPuesto,"Puesto 3");
	else if(Valoracion4>Valoracion1 && Valoracion4>Valoracion2 && Valoracion4>Valoracion3) strcpy(MejorPuesto,"Puesto 4");
	else strcpy(MejorPuesto,"Empate");
}

void MenorValorado(int Valoracion1,int Valoracion2,int Valoracion3,int Valoracion4,char PeorPuesto[9]) //calculo de menor valorado
{
	if(Valoracion1<Valoracion2 && Valoracion1<Valoracion3 && Valoracion1<Valoracion4) strcpy(PeorPuesto,"Puesto 1");
	else if(Valoracion2<Valoracion1 && Valoracion2<Valoracion3 && Valoracion2<Valoracion4) strcpy(PeorPuesto,"Puesto 2");
	else if(Valoracion3<Valoracion1 && Valoracion3<Valoracion2 && Valoracion3<Valoracion4) strcpy(PeorPuesto,"Puesto 3");
	else if(Valoracion4<Valoracion1 && Valoracion4<Valoracion2 && Valoracion4<Valoracion3) strcpy(PeorPuesto,"Puesto 4");
	else strcpy(PeorPuesto,"Empate");
}

void MayorRecaudador(int Rec1,int Rec2,int Rec3,int Rec4,char MayRec[9]) //calculo de mayor recaudador
{
	if(Rec1>Rec2 && Rec1>Rec3 && Rec1>Rec4) strcpy(MayRec,"Puesto 1");
	else if(Rec2>Rec1 && Rec2>Rec3 && Rec2>Rec4) strcpy(MayRec,"Puesto 2");
	else if(Rec3>Rec1 && Rec3>Rec2 && Rec3>Rec4) strcpy(MayRec,"Puesto 3");
	else if(Rec4>Rec1 && Rec4>Rec2 && Rec4>Rec3) strcpy(MayRec,"Puesto 4");
	else strcpy(MayRec,"Empate");	
}

void MenorRecaudador(int Rec1,int Rec2,int Rec3,int Rec4,char MinRec[9]) //calculo de menor recaudador
{
	if(Rec1<Rec2 && Rec1<Rec3 && Rec1<Rec4) strcpy(MinRec,"Puesto 1");
	else if(Rec2<Rec1 && Rec2<Rec3 && Rec2<Rec4) strcpy(MinRec,"Puesto 2");
	else if(Rec3<Rec1 && Rec3<Rec2 && Rec3<Rec4) strcpy(MinRec,"Puesto 3");
	else if(Rec4<Rec1 && Rec4<Rec2 && Rec4<Rec3) strcpy(MinRec,"Puesto 4");
	else strcpy(MinRec,"Empate");	
}
																	  
void MayorCliente(int Clie1,int Clie2,int Clie3,int Clie4,char MayClie[9]) //calculo de mayor clientela
{}                                                                        
	if(Clie1>Clie2 && Clie1>Clie3 && Clie1>Clie4) strcpy(MayClie,"Puesto 1");
	else if(Clie2>Clie1 && Clie2>Clie3 && Clie2>Clie4) strcpy(MayClie,"Puesto 2");
	else if(Clie3>Clie1 && Clie3>Clie2 && Clie3>Clie4) strcpy(MayClie,"Puesto 3");
	else if(Clie4>Clie1 && Clie4>Clie2 && Clie4>Clie3) strcpy(MayClie,"Puesto 4");
	else strcpy(MayClie,"Empate");
}
	  
void MenorCliente(int Clie1,int Clie2,int Clie3,int Clie4,char MinClie[9]) //calculo de menor clientela
{
	if(Clie1<Clie2 && Clie1<Clie3 && Clie1<Clie4) strcpy(MinClie,"Puesto 1");
	else if(Clie2<Clie1 && Clie2<Clie3 && Clie2<Clie4) strcpy(MinClie,"Puesto 2");
	else if(Clie3<Clie1 && Clie3<Clie2 && Clie3<Clie4) strcpy(MinClie,"Puesto 3");
	else if(Clie4<Clie1 && Clie4<Clie2 && Clie4<Clie3) strcpy(MinClie,"Puesto 4");
	else strcpy(MinClie,"Empate");
}

void InformesFin(int Clie1,int Rec1,int Clie2,int Rec2,int Clie3,int Rec3,int Clie4,int Rec4,int Valoracion1,int Valoracion2,int Valoracion3,int Valoracion4)
{
	char MinClie[9],MayClie[9],MejorPuesto[9],MinRec[9],MayRec[9],PeorPuesto[9]; //Mejores y peores
		
	printf("\n\tPuesto 1 tuvo %i clientes y recaudo %i",Clie1,Rec1);
	printf("\n\tPuesto 2 tuvo %i clientes y recaudo %i",Clie2,Rec2);		//informes de acumuladores y contadores
	printf("\n\tPuesto 3 tuvo %i clientes y recaudo %i",Clie3,Rec3);
	printf("\n\tPuesto 4 tuvo %i clientes y recaudo %i",Clie4,Rec4);		
	
	printf("\n\tHubo un total de %i clientes y %i recaudado\n\n\t",TotalClie(Clie1,Clie2,Clie3,Clie4),TotalRec(Rec1,Rec2,Rec3,Rec4)); //informe de totales
	
	system("pause");	
	system("cls");
	
	MasValorado(Valoracion1,Valoracion2,Valoracion3,Valoracion4,MejorPuesto);
	MenorValorado(Valoracion1,Valoracion2,Valoracion3,Valoracion4,PeorPuesto);
	MayorRecaudador(Rec1,Rec2,Rec3,Rec4,MayRec);
	MenorRecaudador(Rec1,Rec2,Rec3,Rec4,MinRec);		//llados a funciones
	MayorCliente(Clie1,Clie2,Clie3,Clie4,MayClie);
	MenorCliente(Clie1,Clie2,Clie3,Clie4,MinClie);
	
	printf("\n\t El puesto con mayor calificacion fue:\t\t%s",MejorPuesto);  
	printf("\n\t El puesto con menor calificacion fue:\t\t%s",PeorPuesto); 
	printf("\n\t El puesto que recaudo mas fue:\t\t\t%s",MayRec);		
	printf("\n\t El puesto que recaudo menos fue:\t\t%s",MinRec);		//informe de mayores y menores
	printf("\n\t El puesto con mayor cantidad de clientes fue:\t%s",MayClie);
	printf("\n\t El puesto con menor cantidad de clientes fue:\t%s",MinClie);
}
