#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <tarefa.h>
#define true 1
#define false 0

int main(){
	setlocale(LC_ALL, "Portuguese");
	tarefa *vetor;
	int op,i,edit,t;
	do{
		mostraMenu();
		scanf("%d",&op);
		switch(op){
			case 1:
				system("cls");
				printf("Quantas tarefas deseja cadastrar? \n");
				scanf("%d",&t);
				vetor=(tarefa*)malloc(t*sizeof(tarefa));
				for(i=0;i<t;i++){
					printf("ID: %d \n",i);
					vetor[i].id = i;
					printf("Defina a tarefa:\n");
					scanf("%s",&vetor[i].nome);
					printf(" Data e hora em que a tarefa estará disponível para ser realizada...\n");
					printf("\n   Dia: ");
					scanf("%d",&vetor[i].inicio.dia);
					printf("\n   MÃªs: ");
					scanf("%d",&vetor[i].inicio.mes);
					printf("\n   Ano: ");
					scanf("%d",&vetor[i].inicio.ano);
					printf("\n   Hora: ");
					scanf("%d",&vetor[i].inicio.hora);
					printf("\n   Minuto: ");
					scanf("%d",&vetor[i].inicio.minuto);
					printf("\nTempo (em minutos) necessário para realização da tarefa: ");
					scanf("%d",&vetor[i].duracao);
					printf("\nPrazo máximo para conclusão...\n");
					printf("\n   Dia: ");
					scanf("%d",&vetor[i].deadline.dia);
					printf("\n   Mês: ");
					scanf("%d",&vetor[i].deadline.mes);
					printf("\n   Ano: ");
					scanf("%d",&vetor[i].deadline.ano);
					printf("\n   Hora: ");
					scanf("%d",&vetor[i].deadline.hora);
					printf("\n   Minuto: ");
					scanf("%d",&vetor[i].deadline.minuto);
				}
				break;
			case 2:
				system("cls");
				imprimeTodos(vetor,t);
				system("pause");
				break;
			case 3:
				system("cls");
				vetor=excluir(vetor, t);
				printf("\n Registro excluído !");
				system("pause");
				t=t-1;
				break;
			case 4:
				system("cls");
				printf("Digite o ID da tarefa que quer editar:\n");
				scanf("%d",&edit);
				editar_tarefas(vetor, edit);
				system("pause");
				break;
			case 0:
				printf("Obrigado por usar o nosso programa!\n");  
				break;
			default:
				printf("OPÇÃO NÃOVÁLIDA!!!\n"); 
				system("pause");
				break;

		}
	}while(op!=0);
}
