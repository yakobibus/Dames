// cellule.h

# ifndef _CELLULE_H_
# define _CELLULE_H_ (1)

# include <cstring>
# include <vector>

# include "constantes.h"
# include "coordonnees.h"
# include "pion.h"


namespace spc_dames
{
	enum class eAspectCellule
	{
		  normal = DETAIL_MOTIF_NORMAL
		, bold   = DETAIL_MOTIF_BOLD
	};

	/*
	enum class eStatutDeLaCellule
	{
		  libre
		, prise
	};
	*/

	class Motif
	{
	public:
		Motif() : _adresseMotif(nullptr) {}
		~Motif() = default;
		Motif(const Motif& m) = default;
		Motif& operator = (const Motif& m) = default;
		//
		char* const adresseMotif(void) { return _adresseMotif; }
		void set(char* const adresseMotif, const char& bordMotif, const char& centreMotif); //  { _motif = mtf; memset(_motif, static_cast<char>(eDetailMotif::normal), TAILLE_CELLULE); }
	private :
		char* _adresseMotif;
	};
}

namespace spc_dames
{
	class Cellule
	{
		/*
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau o� figure un motif : r�f�rence
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau o� figure un motif : r�f�rence
		** de ligne/colonne, une case du damier, ... Elle s'�tend donc au del� de la zone de jeu
		**/
	public:
		Cellule() : _adressePion(nullptr), _motif(), _aspect(eAspectCellule::normal), _adresseMotif(nullptr) /*, _statut(eStatutDeLaCellule::libre)*/ {}
		~Cellule() = default;
		Cellule(const Cellule& c) = default;
		Cellule& operator = (const Cellule& c) = default;
		//
		unsigned int getManoury(void) { return _coordonnees.getManoury(); }
		char* const  getMotif(void) const { return _coordonnees.getMotif(); }
		char         getMotifPion(void) { return (char)_adressePion->motif(); }
		void         setCoordonnees(const unsigned int& y, const unsigned int& x, const unsigned int& manoury, char* const motif, Pion* adressePion);
		void         initAdresseMotif(std::vector<char>* adresseMotif) { _adresseMotif = adresseMotif; }
		void         setMotif(void);
		void         setMotif(int i);
	private:
		Coordonnees    _coordonnees ;
		Pion*          _adressePion ;
		Motif          _motif;
		eAspectCellule _aspect;
		//eStatutDeLaCellule _statut; // libre ou occupee
		std::vector<char>* _adresseMotif;
	};
}

# endif  // _CELLULE_H_
