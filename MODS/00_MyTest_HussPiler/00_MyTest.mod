MODULE LoopIf;
BEGIN
    WRSTR ("OR test:             should be 24:          ");
    IF (5 > 3) OR ( 5 < 3 ) THEN
        WRINT ( 24 ) ; WRLN ;  END ;
	
END LoopIf.