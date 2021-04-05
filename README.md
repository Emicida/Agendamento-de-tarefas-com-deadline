# Estrutura de Dados - Trabalho Final: Agendamento de tarefas com deadline

O ojetivo desse trabalho foi um sistema de software em C para auxiliar na organização das tarefas do usuário.
Ele deve permitir o cadastro, visualização e a manutenção (alteração, inclusão e remoção) do conjunto de tarefas, indicar a cada dia quais as tarefas que devem ser realizadas de forma a maximizar o número de tarefas realizadas e o cumprimento de deadlines

O trabalho foi feito todo em linguagem C, através do uso da ferramenta 'DevC-C++ 5.11'

# Instruções
Ao iniciar o programa um menu como esse abaixo irá aparecer:

|____________________________________________|
|           CADASTRO DE TAREFAS              |
|____________________________________________|
|              MENU DE OPÇÕES                |
|____________________________________________|
|         1 - INCLUIR NOVA TAREFA            |
|         2 - VISUALIZAR TAREFAS CADASTRADAS |
|         3 - EXCLUIR TAREFA                 |
|         4 - EDITAR TAREFA                  |
|         5 - CARREGAR ARQUIVO DE TAREFAS    |
|         6 - GERAR ARQUIVO DE TAREFAS       |
|         7 - COMPUTAR AGENDA DO DIA         |
|         8 - SALVAR A AGENDA DO DIA         |
|         0 – SAIR                           |

Na opção 1, o usuário cadastra uma tarefa.
Na opção 2, são exibidas as tarefas já cadastradas.
Na opção 3, pode-se excluir uma tarefa, informando o ID.
Na opção 4, permite-se editar uma das informações em uma tarefa, também apartir do ID específico.
Na opção 5, deve-se ler um arquivo de com as tarefas cadastradas pelo usuário.
Na opção 6, o arquivo do item 5 é gerado com base nos registros armazenados.
Na opção 7, computa-se as tarefas que devem ser realizadas no dia.
Na opção 8, transferir as tarefas programadas para o dia para em um arquivo.
Na opção 0, o programa para de rodar.

Ao utlizar a opção 1 deve-se dizer quantas tarefas serão incluídas antes. 
Ao tentar a opção 3 ou 4 (editar ou excluir uma tarefa) aparecerá uma confirmação para ver se o usuário está certo da mudança.
Ao tentar a opção 5 antes da opção 6, será aberto um arquivo em branco.
A opção 7 não cria um arquivo só computa, caso queira um arquivo é preciso selecionar a opção 8.

Cada vez que uma opção é selecionada ele volta para o menu inicial até a opção 0 (sair) for selecionada.
