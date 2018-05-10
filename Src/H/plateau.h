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
        Pion(couleur_pion couleur);
        ~Pion() = default ;
        Pion(const Pion& p) = default ;
        Pion& operator = (const Pion& p) = default ;
        //
        char* getMotif(void);
        void resetSurbrillance(void);
        void setCouleur(couleur_pion couleur);
        void setEnSurbrillance(void);
        couleur_pion getCouleur(void) {return _couleur;}
        int operator << (const Pion& p) {return static_cast<int>(_couleur);}
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
        inline int getY(void) {return _y;}
        inline int getX(void) {return _x;}
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
      };

      /* Un joueur est caractérisé par la couleur qu'il joue et sa nature (humain ou intelligence artificielle)
      **/
      class Joueur
      {
      public :
        Joueur() ;
        ~Joueur() = default ;
        Joueur(const Joueur& j) = default ;
        Joueur& operator = (const Joueur& j) = default ;
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
        CasePlateau _cheminRafle[20] ;
        char* _commentaire ;
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
        /*
        int deplacerPion(CasePlateau positionDepart, CasePlateau positionArrivee) ;
        bool finDePartie(void);
        CasePlateau& getCasePlateau(int x, int y); 
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
        Pion _pionsBlancs[20] ;
        Pion _pionsNoirs[20] ;
        Joueur* _prochain ; // Celui des deux joueurs devant jouer le prochain coup
      };

      class Dummy
      {
      public :
      private :
      };
  }
# endif // _PLATEAU_H_
