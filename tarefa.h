struct tempo{
 	int dia;
 	int mes;
 	int ano;
 	int hora;
 	int minuto;
 };
 
 struct reg{
 	int id;
	char nome;
 	struct tempo inicio;
 	int duracao;
 	struct tempo deadline;
 };

typedef struct reg tarefa;

void mostraMenu();
void imprimeTodos(tarefa *v, int t);
tarefa *excluir(tarefa *v, int t);
void editar_tarefas(tarefa *v, int edit);
