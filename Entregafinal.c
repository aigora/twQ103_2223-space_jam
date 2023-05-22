#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARAMETROS 50
#define MAX_NOMBRE 50
#define MAX_FUENTES 25
#define MAX_LINE_LENGTH 100

struct FuenteAgua {
    char parametros[MAX_PARAMETROS];
    float pH;
    int conductividad;
    int turbidez;
    int coliformes;
    char nombre[MAX_NOMBRE];
};

void obtenerDatosFuente(struct FuenteAgua fuentes[], int numfuente, const char nombreBuscado[]) {
    int i;
    for (i = 0; i < numfuente; i++) {
        if (strcmp(fuentes[i].nombre, nombreBuscado) == 0) {
            printf("\nInformacion de la fuente de agua '%s':\n", nombreBuscado);
            printf("pH: %.2f\n", fuentes[i].pH);
            printf("Conductividad: %d\n", fuentes[i].conductividad);
            printf("Turbidez: %d\n", fuentes[i].turbidez);
            printf("Coliformes: %d\n", fuentes[i].coliformes);
            return;
        }
    }
    printf("\nFuente de agua '%s' no encontrada.\n", nombreBuscado);
}

void buscar_por_ph(struct FuenteAgua fuentes[], int numfuente, float ph) {
    int i, found = 0;
    printf("\nFuentes de agua con pH %.2f:\n", ph);
    for (i = 0; i < numfuente; i++) {
        if (fuentes[i].pH == ph) {
            printf("Fuente_%d:\n", i + 1);
            printf("Conductividad: %d\n", fuentes[i].conductividad);
            printf("Turbidez: %d\n", fuentes[i].turbidez);
            printf("Coliformes: %d\n", fuentes[i].coliformes);
            printf("Nombre: %s\n", fuentes[i].nombre);
            found = 1;
        }
    }
    if (!found) {
        printf("No se encontraron fuentes de agua con pH %.2f\n", ph);
    }
}

float calcularPromedioPH(struct FuenteAgua fuentes[], int numfuente) {
    int i;
    float pHmedia = 0;
    for (i = 0; i < numfuente; i++) {
        pHmedia += fuentes[i].pH;
    }
    return pHmedia / numfuente;
}

float calcularMaximoPH(struct FuenteAgua fuentes[], int numfuente) {
    float maxPh = fuentes[0].pH;
    int i;
    for (i = 1; i < numfuente; i++) {
        if (fuentes[i].pH > maxPh) {
            maxPh = fuentes[i].pH;
        }
    }
    return maxPh;
}

float pHmin(struct FuenteAgua fuentes[], int numfuente) {
    float minPh = fuentes[0].pH;
    int i;
    for (i = 1; i < numfuente; i++) {
        if (fuentes[i].pH < minPh) {
            minPh = fuentes[i].pH;
        }
    }
    return minPh;
}


int conductividadMax(struct FuenteAgua fuentes[], int numfuente) {
    int maxCond = fuentes[0].conductividad;
    int i;
    for (i = 1; i < numfuente; i++) {
        if (fuentes[i].conductividad > maxCond) {
            maxCond = fuentes[i].conductividad;
        }
    }
    return maxCond;
}



int conductividadMin(struct FuenteAgua fuentes[], int numfuente) {
    int minCond = fuentes[0].conductividad;
    int i;
    for (i = 1; i < numfuente; i++) {
        if (fuentes[i].conductividad < minCond) {
            minCond = fuentes[i].conductividad;
        }
    }
    return minCond;
}

float calcularPromedioConductividad(struct FuenteAgua fuentes[], int numfuente) {
    int i;
    float Conductividadmedia = 0;
    for (i = 0; i < numfuente; i++) {
        Conductividadmedia += fuentes[i].conductividad;
    }
    return Conductividadmedia / numfuente;
}

int turbidezMax(struct FuenteAgua fuentes[], int numfuente){
	int maxTurb = fuentes[0].turbidez;
	int i;
	for (i=1; i < numfuente; i++){
		if(fuentes[i].turbidez > maxTurb){
			maxTurb = fuentes[i].turbidez;
		}
	}
	return maxTurb;
}

int turbidezMin(struct FuenteAgua fuentes[], int numfuente){
	int minTurb = fuentes[0].turbidez;
	int i;
	for (i=1; i < numfuente; i++){
		if(fuentes[i].turbidez < minTurb){
			minTurb = fuentes[i].turbidez;
		}
	}
	return minTurb;
}

float calcularPromedioTurbidez(struct FuenteAgua fuentes[], int numfuente) {
    int i;
    float Turbidezmedia = 0;
    for (i = 0; i < numfuente; i++) {
        Turbidezmedia += fuentes[i].turbidez;
    }
    return Turbidezmedia / numfuente;
}

int coliformesMax(struct FuenteAgua fuentes[], int numfuente){
	int maxColi = fuentes[0].coliformes;
	int i;
	for (i=1; i < numfuente; i++){
		if(fuentes[i].coliformes > maxColi){
			maxColi = fuentes[i].coliformes;
		}
	}
	return maxColi;
}

int coliformesMin(struct FuenteAgua fuentes[], int numfuente){
	int minColi = fuentes[0].coliformes;
	int i;
	for (i=1; i < numfuente; i++){
		if(fuentes[i].coliformes < minColi){
			minColi = fuentes[i].coliformes;
		}
	}
	return minColi;
}

float calcularPromedioColiformes(struct FuenteAgua fuentes[], int numfuente) {
    int i;
    float Coliformesmedia = 0;
    for (i = 0; i < numfuente; i++) {
        Coliformesmedia += fuentes[i].coliformes;
    }
    return Coliformesmedia / numfuente;
}

int main() {
    struct FuenteAgua fuentes[MAX_FUENTES];
    int numfuente = 0;
    char nombreBuscado[MAX_NOMBRE];
    float promedioPh, maxPh, minPh;
    int maxCond, minCond, maxTurb, minTurb, maxColi, minColi;
    int opcion, opcion2;
    char filename[100];
    
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
    
    printf("Introduce el nombre del archivo: (delicias.txt, embajadores.txt, 202301_ Lavapies.txt)\n ");
	scanf("%s", filename);

    // Abrir el archivo en modo lectura
    FILE *archivo = fopen(filename, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Leer el archivo línea por línea
    char linea[MAX_LINE_LENGTH];
    fgets(linea, sizeof(linea), archivo); // Leer y descartar la primera línea (encabezado)
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Extraer los datos de la línea
        sscanf(linea, "%s %f %d %d %d %[^\n]", fuentes[numfuente].nombre, &fuentes[numfuente].pH, &fuentes[numfuente].conductividad, &fuentes[numfuente].turbidez, &fuentes[numfuente].coliformes, fuentes[numfuente].parametros);
        numfuente++;
        if (numfuente >= MAX_FUENTES) {
            break;
        }
    }


    // Cerrar el archivo de entrada
    fclose(archivo);

    
    while (opcion != 8) {
        printf("\n----- Menu Principal -----\n");
        printf("1. Obtener datos de una fuente de agua\n");//Tienes que escribir por ejemplo Fuente22 para que funcione.
        printf("2. Buscar fuentes de agua por pH\n");
        printf("3. Calcular promedio de pH\n");
        printf("4. Calcular maximo pH\n");
        printf("5. Calcular minimo pH\n");
        printf("6. Estadasticas de calidad del agua\n");
        printf("7. Ver fichero completo\n");
		printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: {
                printf("Ingrese el nombre de la fuente a buscar: ");
    			scanf("%s", nombreBuscado);
    			obtenerDatosFuente(fuentes, numfuente, nombreBuscado);
                break;
            }
            case 2: {
            	printf("\nIngrese el valor del pH a buscar: ");
    			scanf("%f", &promedioPh);
    			buscar_por_ph(fuentes, numfuente, promedioPh);
                break;
            }
            case 3: {
                printf("\nPromedio del pH de todas las fuentes: %.2f\n", calcularPromedioPH(fuentes, numfuente));
                break;
            }
            case 4: {
               	maxPh = calcularMaximoPH(fuentes, numfuente);
                printf("pH maximo: %.2f\n", maxPh);
                break;
            }
            case 5: {
                float minimo = pHmin(fuentes, numfuente);
                printf("\npH minimo: %.2f\n", minimo);
                break;
            }
            case 6: {
                maxCond = conductividadMax(fuentes, numfuente);
    			minCond = conductividadMin(fuentes, numfuente);
    			maxTurb = turbidezMax(fuentes, numfuente);
    			minTurb = turbidezMin(fuentes, numfuente);
    			maxColi = coliformesMax(fuentes, numfuente);
    			minColi = coliformesMin(fuentes, numfuente);
    			
				printf("Conductividad maxima: %d\n", maxCond);
    			printf("Conductividad minima: %d\n", minCond);
    			printf("Promedio de la conductividad de todas las fuentes: %.2f\n", calcularPromedioConductividad(fuentes, numfuente));
    			printf("Turbidez maxima: %d\n", maxTurb);
    			printf("Turbidez minima: %d\n", minTurb);
    			printf("Promedio de la turbidez de todas las fuentes: %.2f\n", calcularPromedioTurbidez(fuentes, numfuente));
    			printf("Coliformes maxima: %d\n", maxColi);
    			printf("Coliformes maxima: %d\n", minColi);
    			printf("Promedio de la coliforme de todas las fuentes: %.2f\n", calcularPromedioColiformes(fuentes, numfuente));
                break;
            }
            case 7: {
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
					default: 
						printf("Opcion incorrecta, selecciona el numero correspondiente a la opcion deseada\n");
						break;
					}
            
            }
            case 8: {
                printf("\nSaliendo del programa...\n");
                break;
            
            }
            default: {
                printf("\nOpcion no valida. Intente nuevamente.\n");
                break;
            }
        }
    }

    return 0;
}
