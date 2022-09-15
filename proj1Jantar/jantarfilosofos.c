/************************************************************************************/
/*						Universidade Presbiteriana Mackenzie						*/
/*						Bacharelado em Ciência da Computação						*/
/*						  Sistemas Operacionais - Turma 04N							*/
/*																					*/
/*										Grupo:										*/
/*						  Diego Guedes de Moraes (TIA: 32148127)					*/
/*						Erick Cauã Ferreira Gomes (TIA: 32148127)					*/
/*						    Pedro Moreno Campos (TIA: 32148127)						*/
/*																					*/
/*							Data: 15 de setembro de 2022							*/
/*																					*/
/************************************************************************************/

//Problema: Jantar dos Filósofos

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <pthread.h>					//Para resolver este problema usaremos a biblioteca pthread, que nos permitirá a utilização de semáforos

#define TRUE 1

//definição de funções
void *filosofoThread(void *args);
void think(int i);
void wait(int i);
void eat(int i);

pthread_mutex_t mutex[5] = {PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};		//inicialização dos mutex, um para cara filosofo

void think(int i){			//função que representa a ação de pensar do filosofo
    printf("O filósofo %d está pensando.\n", i+1);
    sleep(5);
}

void wait(int i){			//função que representa a ação de esperar do filosofo
    printf("O filósofo %d está esperando por garfos.\n", i+1);
}

void eat(int i){			//função que representa a ação de comer do filosofo
    printf("O filósofo %d está comendo.\n", i+1);
    sleep(15);
}

void *filosofoThread(void *args){

    int i = *((int *)args);
    free((int *)args);
	int left, right;

    left = i;
    right = (i + 1) % 5;

    while (TRUE){				//looping infinito
        think(i);
        wait(i);
        while (TRUE){
            if (pthread_mutex_trylock(&mutex[left]) != 0)
                continue;

            if (pthread_mutex_trylock(&mutex[right]) != 0){
                pthread_mutex_unlock(&mutex[left]);
                continue;
            }

            printf("O filosofo %d conseguiu os dois garfos.\n", i+1);
            break;
        }
        eat(x);
        pthread_mutex_unlock(&mutex[left]);
        pthread_mutex_unlock(&mutex[right]);
    }
    pthread_exit(NULL);
}

int main(){

    pthread_t thread[5];

    for (int i = 0; i < 5; i++){
        int *j = malloc(sizeof(int));
        *j = i;
        printf("Filósofo %d sentou na mesa.\n", i+1);
        pthread_create(&thread[i], NULL, filosofoThread, void* j);
    }

    for (int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    return 0;
}
