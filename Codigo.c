#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variaveis definadas para a Matriz tridemensional 
#define NUM_FILA 5
#define NUM_CADEIRAS 10
#define NUM_FILMES 3

// Matriz que representa as cadeiras de cada sala
int assentos[NUM_FILA][NUM_CADEIRAS][NUM_FILMES];

// Procedimento que inicializa todas as cadeiras como disponíveis
void inicializar_assentos() {
    for (int i = 0; i < NUM_FILA; i++) {
        for (int j = 0; j < NUM_CADEIRAS; j++) {
            for (int k = 0; k < NUM_FILMES; k++) {
                assentos[i][j][k] = 0;
            }
        }
    }
}

// Procedimento que imprime o mapa de assentos de um filme
void print_assentos(int filme) {
    printf("Assentos disponiveis para o Filme %d:\n", filme);
    for (int i = 0; i < NUM_FILA; i++) {
        printf("Fila %d: ", i + 1);
        for (int j = 0; j < NUM_CADEIRAS; j++) {
            if (assentos[i][j][filme-1] == 0) {
                printf("%d ", j + 1);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

// Função que verifica se um assento específico está disponível para um filme
int avalia_assento(int fila, int assento, int filme) {
    if (fila < 1 || fila > NUM_FILA || assento < 1 || assento > NUM_CADEIRAS) {
        return 0;           // assento inválido
    } else {
        return assentos[fila - 1][assento - 1][filme-1] == 0;
    }
}

// Função que reserva um assento específico para um filme
int reservar_assento(int fila, int assento, int filme) {
    if (avalia_assento(fila, assento, filme)) {
        assentos[fila - 1][assento - 1][filme-1] = 1;
        return 1;           // reserva feita com sucesso
    } else {
        return 0;           // assento já reservado ou inválido
    }
}

// Função que libera um assento específico para um filme
int liberar_assento(int fila, int assento, int filme) {
    if (avalia_assento(fila, assento, filme)) {
        return 0;           // assento já estava disponível
    } else {
        assentos[fila - 1][assento - 1][filme-1] = 0;
        return 1;           // assento liberado com sucesso
    }
}

struct filmes {
    char nome[20];
    int ano;
    int class;
};

int main(){
    int op;
    int option;
    int assento, fila;
    
    struct filmes c;
    strcpy(c.nome, "Creed");
    c.ano = 2015;
    c.class = 12;
    
    struct filmes s;
    strcpy(s.nome, "Shazam");
    s.ano = 2019;
    s.class = 12;
    
    struct filmes i;
    strcpy(i.nome, "Interestelar");
    i.ano = 2014;
    i.class = 10; 
    
    // Inicializar as cadeiras de todos os filmes disponiveis.
    inicializar_assentos();

    do
    {
        printf("Escolha um filme: \n1 - %s (%d)(%d)\n2 - %s (%d)(%d) \n3 - %s (%d)(%d)\n4 - Para sair\n",c.nome,c.ano,c.class,s.nome,s.ano,s.class,i.nome,i.ano,i.class);
        scanf("%d", &op);

        // Menu de opções do filme 1
        if (op == 1){
            do
            {
                // Imprimir mapa de acento do filme
                print_assentos(op);

                // Menu de opcoes
                printf ("\nDigite uma opcao:\n1 - Reservar um assento\n2 - Liberar um assento\n3 - Sair\n");
                scanf ("%d", &option);

                switch (option)
                {
                    case 1:
                        // Reservar um assento
                        printf ("\nDigite a fila e o assento que deseja reservar:\n");
                        scanf ("%d %d", &fila, &assento);
                        if (reservar_assento(fila, assento, op)) {
                            printf ("\nAssento reservado com sucesso!\n");
                            }
	                    else {
                            printf ("\nAssento ja reservado ou invalido.\n");
                            }
                        break;
                    case 2:
                        // Liberar um assento
	                    printf ("\nDigite a fila e o assento que deseja liberar:\n");
	                    scanf ("%d %d", &fila, &assento);
	                    if (liberar_assento (fila, assento, op)) {
                            printf ("\nAssento liberado com sucesso!\n");
                        }
                        else {
                            printf ("\nAssento ja estava disponivel ou invalido.\n");
                        }
                        break;
                    case 3:
                        // Sair do programa
	                    printf ("Saindo...\n");
                        break;
                    default:
                        printf ("\nopcao invalida. Tente novamente.\n");
                        break;
                }
            } 
            while (option != 3);
        }
        // Menu de opções do filme 2
        else if (op == 2){
            do
            {
                // Imprimir mapa de acento do filme
                print_assentos(op);

                // Menu de opcoes
                printf ("\nDigite uma opcao:\n1 - Reservar um assento\n2 - Liberar um assento\n3 - Sair\n");
                scanf ("%d", &option);

                switch (option)
                {
                    case 1:
                        // Reservar um assento
                        printf ("\nDigite a fila e o assento que deseja reservar:\n");
                        scanf ("%d %d", &fila, &assento);
                        if (reservar_assento(fila, assento, op)) {
                            printf ("\nAssento reservado com sucesso!\n");
                            }
	                    else {
                            printf ("\nAssento ja reservado ou invalido.\n");
                            }
                        break;
                    case 2:
                        // Liberar um assento
	                    printf ("\nDigite a fila e o assento que deseja liberar:\n");
	                    scanf ("%d %d", &fila, &assento);
	                    if (liberar_assento (fila, assento, op)) {
                            printf ("\nAssento liberado com sucesso!\n");
                        }
                        else {
                            printf ("\nAssento ja estava disponivel ou invalido.\n");
                        }
                        break;
                    case 3:
                        // Sair do programa
	                    printf ("Saindo...\n");
                        break;
                    default:
                        printf ("\nOpcao invalida. Tente novamente.\n");
                        break;
                }
            } 
            while (option != 3);
        }
        //Menu de opções do filme 3
        else if (op == 3){
            do
            {
                // Imprimir mapa de acento do filme
                print_assentos(op);

                // Menu de opcoes
                printf ("\nDigite uma opcao:\n1 - Reservar um assento\n2 - Liberar um assento\n3 - Sair\n");
                scanf ("%d", &option);

                switch (option)
                {
                    case 1:
                        // Reservar um assento
                        printf ("\nDigite a fila e o assento que deseja reservar:\n");
                        scanf ("%d %d", &fila, &assento);
                        if (reservar_assento(fila, assento, op)) {
                            printf ("\nAssento reservado com sucesso!\n");
                            }
	                    else {
                            printf ("\nAssento ja reservado ou invalido.\n");
                            }
                        break;
                    case 2:
                        // Liberar um assento
	                    printf ("\nDigite a fila e o assento que deseja liberar:\n");
	                    scanf ("%d %d", &fila, &assento);
	                    if (liberar_assento (fila, assento, op)) {
                            printf ("\nAssento liberado com sucesso!\n");
                        }
                        else {
                            printf ("\nAssento ja estava disponivel ou invalido.\n");
                        }
                        break;
                    case 3:
                        // Sair do programa
	                    printf ("\nSaindo...\n");
                        break;
                    default:
                        printf ("\nOpcao invalida. Tente novamente.\n");
                        break;
                }
            } 
            while (option != 3);
        }
        // Aviso que o programa encerrou.
        else{
            printf("\nPrograma Encerrado!\n");
        }
    }
    while (op != 4);
    
    return 0;
}
