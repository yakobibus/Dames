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
		std::cout << std::endl;
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
		int manoury = 0;
		int y = 10;
		int x = 99;

		unsigned int iiNord = 0;
		unsigned iiSud = 0;

		Pion* pionPtr = nullptr;

		for (Cellule& currentCell : _cellules)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);

			if (y <= 10 && y >= 7)
			{
				pionPtr = _joueurs.at(static_cast<unsigned int>(_placementDesJoueurs)).getPionPtr(iiNord++);
				pionPtr->init(
					(_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalBlanc : eMotifDuPion::normalNoir)
					, iiNord
					, manoury
					, eAspectDuPion::normal
					, eStatutDuPion::libre
				);
			}
			else
			{
				if (y <= 4 && y >= 1)
				{ 
					pionPtr = _joueurs.at(static_cast<unsigned int>(_placementDesJoueurs)).getPionPtr(iiSud++);
					pionPtr->init(
						(_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalNoir : eMotifDuPion::normalBlanc)
						, abs(static_cast<int>(-1 - NB_PIONS_PAR_COULEUR + iiSud)) // Numérotation inverséee au sud par symétrie
						, manoury
						, eAspectDuPion::normal
						, eStatutDuPion::libre
					);
				}
				else
				{
					pionPtr = nullptr;
				}
			}

			currentCell.initCell(y, x, manoury, _cellMotifPtrs.at(-1 + manoury), pionPtr);
			if (manoury % 5 == 0) { --y; }
		}
	}
}
