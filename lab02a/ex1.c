/*
Universidade Presbiteriana Mackenzie
Ciência da Computação - Sistemas Operacionais
Turma 04N - 01 de setembro de 2022

Diego Guedes, Erick Gomes e Pedro Moreno
*/

/*
Rode o programa anterior para valores grandes de n. As
mensagens sempre estar˜ao ordenadas pelo valor de i?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    
    pid_t childpid = 0;
    int i, n;
    
    if (argc != 2){ /* check for valid number of command-line arguments */
        fprintf(stderr, "Usage: %s processes\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    for (i = 1; i < n; i++)
        if (childpid = fork())
            break;
    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n",i, (long)getpid(), (long)getppid(), (long)childpid);
    return 0;
}