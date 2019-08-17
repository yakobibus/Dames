// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# ifndef _PLATEAU_H_
# define _PLATEAU_H_ (1)

# include <iostream>
# include <cstring>
# include "constantes.h"
# include "commonServices.h"
# include "caseDamier.h"
# include "regles.h"

namespace spc_dames
{
	class Cellule;
	class Coordonnees;
	class CaseDamier;
	class Diagonale;
	//class Joueur;
	//class Pion;
	//
	class Coup;
	class TableDeCoups;
	class Input;
	class Joueur;
	class Pion;
	class Plateau;
}


namespace spc_dames
{
	class Coup
	{
	public :
		Coup() : _arrivee(nullptr), _depart(nullptr), _casesDeTransit(nullptr), _nbCasesDeTransit(0), _joueur(nullptr), _valide(false) {}
		~Coup();
		Coup(Coup& c) ;
		Coup& operator = (Coup& c);
		//
		void        addCaseDeTransit(CaseDamier* caseDamier);
		CaseDamier* getCaseArrivee(void) { return _arrivee; }
		CaseDamier* getCaseDepart(void) { return _depart; }
		void        set(CaseDamier* depart, CaseDamier* arrivee, CaseDamier* transit, unsigned int szTransit, Joueur* joueur, bool valide);
		void        setCaseArrivee(CaseDamier* caseArrivee) { _arrivee = caseArrivee; }
		void        setCaseDepart(CaseDamier* caseDepart) { _depart = caseDepart; }
		void        raz(void);
	private :
		CaseDamier*  _arrivee;
		CaseDamier*  _depart;
		CaseDamier* _casesDeTransit;
		unsigned int _nbCasesDeTransit;
		Joueur*      _joueur;
		bool         _valide;
	};

	class TableDeCoups
	{
	public :
		TableDeCoups() : _array(nullptr), _arraySize(0), _arrayMaxSize(NB_DE_COUPS_PAR_LOT) { _array = new Coup*[NB_DE_COUPS_PAR_LOT]; }
		~TableDeCoups() { delete[] _array; _array = nullptr; _arraySize = 0; _arrayMaxSize = NB_DE_COUPS_PAR_LOT; }
		TableDeCoups(const TableDeCoups& c);
		TableDeCoups& operator = (const TableDeCoups& c);
		//
		//void ajouterCoup(Coup* coup);
		const unsigned int& ajouterNouveauCoup(void);
		unsigned int getArraySize(void) const { return _arraySize; }
		Coup* getCoup(const unsigned int& position) { return (position >= 0 && position < _arraySize ? _array[position] : nullptr) ; }
	private :
		Coup**       _array;
		unsigned int _arraySize;
		unsigned int _arrayMaxSize;
	};

	class Input
	{
	public :
		Input();
		~Input() = default;
		Input(const Input& i) = default;
		Input& operator = (const Input& i) = default;
		//
		const Coordonnees& getCoordonnees(void) const { return _coordonnees; }
		InputType    getInputType(void) const { return _inputType; }
		unsigned int getX(void) const { return _coordonnees.getX(); }
		unsigned int getY(void) const { return _coordonnees.getY(); }
		bool isValid(void) const { return _isValid; }
		void saisie(const char* invite);
	private :
		char               _buffer[INPUT_BUFFER_MX_SIZE];
		unsigned int       _bufSize;
		Coordonnees        _coordonnees;
		InputType          _inputType;
		bool               _isValid;
		void               _isValidInput(void);
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
		const CouleurPion& getCouleur(void) const { return _couleur; }
		const IdJoueur& getId(void) const { return _id; }
		const SensDuDeplacement& getSensDuDeplacement(void) const { return _sensDuDeplacement; }
		void init(
			  const IdJoueur& id
			, const CouleurPion& couleur
			, const char* nom
			, const SensDuDeplacement& sensDuDeplacement
			, const NatureJoueur& nature = NatureJoueur::humain
		    );
		const char* const getNom(void) const { return _nom; }
		const unsigned short getSzNom(void) const { return _szNom; }
		//void setId(const IdJoueur& id);
		//void setNom(const char* nom);
	private :
		IdJoueur          _id;
		CouleurPion       _couleur;
		NatureJoueur      _nature;
		char*             _nom;
		unsigned short    _szNom;
		SensDuDeplacement _sensDuDeplacement;
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
		const bool& getPromotion(void) const { return _promotion; }
		void init(CaseDamier* const cd, CouleurPion c, bool p = false);
		const bool& isAqueen(void) const { return _promotion; }
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
		CaseDamier              _casesDamier[NB_CASES_PLATEAU]; // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
		Cellule                 _cellules[NB_Y_REF_CELLULES][NB_X_REF_CELLULES] = MOTIF_PLATEAU_DAMIER;
		Cellule                 _cellulesEntete[NB_Y_REF_CELLULES_ENTETE][NB_X_REF_CELLULES] = MOTIF_TEXTE_ENTETE;
		Cellule                 _cellulesEnqueue[NB_Y_REF_CELLULES_ENQUEUE][NB_X_REF_CELLULES] = MOTIF_TEXTE_ENQUEUE;
		CouleurPion             _couleurPionsNord; // = CouleurPion::null;
		CouleurPion             _couleurPionsSud; // = CouleurPion::null;
		Diagonale               _diagonales[NB_DIAGONALES_PLATEAU];
        Joueur*                 _joueurEnCours; 
		Joueur                  _joueurNord;
		Joueur                  _joueurSud;
		Pion                    _pionsBlancs[NB_PIONS_PAR_COULEUR];
		Pion                    _pionsNoirs[NB_PIONS_PAR_COULEUR];
		Pion* const             _pionsNord = nullptr;
		Pion* const             _pionsSud = nullptr;
		PositionsCouleursDepart _positionsDeDepart;
		TableDeCoups            _tableDeCoups;
		//
		bool                    _caseArriveeValide(const Input& input);
		bool                    _caseDepartValide(const Input& input) { return _isCaseOccupeePionCouleurJoueurEnCours(input); }
		bool                    _coup(void);
		bool                    _coupArrivee(Input& input);
		bool                    _coupDepart(Input& input);
		const CaseDamier&       _getCase(const unsigned int& indx) const { return _casesDamier[indx]; }
		CouleurPion             _getCouleurJoueurEnCours(void) const { return _joueurEnCours->getCouleur(); }
		unsigned int            _getIndexCase(const Input& input) const;
		bool                    _isCaseNoire(const Input& input) const { return (_getIndexCase(input) == 0 ? false : true); }
		bool                    _isCaseOccupee(const Input& input) const { return _casesDamier[_getIndexCase(input)].getPion() != nullptr ; }
		bool                    _isCaseOccupeePionCouleurJoueurEnCours(const Input& input) { return ((_isCaseOccupee(input) && _isCaseNoire(input)) ? (_getCouleurJoueurEnCours() == (_casesDamier[_getIndexCase(input)].getPion()->getCouleur()) ? true : false) : false); }
		//bool                    _isCaseNoire(unsigned int& y, unsigned int& x) const { return (_getIndexCase(y, x) == 0 ? false : true); }
		//bool                    _isDiagonally(const CaseDamier& caseDamier);
		void                    _setSelectionneCase(const unsigned int& index);
	};
}

# endif // _PLATEAU_H_
