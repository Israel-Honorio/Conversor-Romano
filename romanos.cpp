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

  int resultado = 0;
  int tamanho = strlen(num_romano);
  
  // Verifica se todos os caracteres são algarismos romanos válidos
  for (int i = 0; i < tamanho; i++) {
    if (valor_algarismo(num_romano[i]) == -1) {
      return -1;  // Algarismo inválido
    }
  }
  
  for (int i = 0; i < tamanho; i++) {
    int valor_atual = valor_algarismo(num_romano[i]);
    
    // Se não é o último algarismo e o atual é menor que o próximo, subtrai
    if (i + 1 < tamanho) {
      int valor_proximo = valor_algarismo(num_romano[i + 1]);
      
      if (valor_atual < valor_proximo) {
        resultado -= valor_atual;
      } else {
        resultado += valor_atual;
      }
    } else {
      // Último algarismo, sempre soma
      resultado += valor_atual;
    }
  }
  
  return resultado; 
} 

 