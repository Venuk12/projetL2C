#include <stdio.h>
#include "list.c"

int main() {
    //printf("hello word");
    //level_list* mylist= createEmptyList(7); //création d'une liste a niveau
    //insererTriee(mylist, createCell(6,2)); //insertion  cellule à niveaux
    //insererTriee(mylist, createCell(18,6));
    //print_AllLevelList(mylist); // affichage de tous les niveau de la liste
    int n=4;
    level_list*l2=createcomplex_list(n);
    search_value(n,l2);
    return 0;


}
