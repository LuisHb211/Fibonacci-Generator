/*
 * Arquivo: txtFibonacci.c
 * Compilação: gcc -std=c99 txtFibonacci.c -o txtFibonacci
 * Autor: Luis Henrique
 */

#include <stdio.h>
#include <stdlib.h>

//algoritmo para fazer a seq de fibonacci
unsigned long long int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

//a funcao ira percorrer cada elemento do array_a e ira substitui-lo pelo valor de fibonacci(i)
void preenche_array(int N, unsigned long long int *array_a) {
    for (int i = 0; i < N; i++) {
        array_a[i] = fibonacci(i);
        if(i == N - 1){
            printf("%llu\n", fibonacci(i));
        }
    }
}

/*funcao ira criar um ponteiro com "file" como referencia e ira criar um arquivo chamado "fibonacci.txt" 
com a funcao de write. Em cada elemento do array, sera printado no arquivo o seu valor, e pula-se uma linha.*/
void printa_no_arquivo(int N, unsigned long long int *array_a) {
    FILE *file = fopen("fibonacci.txt", "w");
    for (int i = 0; i < N; i++) {
        fprintf(file, "%llu\n", array_a[i]);
    }
    fclose(file);
}

int main(void) {
    #if defined(_WIN32) || defined(_WIN64)
        system("chcp 65001"); // troca para UTF-8
    #endif

    int N;
    //llu, para garantir armazenamento para os inteiros
    unsigned long long int *array_a;

    printf("Quantidade de termos da sequência de Fibonacci: ");
    //%*c para retirar o ultimo valor, como \n ou \0.
    scanf("%d%*c", &N);

    //alocacao de memoria parra o array, usando malloc, baseado no valor de N.
    array_a = (unsigned long long int *)malloc(N * sizeof(unsigned long long int));
    preenche_array(N, array_a);

    printa_no_arquivo(N, array_a);

    //como foi usado o malloc, para impedir vazamendo de memoria usa-se o free, e libera-se a mem alocada
    free(array_a);
    return EXIT_SUCCESS;
}
