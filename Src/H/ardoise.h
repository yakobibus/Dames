// ardoise.h

# ifndef _ARDOISE_H_
# define _ARDOISE_H_ (1)

# include <iostream>
# include <vector>
# include "cellule.h"
# include "constantes.h"
# include "joueur.h"
# include "manoury.h"
# include "pion.h"

namespace spc_dames
{
	class Ardoise
	{
	public:
		Ardoise(ePlacementJoueurs placementDesJoueurs, eJoueurEnCours& joueurEnCours , std::vector<Joueur>& joueurs);
		~Ardoise() = default;
		Ardoise(const Ardoise& a) = default;
		Ardoise& operator = (const Ardoise& a) = default;
		//
		void afficher(void);
		void setEntete(void);
		void setEnqueue(void);
	private:
		std::vector< std::vector< std::vector<char> > > _ardoise = MOTIF_PLATEAU_DAMIER ;
		std::vector< std::vector <std::vector <char>>>  _entete = MOTIF_TEXTE_ENTETE;
		std::vector< std::vector <std::vector <char>>>  _enqueue = MOTIF_TEXTE_ENQUEUE;
		Manoury                           _manoury;
		std::vector<Cellule>              _cellules;
		ePlacementJoueurs&                _placementDesJoueurs;
		eJoueurEnCours&                   _joueurEnCours;
		std::vector<Joueur>&              _joueurs;
		std::vector <std::vector<char>* > _cellMotifPtrs =  {
			&(_ardoise.at(2).at(4)), &(_ardoise.at(2).at(8)), &(_ardoise.at(2).at(12)),& (_ardoise.at(2).at(16)),& (_ardoise.at(2).at(20))
		  , &(_ardoise.at(4).at(2)), &(_ardoise.at(4).at(6)), &(_ardoise.at(4).at(10)),& (_ardoise.at(4).at(14)),& (_ardoise.at(4).at(18))
		  , &(_ardoise.at(6).at(4)),& (_ardoise.at(6).at(8)),& (_ardoise.at(6).at(12)),& (_ardoise.at(6).at(16)),& (_ardoise.at(6).at(20))
		  ,& (_ardoise.at(8).at(2)),& (_ardoise.at(8).at(6)),& (_ardoise.at(8).at(10)),& (_ardoise.at(8).at(14)),& (_ardoise.at(8).at(18))
		  ,& (_ardoise.at(10).at(4)),& (_ardoise.at(10).at(8)),& (_ardoise.at(10).at(12)),& (_ardoise.at(10).at(16)),& (_ardoise.at(10).at(20))
		  ,& (_ardoise.at(12).at(2)),& (_ardoise.at(12).at(6)),& (_ardoise.at(12).at(10)),& (_ardoise.at(12).at(14)),& (_ardoise.at(12).at(18))
		  ,& (_ardoise.at(14).at(4)),& (_ardoise.at(14).at(8)),& (_ardoise.at(14).at(12)),& (_ardoise.at(14).at(16)),& (_ardoise.at(14).at(20))
		  ,& (_ardoise.at(16).at(2)),& (_ardoise.at(16).at(6)),& (_ardoise.at(16).at(10)),& (_ardoise.at(16).at(14)),& (_ardoise.at(16).at(18))
		  ,& (_ardoise.at(18).at(4)),& (_ardoise.at(18).at(8)),& (_ardoise.at(18).at(12)),& (_ardoise.at(18).at(16)),& (_ardoise.at(18).at(20))
		  ,& (_ardoise.at(20).at(2)),& (_ardoise.at(20).at(6)),& (_ardoise.at(20).at(10)),& (_ardoise.at(20).at(14)),& (_ardoise.at(20).at(18))
		};
		//
		const unsigned int decalage(const unsigned int& y) const { return (y == 10 ? 2 : y == 9 ? 4 : y == 8 ? 6 : y == 7 ? 8 : y == 6 ? 10 : y == 5 ? 12 : y == 4 ? 14 : y == 3 ? 16 : y == 2 ? 18 : y == 1 ? 20 : 0); }
	};
}


# endif // _ARDOISE_H_
