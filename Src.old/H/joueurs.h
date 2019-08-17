// joueurs.h

# ifndef _JOUEURS_H_
# define _JOUEURS_H_ (1)

/*
# include <iostream>
# include "commonServices.h"

using spc_commonServices::CouleurPion;
using spc_commonServices::IdJoueur;
using spc_commonServices::NatureJoueur;
using spc_commonServices::SensDuDeplacement;

namespace spc_joueurs
{
	/-* Un joueur est caractérisé par la couleur qu'il joue et sa nature (humain ou intelligence artificielle)
	**-/
	class Joueur
	{
	public:
		Joueur();
		~Joueur();
		Joueur(const Joueur& j);
		Joueur& operator = (const Joueur& j);
		//
		const CouleurPion& getCouleur(void) const { return _couleur; }
		const IdJoueur& getId(void) const { return _id; }
		const SensDuDeplacement& getSensDuDeplacement(void) const { return _sensDuDeplacement; }
		void init(
			const IdJoueur& id
			, const CouleurPion& couleur
			, const char* nom
			, const SensDuDeplacement& sensDuDeplacement
			, const NatureJoueur& nature = NatureJoueur::humain
		);
		const char* const getNom(void) const { return _nom; }
		const unsigned short getSzNom(void) const { return _szNom; }
		//void setId(const IdJoueur& id);
		//void setNom(const char* nom);
	private:
		IdJoueur          _id;
		CouleurPion       _couleur;
		NatureJoueur      _nature;
		char* _nom;
		unsigned short    _szNom;
		SensDuDeplacement _sensDuDeplacement;
	};
}
*/

# endif // _JOUEURS_H_
