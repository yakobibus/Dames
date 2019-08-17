// caseDamier.h

# ifndef _CASE_DAMIER_H_
# define _CASE_DAMIER_H_ (1)


# include "commonServices.h"
# include "constantes.h"
# include "diagonale.h"
# include "pion.h"

using spc_commonServices::ApparenceCase;
using spc_commonServices::CouleurCaseDamier;
using spc_diagonale::Diagonale;

namespace spc_pion
{
	class Pion;
}

namespace spc_cellule
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

	class Coordonnees
	{
	public:
		Coordonnees() : _x(0), _y(0) {}
		Coordonnees(unsigned int y, unsigned x) : _x(x), _y(y) {}
		~Coordonnees() = default;
		Coordonnees(const Coordonnees& c) = default;
		Coordonnees& operator = (const Coordonnees& c) = default;
		// ---
		void set(unsigned int y, unsigned int x) { _y = y; _x = x; }
		Coordonnees& get(void) { return *this; }
		unsigned int getX(void) const { return _x; }
		unsigned int getY(void) const { return _y; }
		char         getXalpha(void) const { return 'a' + _x - 1; }
	private:
		unsigned _x;
		unsigned _y;
	};
}

namespace spc_caseDamier
{
	using spc_pion::Pion;
	// -- 

	class CaseDamier
	{
	public:
		CaseDamier();
		~CaseDamier() = default;
		CaseDamier(const CaseDamier& c) = default;
		CaseDamier& operator = (const CaseDamier& c) = default;
		bool operator == (const CaseDamier& c) const { return (this == &c ? true : (c._coordonnees.getX() == _coordonnees.getX() && c._coordonnees.getY() == _coordonnees.getY() ? true : false)); }
		void affiche(void);
		int  countOfGapCells(const CaseDamier& caseDamier) const;
		bool estLibre(void) const { return _estLibre; }
		void init(const spc_cellule::Coordonnees& coordonnees, int notation, Pion* pion, ApparenceCase apparence, CouleurCaseDamier couleurCase); //  , CouleurPion couleurPion);
		int getX(void) const { return _coordonnees.getX(); }
		char getXalpha(void) const { return _coordonnees.getXalpha(); }
		int getY(void) const { return _coordonnees.getY(); }
		Pion* getPion(void) { return _pion; }
		spc_cellule::Cellule* getCellule(void) const { return _cellule; }
		bool isContiguous(const CaseDamier& caseDamier) const;
		bool isDiagonally(const CaseDamier& caseDamier) const;
		void setPion(Pion* p) { _pion = p; _estLibre = (_pion == nullptr ? true : false); }
		void setCellule(spc_cellule::Cellule* c) { _cellule = c; }
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
		spc_cellule::Cellule* _cellule;
		Coordonnees       _coordonnees;
		CouleurCaseDamier _couleur;
		const Diagonale* _diagonale[NB_DIAGONALES_MAX_PAR_CASE];
		bool              _estLibre;
		unsigned int      _nbDiagonales;
		unsigned int      _notationOfficielle;
		Pion* _pion;
	};
}


# endif // _CASE_DAMIER_H_
