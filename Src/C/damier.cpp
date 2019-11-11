// damier.cpp

# include "damier.h"

namespace spc_dames
{
	void Damier::afficher(void)
	{
		_ardoise.afficherManoury();
		_ardoise.afficher();
	}
}

//namespace spc_dames 
//{
	//void Damier::afficher(void)
	//{
		//for (CaseDamier& x : _casesDamier)
		//{
			//x.afficher();
		//}

		/*
		std::vector<std::vector<char>> dim2char = { { 'a', 'b', 'c', 'd' }, { 'e', 'f', 'g', 'h' }, { 'i', 'j', 'k', 'l' } };
		for (auto&& xx : dim2char)
		{ 
			std::cout << "." ;
			for (auto&& zzz : xx)
			{
				std::cout << zzz;
			}
		}
		for (std::vector<char>& T : dim2char)
		{ 
			std::cout << "<"<<dim2char.size() << "x" << T.size()<<">";
			for (char& t : T)
			{
				std::cout << t;
			}
		}
		*/

//# define MOTIF { {'/', 'x', '/', '|'}, {'/', 'x', '/', ' '} }
//# define MOTIF2 { {'/'}, {'x'}, {'/'}, {'|'}, {'/'}, {'x'}, {'/'}, {' '}, {'\0'} }
//# define MOTIF3 { '/', 'x', '/', '|', '/', 'x', '/', '|' }
		//char lignes[2][4] = MOTIF ;
		//std::cout << "[[" << (char(*))(&lignes[0]) << "]]\n";
		//char lignes2[10][1] = MOTIF2;
		//char lignes3[10] = MOTIF3;
		//lignes3[9] = 0;
		//std::cout << "l2 [" << lignes2 << "]\n";
		//std::cout << "l3 [" << lignes3 << "]\n";
		//char slate [(12 * 4 * 23)] = MOTIF_PLATEAU_DAMIER;  //[1104] = MOTIF_PLATEAU_DAMIER ; // ;
		//slate[1103] = 0;
		//std::cout << std::endl << slate << std::endl << std::endl ;

		//struct LaCellule { char motif[3]; char sep; };
		//std::vector<std::vector<char>> cells = MOTIF; // { {'/', 'x', '/', '|'}, { '/', 'x', '/', ' ' } };
		//LaCellule laCell[2];
		//std::cout << "[[" << laCell[0].motif[1] << "]]\n";
		//char motif[2 * 4];
		//strcpy(laCell->motif, )
	//}
	//
	/*
	void Damier::effaceMoi(void)
	{
		//std::cout << "Ici taille [" << _casesDamier.size() << "]\n";
		//for (CaseDamier x : _casesDamier)
		{
			//x.afficher();
		}
		//
		std::cout << "Seconde vague\n";
		//for (auto&& x : _casesDamier)
		{
			//x.afficher();
		}
		//
		std::cout << "Third motion\n";
		//for (CaseDamier& x : _casesDamier)
		{
			//x.afficher();
		}
	}
	*/
//}
