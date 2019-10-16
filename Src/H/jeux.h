// jeux.h

# ifndef _JEUX_H_
# define _JEUX_H_ (1)

# include "damier.h"
# include "joueur.h"

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
		ePlacementJoueurs   _placementDesJoueurs;
		std::vector<Joueur> _joueurs;
		Damier _damier;
	};
}

# endif  // _JEUX_H_
