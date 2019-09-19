// constantes.h

# ifndef CONSTANTES_H
# define CONSTANTES_H (1)

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
   
   # define MOTIF_PLATEAU_DAMIER \
            { \
               ' ', ' ', ' ', ' ', ' ', 'a', ' ', ' ', ' ', 'b', ' ', ' ', ' ', 'c', ' ', ' ', ' ', 'd', ' ', ' ', ' ', 'e', ' ', ' ', ' ', 'f', ' ', ' ', ' ', 'g', ' ', ' ', ' ', 'h', ' ', ' ', ' ', 'i', ' ', ' ', ' ', 'j', ' ', ' ', ' ', ' ', ' ', '\n'        \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  '1', '0', ' ', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', '1', '0', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '9', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', ' ', '9', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '8', ' ', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', '8', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '7', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', ' ', '7', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '6', ' ', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', '6', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '5', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', ' ', '5', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '4', ' ', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', '4', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '3', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', ' ', '3', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '2', ' ', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', '2', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', '1', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', '/', '/', '/', '|', ' ', ' ', ' ', '|', ' ', '1', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', '-', '-', '-', '+', ' ', ' ', ' ', '\n'  	   \
            ,  ' ', ' ', ' ', ' ', ' ', 'a', ' ', ' ', ' ', 'b', ' ', ' ', ' ', 'c', ' ', ' ', ' ', 'd', ' ', ' ', ' ', 'e', ' ', ' ', ' ', 'f', ' ', ' ', ' ', 'g', ' ', ' ', ' ', 'h', ' ', ' ', ' ', 'i', ' ', ' ', ' ', 'j', ' ', ' ', ' ', ' ', ' ', '\0'  	   \
            }																																																								   
   
   
   # define MOTIF_TEXTE_ENTETE \
   	{ \
               ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'                   \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'J', 'e', 'u', ' ', 'd', 'e', ' ', 'D', 'a', 'm', 'e', 's', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  'J', 'o', 'u', 'e', 'u', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'    \
   	}
   
   # define MOTIF_TEXTE_ENQUEUE \
   	{ \
               ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'                   \
            ,  'J', 'o', 'u', 'e', 'u', 'r', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'    \
            ,  'L', 'e', 's', ' ', '.', '.', '.', '.', '.', '.',  ' ', 'j', 'o', 'u', 'e', 'n', 't', ' ', '(', 'Q', ' ', 'p', 'o', 'u', 'r', ' ', 'a', 'b', 'a', 'n', 'd', 'o', 'n', 'n', 'e', 'r', ')', ' ', '/', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', '\n'    \
            ,  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\0'    \
   	}
   
   # define NB_CHAR_PAR_LIGNE (static_cast<unsigned int>(48)) // Nombre de caract�res par ligne de de l'ardoise, du numero au num�ro
   # define NB_CASES_PLATEAU (static_cast<int>(50 + 0)) // 50 cases noires num�rot�es de 01 � 50 ; la case 00 est blanche ; le num�ro de la case correspond � son indice
   # define NB_DIAGONALES_MAX_PAR_CASE (static_cast<int>(2)) // Une case ne peut appartenir qu'� une ou deux diagonales
   # define NB_DIAGONALES_PLATEAU (static_cast<int>(19))  // de une � 10 cases de suite par diagonale
   # define NB_DE_COUPS_PAR_LOT (static_cast<int>(50)) // Nombre de coups ajout�s � chaque lot
   # define NB_JOUEURS (static_cast<int>(2))
   # define NB_PIONS_PAR_COULEUR (static_cast<int>(20))
   # define NB_X_REF_CELLULES (static_cast<int>(12))
   # define NB_Y_REF_CELLULES (static_cast<int>(23))   // 10 lignes de cases + 2 lignes d'ent�te et enqueue + 11 lignes de separeteurs
   # define NB_Y_REF_CELLULES_ENTETE (static_cast<int>(6))
   # define NB_Y_REF_CELLULES_ENQUEUE (static_cast<int>(6))
   # define TAILLE_CELLULE (static_cast<unsigned int>(3))
   # define TAILLE_COTE_ARDOISE (static_cast<unsigned int>(10))
   # define TAILLE_SEPARATEUR (static_cast<unsigned int>(1))
}

namespace spc_dames
{
	enum class eCouleur
	{
		  blanc
		, noir
	};

	enum class ePlacementJoueurs
	{
		  blancs_noirs  // les blancs occupent les cases 1 � 20, les noirs sont sur les 31 � 50
		, noirs_blancs  // les noirs occupent les cases 1 � 20, les blancs sont plac�s sur les 31 � 50
	};
}

# endif // CONSTANTES_H
