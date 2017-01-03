MODULE FirstProc ;

VAR k : INTEGER ;

(********************************************************************)
(****  L I T T L E ** L I T T L E **  L I T T L E ** L I T T L E ****)
(********************************************************************)
PROCEDURE little ( i : INTEGER ) ;

BEGIN
    WRINT ( i ) ;
	WRSTR (" : ");
	
	i := i * 4;
	
	WRINT ( i ) ;
    WRLN ;
END little ;

(********************************************************************)
(****     M A I N ** M A I N ** M A I N ** M A I N ** M A I N    ****)
(********************************************************************)
BEGIN
    k := 3 ;
    
	WRSTR ("K (3) = ");
	WRINT ( k ) ;
	WRLN ;
	
	WRSTR ( "We should see 3 : 12") ;
	WRLN ;
	little ( k ) ;
	
	WRSTR ("K (3) = ");
	WRINT ( k ) ;
	WRLN ;

END FirstProc.