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

int conductividadMax(struct FuenteAgua fuentes[], int n);
int conductividadMin(struct FuenteAgua fuentes[], int n);
float conductividadmedia(struct FuenteAgua fuentes[], int n);

int turbidezMax(struct FuenteAgua fuentes[], int n);
int turbidezMin(struct FuenteAgua fuentes[], int n);
float turbidezmedia(struct FuenteAgua fuentes[], int n);

int coliformesMax(struct FuenteAgua fuentes[], int n);
int coliformesMin(struct FuenteAgua fuentes[], int n);
float coliformesmedia(struct FuenteAgua fuentes[], int n);

int main() {
	struct FuenteAgua fuentes[25];
	int i;
	int pospHmax;
	int pospHmin;
	float pospHmedia;
	int posconductividadMax;
	int posconductividadMin;
	float posconductividadmedia;
	int posturbidezMax;
	int posturbidezMin;
	float posturbidezmedia;
	int poscoliformesMax;
	int poscoliformesMin;
	float poscoliformesmedia;
	
	FILE *fentrada;
	FILE *fsalida;
	
	fentrada = fopen("202301_Lavapies.txt", "r");
	if (fentrada == NULL) {
		printf("Error leyendo el fichero\n");
		return 0;
	}
	
	i=0;
	fscanf(fentrada, "%s %s %s %s %s", fuentes[i].parametros, &fuentes[i].pH, &fuentes[i].conductividad, &fuentes[i].turbidez, &fuentes[i].coliformes);
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
	pospHmedia = media(fuentes, 25);
	
	posconductividadMax = conductividadMax(fuentes, 25);
	posconductividadMin = conductividadMin(fuentes, 25);
	posconductividadmedia = conductividadmedia(fuentes, 25);
	
	posturbidezMax = turbidezMax(fuentes, 25);
	posturbidezMin = turbidezMin(fuentes, 25);
	posturbidezmedia = turbidezmedia(fuentes, 25);
	
	poscoliformesMax = coliformesMax(fuentes, 25);
	poscoliformesMin = coliformesMin(fuentes, 25);
	poscoliformesmedia = coliformesmedia(fuentes, 25);
	
	printf("El pH maximo es el de la %s, con un ph de %.2f\n", fuentes[pospHmax].parametros, fuentes[pospHmax].pH);
	printf("El pH minimo es el de la %s, con un ph de %.2f\n", fuentes[pospHmin].parametros, fuentes[pospHmin].pH);
	printf("La media de pH es %f\n", pospHmedia);
	
	printf("La conductividad maxima es el de la %s, con una conductividad de %d\n", fuentes[posconductividadMax].parametros, fuentes[posconductividadMax].conductividad);
	printf("La conductividad minima es el de la %s, con una conductividad de %d\n", fuentes[posconductividadMin].parametros, fuentes[posconductividadMin].conductividad);
	printf("La media de conductividad es %f\n", posconductividadmedia);
	
	printf("La turbidez maxima es el de la %s, con una turbidez de %d\n", fuentes[posturbidezMax].parametros, fuentes[posturbidezMax].turbidez);
	printf("La turbidez minima es el de la %s, con una turbidez de %d\n", fuentes[posturbidezMin].parametros, fuentes[posturbidezMin].turbidez);
	printf("La media de turbidez es %f\n", posturbidezmedia);
	
	printf("La coliforme maxima es el de la %s, con una coliforme de %d\n", fuentes[poscoliformesMax].parametros, fuentes[poscoliformesMax].coliformes);
	printf("La coliforme minima es el de la %s, con una coliforme de %d\n", fuentes[poscoliformesMin].parametros, fuentes[poscoliformesMin].coliformes);
	printf("La media de coliforme es %f\n", poscoliformesmedia);
	
	fsalida = fopen("resultados.txt", "w");
	
	/*for (i=0; i<25; i++) {
		fprintf(fsalida,"%s %.2f\n", fuentes[i].parametros, fuentes[i].pH);
	}*/
	fprintf(fsalida, "El pH maximo es el de la %s, con un ph de %.2f\n",  fuentes[pospHmax].parametros, fuentes[pospHmax].pH);
	fprintf(fsalida, "El pH minimo es el de la %s, con un ph de %.2f\n", fuentes[pospHmin].parametros, fuentes[pospHmin].pH);
	fprintf(fsalida, "La media de pH es %f\n", pospHmedia);
	
	fprintf(fsalida, "La conductividad maxima es el de la %s, con una conductividad de %d\n", fuentes[posconductividadMax].parametros, fuentes[posconductividadMax].conductividad);
	fprintf(fsalida, "La conductividad minima es el de la %s, con una conductividad de %d\n", fuentes[posconductividadMin].parametros, fuentes[posconductividadMin].conductividad);
	fprintf(fsalida, "La media de conductividad es %f\n", posconductividadmedia);
	
	fprintf(fsalida, "La turbidez maxima es el de la %s, con una turbidez de %d\n", fuentes[posturbidezMax].parametros, fuentes[posturbidezMax].turbidez);
	fprintf(fsalida, "La turbidez minima es el de la %s, con una turbidez de %d\n", fuentes[posturbidezMin].parametros, fuentes[posturbidezMin].turbidez);
	fprintf(fsalida, "La media de turbidez es %f\n", posturbidezmedia);
	
	fprintf(fsalida, "La coliforme maxima es el de la %s, con una coliforme de %d\n", fuentes[poscoliformesMax].parametros, fuentes[poscoliformesMax].coliformes);
	fprintf(fsalida, "La coliforme minima es el de la %s, con una coliforme de %d\n", fuentes[poscoliformesMin].parametros, fuentes[poscoliformesMin].coliformes);
	fprintf(fsalida, "La media de coliforme es %f\n", poscoliformesmedia);
	
	fclose(fsalida);
		
	return 0;
}
int pHmax(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua pHmax;
	int i, posMax;
	
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

int conductividadMax(struct FuenteAgua fuentes[], int n){
	struct FuenteAgua conductividadMax;
	int i, poscMax;
	conductividadMax = fuentes[0];
	poscMax = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].conductividad> conductividadMax.conductividad) {
		conductividadMax = fuentes[i];
			poscMax = i;
		}
	}
	return poscMax;
}

int conductividadMin(struct FuenteAgua fuentes[], int n){
	struct FuenteAgua conductividadMin;
	int i, poscMin;
	conductividadMin = fuentes[0];
	poscMin = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].conductividad< conductividadMin.conductividad) {
		conductividadMin = fuentes[i];
			poscMin = i;
		}
	}
	return poscMin;
}

float conductividadmedia(struct FuenteAgua fuentes[], int n){
	int i;
	float cmedia=0;
	for(i=0; i<25; i++){
		cmedia+=fuentes[i].conductividad;
	}
	
	cmedia=cmedia/n;
	return cmedia;
}

int turbidezMax(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua turbidezMax;
	int i, postMax;
	
	turbidezMax = fuentes[0];
	postMax = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].turbidez> turbidezMax.turbidez) {
		turbidezMax = fuentes[i];
			postMax = i;
		}
	}
	return postMax;
}

int turbidezMin(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua turbidezMin;
	int i, postMin;
	
	turbidezMin = fuentes[0];
	postMin = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].turbidez< turbidezMin.turbidez) {
		turbidezMin = fuentes[i];
			postMin = i;
		}
	}
	return postMin;
}

float turbidezmedia(struct FuenteAgua fuentes[], int n){
	int i;
	float tmedia=0;
	for(i=0; i<25; i++){
		tmedia+=fuentes[i].turbidez;
	}
	
	tmedia=tmedia/n;
	return tmedia;
}

int coliformesMax(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua coliformesMax;
	int i, posCMax;
	
	coliformesMax = fuentes[0];
	posCMax = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].coliformes> coliformesMax.coliformes) {
		coliformesMax = fuentes[i];
			posCMax = i;
		}
	}
	return posCMax;
}

int coliformesMin(struct FuenteAgua fuentes[], int n){
	
	struct FuenteAgua coliformesMin;
	int i, posCMin;
	
	coliformesMin = fuentes[0];
	posCMin = 0;
	for (i=0; i<25; i++) {
		if (fuentes[i].coliformes< coliformesMin.coliformes) {
		coliformesMin = fuentes[i];
			posCMin = i;
		}
	}
	return posCMin;
}

float coliformesmedia(struct FuenteAgua fuentes[], int n){
	int i;
	float Cmedia=0;
	for(i=0; i<25; i++){
		Cmedia+=fuentes[i].coliformes;
	}
	
	Cmedia=Cmedia/n;
	return Cmedia;
}

