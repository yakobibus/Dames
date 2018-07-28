// regles.h


# ifndef _REGLES_H_
  # define _REGLES_H_ (1)


 namespace spc_regles
  {
// Movement - Regle 1 : La case de départ doit être occupée par un pion de la même couleur que le joueur
//            Règle 2 : La case destination pour un déplacement, une prise, une étape de raffle doit être libre
//            Règle 3 : Pour un déplacement (pion), la case destination doit être voisine de la case de départ en diagonale vers l'avant par rapport à la couleur en jeu
//            Règle 4 : Pour un déplacement (reine), la case destination doit être dans la diagonale et aucun pion ne doit se trouver entre les deux
      # include "plateau.h"

	  class Regles
	  {
	  public :
	  private :
		  spc_plateau::Plateau _plateau;
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

	  /*
	  Blancs [/o/] <<==       vs        ==>> [/x/] Noirs
	  --------------------------------------------------
	  Les Blancs ont la main       Les Noirs ont la main

	                - Q pour abandonner -

	        Départ   :
			Arrivée :

	  **/

	  /*
	  Déroulement d'une partie :

	  I. Construction :
	  1. Initialiser le damier
	  1.1 Cases 50 noires : 5 par ligne sur 10 lignes
	  1.2 Pions : 20 pions blancs et 20 noirs placés à chaque extétrémité ; 2 lignes vides au milieu
	  1.3 Fixer le premier joueur ayant la main : le joueur disposant des blancs ; les blancs commencent toujours

	  II. Jouer (chaque joueur déplace un pion) :
	  1. Tant que la partie continue 
	     FAIRE
			1.1 Dessiner le Damier
			1.2 Donner la main au joueur actif
			1.2.1 Afficher l'invite de la saisie CaseDépart
			1.2.1 Evaluer la pertinence de la case départ
			1.2.1.1 La CaseDépart doit être occupée par un pion de la couleur du joueur
			1.2.1.2 Le pion de la case départ doit être mobilisable :
			1.2.1.2.1 Si c'est un pion : 
			1.2.1.2.1.1 SI la prochaine case en diagonale dans le sens de la marche du pion est libre alors MOBILISABLE
			1.2.1.2.1.2 SInon (diagonale occupée dans le sens de la marche du pion)
			1.2.1.2.1.2.1 SI la case après la case immédiatement occupée dans le sens de la marche l'est par la couleur opposée
			1.2.1.2.1.2.1.1 SI la case immédiatement en diagonale après le pion opposé est libre, alors MOBILISABLE et le pion opposé est PRENABLE
			1.2.1.2.1.2.1.2 SInon NonMOBILISABLE
			1.2.1.2.1.2.1.3 FinSI
			1.2.1.2.1.2.2 SInon NonMOBILISABLE
			1.2.1.2.1.2.3 FinSI
			1.2.1.2.1.3 FinSI
			1.2.1.9 Afficher le Dalier avec la case départ en surbrillance + la référence de la saisieDépart
			1.2.2 Afficher l'invite de la saisie CaseArrivée
			1.2.3 Evaluer la pertinence de la CaseArrivée
			1.3 Evaluer la coup (Est-ce la fin de partie ?)
			1.4 Changer de main (le joueur actif devient le joueur opposé si la partie continue)
	     Fin FAIRE
	  **/
  }
# endif  //  _REGLES_H_
