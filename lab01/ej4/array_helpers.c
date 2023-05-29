#include "array_helpers.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    FILE * fp;
    fp = fopen (filepath, "r");
    fscanf(fp, "%u", &max_size);
    for (unsigned int i = 0; i < max_size; i++){
        fscanf (fp, "%d", &array[i]);
    }   
    fclose(fp);
return max_size;
}

void array_dump(int a[], unsigned int length) {
    printf ("[ ");
    for (unsigned int i = 0; i < length; i++) { 
        printf("%d ", a[i]);
    }
    printf("]");
    printf("\n");
}

bool array_is_sorted(int a[], unsigned int length){
    bool result = true;
    for (unsigned int i = 0; i < length - 1 && result == true; i++){
        if (a[i] > a[i+1]){
            result = false;
        }
    }
    return result;
}

/*
bool result = true;
while (i < lenght && result == true){
    if (a[i] > a[i+1]){
        result = false;
    }
    i++;
} 
*/
