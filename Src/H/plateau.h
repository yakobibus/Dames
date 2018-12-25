// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# ifndef _PLATEAU_H_
# define _PLATEAU_H_ (1)

# include <iostream>
# include <cstring>
# include "constantes.h"

namespace spc_plateau
{
	class Diagonale;
	class Pion;
}

namespace spc_plateau
{
	enum class ApparenceCase : unsigned int
	{
		null = 0,
		normal = 1,
		surbillance = 2
	};

	enum class CouleurCaseDamier : unsigned int
	{
		null = 0,
		blanc = 1,
		noir = 2
	};

	enum class CouleurPion : unsigned int
	{
		null = 0,
		blanc = 1,
		noir = 2
	};

	enum class InputType
	{
		  is_undefined = 0
		, is_digitOne = 1     // a legal digit on _buffer[0]
		, is_digitTwo = 2     // a legal digit on _buffer[1]
		, is_digitOneTwo = 3  // legal digits on _buffer[1 and 2]
		, is_digitThree = 4   // a legal digit on _buffer[2]
		, is_alphaOne = 8     // a legal char on _buffer[0]
		, is_alphaOneDigitTwo = 10
		, is_alphaOnedigitTwoThree = 14
		, is_alphaTwo = 16    // a legal char on _buffer[1]
		, is_digitOneAlphaTwo = 17
		, is_alphaThree = 32  // a legal char on _buffer[2]
		, is_digitOneTwoAlphaThree = 35
		, is_nullTwo = 64     // no char on _buffer[1]
		, is_nullThree = 128  // no char on _buffer[2]
		, is_exiting = 256    // an exit token in the buffer
		, is_error = 512      // No legal char combination in the buffer
	};

	enum class IdJoueur
	{
		  undefined = 0
		, premier = 1
		, second = 2
	};

	enum class NatureJoueur
	{
		  undefined = 0
		, humain    = 1
		, ia        = 2
	};

	enum class PositionsCouleursDepart : unsigned int
	{
		blancs_noirs = 0, // les blancs (cases 1 � 20) puis les noirs (cases 31 � 50)
		noirs_blancs = 1  // les noirs (cases 1 � 20) puis les blancs (cases 31 � 50)
	};
}

namespace spc_plateau
{
	struct Cellule 
	{
		/* 
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau o� figure un motif : r�f�rence
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau o� figure un motif : r�f�rence
		** de ligne/colonne, une case du damier, ... Elle s'�tend donc au del� de la zone de jeu
		**/
		char motif[TAILLE_CELLULE];
		char separateur;
	};
}

namespace spc_plateau
{
	class Regle
	{
	public:
		Regle() = default;
		~Regle() = default;
		Regle(const Regle& r) = default;
		Regle& operator = (const Regle& r) = default;
	private:
	};
}

namespace spc_plateau
{
	class CaseDamier
	{
	public:
		CaseDamier();
		~CaseDamier() = default;
		CaseDamier(const CaseDamier& c) = default;
		CaseDamier& operator = (const CaseDamier& c) = default;
		//
		void affiche(void);
		bool estLibre(void) const { return _estLibre; }
		void init(int x, int y, int notation, Pion* pion, ApparenceCase apparence, CouleurCaseDamier couleurCase); //  , CouleurPion couleurPion);
		int getX(void) { return _x; }
		int getY(void) { return _y; }
		Pion* getPion(void) { return _pion; }
		Cellule* getCellule(void) const { return _cellule; }
		void setPion(Pion* p) { _pion = p; _estLibre = (_pion == nullptr ? true : false);}
		void setCellule(Cellule* c) { _cellule = c; }
		void setCellule(void);
		//
		void setDiagonale(const Diagonale* diagonale);
		const Diagonale* getDiagonale(int i) const { return _diagonale[i]; }
		const Pion* getPion(void) const { return _pion; }
		unsigned int getNbDiagonales(void) const { return _nbDiagonales; }
		void setNormale(void) { _apparence = ApparenceCase::normal; }
		void setSurbrillance(void) { _apparence = ApparenceCase::surbillance; }
	private:
		ApparenceCase     _apparence;
		Cellule*          _cellule;
		CouleurCaseDamier _couleur;
		const Diagonale*  _diagonale[NB_DIAGONALES_MAX_PAR_CASE];
		bool              _estLibre;
		unsigned int      _nbDiagonales;
		unsigned int      _notationOfficielle;
		Pion*             _pion;
		unsigned int      _x;
		unsigned int      _y;
	};

	class Diagonale
	{
	public:
		Diagonale() : _casesDamier(nullptr), _numero(0), _taille(0) {}
		~Diagonale();
		Diagonale(const Diagonale& d);
		Diagonale& operator = (const Diagonale& d);
		//
		int addCase(CaseDamier* c);
		int getNumero(void) const { return _numero; }
		int init(int taille, CaseDamier** c, int numero);
	private:
		CaseDamier** _casesDamier;
		unsigned int _numero;
		unsigned int _taille;
	};

	class Input
	{
	public :
		Input();
		~Input() = default;
		Input(const Input& i) = default;
		Input& operator = (const Input& i) = default;
		//
		InputType    getInputType(void) const { return _inputType; }
		unsigned int getX(void) const { return _x; }
		unsigned int getY(void) const { return _y; }
		bool isValid(void) const { return _isValid; }
		void saisie(const char* invite);
	private :
		char               _buffer[INPUT_BUFFER_MX_SIZE];
		unsigned int       _bufSize;
		//const CaseDamier*  _caseDamier;
		InputType          _inputType;
		bool               _isValid;
		void               _isValidInput(void);
		unsigned int _x;
		unsigned int _y;
		//
		inline unsigned int _aToColumn(const char& colonne) const {
			return (
				  colonne == 'a' || colonne == 'A' ? 1
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
				);
		}
		inline unsigned int _aToLine(const char* s, std::size_t offset = 0) const { return std::stoi(s, &offset); }
		inline bool _isAlpha(const char& c) const { return IS_ALPHA_DAMIER(c); }
		inline bool _isDigit(const char& c) const { return IS_DIGIT_DAMIER(c); }
	};

	class Joueur
	{
	public :
		Joueur();
		~Joueur();
		Joueur(const Joueur& j);
		Joueur& operator = (const Joueur& j);
		//
		CouleurPion getCouleur(void) const { return _couleur; }
		const IdJoueur& getId(void) const { return _id; }
		void init(const IdJoueur& id, const CouleurPion& couleur, const char* nom, const NatureJoueur& nature = NatureJoueur::humain);
		const char* const getNom(void) const { return _nom; }
		const unsigned short getSzNom(void) const { return _szNom; }
		//void setId(const IdJoueur& id);
		//void setNom(const char* nom);
	private :
		IdJoueur     _id;
		CouleurPion  _couleur;
		NatureJoueur _nature;
		char*        _nom;
		unsigned short _szNom;
	};

	class Pion
	{
	public:
		Pion() : _case(nullptr), _couleur(CouleurPion::null), _promotion(false) {} 
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
		//
		CouleurPion getCouleur(void) { return _couleur; }
		bool getPromotion(void) { return _promotion; }
		void init(CaseDamier* const cd, CouleurPion c, bool p = false);
		void setCase(CaseDamier* c);
	private:
		CaseDamier* _case;
		CouleurPion _couleur;
		bool _promotion ;
	};

	class Plateau
	{
	public :
		Plateau(PositionsCouleursDepart positionsDepart = PositionsCouleursDepart::noirs_blancs) ;
		~Plateau() = default;
		Plateau(const Plateau& p) ;
		Plateau& operator = (const Plateau& p) ;
		//
		void affiche(void) ;
		bool coupSuivant(void);
		//CaseDamier* getCaseDamier(unsigned int y, unsigned int x);
		bool getAbandon(void) const { return _abandon; }
		void initDiagonales(void);
		void initPions(Pion* const pions, CaseDamier* const cases, CouleurPion& couleur);
	private :
		bool                    _abandon ;
		CaseDamier              _casesDamier[NB_CASES_PLATEAU]; // 50 cases noires num�rot�es de 01 � 50 ; la case 00 est blanche ; le num�ro de la case correspond � son indice
		Cellule                 _cellules[NB_Y_REF_CELLULES][NB_X_REF_CELLULES] = MOTIF_PLATEAU_DAMIER;
		Cellule                 _cellulesEntete[NB_Y_REF_CELLULES_ENTETE][NB_X_REF_CELLULES] = MOTIF_TEXTE_ENTETE;
		Cellule                 _cellulesEnqueue[NB_Y_REF_CELLULES_ENQUEUE][NB_X_REF_CELLULES] = MOTIF_TEXTE_ENQUEUE;
		CouleurPion             _couleurPionsNord; // = CouleurPion::null;
		CouleurPion             _couleurPionsSud; // = CouleurPion::null;
		Diagonale               _diagonales[NB_DIAGONALES_PLATEAU];
		Input                   _input;
        Joueur*                 _joueurEnCours; 
		Joueur                  _joueurNord;
		Joueur                  _joueurSud;
		short                   _nombreTotalDeCoups;
		Pion                    _pionsBlancs[NB_PIONS_PAR_COULEUR];
		Pion                    _pionsNoirs[NB_PIONS_PAR_COULEUR];
		Pion* const             _pionsNord = nullptr;
		Pion* const             _pionsSud = nullptr;
		PositionsCouleursDepart _positionsDeDepart;
		//
		bool                    _caseArriveeValide(void);
		bool                    _caseDepartValide(void) { return _isCaseOccupeePionCouleurJoueurEnCours(); }
		bool                    _coupArrivee(void);
		bool                    _coupDepart(void);
		CouleurPion             _getCouleurJoueurEnCours(void) const { return _joueurEnCours->getCouleur(); }
		unsigned int            _getIndexCase(void) const;
		//unsigned int            _getIndexCase(unsigned int& y, unsigned int& x) const;
		bool                    _isCaseNoire(void) const { return (_getIndexCase() == 0 ? false : true); }
		bool                    _isCaseOccupee(void) const { return _casesDamier[_getIndexCase()].getPion() != nullptr ; }
		bool                    _isCaseOccupeePionCouleurJoueurEnCours(void) { return ((_isCaseOccupee() && _isCaseNoire()) ? (_getCouleurJoueurEnCours() == (_casesDamier[_getIndexCase()].getPion()->getCouleur()) ? true : false) : false); }
		//bool                    _isCaseNoire(unsigned int& y, unsigned int& x) const { return (_getIndexCase(y, x) == 0 ? false : true); }
		void                    _setSelectionneCase(const unsigned int& index);
	};
}

# endif // _PLATEAU_H_
