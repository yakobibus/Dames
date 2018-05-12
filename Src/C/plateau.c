// plateau.c

# include <iostream>
# include <iomanip>
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
        if(_estLibre)
        {
            std::cout << _couleur ;
        }
        else
        {
            _pion->affiche() ;
        }
        std::cout << _separateur ;
    }
}


namespace spc_plateau
{
    Diagonale::Diagonale() : _taille(0), _cases(nullptr) {}

    Diagonale::~Diagonale()
    {
        if(_taille == 0)
        {
            delete _cases ;
            _taille = 0 ;
            _cases = nullptr ;
        }
    }

    Diagonale::Diagonale(const Diagonale& d)
    {
        if(this != &d)
        {
            if( _taille > 0)
            {
                delete _cases ;
                _taille = 0 ;
                _cases = nullptr ;
            }

            if(d._taille > 0)
            {
                _taille = d._taille ;
                _cases = new CasePlateau* [_taille] ;
                for(int i = 0 ; i < _taille ; ++i)
                {
                    _cases[i] = d._cases[i] ;
                }
            }
        }
    }

    Diagonale& Diagonale::operator = (const Diagonale& d) 
    {
        if(this != &d)
        {
            if( _taille > 0)
            {
                delete _cases ;
                _taille = 0 ;
                _cases = nullptr ;
            }

            if(d._taille > 0)
            {
                _taille = d._taille ;
                _cases = new CasePlateau* [_taille] ;
                for(int i = 0 ; i < _taille ; ++i)
                {
                    _cases[i] = d._cases[i] ;
                }
            }
        }
        return *this;
    }

    int Diagonale::addCase(CasePlateau* c) 
    {
        Diagonale oldDiagonale = *this ;
    
        if( _taille > 0)
        {
            delete _cases ;
            _taille = 0 ;
            _cases = nullptr ;
        }

        _taille = 1 + oldDiagonale._taille ;
        _cases = new CasePlateau* [_taille] ;
        for(int i = 0 ; i < oldDiagonale._taille ; ++i)
        {
            _cases[i] = oldDiagonale._cases[i] ;
        }
        _cases[-1 + _taille] = c ;
        
        return _taille ;
    }
}

namespace spc_plateau
{
    Joueur::Joueur(couleur_pion couleur, nature_joueur nature) : _couleur(couleur), _nature(nature)
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
        if(_joueur1.getCouleur() != _joueur2.getCouleur()) // Les deux joueurs ne peuvent pas avoir la même couleur
        {
            _prochain = (_joueur1.getCouleur() == couleur_pion::blanc ? &_joueur1 : &_joueur2) ;
        }

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
        std::system("clear") ;
        afficheTitre() ;

        ligneLettres();

        int oldY = -1 ;

        for(int i = 1 ; i <= 50 ; ++i)
        {
            
            if(oldY != _cases[i].getY())
            {
                if(oldY > 0)
                {
                    std::cout << " " << oldY ;
                }
                std::cout << std::endl ;
                ligne();
                oldY = _cases[i].getY() ;
                std::cout << std::setw(4) << oldY << std::setw(2) << _cases[0].getSeparateur() ;
            }

            if(0 == (_cases[i].getY() % 2)) // ligne paire : case blancehe en premier
            {
                _cases[0].affiche() ;
                _cases[i].affiche() ;
            }
            else  // ligne impaire : case noire en premier
            {
                _cases[i].affiche() ;
                _cases[0].affiche() ;
            }
        }
        std::cout << " " << oldY ;
        std::cout << std::endl ;
        ligne() ;
        ligneLettres();
        std::cout << std::endl << std::endl ;

        affichePiedDePage() ;
    }

    std::ostream& operator << (std::ostream& os, const Joueur& j)
    {
        os << std::setw(6) << std::left << (j._couleur == couleur_pion::blanc ? "Blancs" : "Noirs") << " (" << (j._nature == nature_joueur::ia ? "ia" : "humain") << ")" ;
        return os;
    }

    void Plateau::affichePiedDePage(void)
    {
        std::cout << _joueur1 << " " << _joueur1.getCouleur() << (_prochain == &_joueur1 ? " <<==next player==" : "") << std::endl << " vs " << std::endl ;
        std::cout << _joueur2 << " " << _joueur2.getCouleur() <<  std::endl ;
    }

    void Plateau::afficheTitre(void)
    {
        int sz = strlen(titre) ; 
        std::cout << "\n\n" << std::setw(3 + sz) << titre << std::endl ; 
        char* trait = new char[1 + sz] ;
        memset(trait, 0, 1 + sz ) ;
        for(int i = 0 ; i < sz ; ++i)
        {
            trait [i] = '-' ;
        }
        std::cout << std::setw(3 + sz) << trait << std::endl << std::endl ; 
        delete [] trait ;
    }
}
