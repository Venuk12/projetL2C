//
// Created by Yrvan on 06/12/2023.
//

#ifndef MODULE_TIMER_20231206_ZIP_AGENDA_H
#define MODULE_TIMER_20231206_ZIP_AGENDA_H

#include "string.h"
#include "stdlib.h"
#include "string.h"

// Structure pour une date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour une heure
typedef struct {
    int heure;
    int minute;
} Heure;

// Structure pour un rendez-vous
typedef struct {
    Date date;
    Heure heureDebut;
    Heure duree;
    char *objet;
} RendezVous;

// Structure pour un contact
typedef struct {
    char *nom;
    char *prenom;
    struct RendezVousNode *rendezVousList;
} Contact;


// Structure pour une entrée de l'agenda
typedef struct headAgenda {
    Contact contact;
    struct headAgenda *next;
} headAgenda;


// fonctions dont on a besoin
char *scanString(void);
RendezVous *createRendezVous(void);
Contact *createContact(void);





#endif //MODULE_TIMER_20231206_ZIP_AGENDA_H
