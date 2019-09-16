// cellule.h

# ifndef _CELLULE_H_
# define _CELLULE_H_ (1)

# include <cstring>

# include "constantes.h"
# include "coordonnees.h"

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
		void setCoordonnees(const unsigned int& y, const unsigned int& x, const unsigned int& m, char* const mtf) { _coordonnees.set(y, x, m, mtf); }
		char* const getMotif(void) const { return _coordonnees.getMotif(); }
		void setMotif(const char& c) { _coordonnees.setMotif(c); }
	private:
		Coordonnees _coordonnees;
	};
}

namespace spc_dames
{
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
}

# endif  // _CELLULE_H_
