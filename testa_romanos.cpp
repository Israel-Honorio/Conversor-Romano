#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"


TEST_CASE( "Numeros romanos - algarismos unicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE( romanos_para_decimal("V") == 5 );
    REQUIRE( romanos_para_decimal("X") == 10 );
    REQUIRE( romanos_para_decimal("L") == 50 );
    REQUIRE( romanos_para_decimal("C") == 100 );
    REQUIRE( romanos_para_decimal("D") == 500 );
    REQUIRE( romanos_para_decimal("M") == 1000 );
    
}




TEST_CASE( "Numeros romanos - algarismos invalidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    REQUIRE( romanos_para_decimal("i") == -1 );

    // Quatro caracteres iguais seguidos
    REQUIRE( romanos_para_decimal("IIII") == -1 );
    REQUIRE( romanos_para_decimal("XXXX") == -1 );
    
    // V, L e D não podem ser repetidos
    REQUIRE( romanos_para_decimal("VV") == -1 );
    REQUIRE( romanos_para_decimal("LL") == -1 );
    REQUIRE( romanos_para_decimal("DD") == -1 );
    
    // Ordem incorreta de subtração
    REQUIRE( romanos_para_decimal("VX") == -1 );
    REQUIRE( romanos_para_decimal("LC") == -1 );
    REQUIRE( romanos_para_decimal("DM") == -1 );
    
    // Apenas I, X, C podem ser usados para subtração
    REQUIRE( romanos_para_decimal("VL") == -1 );
}

TEST_CASE( "Numeros romanos - dois algarismos (adição)", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("II") == 2 );
    REQUIRE( romanos_para_decimal("VI") == 6 );
    REQUIRE( romanos_para_decimal("XI") == 11 );
    REQUIRE( romanos_para_decimal("XV") == 15 );
    REQUIRE( romanos_para_decimal("XXXIII") == 33 );
    REQUIRE( romanos_para_decimal("MM") == 2000 );
}

TEST_CASE( "Numeros romanos - subtração", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("IX") == 9 );
    REQUIRE( romanos_para_decimal("XL") == 40 );
    REQUIRE( romanos_para_decimal("XC") == 90 );
    REQUIRE( romanos_para_decimal("CD") == 400 );
    REQUIRE( romanos_para_decimal("CM") == 900 );
}
