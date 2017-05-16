#include <stdio.h>

int main(){

    int valores[10], i;
    int mat[3][4], j;

    for(i=0;i<10;i++){
        printf("Informe o %d valor: ", i+1);
        scanf("%d", &valores[i]);
    }
    printf("\nResultado Vetor\n");
    for(i=0;i<10;i++){
        printf("O valor da posicao %d eh %d: \n", i+1, valores[i]);
    }
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("Informe o valor da %d linha, coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\nMatriz\n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d\t ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;

}
