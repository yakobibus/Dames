// regles.h


# ifndef _REGLES_H_
  # define _REGLES_H_ (1)


 namespace spc_regles
  {
	 // Placement - Règle P1 : Le damier s'affiche en Haut vers Bas (Nord vers Sud)
	 //             Règle P2 : Le placement se fait blancs_noirs (Blancs au Nord) ou noirs_blancs (Noirs au Nord)
	 //             Règle P3 : Les Blancs ont l'ouverture du jeu

// Movement - Règle M1 : La case est Noire
//            Règle M2 : La case de départ doit être occupée par un pion de la même couleur que le joueur
//            Règle M3 : La case destination pour un déplacement, une prise, une étape de raffle doit être libre
//            Règle M4 : Pour un déplacement (pion), la case destination doit être voisine de la case de départ en diagonale vers l'avant par rapport à la couleur en jeu
//            Règle M5 : Pour un déplacement (reine), la case destination doit être dans la diagonale et aucun pion ne doit se trouver entre les deux

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
       6 |   |///|   |///|   |///|   |///|   |///| 6
         +---+---+---+---+---+---+---+---+---+---+
       5 |///|   |///|   |///|   |///|   |///|   | 5
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
Le Damier :
1148 caractères =
  1125 chars affichables + 
    22 eol + 
	1 asiiNull

Composition de :
  23 lignes
Chaque ligne : 
  48 caractères :
     47 car affichables + 
	 1 eol/asciiNull
  Les 48 cars :
     12 groupes de 4 cars - 1 mot :
	    12 x (3 cars + 1 separateur/eol/asciiNull)
           1 mot = 3 car + 
		           1 séparateur 
.....a...b...c...d...e...f...g...h...i...j.....
...+---+---+---+---+---+---+---+---+---+---+...
10.|...|:::|...|:::|...|:::|...|:::|...|:::|.10
...+---+---+---+---+---+---+---+---+---+---+...
.9.|:::|...|:::|...|:::|...|:::|...|:::|...|.9.
...+---+---+---+---+---+---+---+---+---+---+...
.8.|...|:::|...|:::|...|:::|...|:::|...|:::|.8.
...+---+---+---+---+---+---+---+---+---+---+...
.7.|:::|...|:::|...|:::|...|:::|...|:::|...|.7.
...+---+---+---+---+---+---+---+---+---+---+...
.6.|...|:::|...|:::|...|:::|...|:::|...|:::|.6.
...+---+---+---+---+---+---+---+---+---+---+...
.5.|:::|...|:::|...|:::|...|:::|...|:::|...|.5.
...+---+---+---+---+---+---+---+---+---+---+...
.4.|...|:::|...|:::|...|:::|...|:::|...|:::|.4.
...+---+---+---+---+---+---+---+---+---+---+...
.3.|:::|...|:::|...|:::|...|:::|...|:::|...|.3.
...+---+---+---+---+---+---+---+---+---+---+...
.2.|...|:::|...|:::|...|:::|...|:::|...|:::|.2.
...+---+---+---+---+---+---+---+---+---+---+...
.1.|:::|...|:::|...|:::|...|:::|...|:::|...|.1.
...+---+---+---+---+---+---+---+---+---+---+...
.....a...b...c...d...e...f...g...h...i...j.....

y paire de [2 à 20] et x de [2 à 10 si y%4!=0, de 1 à 9 si y%4 ==0] => cellule

 0   1   2   3   4   5   6   7   8   9   0   1  <- x : _cellules
	 a   b   c   d   e   f   g   h   i   j         y == 0 : _cellules
   +---+---+---+---+---+---+---+---+---+---+	   y == 1
10 |   |:::|   |:::|   |:::|   |:::|   |:::| 10	   y == 2
   +---+---+---+---+---+---+---+---+---+---+	   y == 3
 9 |:::|   |:::|   |:::|   |:::|   |:::|   | 9	   y == 4
   +---+---+---+---+---+---+---+---+---+---+	   y == 5
 8 |   |:::|   |:::|   |:::|   |:::|   |:::| 8	   y == 6
   +---+---+---+---+---+---+---+---+---+---+	   y == 7
 7 |:::|   |:::|   |:::|   |:::|   |:::|   | 7	   y == 8
   +---+---+---+---+---+---+---+---+---+---+	   y == 9
 6 |   |:::|   |:::|   |:::|   |:::|   |:::| 6	   y == 10
   +---+---+---+---+---+---+---+---+---+---+	   y == 11
 5 |:::|   |:::|   |:::|   |:::|   |:::|   | 5	   y == 12
   +---+---+---+---+---+---+---+---+---+---+	   y == 13
 4 |   |:::|   |:::|   |:::|   |:::|   |:::| 4	   y == 14
   +---+---+---+---+---+---+---+---+---+---+	   y == 15
 3 |:::|   |:::|   |:::|   |:::|   |:::|   | 3	   y == 16
   +---+---+---+---+---+---+---+---+---+---+	   y == 17
 2 |   |:::|   |:::|   |:::|   |:::|   |:::| 2	   y == 18
   +---+---+---+---+---+---+---+---+---+---+	   y == 19
 1 |:::|   |:::|   |:::|   |:::|   |:::|   | 1	   y == 20
   +---+---+---+---+---+---+---+---+---+---+	   y == 21
	 a   b   c   d   e   f   g   h   i   j		   y == 22
*/

/*
Voisinage d'une case :
--------------------
   +---+---+---+---+---+---+---+---+---+---+	  Dans le cas nominal, les cases ont 4 voisines,
 3 | 1 |   | 2 |   |:::|   |:::|   |:::|   | 3	  Sauf celles qui sont sur un Bord qui n'en ont que 2
   +---+---+---+---+---+---+---+---+---+---+	  Et Sauf celles qui sont aux extrémité de la grande diagonale qui n'en ont qu'1
 2 |   | o |   |:::|   |:::|   |:::|   |:::| 2	  Ont un nombre de voisines de :
   +---+---+---+---+---+---+---+---+---+---+	  - 4 : 7, 8, 9, 10, 11, 12, 13, 14, 17, 18, 19, 20, 21, 22, 23, 24
 1 | 3 |   | 4 |   |:::|   |:::|   |:::|   | 1	      , 27, 28, 29, 30, 31, 32, 33, 34, 37, 38, 39, 40, 41, 42, 43, 44
   +---+---+---+---+---+---+---+---+---+---+	  - 2 : 1, 2, 3, 4, 6, 15, 16, 25, 26, 35, 36, 45, 47, 48, 49, 50
	 a   b   c   d   e   f   g   h   i   j		  - 1 : 5 et 46
*/



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
			-- Coup (Mouvement)
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
			1.2.3.1 SI CaseArrivée est NOIRE et VIDE (et est dans la diagonale de la CaseDépart)
			1.2.3.1.1 SI Pion (sans promotion)
			1.2.3.1.1.1 SI la CaseArrivée est dans la diagonale de la CaseDépart   ... à refactoriser : existe dans les deux branches de l'algo
			1.2.3.1.1.1.1 SI le déplacement est vers l'avant
			1.2.3.1.1.1.1.1 SI les CaseDépart et CaseArrivée sont contiguës
			1.2.3.1.1.1.1.1.1 CaseArrivéeVRAIE
			1.2.3.1.1.1.2 SInon
			1.2.3.1.1.1.2.1 SI les CaseDépart et CaseArrivée sont séparées d'une seule case
			1.2.3.1.1.1.2.1.1 SI la case intermédiaire est occupée par un pion de la couleur adverse
			1.2.3.1.1.1.2.1.1.1 CaseArrivéeVRAIE
			1.2.3.1.1.1.2.1.2 SInon
			1.2.3.1.1.1.2.1.2.1 CaseArrivéeFAUSSE
			1.2.3.1.1.1.2.1.3 FinSI
			1.2.3.1.1.1.2.2 SInon
			1.2.3.1.1.1.2.2.1 CaseArrivéeFAUSSE
			1.2.3.1.1.1.2.3 FinSI
			1?2.3.1.1.1.3 FinSI
			1.2.3.1.1.2 SInon
			1.2.3.1.1.2.1 CaseArrivéeFAUSSE
			1.2.3.1.1.3 FinSI
			1.2.3.1.2 SInon (c'est une dame)
			1.2.3.1.2.1 SI la CaseArrivée est dans la diagonale de la CaseDépart
			1.2.3.1.2.1.1 SI toutes les cases intermédiaires sont libres
			1.2.3.1.2.1.1.1 CaseArrivéeVRAIE
			1.2.3.1.2.1.2 SInon
			1.2.3.1.2.1.2.1 SI   ...ICI...
			1.2.3.1.2.1.2.2 SInon
			1.2.3.1.2.1.2.3 FinSI
			1.2.3.1.2.1.3 FinSI
			1.2.3.1.2.2 SInon
			1.2.3.1.2.2.1 CaseArrivéeFAUSSE
			1.2.3.1.2.3 FinSI
			1.2.3.1.2.3.1 CaseArrivéeFAUSSE
			1.2.3.1.3 FinSI
			1.2.3.2 SInon
			1.2.3.2.1 CaseArrivéeFAUSSE
			1.2.3.3 FinSI

			1.2.3.1 La CaseArrivée doit être une case NOIRE vide et sur une diagonale de la CaseDépart et (EnAvançant pour pion ordinaire ou qu'importe pour une Dame::promotion)
			1.2.3.1.1 SI la CaseArrivée est contigue de la CaseDépart (ce n'est pas une prise), alors ArrivéeValide
			1.2.3.1.2 SInon (la CaseArrivée n'est pas contigue de la CaseDépart)
			1.2.3.1.2.1 ..... (à réécrire en partant de la promotion)
			1.2.3.1.3 FinSI
			1.3 Evaluer la coup (Est-ce la fin de partie ?)
			1.4 Changer de main (le joueur actif devient le joueur opposé si la partie continue)
	     Fin FAIRE
	  **/
  }
# endif  //  _REGLES_H_
