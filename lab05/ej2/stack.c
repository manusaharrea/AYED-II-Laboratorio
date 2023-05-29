#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool inv_rep(stack s){
    return (s->size <= s->capacity && s->capacity >= 0);
}

stack stack_empty(){
    stack s = NULL;
    s = malloc (sizeof (stack));
    s->elems = NULL;
    s->size = 0;
    s->capacity = 0;
return s;    
}

stack stack_push(stack s, stack_elem e){
    assert(inv_rep(s));
    if(s->size == s->capacity){
        s->capacity = s->capacity*2;
        s->elems = realloc(s->elems, s->capacity*sizeof(stack_elem));
    }    
    s->elems[s->size] = e;
    s->size += 1;
    assert(inv_rep); 
return s;
}

stack stack_pop(stack s){
    assert (inv_rep(s));
    s->elems[s->size-1] = NULL;
    s->size -= 1;
    assert(inv_rep);
return s;
}

unsigned int stack_size(stack s){
    assert(inv_rep(s));
    return s->size;
}

stack_elem stack_top(stack s){
    assert(inv_rep(s));
    return (s != NULL ? s->elems[s->size-1] : NULL);
}

bool stack_is_empty(stack s){
    assert(inv_rep(s));
    return (s->size == 0);
}

stack_elem *stack_to_array(stack s){
    assert(inv_rep(s));
    return s->elems; 
}

stack stack_destroy(stack s){
    s->size = 0;
    s->elems = NULL;
    s->capacity = 0;
return s;
}