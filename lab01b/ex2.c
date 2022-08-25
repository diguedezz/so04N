/*
Universidade Presbiteriana Mackenzie
Ciência da Computação - Sistemas Operacionais
Turma 04N - 25 de agosto de 2022

Diego Guedes, Erick Gomes e Pedro Moreno
*/

/*
 Escreva um programa (na linguagem C) que leia um arquivo texto (entrada) e copie para um outro
arquivo (saída), ou seja, faz o que o comando cp faz no Linux. O seu programa deve solicitar o nome do
arquivo de entrada e de saída (por linha de comando), uma vez obtido os dois nomes, o programa
deve abrir o arquivo de entrada e criar o arquivo de saída. Caso por alguma razão não possa abrir o
arquivo de entrada seu programa deve imprimir uma mensagem de aviso e finalizar, caso aconteça um
erro de criação do arquivo saída o programa imprime uma mensagem e finaliza. Caso o programa tenha
sucesso na abertura e criação, o programa lê a partir do arquivo de entrada e grava no arquivo de saída.
Finalmente, depois que o arquivo de entrada for inteiramente copiado o programa pode fechar os dois
arquivos.
Identifique no seu programa as linhas de comando onde ocorrem chamadas de sistemas ao SO.
Quantas chamadas de sistemas foram realizadas?
*/

#include <stdio.h>

int main(int argc, char *argv[])
{

    FILE *inputFile;
    FILE *outputFile;
    char *output;
    char row[100];
    char inputName[50];
    char outputName[50];

    inputFile = fopen(argv[1], "r");    // linha de comando (fopen = open file, retorna ponteiro, por isso podemos criar a condição de tratamento abaixo)
    outputFile = fopen(argv[2], "w");   // linha de comando
    if (inputFile == NULL || argc != 3) // null é retornado quando não foi encontrado nenhum arquivo
    {
        printf("Não foi encontrado nenhum arquivo!\n"); // linha de comando
        return 0;
    }
    else
        printf("Sucesso!\n");

    // copiando de um arquivo para o outro
    while (feof(inputFile) == 0)
    {
        output = fgets(row, 100, inputFile); // linha de comando
        if (output)
            fprintf(outputFile, "%s", row); // linha de comando
    }

    fclose(inputFile);  // linha de comando!
    fclose(outputFile); // linha de comando!

    // CHECANDO
    outputFile = fopen(outputName, "r");
    while (feof(outputFile) == 0) // linha de comando (a função feof serve como controle para verificar se o arquivo ainda tem linhas a serem lidas)
    {
        output = fgets(row, 100, outputFile); // linha de comando
        if (output)
            printf("%s", row); // linha de comando
    }

    fclose(outputFile);
    return 1;
}