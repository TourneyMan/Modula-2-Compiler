MODULE Bubble ;

TYPE
    ListType = ARRAY [ 1 .. 10 ] OF INTEGER ;

VAR
    thisList : ListType ;

(********************************************************************)
(****                 S W A P                                    ****)
(********************************************************************)
PROCEDURE Swap ( VAR a, b : INTEGER ) ;
VAR temp : INTEGER ;
BEGIN
    temp := a ;
    a    := b ;
    b    := temp ;
END Swap ;

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
(****                 S O R T                                    ****)
(********************************************************************)
PROCEDURE Sort ( VAR list : ListType ) ;
VAR
    index,
    mark
        : INTEGER ;

BEGIN
    LOOP
        mark := 0 ;
        index := 1 ;
        LOOP
            IF index > 9 THEN EXIT; END ;
            IF list[index] > list[index+1] THEN
                Swap ( list[index], list[index+1] ) ;
                mark := 1 ;
            END ;
            index := index + 1 ;
        END ;
        IF mark = 0 THEN EXIT; END ;
    END ;
END Sort ;

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
    Sort  ( thisList ) ;
    Print ( thisList ) ;
END Bubble.