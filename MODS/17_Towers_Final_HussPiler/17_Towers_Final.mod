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
         simpler sub-problems and solve in sequence:
         1.  move n-1 disks from i to k;
         2.  move 1   disk  from i to j ;
         3.  move n-1 disks from k to j ;
*)
( (*in*) n, i, j : INTEGER ) ;

VAR
    k	(* k will be set to the peg # i or j *)
        : INTEGER ;

BEGIN
    IF n = 1 THEN
		WRSTR ("Move ");
        WRINT ( i ) ;
		WRSTR (" to ");
        WRINT ( j ) ;
		WRSTR (".");
        WRLN ;
    ELSE
        k := 6 - i - j ;               (* compute number of third peg *)
        TowersOfHanoi ( n-1, i, k ) ;  (* move n-1 disks from i to k  *)
        TowersOfHanoi (   1, i, j ) ;  (* move   1 disk  from i to j  *)
        TowersOfHanoi ( n-1, k, j ) ;  (* move n-1 disks from k to j  *)
    END ;
END TowersOfHanoi ;

(********************************************************************)
(****     M A I N ** M A I N ** M A I N ** M A I N ** M A I N    ****)
(********************************************************************)
BEGIN
	WRSTR ("Enter a number of disks. (Entering fewer than 10 shows great wisdom.) ");
    WRLN;
	WRSTR("Input: ");
	numDisks := RDINT () ;
	WRLN; WRLN;
	
    TowersOfHanoi ( numDisks, 1, 3 ) ;
END Towers .
