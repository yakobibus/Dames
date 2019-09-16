// plateau.h

# ifndef _PLATEAU_H_
# define _PLATEAU_H_ (1)

# include "damier.h"

namespace spc_dames
{
	class Plateau
	{
	public:
		void afficher (void);
	private:
		Damier _damier;
	};
}

# endif  // _PLATEAU_H_
