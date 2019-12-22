// manoury.h


# ifndef _MANOURY_H_
# define _MANOURY_H_ (1)

# include <iostream>
# include <vector>
# include "constantes.h"

namespace spc_dames
{
	struct YX
	{
		YX() = default;
		YX(const unsigned int& yy, const unsigned int& xx) : y(yy), x(xx) {}
		~YX() = default;
		YX(const YX& yx) = default;
		YX& operator = (const YX& yx) = default;
		unsigned int y ;
		unsigned int x ;
	};

	struct YXM
	{
		YX           yx ;
		unsigned int manoury;
	};

	struct Diagonales
	{
		const std::vector< std::vector <unsigned int> > manouryDiagonales = 
		{
			  {  1,  6 }
			, {  2,  7, 11, 16 }
			, {  3,  8, 12, 17, 21, 26 }
			, {  4,  9, 13, 18, 22, 27, 31, 36 }
			, {  5, 10, 14, 19, 23, 28, 32, 37, 41, 46 }
			, { 15, 20, 24, 29, 33, 38, 42, 47 }
			, { 25, 30, 34, 39, 43, 48 }
			, { 35, 40, 44, 49 }
			, { 45, 50 }
			, {  5 }
			, {  4, 10, 15 }
			, {  3,  9, 14, 20, 25 }
			, {  2,  8, 13, 19, 24, 30, 35 }
			, {  1,  7, 12, 18, 23, 29, 34, 40, 45 }
			, {  6, 11, 17, 22, 28, 33, 39, 44, 50 }
			, { 16, 21, 27, 32, 38, 43, 49 }
			, { 26, 31, 37, 42, 48 }
			, { 36, 41, 47 }
			, { 46 }
		};
		//
		const std::vector< std::vector <unsigned> > diagonalesCellules =  // les indices des diagonales par manoury
		{
			  {0} // Manoury 0 n'este pas
			, {0, 13} // Les indices de la cellule Manoury = 1
            , {1, 12} // 2
            , {2, 11} // 3
            , {3, 10} // 4
            , {4, 9 } // 5
            , {0, 14} // 6
            , {1, 13} // 7
            , {2, 13} // 8
            , {3, 12} // 9
            , {4, 11} // 10
            , {1, 14} // 11
            , {2, 13} // 12
            , {3, 12} // 13
            , {4, 11} // 14
            , {5, 10} // 15
            , {1, 15} // 16
            , {2, 14} // 17
            , {3, 13} // 18
            , {4, 12} // 19
            , {5, 11} // 20
            , {2, 15} // 21
            , {3, 14} // 22
            , {4, 13} // 23
            , {5, 12} // 24
            , {6, 11} // 25
            , {2, 16} // 26
            , {3, 15} // 27
            , {4, 14} // 28
            , {5, 13} // 29
            , {6, 12} // 30
            , {3, 16} // 31
            , {4, 15} // 32
            , {5, 14} // 33
            , {6, 13} // 34
            , {7, 12} // 35
            , {3, 17} // 36
            , {4, 16} // 37
            , {5, 15} // 38
            , {6, 14} // 39
            , {7, 13} // 40
            , {4, 17} // 41
            , {5, 16} // 42
            , {6, 15} // 43
            , {7, 14} // 44
            , {8, 13} // 45
            , {4, 18} // 46
            , {5, 17} // 47
            , {6, 16} // 48
            , {7, 15} // 49
            , {8, 14} // 50
		} ;
	};

	class Manoury
	{
	public:
		Manoury() = default;
		~Manoury() = default;
		Manoury(const Manoury& m) = default;
		Manoury& operator = (const Manoury& m) = default;
		//
		bool areDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const; // Les deux manoury sont sur la m�me diagonale
		bool areNeighbors(const unsigned int& manouryOne, const unsigned int& manouryTwo, unsigned int& ecart); /// Les deux manoury sont voisines sur la diagonales, en sortie eSens indique le sens de one sur two
		const std::vector <unsigned>& getDiagonale(const unsigned& indiceDiag) const { return _diagonales.manouryDiagonales.at(indiceDiag); }
		//void getDiagonales(const unsigned& manoury, std::vector <unsigned>& refDiagonales) const { refDiagonales = _diagonales.diagonalesCellules.at(manoury); }
		const std::vector <unsigned>& getDiagonales(const unsigned& manoury) const { return _diagonales.diagonalesCellules.at(manoury); }
		//
		unsigned int getManoury(const YX& yx) const;
		unsigned int getManoury(const unsigned int& y, const unsigned int& x) const { return getManoury(YX(y, x)); }
		const YXM getManoury(const unsigned int& manoury) const { return _yxManoury.at (-1 + manoury);  }  // _manoury.at(0) est == 1
		const std::vector< YXM>& getYxManouryReference(void) const { return _yxManoury; }
	private:
		const Diagonales        _diagonales;
		const std::vector <YXM> _yxManoury = MOTIF_MANOURY;
	};
}

# endif // _MANOURY_H_
