MODULE LoopTest;

VAR i, j : INTEGER;

BEGIN
	j := 10;
	i := 1;
	LOOP
		IF i > j THEN EXIT; END;
		WRINT(i);
		WRLN;
		i := i + 1;
	END;
END LoopTest.