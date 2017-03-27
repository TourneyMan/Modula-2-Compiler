MODULE IfTest;

VAR k, l : INTEGER;

BEGIN
    k := 4 ;
    l := 5 ;
	
    IF k > l THEN
        WRINT(k);	(* True Case *)
        WRLN;
    ELSE
        WRINT(l);	(* False Case *)
        WRLN;
    END;
END IfTest.