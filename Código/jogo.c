#include "jogo.h"

Lista_jog1* criaLista_jog1(){ //criar lista para o jogador 1(PC)
	Lista_jog1* l_1;
	l_1 = malloc(sizeof(Lista_jog1));
	l_1->comeco_j1 = NULL;
	return l_1;
}

Lista_jog2* criaLista_jog2(){ //criar lista para jogador 2(usuário)
	Lista_jog2* l_2;
	l_2 = malloc(sizeof(Lista_jog2));
	l_2->comeco_j2 = NULL;
	return l_2;
}

Pilha_desc* criaPilha_desc() {// criar pilha para descarte
	Pilha_desc* p_desc;
	p_desc = malloc(sizeof(Pilha_desc));
	p_desc->topo_desc = NULL;
	return p_desc;
}

Pilha_monte* criaPilha_monte(){// criar pilha para o baralho já embaralhado
	Pilha_monte* p_monte;
	p_monte = malloc(sizeof(Pilha_monte));
	p_monte->topo_monte = NULL;
	return p_monte;
}

int empilhar_monte(Pilha_monte* p_monte,int x,int y){
	Elemento_monte* novo = malloc(sizeof(Elemento_monte));
		if(pilhaCheia_monte(novo)==0){
			novo->carta_monte = x;
			novo->naipe_monte = y;
			novo->proximo_monte = NULL;
			novo->proximo_monte = p_monte->topo_monte;    
			p_monte->topo_monte = novo;
			return 1;
			}
			return 0;
}

int comprarCarta_j1(Lista_jog1* l_1,int pos, int c, int e){//comprar carta para o PC
	int i;
	Elemento_jog1* novo = malloc(sizeof(Elemento_jog1));
	Elemento_jog1* temp;
	novo->carta_j1 = c;
	novo->naipe_j1 = e;
	if(estahVazia_jog1(l_1)==1){
		novo->proximo_1 = l_1->comeco_j1;
		l_1->comeco_j1 = novo;
		return 1;
	}else if(estahVazia_jog1(l_1)!=1){
	temp = l_1->comeco_j1;
	for(i=1;i<pos;i++){
			if(temp->proximo_1==NULL){
			break;
			}
			temp = temp->proximo_1;
		}
		novo->proximo_1 = temp->proximo_1;
		temp->proximo_1 = novo;
		return 1;
	}
}

int comprarCarta_j2(Lista_jog2* l_2,int pos, int g, int k){//comprar carta para o usuário
	Elemento_jog2* novo = malloc(sizeof(Elemento_jog2));
	Elemento_jog2* temp;
	int i;
	novo->carta_j2 = g;
	novo->naipe_j2 = k;
	if(estahVazia_jog2(l_2)==1){
		novo->proximo_2 = l_2->comeco_j2;
		l_2->comeco_j2 = novo;
		return 1;
	}else if(estahVazia_jog2(l_2)!=1){
		temp = l_2->comeco_j2;		
		for(i = 1;i<pos;i++){
			if(temp->proximo_2==NULL){
			break;
			}
			temp = temp->proximo_2;
		}
		novo->proximo_2 = temp->proximo_2;
		temp->proximo_2 = novo;
		return 1;
	}
}

int desempilhar_monte(Pilha_monte* p_monte, int *v, int *a){
	Elemento_monte* temp;	
	if(monteVazio(p_monte)==1){
	    return 0;
        }else{
		temp = p_monte->topo_monte;
		*v=temp->carta_monte;
		*a=temp->naipe_monte;
		p_monte->topo_monte = temp->proximo_monte;	
		free(temp);
		return 1;
	}

}

void cartaParaDescarte(Pilha_desc* p_desc,int y,int u){
	Elemento_desc* novo2 = malloc(sizeof(Elemento_desc));
		if(pilhaCheia_desc(novo2)==0){
		novo2->carta_desc = y;
		novo2->naipe_desc = u;
		novo2->proximo_desc = NULL;
		novo2->proximo_desc = p_desc->topo_desc;    
		p_desc->topo_desc = novo2;
	}
}

void excluirCarta(Lista_jog2* l_2,int posicao,int* z, int* o){
	Elemento_jog2* temp3;
	Elemento_jog2* aux9;
	int i;
	if(estahVazia_jog2(l_2)!=1){
		temp3 = l_2->comeco_j2;
	if(posicao==0){
	*z = temp3->carta_j2;
	*o = temp3->naipe_j2;
	l_2->comeco_j2 = temp3->proximo_2;
	free(temp3);
	}else{	
	for(i=1;i<posicao;i++){
	if(temp3->proximo_2==NULL){
	break;
	}else
	temp3 = temp3->proximo_2;
	}
	aux9 = temp3->proximo_2;
	*z = aux9->carta_j2;
	*o = aux9->naipe_j2;
	temp3->proximo_2 = aux9->proximo_2;
	free(aux9);
	}	
	}
}

void excluirCarta_j1(Lista_jog1* l_1,int posicao,int* z, int* o){
	Elemento_jog1* temp4;
	Elemento_jog1* aux6;
	int i;
	if(estahVazia_jog1(l_1)!=1){
		temp4 = l_1->comeco_j1;
	if(posicao==0){
	*z = temp4->carta_j1;
	*o = temp4->naipe_j1;
	l_1->comeco_j1 = temp4->proximo_1;
	free(temp4);
	}else{
	for(i=0;i<posicao;i++){
	if(temp4->proximo_1==NULL){
	break;
	}else{
	temp4 = temp4->proximo_1;
	}
	}
	aux6 = temp4->proximo_1;
	*z = aux6->carta_j1;
	*o = aux6->naipe_j1;
	temp4->proximo_1 = aux6->proximo_1;
	free(aux6);
	}	
	}
}

int compararCartas(Lista_jog1* l_1, Pilha_desc* p_desc){
	Elemento_desc* b;
	Elemento_jog1* f;
	b = p_desc->topo_desc;
	int excluir_2=0,excluir_naipe_2=0,posic_2=0;
	for(f=l_1->comeco_j1;f!=NULL;f=f->proximo_1){
		if(f->naipe_j1==b->naipe_desc||f->carta_j1==b->carta_desc){
			excluirCarta_j1(l_1,posic_2,&excluir_2,&excluir_naipe_2);
			cartaParaDescarte(p_desc,excluir_2,excluir_naipe_2);
			return 1;
			break;
		}
		posic_2++;
	}
	return 0;
}
	
void mostrarUltimaCarta(Pilha_desc* p_desc){
	Elemento_desc* q;
	q = p_desc->topo_desc;
	printf("Ultima carta descartada: %d-",q->carta_desc);
	printf("%d",q->naipe_desc);
	printf("\n");
}
	
void mostrarLista_jog2(Lista_jog2* l_2){// mostrar as cartas do usuário (jogador 2)
	Elemento_jog2 *q;
	printf("Suas cartas: ");
	for(q=l_2->comeco_j2;q!=NULL;q=q->proximo_2){
	printf("% d-", q->carta_j2);
	printf("%d |",q->naipe_j2);
	}
	printf("\n");
}

int contarCartas_jog1(Lista_jog1* l_1){
	Elemento_jog1 *n;
	int s=0;
	for(n=l_1->comeco_j1;n!=NULL;n=n->proximo_1){
	s++;
	}
	printf("Quantidade de cartas do computador: %d\n",s);
}

void mostrarMONTE(Pilha_monte* p_monte){// mostrar as cartas do usuário (jogador 2)
	Elemento_monte *q;
	printf("Cartas do usuario: ");
	for(q=p_monte->topo_monte;q!=NULL;q=q->proximo_monte){
	printf("Valor: %d ", q->carta_monte);
	printf("Naipe: %d| ",q->naipe_monte);
	}
	printf("\n");
}
	
int posicao_l1(Lista_jog1* l_1){
	Elemento_jog1* temp;
	int qtd1=0;
	for(temp=l_1->comeco_j1;temp!=NULL;temp=temp->proximo_1){
	qtd1 ++;
	}
	return qtd1;
}

int posicao_l2(Lista_jog2* l_2){
	Elemento_jog2* temp;
	int qtd1=0;
	for(temp=l_2->comeco_j2;temp!=NULL;temp=temp->proximo_2){
	qtd1 ++;
	}
	return qtd1;
}

int estahVazia_jog1(Lista_jog1* l_1){// verificar se as cartas do PC (jogador 1) acabaram
	if(l_1->comeco_j1 == NULL){
		return 1;
	}else{
		return 0;
	}
}

int estahVazia_jog2(Lista_jog2* l_2){// verificar se as cartas do usuário (jogador 2) acabaram
	if(l_2->comeco_j2 == NULL){
		return 1;
	}else{
		return 0;
	}
}



int monteVazio(Pilha_monte* p_monte){
	if(p_monte->topo_monte==NULL){
		return 1;
	}else{
		return 0;
	}
}

int descVazio(Pilha_desc* p_desc){
	if(p_desc->topo_desc==NULL){
		return 1;
	}else{
		return 0;
	}
}
int pilhaCheia_desc(Elemento_desc* p_desc) {
	if(p_desc == NULL){
		return 1;
	} else {
		return 0;
	}
}

int pilhaCheia_monte(Elemento_monte* p_monte) {
	if(p_monte == NULL){
		return 1;
	} else {
		return 0;
	}
}

int estahCheia_j1(Elemento_jog1* elem_1) {
	if (elem_1 == NULL){
	   return 1;
	}else{
	   return 0;
	}
}

int estahCheia_j2(Elemento_jog2* elem_2) {
	if (elem_2 == NULL){
	   return 1;
	}else{
	   return 0;
	}
}

void liberaLista_1(Lista_jog1* l_1) {
	free(l_1);
	l_1->comeco_j1 = NULL;
}

void liberaLista_2(Lista_jog2* l_2) {
	free(l_2);
	l_2->comeco_j2 = NULL;
}

void liberaPilha_desc(Pilha_desc* p_desc) {
	Elemento_desc* q = p_desc->topo_desc;	
	while (q != NULL) {
		Elemento_desc* temp = q->proximo_desc;
		free(q);
		q = temp;
	}	
	free(p_desc);
}

void liberaPilha_monte(Pilha_monte* p_monte) {
	Elemento_monte* q = p_monte->topo_monte;	
	while (q != NULL) {
		Elemento_monte* temp = q->proximo_monte;
		free(q);
		q = temp;
	}	
	free(p_monte);
}

