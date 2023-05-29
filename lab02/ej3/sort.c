#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/*
static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned ppiv,i,j;
    ppiv=izq;
    i=izq+1;
    j=der;
    while(i<=j){
        if(a[i]<=a[ppiv]){
            i=i+1;
        } else if(a[j]>=a[ppiv]){
            j=j-1;
        } else if(a[i]>a[ppiv] && a[j]<a[ppiv]){
            swap(a,i,j);
        }
    } 
    swap(a,ppiv,j);
    ppiv = j;
return ppiv;
} 
*/
static unsigned int partition (int a[], unsigned int izq, unsigned int der){
    unsigned ppiv,i,j;
    ppiv=izq;
    i=izq+1;
    j=der;
    while(i<=j){
        if(goes_before(a[i],a[ppiv])){
            i=i+1;
        } else if(goes_before(a[ppiv],a[j])){
            j=j-1;
        } else if(goes_before(a[ppiv],a[i]) && goes_before(a[j],a[ppiv])){
            swap(a,i,j);
        }
    } 
    swap(a,ppiv,j);
    ppiv = j;
return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;
    if (der > izq){
        ppiv = partition (a,izq,der);
        if(izq < ppiv){
            quick_sort_rec(a,izq,ppiv-1);
            quick_sort_rec(a,ppiv+1,der);
        } else {
            quick_sort_rec(a,izq,ppiv);
            quick_sort_rec(a,ppiv+1,der);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

