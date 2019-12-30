// cellule.h

# ifndef _CELLULE_H_
# define _CELLULE_H_ (1)

# include <cstring>
# include <vector>

# include "constantes.h"
# include "coordonnees.h"
# include "manoury.h"
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
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** Cellule du plateau : c'est une zone (ligne, colonne) du plateau où figure un motif : référence
		** de ligne/colonne, une case du damier, ... Elle s'étend donc au delà de la zone de jeu
		**/
	public:
		Cellule(Manoury* manouryAddress = nullptr) :_manouryAddress(manouryAddress), _adressePion(nullptr), _aspect(eAspectCellule::normal), _adresseMotif(nullptr) {}
		~Cellule() = default;
		Cellule(const Cellule& c) = default;
		Cellule& operator = (const Cellule& c) = default;
		//
		//unsigned int   getManoury(void) { return _coordonnees.getManoury(); }
		char           getMotifPion(void) { return (_adressePion == nullptr ? '\0' : (char)_adressePion->motif()); }
		Pion*          getPionAddress(void) const { return _adressePion; }
		bool           hasAvailableNeighbours(const eSensAvance& eSens) const { bool bRetcode = false; for (const unsigned& m : _coordonnees.getManouryVoisines()) { if (nullptr == _adressePion/*TODO de m*/) { std::cout << "v(" << m << ") "; } }return bRetcode; }
		void           initCell(const Manoury* manouryAddress, const YXM& yxm, std::vector<char>* cellMotifAddress, Pion* pionPtr);
		void           initAdresseMotif(std::vector<char>* adresseMotif) { _adresseMotif = adresseMotif; }
		void           setMotif(void);
		//
	private:
		const Manoury* _manouryAddress;
		Coordonnees    _coordonnees ;
		Pion*          _adressePion ;
		eAspectCellule _aspect;
		//eStatutDeLaCellule _statut; // libre ou occupee
		std::vector<char>* _adresseMotif;
	};
}

# endif  // _CELLULE_H_
