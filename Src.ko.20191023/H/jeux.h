// jeux.h

# ifndef _JEUX_H_
# define _JEUX_H_ (1)

# include <vector>
# include "coup.h"
# include "damier.h"
# include "joueur.h"
# include "pion.h"

namespace spc_dames
{
	class Jeux
	{
	public :
		Jeux();
		~Jeux() = default;
		Jeux(const Jeux& j) = default;
		Jeux& operator= (const Jeux& j) = default;
		//
		bool jouer(void);
	private :
		ePlacementJoueurs                  _placementDesJoueurs;
		std::vector<Joueur>                _joueurs;
		std::vector<Pion>    _pionsBlancs;
		std::vector<Pion>    _pionsNoirs;
		std::vector< std::vector<Pion>* > _pionsPtrs; // = { _pionsBlancs, _pionsNoirs };
		Damier                             _damier;
		std::vector< std::vector<Coup> >   _coups;  // un coup peut être formé de coups (quand on saute + d'un pion)
		std::vector< std::vector<Pion>* > _pionsRefactoring;
		//
	};
}

# endif  // _JEUX_H_
