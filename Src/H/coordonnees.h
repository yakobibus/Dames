// coordonnees.h

# ifndef _COORDONNEES_H_
# define _COORDONNEES_H_ (1)

# include "constantes.h"

namespace spc_dames
{
	class Coordonnees
	{
	public:
		Coordonnees() : _y(0), _x(0), _manoury(0), _adresseMotif(nullptr) {}
		Coordonnees(unsigned int y, unsigned x, unsigned manoury, char* motif) : _x(x), _y(y), _manoury(manoury), _adresseMotif(motif) {}
		~Coordonnees() = default;
		Coordonnees(const Coordonnees& c) = default;
		Coordonnees& operator = (const Coordonnees& c) = default;
		// ---
		void set(const unsigned int& y, const unsigned int& x, const unsigned int& manoury); // , char* const adresseMotif); // { _y = y; _x = x; _manoury = m; _motif = mtf; }
		Coordonnees& get(void) { return *this; }
		unsigned int getX(void) const { return _x; }
		unsigned int getY(void) const { return _y; }
		unsigned int getManoury(void) const { return _manoury; }
		char         getXalpha(void) const { return 'a' + _x - 1; }
		char* getMotif(void) const { return _adresseMotif; }
		void setMotif(const char& c) { _adresseMotif[1] = c; }
	private:
		unsigned _y;
		unsigned _x;
		unsigned _manoury;
		char*    _adresseMotif ;
	};
}

# endif // _COORDONNEES_H_
