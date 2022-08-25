/*
Universidade Presbiteriana Mackenzie
Ciência da Computação - Sistemas Operacionais
Turma 04N - 25 de agosto de 2022

Diego Guedes, Erick Gomes e Pedro Moreno
*/

/*
Enunciado LAB01b - Exercício 1:
O comando cat é usado no sistema operacional Linux para exibir o conteúdo de um arquivo na tela do
computador. Escreva um programa (na linguagem C) faça exatamente o que o cat faz, o programa
deverá ler um arquivo texto (entrada) informado por linha de comando no interpretador de comando
(Como se faz isso ?) e depois imprimir o conteúdo do arquivo na tela. Faça todos os testes necessários
para abertura, leitura e ao final não se esqueça de fechar o arquivo.
Identifique no seu programa as linhas de comando 
*/

#include <stdio.h>

int main(){

    FILE *inputFile;
    char row[100];
    char *output;

    inputFile = fopen("arqEx1.txt", "r"); //linha de comando (fopen = open file, retorna ponteiro, por isso podemos criar a condição de tratamento abaixo)
    if (inputFile == NULL) //null é retornado quando não foi encontrado nenhum arquivo
    {
        printf("Não foi encontrado nenhum arquivo!\n"); //linha de comando
        return 0;
    }

    while(feof(inputFile) == 0) //linha de comando (a função feof serve como controle para verificar se o arquivo ainda tem linhas a serem lidas)
    {
        output = fgets(row, 100, inputFile); //linha de comando
        if (output)
            printf("%s", row); //linha de comando
    }
    fclose(inputFile); //linha de comando!
    return 1;
}