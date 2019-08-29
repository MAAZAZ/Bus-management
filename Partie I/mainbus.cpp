//////////////////Mini-projet///////////////
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include "Structures.h"
liste1 *L;
liste2 *K;
liste3 *S;
/////////////////Partie 1
////////////////>>BUS

//////////// liste vide
liste1 * ListVide()
{
return NULL; 
}
///////////fonction permet d'ajouter une structure d'un bus vers une liste chaine
void InsertFin(bus x)
{ liste1 *P,*c ;
c=(liste1*)malloc(1*sizeof(liste1)) ;
if(c !=NULL)
{
     c->b=x;
     c->suiv=NULL;
}
if (L!=NULL) //liste n'est pas vide
//Chercher l'adresse de la derniere
{
P=L;
while(P->suiv!=NULL)
P = P-> suiv ;
//brancher
P->suiv=c; 
}
else
L=c ;
}
/////////// remplaire une liste chaine par les informations déja existe sur un fichier "bus"
void fichierversliste()
{
       FILE *f;
       bus x;
       f=fopen("bus.txt","r");
       while (!feof(f))
        { 
              fscanf(f,"%d",&x.numero);
              fscanf(f,"%s",x.marque);
              fscanf(f,"%s",x.lg);
              fscanf(f,"%s",x.date_achat);
              fscanf(f,"%d",&x.nb_passagers);
              InsertFin(x);
        }
        fclose(f);
}
////////////////afficher tous les bus disponibles
void AfficherListebus()
{ 
liste1 *p ;
p=L;
printf("\nLa liste des bus disponibles:");
printf("\n\n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
while(p->suiv!=NULL)
    {
     printf("\nBUS numero : %d\n",p->b.numero);
     printf("La Marque de bus : %s\n",p->b.marque);
     printf("La ligne de bus : %s\n",p->b.lg);
     printf("La Date d'achat de bus : %s\n",p->b.date_achat);
     printf("Le nombre de passagers : %d\n",p->b.nb_passagers);
     Sleep(100);
     printf("\n");
     p=p->suiv ;
     printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
     }
}
///////////////ajouter nouveau bus
void ajouterbus()
{
     bus x;
     FILE *f;
     printf("\n");
     printf("     NOUVEAU BUS    \n\n");
     printf("\n  Donner le Numero de BUS: ");
     scanf("%d",&x.numero);
     getchar();
     printf("\n  Donner la Marque: ");
     scanf("%s",x.marque);
     getchar();
     printf("\n  Donner la Ligne: ");
     scanf("%s",x.lg);
     getchar();
     printf("\n  Donner la Date d'Achat(forme jj-mm-aaaa): ");
     scanf("%s",x.date_achat);
     getchar();
     printf("\n  Donner le Nombre de Passagers: ");
     scanf("%d",&x.nb_passagers);
     printf("\n");
     printf("\n  Le BUS a ete ajoute avec succes");
     InsertFin(x);
     f=fopen("bus.txt","a");
     {
            fprintf(f,"\n%d\n",x.numero);
            fprintf(f,"%s\n",x.marque);
            fprintf(f,"%s\n",x.lg);
            fprintf(f,"%s\n",x.date_achat);
            fprintf(f,"%d\n",x.nb_passagers);
     }
     fclose(f);
}
///////////////// existance d'un bus
 int existebus(int n)
{
  liste1 *c;
  c=L;
  while (c!=NULL && c->b.numero!=n)
    c=c->suiv;
    
  if (c!=NULL)
    return 1;
  else
    return 0;
}
////////////////return la cellule de bus quand choisit
liste1 *cellule_val(int n)
{
   liste1 *c;
   c=L;
   while (c!=NULL & c->b.numero!=n)
   c=c->suiv;
   return c;
}
////////////////transformer le structure de bus vers le fichier
void listeversfichier()
{
     FILE *f;
     f=fopen("bus.txt","w+");
     liste1 *c;
     c=L;
     while(c!=NULL)
     {
            fprintf(f,"%d\n",c->b.numero);
            fprintf(f,"%s\n",c->b.marque);
            fprintf(f,"%s\n",c->b.lg);
            fprintf(f,"%s\n",c->b.date_achat);
            fprintf(f,"%d\n",c->b.nb_passagers);
            c=c->suiv;
     }
     fclose(f);
}
////////////////mise à jour l'information d'un bus
void modifierbus()
{
     liste1 *p;
     FILE *f;
     f=fopen("bus.txt","a");
     int n,m,nb_passagers;
     char date_achat[10],lg[10],marque[10];
     printf("\nDonner Le Numero de BUS Que Vous Choissez De Modifier:");
     scanf("%d",&n);
     if (existebus(n))
      {
        p=cellule_val(n);
        printf("\nBUS N:%d\n",n);
        printf("\nDonner Le Nouveau Numero de Bus:");
        scanf("%d",&m);
        p->b.numero=m; 
        printf("\nDonner La Nouvelle Marque de Bus:");
        scanf("%s",marque);
        strcpy(p->b.marque,marque);
        printf("\nDonner La Nouvelle Ligne de Bus:");
        scanf("%s",lg);
        strcpy(p->b.lg,lg);
        printf("\nDonner La Nouvelle Date d'Achat de bus:");
        scanf("%s",date_achat);
        strcpy(p->b.date_achat,date_achat);
        printf("\nDonner Le Nouveau Nombre de Passagers de bus:");
        scanf("%d",&nb_passagers);
        p->b.nb_passagers=nb_passagers;    
        listeversfichier();
        printf("\nLe BUS a ete Modifie avec succes");
        getch();
      }
     else
     printf("\nPardon,Le Numero de BUS que Vous Entrez n'Existe pas dans la Liste..\n\n");
     printf("\n\nAppuyer sur ENTRER pour retourner au menu principal ...");
     getch();
     
}
///////////////supprimer un bus
void supprimerbus()
{
  liste1 *c,*p;
  p=NULL;
  int val;
  printf("\nDonner le Numero de Bus Que Vous Pouvez Supprimer: ");
  scanf("%d",&val);
  ////
  if(L!=NULL)
    {
       if (L->b.numero==val)
         {
           c=L;
           L=L->suiv;
           free(c);  
           listeversfichier();
         }
        else
         {
          c=L;
          while (c!=NULL && c->b.numero!=val)
            {
              p=c;
              c=c->suiv;
            }
          //le bus existe dans la liste
          if(c!=NULL)
            {
              p->suiv=c->suiv;
              free(c);
              listeversfichier();
              printf("Le BUS a ete supprime avec succes");
              getch();
           }
          else //// le bus n'existe pas dans la liste
            {
              printf("\nLe Numero de BUS n'existe pas dans la Liste\n");
              printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
              getch();
            }
          }
      }
}
/////////////////
////////////////>>LIGNE
//////////// liste vide
liste2 * ListVide2()
{
return NULL; 
}
///////////fonction permet d'ajouter une structure d'une ligne vers une liste chaine
void InsertFin2(ligne s)
{
liste2 *P,*c ;
c=(liste2*)malloc(sizeof(liste2)) ;
if(c !=NULL)
{
     c->l=s;
     c->suiv=NULL;
}
if (K!=NULL) //liste n'est pas vide
//Chercher l'adresse de la derniere
{
P=K;
while(P->suiv!=NULL)
P = P-> suiv ;
//brancher
P->suiv=c; 
}
else
K=c ;
}
//////////////transformer les donnees d'une fichier vers la liste
void fichierversliste2()
{
       FILE *fi;
       ligne s;
       fi=fopen("lignes.txt","r");
       while (!feof(fi))
        { 
              fscanf(fi,"%s",&s.num);
              fscanf(fi,"%f",&s.distance);
              fscanf(fi,"%d",&s.freq_moyenne);
              fscanf(fi,"%s",s.depart);
              fscanf(fi,"%s",s.arrive);
              fscanf(fi,"%s",s.stationdepart);
              fscanf(fi,"%s",s.stationarrive);
              InsertFin2(s);
        }
        fclose(fi);
}
////////////////fonction permet d'afficher tous les lignes
void AfficherListeligne()
{ 
liste2 *p ;
p=K;
printf("La liste des Lignes disponibles:");
printf("\n\n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
while (p->suiv->suiv->suiv!=NULL) //pour résoudre le probleme de répeter la derinere ligne deux fois
{ 
     printf("\nLigne numero : %s\n",p->l.num);
     printf("La Longueur de Ligne : %f Km\n",p->l.distance);
     printf("Le Frequence moyenne : %d Min\n",p->l.freq_moyenne);
     printf("L'heure le premier Depart : %s\n",p->l.depart);
     printf("L'heure Dernier Depart : %s\n",p->l.arrive);
     printf("Station de depart : %s\n",p->l.stationdepart);
     printf("Station d'arrivee : %s\n",p->l.stationarrive);
     Sleep(100);
     p=p->suiv;
     printf("\n");
     printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
}  
}
////////////////fonction permet d'ajouter une nouvelle ligne
void ajouterligne()
{
     ligne x;
     FILE *f;
     printf("     \n NOUVELLE LIGNE\n\n ");
     printf("Donner le Numero de Ligne: ");
     scanf("%s",x.num);
     getchar();
     printf(" Donner la Longueur de Ligne : ");
     scanf("%f",&x.distance);
     getchar();
     printf(" Donner le Frequence Moyenne: ");
     scanf("%d",&x.freq_moyenne);
     getchar();
     printf(" Donner l'Heure de 1er Depart: ");
     scanf("%s",x.depart);
     getchar();
     printf(" Donner l'Heure de Dernier Depart: ");
     scanf("%s",x.arrive);
     getchar();
     printf(" Donner la Station de depart: ");
     scanf("%s",x.stationdepart);
     getchar();
     printf(" Donner la Station de d'Arrivee: ");
     scanf("%s",x.stationarrive);
     printf("\n");
     InsertFin2(x);
     printf("  La Ligne a ete ajoute avec succes");
     getch();
     f=fopen("lignes.txt","a");
     {
            fprintf(f,"\n%s\n",x.num);
            fprintf(f,"%f\n",x.distance);
            fprintf(f,"%d\n",x.freq_moyenne);
            fprintf(f,"%s\n",x.depart);
            fprintf(f,"%s\n",x.arrive);
            fprintf(f,"%s\n",x.stationdepart);
            fprintf(f,"%s\n",x.stationarrive);
     }
     fclose(f);
}
///////////////transformer les informations de liste vers le fichier
void listeversfichier2()
{
   {
     FILE *f;
     f=fopen("lignes.txt","w+");
     liste2 *c;
     c=K;
     while(c!=NULL)
     {
            fprintf(f,"%s\n",c->l.num);
            fprintf(f,"%f\n",c->l.distance);
            fprintf(f,"%d\n",c->l.freq_moyenne);
            fprintf(f,"%s\n",c->l.depart);
            fprintf(f,"%s\n",c->l.arrive);
            fprintf(f,"%s\n",c->l.stationdepart);
            fprintf(f,"%s\n",c->l.stationarrive);
            c=c->suiv;
     }
     fclose(f);
}  
}
/////////////////Modifier une ligne
void modifierligne()
{
     liste2 *c;
     FILE *f;
     f=fopen("lignes.txt","a");
     char numero[10];
     int freq_moyen;
     float dist;
     char depar[10],arriv[10],stationdepar[50],stationarriv[50],lg[10];
     printf("\nDonner Le Numero de Ligne Que Vous Choissez De Modifier:");
     gets(numero);
     
     if(K!=NULL)
     {
     c=K;
     while(c!=NULL && strcmp(c->l.num,numero)!=0)
      c=c->suiv;
      
     if(c!=NULL)
        {
        printf("\n    \nLigne Numero:%s ",numero);
        printf("\nDonner Le Nouveau Numero de Ligne: ");
        scanf("%s",lg);
        strcpy(c->l.num,lg);
        printf("\n\nDonner La Nouvelle Distance: ");
        scanf("%f",&dist);
        c->l.distance=dist;
        getchar();
        printf("\nDonner La Nouvelle Frequence Moyenne: ");
        scanf("%d",&dist);
        c->l.freq_moyenne=freq_moyen;
        getchar();
        printf("\nDonner La Nouvelle Heure de premiere Depart(forme hh:mm): ");
        scanf("%s",depar);
        strcpy(c->l.depart,depar);
        getchar();
        printf("\nDonner La Nouvelle Heure de Dernier Depart(forme hh:mm): ");
        scanf("%s",arriv);
        strcpy(c->l.arrive,arriv);
        getchar();
        printf("\nDonner le Station de Depart: ");
        scanf("%s",stationdepar);
        strcpy(c->l.stationdepart,stationdepar);
        getchar();
        printf("\nDonner le Station d'arrive: ");
        scanf("%s",stationarriv);
        strcpy(c->l.stationarrive,stationarriv);
        listeversfichier2();
        printf("\nLa Ligne a ete Modifie avec succes");
        }
        else
        printf("\nPardon,Le Numero de Ligne que Vous Entrez n'Existe pas dans la Liste..\n\n");
}
}
//////////////supprimer une Ligne
void supprimerLigne()
{
  liste2 *c,*p;
  p=NULL;
  char val[10];
  printf("\nDonner le Numero de Ligne Que Vous Pouvez Supprimer: ");
  scanf("%s",val);
  ////
  if(K!=NULL)
    {
       if (strcmp(K->l.num,val)==0)
         {
           c=K;
           K=K->suiv;
           free(c);  
           listeversfichier2();
         }
        else
         {
          c=K;
          while (c!=NULL && strcmp(c->l.num,val)!=0)
            {
              p=c;
              c=c->suiv;
            }
          //si la ligne existe dans la liste
          if(c!=NULL)
            {
              p->suiv=c->suiv;
              free(c);
              listeversfichier2();
              printf("La Ligne a ete supprime avec succes");
              getch();
           }
          else //// la ligne n'existe pas dans la liste
            {
              printf("\nLe Numero de Ligne n'existe pas dans la Liste\n");
              printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
              getch();
            }
          }
      }
}
/////////////////
////////////////>>STATION
//////////// liste vide
liste3 * ListVide3()
{
return NULL; 
}
///////////fonction permet d'ajouter une structure d'une station vers une liste chaine
void InsertFin3(station x)
{ 
liste3 *P,*c ;
c=(liste3*)malloc(sizeof(liste3)) ;
if(c !=NULL)
{
     c->s=x;
     c->suiv=NULL;
}
if (S!=NULL) //liste n'est pas vide
//Chercher l'adresse de la derniere
{
P=S;
while(P->suiv!=NULL)
P = P-> suiv ;
//brancher
P->suiv=c; 
}
else
S=c ;
}
//////////////transformer les donnees d'une fichier vers la liste
void fichierversliste3()
{
       FILE *fi;
       station s;
       fi=fopen("stations.txt","r");
       while (!feof(fi))
        { 
              fscanf(fi,"%s",&s.nom);
              fscanf(fi,"%d",&s.code1);
              fscanf(fi,"%s",&s.adress);
              InsertFin3(s);
        }
        fclose(fi);
}
////////////////fonction permet d'afficher tous les stations
void AfficherListestation()
{ 
liste3 *p ;
p=S;
printf("La liste des Stations disponibles:\n\n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
while (p->suiv->suiv!=NULL)
{ 
     printf("\n    Le Nom de la Station : %s\n",p->s.nom);
     printf("\n      Code de la Station : %d\n",p->s.code1);
     printf("\n L'adresse De La Station : %s\n",p->s.adress);
     Sleep(100);
     p=p->suiv;
     printf("\n");
     printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
} 
}
////////////////fonction permet d'ajouter une nouvelle station
void ajouterstation()
{
     station n;
     FILE *f;
     printf("     \n Nouvelle Station \n\n ");
     printf("    Donner le Nom de la Staion: ");
     scanf("%s",n.nom);
     getchar();
     printf(" \n Donner Le Numero De La Station : ");
     scanf("%d",&n.code1);
     getchar();
     printf(" \n Donner L'adresse De La Station : ");
     scanf("%s",n.adress);
     InsertFin3(n);
     printf("\n  La Station a ete ajoute avec succes");
     getch();
     f=fopen("stations.txt","a");
     {
            fprintf(f,"\n%s\n",n.nom);
            fprintf(f,"%d\n",n.code1);
            fprintf(f,"%d\n",n.code1);
     }
     fclose(f);
}
////////////////une liste vers le fichier "stations.txt"
void listeversfichier3()
{
   {
     FILE *f;
     f=fopen("stations.txt","w+");
     liste3 *c;
     c=S;
     while(c!=NULL)
     {
            fprintf(f,"%s\n",c->s.nom);
            fprintf(f,"%d\n",c->s.code1);
            fprintf(f,"%s\n",c->s.adress);
            c=c->suiv;
     }
     fclose(f);
}  
}
//////////////supprimer une station
void supprimerstation()
{
  liste3 *c,*p;
  p=NULL;
  char nome[50];
  printf("\nDonner le nom de Station Que Vous Pouvez Supprimer: ");
  scanf("%s",nome);
  ////
  if(S!=NULL)
    {
       if (strcmp(S->s.nom,nome)==0)
         {
           c=S;
           S=S->suiv;
           free(c);  
           listeversfichier3();
         }
        else
         {
          c=S;
          while (c!=NULL && strcmp(c->s.nom,nome)!=0)
            {
              p=c;
              c=c->suiv;
            }
          //si la station existe dans la liste
          if(c!=NULL)
            {
              p->suiv=c->suiv;
              free(c);
              listeversfichier3();
              printf("La Station a ete supprime avec succes");
              getch();
           }
          else //// la station n'existe pas dans la liste
            {
              printf("\nLe Numero de station n'existe pas dans la Liste\n");
              printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
              getch();
            }
          }
      }
}
//////////////
void msgbienvenue()
{
    int i;
    printf("\n\n\n\n\n");
    printf("\t\t");
  for (i = 0 ; i < 2 ; i++)
    {
        printf("\t\t\t\t");
        printf("                    \r");
        Sleep(300);
        printf("\t\t\t\t");
        printf("BIENVENUE !\r");
        Sleep(300);
    }
    system("cls");
}
////////////////
void afficher_menu()
{
    // Menu principal
    system("COLOR F9");
    msgbienvenue();
    printf("\n\n");
    printf("               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\n");
    printf("                 --------------------------------------------\n");
    printf("                    <-> La Gestion De Reseau M'dina Bus <->\n");
    printf("                 --------------------------------------------\n");
    printf("                    [1] Gestion DU BUS\n");
    printf("                    [2] Gestion DE LA LIGNE\n");
    printf("                    [3] Gestion DE LA STATION\n");
    printf("                    [4] Quitter\n");
    printf("               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n\n");
    printf("                        Veuillez choisir votre choix :");
}
///////////////////////
void afficher_menu1()
{
    // Menu du Bus
    system("COLOR F0");
    printf("\n\n");
    printf("               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\n");
    printf("                 --------------------------------------------\n");
    printf("                          <-> LA GESTION DU BUS <->\n");
    printf("                 --------------------------------------------\n\n");
    printf("                    [1] Afficher tous les bus disponibles\n");
    printf("                    [2] Ajouter un nouveau Bus\n");
    printf("                    [3] Mise a jour des information d'un Bus\n");
    printf("                    [4] Supprimer un Bus\n");
    printf("                    [5] Retour au menu principal \n\n\n");
    printf("               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n\n");
    printf("                        Veuillez choisir votre choix :");
}
///////////////
void afficher_menu2()
{
    // Menu de la ligne
    system("COLOR F0");
    printf("\n\n");
    printf("\n\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\n");
    printf("                 --------------------------------------------\n");
    printf("                        <-> LA GESTION DE LA LIGNE <->\n");
    printf("                 --------------------------------------------\n\n\n");
    printf("                    [1] Afficher tous les Lignes disponibles\n");
    printf("                    [2] Ajouter un nouveau ligne\n");
    printf("                    [3] Mise a jour des information d'une ligne\n");
    printf("                    [4] Supprimer Une Ligne\n");
    printf("                    [5] Retour au menu principal \n");
    printf("\n\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n\n");
    printf("                        Veuillez choisir votre choix :");
}
////////////////
void afficher_menu3()
{
    // Menu de la Station
    system("COLOR F0");
    printf("\n\n");
    printf("               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\n");
    printf("                 --------------------------------------------\n");
    printf("                       <-> LA GESTION DE LA STATION <->\n");
    printf("                 --------------------------------------------\n\n\n");
    printf("                    [1] Afficher Les Stations\n");
    printf("                    [2] Ajouter une nouvelle Station\n");
    printf("                    [3] Supprimer une station\n");
    printf("                    [4] Retour au menu principal \n\n\n");
    printf("               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n\n");
    printf("                        Veuillez choisir votre choix :");
}
////////////
//////////////
////////////
int main()
{
    char c,a,b,d;
    //fichierversliste();
    //fichierversliste2();
    //fichierversliste3();
    while(1)
    {
        afficher_menu();
        c = getch();
        while(c>'4' || c<'1')
            c = getch();
            // clear console
        system("cls");
        
         switch(c)
           {
            case '1':
                 {
                 fichierversliste();
                 while(1)
                      {
                       afficher_menu1();

                        a = getch();
                        while(a>'5' || a<'1')
                        a = getch();

                         // clear console
                        system("cls");

                        switch(a)
                        {
                         case '1':
                           {
                            AfficherListebus();
                            break;
                           }
                         case '2':
                           {
                            ajouterbus();
                            break;
                           }
                         case '3':
                           {
                            modifierbus();
                            break;
                           }
                         case '4':
                           {
                            supprimerbus();
                            break;
                           }
                           case '5':
                                {
                                    main();
                                    break;
                                }
                                }
                                printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
                                getchar();
                                system("cls");
                          
                          }
                          }
                          //////////
            case '2':
                   {
                   fichierversliste2();
                     while(1)
                         {
                           afficher_menu2();

                           b = getch();
                           while(b>'5' || b<'1')
                           b = getch();

                           // clear console
                           system("cls");

                           switch(b)
                           {
                            case '1':
                               {
                               AfficherListeligne();
                               break;
                                }
                            case '2':
                               {
                               ajouterligne();
                               break;
                               }
                            case '3':
                               {
                               modifierligne();
                               break;
                                }
                            case '4':
                                {
                                supprimerLigne();
                                break; 
                                }
                                case '5':
                                {
                                     main();
                                    break;
                                }
                                }
                                printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
                                getchar();
                                system("cls");
                 
                 }
                 }
                 ///////////
            case '3':
                 {
                 fichierversliste3();
                  while(1)
                       {
                        afficher_menu3();

                         d = getch();
                        while(d>'4' ||d<'1')
                         d = getch();

                         // clear console
                          system("cls");

                         switch(d)
                                {
                                case '1': 
                                     {    
                                      AfficherListestation();
                                      break;
                                      }
                                case '2':    
                                     {    
                                     ajouterstation();
                                     break;
                                     }
                                case '3':    
                                     {    
                                     supprimerstation();
                                     break;
                                      }
                                      case '4':
                                      {
                                       main();
                                       break;
                                      }
                                      }
                                      printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
                                      getchar();
                                      system("cls");
                                 
                  }
                  }
          /////////////
            case '4':
                 {
                 exit(0);
                 break;
                 }
    }
  } 
    printf("\nAppuyer sur ENTRER pour retourner au menu principal ...");
    getchar();
    system("cls");
    return 0;
}
