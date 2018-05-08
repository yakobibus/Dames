// plateau.c
# include "plateau.h"

namespace spc_plateau
{
    //CasePlateau::CasePlateau(int notation, bool libre = true) : _notationOfficielle(notation), _estLibre(libre)
    CasePlateau::CasePlateau()
    {
        _estLibre = true ;
        _notationOfficielle = 0 ; // case blanche
        _x = 0 ;
        _y = 0 ;
        _couleur = couleur_case::blanc ;
        _pion = nullptr ;  // libre de tout pion
        _apparence = apparence_case::normal ;
        ;
    }

    Plateau::Plateau(Joueur joueur1, Joueur joueur2) : _nombreDeCoups(0), _joueur1(joueur1), _joueur2(joueur2), _prochain(nullptr)
    {
        for(int i = 0 ; i < 51 ; ++i)
        {
            // Todo : initialiser les cases du plateau : ideal, par defaut une noire sauf précision ou set
        }
    }
}
