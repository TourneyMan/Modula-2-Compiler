MODULE RefPass ;

VAR temp : INTEGER;

(********************************************************************)
(****  L I T T L E ** L I T T L E **  L I T T L E ** L I T T L E ****)
(********************************************************************)
PROCEDURE little (VAR j : INTEGER) ;

BEGIN

	WRSTR ("j = ");
	WRINT ( j ) ;
	WRLN ;
	
	j := 4;
	
	WRSTR ("j = ");
	WRINT ( j ) ;
    WRLN ;
	
END little ;

(********************************************************************)
(****     M A I N ** M A I N ** M A I N ** M A I N ** M A I N    ****)
(********************************************************************)
BEGIN
	temp := 3;

	WRSTR ("temp = ");
	WRINT ( temp ) ;
	WRLN ;

	little (temp) ;

	WRSTR ("temp = ");
	WRINT ( temp ) ;
	WRLN ;
	
END RefPass.