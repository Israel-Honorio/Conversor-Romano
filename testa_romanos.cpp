// Copyright 2025 Israel Honório
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "./catch.hpp"
#include "./romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("V") == 5);
    REQUIRE(romanos_para_decimal("X") == 10);
    REQUIRE(romanos_para_decimal("L") == 50);
    REQUIRE(romanos_para_decimal("C") == 100);
    REQUIRE(romanos_para_decimal("D") == 500);
    REQUIRE(romanos_para_decimal("M") == 1000);
}

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("Z") == -1);
    REQUIRE(romanos_para_decimal("Y") == -1);
    REQUIRE(romanos_para_decimal("P") == -1);
    REQUIRE(romanos_para_decimal("K") == -1);

    // Quatro caracteres iguais seguidos
    REQUIRE(romanos_para_decimal("IIII") == -1);
    REQUIRE(romanos_para_decimal("XXXX") == -1);
    REQUIRE(romanos_para_decimal("CCCC") == -1);
    REQUIRE(romanos_para_decimal("MMMM") == -1);
    
    // V, L e D não podem ser repetidos
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("LL") == -1);
    REQUIRE(romanos_para_decimal("DD") == -1);
    
    // Ordem incorreta de subtração
    REQUIRE(romanos_para_decimal("VX") == -1);
    REQUIRE(romanos_para_decimal("LC") == -1);
    REQUIRE(romanos_para_decimal("DM") == -1);
    REQUIRE(romanos_para_decimal("IL") == -1);
    REQUIRE(romanos_para_decimal("IC") == -1);
    REQUIRE(romanos_para_decimal("IM") == -1);
    REQUIRE(romanos_para_decimal("XD") == -1);
    REQUIRE(romanos_para_decimal("XM") == -1);
    
    // Apenas I, X, C podem ser usados para subtração
    REQUIRE(romanos_para_decimal("VL") == -1);
    REQUIRE(romanos_para_decimal("LD") == -1);
    REQUIRE(romanos_para_decimal("DM") == -1);
}

TEST_CASE("Numeros romanos - dois algarismos (adição)", "[romanos]") {
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("VI") == 6);
    REQUIRE(romanos_para_decimal("XI") == 11);
    REQUIRE(romanos_para_decimal("XV") == 15);
    REQUIRE(romanos_para_decimal("XX") == 20);
    REQUIRE(romanos_para_decimal("CL") == 150);
    REQUIRE(romanos_para_decimal("MD") == 1500);
    REQUIRE(romanos_para_decimal("MM") == 2000);
}

TEST_CASE("Numeros romanos - subtração", "[romanos]") {
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("XC") == 90);
    REQUIRE(romanos_para_decimal("CD") == 400);
    REQUIRE(romanos_para_decimal("CM") == 900);
}

TEST_CASE("Numeros romanos - números complexos", "[romanos]") {
    REQUIRE(romanos_para_decimal("MCMXCIV") == 1994);
    REQUIRE(romanos_para_decimal("MMXXI") == 2021);
    REQUIRE(romanos_para_decimal("MCMLXXXIV") == 1984);
    REQUIRE(romanos_para_decimal("MMCMXCIX") == 2999);
    REQUIRE(romanos_para_decimal("MMM") == 3000);
}

TEST_CASE("Numeros romanos - limites e casos especiais", "[romanos]") {
    // Limite máximo permitido
    REQUIRE(romanos_para_decimal("MMM") == 3000);
    
    // Acima do limite máximo
    REQUIRE(romanos_para_decimal("MMMI") == -1);
    
    // String vazia
    REQUIRE(romanos_para_decimal("") == -1);
    
    // String muito longa (mais de 30 caracteres)
    REQUIRE(romanos_para_decimal("MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM") == -1);
}

TEST_CASE("Numeros romanos - padrões especiais de subtração", "[romanos]") {
    // Padrões válidos de subtração
    REQUIRE(romanos_para_decimal("IV") == 4);
    REQUIRE(romanos_para_decimal("IX") == 9);
    REQUIRE(romanos_para_decimal("XL") == 40);
    REQUIRE(romanos_para_decimal("XC") == 90);
    REQUIRE(romanos_para_decimal("CD") == 400);
    REQUIRE(romanos_para_decimal("CM") == 900);
    
    // Padrões inválidos (não pode ter subtração após repetição)
    REQUIRE(romanos_para_decimal("IIV") == -1);
    REQUIRE(romanos_para_decimal("XXL") == -1);
    REQUIRE(romanos_para_decimal("CCD") == -1);
}

TEST_CASE("Numeros romanos - exemplos reais", "[romanos]") {
    REQUIRE(romanos_para_decimal("MCMXCVI") == 1996);    // 1996
    REQUIRE(romanos_para_decimal("MMCDXLVIII") == 2448); // 2448
    REQUIRE(romanos_para_decimal("DCCXCIX") == 799);     // 799
    REQUIRE(romanos_para_decimal("MDCCLXXVI") == 1776);  // 1776
    REQUIRE(romanos_para_decimal("MCMXLIV") == 1944);    // 1944
    REQUIRE(romanos_para_decimal("MMXXIII") == 2023);    // 2023
    REQUIRE(romanos_para_decimal("MCMXCVIII") == 1998);  // 1998
    REQUIRE(romanos_para_decimal("MMXIV") == 2014);      // 2014
}

// Copyright 2025 Israel Honório
