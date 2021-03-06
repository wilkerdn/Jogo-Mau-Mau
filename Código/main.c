#include "jogo.h"

int main(int argc, int **argv){
	int w=0, opcao=0, i=0;
	int excluir,excluir_naipe,comprar,comprar_naipe,pos;
	int qtde,z=1;
	int num=1,np=1;
	int baralho[104],naipe[104],auxn=0,auxb=0;
	Lista_jog1* l_1;
	Lista_jog2* l_2;
	Pilha_desc* p_desc;
	Pilha_monte* p_monte;

	printf("---BEM-VINDO AO JOGO---\n\nINSTRUCOES:\n1.Se o jogador possuir uma carta de mesmo naipe ou mesmo valor da carta de descarte em sua mao e obrigatorio joga-la.\n2.O baralho e numerado com os valores de 1 a 13 e os naipes sao indicados pelos valores: 1=PAUS, 2=COPAS, 3=ESPADAS, 4=OUROS.\n3.O programa exibe o valor da carta seguido pelo naipe separados por um hifen e as cartas separadas por uma barra.\n4.Para descartar uma carta de sua mao, voce devera digitar a posicao que ela se encontra, a posicao e contada da esquerda para direita, sendo que a primeira carta se encontra na posicao 0, a segunda na posicao 1 e assim sucessivamente.\n\nPara jogar tecle 1, para sair tecle 0\n");
	scanf("%d",&opcao);

	if(opcao==1){
		l_1 = criaLista_jog1();
		l_2 = criaLista_jog2();
		p_desc = criaPilha_desc();
		p_monte = criaPilha_monte();

		printf("Embaralhando...\n");
		for(w=0;w<104;w++){
		if(num==14){
		num=1;
		}
		baralho[w]=num;
		num++;
		}
		
		for(w=0;w<104;w++){
		if(w==26){
		np=2;
		}
		if(w==52){
		np=3;
		}
		if(w==78){
		np=4;
		}	
		naipe[w]=np;
		}

		srand(time(NULL));
		for(w=0;w<104;w++){
		i = rand()%104;
		auxb=baralho[i];
		auxn=naipe[i];
		baralho[i]=baralho[w];
		naipe[i]=naipe[w];
		baralho[w]=auxb;
		naipe[w]=auxn;
		}

		for(w=0;w<104;w++){	
		empilhar_monte(p_monte,baralho[w],naipe[w]);
		}

		//mostrarMONTE(p_monte);

		printf("Distribuindo cartas...\n");
		for(w=0;w<5;w++){
			qtde = posicao_l2(l_2);
			desempilhar_monte(p_monte,&comprar,&comprar_naipe);
			comprarCarta_j2(l_2,qtde,comprar,comprar_naipe);
		}
		for(w=0;w<5;w++){
			qtde = posicao_l1(l_1);
			desempilhar_monte(p_monte,&comprar,&comprar_naipe);
			comprarCarta_j1(l_1,qtde,comprar,comprar_naipe);
		}
		
		desempilhar_monte(p_monte,&comprar,&comprar_naipe);
		cartaParaDescarte(p_desc,comprar,comprar_naipe);
		
		printf("\nVAMOS COMEÇAR!\n\n");
		
		for(z=1;z<104;z++){
			mostrarUltimaCarta(p_desc);
			contarCartas_jog1(l_1);
			printf("\nSUA VEZ\n");
			mostrarLista_jog2(l_2);
			printf("Para jogar uma carta tecle: 1 ou para comprar uma carta tecle: 2\n");
			scanf("%d",&opcao);
			if(opcao==2){
				qtde = posicao_l2(l_2);
				desempilhar_monte(p_monte,&comprar,&comprar_naipe);
				comprarCarta_j2(l_2,qtde,comprar,comprar_naipe);
			}else{
				printf("Digite a posicao da carta:\n");
				scanf("%d",&pos);
				excluirCarta(l_2,pos,&excluir,&excluir_naipe);
				cartaParaDescarte(p_desc,excluir,excluir_naipe);
			}
			if(estahVazia_jog2(l_2)==1){
			printf("PARABENS, VOCE GANHOU!\n");
			break;
			}
			mostrarUltimaCarta(p_desc);
			printf("\nVEZ DO COMPUTADOR\n");
			printf("Computador jogando...\n\n");
			if(compararCartas(l_1, p_desc)==0){
				desempilhar_monte(p_monte,&comprar,&comprar_naipe);
				comprarCarta_j1(l_1,qtde,comprar,comprar_naipe);
			}
			printf("Jogada finalizada\n");
			if(estahVazia_jog1(l_1)==1){
			contarCartas_jog1(l_1);
			printf("QUE PENA, VOCE PERDEU!\n");
			break;
			}
		}
		
		liberaLista_1(l_1);
		liberaLista_2(l_2);
		liberaPilha_desc(p_desc);
		liberaPilha_monte(p_monte);
		return 0;
	}else
	return 0;
}
