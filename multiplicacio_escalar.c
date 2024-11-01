#include <stdio.h>

#define N 512  // Definim N com 512, tal com indica la pràctica

void InitData(){
int i,j;
srand(334411);
for( i = 0; i < N; i++ )
 for( j = 0; j < N; j++ ){
 Mat[i][j]=(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
 if ( (abs(i - j) <= 3) && (i != j))
 MatDD[i][j] = (((i*j)%3) ? -1 : 1)*(rand()/(1.0*RAND_MAX));
 else if ( i == j )
 MatDD[i][j]=(((i*j)%3)?-1:1)*(10000.0*(rand()/(1.0*RAND_MAX)));
 else MatDD[i][j] = 0.0;
 }
for( i = 0; i < N; i++ ){
 V1[i]=(i<N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V2[i]=(i>=N/2)?(((i*j)%3)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX))):0.0;
 V3[i]=(((i*j)%5)?-1:1)*(100.0*(rand()/(1.0*RAND_MAX)));
}
}


// Funció per multiplicar un vector per un escalar
void MultEscalar(float vect[N], float vec2[N], float alfa) {
    for (int i = 0; i < N; i++) {
        vec2[i] = alfa * vect[i];  // Multiplica cada element del vector pel valor escalar
    }
}

// Funció per inicialitzar el vector (aquesta funció es proporciona ja programada al document)
void InitData(float vect[N]) {
    for (int i = 0; i < N; i++) {
        vect[i] = (i % 2 == 0) ? i : -i;  // Inicialitzem el vector amb valors positius i negatius per fer proves
    }
}

// Funció per imprimir una part del vector
void PrintVect(float vect[N], int from, int numel) {
    for (int i = from; i < from + numel; i++) {
        printf("%f ", vect[i]);  // Imprimeix cada element del vector a partir de la posició 'from'
    }
    printf("\n");  // Salta a la següent línia després d'imprimir
}

int main() {
    float vect[N], vec2[N];
    float alfa = 2.0;  // Multiplicarem el vector per l'escalar 2.0

    // Inicialitzem el vector amb valors positius i negatius alternants
    InitData(vect);

    // Multipliquem el vector pel valor escalar
    MultEscalar(vect, vec2, alfa);

    // Imprimim els primers 10 elements del vector original i del vector resultant
    printf("Vector original (primers 10 elements):\n");
    PrintVect(vect, 0, 10);

    printf("Vector resultat (primers 10 elements després de multiplicar per l'escalar):\n");
    PrintVect(vec2, 0, 10);

    return 0;
}
