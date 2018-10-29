// plateau.c

# include <iostream>
# include "plateau.h"

namespace spc_plateau
{
	CaseDamier::CaseDamier()
		: _apparence(ApparenceCase::normal)
		, _cellule(nullptr)
		, _couleur(CouleurCaseDamier::null)
		, _estLibre(true)
		, _nbDiagonales(0)
		, _notationOfficielle(0)
		, _pion(nullptr)
		, _x(0)
		, _y(0)
	{
		for (int ii = 0; ii < NB_DIAGONALES_MAX_PAR_CASE; ++ii) 
		{
			_diagonale[ii] = nullptr;
		} 
	}

	void spc_plateau::CaseDamier::affiche(void)
	{
		setCellule();
		char tmp[4];
		std::memset(tmp, 0, 4);
		std::memcpy(tmp, _cellule->motif, 3);
		std::cout << tmp ;
	}

	void CaseDamier::init(int x, int y, int notation, Pion * pion, ApparenceCase apparence, CouleurCaseDamier couleurCase) // , CouleurPion couleurPion)
	{
		_apparence = apparence ;
		_estLibre = (pion == nullptr ? true : false) ;
		_notationOfficielle = notation ;
		_pion = pion ;
		_x = x ;
		_y = y ;
		_couleur = couleurCase ;
	}

	void CaseDamier::setCellule(void)
	{
		const char Blanc[] = " O ";
		const char blanc[] = " o ";
		const char Noir[] = " X ";
		const char noir[] = " x ";
		const char vide[] = ":::";
		const char bold_Blanc[] = "/O/";
		const char bold_blanc[] = "/o/";
		const char bold_Noir[] = "/X/";
		const char bold_noir[] = "/x/";
		const char bold_vide[] = "///";
		const char * const pMotif 
			= ( _apparence == ApparenceCase::surbillance 
				? (_estLibre 
					? bold_vide 
					: (_pion->getPromotion() 
						? (_pion->getCouleur() == CouleurPion::blanc ? bold_Blanc : bold_Noir)
						: (_pion->getCouleur() == CouleurPion::blanc ? bold_blanc : bold_noir)
						) 
					) // fin AppCase::surbillance
				: (_estLibre
					? vide
					: (_pion->getPromotion()
						? (_pion->getCouleur() == CouleurPion::blanc ? Blanc : Noir)
						: (_pion->getCouleur() == CouleurPion::blanc ? blanc : noir)
						)
					) // fin ! AppCase::surbillance
			);
		std::memcpy(_cellule->motif, pMotif, 3);
	}

	void CaseDamier::setDiagonale(const Diagonale * diagonale)
	{
		for (unsigned int ii = _nbDiagonales ; ii < NB_DIAGONALES_MAX_PAR_CASE; ++ii)
		{
			if (_diagonale[ii] == nullptr)
			{
				_diagonale[ii] = diagonale;
				++_nbDiagonales;
				break;
			}
		}
	}
}

namespace spc_plateau
{
	Diagonale::~Diagonale()
	{
		if (_taille == 0)
		{
			delete _casesDamier;
			_taille = 0;
			_numero = 0;
			_casesDamier = nullptr;
		}
	}

	Diagonale::Diagonale(const Diagonale& d)
	{
		if (this != &d)
		{
			if (_taille > 0)
			{
				delete _casesDamier;
				_taille = 0;
				_numero = 0;
				_casesDamier = nullptr;
			}

			if (d._taille > 0)
			{
				_taille = d._taille;
				_numero = d._numero;
				_casesDamier = new CaseDamier*[_taille];
				for (int i = 0; i < _taille; ++i)
				{
					_casesDamier[i] = d._casesDamier[i];
				}
			}
		}
	}

	Diagonale& Diagonale::operator = (const Diagonale& d)
	{
		if (this != &d)
		{
			if (_taille > 0)
			{
				delete _casesDamier;
				_taille = 0;
				_numero = 0;
				_casesDamier = nullptr;
			}

			if (d._taille > 0)
			{
				_taille = d._taille;
				_numero = d._numero;
				_casesDamier = new CaseDamier*[_taille];
				for (int i = 0; i < _taille; ++i)
				{
					_casesDamier[i] = d._casesDamier[i];
				}
			}
		}
		return *this;
	}

	int Diagonale::addCase(CaseDamier* c)
	{
		Diagonale oldDiagonale = *this;

		if (_taille > 0)
		{
			delete _casesDamier;
			_taille = 0;
			_numero = 0;
			_casesDamier = nullptr;
		}

		_taille = 1 + oldDiagonale._taille;
		_numero = oldDiagonale._numero;
		_casesDamier = new CaseDamier*[_taille];
		for (int i = 0; i < oldDiagonale._taille; ++i)
		{
			_casesDamier[i] = oldDiagonale._casesDamier[i];
		}
		_casesDamier[-1 + _taille] = c;

		return _taille;
	}

	int Diagonale::init(int taille, CaseDamier** c, int numero)
	{
		if (_taille > 0)
		{
			delete _casesDamier;
			_taille = 0;
			_numero = 0;
			_casesDamier = nullptr;
		}

		_taille = taille;
		_numero = numero;
		_casesDamier = new CaseDamier*[_taille];
		for (int i = 0; i < _taille; ++i)
		{
			_casesDamier[i] = c[i];
			_casesDamier[i]->setDiagonale(this);
		}

		return _taille;
	}
}

namespace spc_plateau
{
	Input::Input() 
		: _bufSize(0)
		, _caseDamier(nullptr)
		, _inputType(InputType::is_undefined)
	{
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
	}

	void Input::saisie(const char* invite)
	{
		std::cout << invite;

		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
		std::cin.getline(_buffer, -1 + INPUT_BUFFER_MX_SIZE);
		_bufSize = strlen(_buffer);
	}
}

namespace spc_plateau
{
	Plateau::Plateau(PositionsCouleursDepart positionsDepart)
		: _pionsNord(positionsDepart == PositionsCouleursDepart::blancs_noirs ? _pionsBlancs 
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? _pionsNoirs 
				: nullptr ))
		, _pionsSud(positionsDepart == PositionsCouleursDepart::blancs_noirs ? _pionsNoirs
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? _pionsBlancs
				: nullptr))
		, _couleurPionsNord(positionsDepart == PositionsCouleursDepart::blancs_noirs ? CouleurPion::blanc
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? CouleurPion::noir
				: CouleurPion::null))
		, _couleurPionsSud(positionsDepart == PositionsCouleursDepart::blancs_noirs ? CouleurPion::noir
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? CouleurPion::blanc
				: CouleurPion::null))
	{
		/* 
		Initialisation des casesDamier :
		------------------------------
		- La case 0 est blanche, les 50 suivantes noires ; 
		- Les pions couleur 1/2 dans les cases 1 à 20 et les couleur 2/2 de 31 à 50
		NB : le pointeur sur le pion reste null dans un premier temps
		**/

		int iCaseDamier = 0;
		_casesDamier[iCaseDamier].init(0, 0, 0, nullptr, ApparenceCase::normal, CouleurCaseDamier::blanc); //  , CouleurPion::null);

		for (int y = 10; y > 0; --y)       // ligne
		{
			for (int x = 1; x <= 10; ++x)  // colonne
			{
				if (0 == (y % 2))  // lignes paires  => colonnes paires uniquement
				{
					if (0 == (x % 2))
					{
						++iCaseDamier;
						_casesDamier[iCaseDamier].init(
							x
							, y
							, iCaseDamier
							, nullptr
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
						);
					}
				}
				else  // lignes impaires => colonnes impaires
				{
					if (0 != (x % 2))
					{
						++iCaseDamier;
						_casesDamier[iCaseDamier].init(
							x
							, y
							, iCaseDamier
							, nullptr
							, ApparenceCase::normal
							, CouleurCaseDamier::noir
						);
					}
				}
			}
		}

		{
			// Initialisation des pointeurs de cellules dans les caseDamiers
			// y paire de [2 à 20] et x de [2 à 10 si y%4!=0, de 1 à 9 si y%4==0] => cellule
			for (int y = 2, iCase = 1 ; y <= 20; y += 2)
			{
				for (int x = 1; x <= 10; ++x)
				{
					if ((x % 2 == 0 && y % 4 != 0) || (x % 2 != 0 && y % 4 == 0))
					{
						_casesDamier[iCase].setCellule(&_cellules[y][x]);
						++iCase;
					}
				}
			}
		}

		initPions(_pionsNord, &_casesDamier[1], _couleurPionsNord);
		initPions(_pionsSud, &_casesDamier[31], _couleurPionsSud);

		initDiagonales();
	}

	void Plateau::initDiagonales(void)
	{
		CaseDamier* dummy[100] =
		{
			// Paires
			  &_casesDamier[1],  &_casesDamier[6]
			, &_casesDamier[2],  &_casesDamier[7],  &_casesDamier[11], &_casesDamier[16]
			, &_casesDamier[3],  &_casesDamier[8],  &_casesDamier[12], &_casesDamier[17], &_casesDamier[21], &_casesDamier[26]
			, &_casesDamier[4],  &_casesDamier[9],  &_casesDamier[13], &_casesDamier[18], &_casesDamier[22], &_casesDamier[27], &_casesDamier[31], &_casesDamier[36]
			, &_casesDamier[5],  &_casesDamier[10], &_casesDamier[14], &_casesDamier[19], &_casesDamier[23], &_casesDamier[28], &_casesDamier[32], &_casesDamier[37], &_casesDamier[41], &_casesDamier[46]
			, &_casesDamier[15], &_casesDamier[20], &_casesDamier[24], &_casesDamier[29], &_casesDamier[33], &_casesDamier[38], &_casesDamier[42], &_casesDamier[47]
			, &_casesDamier[25], &_casesDamier[30], &_casesDamier[34], &_casesDamier[39], &_casesDamier[43], &_casesDamier[48]
			, &_casesDamier[35], &_casesDamier[40], &_casesDamier[44], &_casesDamier[49]
			, &_casesDamier[45], &_casesDamier[50]
			// Impaires
			, &_casesDamier[46]
			, &_casesDamier[36], &_casesDamier[41], &_casesDamier[47]
			, &_casesDamier[26], &_casesDamier[31], &_casesDamier[37], &_casesDamier[42], &_casesDamier[48]
			, &_casesDamier[16], &_casesDamier[21], &_casesDamier[27], &_casesDamier[32], &_casesDamier[38], &_casesDamier[43], &_casesDamier[49]
			, &_casesDamier[6], &_casesDamier[11], &_casesDamier[17], &_casesDamier[22], &_casesDamier[28], &_casesDamier[33], &_casesDamier[39], &_casesDamier[44], &_casesDamier[50]
			, &_casesDamier[1], &_casesDamier[7], &_casesDamier[12], &_casesDamier[18], &_casesDamier[23], &_casesDamier[29], &_casesDamier[34], &_casesDamier[40], &_casesDamier[45]
			, &_casesDamier[2], &_casesDamier[8], &_casesDamier[13], &_casesDamier[19], &_casesDamier[24], &_casesDamier[30], &_casesDamier[35]
			, &_casesDamier[3], &_casesDamier[9], &_casesDamier[14], &_casesDamier[20], &_casesDamier[25]
			, &_casesDamier[4], &_casesDamier[10], &_casesDamier[15]
			, &_casesDamier[5]
		};
		_diagonales[0].init(2,  &dummy[0] , 1);
		_diagonales[1].init(4,  &dummy[2] , 2);
		_diagonales[2].init(6,  &dummy[6] , 3);
		_diagonales[3].init(8,  &dummy[12], 4);
		_diagonales[4].init(10, &dummy[20], 5);
		_diagonales[5].init(8,  &dummy[30], 6);
		_diagonales[6].init(6,  &dummy[38], 7);
		_diagonales[7].init(4,  &dummy[44], 8);
		_diagonales[8].init(2,  &dummy[48], 9);
		_diagonales[9].init(1,  &dummy[50], 10);
		_diagonales[10].init(3, &dummy[51], 11);
		_diagonales[11].init(5, &dummy[54], 12);
		_diagonales[12].init(7, &dummy[59], 13);
		_diagonales[13].init(9, &dummy[66], 14);
		_diagonales[14].init(9, &dummy[75], 15);
		_diagonales[15].init(7, &dummy[84], 16);
		_diagonales[16].init(5, &dummy[91], 17);
		_diagonales[17].init(3, &dummy[96], 18);
		_diagonales[18].init(1, &dummy[99], 19);
	}
}

namespace spc_plateau
{
	void Pion::init(CaseDamier* const cd, CouleurPion c, bool p)
	{
		_case = cd;
		_couleur = c;
		_promotion = p;
	}
	void Pion::setCase(CaseDamier* c)
	{
		_case = c;
	}
}

namespace spc_plateau
{
	void Plateau::affiche(void)
	{
		for (int iCase = 1; iCase < NB_CASES_PLATEAU; ++iCase)
		{
			_casesDamier[iCase].setCellule();
		}

		std::cout 
			<< _cellulesEntete[0][0].motif << std::endl
			<< _cellules[0][0].motif << std::endl
			<< _cellulesEnqueue[0][0].motif << std::endl
			;
	}

	bool Plateau::coupSuivant(void)
	{
		bool coupInvalide = true;
		char invite[256];

		memset(invite, 0, 256);
		invite[0] = '=';
		invite[1] = '>';
		invite[2] = ' ';
		_input.saisie(invite);

		return coupInvalide;
	}

	void Plateau::initPions(Pion* const pions, CaseDamier* const cases, CouleurPion& couleur)
	{
		for (int i = 0; i < NB_PIONS_PAR_COULEUR; ++i)
		{
			pions[i].init(&cases[i], couleur, false);
			cases[i].setPion(&pions[i]);
		}
	}
}

