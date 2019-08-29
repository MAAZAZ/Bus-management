//////////////////mini projet////////////////////////
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include "Structures.h"
liste *L;
liste_s *S;
/////////////////Partie 2
/////////////////>>fonctionalité 1
///////////////fonction permet de retourner la dernier cellule de liste
liste * AdresseDernierCellule()
 {
   liste *p;
   if (L==NULL)
     return L;
   else
   {
    p=L;
    while (p->suiv!=NULL)
      p=p->suiv;
    return p;
   }
 }
//////////////////fonction permet d'ajouter des une cellule à la fin d'un liste
void AjoutFin(ligne x)
{
      liste *c,*p;
      //reserver l'espace
      c=(liste*)malloc(sizeof(liste));
      c->l=x;
      c->suiv=NULL;
     //Adresse de la derniere cellule
     p=AdresseDernierCellule();
     //si L est liste vide
    if (p==NULL)  
      L=c;
    else
       p->suiv=c;
 }
//////////////transformer les donnees d'une fichier vers la liste
void fichierversliste()
{
       FILE *f;
       ligne s;
       f=fopen("lignes.txt","r");
       while (!feof(f))
        { 
              fscanf(f,"%s",s.num);
              fscanf(f,"%f",&s.distance);
              fscanf(f,"%d",&s.freq_moyenne);
              fscanf(f,"%d",&s.depart.heure);
              fscanf(f,"%d",&s.depart.minute);
              fscanf(f,"%d",&s.arrive.heure);
              fscanf(f,"%d",&s.arrive.minute);
              fscanf(f,"%s",s.firststat);
              fscanf(f,"%s",s.laststat);
              fscanf(f,"%s",s.statdep);
              fscanf(f,"%s",s.statarriv);
              AjoutFin(s);
        }
        fclose(f);
}
////////////////fonction permet de vérifier l'existance d'une ligne
int existeligne(char numero[])
{
 liste *c;
 c=NULL;
 if(L!=NULL)
 {
  c=L;
  while(c!=NULL && strcmp(c->l.num,numero)!=0)
  c=c->suiv;
 }
 if(c==NULL)
 return 0;
 else
 return 1;
}
//////////////fonction retourner la position de ligne spécifier par l'utlisateur
liste * positionliste(char numero[])
{
 liste *c;
 c=L;
   while(c!=NULL && strcmp(c->l.num,numero)!=0)
   {
   c=c->suiv;
   }
  return c;       
}
//////////////fonction permet de convertir une chaine de caratere minuscule vers une chaine de caractere majuscule
void MinToMaj(char *chMin,char *chMaj)
{
int i,N;
N=strlen(chMin);
for(i=0;i<=N;i++)
 if(chMin[i]>='a' && chMin[i]<='z')
  chMaj[i]=chMin[i]+('A'-'a');
 else
  chMaj[i]=chMin[i];
}
///////////seulement pour tester
void AfficherListeligne()
{ 
liste *p ;
p=L;
printf("La liste des Lignes disponibles:");
printf("\n\n");
printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
while (p!=NULL) 
{ 
     printf("\nLigne numero : %s\n",p->l.num);
     printf("La Longueur de Ligne : %f Km\n",p->l.distance);
     printf("Le Frequence moyenne : %d Min\n",p->l.freq_moyenne);
     printf("L'heure le premier Depart : %d:%d\n",p->l.depart.heure,p->l.depart.minute);
     printf("L'heure Dernier Depart : %d:%d\n",p->l.arrive.heure,p->l.arrive.minute);
     printf("Station de depart : %s\n",p->l.firststat);
     printf("Station d'arrivee : %s\n",p->l.laststat);
     printf("Trajet de depart : %s\n",p->l.statdep);
     printf("Trajet d'arrivee : %s\n",p->l.statarriv);
     Sleep(100);
     p=p->suiv;
     printf("\n");
     printf("°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°\n");
}  
}
//////////////horaires de ligne
void horaires_ligne()
{
  char numero[10];
  char stat1[1000],stat2[1000];
  char *proch;
  char choix,n;
  liste *c;
  printf("Donner Le Numero de Ligne:");
  scanf("%s",numero);                         
  if(existeligne(numero)!=1)                           
   {
    printf("\n  Impossible..Ce Numero de Ligne n'existe pas dans la Liste\n\n");
    printf("  Veuillez Enter Un Numero De Ligne Correcte..\n");
    printf("\n\n  Appuyer sur ENTRER pour retourner au menu principal ...");
    getch();
    system("cls");
    horaires_ligne();
   }
   else
    {
       c=positionliste(numero);
       printf("Votre station:");
       scanf("%s",stat1);
       MinToMaj(stat1,stat2);
       getchar();
       printf("\n\nVous Pouver Choisir Votre Direction (o/n):");
       scanf("%c",&choix);
       getchar();
       
       if(choix=='o'|| choix=='O')
       {
            printf("\nVeuiller Choisir svp Votre Direction (en format a=aller r=retour (a/r)):");
            scanf("%c",&n);
            getchar();
            if(n=='a' || n=='A')
            {
                    printf("\n\nLa Liste des station dans la prochaine passage:");
                    proch=strstr(c->l.statdep,stat2);
                    printf("\n\n%s",proch);
            } 
            if(n=='r' || n=='R')
            {
                    printf("\n\nLa Liste des station dans la prochaine passage:"); 
                    proch=strstr(c->l.statarriv,stat2); 
                    printf("\n\n%s",proch);
            }
       }
       else
       {
           printf("\n\nLa Liste des station dans la prochaine passage:\n");
           proch=strstr(c->l.statdep,stat2);
           printf("\n\n\nALLER:%s",proch);
           proch=strstr(c->l.statarriv,stat2);
           printf("\n\n\nRETOUR:%s",proch);
       }
    }
}
//////////// liste station vide (INSIALISER)
liste_s * ListVide()
{
return NULL; 
}
///////////fonction permet d'ajouter une structure d'un bus vers une liste chaine
void InsertFin(station x)
{ liste_s *P,*c ;
c=(liste_s*)malloc(1*sizeof(liste_s)) ;
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
/////////// remplaire une liste chaine par les informations déja existe sur un fichier "bus"
void fichierverslistestat()
{
       FILE *f;
       station x;
       f=fopen("stations.txt","r");
       while (!feof(f))
        { 
              fscanf(f,"%s",x.nom);
              fscanf(f,"%d",&x.b.numero);
              fscanf(f,"%s",x.b.lg);
              fscanf(f,"%s",x.b.times_al);
              fscanf(f,"%s",x.b.times_re);
              InsertFin(x);
        }
        fclose(f);
}
/////////////////>>fonctionalité 2
///////////horaires d'arrét
void horaire_arret()
{
     liste *p;
     liste_s *c;
     char *n;
     n=(char*)malloc(5);
     char arret1[50],arret2[50],ligne[10];
     char *exist1 , *exist2;
     char direction;
     char *proc;
     FILE *f;
     f=fopen("stations.txt","r");
     printf("SVP Taper Le Nom de Prochaine Arret:");
     scanf("%s",arret1);
     MinToMaj(arret1,arret2);// si l'utilisateur tape le nom en miniscule
     printf("\n\nLa liste des lignes passent par cette station:\n");
     p=L;
     while(p!=NULL)
     {
       exist1=strstr(p->l.statdep,arret2);
       exist2=strstr(p->l.statarriv,arret2);
       if(exist1!=NULL)
       {
        Sleep(800);
        printf("\n\n           La Ligne N %s\n\n",p->l.num);
        Sleep(800);
        printf("ALLER  :%s\n\n",p->l.statdep);
        Sleep(800);
        printf("RETOUR :%s\n\n",p->l.statarriv);
        }
       else
       if(exist2!=NULL)
       {
        Sleep(800);
        printf("\n\n            La Ligne N %s\n\n",p->l.num);
        Sleep(800);
        printf("ALLER  :%s\n\n",p->l.statdep);
        Sleep(800);
        printf("RETOUR :%s\n\n",p->l.statarriv);
        }
         p=p->suiv;
     }
     printf("Choissez Votre Ligne:");
     scanf("%s",ligne);
     getchar();
     printf("Choisir Votre Direction en format a=aller r=retour (a/r)):");
     scanf("%c",&direction);
     c=S;
     if(direction=='a' || direction=='A')
     {
        printf("La liste des Bus disponibles:");
        printf("\n05h 06h 07h 08h 09h 10h 11h 12h 13h 14h 15h 16h 17h 18h 19h 20h 21h\n");
        while(c!=NULL)
        {
          if(strcmp(c->s.b.lg,ligne)==0 && strcmp(c->s.nom,arret2)==0)
          {
            n="05";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("\n%d  ",c->s.b.numero);
            else
            printf("\n    ");
            n="06";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="07";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="08";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="09";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="10";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="11";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="12";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="13";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="14";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="15";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="16";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="17";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="18";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="19";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d    ",c->s.b.numero);
            else
            printf("    ");
            n="20";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="21";
            proc=strstr(c->s.b.times_al,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
          }
          c=c->suiv;
        }
      }
     else
        if (direction=='r' || direction=='R')
        {
         printf("La liste des Bus disponibles:");
         printf("\n05h 06h 07h 08h 09h 10h 11h 12h 13h 14h 15h 16h 17h 18h 19h 20h 21h");
         while(c!=NULL)
        {
          if(strcmp(c->s.b.lg,ligne)==0 && strcmp(c->s.nom,arret2)==0)
          {
            n="05";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("\n%d  ",c->s.b.numero);
            else
            printf("\n    ");
            n="06";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="07";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="08";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="09";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="10";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="11";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="12";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="13";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="14";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="15";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="16";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="17";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="18";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="19";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d    ",c->s.b.numero);
            else
            printf("    ");
            n="20";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");
            n="21";
            proc=strstr(c->s.b.times_re,n);
            if(proc!=NULL)
            printf("%d  ",c->s.b.numero);
            else
            printf("    ");                          
          }
          c=c->suiv;
        }
        }
        else
         printf("ERROR #404");
         printf("\n\nAppuyer sur ENTRER pour retourner au menu principal ...");
         getch();
}
///////////////>>fonctionalité 3
/////////////////prochaine passage
void prochaine_passage()
{
  char arret1[50],arret2[50];
  char direction;
  char *proc1,*proc2;
  char ligne[10];
  liste_s *c;
  int i,s;
  liste *p,*k;
  time_t secondes;
  struct tm instant;
  time(&secondes);
  printf("SVP Taper Le Nom de La Prochaine Arret:");
  scanf("%s",arret1);
  MinToMaj(arret1,arret2); // si l'utilisateur tape le nom en miniscule
  instant=*localtime(&secondes);
  //printf("%d:%d\n",instant.tm_hour, instant.tm_min);
  getchar();
  printf("\n\nTaper votre Direction ( format a=aller r=retour ) (a/r):");
  scanf("%c",&direction);
  c=S;
  p=L;
  printf("\nProchaine Passage: %s",arret2);
  printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
  if(direction=='a' || direction=='A')
  while(c!=NULL)
  {
     if(strcmp(c->s.nom,arret2)==0)
     {
       while(p!=NULL)
         {
         proc1=strstr(p->l.statdep,arret2);
         if(proc1!=NULL)
         printf("\nL0%s direction %s",p->l.num,p->l.laststat);
         p=p->suiv;
         }
     }
   c=c->suiv;
  }
   else
    if(direction=='r' || direction=='R')
    while(c!=NULL)
     {
      if(strcmp(c->s.nom,arret2)==0)
       {
       while(p!=NULL)
         {
         proc1=strstr(p->l.statarriv,arret2);
         if(proc1!=NULL)
         printf("\nL0%s direction %s",p->l.num,p->l.firststat);
         p=p->suiv;
         }
       }
   c=c->suiv;
    }
    else 
    {
    printf("\nchoix incorrecte..");
    system("cls");
    prochaine_passage();
    }
    printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
    printf("\n\nTaper Le Numero de votre Ligne:");
    scanf("%s",ligne);
    k=L;
    while (k!=NULL && strcmp(k->l.num,ligne)!=0)
    k=k->suiv;
    if(direction=='a' || direction=='A') 
    printf("\nProchaine Passage %s de L0%s direction %s:",arret2,k->l.num,k->l.laststat);
    else
    printf("\nProchaine Passage %s de L0%s direction %s:",arret2,k->l.num,k->l.firststat);
    //printf("\n a %d:%d (dans %d min)\n",instant.tm_hour,instant.tm_min);
    for(i=1;i<=5;i++)
    {
    s=i*k->l.freq_moyenne+instant.tm_min;
    if(s>=60)
    {
    Sleep(100);
    printf("\n\n a %d:%d (dans %d min)\n",instant.tm_hour+1,s-60,i*k->l.freq_moyenne);
    }
    else
    {
    Sleep(100);
    printf("\n\n a %d:%d (dans %d min)\n",instant.tm_hour,s,i*k->l.freq_moyenne);
    }
    }
    printf("\n\nAppuyer sur ENTRER pour retourner au menu principal ...");
    getch();
}
/////////////////menu principale
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
///////////////
void afficher_menu()
{
    // Menu
    system("COLOR F9");
    msgbienvenue();
    printf("               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n\n");
    printf("                 --------------------------------------------\n");
    printf("                             ->  BONJOUR ! ->\n");
    printf("                 --------------------------------------------\n");
    printf("                         [1] Horaires De Ligne\n");
    printf("                           [2] Horaires a L'arret\n");
    printf("                             [3] Prochains Passages\n");
    printf("                               [4] Quitter\n\n");
    printf("               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n\n");
    printf("                        Veuillez choisir votre choix :");
}
////////////////
int main()
{
    char c;
    fichierversliste();
    fichierverslistestat();
    
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
                horaires_ligne();
                break;
            }
            case '2':
            {
                horaire_arret(); 
                break;
            }
            case '3':
            {
               prochaine_passage();
                break;
            }
            case '4':
            {
                exit(0);
                break;
            }
        }
        printf("\n\nAppuyer sur ENTRER pour retourner au menu principal ...");
        getchar();
        system("cls");
    }
    return 0;
}
