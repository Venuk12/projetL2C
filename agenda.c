//
// Created by Yrvan on 06/12/2023.
//
#include "agenda.h"
#include "stdio.h"



RendezVous *createRendezVous(void) {
    RendezVous *rv = malloc(sizeof(RendezVous));
    printf("Date (jour mois annee) : ");
    scanf("%d %d %d", &rv->date.jour, &rv->date.mois, &rv->date.annee);
    printf("Heure de début (heure minute) : ");
    scanf("%d %d", &rv->heureDebut.heure, &rv->heureDebut.minute);
    printf("Durée (heure minute) : ");
    scanf("%d %d", &rv->duree.heure, &rv->duree.minute);
    printf("Objet : ");
    rv->objet = scanString();
    return rv;
}

Contact *createContact(void) {
    Contact *c = malloc(sizeof(Contact));
    printf("Nom : ");
    c->nom = scanString();
    printf("Prénom : ");
    c->prenom = scanString();
    c->rendezVousList = NULL; // Initialise la liste de rendez-vous à NULL
    return c;
}

void insertContact(headAgenda **agenda, Contact *c) {
    headAgenda *newhead = malloc(sizeof(headAgenda));
    newhead->contact = *c;
    newhead->next = *agenda;
    *agenda = newhead;
}