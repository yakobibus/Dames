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
		std::cout << std::endl;
		//
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

	bool Ardoise::jouer(std::vector<Coup>& coup, eJoueurEnCours& joueurEnCours)
	{
		_input.saisie("\n\n\t\t=> ");

		if (_input.isValid())
		{
			coup.push_back(Coup(coup.size(), &_joueurs.at(static_cast<unsigned>(_joueurEnCours)), nullptr, &_cellules.at(-1 + _input.getManoury()), nullptr));
			bool isValid = coup.at(-1 + coup.size()).isValidDepart();
			std::cout << "dEpart "<<(isValid == true ? "valide" : "invalide")<<"\n";

			//Joueur& j = _joueurs.at(_joueurEnCours);
			//coup.at(0).jouer(ici, _joueurs[_joueurEnCours]);
			//_cellules.at(_input.getManoury());
			//_cellules.at(_input.getManoury()).getPionAddress().getCouleur() ; // maoury occupEe par un pion de la bonne couleur ?
		}

		return _input.isValid() ;
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

		for (unsigned int ii = 0; ii < _joueurs.at((int)_joueurEnCours).couleurTexte().size() && ii < _enqueue.at(4).at(2).size(); ++ii)
		{
			_enqueue.at(4).at(2).at(ii) = _joueurs.at((int)_joueurEnCours).couleurTexte().c_str()[ii];
		}
	}
}

namespace spc_dames
{
	Ardoise::Ardoise(ePlacementJoueurs& placementDesJoueurs, eJoueurEnCours& joueurEnCours, std::vector<Joueur>& joueurs)
		: _cellules(NB_CASES_PLATEAU)
		, _placementJoueurNord(placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? ePlacementJoueurs::blancs_noirs : ePlacementJoueurs::noirs_blancs)
		, _placementJoueurSud(placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? ePlacementJoueurs::noirs_blancs : ePlacementJoueurs::blancs_noirs)
		, _motifPionsNord(placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalBlanc : eMotifDuPion::normalNoir)
		, _motifPionsSud(placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalNoir : eMotifDuPion::normalBlanc)
		, _eCouleurPionsNord(placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? Couleur::eCouleur::blanc : Couleur::eCouleur::noir)
		, _eCouleurPionsSud(placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? Couleur::eCouleur::noir : Couleur::eCouleur::blanc)
		, _joueurEnCours(joueurEnCours)
		, _joueurs(joueurs)
		, _continuerLaPartie(false)
		, _input(_manoury)
	{
		unsigned int iiNord = 0;
		unsigned iiSud = 0;

		Pion* pionPtr = nullptr;

		for (YXM& yxm : _manoury.getYxManouryReference()) 
		{
			if (yxm.yx.y <= 10 && yxm.yx.y >= 7)
			{
				pionPtr = _joueurs.at(static_cast<unsigned int>(_placementJoueurNord)).getPionPtr(iiNord++);
				pionPtr->init(
					_motifPionsNord
					, _eCouleurPionsNord
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
					pionPtr = _joueurs.at(static_cast<unsigned int>(_placementJoueurSud)).getPionPtr(iiSud++);
					pionPtr->init(
						_motifPionsSud
						, _eCouleurPionsSud
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

			_cellules.at(-1 + yxm.manoury).initCell(yxm, _cellMotifPtrs.at(-1 + yxm.manoury), pionPtr); // (/*_manoury.getYxmRef(manoury),*/ yxm.yx.y, yxm.yx.x, yxm.manoury, _cellMotifPtrs.at(-1 + yxm.manoury), pionPtr);
		}
	}
}
