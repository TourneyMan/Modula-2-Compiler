MODULE Primes ;

CONST
    maxIntInSqrt = 8 ;

TYPE
    ListType = ARRAY [2 .. 50] OF INTEGER ;

VAR
    aiPrimes
        : ListType ;

    currPrime,
    mult,
    index
        : INTEGER ;

BEGIN

	(* Set all values of the array to 0 *)
    index := 2 ;
    LOOP
        IF index > 50 THEN EXIT ; END ;
        aiPrimes[index] := 0 ;
        index := index + 1 ;
    END ;
	
	(* Mark all prime numbers in the array with a 1 *)
    currPrime := 2 ;
    LOOP
        IF currPrime > maxIntInSqrt THEN EXIT ; END ;
        mult := 2 ;
        LOOP
            IF mult * currPrime > 50 THEN EXIT ; END ;
            aiPrimes [mult * currPrime] := 1 ;
            mult := mult + 1 ;
        END ;
        LOOP
            currPrime := currPrime + 1 ;
            IF aiPrimes[currPrime] = 0 THEN EXIT ; END ;
        END ;
    END ;
	
	WRSTR("Prime numbers between 2 and 50:");
	WRLN;
	
	(* Print all prime numbers between 2 and 50 *)
    index := 2 ;
    LOOP
        IF index > 50 THEN EXIT ; END ;
        IF aiPrimes[index] = 0 THEN
            WRINT ( index ) ;
            WRLN ;
        END ;
        index := index + 1 ;
    END ;

END Primes.