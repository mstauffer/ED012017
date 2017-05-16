#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listano ListaNo;

struct lista{
	ListaNo* prim;
};

struct listano{
	int info;
	ListaNo* prox;
};

/*funçao criaçao de listas: retorna uma lista inicialmente vazia
LSE: Lista Simplesmente Encadeada*/
Lista* LSE_Criar(void){
	Lista* l = (Lista*) malloc(sizeof(Lista));
	l->prim = NULL;
	return l;
}
/*Fim Criar Lista Vazia*/

/*inserçao no inicio: recebe como parametros o ponteiro inicial da Lista, aquele
criado na funçao LSE_Criar, pois precisamos da referencia de posiçao da memoria
para armazenar o novo elemento, ja da struct ListaNo, que tera como informaçao o
'inteiro v', outro parametro recebido pela funçao.*/
void LSE_InserirInicio(Lista* l, int v){
	ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
	/*Inicialmente, aloca-se memoria para o novo elemento da lista, usando a funçao
	malloc. O casting (ListaNo*) eh feito para que se trate aquela regiao da memoria
	como uma struct do tipo ListaNo. Declara-se o novo elemento como um ponteiro
	de struct pois sempre precisaremos de sua referencia de posiçao na memoria para
	adicionar novos elementos na lista*/
	novo->info = v;
	/*Atribui-se, como informaçao do novo elemento, o inteiro v. Lembrando que tal
	elemento eh do tipo struct ListaNo, que possui um inteiro info e o ponteiro para
	o proximo elemento da mesma struct*/
	novo->prox = l->prim;
	/*O novo no aponta para o no que era, ate entao, o primeiro da lista, isto eh, 
	o ponteiro para o proximo elemento - do no que estamos inserindo agora - recebe a
	informaçao contida pelo elemento 'l', do tipo struct Lista, que foi criado
	exclusivamente para armazenar a referencia de posiçao de memoria do primeiro elemento
	da lista*/
	l->prim = novo;
	/*O primeiro no da lista eh entao atualizado. 'l' eh tipo struct Lista, que possui
	um unico "parametro": uma referencia (PONTEIRO!!) de uma struct do tipo ListaNo, ou
	seja, uma referencia de um no*/
}
/*Fim Inserir Inicio*/

/*imprimir elementos: cria-se um laço para percorrimento da lista inteira. Para isso, 
a funçao recebe como parametro a referencia(PONTEIRO!!) do primeiro elemento da lista,
que por sua vez tem a referencia do proximo, que tem do seguinte, e assim por diante.*/
void LSE_Imprimir(Lista* l){
	ListaNo* p;
	for(p = l->prim; p!=NULL; p = p->prox)
		printf("info = %d\n", p->info);
	/*O laço 'for' geralmente tem uma variavel auxiliar para armazenar o indice de cada
	elemento. No caso de uma lista, essa variavel, p, deve ser um ponteiro, do tipo ListaNo,
	que contem o endereço de cada elemento. p eh iterado, desde o primeiro endereço da lista,
	representado por l->prim - que por sua vez vem da struct Lista, usada para armazenar o 
	primeiro elemento da lista -, olhando para o ponteiro do proximo elemento da lista,
	representado por prox - No caso, p recebe a referencia prox: p=p->prox -, ate que o
	proximo elemento seja o ponteiro nulo. Em cada iteraçao, eh impresso o inteiro contido
	no elemento, representado por info.*/
}
/*Fim Imprimir Lista*/

void LSE_Buscar(Lista* l, int v){
	ListaNo* p;
	int i, j;

	i = 0;
	j = 0;
	for(p = l->prim; p!=NULL || j!=1; p = p->prox){
		i++;
		if(p->info == v){
			printf("Valor %d encontrado no elemento de posiçao %d.\n", v, i);
			j = 1;
		}
	}
	if(j==0)
		printf("O valor buscado nao estah na lista.\n");
}

int main(){
	

	Lista* l = LSE_Criar();
	LSE_InserirInicio(l, 23);
	LSE_InserirInicio(l, 10);
	LSE_InserirInicio(l, 95);
	LSE_InserirInicio(l, 2);
	LSE_Imprimir(l);
	LSE_Buscar(l, 10);
	LSE_Buscar(l, 95);
	LSE_Buscar(l, 38);

	return 0;
}