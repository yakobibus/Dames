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
		//unsigned int joueurEnCours(void) { return static_cast<unsigned int> (_joueurEnCours); }
		void alterneJoueurEnCours(void) { _joueurEnCours = (_joueurEnCours == eJoueurEnCours::nord ? eJoueurEnCours::sud : eJoueurEnCours::nord); }
	private :
		ePlacementJoueurs                  _placementDesJoueurs;
		std::vector<Joueur>                _joueurs;
		eJoueurEnCours                     _joueurEnCours;  //  ce sont toujours les BLANCS qui commencent
		std::vector<Pion>                  _pionsBlancs;
		std::vector<Pion>                  _pionsNoirs;
		Damier                             _damier;
		std::vector< std::vector<Coup> >   _coups;  // un coup peut être formé de coups (quand on saute + d'un pion)
	} ;
}

# endif  // _JEUX_H_
