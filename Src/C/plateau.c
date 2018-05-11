// plateau.c

# include <iostream>
//# include <cstring>
# include "plateau.h"

namespace spc_plateau
{
    std::ostream& operator << (std::ostream& os, const couleur_pion& cp)
    {
        switch(cp)
        {
            case couleur_pion::blanc : os << "/o/" ; break ;
            case couleur_pion::noir  : os << "/x/" ; break ;
            default : os << "~~~" ; break ;
        }
        return os ;
    }

    std::ostream& operator << (std::ostream& os, const couleur_case& cc)
    {
        switch(cc)
        {
            case couleur_case::blanc : os << "   " ; break ;
            case couleur_case::noir  : os << "///" ; break ;
            default : os << "..." ; break ;
        }
        return os ;
    }
}

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
        _motif[0] = ' ';
        _motif[1] = _couleur == couleur_case::blanc ? ' ' : '-' ;
        _motif[2] = ' ';
        _motif[3] = '\0';
        _motifSurbrillance[0] = ' ';
        _motifSurbrillance[1] = _couleur == couleur_case::blanc ? ' ' : '=' ;
        _motifSurbrillance[2] = ' ';
        _motifSurbrillance[3] = '\0';
        ;
    }

    void CasePlateau::init( int x
                          , int y
                          , int notation
                          , Pion* pion = nullptr
                          , apparence_case apparence = apparence_case::normal
                          , couleur_case couleur = couleur_case::noir
                          )
    {
        _y = y ;
        _x = x ;
        _notationOfficielle = notation ;
        _pion = pion ;
        _apparence = apparence ;
        _estLibre = pion == nullptr ? true : false ;
        _couleur = couleur ; 
        _motif[1] = _couleur == couleur_case::blanc ? ' ' : '-' ;
        _motifSurbrillance[1] = _couleur == couleur_case::blanc ? ' ' : '=' ;
    }
    
    void CasePlateau::setPion(Pion* pion) 
    {
        _pion = pion ;
    }

    void CasePlateau::affiche(void)
    {
//std::cout << "("<< _y <<","<< _x <<")<"<<_motif<<"><"<<(_estLibre ? ":::" : _pion->getMotif())<<">{"<<(_estLibre ? ' ' : '!')<<"} " ;
        if(_estLibre)
        {
            std::cout << _couleur ;
        }
        else
        {
            _pion->affiche() ;
        }
        //std::cout << (_estLibre ? _motif : _pion->getMotif()) /*<< "<" << "_pion" <<">"*/ ;
        //std::cout << couleur_pion::blanc ;
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
        _motif[0] = ' ' ;
        _motif[1] = _couleur == couleur_pion::blanc ? 'o' : 'x' ;
        _motif[2] = ' ' ;
        _motif[3] = '\0' ;
        _motifSurbrillance[0] = ' ' ;
        _motifSurbrillance[1] = _couleur == couleur_pion::blanc ? 'O' : 'X' ;
        _motifSurbrillance[2] = ' ' ;
        _motifSurbrillance[3] = '\0' ;
    }

    /*
    char* Pion::getMotif(void)
    {
        return _motif ;
    }
    */

    void Pion::setCouleur(couleur_pion couleur)
    {
        _couleur = couleur ;
        _motif[1] = ( _couleur == couleur_pion::blanc ? 'o' : 'x' ) ;
        _motifSurbrillance[1] = ( _couleur == couleur_pion::blanc ? 'O' : 'X' ) ;
    }
}

namespace spc_plateau
{
    Plateau::Plateau(Joueur joueur1, Joueur joueur2) : _nombreDeCoups(0), _joueur1(joueur1), _joueur2(joueur2), _prochain(nullptr)
    {
        int iCase = 0 ; // Les pions noirs dans les cases 1 à 20 et les blancs de 31 à 50

        _cases[iCase].init(0, 0, 0, nullptr, apparence_case::normal, couleur_case::blanc) ;

        for(int y = 10 ; y > 0 ; --y)       // ligne
        {
            for(int x = 1 ; x <= 10 ; ++x)  // colonne
            {
                if( 0 == (y % 2) )  // lignes paires  => colonnes paires uniquement
                {
                    if( 0 == (x % 2) )
                    {
                        ++iCase ;
                        _cases[iCase].init( x
                                          , y
                                          , iCase
                                          , (iCase >= 1 && iCase <= 20) ? &(_pionsBlancs [-1 + iCase]) 
                                                                        : ((iCase >= 31 && iCase <= 50) ? &(_pionsNoirs [-1 + iCase]) 
                                                                        : nullptr)
                                          , apparence_case::normal
                                          , couleur_case::noir
                                          ) ;
                    }
                }
                else  // lignes impaires => colonnes impaires
                {
                    if( 0 != (x % 2) )
                    {
                        ++iCase ;
                        _cases[iCase].init( x
                                          , y
                                          , iCase
                                          , (iCase >= 1 && iCase <= 20) ? &(_pionsBlancs [-1 + iCase]) 
                                                                        : ((iCase >= 31 && iCase <= 50) ? &(_pionsNoirs [-1 + iCase]) 
                                                                        : nullptr)
                                          , apparence_case::normal
                                          , couleur_case::noir
                                          ) ;
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
        int oldY = -1 ;
        //ligne();
        for(int i = 1 ; i <= 50 ; ++i)
        {
            
            if(oldY != _cases[i].getY())
            {
                std::cout << std::endl ;
                ligne();
                std::cout << "|" ;
                oldY = _cases[i].getY() ;
            }

            if(0 == (_cases[i].getY() % 2)) // ligne paire : case blancehe en premier
            {
                _cases[0].affiche() ;
                std::cout << "|" ;
                _cases[i].affiche() ;
                std::cout << "|" ;
            }
            else  // ligne impaire : case noire en premier
            {
                _cases[i].affiche() ;
                std::cout << "|" ;
                _cases[0].affiche() ;
                std::cout << "|" ;
            }
        }
        std::cout << std::endl ;
        ligne() ;
    }
}
