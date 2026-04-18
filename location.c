#include <stdio.h>
#include <string.h>

typedef struct {
    char matricule[20];
    char marque[50];
    float prixJour;
    int etat; 
} Voiture;

int saisirVoitures(Voiture v[]);
void afficherTout(Voiture v[], int n);
void louerVoiture(Voiture v[], int n);
void afficherDisponibles(Voiture v[], int n);

int main() {
    Voiture v[100]; 
    int n;             
   
    n = saisirVoitures(v);

    printf("\n--- ETAT INITIAL DU VOITURES ---\n");
    afficherTout(v, n);

    printf("\n--- LOCATION D'UNE VOITURE ---\n");
    louerVoiture(v, n);

    printf("\n--- ETAT APRES LOCATION ---\n");
    afficherTout(v, n);

    printf("\n--- LISTE DES VOITURES DISPONIBLES ---\n");
    afficherDisponibles(v, n);

    return 0;
}

int saisirVoitures(Voiture v[]) {
    int nombre;
    printf("Donner le nombre de voitures a ajouter: ");
    scanf("%d", &nombre);
    for(int i = 0; i < nombre; i++) {
        printf("Voiture %d:\n", i + 1);
        printf("  Matricule : ");
        scanf("%s", v[i].matricule);
        printf("  Marque : ");
        scanf("%s", v[i].marque);
        printf("  Prix par jour : ");
        scanf("%f", &v[i].prixJour);
        
        v[i].etat = 1; 
    }
    return nombre;
}

void afficherTout(Voiture v[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Matricule: %s | Marque: %s | Prix: %.2f | Etat: ", 
               v[i].matricule, v[i].marque, v[i].prixJour);
        if(v[i].etat == 1) {
            printf("DISPONIBLE\n");
        } else {
            printf("LOUEE\n");
        }
    }
}

void louerVoiture(Voiture v[], int n) {
    char mat_cherche[20];
    int trouve = 0;
    printf("Entrez le matricule de la voiture a louer : ");
    scanf("%s", mat_cherche);

    for(int i = 0; i < n; i++) {
        if(strcmp(v[i].matricule, mat_cherche) == 0) {
            trouve = 1;
            
            if(v[i].etat == 1) {
                v[i].etat = 0;
                printf("--> Succes : La voiture %s est maintenant LOUEE.\n", v[i].marque);
            } else {
                printf("--> Erreur : Cette voiture est deja louee !\n");
            }
        }
    }
    if(trouve == 0) printf("--> Erreur : Matricule introuvable.\n");
}

void afficherDisponibles(Voiture v[], int n) {
    int disponible = 0;
    for(int i = 0; i < n; i++) {
        if(v[i].etat == 1) {
            printf("- %s (%s) : %.2f DH\n", v[i].marque, v[i].matricule, v[i].prixJour);
            disponible++;
        }
    }
    if(disponible == 0) printf("Aucune voiture disponible.\n");
}