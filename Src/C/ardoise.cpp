// ardoise.cpp

# include "ardoise.h"
# include "constantes.h"
# include "pion.h"


namespace spc_dames
{
	void Ardoise::afficher(void) 
	{ 
		std::cout << std::endl;
		std::cout << _ardoise; 
		std::cout << std::endl;
		std::cout.flush();
	}
}

namespace spc_dames
{
	Ardoise::Ardoise(ePlacementJoueurs placementDesJoueurs)
		: _cellules(NB_CASES_PLATEAU)
		, _pionsBlancs(NB_PIONS_PAR_COULEUR)
		, _pionsNoirs(NB_PIONS_PAR_COULEUR)
		, _placementDesJoueurs(placementDesJoueurs)
		//, _titi( (_ardoisier.at(2).at(4)), (_ardoisier.at(2).at(8)) )
		//, _pionsDansOrdreDuJeu(NB_JOUEURS)
	{
		//std::vector<char>* toto = &(_ardoisier.at(2).at(4)) ;
		//std::cout << "ici [" << toto->at(1) << "], [" << _toto[0]->at(1) << "], [" << _toto[1]->at(1) << "]\n";
		//std::cout << "iti [" << _cellsPtrs.at(0)->at(1) << "], [" << _cellsPtrs.at(1)->at(0) << _cellsPtrs.at(1)->at(1) << _cellsPtrs.at(1)->at(2) << "]\n";
		//_cells.at(1)->at(0) = '/';
		//_cells.at(1)->at(1) = 'O';
		//_cells.at(1)->at(2) = '/';
		//_cells.at(0)->at(0) = '\\';
		//_cells.at(0)->at(1) = 'X';
		//_cells.at(0)->at(2) = '\\';
		//std::cout << "iti [" << _cells.at(0)->at(1) << "], [" << _cells.at(1)->at(0) << _cells.at(1)->at(1) << _cells.at(1)->at(2) << "]\n";
		//for (Cellule& cell : _cellules)
		//{ // initialisation des adresses des motifs de cellules
		//	std::cout << "[" << cell.getManoury()  << "] .. "; // ICI ...
		//	cell.initAdresseMotif(_cellsPtrs.at(cell.getManoury()));
		//	cell.setMotif(0);
		//}
		/*
		for (std::vector<char>* pp : _cellsPtrs)
		{ // Intializing the cell motif
			for (char&  c : *pp)
			{ 
				c = DETAIL_MOTIF_NORMAL ;
			}
		}
		*/
		//{
		//	std::cout << "\n\nNw mode [\n";
		//	std::cout << std::endl;
		//	for (unsigned int ii = 0; ii < _ardoisier.size(); ++ii)
		//	{
		//		for (unsigned int jj = 0; jj < _ardoisier.at(ii).size(); ++jj)
		//		{
		//			for (char& c : _ardoisier.at(ii).at(jj))
		//			{
		//				std::cout << c;
		//			}
		//		}
		//	}
		//	std::cout << "\n] end of nw mode\n";
		//}
		//for (unsigned int ii = 0; ii < NB_JOUEURS; ++ii)
		//{
		//	_pionsDansOrdreDuJeu.at(ii).push_back(NB_PIONS_PAR_COULEUR, Pion);
		//}

		/*
		std::cout << "Avt [\n";
		for (char& c : _ardoisette)
		{ 
			std::cout << c;
		}
		std::cout << "\n] Apr\n";
		*/

		/* ici :: l'initialisation ser faite avec les cellules de l'ardoise
		for (Pion& pionB : _pionsBlancs)
		{
			pionB.setMotif(eMotifDuPion::normalBlanc);
		}

		for (Pion& pionN : _pionsNoirs)
		{
			pionN.setMotif(eMotifDuPion::normalNoir);
		}
		*/

		//_pionsDansOrdreDuJeu.at(0) = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsBlancs : &_pionsNoirs);
		//_pionsDansOrdreDuJeu.at(1) = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsNoirs : &_pionsBlancs);

		int manoury = 0;
		int y = 10;
		int x = 99;

		unsigned int iiNord = 0;
		unsigned iiSud = 0;

		Pion* pionPtr = nullptr ;

		for (Cellule& currentCell : _cellules)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);

			if (y <= 10 && y >= 7)
			{
				pionPtr = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsBlancs.at(iiNord++) : &_pionsNoirs.at(iiNord++));
				pionPtr->init(
					  (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalBlanc : eMotifDuPion::normalNoir)
					, manoury
					, eAspectDuPion::normal
					, eStatutDuPion::libre
				);
			}
			else
			{
				if (y <= 4 && y >= 1)
				{ 
					pionPtr = (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? &_pionsNoirs.at(iiSud++) : &_pionsBlancs.at(iiSud++));
					pionPtr->init(
						  (_placementDesJoueurs == ePlacementJoueurs::blancs_noirs ? eMotifDuPion::normalNoir : eMotifDuPion::normalBlanc)
						, manoury
						, eAspectDuPion::normal
						, eStatutDuPion::libre
					);
				}
				else
				{
					pionPtr = nullptr ;
				}
			}

			currentCell.initCell(y, x, manoury, _cellMotifPtrs.at(-1 + manoury), pionPtr);
			if (manoury % 5 == 0) { --y; std::cout << std::endl; }
			//currentCell.initAdresseMotif(_cellMotifPtrs.at(currentCell.getManoury()));
			//currentCell.setMotif(0);
		}

		{
			std::cout << "\n\nNw mode [\n";
			std::cout << std::endl;
			for (unsigned int ii = 0; ii < _ardoisier.size(); ++ii)
			{
				for (unsigned int jj = 0; jj < _ardoisier.at(ii).size(); ++jj)
				{
					for (char& c : _ardoisier.at(ii).at(jj))
					{
						std::cout << c;
					}
				}
			}
			std::cout << "\n] end of nw mode\n";
		}


		manoury = 0; y = 10; x = 99; iiNord = 0; iiSud = 0;
		for (Cellule& currentCell : _cellules)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);
			currentCell.setCoordonnees(
				y
				, x
				, manoury
				//, &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x]
				, (y <= 10 && y >= 7 ? &_pionsBlancs[iiNord++] : (y <= 4 && y >= 1 ? &_pionsNoirs[iiSud++] : nullptr))
			);
			if (manoury % 5 == 0) { --y; std::cout << std::endl; }
		}
	}
}
