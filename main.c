#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

 /*struct tempo{
 	int dia;
 	int mes;
 	int ano;
 	int hora;
 	int minuto;
 };*/
 
 struct reg{
	char nome;
	struct tm inicio;
	int duracao;
	struct tm deadline;
 };

typedef struct tarefa nodo;
 
 struct tarefa{
	nodo * prox;
	nodo * ant;
	int id;
	struct reg dado;
 };
 
void mostraMenu(){
	system("cls");//limpa a tela
	printf("|      CADASTRO DE FUNCIONÁRIOS      |\n");
	printf("|____________________________________|\n");
	printf("|           MENU DE OPÇÕES           |\n");
	printf("|------------------------------------|\n");
	printf("| 1 - INCLUIR NOVA TAREFA            |\n");
	printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS |\n");
	printf("| 3 - EXCLUIR TAREFA                 |\n");	
	printf("| 4 - EDITAR TAREFA                  |\n");
	printf("| 5 - CARREGAR ARQUIVO               |\n");
	printf("| 6 - GERAR ARQUIVO                  |\n");
	printf("| 7 - COMPUTAR AGENDA                |\n");
	printf("| 8 - SALVAR A AGENDA                |\n");
	printf("| 0 - SAIR                           |\n");
	printf("|------------------------------------|\n");
}

nodo * inserir(nodo *l, int i){
	int ano,mes;
	nodo *n;
	nodo *p;
	p=l;
	n= (nodo *)malloc (sizeof(nodo));
	printf("ID: %d \n",i);
	n->id=i;
	printf("Defina a tarefa:\n");
	scanf("%s",n->dado.nome);
	printf(" Data e hora em que a tarefa estara disponível para ser realizada.\n");
	printf("\n   Data (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &n->dado.inicio.tm_mday, &mes, &ano);
	n->dado.inicio.tm_mon = mes - 1;
	n->dado.inicio.tm_year = ano - 1900;
	printf("\n   Horário (hh:mm): ");
	scanf("%d:%d",&n->dado.inicio.tm_hour, &n->dado.inicio.tm_min );
	printf("\nTempo (em minutos) necessário para realização da tarefa: ");
	scanf("%d",&n->dado.duracao);
	printf("\nPrazo máximo para conclusão...\n");
	printf("\n   Data (dd/mm/aaaa): ");
	scanf("%d/%d/%d", &n->dado.deadline.tm_mday, &mes, &ano);
    n->dado.deadline.tm_mon = mes - 1;
    n->dado.deadline.tm_year = ano - 1900;
	printf("\n   Horário (hh:mm): ");
	scanf("%d:%d",&n->dado.deadline.tm_hour, &n->dado.deadline.tm_min);
	n->prox=NULL;
	if(p!=NULL){
		while(p->prox!=NULL){
			p=p->prox;
		}
		p->prox=n;
		n->ant = p;
	}
	else{ //lista vazia
		l=n;
	}
	return (n);
}

void imprime_lista(nodo *l){
	nodo *p;
	p=l;
	while(p!=NULL){
		printf("\n ID: %d\n",p->id);
		printf("Nome: %s\n",p->dado.nome);
		printf("Início: Começa em %d/%d/%d ás %d:%d\n",p->dado.inicio.tm_mday,p->dado.inicio.tm_mon,p->dado.inicio.tm_year,p->dado.inicio.tm_hour,p->dado.inicio.tm_min);
		printf("Duração: %d minutos\n",p->dado.duracao);
		printf("Deadline: Acaba em %d/%d/%d ás %d:%d\n",p->dado.deadline.tm_mday,p->dado.deadline.tm_mon,p->dado.deadline.tm_year,p->dado.deadline.tm_hour,p->dado.deadline.tm_min);
		p=p->prox;
	}
	return;
}

nodo * remover(nodo *l, int pos){
	int x;
	nodo *p=l;
	printf("Tarefa escolhida: %c\n",p->dado.nome);
	printf("Tem certeza que deseja excluir? (Digite 1 para SIM)\n ");
	scanf("%d",x);
	if(x==1){
		while(p!=NULL && p->id != pos){
		p=p->prox;
		}
		if(p == NULL){
			printf("valor nao encontrado!\n");
			return l;
		}
		else{
			if(p->ant==NULL){
				l=p->prox;
			}
			else{
				p->ant->prox = p->prox;
				p->prox->ant = p->ant;
			}
			free(p);
		}
	}
	return (l);
}

void editar(nodo *l, int edit){
	int ed,escolha,mes,ano;
	nodo *p=l;
	while (p != NULL && p->id != edit){
   		p = p->prox;
	}
	printf("	Selecione qual opção quer editar: \n");
	printf(" 		1) Nome\n");
	printf(" 		2) Início\n");
	printf(" 		3) Duração\n");
	printf("		4) Deadline\n");
	scanf("%d",&ed);
		switch(ed){
			case 1:
				printf("Nome antigo: %s \n",&p->dado.nome);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina um novo nome:\n");
					fflush(stdin);
					scanf("%s",&p->dado.nome);
					break;
				}
				else
				break;
			case 2:
				printf("InÃ­cio antigo: %d/%d/%d Ã¡s %d:%d\n",p->dado.inicio.tm_mday,p->dado.inicio.tm_mon,p->dado.inicio.tm_year,p->dado.inicio.tm_hour,p->dado.inicio.tm_min);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina o novo início:\n");
					fflush(stdin);
					printf("\n   Data (dd/mm/aaaa): ");
					scanf("%d/%d/%d", &p->dado.inicio.tm_mday, &mes, &ano);
					p->dado.inicio.tm_mon = mes - 1;
					p->dado.inicio.tm_year = ano - 1900;
					printf("\n   Horário: ");
					scanf("%d",&p->dado.inicio.tm_hour, &p->dado.inicio.tm_min);
					break;
				}
				else
					break;
			case 3:
				printf("Duração antiga: %s \n",&p->dado.duracao);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina a nova duraÃ§Ã£o:\n");
					fflush(stdin);
					scanf("%d",&p->dado.duracao);
					break;
				}
				else
				break;
			case 4:
				printf("Prazo antigo: %d/%d/%d Ã¡s %d:%d\n",p->dado.deadline.tm_mday,p->dado.deadline.tm_mon,p->dado.deadline.tm_year,p->dado.deadline.tm_hour,p->dado.deadline.tm_min);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina o novo prazo:\n");
					fflush(stdin);
					printf("\n   Data (dd/mm/aaaa): ");
					scanf("%d",&p->dado.deadline.tm_mday, &mes, &ano);
					p->dado.deadline.tm_mon = mes - 1;
    				p->dado.deadline.tm_year = ano - 1900;
					printf("\n   Horário (hh/mm): ");
					scanf("%d",&p->dado.deadline.tm_hour, &p->dado.deadline.tm_min);
					break;
				}
			default:
				printf("OPÇÃO NÃO VÁLIDA!\n");  
				system("pause");
				break;
		}
}

void criar_arquivo(nodo *l){
	FILE * arq;
	nodo *p;
	p=l;
	arq = fopen("Tarefa.txt", "wb");
		while(p!=NULL){
			fprintf(arq,"\n %d",p->id);
			fprintf(arq," %s,",p->dado.nome);
			fprintf(arq," %d/",p->dado.inicio.tm_mday);
			fprintf(arq,"%d/",p->dado.inicio.tm_mon);
			fprintf(arq,"%d -",p->dado.inicio.tm_year);
			fprintf(arq," %d:",p->dado.inicio.tm_hour);
			fprintf(arq,"%d, ",p->dado.inicio.tm_min);
			fprintf(arq," %d min, ",p->dado.duracao);
			fprintf(arq," %d/",p->dado.deadline.tm_mday);
			fprintf(arq,"%d/",p->dado.deadline.tm_mon);
			fprintf(arq,"%d -",p->dado.deadline.tm_year);
			fprintf(arq," %d:",p->dado.deadline.tm_hour);
			fprintf(arq,"%d\n",p->dado.deadline.tm_min);
			p=p->prox;
		}
		if (arq == NULL){
			printf("Problemas na abertura do arquivo\n");
			fclose(arq);
		}
}

void criar_agenda(nodo *ord){
	FILE * agen;
	nodo *p;
	p=ord;
	agen = fopen("Agenda.txt", "wb");
		while(p!=NULL){
			fprintf(agen,"\n %d",p->id);
			fprintf(agen," %s,",p->dado.nome);
			fprintf(agen," %d/",p->dado.inicio.tm_mday);
			fprintf(agen,"%d/",p->dado.inicio.tm_mon);
			fprintf(agen,"%d -",p->dado.inicio.tm_year);
			fprintf(agen," %d:",p->dado.inicio.tm_hour);
			fprintf(agen,"%d, ",p->dado.inicio.tm_min);
			fprintf(agen," %d min, ",p->dado.duracao);
			fprintf(agen," %d/",p->dado.deadline.tm_mday);
			fprintf(agen,"%d/",p->dado.deadline.tm_mon);
			fprintf(agen,"%d -",p->dado.deadline.tm_year);
			fprintf(agen," %d:",p->dado.deadline.tm_hour);
			fprintf(agen,"%d\n",p->dado.deadline.tm_min);
			p=p->prox;
		}
		if (agen == NULL){
		printf("Problemas na abertura do arquivo\n");
		fclose(agen);
	}
}

void troca_valor(nodo *x, nodo *y){
 nodo tmp; // ponteiro temporário
 tmp = *x; // recebe conteudo do x
 *x = *y; // x recebe conteudo do y
 *y=tmp; // y recebe conteudo do x
//Y recebe a posição de x
 y->prox = x->prox;
 y->ant = x->ant;
// X recebe a posição de y
 x->prox=tmp.prox;
 x->ant=tmp.ant;
}

void * bubbleSort(nodo *l){
	time_t t1, t2;
	nodo *p, *a, *next;
	int trocou;
	p=l;
	while(p!=NULL){
		a=p;
		next=a->prox;
		trocou=0;
		while(next!=NULL){
			t1 = mktime(&a->dado.deadline);
			t2 = mktime(&next->dado.deadline); 
			if(t1>t2){
				troca_valor(a,next);
				trocou=1;
			}
			a=next;
			next=next->prox;
		}
		if(!trocou) return;
		p=p->prox;
	}
}

nodo* passa_nodo( nodo* l, nodo* ord ){
    nodo* p;
    for (p = l; p; p = p->prox){
        nodo* novo = (nodo*) malloc(sizeof(nodo));
   		novo->dado = p->dado;
   		novo->prox = l;
    }
    return ord;
}

nodo * interval_scheduling(nodo *l, nodo *ord){
	struct tm *data;
	struct tm *data_atual;
	time_t segundos;
	time(&segundos);
	data = localtime(&segundos);  
	data_atual->tm_mday=data->tm_mday;
	data_atual->tm_mon=((data->tm_mon)+1);
	data_atual->tm_year=((data->tm_year)+1900);
	data_atual->tm_hour=data->tm_hour;
	data_atual->tm_min=data->tm_min;
	data_atual->tm_sec= data->tm_sec;
	time_t x,y,hj;
	bubbleSort(l); // Ordenada a lista base
	while (l->prox!=NULL){// Verifica se é compatível
		x = mktime(&l->dado.deadline);
    	y = mktime(&ord->dado.inicio);
		hj = mktime(data_atual); 
		 if(x < y && x == hj){
			passa_nodo(l,ord); // Passa conteúdo da lista l para a ordenada
			l=l->prox; // Segue para o proximo da lista base
			}
	}
	return (ord);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op,i=0,edit,t;
	nodo *l; // Criando lista que vai servir como base
	nodo *ord; // Lista ordenada
	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				printf("Quantas tarefas deseja cadastrar? \n");
				scanf("%d",&t);
				while(i<t){
					inserir(l,i);
					i++;
				}
				break;
			case 2:
				system("cls");
				imprime_lista(l);
				system("pause");
				break;
			case 3:
				system("cls");
				int pos;
				printf("Digite o ID da tarefa que quer excluir:\n");
				scanf("%d",&pos);
				remover(l,pos);
				printf("\n Registro excluído!");
				system("pause");
				break;
			case 4:
				system("cls");
				printf("Digite o ID da tarefa que quer editar:\n");
				scanf("%d",&edit);
				editar(l,edit);
				system("pause");
				break;
			case 5:
				 fopen("Tarefa.txt", "rt");
				break;
			case 6:
				criar_arquivo(l);
				printf("\nArquivo criado!");
				printf("\nSelecione opção 5 para vizualiza-lo");
				system("pause");
				break;
			case 7:
				interval_scheduling(l,ord);
				printf("\nTarefas computadas!");
				printf("\nSelecione a opção 8 para visualiza-las");
				system("pause");
				break;
			case 8:
				criar_agenda(ord);
				fopen("Agenda.txt", "rt");
			
				break;
			default:
				system("cls");
				printf("OPÇÃO NÃO CADASTRADA!\n");  
				system("pause");
				break;

		}
	}while(op!=0);
}

