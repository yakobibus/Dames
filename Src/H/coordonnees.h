// coordonnees.h

# ifndef _COORDONNEES_H_
# define _COORDONNEES_H_ (1)

# include "constantes.h"
# include "manoury.h"

namespace spc_dames
{
	class Coordonnees
	{
	public:
		Coordonnees() : _yxmAddress(nullptr), _manouryAddress(nullptr){}
		Coordonnees(YXM* yxm, Manoury* manouryAddress, char* motif) : _yxmAddress(yxm), _manouryAddress(manouryAddress) {}
		~Coordonnees() = default;
		Coordonnees(const Coordonnees& c) = default;
		Coordonnees& operator = (const Coordonnees& c) = default;
		// ---
		void set(const YXM& yxm, const Manoury* manouryAddress);
		Coordonnees& get(void) { return *this; }
		unsigned int getX(void) const { return _yxmAddress->yx.x; }
		unsigned int getY(void) const { return _yxmAddress->yx.y; }
		const YXM*         getXMaddress(void) const { return _yxmAddress; }
		unsigned int getManoury(void) const { return _yxmAddress->manoury; } 
		char         getXalpha(void) const { return 'a' + _yxmAddress->yx.x - 1; }
	private:
		const YXM*                         _yxmAddress ;
		const Manoury*                     _manouryAddress;
		std::vector<unsigned>              _boardDiagonalsIndices ;
		std::vector<unsigned>              _manouryVoisines ;

		// ici peut-être ptrMotif : _adresseMotif ?
	};
}

# endif // _COORDONNEES_H_
