//////////////les structures
typedef struct LIGNE {
        char num[10];
        float distance;
        int freq_moyenne;
        char depart[10];
        char arrive[10];
        char stationdepart[50];
        char stationarrive[50];
        }ligne;
////////////////////        
typedef struct Bus {
        int numero;
        char marque[50];
        char lg[10];
        char date_achat[20];
        int nb_passagers;
        }bus;
//////////////////
typedef struct Station {
        char nom[50];
        int code1; //numero de sens aller/retour au station
        char adress[100];
        }station;
//////////////////
typedef struct listebus{
        bus b;
        struct listebus *suiv;
        }liste1;
///////////////////
typedef struct listeligne{
        ligne l;
        struct listeligne *suiv;
        }liste2;
///////////////////
typedef struct listestation{
        station s;
        struct listestation *suiv;
        }liste3;
///////////////////
