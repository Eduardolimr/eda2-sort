#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createVector(int *vector, int size){
    int i,range;

    printf("Range do vetor: ");
    scanf("%d", &range);

    srand((unsigned)time(NULL));
    for (i = 0; i < size; i++){
        /* gerando valores aleatórios entre zero e o range */
        vector[i] = (rand() % (range));
        printf("%d\n", vector[i]);
    }
    puts("====Vetor gerado com sucesso====");
}

void showVector(int vector[], int size){
    int i;
    puts("====Inicio Vetor");
    for (i = 0; i < size; i++){
        printf("%d\n", vector[i]);
    }
    puts("====Fim Vetor");
}

void shellSort(int vector[], int size){
    clock_t t = clock();
    int gap = size/2;
    int i, atual, j, printar;
    int v2[size];
    //cópia do vetor para ordenar para não atrapalhar a outra ordenação
    for(i = 0; i < size; i++){
        v2[i] = vector[i];
    }
    while(gap > 0){
        for(i = gap; i < size; i++){
            atual = v2[i];
            j = i;
            while(j >= gap && v2[j-gap] > atual){
                v2[j] = v2[j-gap];
                j = j-gap;
            }
            v2[j] = c;
        }
        gap = gap/2;
    }
    printf("====Tempo gasto %lfs====\n\n", (double)(clock()-t)/CLOCKS_PER_SEC);
    printf("Printar vetor ordenado? (0 = nao; outro numero = sim)");
    scanf("%d", &printar);
    if(printar != 0) showVector(v2, size);
}

void menu(){
    puts("1 - Gerar novo vetor");
    puts("2 - Fazer sort (insert e sort)");
    puts("3 - Printar vetor desordenado");
    puts("0 - Sair");
}

int main(){
    int *vector;
    int size=0, op;
    do{
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Tamanho do vetor: ");
                scanf("%d", &size);
                vector = (int *) malloc(size * sizeof(int));
                createVector(vector, size);
                break;
            case 2:
                size>0 ? shellSort(vector, size) :
                 printf("Vetor nao inicializado\n");
                break;
            case 3:
                size>0 ? showVector(vector, size) :
                 printf("Vetor nao inicializado\n");
        }
    }while (op != 0);
    return 0;
}
