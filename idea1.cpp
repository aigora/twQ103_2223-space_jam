#include <stdio.h>
#include <string.h>

struct FuenteAgua{
	char parametros[25];
	float pH;
	int conductividad;
	int turbidez;
	int coliformes;
};

void buscar_por_ph(struct FuenteAgua fuentes[], int n, float ph, int i) {
    int encontradas = 0;
    for (i = 0; i < n; i++) {
        if (fuentes[i].pH == ph) {
            printf("Fuente_%d:\n", i + 1);
            printf("Parámetros: %s\n", fuentes[i].parametros);
            printf("pH: %.2f\n", fuentes[i].pH);
            printf("Conductividad: %d\n", fuentes[i].conductividad);
            printf("Turbidez: %d\n", fuentes[i].turbidez);
            printf("Coliformes: %d\n", fuentes[i].coliformes);
            encontradas++;
        }
    }
    if (encontradas == 0) {
        printf("No se encontraron fuentes de agua con pH %.2f\n", ph);
    }
}

void filtrar(struct FuenteAgua fuentes[], int n, int coliformes, int conductividad, int turbidez, int i) {
    int encontradas = 0;
    for (i = 0; i < n; i++) {
        if (fuentes[i].coliformes > coliformes &&
            fuentes[i].conductividad < conductividad &&
            fuentes[i].turbidez < turbidez) {
            printf("Fuente_%d:\n", i + 1);
            printf("Parámetros: %s\n", fuentes[i].parametros);
            printf("pH: %.2f\n", fuentes[i].pH);
            printf("Conductividad: %d\n", fuentes[i].conductividad);
            printf("Turbidez: %d\n", fuentes[i].turbidez);
            printf("Coliformes: %d\n", fuentes[i].coliformes);
            encontradas++;
        }
    }
    if (encontradas == 0) {
        printf("No se encontraron fuentes de agua que cumplan con los criterios de filtrado\n");
    }
}

int main(){
	FILE *fichero = fopen("ficheroagua.txt", "r");
	
		if (fichero == NULL) {
		printf("Error, no puede abrir el fichero.\n");
		return 0;
	}
	
	int n,i;
	fscanf(fichero, "%d", &n);
	
	struct FuenteAgua fuentes[n];
	for(i=0;i<n;i++){
		fscanf(fichero, "%s %f %d %d %d", fuentes[i].parametros, fuentes[i].pH,fuentes[i].conductividad, fuentes[i].coliformes, fuentes[i].turbidez);
	}	
}
