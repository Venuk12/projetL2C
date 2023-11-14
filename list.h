//
// Created by Yrvan on 12/11/2023.
//
#ifndef PORJET_C__LIST_H
#define PORJET_C__LIST_H



typedef struct s_cell{
    int value;
    int levels;
    struct s_cell** next;
}t_cell;


typedef struct level_list{
    int max_level;
    t_cell** heads;
}level_list;

t_cell* createCell(int, int);
level_list createEmptyList();
level_list InsertCell(int level, t_cell*p, level_list * l);
void print_LevelCell(level_list*l, int level);
void print_AllLevelList(level_list*l);

#endif //PORJET_C__LIST_H




