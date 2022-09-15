/*
UNIVERSIDADE PRESBITERIANA MACKENZIE

Diego Guedes de Moraes - 321
Erick Cauã Ferreira Gomes - 321
Pedro Moreno Campos - 321

Problema do Jantar dos Filósofos
*/


//para que não ocorram impasses nem starvation, protegeremos os cinco comandos seguindo a chamada think com um semáforo binário, ao invés de apenas pegar garfos, um filósofo vai realizar um down em mutex e após substituir os garfos, ele realizará um up em mutex
//

#include <stdio.h>

#define N          5
#define LEFT       (i+N-1)%N
#define RIGHT      (i+1)%N
#define THINKING   0
#define HUNGRY     1
#define EATING     2

typedef int semaforo;
int estado[N];
semaforo mutex = 1;
semaforo s[N];

void filosos(int i){
    while(true){
        think();
        take_forks();
        eat();
        put_forks();
    }
}

void take_forks(int i){
    down(&mutex);                //região crítica
    estado[i] = HUNGRY;
    test(i);
    up(&mutex);
    down(&s[i])
}

void put_forks(i){
    down(&mutex);
    estado[i] = THINKING;
    test(LEFT);
    test(RIGHT);
    up(&mutex);
}

void test(i){
    if(estado[i] == HUNGRY && estado[LEFT] != EATING && estado[RIGHT] != EATING){
        state[i] = EATING;
        up(&s[i]);
    }
}