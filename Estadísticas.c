#include <stdio.h>

struct FuenteAgua{
	char parametros[25];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
	char nombre[50];
};

int pHmax(struct FuenteAgua fuentes[], int n);
int pHmin(struct FuenteAgua fuentes[], int n);
float media(struct FuenteAgua fuentes[], int n);

int main() {
	struct FuenteAgua fuentes[25];
	int i;
	int pospHmax;
	int pospHmin;
	float pospHmedia;

	FILE *fentrada;
	FILE *fsalida;
	
	fentrada = fopen("ficheroagua.txt", "r");
	if (fentrada == NULL) {
		printf("Error leyendo el fichero\n");
		return 0;
	}
	
	i=0;
	// Leer los datos del fichero a memoria (al vector de estructuras)
	while (fscanf(fentrada, "%s %f %d %d %d", fuentes[i].parametros, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes) != EOF) {
		i++;
	}
	fclose(fentrada);
	
	/*for (i=0; i<25; i++) {
		printf("%s %.2f\n", fuentes[i].parametros, fuentes[i].pH);
	}*/
	
	pospHmax = pHmax(fuentes, 25);
	pospHmin = pHmin(fuentes, 25);
	pospHmedia = media(fuentes,25);
	
	printf("El pH maximo es el de la %s, con un ph de %.2f\n", fuentes[pospHmax].parametros, fuentes[pospHmax].pH);
	printf("El pH minimo es el de la %s, con un ph de %.2f\n", fuentes[pospHmin].parametros, fuentes[pospHmin].pH);
	printf("La media de pH es %f\n", pospHmedia);
	
	fsalida = fopen("resultados.txt", "w");
	
	/*for (i=0; i<25; i++) {
		fprintf(fsalida,"%s %.2f\n", fuentes[i].parametros, fuentes[i].pH);
	}*/
	fprintf(fsalida, "El pH maximo es el de la %s, con un ph de %.2f\n",  fuentes[pospHmax].parametros, fuentes[pospHmax].pH);
	fprintf(fsalida, "El pH minimo es el de la %s, con un ph de %.2f\n", fuentes[pospHmin].parametros, fuentes[pospHmin].pH);
	fprintf(fsalida, "La media de pH es %f\n", pospHmedia);
	fclose(fsalida);
		
	return 0;
}
int pHmax(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua pHmax;
	int i, posMax;
	
	// Calcular ciudad con mayor area
	pHmax = fuentes[0];
	posMax = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].pH> pHmax.pH) {
		pHmax = fuentes[i];
			posMax = i;
		}
	}
	return posMax;
}

int pHmin(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua pHmin;
	int i, posMin;
	
	// Calcular ciudad con mayor area
	pHmin = fuentes[0];
	posMin = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].pH< pHmin.pH) {
		pHmin = fuentes[i];
			posMin = i;
		}
	}
	return posMin;
}

float media(struct FuenteAgua fuentes[], int n){
	int i;
	float pHmedia=0;
	for(i=0; i<25; i++){
		pHmedia+=fuentes[i].pH;
	}
	
	pHmedia=pHmedia/n;
	return pHmedia;
}






