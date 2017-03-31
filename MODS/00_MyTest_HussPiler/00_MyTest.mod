MODULE ReadTest;

VAR x, y : INTEGER;

BEGIN

	x := 10;
	WRSTR("X = ");
	WRINT(x);
	WRLN;
	
	(* Prompt for user input *)
    WRSTR ("Enter an integer: ");
	y := 4;
    
	(* Add user input to value of x and print out result *)
	WRINT(x);
	WRSTR (" + ");
	WRINT(y);
	WRSTR (" = ");
	WRINT(x + y);
	WRLN;

END ReadTest.