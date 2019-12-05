// joueur.h

# ifndef _JOUEUR_H_
# define _JOUEUR_H_ (1)

# include <iostream>
# include <string>
# include <vector>
# include "constantes.h"
# include "pion.h"

//# include "coup.h" // ici

namespace spc_dames
{
	enum class eJoueurEnCours
	{
		nord = 0
		, sud = 1
	};
}

namespace spc_dames
{
	class Joueur
	{
	public :
		Joueur() : _couleur(Couleur::eCouleur::blanc), /*_pionsVctrAddress(nullptr),*/ _pions(NB_PIONS_PAR_COULEUR) {}
		~Joueur() = default;
		Joueur(const Joueur& j) = default;
		Joueur& operator =(const Joueur& j) = default;
		//
		Couleur::eCouleur eCouleur(void) { return _couleur; }
		
		//void ici(void) { std::cout << " .Joueur.ici().\n"; }
		//void ici(std::vector<Coup>& coup) { Coup ici; coup.push_back(ici); std::cout << " .Joueur.ici(RefCoup).\n"; }

		const std::string& couleurTexte(void) const { return _couleurTexte.couleurTexte(_couleur); }
		Pion* getPionPtr(unsigned int range) { return &_pions.at(range); }
		const std::string& nom(void) const { return _nom; }
		void set(Couleur::eCouleur couleur, std::string nom, std::vector<Pion>* pionsPtr) { _couleur = couleur; _nom = nom; /*_pionsVctrAddress = pionsPtr;*/ }		
		//void setPionPtr(std::vector<Pion>* pawnVectorAddress) { _pionsVctrAddress = pawnVectorAddress; }
		//
		//std::vector<Pion>* getPionsVectorAddress(void) const { return _pionsVctrAddress; }
	private :
		Couleur::eCouleur    _couleur;
		std::string          _nom;
		//std::vector<Pion>*   _pionsVctrAddress;
		std::vector<Pion>    _pions;
		Couleur         _couleurTexte;
	};
}

# endif // _JOUEUR_H_
