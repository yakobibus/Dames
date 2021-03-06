// constantes.h

# ifndef CONSTANTES_H
# define CONSTANTES_H (1)

# include <string>

namespace spc_dames
{
   # define DUMMY_GAPS (static_cast<int>(99))
   # define INPUT_BUFFER_MX_SIZE (static_cast<unsigned int>(128))
   
   # define IS_ALPHA_DAMIER(c) ((c >= 'a' && c <= 'j') || (c >= 'A' && c <= 'J'))
   # define IS_DIGIT_DAMIER(c) (c >= '0' && c <= '9')
   
   # define DETAIL_MOTIF_NORMAL '/'
   # define DETAIL_MOTIF_BOLD   '\\'
   
   # define MOTIF_NORMAL_PION_BLANC 'o'
   # define MOTIF_NORMAL_PION_NOIR  'x'
   # define MOTIF_PROMU_PION_BLANC  'O'
   # define MOTIF_PROMU_PION_NOIR   'X'
   
   # define MOTIF_MANOURY                                                                       \
    {                                                                                           \
	      { {10, 2}, 1  }, { {10, 4}, 2  }, { {10, 6}, 3  }, { {10, 8}, 4  }, { {10, 10}, 5  }  \
		, { {9,  1}, 6  }, { {9,  3}, 7  }, { {9,  5}, 8  }, { {9,  7}, 9  }, { {9,  9 }, 10 }  \
		, { {8,  2}, 11 }, { {8,  4}, 12 }, { {8,  6}, 13 }, { {8,  8}, 14 }, { {8,  10}, 15 }  \
		, { {7,  1}, 16 }, { {7,  3}, 17 }, { {7,  5}, 18 }, { {7,  7}, 19 }, { {7,  9 }, 20 }  \
		, { {6,  2}, 21 }, { {6,  4}, 22 }, { {6,  6}, 23 }, { {6,  8}, 24 }, { {6,  10}, 25 }  \
		, { {5,  1}, 26 }, { {5,  3}, 27 }, { {5,  5}, 28 }, { {5,  7}, 29 }, { {5,  9 }, 30 }  \
		, { {4,  2}, 31 }, { {4,  4}, 32 }, { {4,  6}, 33 }, { {4,  8}, 34 }, { {4,  10}, 35 }  \
		, { {3,  1}, 36 }, { {3,  3}, 37 }, { {3,  5}, 38 }, { {3,  7}, 39 }, { {3,  9 }, 40 }  \
		, { {2,  2}, 41 }, { {2,  4}, 42 }, { {2,  6}, 43 }, { {2,  8}, 44 }, { {2,  10}, 45 }  \
		, { {1,  1}, 46 }, { {1,  3}, 47 }, { {1,  5}, 48 }, { {1,  7}, 49 }, { {1,  9 }, 50 }  \
	}

   # define MOTIF_PLATEAU_DAMIER \
            { \
               {{' ', ' ', ' '}, {' '}, {' ', 'a', ' '}, {' '}, {' ', 'b', ' '}, {' '}, {' ', 'c', ' '}, {' '}, {' ', 'd', ' '}, {' '}, {' ', 'e', ' '}, {' '}, {' ', 'f', ' '}, {' '}, {' ', 'g', ' '}, {' '}, {' ', 'h', ' '}, {' '}, {' ', 'i', ' '}, {' '}, {' ', 'j', ' '}, {' '}, {' ', ' ', ' '}, {'\n'}}        \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{'1', '0', ' '}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', '1', '0'}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '9', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {' ', '9', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '8', ' '}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', '8', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '7', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {' ', '7', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '6', ' '}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', '6', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '5', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {' ', '5', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '4', ' '}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', '4', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '3', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {' ', '3', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '2', ' '}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', '2', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', '1', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {'$', '$', '$'}, {'|'}, {' ', ' ', ' '}, {'|'}, {' ', '1', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {'-', '-', '-'}, {'+'}, {' ', ' ', ' '}, {'\n'}}  	   \
            ,  {{' ', ' ', ' '}, {' '}, {' ', 'a', ' '}, {' '}, {' ', 'b', ' '}, {' '}, {' ', 'c', ' '}, {' '}, {' ', 'd', ' '}, {' '}, {' ', 'e', ' '}, {' '}, {' ', 'f', ' '}, {' '}, {' ', 'g', ' '}, {' '}, {' ', 'h', ' '}, {' '}, {' ', 'i', ' '}, {' '}, {' ', 'j', ' '}, {' '}, {' ', ' ', ' '}, {'\0'}}  	   \
            }																																																								   


   # define MOTIF_TEXTE_ENTETE \
   	{ \
               {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'J', 'e', 'u', ' ', 'd', 'e', ' ', 'D', 'a', 'm', 'e', 's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\0'}}    \
   	}
   
   # define MOTIF_TEXTE_ENQUEUE \
   	{ \
               {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\n'}}    \
            ,  {{'L', 'e', 's'}, {' '}, {'.', '.', '.', '.', '.', '.'},  {' '}, {'j', 'o', 'u', 'e', 'n', 't', ' ', '(', 'Q', ' ', 'p', 'o', 'u', 'r', ' ', 'a', 'b', 'a', 'n', 'd', 'o', 'n', 'n', 'e', 'r', ')', ' ', '$', ' ', '\0', ' ', ' ', ' ', ' ',' ', ' '}, {'\0'}}    \
   	}
	//,  {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, {'\0'}}    
   
   # define NB_CHAR_PAR_LIGNE (static_cast<unsigned int>(48)) // Nombre de caractères par ligne de de l'ardoise, du numero au numéro
   # define NB_CASES_PLATEAU (static_cast<int>(50 + 0)) // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
   # define NB_DIAGONALES_MAX_PAR_CASE (static_cast<int>(2)) // Une case ne peut appartenir qu'à une ou deux diagonales
   # define NB_DIAGONALES_PLATEAU (static_cast<int>(19))  // de une à 10 cases de suite par diagonale
   # define NB_DE_COUPS_PAR_LOT (static_cast<int>(50)) // Nombre de coups ajoutés à chaque lot
   # define NB_JOUEURS (static_cast<int>(2))
   # define NB_PIONS_PAR_COULEUR (static_cast<int>(20))
   # define NB_X_REF_CELLULES (static_cast<int>(12))
   # define NB_Y_REF_CELLULES (static_cast<int>(23))   // 10 lignes de cases + 2 lignes d'entête et enqueue + 11 lignes de separeteurs
   # define NB_Y_REF_CELLULES_ENTETE (static_cast<int>(6))
   # define NB_Y_REF_CELLULES_ENQUEUE (static_cast<int>(6))
   # define TAILLE_CELLULE (static_cast<unsigned int>(3))
   # define TAILLE_COTE_ARDOISE (static_cast<unsigned int>(10))
   # define TAILLE_SEPARATEUR (static_cast<unsigned int>(1))
}

namespace spc_dames
{
	//enum class eCouleur
	//{
	//	  blanc
	//	, noir
	//};

	enum class ePlacementJoueurs
	{
		  blancs_noirs  // les blancs occupent les cases 1 à 20, les noirs sont sur les 31 à 50
		, noirs_blancs  // les noirs occupent les cases 1 à 20, les blancs sont placés sur les 31 à 50
	};

    enum class eSensAvance
    {
          negatif = -1 // les diagonales vont des grands vers les petits Manourys
        , nonDefini = 0  // à l'initialisation ?
        , positif = 1 // les diagonales vont des petis aux grands Manourys
    };

	class Couleur
	{
	public:
		enum class eCouleur
		{
			  blanc
			, noir
			, nonDefinie = 99
		};
		const std::string& couleurTexte(const eCouleur& couleur) const { return (eCouleur::blanc == couleur ? _blanc : (eCouleur::noir == couleur ? _noir : _nonDefinie)); }
	private:
		std::string  _blanc = "BLANCS";
		std::string  _noir  = "NOIRS";
		std::string  _nonDefinie = "";
	};
}

# endif // CONSTANTES_H
