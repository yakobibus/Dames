// plateau.c

# include <iostream>
# include "plateau.h"

namespace spc_dames
{
	CaseDamier::CaseDamier()
		: _apparence(ApparenceCase::normal)
		, _cellule(nullptr)
		, _coordonnees(0, 0)
		, _couleur(CouleurCaseDamier::null)
		, _estLibre(true)
		, _nbDiagonales(0)
		, _notationOfficielle(0)
		, _pion(nullptr)
	{
		for (int ii = 0; ii < NB_DIAGONALES_MAX_PAR_CASE; ++ii)
		{
			_diagonale[ii] = nullptr;
		}
	}

	void CaseDamier::affiche(void)
	{
		setCellule();
		char tmp[4];
		std::memset(tmp, 0, 4);
		std::memcpy(tmp, _cellule->motif, 3);
		std::cout << tmp;
	}

	int  CaseDamier::countOfGapCells(const CaseDamier& caseDamier) const
	{
		for (unsigned int ii = 0; ii < _nbDiagonales; ++ii)
		{
			if (_diagonale[ii]->estDansLaDiagonale(caseDamier))
			{
				return _diagonale[ii]->countOfGapCells(*this, caseDamier);
			}
		}
		return DUMMY_GAPS;  // the cells aren't on the same diagonal
	}

	void CaseDamier::init(const Coordonnees& coordonnees, int notation, Pion* pion, ApparenceCase apparence, CouleurCaseDamier couleurCase) // , CouleurPion couleurPion)
	{
		_apparence = apparence;
		_estLibre = (pion == nullptr ? true : false);
		_notationOfficielle = notation;
		_pion = pion;
		_coordonnees = coordonnees;
		_couleur = couleurCase;
	}

	bool CaseDamier::isContiguous(const CaseDamier& caseDamier) const
	{
		for (unsigned int ii = 0; ii < _nbDiagonales; ++ii)
		{
			if (_diagonale[ii]->areContiguous(*this, caseDamier))
			{
				return true;
			}
		}

		return false;
	}

	bool CaseDamier::isDiagonally(const CaseDamier& caseDamier) const
	{
		for (unsigned int ii = 0; ii < _nbDiagonales; ++ii)
		{
			if (_diagonale[ii]->estDansLaDiagonale(caseDamier))
			{
				return true;
			}
		}

		return false;
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
		const char* const pMotif
			= (_apparence == ApparenceCase::surbillance
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

	void CaseDamier::setDiagonale(const Diagonale* diagonale)
	{
		for (unsigned int ii = _nbDiagonales; ii < NB_DIAGONALES_MAX_PAR_CASE; ++ii)
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

namespace spc_dames
{
	Coup::~Coup()
	{
		delete[] _casesDeTransit;
		_casesDeTransit = nullptr;
		_nbCasesDeTransit = 0;
	}

	Coup::Coup(Coup & c)
	{
		if (this != &c)
		{
			_arrivee = c._arrivee;
			_depart = c._depart;
			delete[] _casesDeTransit;
			_casesDeTransit = c._casesDeTransit;
			_nbCasesDeTransit = c._nbCasesDeTransit;
			_joueur = c._joueur;
			_valide = c._valide;
		}
	}

	Coup & Coup::operator = (Coup & c)
	{
		if (this != &c)
		{
			_arrivee = c._arrivee;
			_depart = c._depart;
			delete[] _casesDeTransit;
			_casesDeTransit = c._casesDeTransit;
			_nbCasesDeTransit = c._nbCasesDeTransit;
			_joueur = c._joueur;
			_valide = c._valide;
		}

		return *this;
	}

	// ---

	void Coup::addCaseDeTransit(CaseDamier* caseDamier)
	{
		if (_casesDeTransit == nullptr)
		{
			//CaseDamier** dummyListe = new CaseDamier* [1 + _nbCasesDeTransit] ;
			++_nbCasesDeTransit;
			_casesDeTransit = new CaseDamier[_nbCasesDeTransit] ;
			_casesDeTransit = caseDamier;
		}
	}

	void Coup::set (
		CaseDamier* depart = nullptr
		, CaseDamier* arrvivee = nullptr
		, CaseDamier* transit = nullptr
		, unsigned int szTransit = 0
		, Joueur* joueur = nullptr
		, bool valide = false
	)
	{
		_depart = depart;
		_arrivee = arrvivee;
		delete[] _casesDeTransit;
		_nbCasesDeTransit = szTransit;
		_casesDeTransit = transit;
		_joueur = joueur;
		_valide = valide;
	}

	void Coup::raz(void) 
	{ 
		_arrivee = nullptr;
		_depart = nullptr;
		delete[] _casesDeTransit;
		_nbCasesDeTransit = 0;
		_joueur = nullptr;
		_valide = false;
	}
}

namespace spc_dames
{
	TableDeCoups::TableDeCoups(const TableDeCoups & c)
	{
		if (this != &c) 
		{ 
			for (unsigned short ii = 0; ii < _arraySize; ++ii)
			{
				delete _array[ii];
			}
			delete[] _array;
			_arraySize = c._arraySize;
			_arrayMaxSize = c._arrayMaxSize;
			if (_arraySize > 0)
			{
				_array = new Coup*[_arraySize];
				for (unsigned int ii = 0; ii < _arraySize; ++ii)
				{
					_array[ii] = c._array[ii];
				}
			}
			else
			{
				_array = nullptr;
			}
		}
	}

	TableDeCoups & TableDeCoups::operator=(const TableDeCoups & c)
	{
		if (this != &c) 
		{ 
			for (unsigned short ii = 0; ii < _arraySize; ++ii)
			{
				delete _array[ii];
			}
			delete[] _array;
			_arraySize = c._arraySize;
			_arrayMaxSize = c._arrayMaxSize;
			if (_arraySize > 0)
			{
				_array = new Coup*[_arraySize];
				for (unsigned int ii = 0; ii < _arraySize; ++ii)
				{
					_array[ii] = c._array[ii];
				}
			}
			else
			{
				_array = nullptr;
			}
		}
		return *this;
	}

	//

	/*
	void TableDeCoups::ajouterCoup(Coup* coup)
	{
		if (_arraySize == _arrayMaxSize)
		{
			_arrayMaxSize = (1 + (_arrayMaxSize / NB_DE_COUPS_PAR_LOT)) * NB_DE_COUPS_PAR_LOT;
			Coup** dummyArray = new Coup*[_arrayMaxSize];
			for (unsigned int ii = 0; ii < _arraySize; ++ii)
			{
				dummyArray[ii] = _array[ii];
			}

			for (short ii = 0; ii < _arraySize; ++ii)
			{
				delete _array[ii];
			}
			delete[] _array;
			_array = dummyArray;
		}
		_array[_arraySize] = coup;
		++_arraySize;
	}
	*/

	const unsigned int& TableDeCoups::ajouterNouveauCoup(void)
	{
		if (_arraySize == _arrayMaxSize)
		{
			_arrayMaxSize = (1 + (_arrayMaxSize / NB_DE_COUPS_PAR_LOT)) * NB_DE_COUPS_PAR_LOT;
			Coup** dummyArray = new Coup*[_arrayMaxSize];
			for (unsigned int ii = 0; ii < _arraySize; ++ii)
			{
				dummyArray[ii] = _array[ii];
			}

			for(unsigned short ii = 0 ; ii < _arraySize ; ++ii) 
			{
				delete _array[ii];
			}
			delete[] _array;
			_array = dummyArray;
		}

		_array[_arraySize] = new Coup ;
		++_arraySize;

		return _arraySize;
	}
}

namespace spc_dames
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
				for (unsigned int i = 0; i < _taille; ++i)
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
				for (unsigned int i = 0; i < _taille; ++i)
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
		for (unsigned int i = 0; i < oldDiagonale._taille; ++i)
		{
			_casesDamier[i] = oldDiagonale._casesDamier[i];
		}
		_casesDamier[-1 + _taille] = c;

		return _taille;
	}

	bool Diagonale::areContiguous(const CaseDamier& c1, const CaseDamier& c2) const
	{
		for (unsigned int ii = 0; ii < _taille; ++ii)
		{
			if (c1 == *(_casesDamier[ii]))
			{
				for (unsigned int jj = (ii == 0 ? 0 : -1 + ii) ; jj < ((1 + ii) < _taille ? 2 + ii : ii); ++jj)
				{
					if ((ii != jj) && (c2 == *(_casesDamier[jj])))
					{
						return true;
					}
				}
				break ;
			}
		}

		return false; 
	}

//# include <cstdlib>  // for std::abs

	int Diagonale::countOfGapCells(const CaseDamier& c1, const CaseDamier& c2) const
		/*
		  Returning values :
		  - (DUMMY_GAPS) : the 2 cells aren't on the same diagonal
		  - (0)  : the 2 cells are the same
		  - (!=0) : the number of gap cells (1 : adjacent cells, 2 : one cell between them, n : -1+n cells between)
		**/
	{
		for (unsigned int ii = 0; ii < _taille; ++ii)
		{
			if (c1 == *(_casesDamier[ii]))
			{
				for (unsigned int jj = 0 ; jj < _taille ; ++jj)
				{
					if (c2 == *(_casesDamier[jj]))
					{
						return ((c2.getY() - c1.getY()) < 0 ? -1 : 1) * std::abs( static_cast <long long> (ii - jj)); //  (static_cast<int>(ii - jj));
					}
				}
				break;
			}
		}

		return DUMMY_GAPS ; // The 2 cells aren't on the same diagonal
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
		for (unsigned int i = 0; i < _taille; ++i)
		{
			_casesDamier[i] = c[i];
			_casesDamier[i]->setDiagonale(this);
		}

		return _taille;
	}
}

namespace spc_dames
{
	Input::Input() 
		: _bufSize(0)
		//, _caseDamier(nullptr)
		, _inputType(InputType::is_undefined)
		, _isValid(false)
	{
		_coordonnees.set(0, 0);
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
	}

	void Input::_isValidInput(void)
	{
		_inputType = InputType::is_error;

		if (_bufSize == 2)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _buffer[1] != '0')
			{
				_isValid = true;
				_inputType = InputType::is_alphaOneDigitTwo;
				_coordonnees.set(_aToLine(&(_buffer[1])), _aToColumn(_buffer[0]));
			}
			else if (_isDigit(_buffer[0]) && _isAlpha(_buffer[1]) && _buffer[0] != '0')
			{
				_isValid = true;
				_inputType = InputType::is_digitOneAlphaTwo;
				_coordonnees.set(_aToLine(&(_buffer[0]), 1), _aToColumn(_buffer[1]));
			}
		}
		else if (_bufSize == 3)
		{
			if (_isAlpha(_buffer[0]) && _isDigit(_buffer[1]) && _isDigit(_buffer[2]))
			{
				_inputType = InputType::is_alphaOnedigitTwoThree;
				_coordonnees.set(_aToLine(&(_buffer[1])), _aToColumn(_buffer[0]));
				if (_buffer[1] == '0' && _buffer[2] != '0')
				{
					_isValid = true;
				}
				else if (_buffer[1] == '1' && _buffer[2] == '0')
				{
					_isValid = true;
				}
			}
			else if (_isDigit(_buffer[0]) && _isDigit(_buffer[1]) && _isAlpha(_buffer[2]))
			{
				_inputType = InputType::is_digitOneTwoAlphaThree;
				_coordonnees.set(_aToLine(&(_buffer[0]), 2), _aToColumn(_buffer[2]));
				if (_buffer[0] == '0' && _buffer[1] != '0')
				{
					_isValid = true;
				}
				else if (_buffer[0] == '1' && _buffer[0] == '0')
				{
					_isValid = true;
				}
			}
		}
		else if (_bufSize > 0 && (_buffer[0] == 'x' || _buffer[0] == 'X' || _buffer[0] == 'q' || _buffer[0] == 'Q'))
		{
			_isValid = true;
			_inputType = InputType::is_exiting;
		}
	}

	void Input::saisie(const char* invite)
	{
		_isValid = false;
		std::cout << invite;

		_inputType = InputType::is_undefined;
		_coordonnees.set(0, 0);
		_bufSize = 0;
		std::memset(_buffer, 0, INPUT_BUFFER_MX_SIZE);
		std::cin.getline(_buffer, -1 + INPUT_BUFFER_MX_SIZE);
		_bufSize = strlen(_buffer);
		//
		_isValidInput();
	}
}

namespace spc_dames
{
	Joueur::Joueur() 
		: _id(IdJoueur::undefined)
		, _couleur(CouleurPion::null)
		, _nature(NatureJoueur::undefined)
		, _nom(nullptr)
		, _szNom(0)
		, _sensDuDeplacement(SensDuDeplacement::undefined)
	{}

	Joueur::~Joueur()
	{
		if (_nom != nullptr)
		{
			delete _nom;
			_nom = nullptr;
			_szNom = 0;
		}
	}

	Joueur::Joueur(const Joueur& j)
	{
		if (this != &j)
		{
			_couleur = j._couleur;
			_id = j._id;
			_nature = j._nature;

			if (_nom != nullptr)
			{
				delete _nom;
				_nom = nullptr;
				_szNom = 0;
			}

			_szNom = std::strlen(j._nom);
			_nom = new char[1 + _szNom];
			std::memset(_nom, 0, 1 + _szNom);
			std::memcpy(_nom, j._nom, _szNom);

			_sensDuDeplacement = j._sensDuDeplacement;
		}
	}

	Joueur& Joueur::operator=(const Joueur & j)
	{
		if (this != &j)
		{
			_couleur = j._couleur;
			_id = j._id;
			_nature = j._nature;

			if (_nom != nullptr)
			{
				delete _nom;
				_nom = nullptr;
				_szNom = 0;
			}

			if (j._nom != nullptr)
			{
				_szNom = std::strlen(j._nom);
				_nom = new char[1 + _szNom];
				std::memset(_nom, 0, 1 + _szNom);
				std::memcpy(_nom, j._nom, _szNom);
			}
			
			_sensDuDeplacement = j._sensDuDeplacement;
		}

		return *this;
	}

	void Joueur::init(
		  const IdJoueur& id
		, const CouleurPion& couleur
		, const char* nom
		, const SensDuDeplacement& sensDuDeplacement
		, const NatureJoueur& nature
	)
	{
		_id = id;
		_couleur = couleur;
		_nature = nature;
		if (_nom != nullptr)
		{ 
			delete _nom; 
			_nom = nullptr; 
			_szNom = 0;
		}
		if(nom != nullptr)
		{
			_szNom = std::strlen(nom);
			_nom = new char[1 + _szNom];
			std::memset(_nom, 0, 1 + _szNom);
			std::memcpy(_nom, nom, _szNom);
			_sensDuDeplacement = sensDuDeplacement;
		}
	}
}

namespace spc_dames
{
	Plateau::Plateau(PositionsCouleursDepart positionsDepart)
		: _abandon(false)
		, _couleurPionsNord(positionsDepart == PositionsCouleursDepart::blancs_noirs ? CouleurPion::blanc
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? CouleurPion::noir
				: CouleurPion::null))
		, _couleurPionsSud(positionsDepart == PositionsCouleursDepart::blancs_noirs ? CouleurPion::noir
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? CouleurPion::blanc
				: CouleurPion::null))
		, _joueurEnCours(nullptr)
		, _pionsNord(positionsDepart == PositionsCouleursDepart::blancs_noirs ? _pionsBlancs
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? _pionsNoirs
				: nullptr))
		, _pionsSud(positionsDepart == PositionsCouleursDepart::blancs_noirs ? _pionsNoirs
			: (positionsDepart == PositionsCouleursDepart::noirs_blancs ? _pionsBlancs
				: nullptr))
	{
		/*
		Initialisation des casesDamier :
		------------------------------
		- La case 0 est blanche, les 50 suivantes noires ;
		- Les pions couleur 1/2 dans les cases 1 � 20 et les couleur 2/2 de 31 � 50
		NB : le pointeur sur le pion reste null dans un premier temps
		**/

		/*
		c'est ici le probl�me de couleur des joueurs
		*/
		if (positionsDepart == PositionsCouleursDepart::blancs_noirs)
		{
			std::cout << "......blancs_noirs.....ici...\n";
			_joueurNord.init(IdJoueur::premier, CouleurPion::blanc, "Caladan", SensDuDeplacement::negatif, NatureJoueur::humain);
			_joueurSud.init(IdJoueur::second, CouleurPion::noir, "SalusaSecundus", SensDuDeplacement::positif, NatureJoueur::humain);
			_joueurEnCours = &_joueurNord;  // Les blancs commencent
		}
		else if (positionsDepart == PositionsCouleursDepart::noirs_blancs) 
		{
			std::cout << "......noirs_blancs.....ici...\n";
			_joueurNord.init(IdJoueur::second, CouleurPion::noir, "SalusaSecundus", SensDuDeplacement::negatif, NatureJoueur::humain);
			_joueurSud.init(IdJoueur::premier, CouleurPion::blanc, "Caladan", SensDuDeplacement::positif, NatureJoueur::humain);
			_joueurEnCours = &_joueurSud;  // Les blancs commencent
		}

		std::memcpy(&(_cellulesEntete[4][0]), _joueurNord.getNom(), _joueurNord.getSzNom());
		std::memcpy(&(_cellulesEnqueue[1][0]), _joueurSud.getNom(), _joueurSud.getSzNom());

		int iCaseDamier = 0;
		_casesDamier[iCaseDamier].init(Coordonnees(0, 0), 0, nullptr, ApparenceCase::normal, CouleurCaseDamier::blanc); //  , CouleurPion::null);

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
							Coordonnees(y, x)
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
							Coordonnees(y, x)
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
			// y paire de [2 � 20] et x de [2 � 10 si y%4!=0, de 1 � 9 si y%4==0] => cellule
			for (int y = 2, iCase = 1; y <= 20; y += 2)
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

	Plateau::Plateau(const Plateau& p)
	{
		if (this != &p)
		{
			for (short ii = 0; ii < NB_CASES_PLATEAU; ++ii) {
				_casesDamier[ii] = p._casesDamier[ii];
			}
			for (short yy = 0; yy < NB_Y_REF_CELLULES; ++yy) {
				for (short xx = 0; xx < NB_X_REF_CELLULES; ++xx) {
					_cellules[yy][xx] = p._cellules[yy][xx];
				}
			}
			for (short yy = 0; yy < NB_Y_REF_CELLULES_ENTETE; ++yy) {
				for (short xx = 0; xx < NB_X_REF_CELLULES; ++xx) { 
					_cellulesEntete[yy][xx] = p._cellulesEntete[yy][xx];
				}
			}
			for (short yy = 0; yy < NB_Y_REF_CELLULES_ENQUEUE; ++yy) {
				for (short xx = 0; xx < NB_X_REF_CELLULES; ++xx) { 
					_cellulesEnqueue[yy][xx] = p._cellulesEnqueue[yy][xx];
				}
			}

			_abandon = p._abandon;
			_couleurPionsNord = p._couleurPionsNord;
			_couleurPionsSud = p._couleurPionsSud;

			for (short ii = 0; ii < NB_DIAGONALES_PLATEAU ; ++ii) { 
				_diagonales[ii] = p._diagonales[ii];
			}

			_joueurNord = p._joueurNord;
			_joueurSud = p._joueurSud;

			for (short ii = 0; ii < NB_PIONS_PAR_COULEUR; ++ii) { 
				_pionsBlancs[ii] = p._pionsBlancs[ii]; 
				_pionsNoirs[ii] = p._pionsNoirs[ii]; 
			}

			_joueurEnCours = p._joueurEnCours;
			_positionsDeDepart = p._positionsDeDepart;
		}
	}

	Plateau & Plateau::operator=(const Plateau & p)
	{
		if (this != &p)
		{
			for (short ii = 0; ii < NB_CASES_PLATEAU; ++ii) {
				_casesDamier[ii] = p._casesDamier[ii];
			}
			for (short yy = 0; yy < NB_Y_REF_CELLULES; ++yy) {
				for (short xx = 0; xx < NB_X_REF_CELLULES; ++xx) {
					_cellules[yy][xx] = p._cellules[yy][xx];
				}
			}
			for (short yy = 0; yy < NB_Y_REF_CELLULES_ENTETE; ++yy) {
				for (short xx = 0; xx < NB_X_REF_CELLULES; ++xx) {
					_cellulesEntete[yy][xx] = p._cellulesEntete[yy][xx];
				}
			}
			for (short yy = 0; yy < NB_Y_REF_CELLULES_ENQUEUE; ++yy) {
				for (short xx = 0; xx < NB_X_REF_CELLULES; ++xx) {
					_cellulesEnqueue[yy][xx] = p._cellulesEnqueue[yy][xx];
				}
			}

			_abandon = p._abandon;
			_couleurPionsNord = p._couleurPionsNord;
			_couleurPionsSud = p._couleurPionsSud;
			for (short ii = 0; ii < NB_DIAGONALES_PLATEAU; ++ii) {
				_diagonales[ii] = p._diagonales[ii];
			}

			_joueurNord = p._joueurNord;
			_joueurSud = p._joueurSud;

			for (short ii = 0; ii < NB_PIONS_PAR_COULEUR; ++ii) {
				_pionsBlancs[ii] = p._pionsBlancs[ii];
				_pionsNoirs[ii] = p._pionsNoirs[ii];
			}
			_joueurEnCours = p._joueurEnCours;
			_positionsDeDepart = p._positionsDeDepart;
		}
		
		return *this;
	}	
}

namespace spc_dames
{

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

namespace spc_dames
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

namespace spc_dames
{
	unsigned int Plateau::_getIndexCase(const Input& input) const
	{
		unsigned int index = 0;
		const unsigned int& y = input.getY();
		const unsigned int& x = input.getX();

		switch (y)
		{
		case 1:
			index = (x == 1 ? 46 : (x == 3 ? 47 : (x == 5 ? 48 : (x == 7 ? 49 : (x == 9 ? 50 : 0)))));
			break;
		case 2:
			index = (x == 2 ? 41 : (x == 4 ? 42 : (x == 6 ? 43 : (x == 8 ? 44 : (x == 10 ? 45 : 0)))));
			break;
		case 3:
			index = (x == 1 ? 36 : (x == 3 ? 37 : (x == 5 ? 38 : (x == 7 ? 39 : (x == 9 ? 40 : 0)))));
			break;
		case 4:
			index = (x == 2 ? 31 : (x == 4 ? 32 : (x == 6 ? 33 : (x == 8 ? 34 : (x == 10 ? 35 : 0)))));
			break;
		case 5:
			index = (x == 1 ? 26 : (x == 3 ? 27 : (x == 5 ? 28 : (x == 7 ? 29 : (x == 9 ? 30 : 0)))));
			break;
		case 6:
			index = (x == 2 ? 21 : (x == 4 ? 22 : (x == 6 ? 23 : (x == 8 ? 24 : (x == 10 ? 25 : 0)))));
			break;
		case 7:
			index = (x == 1 ? 16 : (x == 3 ? 17 : (x == 5 ? 18 : (x == 7 ? 19 : (x == 9 ? 20 : 0)))));
			break;
		case 8:
			index = (x == 2 ? 11 : (x == 4 ? 12 : (x == 6 ? 13 : (x == 8 ? 14 : (x == 10 ? 15 : 0)))));
			break;
		case 9:
			index = (x == 1 ? 6 : (x == 3 ? 7 : (x == 5 ? 8 : (x == 7 ? 9 : (x == 9 ? 10 : 0)))));
			break;
		case 10:
			index = (x == 2 ? 1 : (x == 4 ? 2 : (x == 6 ? 3 : (x == 8 ? 4 : (x == 10 ? 5 : 0)))));
			break;
		}

		return index;
	}
}

namespace spc_dames
{
	bool Plateau::_coup(void)
	{
		unsigned int nombreDeCoups = _tableDeCoups.ajouterNouveauCoup();
		Coup& coupEnCours = *_tableDeCoups.getCoup(-1 + nombreDeCoups);
		coupEnCours.set(nullptr, nullptr, nullptr, 0, _joueurEnCours, false);

		Input input;
		bool isCaseArriveeValide = false;
		bool isCaseDepartValide = _coupDepart(input);
		if (isCaseDepartValide)
		{
			coupEnCours.setCaseDepart(&_casesDamier[_getIndexCase(input)]);
			//
			isCaseArriveeValide = (_abandon == true ? false : _coupArrivee(input));
			if (isCaseArriveeValide)
			{
				coupEnCours.setCaseArrivee(&_casesDamier[_getIndexCase(input)]);
			}
		}
		//coupEnCours.setCaseDepart(_getCase(_getIndexCase(input)));
		std::cout << ".....indx.....[" << _getIndexCase(input) << "].....ici....." << std::endl;

		//bool isCaseArriveeValide = ( _abandon == true ? false : _coupArrivee(input) ) ;

		std::cout << (isCaseDepartValide ? "depart==vrai" : "depart==faux") << std::endl;
		std::cout << (isCaseArriveeValide ? "arrivee==vrai" : "arrivee==faux") << std::endl;
		std::cout << (isCaseDepartValide && isCaseArriveeValide ? "depart&&arrivee==vrai" : "depart&&arrivee==faux") << std::endl;

		return isCaseDepartValide && isCaseArriveeValide ;
	}

	bool Plateau::_coupArrivee(Input& input)
	{
		char  invite[256];
		std::memset(invite, 0, 256);
		std::memcpy(invite, "+> ", 3);
		//invite[0] = '=';
		//invite[1] = '>';
		//invite[2] = ' ';
		//Input input;
		input.saisie(invite);
		_abandon = (input.getInputType() == InputType::is_exiting ? true : false);
		_setSelectionneCase(_getIndexCase(input));

		affiche();

		return _caseArriveeValide(input); //ICI...
	}

	bool Plateau::_coupDepart(Input& input)
	{
		char  invite[256];
		memset(invite, 0, 256);
		std::memcpy(invite, "=> ", 3);
		//invite[0] = '=';
		//invite[1] = '>';
		//invite[2] = ' ';
		//Input input;
		input.saisie(invite);
		_abandon = (input.getInputType() == InputType::is_exiting ? true : false);
		_setSelectionneCase(_getIndexCase(input));
		_tableDeCoups.getCoup(-1 + _tableDeCoups.getArraySize())->setCaseDepart(&(_casesDamier[_getIndexCase(input)]));

		affiche();

		return _caseDepartValide(input);
	}

	bool Plateau::_caseArriveeValide(const Input& input) ///  ICI...
	{
		bool isArriveeValide = false;

		if (! _isCaseOccupee(input))
		{
			switch (int countOfGapBetweenCells = _tableDeCoups.getCoup(-1 + _tableDeCoups.getArraySize())->getCaseDepart()->countOfGapCells(_casesDamier[_getIndexCase(input)]))
			{
			case DUMMY_GAPS: // not on the same diagonal : then false !
				std::cout << "......no gap [" << countOfGapBetweenCells << "].not on the same diag..!.........\n";
				break;
			case 0: // the 2 cells are the same : then false
				std::cout << "......no gap [" << countOfGapBetweenCells << "]....dummy move........\n";
				break;
			case -1: // Mouvement descendant - r��valuer selon la promotion et le sens du jeu ::ICI::TODO::
				if (   _joueurEnCours->getSensDuDeplacement() == SensDuDeplacement::negatif
					|| _tableDeCoups.getCoup(-1 + _tableDeCoups.getArraySize())->getCaseDepart()->getPion()->isAqueen()
					)
				{
					isArriveeValide = true;
				}
				break;
			case 1:  // Mouvement montant - r��valuer selon la promotion et les sens du jeu ::ICI::TODO::
				if (   _joueurEnCours->getSensDuDeplacement() == SensDuDeplacement::positif
					|| _tableDeCoups.getCoup(-1 + _tableDeCoups.getArraySize())->getCaseDepart()->getPion()->isAqueen()
					)
				{
					isArriveeValide = true;
				}
				break;
			default: // there is a gap + cells on the same diagonal
				std::cout << "......gap of [" << countOfGapBetweenCells << "].cell(s)...........\n";
				break;
			}
		}

		return isArriveeValide;  ///  ICI...

		if (_tableDeCoups.getCoup(-1 + _tableDeCoups.getArraySize())->getCaseDepart()->getPion()->isAqueen());
		
		return isArriveeValide;
	}
}

namespace spc_dames
{
	void Plateau::_setSelectionneCase(const unsigned int& index)
	{
		if (index > 0 && index < NB_CASES_PLATEAU) // Ce n'est pas une case blanche
		{
			_casesDamier[index].setSurbrillance();
			memcpy(_casesDamier[index].getCellule()->motif, "///", 3);
			_casesDamier[index].getCellule()->motif[1] = (_casesDamier[index].estLibre() ? '/' : ((_casesDamier[index]).getPion()->getCouleur() == CouleurPion::blanc ? 'o' : 'x'));
		}
	}
}

namespace spc_dames
{
	void Plateau::affiche(void)
	{
		for (int iCase = 1; iCase < NB_CASES_PLATEAU; ++iCase)
		{
			_casesDamier[iCase].setCellule();
		}

		std::memcpy(&_cellulesEnqueue[4][1], (_joueurEnCours->getCouleur() == CouleurPion::blanc ? "BLANCS" : "NOIRS"), 6) ;

		std::cout
			<< _cellulesEntete[0][0].motif << std::endl
			<< _cellules[0][0].motif << std::endl
			<< _cellulesEnqueue[0][0].motif << std::endl
			;
	}

	bool Plateau::coupSuivant(void)
	{
		_abandon = false;

		return _coup();
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

