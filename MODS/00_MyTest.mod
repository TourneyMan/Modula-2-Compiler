MODULE OutOfBoundsTest ;

TYPE
    ListType = ARRAY [ 1 .. 10 ] OF INTEGER ;

VAR
    thisList : ListType ;


BEGIN
    thisList[0] := 4;
	WRINT(thisList[11]);
END OutOfBoundsTest.