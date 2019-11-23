// ardoise.cpp

# include <cmath>
# include "ardoise.h"
# include "constantes.h"
# include "pion.h"


namespace spc_dames
{
	void Ardoise::afficher(void) 
	{ 
		setEntete();
		for (std::vector <std::vector <char>>& ligneEntete : _entete)
		{
			for (std::vector <char>& regionLigneEntete : ligneEntete)
			{
				for (char& c: regionLigneEntete)
				{
					std::cout << "" << c << "";
				}
			}
		}
		//
		std::cout << std::endl;
		for (unsigned int ii = 0; ii < _ardoise.size(); ++ii)
		{
			for (unsigned int jj = 0; jj < _ardoise.at(ii).size(); ++jj)
			{
				for (char& c : _ardoise.at(ii).at(jj))
				{
					std::cout << c;
				}
			}
		}
		std::cout << std::endl;
		//
		setEnqueue();
		for (std::vector <std::vector <char>>& ligneEnqueue : _enqueue)
		{
			for (std::vector <char>& regionLigneEnqueue : ligneEnqueue)
			{
				for (char& c : regionLigneEnqueue)
				{
					std::cout << "" << c << "";
				}
			}
		}
		//std::cout << std::endl;
		std::cout.flush();
	}

	void Ardoise::setEntete(void) 
	{
		for (unsigned int ii = 0; ii < _joueurs.at(0).nom().size() && ii < _entete.at(4).at(1).size() ; ++ii)
		{
			_entete.at(4).at(1).at(ii) = _joueurs.at(0).nom().c_str()[ii];
		}
	}

	void Ardoise::setEnqueue(void)
	{
		for (unsigned int ii = 0; ii < _joueurs.at(1).nom().size() && ii < _enqueue.at(1).at(1).size() ; ++ii)
		{
			_enqueue.at(1).at(1).at(ii) = _joueurs.at(1).nom().c_str()[ii];
		}

		for (unsigned int ii = 0; ii < _joueurs.at((int)_joueurEnCours).couleur().size() && ii < _enqueue.at(4).at(2).size(); ++ii)
		{
			_enqueue.at(4).at(2).at(ii) = _joueurs.at((int)_joueurEnCours).couleur().c_str()[ii];
		}
	}
}

namespace spc_dames
{
	Ardoise::Ardoise(ePlacementJoueurs placementDesJoueurs, eJoueurEnCours& joueurEnCours, std::vector<Joueur>& joueurs)
		: _cellules(NB_CASES_PLATEAU)
		, _placementDesJoueurs(placementDesJoueurs)
		, _joueurEnCours(joueurEnCours)
		, _joueurs(joueurs)
	{
		unsigned int iiNord = 0;
		unsigned iiSud = 0;

		Pion* pionPtr = nullptr;

		for (YXM& yxm : _manoury.getYxManouryReference()) 
		{
			if (yxm.yx.y <= 10 && yxm.yx.y >= 7)
			{
				pionPtr = _joueurs.at(static_cast<unsigned int>(_placementDesJoueurs)).getPionPtr(iiNord++);
				pionPtr->init(
					(_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalBlanc : eMotifDuPion::normalNoir)
					, iiNord
					, yxm.manoury
					, eAspectDuPion::normal
					, eStatutDuPion::libre
				);
			}
			else
			{
				if (yxm.yx.y <= 4 && yxm.yx.y >= 1)
				{
					pionPtr = _joueurs.at(static_cast<unsigned int>(_placementDesJoueurs)).getPionPtr(iiSud++);
					pionPtr->init(
						(_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalNoir : eMotifDuPion::normalBlanc)
						, abs(static_cast<int>(-1 - NB_PIONS_PAR_COULEUR + iiSud)) // Numérotation inverséee au sud par symétrie
						, yxm.manoury
						, eAspectDuPion::normal
						, eStatutDuPion::libre
					);
				}
				else
				{
					pionPtr = nullptr;
				}
			}

			//TODO ici : trouver le moyen d'initialiser l'adresse yxm des coordonnées de la cellule  !!!
			_cellules.at(-1 + yxm.manoury).initCell(yxm, _cellMotifPtrs.at(-1 + yxm.manoury), pionPtr); // (/*_manoury.getYxmRef(manoury),*/ yxm.yx.y, yxm.yx.x, yxm.manoury, _cellMotifPtrs.at(-1 + yxm.manoury), pionPtr);
		}
	}
}
