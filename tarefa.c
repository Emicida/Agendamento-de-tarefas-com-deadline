#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <tarefa.h>

void mostraMenu(){
	system("cls");//limpa a tela
	printf("|------------------------------------|\n");	
	printf("|           MENU DE OPÇÕES           |\n");
	printf("|------------------------------------|\n");
	printf("| 1 - INCLUIR NOVA TAREFA            |\n");
	printf("| 2 - VISUALIZAR TAREFAS CADASTRADAS |\n");
	printf("| 3 - EXCLUIR TAREFA                 |\n");	
	printf("| 4 - EDITAR TAREFA                  |\n");
	printf("| 0 - SAIR                           |\n");
	printf("|------------------------------------|\n");
}

void imprimeTodos(tarefa *v, int t){
	int j;
	for(j=0;j<t;j++){
		printf("\n ID: %d\n",v[j].id);
		printf("Nome: %c\n",v[j].nome);
		printf("Início: Começa em %d/%d/%d ás %d:%d\n",v[j].inicio.dia,v[j].inicio.mes,v[j].inicio.ano,v[j].inicio.hora,v[j].inicio.minuto);
		printf("Duração: %d minutos\n",v[j].duracao);
		printf("Deadline: Acaba em %d/%d/%d ás %d:%d\n",v[j].deadline.dia,v[j].deadline.mes,v[j].deadline.ano,v[j].deadline.hora,v[j].deadline.minuto);
	}
}

tarefa * excluir(tarefa *v, int t){
	int pos,escolha;
	printf("Digite o ID da tarefa que quer excluir:\n");
	scanf("%d",&pos);
	printf("Tarefa escolhida: %c\n",v[pos].nome);
	printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
	scanf("%d",escolha);
	if (escolha==1){
		if(pos>=0 && pos<t){
			int apagar;
			for(apagar=pos;apagar<t-1;++apagar){
				v[apagar]=v[apagar+1];
			}
			v=(tarefa *)realloc(v,(t-1)*sizeof(tarefa));
		}
	return(v);
	}
	else
	system("pause");
}

void editar_tarefas(tarefa *v, int edit){
	int ed,escolha;
	printf("	Selecione qual opção quer editar: \n");
	printf(" 		1) Nome\n");
	printf(" 		2) Iníco\n");
	printf(" 		3) Duração\n");
	printf("		4) Deadline\n");
	scanf("%d",&ed);
		switch(ed){
			case 1:
				printf("Nome antigo: %c \n",&v[edit].nome);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina um novo nome:\n");
					fflush(stdin);
					scanf("%s",&v[edit].nome);
					break;
				}
				else
				break;
			case 2:
				printf("Início antigo: %d/%d/%d ás %d:%d\n",v[edit].inicio.dia,v[edit].inicio.mes,v[edit].inicio.ano,v[edit].inicio.hora,v[edit].inicio.minuto);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina o novo início:\n");
					fflush(stdin);
					printf("\n   Dia: ");
					scanf("%d",&v[edit].inicio.dia);
					printf("\n   MÃªs: ");
					scanf("%d",&v[edit].inicio.mes);
					printf("\n   Ano: ");
					scanf("%d",&v[edit].inicio.ano);
					printf("\n   Hora: ");
					scanf("%d",&v[edit].inicio.hora);
					printf("\n   Minuto: ");
					scanf("%d",&v[edit].inicio.minuto);
					break;
				}
				else
					break;
			case 3:
				printf("Duração antiga: %s \n",&v[edit].duracao);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina a nova duração:\n");
					fflush(stdin);
					scanf("%d",&v[edit].duracao);
					break;
				}
				else
				break;
			case 4:
				printf("Prazo antigo: %d/%d/%d ás %d:%d\n",v[edit].deadline.dia,v[edit].deadline.mes,v[edit].deadline.ano,v[edit].deadline.hora,v[edit].deadline.minuto);
				printf("Tem certeza que deseja mudar? (Digite 1 para SIM)\n ");
				scanf("%d",escolha);
				if (escolha==1){
					printf("Defina o novo prazo:\n");
					fflush(stdin);
					printf("\n   Dia: ");
					scanf("%d",&v[edit].deadline.dia);
					printf("\n   Mês: ");
					scanf("%d",&v[edit].deadline.mes);
					printf("\n   Ano: ");
					scanf("%d",&v[edit].deadline.ano);
					printf("\n   Hora: ");
					scanf("%d",&v[edit].deadline.hora);
					printf("\n   Minuto: ");
					scanf("%d",&v[edit].deadline.minuto);
					break;
				}
				else
				break;
			default:
				printf("OPÇÃO NÃOVÁLIDA!!!\n");  
				system("pause");
				break;
		}
}
