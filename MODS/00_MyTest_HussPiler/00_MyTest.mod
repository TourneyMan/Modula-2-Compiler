MODULE Towers ;

VAR
    numDisks	(* number of disks for current solution *)
        : INTEGER ;

(********************************************************************)
(****                 T O W E R S  O F  H A N O I                ****)
(********************************************************************)
PROCEDURE TowersOfHanoi
(* recursively solves the Towers of Hanoi problem;
   Pre:  n is the number of disks;
         i is the start peg;
         j is the goal peg;
   Post: if n = 1 output a move; otherwise decompose the problem into three
         simpler subproblems and solve in sequence:
         1.  move n-1 disks from i to k;
         2.  move 1   disk  from i to j ;
         3.  move n-1 disks from k to j ;
*)
( (*in*) one, two, three : INTEGER ) ;

VAR
    k	(* k will be set to the peg # i or j *)
        : INTEGER ;

BEGIN
        WRINT ( one ) ;
        WRSTR ( "  " ) ;
        WRINT ( two ) ;
        WRSTR ( "  " ) ;
        WRINT ( three ) ;
        WRLN ;
END TowersOfHanoi ;

(********************************************************************)
(****     M A I N ** M A I N ** M A I N ** M A I N ** M A I N    ****)
(********************************************************************)
BEGIN
    WRSTR ( "Enter the number of disks (0-9 please) and press ENTER:  " ) ;
	WRLN;
	WRSTR("Input: ");
    numDisks := RDINT ();
	
    WRSTR ( "This should print the number entered, then 1, then 3." ) ;
    WRLN ;
END Towers.