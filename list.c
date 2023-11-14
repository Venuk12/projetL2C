//
// Created by Yrvan on 12/11/2023.
//
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

t_cell* createCell(int val, int levels){
    t_cell* p =(t_cell*)malloc(sizeof(t_cell));
    p->value= val;
    p->levels = levels;
    p->next = (t_cell**)malloc(levels*sizeof(t_cell*));
    for(int i =0; i<levels; i++){
        p->next[i] = NULL;
    }
    return p;
}



level_list CreateEmptyList(int max_levels){
    level_list l;
    l.max_level = max_levels;
    l.heads = (t_cell**)malloc(max_levels*sizeof(t_cell*));
    for(int i =0; i<max_levels; i++){
        l.heads[i]= NULL;
    }
    return l;

}

level_list InsertCell( int level, t_cell*p, level_list * l ){
    while(level>0) {
        l->heads[level] = p->next[level];
        return InsertCell(level, p, l->heads[level-1]);
    }

}

void print_LevelList(level_list*l, int level, t_cell*p){
    if ((level>l->max_level)|| (level<0)){
        printf("le niveau n'existe pas");
    }
    else{
        while (l->heads[level]!=0){
            printf("%d", l->heads[level]);
            l->heads[level]=l->heads[level]->next;
        }
    }
}

void print_AllLevelList(level_list*l){
    if (l->max_level=0) {
        printf("la liste est vide");
    }
    for(int i=0;i<l->max_level;i++){
        while(l->heads[i]!=NULL){
            printf("%d", l->heads[i]);
            l->heads[i]=l->heads[i]->next;
        }
    }
}





