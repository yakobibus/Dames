// manoury.cpp

#include "manoury.h"

namespace spc_dames
{
	unsigned int Manoury::getManoury(YX yx) const 
	{ 
		unsigned int m = 99 ;
		switch (yx.y)
		{
		case 10 :
			m = (yx.x == 2 ? 1 : (yx.x == 4 ? 2 : (yx.x == 6 ? 3 : (yx.x == 8 ? 4 : (yx.x == 10 ? 5 : 99))))) ;
			break;
		case 9 :
			m = (yx.x == 1 ? 6 : (yx.x == 3 ? 7 : (yx.x == 5 ? 8 : (yx.x == 7 ? 9 : (yx.x == 9 ? 10 : 99))))) ;
			break;
		case 8 :
			m = (yx.x == 2 ? 11 : (yx.x == 4 ? 12 : (yx.x == 6 ? 13 : (yx.x == 8 ? 14 : (yx.x == 10 ? 15 : 99))))) ;
			break;
		case 7 :
			m = (yx.x == 1 ? 16 : (yx.x == 3 ? 17 : (yx.x == 5 ? 18 : (yx.x == 7 ? 19 : (yx.x == 9 ? 20 : 99))))) ;
			break;
		case 6 :
			m = (yx.x == 2 ? 21 : (yx.x == 4 ? 22 : (yx.x == 6 ? 23 : (yx.x == 8 ? 24 : (yx.x == 10 ? 25 : 99))))) ;
			break;
		case 5 :
			m = (yx.x == 1 ? 26 : (yx.x == 3 ? 27 : (yx.x == 5 ? 28 : (yx.x == 7 ? 29 : (yx.x == 9 ? 30 : 99))))) ;
			break;
		case 4 :
			m = (yx.x == 2 ? 31 : (yx.x == 4 ? 32 : (yx.x == 6 ? 33 : (yx.x == 8 ? 34 : (yx.x == 10 ? 35 : 99))))) ;
			break;
		case 3 :
			m = (yx.x == 1 ? 36 : (yx.x == 3 ? 37 : (yx.x == 5 ? 38 : (yx.x == 7 ? 39 : (yx.x == 9 ? 40 : 99))))) ;
			break;
		case 2 :
			m = (yx.x == 2 ? 41 : (yx.x == 4 ? 42 : (yx.x == 6 ? 43 : (yx.x == 8 ? 44 : (yx.x == 10 ? 45 : 99))))) ;
			break;
		case 1 :
			m = (yx.x == 1 ? 46 : (yx.x == 3 ? 47 : (yx.x == 5 ? 48 : (yx.x == 7 ? 49 : (yx.x == 9 ? 50 : 99))))) ;
			break;
		default:
			m = 99;
			break;
		}
		return _yxManoury.at (-1 + m).manoury ;
	}
}
