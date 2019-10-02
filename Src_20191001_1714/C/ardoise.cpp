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
	const unsigned int Ardoise::decalage(const unsigned int& y) const 
	{
		return (
			  y == 10 ? 2 
			: y == 9 ? 4 
			: y == 8 ? 6 
			: y == 7 ? 8 
			: y == 6 ? 10 
			: y == 5 ? 12 
			: y == 4 ? 14 
			: y == 3 ? 16 
			: y == 2 ? 18 
			: y == 1 ? 20 
			: 0
			); 
	}
}

namespace spc_dames
{
	Ardoise::Ardoise(ePlacementJoueurs placementDesJoueurs)
		: _cellules(NB_CASES_PLATEAU)
		, _pionsBlancs(NB_PIONS_PAR_COULEUR)
		, _pionsNoirs(NB_PIONS_PAR_COULEUR)
		, _placementDesJoueurs(placementDesJoueurs)
	{
		//for (Pion& pionB : _pionsBlancs)
		//{
		//	pionB.setMotif(eMotifDuPion::normalBlanc);
		//	//std::cout << ":::" << static_cast<char>(pionB.motif()) << "::: ";
		//}

		//for (Pion& pionN : _pionsNoirs)
		//{
		//	pionN.setMotif(eMotifDuPion::normalNoir);
		//	//std::cout << ":::ici" << static_cast<char>(pionN.motif()) << "ici::: ";
		//}
		int manoury = 0;
		int y = 10;
		int x = 99;
		////char mtf[4] = "";
		/*
		std::cout << "NbCellules = " << _cellules.size() << std::endl;
		for (unsigned int ii = 0; ii < _cellules.size(); ++ii)
		{
			std::cout << ii << ". ";
			_cellules[ii].set(ii);
		}
		*/
		for (std::vector<Cellule>::iterator currCell = _cellules.begin(); currCell < _cellules.end(); ++currCell)
		{
			++manoury;
			x = y % 2 == 0 ? (x > 8 ? 2 : x + 2) : (x > 7 ? 1 : x + 2);
			//std::cout << "manoury = ("<<manoury<<"), y = <"<<y<<">, x=<"<<x<<">  ";
			//memset(mtf, 0, 4); memcpy(mtf, &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x], 3);
			//std::cout <<"\n"<< "y=" << y << ", x=" << x << ", manoury=" << manoury << ", motif=[" << &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x] << "] ";
			//currCell[-1 + manoury].set(y, x, manoury, &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x], &_pionsBlancs[0]);
			_cellules[-1 + manoury].set(y, x, manoury, &_ardoise[NB_CHAR_PAR_LIGNE * decalage(y) + (TAILLE_CELLULE + TAILLE_SEPARATEUR) * x], &_pionsBlancs[0]);
			//std::cout << "cell["<< manoury << "]-(y, x)=(" << y << ", " << x << ") " << currCell[-1 + manoury].getMotifPion() << " .. ";
			if (manoury % 5 == 0) { --y; std::cout << std::endl;}
		}
		//std::cout << std::endl;
	}
}

