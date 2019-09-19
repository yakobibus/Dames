// damier.h

# ifndef _DAMIER_H_
# define _DAMIER_H_ (1)

# include <vector>
# include "ardoise.h"
# include "constantes.h"

namespace spc_dames
{
	class Damier
	{
	public:
		Damier(ePlacementJoueurs placement) : _ardoise(_placementDesJoueurs),  _placementDesJoueurs(placement) {}
		~Damier() = default;
		Damier(const Damier& d) = default;
		Damier& operator = (const Damier& d) = default;
		void afficher(void);
		//
	private:
		Ardoise _ardoise;
		ePlacementJoueurs& _placementDesJoueurs;
	};
}

# endif  // _DAMIER_H_
