MODULE FullExpr;

VAR k, m : INTEGER ;

BEGIN
	k := 63;
	m := 53;

    WRSTR ("OR AND test(5.09):   should be  1:          ");
    IF  (5 < 3) AND (2 = 2) OR (12 = 2 * 6) THEN
        WRINT ( 1 ) ; WRLN ; ELSE WRINT ( 9999 ) ; WRLN ; END ;

END FullExpr.