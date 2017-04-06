MODULE FullExpr;

CONST
	little = 3;
	hi = 7;
	middle = 7;

VAR
   good, bad, ugly : INTEGER;

VAR k, m : INTEGER ;

BEGIN

    good := 42+7-31+1 - 14;

	(*****************************************************************************)
	(*****  Part 1                                                           *****)
	(*****************************************************************************)

	WRSTR ("Part 1:");
	WRLN;
	WRSTR ("_______");
	WRLN;
	
    WRSTR ("42+8-31+ugly:        should be 20:          ");
    WRINT (42+8-31+ugly); WRLN;
	
    WRSTR ("good * little:       should be 15:          ");
    WRINT (good * little); WRLN;
	
    WRSTR ("42000 DIV 4200:      should be 10:          ");
    WRINT (42000 DIV 4200); WRLN;
	
    WRSTR ("42042 MOD 100:       should be 42:          ");
    WRINT (42042 MOD 100); WRLN;
	
    WRSTR ("20000 * 21000:       should be 420,000,000: ");
    WRINT (20000 * 21000); WRLN;
	
    WRSTR ("6*7+2*little-1:      should be 47:          ");
    WRINT (6*7+2*little-1); WRLN;
	
    WRSTR ("6*2+((1+2)*3-1)*2:   should be 28:          ");
    WRINT (6*2+((1+2)*3-1)*2); WRLN;

	WRLN;
	
	WRSTR ("Enter 1 and press <return> to continue): ");
	ugly := RDINT ();
    
	LOOP
		IF ugly = 1 THEN EXIT; END;
		WRSTR ("Invalid input...Enter 1 and press <return> to continue: ");
		ugly := RDINT();
	END;
	CLS;
	
	(*****************************************************************************)
	(*****  Part 2                                                           *****)
	(*****************************************************************************)
	
	WRSTR ("Part 2:");
	WRLN;
	WRSTR ("_______");
	WRLN;
	
    WRSTR ("IF test(5):          should be  4:          ");
	k := 4 ;
	m := 3 ;
	IF k > m THEN
		WRINT ( k ) ;
		WRLN ;
	ELSE
		WRINT ( m ) ;
		WRLN ;
	END ;

    WRSTR ("IF test(5.01):       should be 17:          ");
	k := 4 ;
	m := 17 ;
	IF k > m THEN
		WRINT ( k ) ;
		WRLN ;
	ELSE
		WRINT ( m ) ;
		WRLN ;
	END ;

    WRSTR ("IF test(5.02):       should be 71:          ");
	k := 4 ;
	m := 71 ;
	IF k > m THEN
		WRINT ( k ) ;
		WRLN ;
	ELSE
		IF ( m <= 71 ) THEN
			WRINT ( m ) ;
			WRLN ;
		ELSE
			WRINT ( m * 10000 ) ;
			WRLN ;
		END ;
	END ;

    WRSTR ("AND test(5.03):      should be  1:          ");
	k := 4 ;
	m := 71 ;
	IF (k < m) AND ( (k*m) >= (k*m-1) ) THEN
		WRINT ( 1 ) ;
		WRLN ;
	ELSE

		IF m <= 71 THEN
			WRINT ( m ) ;
			WRLN ;
		ELSE
			WRINT ( m * 10000 ) ;
			WRLN ;
		END ;
	END ;

    WRSTR ("AND test(5.04):      should be  1:          ");
	k := 4 ;
	m := 71 ;
	IF (m > k) AND ( (k*m) >= (k*m-1) ) THEN
		WRINT ( 1 ) ;
		WRLN ;
	ELSE

		IF ( m <= 71 ) THEN
			WRINT ( m ) ;
			WRLN ;
		ELSE
			WRINT ( m * 10000 ) ;
			WRLN ;
		END ;
	END ;

    WRSTR ("OR test(5.05):       should be  1:          ");
	k := 4 ;
	m := 71 ;
	IF (k > k) OR (10 <> 10) THEN
		WRINT ( 1111 ) ;
		WRLN ;
	ELSE
		IF ( m <= 71 ) THEN
			WRINT ( 1 ) ;
			WRLN ;
		ELSE
			WRINT ( m * 10000 ) ;
			WRLN ;
		END ;
	END ;

    WRSTR ("OR test(5.06):       should be  1:          ");
    IF (5 > 3) OR ( k*m = (k*m-1) ) THEN
        WRINT ( 1 ) ; WRLN ; ELSE WRINT ( 9999 ); WRLN ; END ;

    WRSTR ("OR AND test(5.07):   should be  1:          ");
    IF (5 < 3) OR ( k*m <> (k*m-1) ) AND (2 = 2) THEN
        WRINT ( 1 ) ; WRLN ; ELSE WRINT ( 9999 ) ; WRLN ; END ;

    WRSTR ("OR AND test(5.08):   should be  1:          ");
    IF (5 < 3) AND ( k*m <> (k*m-1) ) AND (2 = 2) OR ( 1 = 2) THEN
        WRINT ( 9999 ) ; WRLN ; ELSE WRINT ( 1 ) ; WRLN ; END ;

    WRSTR ("OR AND test(5.09):   should be  1:          ");
    IF (5 < 3) AND ( k*m <> (k*m-1) ) AND (2 = 2) OR ( 12 = 2 * 6 ) THEN
        WRINT ( 1 ) ; WRLN ; ELSE WRINT ( 9999 ) ; WRLN ; END ;

    WRSTR ("NOT test(5.10):      should be  1:          ");
    IF NOT (5 < 3) THEN
        WRINT ( 1 ) ; WRLN ;  ELSE WRINT ( 9999 ) ; WRLN ; END ;

    WRSTR ("NOT test(5.11):      should be  1:          ");
    IF NOT (5 < 23) THEN
        WRINT ( 9999 ) ; WRLN ;  ELSE WRINT ( 1 ) ; WRLN ; END ;

	WRLN;
	
	WRSTR ("Enter 1 and press <return> to continue): ");
	ugly := RDINT ();
    
	LOOP
		IF ugly = 1 THEN EXIT; END;
		WRSTR ("Invalid input...Enter 1 and press <return> to continue: ");
		ugly := RDINT();
	END;
	CLS;
	
	(*****************************************************************************)
	(*****  Part 3                                                           *****)
	(*****************************************************************************)
	
	WRSTR ("Part 3: LOOP test (1-X)"); WRLN;
	WRSTR ("_______________________"); WRLN; WRLN;
	
	WRSTR("Enter X: ");
	k := RDINT(); WRLN;

    m := 1 ;
    LOOP
        IF m = k + 1 THEN EXIT ; END ;
    
		WRINT ( m ) ;
		WRLN ;
        
		m := m + 1 ;
    END ;
    
	WRLN ;

	WRSTR ("Enter 1 and press <return> to continue): ");
	ugly := RDINT ();
    
	LOOP
		IF ugly = 1 THEN EXIT; END;
		WRSTR ("Invalid input...Enter 1 and press <return> to continue: ");
		ugly := RDINT();
	END;
	CLS;
	
	(*****************************************************************************)
	(*****  Part 4                                                           *****)
	(*****************************************************************************)
	
	WRSTR ("Part 4: Nested LOOP test (pretty pyramid)"); WRLN;
	WRSTR ("_________________________________________"); WRLN; WRLN;
	
	WRSTR("Enter height of the pyramid: ");
	k := RDINT(); WRLN;
	
	m := 1 ;
    LOOP
        IF m = k + 1 THEN EXIT ; END ;

        good := 1;
        LOOP
            WRSTR ("@");
            IF good = m THEN EXIT ; END ;
            good := good + 1 ;
        END ;

        WRLN ;
		
        m := m + 1 ;
    END ;
    
	WRLN;

END FullExpr.