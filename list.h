//
// Created by Yrvan on 12/11/2023.
//

#ifndef PORJET_C__LIST_H
#define PORJET_C__LIST_H

#endif //PORJET_C__LIST_H

typedef struct s_cell{
    int value;
    struct t_cell* next;
}t_cell;

typedef struct s_ht_list{
    t_cell*head;
    t_cell*tail;
}t_ht_list;

typedef struct level_list{
    int max_level;
    struct t_cell* h;
};

typedef struct s_d_list{
    int value;
    int level;
   struct level_list** tab_head;
}t_d_cell;

t_cell*createCell(int);
t_cell*createEmptyList();
struct level_list*createlevel_list(int, int, t_cell*);




