//
// Created by Yrvan on 12/11/2023.
//
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

//création d'une liste à niveau vide
t_cell* createCell(int val, int levels){
    t_cell* p =(t_cell*)malloc(sizeof(t_cell));
    p->value=val;
    p->levels = levels;
    p->next = (t_cell**)malloc(levels*sizeof(t_cell*)); // création d'un tableau de pointeurs
    for(int i=0; i<levels; i++){
        p->next[i] = NULL; //tous en tête de chaqua niveaux sont mises a NULL
    }
    return p;
}
//Création d'une liste a niveau vide

level_list* createEmptyList(int max_levels){
    level_list*l=(level_list*)malloc(sizeof(level_list));
    l->max_level = max_levels;
    l->heads = (t_cell**)malloc(max_levels*sizeof(t_cell*)); // création d'un tableau de pointeurs
    for(int i =0; i<max_levels; i++){
        l->heads[i]= NULL; //toutes les cellules en tête de chaqua niveaux sont mises a NULL
    }
    return l;

}

//Fonction pour insérer une liste a niveau

void InsertCell( level_list* l, t_cell*p){
    int level= p->levels;
    if (level>=0 && level< l->max_level){   //on vérifie si le niveau de la liste est valide
        p->next[level]=l->heads[level];
        l->heads[level]=p;
    }else{
        printf("Niveau invalide\n");
    }
}

void print_LevelList(level_list*l, int level){
    if (level>=0 && level<l->max_level){ //on vérifie si le niveau de la liste est valide
        printf("Niveau %d :", level);
        t_cell*cur=l->heads[level]; //on utilise un curseur pour afficher le niveau de la liste
        while (cur!=NULL){
            printf("%d", cur->value);
            cur=cur->next[level];
        }
        printf("\n");
    }else{
        printf("Niveau invalide\n");
    }
}

void print_AllLevelList(level_list*l){
    for (int i = 0; i < l->max_level; i++) { // parcours de i jusqu'au niveau max
        print_LevelList(l, i); // il nous reste plus qu'a utilisé la fonction précédente avec l'indice i qui montre le niveau de la liste
    }
}


void afficher_mylistAlignee(level_list*l){
    int cpt_columns=0;
    //on essaye de trouver le nombre total de colonnes
    for (int i=0; i<l->max_level;i++){
        if(l->heads[i] !=NULL && cpt_columns<i+1){
            cpt_columns=i+1;
        }
    }
    //affichage des niveaux alignees
    for(int i=0;i<cpt_columns;i++){
        print_LevelList(l,i);
    }
}

// Fonction pour insérer une cellule à niveau dans la liste triée par ordre croissant
void insererTriee(level_list * l, t_cell * p) {
    int niveau = p->levels;

    if (niveau >= 0 && niveau < l->max_level) {
        t_cell * prev = NULL;
        t_cell * cur = l->heads[niveau];

        // Trouver ou placer notre cellule
        while (cur != NULL && cur->value < p->value) {
            prev = cur;
            cur = cur->next[niveau];
        }

        // Insertion la cellule au bon endroit
        if (prev == NULL) {
            // Insertion en tête de liste
            p->next[niveau] = l->heads[niveau];
            l->heads[niveau] = p;
        } else {
            p->next[niveau] = cur;
            prev->next[niveau] = p;
        }
    } else {
        printf("Niveau invalide.\n");
    }
}





