// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# ifndef _PLATEAU_H_
# define _PLATEAU_H_ (1)

# include "constantes.h"

namespace spc_plateau
{
	class Pion;
}

namespace spc_plateau
{
	enum class ApparenceCase : unsigned int
	{
		normal = 0,
		surbillance = 1
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
		CaseDamier() = default;
		~CaseDamier() = default;
		CaseDamier(const CaseDamier& c) = default;
		CaseDamier& operator = (const CaseDamier& c) = default;
		//
		void affiche(void);
		void init(int x, int y, int notation, Pion* pion, ApparenceCase apparence, CouleurCaseDamier couleurCase, CouleurPion couleurPion);
	private:
		ApparenceCase     _apparence;
		bool              _estLibre;
		unsigned int      _notationOfficielle;
		Pion*             _pion;
		unsigned int      _x;
		unsigned int      _y;
		CouleurCaseDamier _couleur;
	};

	class Pion
	{
	public:
		Pion() : _x(0), _y(0), _couleur(CouleurPion::null), _promotion(false) { std::cout << "Pion.Ctor()\n"; }
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
		//
		CouleurPion couleur(void);
		void init(int x, int y, CouleurPion c, bool p = false);
	private:
		unsigned int _x;
		unsigned int _y;
		CouleurPion _couleur;
		bool _promotion ;
	};

	class Plateau
	{
	public :
		Plateau(PositionsCouleursDepart positionsDepart = PositionsCouleursDepart::noirs_blancs) ;
		~Plateau() = default;
		Plateau(const Plateau& p) = default;
		Plateau& operator = (const Plateau& p) = default;
		//
		void affiche(void);
	private :
		CaseDamier              _casesDamier[NB_CASES_PLATEAU]; // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
		Pion*                   _pionsNord = nullptr ;
		Pion*                   _pionsSud  = nullptr ;
		CouleurPion             _couleurPionsNord = CouleurPion::null;
		CouleurPion             _couleurPionsSud = CouleurPion::null;
		Pion                    _pionsBlancs[NB_PIONS_PAR_COULEUR];
		Pion                    _pionsNoirs[NB_PIONS_PAR_COULEUR];
		PositionsCouleursDepart _positionsDeDepart;
	};
}

# endif // _PLATEAU_H_
