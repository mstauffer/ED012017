#include <stdio.h>
#include <math.h>

float DesvioP(float valores[], float* md, float* vr, float* dp, int tam){
    int i, qtd = 10;
    float total = 0, submedia;

    for(i=0;i<tam;i++){
        printf("Informe o %d valor: ", i+1);
        scanf("%f", &valores[i]);
        total = total + valores[i];
    }
    *md = total/qtd;
    submedia = 0;
    for(i=0;i<tam;i++){
        submedia = submedia +((valores[i] - *md)*(valores[i] - *md));
    }
    *vr = (submedia/qtd);
    *dp = sqrt(*vr);
    return *dp;
}

int main(){
    float valores[10], md, vr, dp;
    int tam;

    printf("Informe qual o tamanho do vetor desejado,\npara que se calcule seu desvio padrao, media e variancia: \n");
    scanf("%d", &tam);
    DesvioP(valores, &md, &vr, &dp, tam);
    printf("\nA media dos valores informados eh: %f\n", md);
    printf("A variancia eh: %f\n", vr);
    printf("O desvio padrao eh: %f\n", dp);

    return 0;
}