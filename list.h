//
// Created by Yrvan on 12/11/2023.
//
#ifndef PORJET_C__LIST_H
#define PORJET_C__LIST_H



typedef struct s_cell{
    int value;
    int levels;
    struct s_cell**next;
}t_cell;


typedef struct level_list{
    int max_level;
    t_cell** heads;
}level_list;

t_cell* createCell(int value, int level);
level_list* createEmptyList(int max_level);
void InsertCell(level_list * l, t_cell*p);
void print_LevelList(level_list*l, int level);
void print_AllLevelList(level_list*l);
void afficher_mylistAlignee(level_list*l);
void insererTriee(level_list * l, t_cell * p);
int search_value(int x, level_list l);
level_list* createcomplex_list(int n);

#endif //PORJET_C__LIST_H




