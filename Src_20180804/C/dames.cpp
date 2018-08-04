// dames.c

# include <iostream>
# include "dames.h"
# include "plateau.h"

using namespace spc_plateau ;

int main (int argc, char** argv)
{
    int retCode = 0;

    Joueur joueur1(couleur_pion::blanc, nature_joueur::ia) ;
    Joueur joueur2(couleur_pion::noir, nature_joueur::humain) ;
    /*
    */
    Plateau plateau(joueur1, joueur2) ;
    retCode = plateau.jouer();

    return retCode ;
}
