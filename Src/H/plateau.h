// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# include <map>

# ifndef _PLATEAU_H_
  # define _PLATEAU_H_ (1)
  namespace spc_plateau
  {
      /* La couleur d'un pion */
      enum class couleur_pion
      {
          blanc
        , noir
      } ;

      /* La couleur d'une case */
      enum class couleur_case
      {
          blanc
        , noir
      } ;

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
        void setEnSurbrillance(void);
        void resetSurbrillance(void);
      private :
        couleur_pion _couleur ;
        promotion_pion _promotion ;
        apparence_pion _apparence ;
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
        void init(couleur_case couleur, bool libre, Pion pion, int x, int y, int notation, apparence_case apparence) ;
        void affiche(void);
        void setEnSurbrillance(void);
        void resetSurbrillance(void);
      private :
        couleur_case _couleur ;
        bool _estLibre ;
        Pion* _pion ;
        int _x ;
        int _y ;
        int _notationOfficielle ;
        apparence_case _apparence ;
      };

      /* Un joueur est caractérisé par la couleur qu'il joue et sa nature (humain ou intelligence artificielle)
      **/
      class Joueur
      {
      public :
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
        CasePlateau _prises [20] ;
        CasePlateau _cheminRafle ;
        char* _commentaire ;
      };

      class Plateau
      {
      public :
        Plateau(Joueur joueur1, Joueur joueur2) ;
        ~Plateau() = default ;
        Plateau(const Plateau& p) = default ;
        Plateau& operator = (const Plateau& p) = default ;
        /*
        int deplacerPion(CasePlateau positionDepart, CasePlateau positionArrivee) ;
        bool finDePartie(void);
        CasePlateau& getCasePlateau(int x, int y); 
        void affiche(void);
        void resetSurbrillance(void);  // Annule la surbrillance de toutes les case et pions du plateau
        void afficheListeDesCoups(void);
        int getNombreDeCoups(void);
        */
      private :
        CasePlateau _cases [51] ; // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
        Coup _historique [500] ; // Historique des coup ; TODO : en faire une liste pour ne plus avoir de limite
        int _nombreDeCoups ;
        Joueur _joueur1 ;
        Joueur _joueur2 ;
        Joueur* _prochain ; // Celui des deux joueurs devant jouer le prochain coup
      };

      class Dummy
      {
      public :
      private :
      };
  }
# endif // _PLATEAU_H_
