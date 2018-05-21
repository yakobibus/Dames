// regles.h

# ifndef _REGLES_H_
  # define _REGLES_H_ (1)
  namespace spc_regles
  {
// Movement - Regle 1 : La case de départ doit être occupée par un pion de la même couleur que le joueur
//            Règle 2 : La case destination pour un déplacement, une prise, une étape de raffle doit être libre
//            Règle 3 : Pour un déplacement (pion), la case destination doit être voisine de la case de départ en diagonale vers l'avant par rapport à la couleur en jeu
//            Règle 4 : Pour un déplacement (reine), la case destination doit être dans la diagonale et aucun pion ne doit se trouver entre les deux
	  class Regle
	  {
	  public :
	  private :
	  };
      /*
         Une diagonale est une suite de 2 cases au moins et de 10 au plus sur un damier ; 
         Une diagonale de taille paire a une orientation nord-est/ ; taille impaire orientation nord-ouest

      Positions de départ des blancs (o) et des noirs (x)
           a   b   c   d   e   f   g   h   i   j
         +---+---+---+---+---+---+---+---+---+---+
      10 |   | x |   | x |   | x |   | x |   | x | 10
         +---+---+---+---+---+---+---+---+---+---+
       9 | x |   | x |   | x |   | x |   | x |   | 9
         +---+---+---+---+---+---+---+---+---+---+
       8 |   | x |   | x |   | x |   | x |   | x | 8
         +---+---+---+---+---+---+---+---+---+---+
       7 | x |   | x |   | x |   | x |   | x |   | 7
         +---+---+---+---+---+---+---+---+---+---+
       6 |   |   |   |   |   |   |   |   |   |   | 6
         +---+---+---+---+---+---+---+---+---+---+
       5 |   |   |   |   |   |   |   |   |   |   | 5
         +---+---+---+---+---+---+---+---+---+---+
       4 |   | o |   | o |   | o |   | o |   | o | 4
         +---+---+---+---+---+---+---+---+---+---+
       3 | o |   | o |   | o |   | o |   | o |   | 3
         +---+---+---+---+---+---+---+---+---+---+
       2 |   | o |   | o |   | o |   | o |   | o | 2
         +---+---+---+---+---+---+---+---+---+---+
       1 | o |   | o |   | o |   | o |   | o |   | 1
         +---+---+---+---+---+---+---+---+---+---+
           a   b   c   d   e   f   g   h   i   j

      Notation MANOURY :
           a   b   c   d   e   f   g   h   i   j
         +---+---+---+---+---+---+---+---+---+---+
      10 |   | 1 |   | 2 |   | 3 |   | 4 |   | 5 | 10
         +---+---+---+---+---+---+---+---+---+---+
       9 | 6 |   | 7 |   | 8 |   | 9 |   |10 |   | 9
         +---+---+---+---+---+---+---+---+---+---+
       8 |   |11 |   |12 |   |13 |   |14 |   |15 | 8
         +---+---+---+---+---+---+---+---+---+---+
       7 |16 |   |17 |   |18 |   |19 |   |20 |   | 7
         +---+---+---+---+---+---+---+---+---+---+
       6 |   |21 |   |22 |   |23 |   |24 |   |25 | 6
         +---+---+---+---+---+---+---+---+---+---+
       5 |26 |   |27 |   |28 |   |29 |   |30 |   | 5
         +---+---+---+---+---+---+---+---+---+---+
       4 |   |31 |   |32 |   |33 |   |34 |   |35 | 4
         +---+---+---+---+---+---+---+---+---+---+
       3 |36 |   |37 |   |38 |   |39 |   |40 |   | 3
         +---+---+---+---+---+---+---+---+---+---+
       2 |   |41 |   |42 |   |43 |   |44 |   |45 | 2
         +---+---+---+---+---+---+---+---+---+---+
       1 |46 |   |47 |   |48 |   |49 |   |50 |   | 1
         +---+---+---+---+---+---+---+---+---+---+
           a   b   c   d   e   f   g   h   i   j
      **/
  }
# endif  //  _REGLES_H_
