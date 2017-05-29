/*
Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados 1/2017
Alunos: Matheus Stauffer Viana de Oliveira e Rafael Frade Leão
Matricula: 16/0071852 e 15/0145527
Turma: B
Versão do compilador: gcc (SUSE Linux) 6.1.1 20160707 [gcc-6-branch revision 238088]
Copyright (C) 2016 Free Software Foundation, Inc.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32              /* DEFINE AS CONFIGURACOES         */
    #define CLEAR "cls"    /* PARA LIMPAR A TELA PRA WINDOWS  */
#else                      /* OU                              */
    #define CLEAR "clear"  /* LINUX                           */
#endif

typedef struct inicio Inicio;
typedef struct agenda Agenda;

struct inicio{
	Agenda* prim;
};

struct agenda{
	char nome[30];
	char email[40];
	char telefone[10];
	Agenda* prox;
};

Inicio* CriarLista(void){
	Inicio* l = (Inicio*) malloc(sizeof(Inicio));
	l->prim = NULL;
	return l;
}/*Cria a lista inicial*/

void Inserir(Inicio* l){
	Agenda* novo = (Agenda*) malloc(sizeof(Agenda));
	char c;

    while(c != '\n'){
        c = getchar();
        printf("%c", c);
        printf("Insira o nome do contato: \n");
        scanf("%[^\n]s%*c", novo->nome);
    }
    getchar();
	printf("Insira o endereço eletronico do contato: \n");
	scanf("%[^\n]s%*c", novo->email);
	getchar();
    printf("Insira o telefone do contato: \n");
	scanf("%[^\n]s%*c", novo->telefone);
	getchar();
    novo->prox = l->prim;
	l->prim = novo;
	printf("Contato inserido com sucesso!");
	getchar();
}

void Ordenar(Inicio* l){
	Agenda* p;
	Agenda* aux;
	int qual;
	char s[30];

	printf("Como deseja ordenar seus contatos? Se quiser ordenar por nome, digite 1.\n");
	printf("Caso queira ordenar por email, digite 2, e se quiser por telefone, 3.\n");
	scanf("%d", &qual);
	/*Os contatos sao ordenados pelo algortimo BubbleSort, de acordo com a escolha do
	usuario: por nome, email ou telefone. Sao utilizadas funçoes da biblioteca
	string.h para tornar o codigo menos denso.*/
	aux = l->prim;
	if(qual == 1){
		while(aux!=NULL){
			p = aux->prox;
			while(p!=NULL){
				if(strcmp(aux->nome, p->nome) > 0){
					strcpy(s, aux->nome);
					strcpy(aux->nome, p->nome);
					strcpy(p->nome, s);
				}
				p = p->prox;
			}
			aux = aux->prox;
		}
	}/*Fim ordenaçao por NOME*/
	else{
		if(qual == 2){
			while(aux!=NULL){
				p = aux->prox;
				while(p!=NULL){
					if(strcmp(aux->email, p->email) > 0){
						strcpy(s, aux->email);
						strcpy(aux->email, p->email);
						strcpy(p->email, s);
					}
					p = p->prox;
				}
				aux = aux->prox;
			}
		}/*Fim ordenaçao por EMAIL*/
		else{
			while(aux!=NULL){
				p = aux->prox;
				while(p!=NULL){
					if(strcmp(aux->telefone, p->telefone) > 0){
						strcpy(s, aux->telefone);
						strcpy(aux->telefone, p->telefone);
						strcpy(p->telefone, s);
					}
					p = p->prox;
				}
				aux = aux->prox;
			}
		}
	}/*Fim Bloco Else (qual != 1)*/
}

void ImprimirTudo(Inicio* l){
	Agenda* p;
	int validador;

	printf("\t\tCONTATOS\t\t\n");
	if(l->prim == NULL){
		printf("Sua Lista de contatos esta vazia! Digite 1 se deseja incluir novos contatos.\n");
		scanf("%d", &validador);
		if(validador == 1){
			Inserir(l);
		}
	}
	else{
		for(p = l->prim; p != NULL; p = p->prox){
		printf("Nome: %s\n", p->nome);
		printf("Email: %s\n", p->email);
		printf("Telefone: %s\n", p->telefone);
		printf("\n");
		getchar();
		getchar();
		}
	}
}

void ImprimirCTT(Inicio* l){
	Agenda* p;
	int j;
	char validador;
	char nomectt[30];

	getchar();
	printf("Informe o nome do contato que deseja visualizar:\n");
	scanf("%[^\n]s%*c", nomectt);
	j = 0;
	for(p = l->prim; p!=NULL && j!= 1; p = p->prox){
		if(strcmp(p->nome, nomectt) == 0){
			printf("\t\tCONTATO\t\t\n");
			printf("\t\t%s\t\t\n", p->nome);
			printf("\t\t%s\t\t\n", p->email);
			printf("\t\t%s\t\t\n", p->telefone);
			getchar();
			j = 1;
		}

	}
	if(j==0){/*MAS NÃO PODIA SER UM ELSE?*/
		printf("O contato buscado nao existe. Deseja inclui-lo? (S/N)\n");
		scanf("%c", &validador);
		getchar();
		if(validador == 'S' || validador == 's'){
			Inserir(l);
		}
	}
}

void Editar(Inicio* l){
	Agenda* p;
	char s[30], nvnome[30], nvemail[40], nvtelefone[10];
	char keep;
	int j;

	getchar();
	printf("Digite o nome do contato que deseja editar: \n");
	scanf("%[^\n]s%*c", s);
	j = 1;
	for(p = l->prim; p!=NULL && j!=0; p = p->prox){
		if(strcmp(s, p->nome) == 0){
			getchar();
			printf("Digite o novo nome do contato:\n");
			scanf("%[^\n]s%*c", nvnome);
			strcpy(p->nome, nvnome);
			getchar();
			printf("Digite o novo email do contato:\n");
			scanf("%[^\n]s%*c", nvemail);
			strcpy(p->email, nvemail);
			getchar();
			printf("Digite o novo telefone do contato:\n");
			scanf("%[^\n]s%*c", nvtelefone);
			strcpy(p->telefone, nvtelefone);
			j = 0;
		}
	}
	printf("Deseja editar mais algum contato?(S/N)\n");
	scanf("%c", &keep);
	if(keep == 'S' || keep == 's'){
		Editar(l);
	}
}

void Remover(Inicio* l){
	Agenda* ant = NULL;
	Agenda* p = l->prim;
	char keep;
	char nomectt[30];

	getchar();
	printf("Informe o nome do contato que deseja remover:\n");
	scanf("%[^\n]s%*c", nomectt);
	while(p != NULL && strcmp(p->nome, nomectt) != 0){
		ant = p;
		p = p->prox;
	}
	if(p != NULL){
		if(ant == NULL){
			l->prim = p->prox;
			/*O elemento a ser removido foi encontrado na primeira posiçao da lista,
			cujo ponteiro passa a apontar para o proximo elemento, afim de que o
			no´ encontrado possa ser removido.*/
		}
		else{
			ant->prox = p->prox;
			/*O elemento a ser removido foi encontrado no meio lista. Para efetuar a
			operaçao, precisamos que a referencia(Ponteiro) do elemento anterior passe
			a ser a do elemento removido, a fim de manter o encadeamento da lista.*/
		}
		free(p);
	}

	printf("Deseja remover mais algum elemento?(S/N)\n");
	scanf("%c", &keep);
	if(keep == 'S' || keep == 's'){
		Remover(l);
	}
}

int main(){
	int keep;

	Inicio* l = CriarLista();
	do{
	    system(CLEAR);
		printf("\t\tAGENDA DE CONTATOS\t\t\n\n");
		printf("Informe a operacao que deseja realizar:\n");
		printf("1 - Inserir novo contato\n");
		printf("2 - Ordenar Lista de Contatos\n");
		printf("3 - Imprimir toda a Lista de Contatos\n");
		printf("4 - Imprimir Contato especifico\n");
		printf("5 - Editar um contato\n");
		printf("6 - Remover contato\n");
		printf("7 - Encerrar programa\n");
		scanf("%d", &keep);
		while(keep < 1 || keep > 7){
			printf("Informe uma opçao valida!\n");
			scanf("%d", &keep);
		}
		switch(keep){
			case 1:
				Inserir(l);
				break;
			case 2:
				Ordenar(l);
				break;
			case 3:
				ImprimirTudo(l);
				break;
			case 4:
				ImprimirCTT(l);
				break;
			case 5:
				Editar(l);
				break;
			case 6:
				Remover(l);
		}
	} while(keep != 7);


	return 0;
}
