//////////////les structures
typedef struct horloge{
        int minute;
        int heure;
        }heures;
///////////////////
typedef struct bus {
        int numero;
        char lg[10];
        char times_al[20]; // les horaires  de  la disponibilité de bus au station à l'aller
        char times_re[20]; // les horaires de la disponibilité de bus au station au retour
        }bus;
///////////////////
typedef struct station {
        char nom[40];
        bus b;
        }station;
////////////////////
typedef struct LIGNE {
        char num[10];
        float distance;
        int freq_moyenne;
        heures depart;
        heures arrive;
        char firststat[50];
        char laststat[50];
        char statdep[1000];
        char statarriv[1000];
        }ligne;
///////////////////
typedef struct listeligne{
        ligne l;
        struct listeligne *suiv;
        }liste;
///////////////////
typedef struct listebus{
        station s;
        struct listebus *suiv;
        }liste_s;
