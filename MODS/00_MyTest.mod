MODULE HelloWorld;

TYPE
    ListType = ARRAY [11 .. 30] OF INTEGER ;

VAR
    aiSquares
        : ListType ;

    index
        : INTEGER ;

BEGIN
	index := 11;
	aiSquares[index] := index * index;
	WRINT(aiSquares[index]);
END HelloWorld.