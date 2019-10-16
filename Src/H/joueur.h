// joueur.h

# ifndef _JOUEUR_H_
# define _JOUEUR_H_ (1)

# include <iostream>
# include <string>
# include "constantes.h"

namespace spc_dames
{
	class Joueur
	{
	public :
		Joueur() = default;
		~Joueur() = default;
		Joueur(const Joueur& j) = default;
		Joueur& operator =(const Joueur& j) = default;
		//
		eCouleur couleur(void) { return _couleur; }
		const std::string& nom(void) const { return _nom; }
		void set(eCouleur couleur, std::string nom) { _couleur = couleur; _nom = nom; }
	private :
		eCouleur _couleur;
		std::string _nom;
	};
}

# endif // _JOUEUR_H_
