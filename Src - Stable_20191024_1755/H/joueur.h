// joueur.h

# ifndef _JOUEUR_H_
# define _JOUEUR_H_ (1)

# include <iostream>
# include <string>
# include <vector>
# include "constantes.h"
# include "pion.h"

namespace spc_dames
{
	class Joueur
	{
	public :
		Joueur() : _pions(NB_PIONS_PAR_COULEUR) {}
		~Joueur() = default;
		Joueur(const Joueur& j) = default;
		Joueur& operator =(const Joueur& j) = default;
		//
		eCouleur couleur(void) { return _couleur; }
		Pion* getPionPtr(unsigned int range) { return &_pions.at(range); }
		const std::string& nom(void) const { return _nom; }
		void set(eCouleur couleur, std::string nom, std::vector<Pion>* pionsPtr) { _couleur = couleur; _nom = nom; _pionsPrt = pionsPtr; }		void setPions(void) {}
	private :
		eCouleur             _couleur;
		std::string          _nom;
		std::vector<Pion>*   _pionsPrt;
		std::vector<Pion>    _pions;
	};
}

# endif // _JOUEUR_H_
