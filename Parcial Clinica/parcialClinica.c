#include <stdio.h>
#include <stdlib.h>
main()
{
	int band=0,menor,edad,especialidad,Tsocio=0,Tprivado=0,Recaudado,Tturnos,Rdermat=0,Rtraumat=0,Rcardio=0,Rneumo=0,paciente,Costo;
	char nombre [50];
	
	printf("\n Socio=1 \n Privado=2 \n Salir=3 \n Ingrese tipo de paciente: ");
	scanf ("%i",&paciente);
	
	while (paciente!=3)
	{
		printf("\n Ingrese su nombre: ");
		scanf("%s",&nombre);
		printf("\n Ingrese su edad: ");
		scanf("%i",&edad);
		printf("\n Dermatologia=1 \n Traumatologia=2 \n Cardiologia=3 \n Neumonologia=4 \n Escoja la especialidad deseada: ");
		scanf("%i",&especialidad);
		
		if (band==0)
		{
			band=1;
			menor=edad;
		}
		else if (edad<menor) menor=edad;
		
		if (paciente==1)
		{
			Tsocio++;
			Costo=0;
		}
		
		else if (paciente ==2)
		{
			Tprivado++;
			Costo=400;
		}
		
			switch (especialidad)
		{
			case 1:
				printf("\n DERMATOLOGIA");
				Rdermat+=Costo;
				printf("\n Valor de consulta: %i",Costo);
				break;
			case 2:
				printf("\n DTRAUMATOLOGIA");
				Rtraumat+=Costo;
				printf("\n Valor de consulta: %i",Costo);
				break;
			case 3:
				printf("\n CARDIOLOGIA");
				Rcardio+=Costo;
				printf("\n Valor de consulta: %i",Costo);
				break;
			case 4:
				printf("\n NEUMONOLOGIA");
				Rneumo+=Costo;
				printf("\n Valor de consulta: %i",Costo);
				break;
		}		
		
		system("\n pause");
		system("cls");
		
		printf("\n Socio=1 \n Privado=2 \n Salir=3 \n Ingrese tipo de paciente: ");
		scanf ("%i",&paciente);
	}
	
	Recaudado=Rdermat+Rtraumat+Rcardio+Rneumo;
	Tturnos=Tsocio+Tprivado;
	
	printf("\n Turnos de socios: %i",Tsocio);
	printf("\n Turnos de privados: %i",Tprivado);
	printf("\n Total de turnos: %i",Tturnos);
	printf("\n Recaudado en dermatologia: %i",Rdermat);
	printf("\n Recaudado en traumatologia: %i",Rtraumat);
	printf("\n Recaudado en cardiologia: %i",Rcardio);
	printf("\n Recaudado en neumologia: %i",Rneumo);
	printf("\n Total recaudado: %i",Recaudado);
	printf("\n Menor edad entre pacientes: %i",menor);
	
	getchar();	
}
