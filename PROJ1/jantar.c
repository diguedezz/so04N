/*
UNIVERSIDADE PRESBITERIANA MACKENZIE

Diego Guedes de Moraes - 321
Erick Cauã Ferreira Gomes - 321
Pedro Moreno Campos - 321

Problema do Jantar dos Filósofos
*/

// para que não ocorram impasses nem starvation, protegeremos os cinco comandos seguindo a chamada think com um semáforo binário, ao invés de apenas pegar garfos, um filósofo vai realizar um down em mutex e após substituir os garfos, ele realizará um up em mutex
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define TRUE 1

typedef pthread_mutex_t semaforo;
int estado[N];
pthread_mutex_t mutex;
pthread_mutex_t s[N];

void think();
void eat();
void take_forks(int i);
void put_forks(int i);
void test(int i);
void *filosos(void *args);

void think()
{
    sleep(5);
}

void eat()
{
    sleep(15);
}

void *filosos(void *args)
{
    int i = (long)args;
    while (TRUE)
    { // looping infinito
        think();
        take_forks(i);
        eat();
        put_forks(i);
    }
}

void take_forks(int i)
{                                 // i = nº de filosofos
    pthread_mutex_lock(&mutex);   // região crítica
    estado[i] = HUNGRY;           // registra a fome do filosofo
    test(i);                      // testa se os garfos estao disponiveis
    pthread_mutex_unlock(&mutex); // sai da região critica
    pthread_mutex_lock(&s[i]);    // bloqueia caso os garfos nao foram pegos
}

void put_forks(int i)
{
    pthread_mutex_lock(&mutex); // região crítica
    if (estado[i] == EATING)
    {
        printf("O filósofo %d largou os garfos!\n", i);
    }
    estado[i] = THINKING;         // depois de comer o filosofo larga os garfos e volta a pensar
    test(LEFT);                   // testa se o vizinho a esuqerda pode comer
    test(RIGHT);                  // testa se o vizinho a esuqerda pode comer
    pthread_mutex_unlock(&mutex); // sai da região crítica
}

void test(int i)
{
    if (estado[i] == HUNGRY && estado[LEFT] != EATING && estado[RIGHT] != EATING)
    {
        estado[i] = EATING;
        printf("O filósofo %d está comendo!\n", i);
        pthread_mutex_lock(&s[i]);
    }
    else if (estado[i] == HUNGRY)
    {
        printf("O filósofo %d está esperando para comer!\n", i);
    }
}

int main(int arg, char *args[], char *envp[])
{

    pthread_t filosos[N];
    pthread_mutex_init(&mutex, 0);
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&s[i], 0);
    }

    for (int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&s[i]);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}