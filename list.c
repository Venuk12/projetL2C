//
// Created by Yrvan on 12/11/2023.
//
#include "list.h"
#include "stdlib.h"

t_cell*createCell(int val){
    t_cell*l =(int*)malloc(sizeof(t_cell));
    l->value= val;
    l->next=NULL;
    return l;
}

t_cell*createEmptyList(){
    t_cell*l=(int*)malloc(sizeof(t_cell));
    l=NULL;
    return l;
}

struct level_list*createlevel_list(int val, int c, t_cell*h){
    struct level_list*l=(int*)malloc(sizeof(struct level_list));
    l->max_level=val;
    l->h->value=c;
    l->h->next=NULL;
    return l;

}





