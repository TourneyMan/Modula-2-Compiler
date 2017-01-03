MODULE Float ;

BEGIN
    WRSTR ( "Write the real number 0.035: ") ;
    WRREAL ( 0.035 ) ;
    WRLN ;
	
    WRSTR ( "Write the real numbers 12.25 and 351.123: ") ;
    WRREAL ( 12.25 ) ;
    WRSTR ( " and " ) ;
    WRREAL ( 351.123 ) ;
    WRLN ;
	
    WRSTR ( "Their sum is 363.373: " ) ;
    WRREAL ( 351.123 + 12.25 ) ;
    WRLN ;
	
    WRSTR ( "Their difference is -338,873: " ) ;
    WRREAL ( 12.25 - 351.123 ) ;
    WRLN ;
	
    WRSTR ( "Their product is 4301.256: " ) ;
    WRREAL ( 351.123 * 12.25 ) ;
    WRLN ;
	
    WRSTR ( "Their quotient (351.123 / 12.25) is 28.663: " ) ;
    WRREAL ( 351.123 / 12.25 ) ;
    WRLN ;
	
    WRSTR ( "Their reciprocal quotient ( 12.25 / 351.123 ) is 0.035: " ) ;
    WRREAL ( 12.25 / 351.123 ) ;
    WRLN ;
	
    WRSTR ( "15.3 + 17.113 * 0.125 - 12.1 / 6.05 is 15.439:  " ) ;
    WRREAL ( 15.3 + 17.113 * 0.125 - 12.1 / 6.05 ) ;
    WRLN ;
	
END Float .