// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# ifndef _PLATEAU_H_
# define _PLATEAU_H_ (1)

# include <iostream>
# include <cstring>
# include "constantes.h"

namespace spc_plateau
{
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

	enum class PositionsCouleursDepart : unsigned int
	{
		blancs_noirs = 0, // les blancs (cases 1 à 20) puis les noirs (cases 31 à 50)
		noirs_blancs = 1  // les noirs (cases 1 à 20) puis les blancs (cases 31 à 50)
	};
}

namespace spc_plateau
{
	struct Cellule 
	{
		/* 
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** de ligne/colonne, une case du damier, ... Elle s'étend donc au delà de la zone de jeu
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
		CaseDamier() : _apparence(ApparenceCase::normal), _estLibre(true), _notationOfficielle(0), _pion(nullptr), _cellule(nullptr), _x(0), _y(0), _couleur(CouleurCaseDamier::null) {}
		~CaseDamier() = default;
		CaseDamier(const CaseDamier& c) = default;
		CaseDamier& operator = (const CaseDamier& c) = default;
		//
		void affiche(void);
		void init(int x, int y, int notation, Pion* pion, ApparenceCase apparence, CouleurCaseDamier couleurCase); //  , CouleurPion couleurPion);
		int getX(void) { return _x; }
		int getY(void) { return _y; }
		Pion* getPion(void) { return _pion; }
		void setPion(Pion* p) { _pion = p; _estLibre = (_pion == nullptr ? true : false);}
		void setCellule(Cellule* c) { _cellule = c; }
		void setCellule(void);
	private:
		ApparenceCase     _apparence;
		bool              _estLibre;
		unsigned int      _notationOfficielle;
		Pion*             _pion;
		Cellule*          _cellule;
		unsigned int      _x;
		unsigned int      _y;
		CouleurCaseDamier _couleur;
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
		Plateau(PositionsCouleursDepart positionsDepart = PositionsCouleursDepart::blancs_noirs) ;
		~Plateau() = default;
		Plateau(const Plateau& p) = default;
		Plateau& operator = (const Plateau& p) = default;
		//
		void affiche(void);
		void initPions(Pion* const pions, CaseDamier* const cases, CouleurPion& couleur);
	private :
		Cellule _cellules[23][12] = MOTIF_PLATEAU_DAMIER; /// [23 * 12] cellules = 1125 chars + 22 eol + 1 asciiNull = 1148 chars [1148]
		//
		CaseDamier              _casesDamier[NB_CASES_PLATEAU]; // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
		CouleurPion             _couleurPionsNord = CouleurPion::null;
		CouleurPion             _couleurPionsSud = CouleurPion::null;
		Pion                    _pionsBlancs[NB_PIONS_PAR_COULEUR];
		Pion                    _pionsNoirs[NB_PIONS_PAR_COULEUR];
		Pion* const             _pionsNord = nullptr;
		Pion* const             _pionsSud = nullptr;
		PositionsCouleursDepart _positionsDeDepart;
	};
}

# endif // _PLATEAU_H_
