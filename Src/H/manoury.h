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
	};

	class Manoury
	{
	public:
		Manoury() = default;
		~Manoury() = default;
		Manoury(const Manoury& m) = default;
		Manoury& operator = (const Manoury& m) = default;
		//
		bool isDiagonalized(const unsigned int& manouryOne, const unsigned int& manouryTwo) const; // Les deux manoury sont sur la même diagonale
		bool areNeighbors(void); /// ???
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
