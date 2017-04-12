MODULE HelloWorld;

TYPE
    ListType = ARRAY [11 .. 30] OF INTEGER ;

VAR
    aiSquares
        : ListType ;

    index
        : INTEGER ;

BEGIN
    WRSTR ("Hello world!");
    WRLN;
END HelloWorld.