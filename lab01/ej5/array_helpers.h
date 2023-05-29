#ifndef MAX_SIZE
#include "mybool.h"

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {

    FILE *fichero = fopen(filepath,"rt");

    for(unsigned int i=0 ; i<max_size ; i++){
        fscanf(fichero,"%d",&array[i]);
    }

    fclose(fichero);

    return array[0];
}

void array_dump(int a[], unsigned int length) {
    // preguntar sobre caso invalid si debe imprimir un error, o el array + algo
    printf("[");
    for(unsigned int i =1 ; i<=length ; i++){
        printf(" %d",a[i]);
        if(i<length){
            printf(",");
        }
    }
    printf("]");
}

mybool array_is_sorted(int a[], unsigned int length){

    mybool ordenado = true;

    for (unsigned int i=1; i<length; i++){
        ordenado = ordenado && a[i]<a[i+1];
    }

    return ordenado;
}

#endif