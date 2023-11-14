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

level_list InsertCell(t_cell*p, level_list* l){
    while(p->levels>=0) {
        l->heads[p->levels] = p->next[p->levels];
        return InsertCell(p->next[p->levels-1], l);
    }

void print_LevelList(level_list*l, t_cell*p){
    level_list*cur=l;
    if ((p->levels>l->max_level)|| (p->levels<0)){
        printf("le niveau n'existe pas");
    }
    else{
        while (cur->heads[p->levels]!=0){
            printf("%d", l->heads[p->levels]);
            cur->heads[p->levels]=cur->heads[p->levels-1];
        }
    }
}

void print_AllLevelList(level_list*l){
    level_list*cur=l;
    if (l->max_level=0) {
        printf("la liste est vide");
    }
    for(int i=0;i<l->max_level;i++){
        while(l->heads[i]!=NULL){
            printf("%d", l->heads[i]);
            cur->heads[i]=cur->heads[i+1];
        }
    }
}





