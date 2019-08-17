// commonServices.cpp

# include <iostream>
# include <iomanip>
# include <cstring>
# include "joueurs.h"
# include "commonServices.h"

/*
namespace spc_joueurs
{
	Joueur::Joueur()
		: _id(IdJoueur::undefined)
		, _couleur(CouleurPion::null)
		, _nature(NatureJoueur::undefined)
		, _nom(nullptr)
		, _szNom(0)
		, _sensDuDeplacement(SensDuDeplacement::undefined)
	{}

	Joueur::~Joueur()
	{
		if (_nom != nullptr)
		{
			delete _nom;
			_nom = nullptr;
			_szNom = 0;
		}
	}

	Joueur::Joueur(const Joueur& j)
	{
		if (this != &j)
		{
			_couleur = j._couleur;
			_id = j._id;
			_nature = j._nature;

			if (_nom != nullptr)
			{
				delete _nom;
				_nom = nullptr;
				_szNom = 0;
			}

			_szNom = std::strlen(j._nom);
			_nom = new char[1 + _szNom];
			std::memset(_nom, 0, 1 + _szNom);
			std::memcpy(_nom, j._nom, _szNom);

			_sensDuDeplacement = j._sensDuDeplacement;
		}
	}

	Joueur& Joueur::operator=(const Joueur& j)
	{
		if (this != &j)
		{
			_couleur = j._couleur;
			_id = j._id;
			_nature = j._nature;

			if (_nom != nullptr)
			{
				delete _nom;
				_nom = nullptr;
				_szNom = 0;
			}

			if (j._nom != nullptr)
			{
				_szNom = std::strlen(j._nom);
				_nom = new char[1 + _szNom];
				std::memset(_nom, 0, 1 + _szNom);
				std::memcpy(_nom, j._nom, _szNom);
			}

			_sensDuDeplacement = j._sensDuDeplacement;
		}

		return *this;
	}

	void spc_joueurs::Joueur::init(
		const IdJoueur& id
		, const CouleurPion& couleur
		, const char* nom
		, const SensDuDeplacement& sensDuDeplacement
		, const NatureJoueur& nature
	)
	{
		_id = id;
		_couleur = couleur;
		_nature = nature;
		if (_nom != nullptr)
		{
			delete _nom;
			_nom = nullptr;
			_szNom = 0;
		}
		if (nom != nullptr)
		{
			_szNom = std::strlen(nom);
			_nom = new char[1 + _szNom];
			std::memset(_nom, 0, 1 + _szNom);
			std::memcpy(_nom, nom, _szNom);
			_sensDuDeplacement = sensDuDeplacement;
		}
	}
}
*/
