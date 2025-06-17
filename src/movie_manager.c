#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include"include/movie_manager.h"

int id_global=0;
int tab[500];
int i=1;
int nb_prinact[450];
int nb_realact[450];

void Menu(){
char f_films[]="../data/Films.txt";
char f_pers[]="../data/Personnes.txt";
int ident;
int num;
printf("------------------------------MENU:-----------------------------------------------\n\n");
printf("\t\t   1. Afficher la liste des films.\n");
printf("\t\t   2. Afficher la liste des acteurs et realisateurs.\n");
printf("\t\t   3. Inserer un nouveau film.\n");
printf("\t\t   4. Inserer un nouvel acteur ou realisateur.\n");
printf("\t\t   5. Rechercher un film par identificateur.\n");
printf("\t\t   6. Supprimer le fichier des films.\n");
printf("\t\t   7. Supprimer le fichier des acteurs et realisateurs.\n");
printf("\t\t   8. Termine.\n");
printf("----------------------------------------------------------------------------------\n\n");
while(num!=8){
 printf("-->Veuillez saisir un numero a partir de MENU (1,2...7,8) :");
 scanf("%d",&num);
 printf("\n\n");
  switch(num){
    case 1:Afficher_Films(f_films);
    break;
    case 2:Afficher_Personnes(f_pers);
    break;
    case 3:Inserer_Film(f_films);
    break;
    case 4:Inserer_Personne(f_pers);
    break;
    case 5:printf("-->Veuillez saisir l'identificateur de film a recherchee  :");
           scanf("%d",&ident);
           printf("\n\n");
           while(Rechercher_Film(f_films,ident)==0){
           printf("Le film d'id %d n'est pas trouver dans la liste des films ! \n\n",ident);
           printf("--> !! Veuillez saisir un autre identificateur de film  existant a recherche  :");
           scanf("%d",&ident);
           printf("\n\n");

           }

    break;
    case 6:remove(f_films);
           printf("Le fichier des films a ete supprime avec succes !\n \n");
    break;
    case 7:remove(f_pers);
           printf("Le fichier des acteurs et realisateurs a ete supprime avec succes !\n \n");
    break;
    case 8:printf("--------------------------------Au Revoir ;)!-----------------------------------\n") ;
    break;
    default :printf("Ce numero n'existe pas dans le MENU \n\n") ;
  }
}
}

void Afficher_Films (char *f_films){
FILE *fr1;
Film info;
fr1= fopen(f_films, "r");
char ligne_pre[250];
int k=1;

if(fr1==NULL)
    puts("Erreur d'ouverture de fichier Films !");

  while((!feof(fr1))&&(fscanf(fr1," %[^\n]s",ligne_pre)==1)) {
    fscanf(fr1," %[^\n]s",ligne_pre);
    fscanf(fr1,"%d",&info.id);
    printf("--------------------------Voici les informations de film d'id %d :-----------------------\n\n",info.id);
    printf("Identificateur : %d \n\n",info.id);

     fscanf(fr1," %[^\n]s",ligne_pre);
     fscanf(fr1," %[^\n]s",info.titre);
     printf("Titre : %s \n\n",info.titre);

     fscanf(fr1," %[^\n]s",ligne_pre);
     fscanf(fr1," %[^\n]s",info.genre);
     printf("Genre : %s \n\n",info.genre);

     fscanf(fr1," %[^\n]s",ligne_pre);
     fscanf(fr1,"%d",&info.anne_produc);
     printf("Annee de production : %d \n\n",info.anne_produc);

     fscanf(fr1," %[^\n]s",ligne_pre);
     printf("Identificateurs des acteurs principaux : \n");
     for(int j=0;j<nb_prinact[k];j++){
     fscanf(fr1,"%d",&info.id_pract[j]);
     printf("  ID de l'acteur principal %d : %d \n",j+1,info.id_pract[j]);
     }
     fscanf(fr1," %[^\n]s",ligne_pre);
     printf("\nIdentificateurs des acteurs realisateurs : \n");
     for(int j=0;j<nb_realact[k];j++){
     fscanf(fr1,"%d",&info.id_react[j]);
     printf("  ID de l'acteur realisateur %d : %d \n",j+1,info.id_react[j]);
     }
    fscanf(fr1," %[^\n]s",ligne_pre);
    fscanf(fr1," %[^\n]s",info.pays);
    printf("\nPays : %s \n\n ",info.pays);

k++;
}
fclose(fr1);
}
void Afficher_Personnes(char *f_pers){
FILE *pr;
char aff_pers[555];
pr= fopen(f_pers, "r");

  if(pr==NULL)
   puts("Erreur d'ouverture de fichier Personnes !");

     while(fscanf(pr," %[^\n]s",aff_pers)==1 ) {
         printf(" %s \n\n",aff_pers);
     }

    fclose(pr);
}
void Inserer_Film (char *f_films){
int cmt=0;
int cmt2=0;
FILE *fw1;
Film infilm ;
fw1= fopen(f_films,"a");
if(fw1==NULL)
   puts("Erreur d'ouverture de fichier Films !");

 printf("------------------------------Remplir les informations de Film :-------------------------------\n");
int j;
   while(cmt2==0){
    printf("Identificateur ( !unique! ): ");
    scanf ("%d",&infilm.id);
    if(id_global!= 0){
     for( j=0;j<id_global;j++){
            if(tab[j]!=infilm.id){
               cmt++;
               }
            else{
            printf("! L'identificateur doit etre unique ( l'identificateur %d existe deja).\n\n",infilm.id);
            j=id_global;
            }
       }
       if(j==id_global){
        tab[id_global]=infilm.id;
        cmt2++;
       }
    }
    else{
      tab[id_global]=infilm.id;
      cmt2++;
        }
    }
 fprintf(fw1,"---------------------------------------Informations de Film d'id %d :----------------------------------\n",infilm.id);
    fprintf(fw1,"Identificateur :\n");
    fprintf(fw1,"%d \n",infilm.id);

    printf("Titre : ");
    scanf(" %[^\n]s",&infilm.titre);
    fprintf(fw1,"Titre :\n");
    fprintf(fw1,"%s \n",infilm.titre);

    printf("Genre : ");
    scanf(" %[^\n]s",&infilm.genre);
    fprintf(fw1,"Genre :\n");
    fprintf(fw1,"%s \n",infilm.genre);

    printf("Annee de production : ");
    scanf("%d",&infilm.anne_produc);
    fprintf(fw1,"Annee de production :\n");
    fprintf(fw1,"%d \n",infilm.anne_produc);

    printf("->Saisir nombre des acteurs principaux : ");
    fprintf(fw1,"Identificateurs des acteurs principaux : \n");
    scanf("%d",&nb_prinact[i]);
    for(int j=0;j<nb_prinact[i];j++){
    printf("  ID de l'acteur principal %d : ", j + 1);
    scanf("%d",&infilm.id_pract[j]);
    fprintf(fw1,"%d\n",infilm.id_pract[j]);
      }
    printf("->Saisir nombre des acteurs realisateurs : ");
    fprintf(fw1,"Identificateurs des acteurs realisateurs : \n");
    scanf("%d",&nb_realact[i]);
    for(int j=0;j<nb_realact[i];j++){
    printf("  ID de l'acteur realisateur %d : ", j + 1);
    scanf("%d",&infilm.id_react[j]);
    fprintf(fw1,"%d\n",infilm.id_react[j]);
      }
     printf("Pays : ");
     scanf(" %[^\n]s",&infilm.pays);
     fprintf(fw1,"Pays :\n");
     fprintf(fw1,"%s \n",infilm.pays);
     printf("\n");

  fclose(fw1);
id_global++;
i++;
   }

void Inserer_Personne(char *f_pers){
FILE *fw2;
Personne pers;
int i;
fw2= fopen(f_pers,"a");

if(fw2==NULL)
   puts("Erreur d'ouverture de fichier Personnes !");

printf("-----------------------------Remplir les informations de Personne(acteur/realisateur) :-------------------------------\n");

     printf("Identificateur : ");
     scanf ("%d",&pers.ident);
fprintf(fw2,"-------------------------------les informations de Personne(acteur/realisateur) d'id %d :-----------------------------\n",pers.ident);
     fprintf(fw2,"Identificateur : %d \n",pers.ident);

     printf("Nom : ");
     scanf(" %[^\n]s",&pers.nom);
     fprintf(fw2,"Nom : %s \n",pers.nom);

     printf("Prenom : ");
     scanf(" %[^\n]s",&pers.prenom);
     fprintf(fw2,"Prenom : %s \n",pers.prenom);

     printf("Date de naissance(JJ MM AAAA) : \n");
     fprintf(fw2,"Date de naissance(JJ MM AAAA) : \n");
     printf("->Jour : ");
     scanf("%d",&pers.date_naiss.jour);
     fprintf(fw2,"->Jour :%d\n",pers.date_naiss.jour);
     printf("->Moi : ");
     scanf("%d",&pers.date_naiss.moi);
     fprintf(fw2,"->Moi :%d\n",pers.date_naiss.moi);
     printf("->Annee : ");
     scanf("%d",&pers.date_naiss.annee);
     fprintf(fw2,"->Annee :%d\n",pers.date_naiss.annee);

     printf("Fonction (acteur /realisateur) : ");
     scanf(" %[^\n]s",&pers.fonction);
     fprintf(fw2,"Fonction (acteur /realisateur) : %s \n",pers.fonction);
     printf("\n");

  fclose(fw2);
}

int Rechercher_Film(char *f_films ,int id ){
int cmp=0;
FILE * fr2 ;
fr2= fopen(f_films, "r");
Film film_rech ;
char ligne_pre[250];
  if(fr2==NULL)
    puts("Erreur d'ouverture de fichier Films !");
int k=1;
   while(!feof(fr2)){
  fscanf(fr2," %[^\n]s",ligne_pre);
   fscanf(fr2," %[^\n]s",ligne_pre);
    fscanf(fr2,"%d",&film_rech.id);
    fscanf(fr2," %[^\n]s",ligne_pre);
     fscanf(fr2," %[^\n]s",&film_rech.titre);
     fscanf(fr2," %[^\n]s",ligne_pre);
      fscanf(fr2," %[^\n]s",&film_rech.genre);
      fscanf(fr2," %[^\n]s",ligne_pre);
       fscanf(fr2,"%d",&film_rech.anne_produc);
       fscanf(fr2," %[^\n]s",ligne_pre);
        for(int j=0;j<nb_prinact[k];j++){
         fscanf(fr2,"%d",&film_rech.id_pract[j]);
          }
          fscanf(fr2," %[^\n]s",ligne_pre);
           for(int j=0;j<nb_realact[k];j++){
            fscanf(fr2,"%d",&film_rech.id_react[j]);
             }
             fscanf(fr2," %[^\n]s",ligne_pre);
              fscanf(fr2," %[^\n]s",&film_rech.pays);

     if(film_rech.id==id){
  printf(" ----------------------le Film recherchee d'id %d  est pour informations suivants:-------------------------\n\n",id);
        printf("Identificater :%d \n\n",film_rech.id);
        printf("Titre : %s \n\n",film_rech.titre);
        printf("Genre : %s \n\n",film_rech.genre);
        printf("Annee de production : %d\n\n",film_rech.anne_produc);
        printf("Identificateurs des acteurs princpaux :\n");
        for(int j=0;j<nb_prinact[k];j++){
        printf("  ID de l'acteur principal %d : %d \n",j+1,film_rech.id_pract[j]);
        }
        printf("\nIdentificateurs des acteurs realisateurs :\n");
       for(int j=0;j<nb_realact[k];j++){
        printf("  ID de l'acteur realisateur %d : %d \n",j+1,film_rech.id_react[j]);
        }
        printf("\nPays : %s \n\n",film_rech.pays);
        cmp++;
       fclose(fr2);
       break;
    }
  k++;
  }
  if(cmp==0)
        return 0;

  else
    return 1;
}


