// damier.h

# ifndef _DAMIER_H_
# define _DAMIER_H_ (1)

# include <vector>
# include "ardoise.h"
# include "constantes.h"
# include "coup.h"
# include "damier.h"
# include "joueur.h"

namespace spc_dames
{
	class Damier
	{
	public:
		Damier(ePlacementJoueurs& placement, eJoueurEnCours& joueurEnCours, std::vector<Joueur>& joueurs, std::vector<std::vector<Pion>*> pawnsVectorAddress) : _placementDesJoueurs(placement), _joueurEnCours(joueurEnCours), _joueurs(joueurs), _pawnsVectorAddress(pawnsVectorAddress), _ardoise(_placementDesJoueurs, _joueurEnCours, _joueurs), _continuerLaPartie(false) {} //_joueurs.at(0).setPionPtr(pawnsVectorAddress.at(0)); };// TODO: affecter les adresses des vecteurs de pions pour chaqu'un des joueurs ....}
		~Damier() = default;
		Damier(const Damier& d) = default;
		Damier& operator = (const Damier& d) = default;
		void afficher(void);
		bool jouer(std::vector<Coup>& coup, eJoueurEnCours& joueurEnCours);
		const std::string& nomJoueur(unsigned int indice) const { return _joueurs.at(indice).nom(); }
	private:
		ePlacementJoueurs&   _placementDesJoueurs;
		eJoueurEnCours&      _joueurEnCours;
		std::vector<Joueur>& _joueurs;
		std::vector<std::vector<Pion>*>   _pawnsVectorAddress;
		Ardoise              _ardoise;
		bool                 _continuerLaPartie;
	};
}

# endif  // _DAMIER_H_
