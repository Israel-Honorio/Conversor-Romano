#include "romanos.hpp"
#include <string.h>


int valor_algarismo(char c) {
  switch (c) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    default: return -1;
  }
}

int romanos_para_decimal(char const * num_romano)
{
  if (strlen(num_romano) == 0) {
    return -1;  // String vazia
  }

  int soma = 0;
  
  // Verifica se todos os caracteres são algarismos romanos válidos
  for (int i = 0; num_romano[i] != '\0'; i++) {
    int valor = valor_algarismo(num_romano[i]);
    if (valor == -1) {
      return -1;  // Algarismo inválido
    }
    soma += valor;
  }
  
  return soma; 
} 

 