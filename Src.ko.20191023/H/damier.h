// damier.h

# ifndef _DAMIER_H_
# define _DAMIER_H_ (1)

# include <vector>
# include "ardoise.h"
# include "constantes.h"
# include "joueur.h"

namespace spc_dames
{
	class Damier
	{
	public:
		Damier(ePlacementJoueurs& placement, std::vector<Joueur>& joueurs, std::vector<std::vector<Pion>*> pions) : _placementDesJoueurs(placement), _joueurs(joueurs), _pionsPrts(pions), _ardoise(_placementDesJoueurs, _joueurs, _pionsPrts) {}
		~Damier() = default;
		Damier(const Damier& d) = default;
		Damier& operator = (const Damier& d) = default;
		void afficher(void);
		const std::string& nomJoueur(unsigned int indice) const { return _joueurs.at(indice).nom(); }
	private:
		ePlacementJoueurs& _placementDesJoueurs;
		std::vector<Joueur>& _joueurs;
		std::vector< std::vector<Pion>* > _pionsPrts;
		Ardoise _ardoise;
	};
}

# endif  // _DAMIER_H_
