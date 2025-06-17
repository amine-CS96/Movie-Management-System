#ifndef MOVIE_MANAGER_H
#define MOVIE_MANAGER_H

typedef struct{
     int jour;
     int moi ;
    int annee ;

}Date ;
typedef struct{
    int id ;
    char titre[50] ;
    char genre[50];
    int anne_produc ;
     int id_pract[50];
     int id_react[50];
    char pays [50];
}Film ;

typedef struct{
     int ident ;
    char nom[50] ;
    char prenom[50];
    Date date_naiss ;
    char fonction [50];
} Personne;

extern void Menu();
extern void Afficher_Films(char *f_films);
extern void Afficher_Personnes(char *f_pers);
extern void Inserer_Film (char *f_films);
extern void Inserer_Personne(char *f_pers);
extern int Rechercher_Film(char *f_films,int id);
extern int id_global;
extern int tab[500];
extern int nb_prinact[450];
extern int nb_realact[450];
extern int i;

#endif