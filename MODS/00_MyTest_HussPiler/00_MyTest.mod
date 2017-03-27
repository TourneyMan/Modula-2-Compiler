MODULE IfTest;

VAR k, l : INTEGER;

BEGIN
    k := 14 ;
    l := 15 ;
	
    IF k <= l THEN
        WRINT(1);	(* True Case *)
        WRLN;
    ELSE
        WRINT(0);	(* False Case *)
        WRLN;
    END;
END IfTest.