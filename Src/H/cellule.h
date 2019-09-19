// cellule.h

# ifndef _CELLULE_H_
# define _CELLULE_H_ (1)

# include <cstring>

# include "constantes.h"
# include "coordonnees.h"
# include "pion.h"


namespace spc_dames
{
	enum class eDetailMotif
	{
		  normal = DETAIL_MOTIF_NORMAL
		, bold   = DETAIL_MOTIF_BOLD
	};

	enum class eStatutDeLaCellule
	{
		  libre
		, prise
	};

	class Motif
	{
	public:
		Motif() : _motif(nullptr) {}
		~Motif() = default;
		Motif(const Motif& m) = default;
		Motif& operator = (const Motif& m) = default;
		//
		void set(char* const mtf) { _motif = mtf; memset(_motif, static_cast<char>(eDetailMotif::normal), TAILLE_CELLULE); }
	private :
		char* _motif;
	};
}

namespace spc_dames
{
	class Cellule
	{
		/*
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** de ligne/colonne, une case du damier, ... Elle s'étend donc au delà de la zone de jeu
		**/
	public:
		Cellule() : _pion(nullptr), _motif(), _statut(eStatutDeLaCellule::libre) {}
		~Cellule() = default;
		Cellule(const Cellule& c) = default;
		Cellule& operator = (const Cellule& c) = default;
		void setCoordonnees(const unsigned int& y, const unsigned int& x, const unsigned int& m, char* const mtf) { _coordonnees.set(y, x, m, mtf); _motif.set(mtf); }
		char* const getMotif(void) const { return _coordonnees.getMotif(); }
	private:
		Coordonnees _coordonnees ;
		Pion*       _pion ;
		Motif       _motif;
		eStatutDeLaCellule _statut; // libre ou occupee
	};
}


//namespace spc_dames
//{
	/*
	class Cellule
	{
	public :
		Cellule() : _separateur(0) { memset(_motif, 0, TAILLE_CELLULE); }
		~Cellule() = default;
		Cellule(const Cellule& c) = default;
		Cellule& operator = (const Cellule& c) = default;
		const char* motif(void) const { return _motif; }
		const char& separateur(void) const { return _separateur; }
		void setMotif(const char* motif) { memcpy(_motif, motif, TAILLE_CELLULE); }
		void setSeparateur(const char& separateur) { _separateur = separateur; }
	private :
		char _motif[TAILLE_CELLULE];
		char _separateur;
	};
	*/
	/*
	class CaseDamier
	{
	public:
		void afficher(void);
		void setOccupe(void) { _cellule.setMotif("/+/\0"); _cellule.setSeparateur('|'); }
		void setLibre(void) { _cellule.setMotif( "///\0" ); _cellule.setSeparateur('|'); }
	private:
		Cellule     _cellule; // ICI : des references sur une case de l'ardoise
		Coordonnees _coordonnees;
	};
	*/
	/*
	enum class eMotifCellule
	{
		  normal
		, bold
		//
		, normalPionBlanc
		, normalPionNoir
		, normalPromoPionBlanc
		, normalPromoPionNoir
		//
		, boldPionBlanc
		, boldPionNoir
		, boldPromoPionBlanc
		, boldPromoPionNoir
	};

	class Motif
	{
	public :
		const char* const normal(void) const { return _normal; }
		const char* const motif(eMotifCellule m) const {
			return m == eMotifCellule::normal ? _normal
				: m == eMotifCellule::bold ? _bold
				: m == eMotifCellule::normalPionBlanc ? _normalPionBlanc
				: m == eMotifCellule::normalPionNoir ? _normalPionNoir
				: m == eMotifCellule::normalPromoPionBlanc ? _normalPromoPionBlanc
				: m == eMotifCellule::normalPromoPionNoir ? _normalPromoPionNoir
				: m == eMotifCellule::boldPionBlanc ? _boldPionBlanc
				: m == eMotifCellule::boldPionNoir ? _boldPionNoir
				: m == eMotifCellule::boldPromoPionBlanc ? _boldPromoPionBlanc
				: m == eMotifCellule::boldPromoPionNoir ? _boldPromoPionNoir
				: nullptr ;
		}
	private :
		const char _normal[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '/', '/', '/', 0 };
		const char _bold[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '\\', '\\', '\\', 0 };
		//
		const char _normalPionBlanc[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '/', static_cast<char>(eMotifDuPion::normalBlanc), '/', 0 };
		const char _normalPionNoir[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '/', static_cast<char>(eMotifDuPion::normalNoir), '/', 0 };
		const char _normalPromoPionBlanc[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '/', static_cast<char>(eMotifDuPion::promuBlanc), '/', 0 };
		const char _normalPromoPionNoir[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '/', static_cast<char>(eMotifDuPion::promuNoir), '/', 0 };
		//
		const char _boldPionBlanc[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '\\', static_cast<char>(eMotifDuPion::normalBlanc), '\\', 0 };
		const char _boldPionNoir[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '\\', static_cast<char>(eMotifDuPion::normalNoir), '\\', 0 };
		const char _boldPromoPionBlanc[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '\\', static_cast<char>(eMotifDuPion::promuBlanc), '\\', 0 };
		const char _boldPromoPionNoir[TAILLE_CELLULE + TAILLE_SEPARATEUR] = { '\\', static_cast<char>(eMotifDuPion::promuNoir), '\\', 0 };
	};
	*/
//}

# endif  // _CELLULE_H_
