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
    if (niveau >= 0 && niveau < l->max_level) { // si le niveau de la cellule correspond au niveaux max de la liste
        for(int i=0; i<=niveau;i++){ //on commence au niveau zéro
            t_cell * prev = NULL;
            t_cell * cur = l->heads[i];
            // Trouver ou placer notre cellule
            while (cur != NULL && cur->value < p->value) {
                prev = cur;
                cur = cur->next[i];
            }
            // Insertion la cellule au bon endroit
            if (prev == NULL) {
                // Insertion en tête de liste
                p->next[i] = l->heads[i];
                l->heads[i] = p;
            } else {
                p->next[i] = cur; //insertion au milieu de la liste si elle n'est pas vide.
                prev->next[i] = p;
            }
        }
    } else {
        printf("Niveau invalide.\n");
    }
}


level_list* createcomplex_list(int n) {
    level_list*l=createEmptyList(int n);
    int nb_cell = (int)pow(2, n) - 1;
    int cpt;
    for(int i = 0; i < n; i++){ // on commence par la première ligne
        cpt=1;
        if ((i == 0) || (i == 1)){
            while (cpt <= nb_cell) { // on défini le nombre de cellules par niveau
                insererTriee(l, createCell(cpt, i));
                cpt += i + 1;
            }
        } 
        else{
            while (cpt <= nb_cell){
                insererTriee(l, createCell(cpt, i));
                cpt = (int)pow(i, 2);
            }
        }
        
    }
    return l;
}

int search_value(int x, level_list l){
    int niveau=l.max_level; // valeur qui va prendre le nombres de niveaux de la liste.
    level_list cur= l; //initialisation d'un curseur pour se déplacer dans la liste.
    while(niveau>=0){
        while(cur.heads[niveau]!=NULL || cur.heads[niveau]->value!=x){ // tant que le curseur n'a pas trouver la valeur et qu'il n'est pas à null
            cur.heads[niveau] =cur.heads[niveau]->next[niveau]; // déplacement du curseur dans la liste.
        }

        if (cur.heads[niveau]->value==x){
            return niveau; // la fonction retourne la valeur du niveau où a été trouvée la valeur.
        }
        else{
            niveau-=1;
        }
    }
    return 0;
}

int search_valuefirstlevel(level_list*l){
    int x =-1;
    printf("saisir un entier: ");
    scanf("%d", &x);
    if (x<0){
        return 0;
    }
    level_list*cur=l;
    while (cur->heads[0]!=NULL || cur->heads[0]->value!=x){ // on regarde seulement le niveau 0 donc pas besoin d'incrémenter ou de soustraire une variable temporaire.
        cur->heads[0] =cur->heads[0]->next[0];
    }
    if (cur->heads[0]->value==x){
        return 1; // si la valeur se trouve dans la liste
    }
    else{
        return 0; // si elle n'y est pas
    }

}
