// ardoise.h

# ifndef _ARDOISE_H_
# define _ARDOISE_H_ (1)

# include <iostream>
# include <vector>
# include "constantes.h"
# include "cellule.h"

namespace spc_dames
{
	class Ardoise
	{
	public :
		Ardoise(); 
		~Ardoise() = default;
		Ardoise(const Ardoise& a) = default;
		Ardoise& operator = (const Ardoise& a) = default;
		//
		void afficher(void) { std::cout << _ardoise ; }
		const char* const ardoise(void) const { return _ardoise; }
	private :
		char _ardoise[NB_X_REF_CELLULES * NB_Y_REF_CELLULES * (TAILLE_CELLULE + TAILLE_SEPARATEUR)] = MOTIF_PLATEAU_DAMIER;
		std::vector<Cellule> _cellule;
		//
		const unsigned int decalage(const unsigned int& y) const { return (y == 10 ? 2 : y == 9 ? 4 : y == 8 ? 6 : y == 7 ? 8 : y == 6 ? 10 : y == 5 ? 12 : y == 4 ? 14 : y == 3 ? 16 : y == 2 ? 18 : y == 1 ? 20 : 0); }
		void setMotif(const unsigned int& manoury, const char& c) { _cellule[-1 + manoury].setMotif(c); }
	};
}

# endif // _ARDOISE_H_
