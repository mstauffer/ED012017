#include <stdio.h>
#include <stdlib.h>

int main(){
	int m, n, i, j;
	int **p;

	/*Declarar um ponteiro simples permite criar um vetor do tipo selecionado:
	int* permite criar um vetor de elementos inteiros.
	int** permite criar um vetor de elementos int*, ou seja, cada posiçao tem
	seu proprio vetor de elementos inteiros, e isto, na pratica, e´ um vetor
	de valores inteiros com 2 dimensoes, uma matriz.
	int*** permitiria criar um vetor de elementos int**, no qual cada posiçao
	seria um vetor de elementos int**, onde cada posiçao por sua vez seria um
	vetor de elementos int*, onde por fim cada posiçao seria um vetor de valores
	inteiros, e isto na pratica seria, pensando geometricamente, um cubo, ou seja,
	um vetor de inteiros com 3 dimensoes. A logica e´ a mesma para qualquer
	n dimensoes preteridas.*/

	printf("Informe o numero de linhas da sua matriz: \n");
	scanf("%d", &m);
	printf("Informe o numero de colunas da sua matriz: \n");
	scanf("%d", &n);

	p = (int **)malloc (m*sizeof(int*));
	for (int i = 0; i < m; ++i){
		p[i] = (int*)malloc(n*sizeof(int));
		for (int j = 0; j < n; ++j){
			printf("Informe o elemento da linha %d e coluna %d: \n", i+1, j+1);
			scanf("%d", &p[i][j]);
		}
	}
	printf("Sua matriz eh:\n");
	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++j){
			printf("%d\t", p[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < m; ++i){
		free(p[i]);
	}
	free(p);/*
	q = malloc (n*sizeof(int));

	for (int i = 0; i < m; ++i){
		for (int j = 0; j < n; ++i){
			printf("Informe o elemento da linha %d e coluna %d: \n", m+1, n+1);
			scanf("%d", )
		}
	} */

	return 0;
}