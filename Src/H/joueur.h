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
		Joueur() : _eCouleur(Couleur::eCouleur::blanc), _nom(""), _eSensAvance(eSensAvance::nonDefini), /*_pionsVctrAddress(nullptr),*/ _pions(NB_PIONS_PAR_COULEUR) {}
		~Joueur() = default;
		Joueur(const Joueur& j) = default;
		Joueur& operator =(const Joueur& j) = default;
		//
		const Couleur::eCouleur& eCouleur(void) const { return _eCouleur; }
		
		//void ici(void) { std::cout << " .Joueur.ici().\n"; }
		//void ici(std::vector<Coup>& coup) { Coup ici; coup.push_back(ici); std::cout << " .Joueur.ici(RefCoup).\n"; }

		const std::string& couleurTexte(void) const { return _couleurTexte.couleurTexte(_eCouleur); }
		Pion* getPionPtr(unsigned int range) { return &_pions.at(range); }
		const eSensAvance& getSensAvance(void) const { return _eSensAvance; }
		const std::string& nom(void) const { return _nom; }
		void set(Couleur::eCouleur couleur, std::string nom, eSensAvance eSensAvance, std::vector<Pion>* pionsPtr) { _eCouleur = couleur; _nom = nom; _eSensAvance = eSensAvance; /*_pionsVctrAddress = pionsPtr;*/ }
		//void setPionPtr(std::vector<Pion>* pawnVectorAddress) { _pionsVctrAddress = pawnVectorAddress; }
		//
		//std::vector<Pion>* getPionsVectorAddress(void) const { return _pionsVctrAddress; }
	private :
		Couleur::eCouleur    _eCouleur;
		std::string          _nom;
		eSensAvance          _eSensAvance;
		//std::vector<Pion>*   _pionsVctrAddress;
		std::vector<Pion>    _pions;
		Couleur              _couleurTexte;
	};
}

# endif // _JOUEUR_H_
