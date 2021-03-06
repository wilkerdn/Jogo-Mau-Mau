#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento_jog1{// elemento para lista jogador 1 (PC)
	int carta_j1;
	int naipe_j1;
	struct elemento_jog1 *proximo_1;
}Elemento_jog1;

typedef struct lista_jog1{// lista para jogador 1 (PC)
  Elemento_jog1 *comeco_j1;	
} Lista_jog1;

typedef struct elemento_jog2{// elemento para lista jogador 2 (usuário)
	int carta_j2;
	int naipe_j2;
	struct elemento_jog2 *proximo_2;
} Elemento_jog2;

typedef struct lista_jog2{// lista para jogador 2 (usuário)
  Elemento_jog2 *comeco_j2;	
} Lista_jog2;

typedef struct elemento_desc {// elemento para pilha de descarte
	int carta_desc;
	int naipe_desc;
	struct elemento_desc *proximo_desc;
}Elemento_desc;

typedef struct Pilha_desc {// pilha para descarte de cartas
  Elemento_desc *topo_desc;	
} Pilha_desc;

typedef struct elemento_monte {// elemento para pilha monte de cartas
	int carta_monte;
	int naipe_monte;
	struct elemento_monte *proximo_monte;
}Elemento_monte;

typedef struct Pilha_monte { // elemento para pilha monte de cartas
  Elemento_monte *topo_monte;	
} Pilha_monte;

Pilha_monte* criaPilha_monte();
Pilha_desc* criaPilha_desc();
Lista_jog1* criaLista_jog1();
Lista_jog2* criaLista_jog2();
int empilhar_monte(Pilha_monte* p_monte, int x,int y);
int comprarCarta_j1(Lista_jog1* l_1,int pos, int c, int e);
int comprarCarta_j2(Lista_jog2* l_2,int pos, int g, int k);
int desempilhar_monte(Pilha_monte* p_monte, int *v, int *a);
void cartaParaDescarte(Pilha_desc* p_desc,int y,int u);
void excluirCarta(Lista_jog2* l_2,int posicao,int* z,int* o);
void excluirCarta_j1(Lista_jog1* l_1,int posicao,int* z, int* o);
int compararCartas(Lista_jog1* l_1, Pilha_desc* p_desc);
void mostrarUltimaCarta(Pilha_desc* p_desc);
void mostrarLista_jog2(Lista_jog2* l_2);
int contarCartas_jog1(Lista_jog1* l_1);
int posicao_l1(Lista_jog1* l_1);
int posicao_l2(Lista_jog2* l_2);
int monteVazio(Pilha_monte* p_monte);
int descVazio(Pilha_desc* p_desc);
int estahVazia_jog1(Lista_jog1* l_1);
int estahVazia_jog2(Lista_jog2* l_2);
int pilhaCheia_desc(Elemento_desc* p_desc);
int pilhaCheia_monte(Elemento_monte* p_monte);
int estahCheia_j1(Elemento_jog1* elem_1);
int estahCheia_j2(Elemento_jog2* elem_2);
void liberaLista_1(Lista_jog1* l_1);
void liberaLista_2(Lista_jog2* l_2);
void liberaPilha_desc(Pilha_desc* p_desc);
void liberaPilha_monte(Pilha_monte* p_monte);
void mostrarMONTE(Pilha_monte* p_monte);
