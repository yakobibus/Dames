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
		Damier(ePlacementJoueurs& placement, eJoueurEnCours& joueurEnCours, std::vector<Joueur>& joueurs) : _placementDesJoueurs(placement), _joueurEnCours(joueurEnCours), _joueurs(joueurs), _ardoise(_placementDesJoueurs, _joueurEnCours, _joueurs) { }
		~Damier() = default;
		Damier(const Damier& d) = default;
		Damier& operator = (const Damier& d) = default;
		void afficher(void);
		const std::string& nomJoueur(unsigned int indice) const { return _joueurs.at(indice).nom(); }
	private:
		ePlacementJoueurs&  _placementDesJoueurs;
		eJoueurEnCours&     _joueurEnCours;
		std::vector<Joueur>& _joueurs;
		Ardoise _ardoise;
	};
}

# endif  // _DAMIER_H_
