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
	enum class MotifCase : unsigned char
	{
		null = ' ',
		normal = ':',
		surbrillance = '/',
		blanc = 'o',
		noir = 'x',
		BLANC = 'O',
		NOIR = 'X'
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
	class Damier {
	public :
		void aff(void) { std::cout << _dada[0]._l << std::endl; }   // Meilleurs compromis au 20181016_1648
		void a(void) { std::cout << _casa[0][0]._z << std::endl; } // Sln Ko
		void setCasa(int y, int x, int i, char c) { _casa[y][x]._z[i] = c; }
		void setCasa(int y, int x, bool normal) { 
			const char terne[] = ":::"; 
			const char bold[] = "///"; 
			std::memcpy( &(_casa[y][x]._z[0]), (normal ? &terne[0] : &bold[0]), 3 );
		}
		void setCasa(int y, int x, CouleurPion c, bool promo)
		{
			const char b[] = " o "; 
			const char B[] = " O ";
			const char n[] = " x "; 
			const char N[] = " X ";
			std::memcpy(&(_casa[y][x]._z[0]), (promo ? (c==CouleurPion::blanc ? &B[0] : &N[0]) : (c == CouleurPion::blanc ? &b[0] : &n[0])), 3);
		}
	private :
		struct Dada { char _l[47]; char _c; };
		Dada _dada[23] = MOTIF_PLATEAU_DAMIER; // 48 caractères sur 23 lignes

		struct Casa { char _z[3]; char _c; };
		Casa _casa[23][12] = MOTIF_PLATEAU_DAMIER ; /// [23 * 12] = 1125 chars + 22 eol + 1 asciiNull = 1148 chars [1148]
	};

	class LeDamier
	{
	public :
		LeDamier() = default;
		~LeDamier() = default;
		LeDamier(const LeDamier& ld) = default;
		LeDamier& operator = (const LeDamier& ld) = default;
		void affiche(void) { std::cout << _ln._m[0]._mot << std::endl; }
		void setLn(int im, int ii, char c) { _ln._m[im]._mot[ii] = c; }
		void setLn(int ii, char c) { _m1._mot[ii] = c; }
	private :
		struct Mot { char _mot[3]; char _separator; };
		struct Ligne { Mot _mot[12]; }; 
		struct Surface { Ligne _ligne[23]; }; 
		//----
		//struct M { M() = default; ~M() = default; M(const M& m) = default; M& operator=(const M&m) = default; char _mot[2]; char _separator; };
		struct M { char _mot[3]; char _separator; };
		struct Ln { M _m[3]; };
		struct Sf {Ln _l[2]; };
		//
		Ln _ln =
		{
			{':', '1', ':', '|', '2', ':', '3', '|', ':', '4', '\0'}
		};

		M& _m0 = _ln._m[0]; /// ici
		M& _m1 = _ln._m[1];
		M& _m2 = _ln._m[2];
		//M& _tbl[3] = { _ln._m[0] , _ln._m[1] , _ln._m[2] };
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
		CaseDamier() : _apparence(ApparenceCase::null), _estLibre(true), _notationOfficielle(0), _pion(nullptr), _x(0), _y(0), _couleur(CouleurCaseDamier::null) {}
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
		Pion() : _case(nullptr), _couleur(CouleurPion::null), _promotion(false) {} // { std::cout << "Pion.Ctor(" << (_couleur == CouleurPion::null ? "NilColor" : "Oups") << ")\n"; }
		~Pion() = default;
		Pion(const Pion& p) = default;
		Pion& operator = (const Pion& p) = default;
		//
		CouleurPion couleur(void);
		//friend std::ostream& operator<< (std::ostream& os, const Pion& p) { return os; } 
		//{ 
			//os << "("<<p._y<<","<<p._x<<"{"<<(p._couleur==CouleurPion::blanc?"White":(p._couleur==CouleurPion::noir?"Black"
			//:(p._couleur==CouleurPion::null?"NillColor":"Curious")))<<"}"<<")"; 
			//os << (p._couleur == CouleurPion::null ? "White" : ";;;");// (p._couleur == CouleurPion::noir ? "Black" : (p._couleur == CouleurPion::null ? "NillColor" : "Curious")));
			//os << _x;
		    //return os; 
		//}
		void init(CaseDamier* const cd, CouleurPion c, bool p = false);
		void setCase(CaseDamier* c);
	private:
		CaseDamier* _case;
		CouleurPion _couleur;
		bool _promotion ;
	};

	class Plateau
	{
	private :
		//
		/* Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** de ligne/colonne, une case du damier, ... Elle s'étend donc au delà de la zone de jeu
		**/
		struct Cellule { char motif[3]; char separateur; };
	public :
		Plateau(PositionsCouleursDepart positionsDepart = PositionsCouleursDepart::blancs_noirs) ;
		~Plateau() = default;
		Plateau(const Plateau& p) = default;
		Plateau& operator = (const Plateau& p) = default;
		//
		void affiche(void);
		void initPions(Pion* const pions, CaseDamier* const cases, CouleurPion& couleur);
	private :
		Cellule _Cellules[23][12] = MOTIF_PLATEAU_DAMIER; /// [23 * 12] cellules = 1125 chars + 22 eol + 1 asciiNull = 1148 chars [1148]
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
