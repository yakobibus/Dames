// plateau.c

# include <iostream>
# include <string>
# include <cstring>
# include <iomanip>
//# include <memory>
//# include <cctype>
# include "plateau.h"

namespace spc_plateau
{
	std::ostream& operator << (std::ostream& os, const couleur_pion& cp)
	{
		switch (cp)
		{
		case couleur_pion::blanc: os << "/o/"; break;
		case couleur_pion::noir: os << "/x/"; break;
		default: os << "~~~"; break;
		}
		return os;
	}

	std::ostream& operator << (std::ostream& os, const couleur_case& cc)
	{
		switch (cc)
		{
		case couleur_case::blanc: os << "   "; break;
		case couleur_case::noir: os << "///"; break;
		default: os << "..."; break;
		}
		return os;
	}
}

namespace spc_plateau
{
    //CasePlateau::CasePlateau(int notation, bool libre = true) : _notationOfficielle(notation), _estLibre(libre)
    CasePlateau::CasePlateau()
    {
        _couleur = couleur_case::blanc ;
        _estLibre = true ;
        _pion = nullptr ;  // libre de tout pion
        _x = 0 ;
        _y = 0 ;
        _notationOfficielle = 0 ; // case blanche
        _apparence = apparence_case::normal ;
        _motif[0] = ' ' ;
        _motif[1] = _couleur == couleur_case::blanc ? ' ' : '-' ;
        _motif[2] = ' ' ;
        _motif[3] = '\0' ;
        _motifSurbrillance[0] = ' ' ;
        _motifSurbrillance[1] = _couleur == couleur_case::blanc ? ' ' : '=' ;
        _motifSurbrillance[2] = ' ' ;
        _motifSurbrillance[3] = '\0' ;
    }

    CasePlateau& CasePlateau::operator = (const CasePlateau& c)
    {
        if(this != &c)
        {
            _couleur = c._couleur ;
            _estLibre = c._estLibre ;
            _pion = c._pion ;
            _x = c._x ;
            _y = c._y ;
            _notationOfficielle = c._notationOfficielle ; 
            _apparence = c._apparence ;
            std::memcpy(_motif, c._motif, MOTIF_SIZE) ;
            std::memcpy(_motifSurbrillance, c._motifSurbrillance, MOTIF_SIZE) ;
        }

        return *this ;
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
        }

        return _taille ;
    }
}

namespace spc_plateau
{
    void Input::_scanner(int index)
    {
        _input_type[index] = (IS_DIGIT_DAMIER(_buffer[index]) ? (index == 0 ? input_type::is_digitOne : index == 1 ? input_type::is_digitTwo : index == 2 ? input_type::is_digitThree : input_type::is_undefined)
                                                      : (_isAlpha(_buffer[index]) ? (index == 0 ? input_type::is_alphaOne : index == 1 ? input_type::is_alphaTwo : index == 2 ? input_type::is_alphaThree : input_type::is_undefined)
                                                                          : input_type::is_undefined
                                                        )
                             ) ;
    }

    void Input::InputCase(Plateau& plateau, const char* invite = nullptr)
    {
        int inputLine = 0 ;
        int inputColumn = 0 ;
        int inputNotation = 0 ;

        std::cout << invite ;
        std::cin.getline(_buffer, -1 + BUFFER_MX_SIZE) ;
        _bufSize = std::strlen(_buffer) ;

        _input_type[0] = input_type::is_undefined ;
        _input_type[1] = input_type::is_undefined ;
        _input_type[2] = input_type::is_undefined ;

        _token = input_token::neutral ;

        switch(_bufSize)
        {
            case 2 :
                _scanner(0) ;
                _scanner(1) ;
                break ;
           case 3 :
                _scanner(0) ;
                _scanner(1) ;
                _scanner(2) ;
                break ;
            default :
                _token = ( _buffer[0] == 'q' 
                        || _buffer[0] == 'Q' 
                        || _buffer[0] == 'x' 
                        || _buffer[0] == 'X' 
                        ? input_token::quit 
                        : input_token::error
                         ) ;
                break ;
        }

        if(_token == input_token::neutral)
        {
            switch(static_cast<int>(_input_type[0]) | static_cast<int>(_input_type[1]) | static_cast<int>(_input_type[2]))
            {
                case IS_ALPHA_ONE | IS_DIGIT_TWO :  //AD
                    inputColumn = _aToColumn(_buffer[0]) ;
                    inputLine = std::stoi(&(_buffer[1])) ;
                    break ;
                case IS_DIGIT_ONE | IS_ALPHA_TWO :  //DA
                    inputColumn = _aToColumn(_buffer[1]) ;
                    _buffer[1] = '\0' ;
                    inputLine = std::stoi(&(_buffer[0])) ;
                    break ;
                case IS_ALPHA_ONE | IS_DIGIT_TWO | IS_DIGIT_THREE :  //ADD
                    inputColumn = _aToColumn(_buffer[0]) ;
                    inputLine = std::stoi(&(_buffer[1])) ;
                    break ;
                case IS_DIGIT_ONE | IS_DIGIT_TWO | IS_ALPHA_THREE :  //DDA
                    inputColumn = _aToColumn(_buffer[2]) ;
                    _buffer[2] = '\0' ;
                    inputLine = std::stoi(&(_buffer[0])) ;
                    break ;
                default :
                    _token = input_token::error ;
                    break ;
            }

            if(_token == input_token::neutral)
            {
                inputNotation = plateau.notationCase(inputLine, inputColumn) ;
                if(0 == inputNotation)
                {
                    _token = input_token::error ;
                }
                else
                {
                    _casePlateau = plateau.adresseCasePlateau(inputNotation) ;
                }
            }
// Movement - Regle 1 : La case de départ doit être occupée par un pion de la même couleur que le joueur
//            Règle 2 : La case destination pour un déplacement, une prise, une étape de raffle doit être libre
//            Règle 3 : Pour un déplacement (pion), la case destination doit être voisine de la case de départ en diagonale vers l'avant par rapport à la couleur en jeu
//            Règle 4 : Pour un déplacement (reine), la case destination doit être dans la diagonale et aucun pion ne doit se trouver entre les deux
        }
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
        _motif[0] = ' ' ;
        _motif[1] = (_couleur == couleur_pion::blanc ? 'o' : 'x') ;
        _motif[2] = ' ' ;
        _motif[3] = '\0' ;
        _motifSurbrillance[0] = ' ' ;
        _motifSurbrillance[1] = (_couleur == couleur_pion::blanc ? 'O' : 'X') ;
        _motifSurbrillance[2] = ' ' ;
        _motifSurbrillance[3] = '\0' ;
    }

    void Pion::setCouleur(couleur_pion couleur)
    {
        _couleur = couleur ;
        if(std::strlen(_motif) != 3)
        {
            _motif[0] = ' ' ;
            _motif[2] = ' ' ;
            _motif[3] = '\0' ;
        }

        if(std::strlen(_motifSurbrillance) != 3)
        {
            _motifSurbrillance[0] = ' ' ;
            _motifSurbrillance[2] = ' ' ;
            _motifSurbrillance[3] = '\0' ;
        }
        _motif[1] = ( _couleur == couleur_pion::blanc ? 'o' : 'x' ) ;
        _motifSurbrillance[1] = ( _couleur == couleur_pion::blanc ? 'O' : 'X' ) ;
    }
}

namespace spc_plateau
{
    Plateau::Plateau(Joueur joueur1, Joueur joueur2) : _nombreDeCoups(0), _joueur1(joueur1), _joueur2(joueur2), _prochain(nullptr)
    {
		std::memset(_errorMsg, 0, BUFFER_ERR_MX_SIZE);
		if(_joueur1.couleur() != _joueur2.couleur()) // Les deux joueurs ne peuvent pas avoir la même couleur
        {
            _prochain = (_joueur1.couleur() == couleur_pion::blanc ? &_joueur1 : &_joueur2) ;
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
                std::cout << std::right << std::setw(4) << oldY << std::setw(2) << _cases[0].separateur() ;
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
		ligneLettres() ;
		std::cout << std::endl ;
		_piedDePage.init(*this, _prochain, _coupEnCours) ;
		_piedDePage.affiche(_errorMsg) ;
    }

    std::ostream& operator << (std::ostream& os, const Joueur& j)
    {
        os << std::setw(6) << std::left << (j._couleur == couleur_pion::blanc ? "Blancs" : "Noirs") << " (" << (j._nature == nature_joueur::ia ? "ia" : "humain") << ")" ;
        return os;
    }

    void Plateau::afficheTitre(void)
    {
        int sz = std::strlen(_titre) ;
        std::cout << "\n\n" << std::setw(3 + sz) << _titre << std::endl ; 
        char* trait = new char[1 + sz] ;
        std::memset(trait, 0, 1 + sz ) ;
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

        Coup coup ;

		_coupEnCours.setEtape(etapes_du_coup::debut) ;

        while(! _finDePartie)
        {
			_coupEnCours.setEtape(etapes_du_coup::input_depart) ;
            affiche() ;

//ici todo : réaffecter l'étape en fonction des erreurs en cours ...
//ici : todo : Déterminer le joueur qui a la main puis exécuter le coup puis l'évaluer et le typer (déplacement/prise)
			//std::cout << "::" << _errorMsg << "::\n";
			std::memset(_errorMsg, 0, BUFFER_ERR_MX_SIZE) ;
            _input.InputCase(*this, _piedDePage.invite()) ;

            switch(_input.token())
            {
                case input_token::quit :
					std::memcpy(_errorMsg, "Abandon des ", -1 + BUFFER_ERR_MX_SIZE) ;
					std::strcat(_errorMsg, _prochain->laCouleur());
					std::strcat(_errorMsg, " !" );
                    std::cout << "Abandon des " << _prochain->laCouleur() << " !" << std::endl ;
                    _finDePartie = true ;
                    continue ;
                    break ;
                case input_token::error :
					std::memcpy(_errorMsg, "Erreur de saisie !", -1 + BUFFER_ERR_MX_SIZE);
					std::cout << "Erreur de saisie !" << std::endl ;
                    continue ;
                    break ;
                case input_token::neutral :
                    //ici:règles pour la case départ/arrivée/raffle/... !
					_coupEnCours.setEtape(etapes_du_coup::evaluation_depart) ;
					if (_input.casePlateau()->estLibre())
					{
						_coupEnCours.setEtape(etapes_du_coup::depart_error) ;
						std::memcpy(_errorMsg, "ERROR : case de départ ne peut pas être libre" , -1 + BUFFER_ERR_MX_SIZE);
					}
					else if(_input.casePlateau()->pion()->getCouleur() != _prochain->couleur())
					{
						_coupEnCours.setEtape(etapes_du_coup::depart_error) ;
						std::memcpy(_errorMsg, "ERROR : le pion (", -1 + BUFFER_ERR_MX_SIZE);
						std::strcat(_errorMsg, _input.casePlateau()->pion()->motif());
						std::strcat(_errorMsg, ") n'appartient pas aux (");
						std::strcat(_errorMsg, _prochain->laCouleur());
						std::strcat(_errorMsg, ") !");
					}
					else
					{
						_coupEnCours.setEtape(etapes_du_coup::depart_ok) ;
						std::cout << "La case <<" << _input.casePlateau()->pion()->getCouleur() << ">> est occupée \n";
						std::cout << " .... par la même couleur que le joueur en cours [" << _prochain->laCouleur() << "] \n";
					}
                    break ;
                default :
                    break ;
            }

            {
                continue ;
            }
        }

        return retCode ;
    }

    int Plateau::notationCase(const int& y, const int& x) const
    {
        int retValue = 0 ;

        for(int i = 1 ; i < NB_CASES_PLATEAU ; ++i)
        {
            retValue = _cases[i].notationOfficielle( y, x ) ;
            if(retValue != 0)
            {
                break ;
            }
        }

        return retValue ;
    }
}

namespace spc_plateau
{
	Plateau::PiedDePage::PiedDePage()
	{
		for (int l = 0; l < NB_LIGNES_PIED_DE_PAGE; ++l)
		{
			std::memset(_lignes[l], 0, SZ_LIGNE_PIED_DE_PAGE);
		}
		std::memset(_buffer, 0, 111);
		std::memcpy(_lignes[2], "Blancs [/o/]            vs             [/x/] Noirs", -1 + SZ_LIGNE_PIED_DE_PAGE);
		std::memcpy(_lignes[3], "--------------------------------------------------", -1 + SZ_LIGNE_PIED_DE_PAGE);
		std::memcpy(_lignes[6], "- Q pour abandonner -", -1 + SZ_LIGNE_PIED_DE_PAGE);
	}

	void Plateau::PiedDePage::affiche(const char* errorMsg)
	{
		std::cout << std::endl << _marge << (std::strlen(errorMsg) > 0 ? errorMsg : "") << std::endl ;

		for (int i = 0; i < NB_LIGNES_PIED_DE_PAGE; ++i)
		{
			std::cout << _marge << _lignes[i] << std::endl;
		}
	}

	void Plateau::PiedDePage::init(Plateau& plateau, const Joueur* joueur, const Coup& coup)
	{
		std::memset(_lignes[4], 0, SZ_LIGNE_PIED_DE_PAGE);

		std::memcpy(13 + _lignes[2], (joueur->couleur() == couleur_pion::blanc ? FLECHE_GAUCHE : FLECHE_VIDE), SZ_FLECHE);
		std::memcpy(34 + _lignes[2], (joueur->couleur() == couleur_pion::noir ? FLECHE_DROITE : FLECHE_VIDE), SZ_FLECHE);
		std::memcpy(_lignes[4], "Les ", 4);
		std::strcat(_lignes[4], joueur->laCouleur());
        std::strcat(_lignes[4], " ont la main");
		if (joueur->couleur() == couleur_pion::blanc)
		{
			_lpad(_lignes[4]);
		}
		std::memset(_invite, 0, SZ_INVITE);
		std::memcpy(_invite, _marge, SZ_MARGE_PIED_DE_PAGE);
		if (coup.etape() <= etapes_du_coup::input_depart)
		{
			std::memcpy(SZ_MARGE_PIED_DE_PAGE + _invite, "Départ : ", -(SZ_MARGE_PIED_DE_PAGE) + SZ_INVITE);
		}
		else if (coup.etape() > etapes_du_coup::depart_ok)
		{
			std::memcpy(SZ_MARGE_PIED_DE_PAGE + _invite, "Arrivée : ", -(SZ_MARGE_PIED_DE_PAGE) + SZ_INVITE);
		}
	}

	char* Plateau::PiedDePage::_lpad(char* str, const int & size)
	{
		const int szStr = std::strlen(str);
		char dummy[2 + szStr];
		std::memset(dummy, 0, 2 + szStr);
		std::memcpy(dummy, str, szStr);
		std::memset(str, 0, (szStr > size ? szStr : size));
		std::memset(str, _motif, -1 + (szStr > size ? szStr : size));
		std::memcpy(str + ((szStr > size ? szStr + 1 : size) - szStr - 1), dummy, szStr);

		return str;
	}

	char* Plateau::PiedDePage::_rpad(char* str, const int & size)
	{
		const int szStr = std::strlen(str);
		char dummy[2 + szStr];
		std::memset(dummy, 0, 2 + szStr);
		std::memset(str + szStr, _motif, -1 + (szStr > size ? szStr + 1 : size) - szStr);
		str[-1 + (szStr > size ? szStr + 1 : size)] = 0;

		return str;
	}
}

namespace spc_plateau
{
}
