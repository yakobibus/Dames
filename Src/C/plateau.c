// plateau.c
//# include <cstring>
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

    void CasePlateau::init( int x
                          , int y
                          , int notation
                          , Pion* pion = nullptr
                          , apparence_case apparence = apparence_case::normal
                          , bool libre = true
                          , couleur_case couleur = couleur_case::noir
                          )
    {}
    
    void CasePlateau::setPion(Pion* pion) 
    {
        _pion = pion ;
    }
}

namespace spc_plateau
{
    Joueur::Joueur() : _couleur(couleur_pion::blanc), _nature(nature_joueur::ia)
    {}
}

namespace spc_plateau
{
    Pion::Pion(couleur_pion couleur = couleur_pion::blanc) : _couleur(couleur)
                                                           , _promotion(promotion_pion::normal)
                                                           , _apparence(apparence_pion::normal)
    {
        //memset(_motif, 0, 4);
        _motif[0] = ' ';
        _motif[1] = _couleur == couleur_pion::blanc ? 'o' : 'x' ;
        _motif[2] = ' ';
        _motif[3] = '\0';
    }

    void Pion::setCouleur(couleur_pion couleur)
    {
        _couleur = couleur ;
    }
}

namespace spc_plateau
{
    Plateau::Plateau(Joueur joueur1, Joueur joueur2) : _nombreDeCoups(0), _joueur1(joueur1), _joueur2(joueur2), _prochain(nullptr)
    {
        int iCase = 0 ; // Les pions noirs dans les cases 1 à 20 et les blancs de 31 à 50

        _cases[iCase].init(0, 0, 0, nullptr, apparence_case::normal, true, couleur_case::blanc) ;

        for(int y = 10 ; y > 0 ; --y)       // ligne
        {
            for(int x = 1 ; x <= 10 ; ++x)  // colonne
            {
                if( 0 == (y % 2) )  // lignes paires  => colonnes paires uniquement
                {
                    if( 0 == (x % 2) )
                    {
                        _cases[++iCase].init(x, y, iCase, nullptr, apparence_case::normal, true, couleur_case::noir) ;
                    }
                }
                else  // lignes impaires => colonnes impaires
                {
                    if( 0 != (x % 2) )
                    {
                        _cases[++iCase].init(x, y, iCase, nullptr, apparence_case::normal, true, couleur_case::noir) ;
                    }
                }

                if(( 0 == (y % 2) && 0 == (x % 2) ) || ( 0 != (y % 2) && 0 != (x % 2)) )
                {
                    if(iCase >= 1 && iCase <= 20)
                    {
                        _pionsBlancs [-1 + iCase].setCouleur(couleur_pion::blanc) ;
                        _cases[iCase].setPion(&(_pionsBlancs[-1 + iCase])) ;
                    }
                    else
                    {
                        if(iCase >= 31 && iCase <= 50)
                        {
                            _pionsNoirs [-1 + iCase].setCouleur(couleur_pion::noir) ;
                            _cases[iCase].setPion(&(_pionsNoirs[-1 + iCase])) ;
                        }
                    }
                }
            }
        }
    }

    void Plateau::affiche(void)
    {
        for(int i = 0 ; i < 51 ; ++i)
        {
            ; // Afficher la case
        }
    }
}
