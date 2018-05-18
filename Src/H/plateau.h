// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# include <map>
# include <cstring>

# include "constantes.h"

# ifndef _PLATEAU_H_
  # define _PLATEAU_H_ (1)
  namespace spc_plateau
  {
      /* La couleur d'un pion */
      enum class couleur_pion
      {
          blanc
        , noir
        //, friend std::ostream& operator << (std::ostream& os, const couleur_pion& cp);
      } ;
      std::ostream& operator << (std::ostream& os, const couleur_pion& cp) ;

      /* La couleur d'une case */
      enum class couleur_case
      {
          blanc
        , noir
      } ;
      std::ostream& operator << (std::ostream& os, const couleur_case& cc) ;

      enum class apparence_case
      {
          normal
        , surbrillance
      } ;

      enum class apparence_pion
      {
          normal
        , surbrillance
      } ;

      enum class promotion_pion
      {
          normal
        , dame
      };

      enum class nature_joueur
      {
          humain
        , ia
      };

      /* Les types de coups : prise ou deplacement */
      enum class type_coup
      {
          prise
        , deplacement
      } ;

      /* Un pion est déterminé par sa couleur et sa promotion */
      class Pion
      {
      public :
        Pion(couleur_pion couleur);
        ~Pion() = default ;
        Pion(const Pion& p) = default ;
        Pion& operator = (const Pion& p) = default ;
        //
        void affiche(void) {std::cout << _couleur ;}
        void resetSurbrillance(void);
        void setCouleur(couleur_pion couleur);
        void setEnSurbrillance(void);
        couleur_pion getCouleur(void) {return _couleur;}
        friend std::ostream& operator << (std::ostream& os, const Pion& p) {switch(p._couleur) {case couleur_pion::blanc : os << "pion blanc" ; break ;case couleur_pion::noir : os << "pion noir";break; default : os << "curieuse couleur de pion";break;} return os;}
      private :
        couleur_pion _couleur ;
        promotion_pion _promotion ;
        apparence_pion _apparence ;
        char _motif[4] ;
        char _motifSurbrillance[4] ;
      };

      /* Une case est définie par une couleur (noire/banche) et, 
         si elle est noire, elle dispose d'une abscisse (x) et une ordonnée (y) sur le plateau.
         Une case peut être libre ou non. Quand elle n'est pas libre elle contient un pion.
      **/
      class CasePlateau
      {
      public :
        CasePlateau() ;
        ~CasePlateau() = default ;
        CasePlateau(const CasePlateau& c) = default ;
        CasePlateau& operator = (const CasePlateau& c) = default ;
        //
        void init(int x, int y, int notation, Pion* pion, apparence_case apparence, couleur_case couleur) ;
        void affiche(void);
        void setPion(Pion* pion) ;
        void resetSurbrillance(void);
        void setEnSurbrillance(void);
        inline int getNotation(void) {return _notationOfficielle ;}
        inline int getNotation(int y, int x) {return (y == _y && x == _x ? _notationOfficielle : 0) ;}
        inline int getY(void) {return _y;}
        inline int getX(void) {return _x;}
        inline const char* getSeparateur(void) {return _separateur ;}
        couleur_pion getCouleurPion(void) {return _pion->getCouleur();}
      private :
        couleur_case _couleur ;
        bool _estLibre ;
        Pion* _pion ;
        int _x ;
        int _y ;
        int _notationOfficielle ;
        apparence_case _apparence ;
        char _motif[4] ;
        char _motifSurbrillance[4] ;
        const char _separateur[2] = "|" ;
      } ;

      enum class input_token
      {
          neutral    = 0
        , badInteger = -1
        , badColumn  = -2
        , badLine    = -3
        , badCase    = -4
        , error      = -5
        , okInteger  = 1
        , okColumn   = 2
        , okLine     = 3
        , okCase     = 4
        , quit       = 5
      } ;

      enum class input_type
      {
        is_undefined  = 0
      , is_digitOne  = 1
      , is_alphaOne   = 2
      , is_digitTwo  = 4
      , is_alphaTwo   = 8
      , is_digitThree = 16
      , is_alphaThree  = 32
      } ;

      class Input
      {
      public :
        void InputCase(CasePlateau& casePlateau, input_token& token, const char* invite) ;
      private :
        inline bool _isAlpha(const char& c) {return (((c >='a' && c <= 'j') || (c >= 'A' && c <= 'J')) && isalpha(c)) ;}
        inline int _aToColumn(const char& colonne) {return (
                                  colonne == 'a' || colonne == 'A' ? 1 
                                : colonne == 'b' || colonne == 'B' ? 2 
                                : colonne == 'c' || colonne == 'C' ? 3
                                : colonne == 'd' || colonne == 'D' ? 4
                                : colonne == 'e' || colonne == 'E' ? 5
                                : colonne == 'f' || colonne == 'F' ? 6
                                : colonne == 'g' || colonne == 'G' ? 7
                                : colonne == 'h' || colonne == 'H' ? 8
                                : colonne == 'i' || colonne == 'I' ? 9
                                : colonne == 'j' || colonne == 'J' ? 10
                                : 0
                                ) ;}
        void _scanner(int index) ;
        //void parser(void) ; // 169
        char _buffer[BUFFER_MX_SIZE] ;
        int _bufSize = 0 ;
        input_type _input_type[INPUT_TYPE_ARRAY_SIZE] ;
        input_token _token ;
      } ;

      /* Un joueur est caractérisé par la couleur qu'il joue et sa nature (humain ou intelligence artificielle)
      **/
      class Joueur
      {
      public :
        Joueur(couleur_pion couleur = couleur_pion::blanc, nature_joueur nature  = nature_joueur::ia) ;
        ~Joueur() = default ;
        Joueur(const Joueur& j) = default ;
        Joueur& operator = (const Joueur& j) = default ;
        friend std::ostream& operator << (std::ostream& os, const Joueur& j) ;
        couleur_pion getCouleur(void) {return _couleur ;}
      private :
        couleur_pion _couleur ;
        nature_joueur _nature ;
      };

      class Commentaire 
      {
      public :
        enum class e_commentaire
        {
            coupFort
          , coupTresFort
          , coupFaible
          , coupTresFaible
          , coupFaussementFort
          , coupFaussementFaible
          , coupForcE
          , gainDePartie
          , Jeuegal
          , gain1pion
          , gainNpions
          , avantageAuxBlancs
          , avantageAuxNoirs
        } ;
      private :
        std::map<std::string, std::string> _commentaires 
        {
              {"!", "Coup fort ou bien joué"}
            , {"!!", "Coup très fort"}
            , {"?", "Coup faible ou mal joué"}
            , {"??", "Coup très faible ou une gaffe"}
            , {"!?", "Coup paraissant fort, mais qui en réalité se révèle faible"}
            , {"?!", "Coup paraissant faible, mais qui en réalité se révèle fort"} 
            , {"*", "Coup forcé, tout autre mouvement entraînant une perte immédiate"} 
            , {"+", "Gain de la partie"} 
            , {"=", "Jeu égal"} 
            , {"+1", "Gain d’un pion"} 
            , {"+n", "Gain de n pions"}
            , {"+-", "Avantage aux blancs"} 
            , {"-+", "Avantage aux noirs"} 
        } ;
        std::string _commentaire ;
      };
      
      class Coup
      {
      public :

      private :
        int _caseDepart ;
        int _caseArrivee ;
        type_coup _typeDeCoup ;
        int _nombreDePrises ;
        CasePlateau _prises [NB_MX_COUPS_PAR_PRISE] ;
        CasePlateau _cheminRafle[NB_MX_COUPS_PAR_RAFLE] ;
        char* _commentaire ;
      };

      class Diagonale
      {
      public :
        Diagonale() ;
        ~Diagonale() ;
        Diagonale(const Diagonale& d) ;
        Diagonale& operator = (const Diagonale& d) ;
        //
        int addCase(CasePlateau* c) ;
        int init(int taille, CasePlateau** c) ;
      private :
        int _taille ;
        CasePlateau** _cases ;
      };

      class Plateau
      {
      public :
        Plateau(Joueur joueur1, Joueur joueur2) ;
        ~Plateau() = default ;
        Plateau(const Plateau& p) = default ;
        Plateau& operator = (const Plateau& p) = default ;
        //
        void affiche(void);
        void afficheTitre(void) ;
        inline void ligne (void) {std::cout        << "     +---+---+---+---+---+---+---+---+---+---+" << std::endl ;}
        inline void ligneLettres (void) {std::cout << "       a   b   c   d   e   f   g   h   i   j" ;}
        void affichePiedDePage(void) ;
        void initDiagonales(void) ;
        int getNotationCase(const int& y, const int& x) ;
        void oldInitDiagonales(void) ;
        int jouer(void) ;
        bool setCoup(std::string& message) ;
        /*
        int deplacerPion(CasePlateau positionDepart, CasePlateau positionArrivee) ;
        bool finDePartie(void);
        CasePlateau& getCasePlateau(int x, int y); 
        void resetSurbrillance(void);  // Annule la surbrillance de toutes les case et pions du plateau
        void afficheListeDesCoups(void);
        int getNombreDeCoups(void);
        */
      private :
        const char titre[24] = "*** Jeux de Dames ***" ;
        CasePlateau _cases [NB_CASES_PLATEAU] ; // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
        Coup _historique [NB_MX_COUPS_HISTORIQUE] ; // Historique des coup ; TODO : en faire une liste pour ne plus avoir de limite
        Diagonale _diagonales[NB_DIAGONALES_PLATEAU] ;  // j'ai ajouté les deux diagonales d'une seule case
        int _nombreDeCoups ;
        Joueur _joueur1 ;
        Joueur _joueur2 ;
        Pion _pionsBlancs[NB_PIONS_PAR_COULEUR] ;
        Pion _pionsNoirs[NB_PIONS_PAR_COULEUR] ;
        Joueur* _prochain ; // Celui des deux joueurs devant jouer le prochain coup
        bool _finDePartie = false ;
        Coup _coup ; // Coup en cours
      };

      class Dummy
      {
      public :
      private :
      };
  }
# endif // _PLATEAU_H_
