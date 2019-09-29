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
		Damier(ePlacementJoueurs placement) : _placementDesJoueurs(placement), _ardoise(_placementDesJoueurs) {}
		~Damier() = default;
		Damier(const Damier& d) = default;
		Damier& operator = (const Damier& d) = default;
		void afficher(void);
		//
	private:
		ePlacementJoueurs& _placementDesJoueurs;
		Ardoise _ardoise;
	};
}

# endif  // _DAMIER_H_
