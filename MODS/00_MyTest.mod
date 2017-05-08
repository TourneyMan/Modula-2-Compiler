MODULE Bubble ;

TYPE
    ListType = ARRAY [ 1 .. 10 ] OF INTEGER ;

VAR
    thisList : ListType ;

(********************************************************************)
(****                 R A N D O M                                ****)
(********************************************************************)
PROCEDURE Random ( VAR seed : INTEGER ) ;

CONST
    m = 8192 ;
    t = 4361 ;
    c = 3899 ;

VAR
    temp : INTEGER ;

BEGIN
    temp := ( seed * t + c ) MOD m ;
    seed := temp ;
END Random ;

(********************************************************************)
(****                 F I L L                                    ****)
(********************************************************************)
PROCEDURE Fill ( VAR list : ListType ) ;

CONST startSeed = 29 ;

VAR
    index,
    seed
        : INTEGER ;

BEGIN
    seed := startSeed ;
    index := 1 ;
    LOOP
        IF index > 10 THEN EXIT; END ;
        list[index] := seed + 1000;
        Random ( seed ) ;
        index := index + 1 ;
    END ;
END Fill ;

(********************************************************************)
(****                 P R I N T                                  ****)
(********************************************************************)
PROCEDURE Print ( VAR list : ListType ) ;
VAR
    index : INTEGER ;

BEGIN
    index := 1 ;
    LOOP
        IF index > 10 THEN EXIT; END ;
        WRINT ( list[index] ) ;
        WRLN ;
        index := index + 1 ;
    END ;
END Print ;

(********************************************************************)
(****                 M A I N                                    ****)
(********************************************************************)
BEGIN
    Fill  ( thisList ) ;
    Print ( thisList ) ;
    WRLN ;
END Bubble.