MODULE Bubble ;

TYPE
    ListType = ARRAY [ 1 .. 10 ] OF INTEGER ;

VAR
    thisList : ListType ;

(********************************************************************)
(****                 F I L L                                    ****)
(********************************************************************)
PROCEDURE Fill ( VAR list : ListType ) ;

CONST startSeed = 29 ;

VAR
    index : INTEGER ;

BEGIN
    index := 1 ;
    LOOP
        IF index > 10 THEN EXIT; END ;
        list[index] := index;
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
END Bubble.