#include <stdio.h>
//Estadísticas PH
int main(){
	int parametro, i;
	int nfuente;
	float ph, phmedia=0, phMax, phMin;

	FILE*fichero;
	fichero = fopen("Otro.txt", "r");
	
	if(fichero==NULL){
		printf("Error, no se puede abrir el fichero.\n");
		return 0;
	}
	
	fscanf(fichero, "%d", &parametro);
	printf("Numero de fuentes: %d\n", parametro);

	phMax=0;
	for(i=0; i<parametro; i++){
		fscanf(fichero, "%d %f\n", &nfuente, &ph);
		printf("%d %f\n", nfuente, ph);
		phmedia+=ph;
		if(ph>phMax){
			phMax=ph;
		} break; //Preguntarlo
	}
	
	phMin=0;
	for(i=0; i<parametro; i++){
		fscanf(fichero, "%d %f\n", &nfuente, &ph);
		printf("%d %f\n", nfuente, ph);
		phmedia+=ph;
		if(ph<phMin){
			phMin=ph;
		}
	}
	printf("La media del PH es: %f\n", phmedia/parametro);
	printf("El PH maximo es: %f\n", phMax);
	printf("El PH minimo es: %f\n", phMin);
	
	
	//Paso 3: Cerrar el archivo
	fclose(fichero);
	
	// Operacion de escritura en un archivo
	FILE *fsalida;
	//Paso 1: Abrir el archivo
	fsalida=fopen("estadisticasPH.txt", "w");
	if(fsalida==NULL){
		printf("Error, no se puede crear el fichero.\n");
		return 0;
	}
	//Paso 2: Escribir en el archivo
	fprintf(fsalida, "La media del PH es: %f\n", phmedia/parametro);
	fprintf(fsalida, "El PH maximo es: %f\n", phMax);
	fprintf(fsalida, "El PH minimo es: %f\n", phMin);
	
	//Paso 3. Crear el archivo
	fclose(fsalida);
	return 0;
}
