// plateau.c

# include <iostream>
# include <string>
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

    int Diagonale::init(int taille, CasePlateau** c)
    {
        if( _taille > 0)
        {
            delete _cases ;
            _taille = 0 ;
            _cases = nullptr ;
        }

        _taille = taille ;
        _cases = new CasePlateau*[_taille] ;
        for(int i = 0 ; i < _taille ; ++i)
        {
            _cases[i] = c[i];
//std::cout << "<" << _cases[i]->getNotation() << "> " ;
        }
//std::cout << std::endl ;

        return _taille ;
    }
}

namespace spc_plateau
{
    void Input::InputCase(CasePlateau& casePlateau, input_token& token)
    {
        std::cout << "Input :: " ;
        std::cin.getline(_buffer, BUFFER_MX_SIZE) ;
std::cout << "Sz saisie==[" << strlen(_buffer) << "]\n" ;
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
                                          , (iCase >= 1 && iCase <= NB_PIONS_PAR_COULEUR) ? &(_pionsBlancs [-1 + iCase]) 
                                                                        : ((iCase >= 31 && iCase < NB_CASES_PLATEAU) ? &(_pionsNoirs [-1 + iCase]) 
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
                                          , (iCase >= 1 && iCase <= NB_PIONS_PAR_COULEUR) ? &(_pionsBlancs [-1 + iCase]) 
                                                                        : ((iCase >= 31 && iCase < NB_CASES_PLATEAU) ? &(_pionsNoirs [-1 + iCase]) 
                                                                        : nullptr)
                                          , apparence_case::normal
                                          , couleur_case::noir
                                          ) ;
                    }
                }

                if(( 0 == (y % 2) && 0 == (x % 2) ) || ( 0 != (y % 2) && 0 != (x % 2)) )
                {
                    if(iCase >= 1 && iCase <= NB_PIONS_PAR_COULEUR)
                    {
                        _pionsBlancs [-1 + iCase].setCouleur(couleur_pion::blanc) ;
                        _cases[iCase].setPion(&(_pionsBlancs[-1 + iCase])) ;
                    }
                    else
                    {
                        if(iCase >= 31 && iCase < NB_CASES_PLATEAU)
                        {
                            _pionsNoirs [-1 + iCase].setCouleur(couleur_pion::noir) ;
                            _cases[iCase].setPion(&(_pionsNoirs[-1 + iCase])) ;
                        }
                    }
                }
            }
        }

        initDiagonales() ;
    }

    void Plateau::initDiagonales(void)
    {
        CasePlateau* dummy[100] = 
        {
            // Paires
              &_cases[1], &_cases[6]
            , &_cases[2], &_cases[7], &_cases[11], &_cases[16]
            , &_cases[3], &_cases[8], &_cases[12], &_cases[17], &_cases[21], &_cases[26]
            , &_cases[4], &_cases[9], &_cases[13], &_cases[18], &_cases[22], &_cases[27], &_cases[31], &_cases[36]
            , &_cases[5], &_cases[10], &_cases[14], &_cases[19], &_cases[23], &_cases[28], &_cases[32], &_cases[37], &_cases[41], &_cases[46]
            , &_cases[15], &_cases[20], &_cases[24], &_cases[29], &_cases[33], &_cases[38], &_cases[42], &_cases[47]
            , &_cases[25], &_cases[30], &_cases[34], &_cases[39], &_cases[43], &_cases[48]
            , &_cases[35], &_cases[40], &_cases[44], &_cases[49]
            , &_cases[45], &_cases[50]
            // Impaires
            , &_cases[46]
            , &_cases[36], &_cases[41], &_cases[47]
            , &_cases[26], &_cases[31], &_cases[37], &_cases[42], &_cases[48]
            , &_cases[16], &_cases[21], &_cases[27], &_cases[32], &_cases[38], &_cases[43], &_cases[49]
            , &_cases[6], &_cases[11], &_cases[17], &_cases[22], &_cases[28], &_cases[33], &_cases[39], &_cases[44], &_cases[50]
            , &_cases[1], &_cases[7], &_cases[12], &_cases[18], &_cases[23], &_cases[29], &_cases[34], &_cases[40], &_cases[45]
            , &_cases[2], &_cases[8], &_cases[13], &_cases[19], &_cases[24], &_cases[30], &_cases[35]
            , &_cases[3], &_cases[9], &_cases[14], &_cases[20], &_cases[25]
            , &_cases[4], &_cases[10], &_cases[15]
            , &_cases[5]
        } ;
        _diagonales[0].init(2, &dummy[0]) ;
        _diagonales[1].init(4, &dummy[2]) ;
        _diagonales[2].init(6, &dummy[6]) ;
        _diagonales[3].init(8, &dummy[12]) ;
        _diagonales[4].init(10, &dummy[20]) ;
        _diagonales[5].init(8, &dummy[30]) ;
        _diagonales[6].init(6, &dummy[38]) ;
        _diagonales[7].init(4, &dummy[44]) ;
        _diagonales[8].init(2, &dummy[48]) ;
        _diagonales[9].init(1, &dummy[50]) ;
        _diagonales[10].init(3, &dummy[51]) ;
        _diagonales[11].init(5, &dummy[54]) ;
        _diagonales[12].init(7, &dummy[59]) ;
        _diagonales[13].init(9, &dummy[66]) ;
        _diagonales[14].init(9, &dummy[75]) ;
        _diagonales[15].init(7, &dummy[84]) ;
        _diagonales[16].init(5, &dummy[91]) ;
        _diagonales[17].init(3, &dummy[96]) ;
        _diagonales[18].init(1, &dummy[99]) ;
    }

    void Plateau::oldInitDiagonales(void)
    {
        // Paires
        {
            CasePlateau* cp[2] = {&_cases[1], &_cases[6]} ;
            _diagonales[0].init(2, cp) ;
        }
        {
            CasePlateau* cp[4] = {&_cases[2], &_cases[7], &_cases[11], &_cases[16]} ;
            _diagonales[1].init(4, cp) ;
        }
        {
            CasePlateau* cp[6] = {&_cases[3], &_cases[8], &_cases[12], &_cases[17], &_cases[21], &_cases[26]} ;
            _diagonales[2].init(6, cp) ;
        }
        {
            CasePlateau* cp[8] = {&_cases[4], &_cases[9], &_cases[13], &_cases[18], &_cases[22], &_cases[27], &_cases[31], &_cases[36]} ;
            _diagonales[3].init(8, cp) ;
        }
        {
            CasePlateau* cp[10] = {&_cases[5], &_cases[10], &_cases[14], &_cases[19], &_cases[23], &_cases[28], &_cases[32], &_cases[37], &_cases[41], &_cases[46]} ;
            _diagonales[4].init(10, cp) ;
        }
        {
            CasePlateau* cp[8] = {&_cases[15], &_cases[20], &_cases[24], &_cases[29], &_cases[33], &_cases[38], &_cases[42], &_cases[47]} ;
            _diagonales[5].init(8, cp) ;
        }
        {
            CasePlateau* cp[6] = {&_cases[25], &_cases[30], &_cases[34], &_cases[39], &_cases[43], &_cases[48]} ;
            _diagonales[6].init(6, cp) ;
        }
        {
            CasePlateau* cp[4] = {&_cases[35], &_cases[40], &_cases[44], &_cases[49]} ;
            _diagonales[7].init(4, cp) ;
        }
        {
            CasePlateau* cp[2] = {&_cases[45], &_cases[50]} ;
            _diagonales[8].init(2, cp) ;
        }
        // Impaires
        {
            CasePlateau* cp[1] = {&_cases[46]} ;
            _diagonales[18].init(1, cp) ;
        }
        {
            CasePlateau* cp[3] = {&_cases[36], &_cases[41], &_cases[47]} ;
            _diagonales[9].init(3, cp) ;
        }
        {
            CasePlateau* cp[5] = {&_cases[26], &_cases[31], &_cases[37], &_cases[42], &_cases[48]} ;
            _diagonales[10].init(5, cp) ;
        }
        {
            CasePlateau* cp[7] = {&_cases[16], &_cases[21], &_cases[27], &_cases[32], &_cases[38], &_cases[43], &_cases[49]} ;
            _diagonales[11].init(7, cp) ;
        }
        {
            CasePlateau* cp[9] = {&_cases[6], &_cases[11], &_cases[17], &_cases[22], &_cases[28], &_cases[33], &_cases[39], &_cases[44], &_cases[50]} ;
            _diagonales[12].init(9, cp) ;
        }
        {
            CasePlateau* cp[9] = {&_cases[1], &_cases[7], &_cases[12], &_cases[18], &_cases[23], &_cases[29], &_cases[34], &_cases[40], &_cases[45]} ;
            _diagonales[13].init(9, cp) ;
        }
        {
            CasePlateau* cp[7] = {&_cases[2], &_cases[8], &_cases[13], &_cases[19], &_cases[24], &_cases[30], &_cases[35]} ;
            _diagonales[14].init(7, cp) ;
        }
        {
            CasePlateau* cp[5] = {&_cases[3], &_cases[9], &_cases[14], &_cases[20], &_cases[25]} ;
            _diagonales[15].init(5, cp) ;
        }
        {
            CasePlateau* cp[3] = {&_cases[4], &_cases[10], &_cases[15]} ;
            _diagonales[16].init(3, cp) ;
        }
        {
            CasePlateau* cp[1] = {&_cases[5]} ;
            _diagonales[17].init(1, cp) ;
        }
    }

    void Plateau::affiche(void)
    {
        std::system("clear") ;
        afficheTitre() ;

        ligneLettres();

        int oldY = -1 ;

        for(int i = 1 ; i < NB_CASES_PLATEAU ; ++i)
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
                std::cout << std::right << std::setw(4) << oldY << std::setw(2) << _cases[0].getSeparateur() ;
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

    int Plateau::jouer(void)
    {
        int retCode = 0 ;
        std::string errorMsg = "" ;

        Coup coup ;

        while(! _finDePartie)
        {
            affiche() ;

Input iii ;
CasePlateau cp ;
input_token t ;
iii.InputCase(cp, t) ;
            std::cout << errorMsg ;
            std::cout << std::endl ;
            std::cout << "\n  ==>> La main est aux " << _prochain->getCouleur() << "   Q pour abandonner"<< std::endl ;
            std::cout << "\n       Depart : " ;
            if ( ! setCoup(errorMsg) )
            {
                continue ;
            }
        }

        return retCode ;
    }

    int Plateau::getNotationCase(const int& y, const int& x)
    {
        int retValue = 0 ;

        for(int i = 1 ; i < NB_CASES_PLATEAU ; ++i)
        {
            retValue = _cases[i].getNotation( y, x ) ;
            if(retValue != 0)
            {
                break ;
            }
        }

        return retValue ;
    }

    bool Plateau::setCoup(std::string& message)
    {
        bool retCode = true ;
        int y = 0 ;
        int x = 0 ;

        message = "" ;
        std::string saisie ;
        getline(std::cin, saisie) ;

        if(saisie == "Q" || saisie == "q" || saisie == "X" || saisie == "x")
        {
            _finDePartie = true ;
            message = "Partie abandonnée ... " ;
        }
        else 
        {
            std::string sLigne = "" ;

            char colonne = saisie.c_str()[0] ;
            x = ( colonne == 'a' || colonne == 'A' ? 1 
                : colonne == 'b' || colonne == 'B' ? 2 
                : colonne == 'c' || colonne == 'C' ? 3
                : colonne == 'd' || colonne == 'D' ? 4
                : colonne == 'e' || colonne == 'E' ? 5
                : colonne == 'f' || colonne == 'F' ? 6
                : colonne == 'g' || colonne == 'G' ? 7
                : colonne == 'h' || colonne == 'H' ? 8
                : colonne == 'i' || colonne == 'I' ? 9
                : colonne == 'j' || colonne == 'J' ? 10
                : 0
                ) ;
            sLigne = saisie.c_str()[1] ;
            try
            {
                y = std::stoi(sLigne) ;
            }
            catch (std::invalid_argument& e)
            {
                message = "Invalid position (" + saisie + ")" ;
                retCode = false ;
            }

            if(retCode && ( x < 1 || x > 10 || y < 0 || y > 10))
            {
                retCode = false ;
                message = "Invalid position (" + saisie + ")" ;
            }
            else
            {
                int caseDepart = getNotationCase(y, x) ;
                std::cout << "Case de départ (" << caseDepart << ")\n" ;
            }
            //
            if(! retCode) // Mauvaise saisie, essayer de réévaluer ligne/Colonne
            {
                char zz[5] ;
                memset(zz, 0, 5) ;
                memcpy(zz, &(saisie.c_str()[0]), (saisie.length() == 3 ? 2 : 1)) ;
                try
                {
                    y = std::stoi(zz) ;
                    retCode = true ;
                }
                catch(std::invalid_argument& e)
                {
                    //message = "Invalid position (" + saisie + ")" ;
                    retCode = false ;
                }

                if(retCode)
                {
                    colonne = saisie.c_str()[(saisie.length() == 3 ? 2 : 1)];
                    x = ( colonne == 'a' || colonne == 'A' ? 1 
                        : colonne == 'b' || colonne == 'B' ? 2 
                        : colonne == 'c' || colonne == 'C' ? 3
                        : colonne == 'd' || colonne == 'D' ? 4
                        : colonne == 'e' || colonne == 'E' ? 5
                        : colonne == 'f' || colonne == 'F' ? 6
                        : colonne == 'g' || colonne == 'G' ? 7
                        : colonne == 'h' || colonne == 'H' ? 8
                        : colonne == 'i' || colonne == 'I' ? 9
                        : colonne == 'j' || colonne == 'J' ? 10
                        : 0
                        ) ;

                        if(retCode && ( x < 1 || x > 10 || y < 0 || y > 10))
                        {
                            retCode = false ;
                            message = "Invalid position (" + saisie + ")" ;
                        }
                        else
                        {
                            int caseDepart = getNotationCase(y, x) ;
                            message = "" ;
                            std::cout << "Case de re-départ (" << caseDepart << ")\n" ;
                        }
                }
            }
std::cout << "L("<< sLigne <<"), C(" << colonne << ") et ("<<y<<")\n" ;
        }

        return retCode ;
    }
}

namespace spc_plateau
{
}
