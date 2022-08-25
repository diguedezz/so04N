#include <stdio.h>

int main(){
    FILE *arq;
    char linha[100];
    char *result;
    char entrada[50];
    printf("Digite o arquivo de entrada:\n");
    arq = fopen(scanf(entrada), "r");
    if (arq == NULL){
        printf("Não foi encontrado nenhum arquivo.\n");
        return 0;
    }
    int i = 1;
    while(! feof(arq)){
        result = fgets(linha, 100, arq);
        if (result)
            printf("linha %d: %s", i, linha);
        i++;
    }
    fclose(arq);
    return 1;
}