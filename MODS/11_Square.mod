MODULE Square;

TYPE
    ListType = ARRAY [11 .. 30] OF INTEGER ;

VAR
    aiSquares
        : ListType ;

    index
        : INTEGER ;

BEGIN

	(* Load values into the array *)
    index := 11 ;
    LOOP
        IF index > 30 THEN EXIT ; END ;
        aiSquares[index] := index * index;
        index := index + 1 ;
    END ;

	(* Print the array *)
    index := 11 ;
    LOOP
        IF index > 30 THEN EXIT ; END ;
        WRINT ( index ) ;
        WRSTR ( " squared is " ) ;
        WRINT ( aiSquares[index] ) ;
        WRSTR ( "." ) ;
        WRLN ;
        index := index + 1 ;
    END ;

END Square.