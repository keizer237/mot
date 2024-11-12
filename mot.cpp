#include <stdio.h>

// Fonction qui recherche la première occurrence d'un mot dans une phrase
// Retourne un pointeur vers le début du mot dans la phrase si trouvé, sinon retourne NULL
char* cherche_mot(const char *phrase, const char *mot) {
    // Pointeurs temporaires pour parcourir la phrase et le mot
    const char *p, *m;
    
    // Boucle à travers chaque caractère de la phrase
    while (*phrase != '\0') {
        // Si le caractère courant correspond au premier caractère du mot
        if (*phrase == *mot) {
            // Sauvegarder les positions actuelles pour comparaison
            p = phrase;
            m = mot;
            
            // Vérifier si les caractères suivants correspondent au mot
            while (*m != '\0' && *p == *m) {
                p++;
                m++;
            }
            
            // Si la fin du mot est atteinte, le mot a été trouvé dans la phrase
            if (*m == '\0') {
                return (char*)phrase;
            }
        }
        // Passer au caractère suivant dans la phrase
        phrase++;
    }
    
    // Retourne Null si aucune occurence n'est trouve
    return NULL;
}

int main() {
    const char *phrase = "maman va au marche chaque samedi matin.";
    const char *mot = "phrase";
    
    // Appel de la fonction de recherche
    char *resultat = cherche_mot(phrase, mot);
    
    // Affichage du résultat
    if (resultat != NULL) {
        printf("Mot trouvé : %s\n", resultat);
    } else {
        printf("Mot non trouvé.\n");
    }
    
    return 0;
}

