// dames.c

# include <iostream>
# include "dames.h"
# include "plateau.h"

using namespace spc_plateau ;

int main (int argc, char** argv)
{
    int retCode = 0;

    Joueur joueur1;
    Joueur joueur2;
    /*
    */
    Plateau plateau(joueur1, joueur2) ;
    plateau.affiche();

    return retCode ;
}
