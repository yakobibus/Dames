// plateau.h


/* Le plateau de jeu et tout ce qui y touche : damier, pions joueurs ... */

# include <iostream>
# include <map>
# include <locale>
# include <cstring>
//# include <string>
//# include <cctype>
//# include <cstdio>



# ifndef _PLATEAU_H_
  # define _PLATEAU_H_ (1)

# include "constantes.h"
# include "regles.h"

  namespace spc_plateau
  {
      using namespace spc_regles;

	  // ----------------------------------------------------------------------

	  class CasePlateau ;
	  class Diagonale ;
	  class Pion ;
	  class Plateau ;

      // ----------------------------------------------------------------------

	  enum class apparence_case
	  {
		  normal
		  , surbrillance
	  };

	  enum class apparence_pion
	  {
		  normal
		  , surbrillance
	  };

	  /* La couleur d'une case */
      enum class couleur_case
      {
          blanc
        , noir
      } ;
      std::ostream& operator << (std::ostream& os, const couleur_case& cc) ;

      /* La couleur d'un pion */
      enum class couleur_pion
      {
          blanc
        , noir
        //, friend std::ostream& operator << (std::ostream& os, const couleur_pion& cp);
      } ;
      std::ostream& operator << (std::ostream& os, const couleur_pion& cp) ;

	  enum class etapes_du_coup
	  {
		    indefini = 0
		  , debut
		  , input_depart
		  , evaluation_depart
		  , depart_error
		  , depart_ok
		  , input_arrivee
		  , evaluation_arrivee
		  , arrivee_error
		  , arrivee_ok
	  };

	  enum class input_token
	  {
		  neutral = 0
		  , badInteger = -1
		  , badColumn = -2
		  , badLine = -3
		  , badCase = -4
		  , error = -5
		  , okInteger = 1
		  , okColumn = 2
		  , okLine = 3
		  , okCase = 4
		  , quit = 5
	  };

	  enum class input_type
	  {
		  is_undefined = 0
		  , is_digitOne = 1
		  , is_alphaOne = 2
		  , is_digitTwo = 4
		  , is_alphaTwo = 8
		  , is_digitThree = 16
		  , is_alphaThree = 32
	  };

	  enum class nature_joueur
      {
          humain
        , ia
      };

      enum class promotion_pion
      {
          normal
        , dame
      };

	  enum class sens_attaque_pion
	  {
		    neutre = 0 // Sert pour les initialisations
		  , descendant  = 1  // Haut vers Bas
		  , ascendant = 2 // Bas vers Haut
		  , tousAzimuts = 3 // pour les déplacements des reines
	  } ;

      /* Les types de coups : prise ou deplacement */
      enum class type_coup
      {
          prise
        , deplacement
      } ;

	  /* Une case est définie par une couleur (noire/banche) et,
	  si elle est noire, elle dispose d'une abscisse (x) et une ordonnée (y) sur le plateau.
	  Une case peut être libre ou non. Quand elle n'est pas libre elle contient un pion.
	  **/
	  class CasePlateau
	  {
	  public:
		  CasePlateau();
		  ~CasePlateau() = default;
		  CasePlateau(const CasePlateau& c) = default;
		  CasePlateau& operator = (const CasePlateau& c);
		  //
		  void affiche(void);
		  inline const bool estLibre(void) const { return _estLibre; }
		  inline const int getY(void) const { return _y; }
		  inline const int getX(void) const { return _x; }
		  inline const char* separateur(void) const { return _separateur; }
		  //couleur_pion couleurPion(void) {return _pion->getCouleur();}
		  void init(int x, int y, int notation, Pion* pion, apparence_case apparence, couleur_case couleur);
		  void resetSurbrillance(void);
		  void setPion(Pion* pion);
		  void setEnSurbrillance(void);
		  void setDiagonale(const Diagonale* diagonale) ;
		  const Diagonale* diagonale(const unsigned int& index) const ;
		  inline Pion* pion(void) const {return _pion ;}
		  inline int notationOfficielle(void) const { return _notationOfficielle; }
		  inline int notationOfficielle(int y, int x) const { return (y == _y && x == _x ? _notationOfficielle : 0); }
	  private:
		  couleur_case _couleur;
		  bool _estLibre;
		  Pion* _pion;
		  int _x;
		  int _y;
		  const Diagonale* _diagonale[NB_DIAGONALES_MAX_PAR_CASE]; 
		  int _notationOfficielle;
		  apparence_case _apparence;
		  char _motif[MOTIF_SIZE];
		  char _motifSurbrillance[MOTIF_SIZE];
		  const char _separateur[2] = "|";
	  };

	  class Commentaire
	  {
	  public:
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
		  };
	  private:
		  std::map<std::string, std::string> _commentaires
		  {
			  { "!", "Coup fort ou bien joué" }
			  ,{ "!!", "Coup très fort" }
			  ,{ "?", "Coup faible ou mal joué" }
			  ,{ "??", "Coup très faible ou une gaffe" }
			  ,{ "!?", "Coup paraissant fort, mais qui en réalité se révèle faible" }
			  ,{ "?!", "Coup paraissant faible, mais qui en réalité se révèle fort" }
			  ,{ "*", "Coup forcé, tout autre mouvement entraînant une perte immédiate" }
			  ,{ "+", "Gain de la partie" }
			  ,{ "=", "Jeu égal" }
			  ,{ "+1", "Gain d’un pion" }
			  ,{ "+n", "Gain de n pions" }
			  ,{ "+-", "Avantage aux blancs" }
			  ,{ "-+", "Avantage aux noirs" }
		  };
		  std::string _commentaire;
	  };

	  class Coup
	  {
	  public:
		  Coup() : _etape(etapes_du_coup::indefini), _nombreDePrises(0), _commentaire(nullptr) {}
		  ~Coup() = default ;
		  Coup(const Coup& c) = default ;
		  Coup& operator = (const Coup& c) = default ;

		  inline CasePlateau& caseDepart(void) { return _caseDepart ; }
		  inline const etapes_du_coup& etape(void) const { return _etape ; }
		  inline void setEtape(const etapes_du_coup& etape) { _etape = etape ; }
		  void setCaseDepart(const CasePlateau& caseDepart) { _caseDepart = caseDepart; }
	  private:
		  CasePlateau _caseDepart ;
		  CasePlateau _caseArrivee ;
		  couleur_pion _couleur ;
		  etapes_du_coup _etape ;
		  type_coup _typeDeCoup ;
		  int _nombreDePrises ;
		  CasePlateau _prises[NB_MX_COUPS_PAR_PRISE] ;
		  CasePlateau _cheminRafle[NB_MX_COUPS_PAR_RAFLE] ;
		  char* _commentaire ;
	  };

	  class Diagonale
	  {
	  public:
		  Diagonale();
		  ~Diagonale();
		  Diagonale(const Diagonale& d);
		  Diagonale& operator = (const Diagonale& d);
		  //
		  int addCase(CasePlateau* c);
		  int init(int taille, CasePlateau** c);
	  private:
		  int _taille;
		  CasePlateau** _cases;
	  };

	  class Input
	  {
	  public:
		  Input() = default;
		  ~Input() = default;
		  Input(const Input& i) = default;
		  Input& operator = (const Input& i) = default;

		  void InputCase(Plateau& plateau/*, CasePlateau& casePlateau*/, const char* invite);
		  const input_token& token(void) const { return _token; }
		  inline const CasePlateau* casePlateau(void) const { return _casePlateau ; }
	  private:
		  //inline bool _isAlpha(const char& c) { std::locale loc ; return (((c >='a' && c <= 'j') || (c >= 'A' && c <= 'J')) && std::isalpha(c, loc)) ;}
		  //inline bool _isAlpha(const char& c) { return (((c >= 'a' && c <= 'j') || (c >= 'A' && c <= 'J')) && isalpha(c)); }
		  inline bool _isAlpha(const char& c) { return IS_ALPHA_DAMIER(c); }
		  inline int _aToColumn(const char& colonne) {
			  return (
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
				  );
		  }
		  void _scanner(int index);
		  //void parser(void) ; // 169
		  char _buffer[BUFFER_MX_SIZE];
		  int _bufSize = 0;
		  input_type _input_type[INPUT_TYPE_ARRAY_SIZE];
		  input_token _token;
		  CasePlateau* _casePlateau;
	  };

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
        inline const couleur_pion couleur(void) const {return _couleur ;}
		inline const char* laCouleur(void) const { return (_couleur == couleur_pion::blanc ? "Blancs" : "Noirs") ;}
      private :
        couleur_pion _couleur ;
        nature_joueur _nature ;
      };

	  /* Un pion est déterminé par sa couleur et sa promotion */
      class Pion
      {
      public :
        Pion(couleur_pion couleur);
        ~Pion() = default ;
        Pion(const Pion& p) = default ;
        Pion& operator = (const Pion& p) = default ;
        //
		void const affiche(void) const ; 
		apparence_pion apparence(void) { return _apparence; }
        couleur_pion getCouleur(void) {return _couleur;}
        inline const char* motif(void) const {return _motif ;}
        void resetSurbrillance(void);
		void setApparence(const apparence_pion& apparence) { _apparence = apparence; }
        void setCouleur(couleur_pion couleur);
        void setEnSurbrillance(void);
		void setSensAttaque(const sens_attaque_pion& sens) { _sens_attaque = sens; }
		inline sens_attaque_pion& sens_attaque(void) { return _sens_attaque; }
        //
        friend std::ostream& operator << (std::ostream& os, const Pion& p) {switch(p._couleur) {case couleur_pion::blanc : os << "pion blanc" ; break ;case couleur_pion::noir : os << "pion noir";break; default : os << "curieuse couleur de pion";break;} return os;}
      private :
        couleur_pion _couleur ;
		sens_attaque_pion _sens_attaque;
        promotion_pion _promotion ;
        apparence_pion _apparence ;
        char _motif[MOTIF_SIZE] ;
        char _motifSurbrillance[MOTIF_SIZE] ;
      };

	  class LeTrait
	  {
	  public:
		  LeTrait(int sz = 0);
		  ~LeTrait() = default;
		  LeTrait(const LeTrait& l) = default;
		  LeTrait& operator = (const LeTrait& l) = default;

		  void init(int size);

		  friend std::ostream& operator << (std::ostream& os, const LeTrait& t);
	  private:
		  int _sz;
		  char _buffer[255];
	  };

	  class Plateau
	  {
	  private:
		  class PiedDePage
		  {
		  public :
			  PiedDePage();
			  ~PiedDePage() = default;
			  PiedDePage(const PiedDePage& p) = default;
			  PiedDePage& operator = (const PiedDePage& p) = default;

			  void affiche(const char* errorMsg) ;
			  void init(Plateau& plateau, const Joueur* joueur, const Coup& coup) ;
			  inline const char* invite(void) const { return _invite ; }
			  inline const char* const marge(void) const { return _marge; }
		  private :
			  char* _lpad(char* str, const int& size = SZ_LIGNE_PIED_DE_PAGE) ;
			  char* _rpad(char* str, const int& size = -1 + SZ_LIGNE_PIED_DE_PAGE) ;
			  char _lignes[NB_LIGNES_PIED_DE_PAGE][SZ_LIGNE_PIED_DE_PAGE] ;
			  const char _marge[1 + SZ_MARGE_PIED_DE_PAGE] = MARGE_PIED_DE_PAGE;
			  char _buffer[111] ;
			  const char _motif = ' ' ;
			  char _invite[SZ_INVITE] ;
		  } ;
	  public:
		  Plateau(Joueur joueur1, Joueur joueur2);
		  ~Plateau() = default;
		  Plateau(const Plateau& p) = default;
		  Plateau& operator = (const Plateau& p) = default;
		  //
		  void affiche(void);
		  void afficheFinDePartie(void);
		  void afficheTitre(void);
		  inline void ligne(void) { std::cout << MOTIF_TRAIT_DAMIER << std::endl; }
		  inline void ligneLettres(void) { std::cout << MOTIF_LETTRES_DAMIER; }
		  void initDiagonales(void);
		  int notationCase(const int& y, const int& x) const;
		  int jouer(void);
		  inline const CasePlateau& casePlateau(const int& notation) const { return _cases[notation]; }
		  inline CasePlateau* adresseCasePlateau(const int& notation) { return &(_cases[notation]); }
		  inline void aloueCasePlateau(const int& notation, CasePlateau& casePlateau) { casePlateau = _cases[notation]; }
//TODO: boolean casesVoisines(caseDepart, caseArrivee, sensDeplacementPion);
		  //
		  /*
		  // inline const char* errorMsg(void) const { return _errorMsg; }
		  void oldInitDiagonales(void) ;
		  bool setCoup(std::string& message) ;
		  inline void aloueCasePlateau(const int& notation, CasePlateau& casePlateau) {casePlateau = _cases[notation] ;}
		  int deplacerPion(CasePlateau positionDepart, CasePlateau positionArrivee) ;
		  bool finDePartie(void);
		  CasePlateau& casePlateau(int x, int y);
		  void resetSurbrillance(void);  // Annule la surbrillance de toutes les case et pions du plateau
		  void afficheListeDesCoups(void);
		  int nombreDeCoups(void);
		  */
	  private:
		  const char _titre[24] = "*** Jeux de Dames ***";
		  CasePlateau _cases[NB_CASES_PLATEAU]; // 50 cases noires numérotées de 01 à 50 ; la case 00 est blanche ; le numéro de la case correspond à son indice
		  Coup _historique[NB_MX_COUPS_HISTORIQUE]; // Historique des coup ; TODO : en faire une liste pour ne plus avoir de limite
		  Diagonale _diagonales[NB_DIAGONALES_PLATEAU];  // j'ai ajouté les deux diagonales d'une seule case
		  int _nombreDeCoups;
		  Joueur _joueur1;
		  Joueur _joueur2;
		  Pion _pionsBlancs[NB_PIONS_PAR_COULEUR];
		  Pion _pionsNoirs[NB_PIONS_PAR_COULEUR];
		  Joueur* _prochain; // Celui des deux joueurs devant jouer le prochain coup
		  bool _finDePartie = false;
		  Coup _coupEnCours; // Coup en cours
		  Input _input;
		  Regles _regles;
		  PiedDePage _piedDePage;
		  char _errorMsg[BUFFER_ERR_MX_SIZE];
		  //void _strcopy(char* target, char* source) { strcpy(target, source); }
		  //inline void _trait(const int& size) const { for (int i = 0; i < size; ++i) { std::cout << '-'; } std::cout << std::endl; }
		  LeTrait _leTrait;
	  };

      class Dummy
      {
      public :
		  Dummy() : _ii(55) { _tt.init(_ii); std::cout << _tt << std::endl; }
		  ~Dummy() = default;
		  Dummy(const Dummy& d) = default;
		  Dummy& operator = (const Dummy& d) = default;
		  void Ho(void) const { _yo.ha() ; }
      private :
		  class Yo
		  {
		  public :
			  void ha(void) const { std::cout << "En Yo::ha, ii=[" << ii << "]\n"; }
		  private :
		  };
		  Yo _yo;
		  static const int ii = 55;
		  //
		  int _ii = 5;
		  LeTrait _tt;
      };
  }
# endif // _PLATEAU_H_
