
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graphemat.h"
#include "liregraphe.h"
#include "liste.h"

typedef GrapheMat Graphe;

int menu () {

  printf ("\n\nINTELLIGENCE ARTIFICIELLE : Exploration\n\n");

  printf ("0 - Fin du programme\n");
  printf ("1 - Creation a partir d'un fichier\n");
  printf ("\n");
  printf ("2 - Initialisation d'un graphe vide\n");
  printf ("3 - Ajout d'un sommet\n");
  printf ("4 - Ajout d'un arc\n");
  printf ("\n");
  printf ("5 - Liste des sommets et des arcs\n");
  printf ("6 - Destruction du graphe\n");
  printf ("7 - Parcours en profondeur d'un graphe\n");
  printf ("\n");
  printf ("8  - Floyd \n");
  printf ("9 - Parcours en largeur d'un graphe\n");
 // printf ("10 - Parcours en largeur 1 d'un graphe\n");
  printf ("\n");
  printf ("Votre choix ? ");
  int cod; scanf ("%d", &cod); getchar();
  printf ("\n");
  return cod;
}
int main () {
  Graphe* graphe;
  booleen fini = faux;
  while (!fini) {
    switch ( menu() ) {
    case 0:
      fini = vrai;
      break;
    case 1: {  // cr�ation � partir d'un fichier
      printf ("Nom du fichier contenant le graphe ? ");
      char nomFe [50];
      scanf  ("%s", nomFe);
      //strcpy (nomFe, "graphe.txt");
      FILE* fe = fopen (nomFe, "r");
      if (fe == NULL) {
        perror (nomFe);
      } else {
        graphe = lireGraphe (fe, 20); // 20 sommets maximum
        fclose (fe);
      }
      } break;
   case 2: {             // cr�ation d�un graphe vide
      printf ("Nombre maximum de sommets ? ");
      int nMaxSom; scanf  ("%d", &nMaxSom);
      printf ("0) non value; 1) graphe value ? ");
      int value; scanf ("%d", &value);

      graphe = creerGrapheMat (nMaxSom, value);

    } break;
    case 3: {  // ajouter un sommet
      printf ("Nom du sommet a inserer ? ");
      NomSom somD; scanf  ("%s", somD);
      ajouterUnSommet (graphe, somD);
    } break;
    case 4: {  // ajouter un arc
      printf ("Nom du sommet de depart ? ");
      NomSom somD; scanf  ("%s", somD);
      printf ("Nom du sommet d'arrivee ? ");
      NomSom somA; scanf  ("%s", somA);
      int cout;
      if (graphe->value) {
        printf ("Cout de la relation ? ");
        scanf ("%d", &cout);
      } else {
        cout = 0;
      }
      ajouterUnArc (graphe, somD, somA, cout);
    } break;
    case 5:
      ecrireGraphe (graphe);
      break;
    case 6:
      detruireGraphe (graphe);
      break;
    case 7:
      parcoursProfond (graphe);
      break;
    case 8:
     if (graphe->value) {
        printf ("\nLes plus courts chemins\n\n");
          floyd (graphe);
      } else {
        printf ("Graphe non value\n");
      }
      break;
    case 9:
      parcoursLargeur(graphe);
      break;
    /*case 10:
      parcoursLargeur1(graphe);
      break;*/
            
    }   // switch
    if (!fini) {
      printf ("\n\nTaper Return pour continuer\n");
      getchar();
    }
  }

return 0;
}
