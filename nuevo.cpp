#include <stdio.h>
#include <math.h>
#include <string.h>

struct FuenteAgua{ //Estructura del programa
	char parametros[25];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
	char nombre[50];
};



	int main(){
	int opcion, opcion2, numfuente; 
	
	
	//INTERFAZ
	printf("     \n"); 
	printf("				*************************************************\n"); 
	printf("				*                                               *\n");
	printf("				*                                               *\n"); 
	printf("				*           OBJETIVO MEDIO AMBIENTE             *\n");
	printf("				*           -----------------------             *\n"); 
	printf("				*          Investigacion de las aguas           *\n");
	printf("				*                  madrilenas                   *\n"); 
	printf("				*                                               *\n");
	printf("				*                                               *\n"); 
	printf("				*                                               *\n");
	printf("				*************************************************\n"); 
		printf("     \n"); 
	printf("			   Bienvenidos a nuestro proyecto de investigacion acerca de\n"); 
	printf("			   las aguas madrilenas, donde podras conocer informacion\n");
	printf("			   interactuando con cada una de las opciones que hay debajo:\n"); 
	printf("     \n"); 
	do{

		
	printf("	1.Informacion general acerca de las fuentes\n"); //informacion general acerca de una fuente 
	printf("	2.Buscar una fuente concreta\n");//informacion acerca de una fuente concreta introduciendola por pantalla
	printf("	3.Cual es el pH maximo de todas las fuentes\n");
	printf("	4.\n");
	printf("	5.\n");
	printf("	6.\n");
	printf("	7.Salir\n");
	scanf("%d", &opcion);
	 
	if(opcion>7 || opcion<1){
			printf("    \n");
			printf("Opcion incorrecta, seleccione el numero correspondiente a la opcion deseada\n");
			printf("    \n");
	}
	
	

	switch (opcion){
		do{
		
		case 1: 
			printf("      \n");
			printf("1.Embajadores\n"); 
			printf("2.Delicias\n"); 
			printf("3.Lavapies\n"); 
			printf("4.Menu principal\n");
			printf("      \n");
			scanf("%d", &opcion2);
			FILE *archivo;
			
			switch (opcion2){
					case 1: 
						printf("Informacion acerca de las fuentes de Embajadores: \n");
						printf("*************************************************\n");
	   					int caracter;
	  					archivo = fopen("embajadores.txt", "r");
	
	   					if (archivo == NULL) {
	      				printf("No se pudo abrir el archivo.\n");
	      				return 1;
	   					}
	
	   					while ((caracter = fgetc(archivo)) != EOF) {
	      				printf("%c", caracter);
	   					}
	
	   					fclose(archivo);
						break;				
					
				
					case 2: 
						printf("Informacion acerca de las fuentes de Delicias: \n");
						printf("**********************************************\n");
	
	  					archivo = fopen("delicias.txt", "r");
	
	   					if (archivo == NULL) {
	      				printf("No se pudo abrir el archivo.\n");
	      				return 1;
	   					}
	
	   					while ((caracter = fgetc(archivo)) != EOF) {
	      				printf("%c", caracter);
	   					}
	
	   					fclose(archivo);
						break;				
				
					
					case 3: 
						printf("Informacion acerca de las fuentes de Lavapies: \n");
						printf("**********************************************\n");
	
	  					archivo = fopen("lavapies.txt", "r");
	
	   					if (archivo == NULL) {
	      				printf("No se pudo abrir el archivo.\n");
	      				return 1;
	   					}
	
	   					while ((caracter = fgetc(archivo)) != EOF) {
	      				printf("%c", caracter);
	   					}
	
	   					fclose(archivo);
						break;		
					case 4: 
					printf(" "); 
					break;
			
					default: 
					printf("Opcion incorrecta, selecciona el numero correspondiente a la opcion deseada\n");
					break;
					}				
					
			}while(opcion2!=4);
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			}
				



	
	}while(opcion != 7); 
	printf("Gracias por visitarnos. Vuelve pronto.");
return 0;
}
