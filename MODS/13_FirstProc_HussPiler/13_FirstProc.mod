MODULE FirstProc ;

VAR k : INTEGER ;

(********************************************************************)
(****  L I T T L E ** L I T T L E **  L I T T L E ** L I T T L E ****)
(********************************************************************)
PROCEDURE little ( ) ;

BEGIN
    
	WRSTR ("Hello Procedure!");
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
	
	little (  ) ;

END FirstProc.