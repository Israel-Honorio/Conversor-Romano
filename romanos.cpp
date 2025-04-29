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

int pode_subtrair(char c) {
  return (c == 'I' || c == 'X' || c == 'C');
}

int romanos_para_decimal(char const * num_romano)
{
  int tamanho = strlen(num_romano);
  
  if (tamanho == 0 || tamanho > 30) {
    return -1;  // String vazia ou muito longa
  }

  // Verifica se todos os caracteres são algarismos romanos válidos
  for (int i = 0; i < tamanho; i++) {
    if (valor_algarismo(num_romano[i]) == -1) {
      return -1;  // Algarismo inválido
    }
  }
  
  // Verifica repetições inválidas (V, L, D não podem repetir e outros no máximo 3 vezes)
  int contador_I = 0, contador_X = 0, contador_C = 0, contador_M = 0;
  int contador_V = 0, contador_L = 0, contador_D = 0;
  
  for (int i = 0; i < tamanho; i++) {
    switch (num_romano[i]) {
      case 'I': contador_I++; 
                if (contador_I > 3) return -1;
                break;
      case 'V': contador_V++; 
                if (contador_V > 1) return -1;
                break;
      case 'X': contador_X++; 
                if (contador_X > 3) return -1;
                break;
      case 'L': contador_L++; 
                if (contador_L > 1) return -1;
                break;
      case 'C': contador_C++; 
                if (contador_C > 3) return -1;
                break;
      case 'D': contador_D++; 
                if (contador_D > 1) return -1;
                break;
      case 'M': contador_M++; 
                if (contador_M > 3) return -1;
                break;
    }
  }
  
  int resultado = 0;
  
  for (int i = 0; i < tamanho; i++) {
    int valor_atual = valor_algarismo(num_romano[i]);
    
    // Se não é o último algarismo e o atual é menor que o próximo
    if (i + 1 < tamanho) {
      int valor_proximo = valor_algarismo(num_romano[i + 1]);
      
      if (valor_atual < valor_proximo) {
        // Verifica se a subtração é válida
        if (!pode_subtrair(num_romano[i])) {
          return -1;  // Apenas I, X e C podem subtrair
        }
        
        // Verifica se a subtração está na ordem correta
        if ((valor_atual == 1 && valor_proximo != 5 && valor_proximo != 10) ||
            (valor_atual == 10 && valor_proximo != 50 && valor_proximo != 100) ||
            (valor_atual == 100 && valor_proximo != 500 && valor_proximo != 1000)) {
          return -1;  // Ordem incorreta de subtração
        }
        
        resultado -= valor_atual;
      } else {
        resultado += valor_atual;
      }
    } else {
      // Último algarismo, sempre soma
      resultado += valor_atual;
    }
  }
  
  // Verifica se o número está dentro do limite
  if (resultado > 3000) {
    return -1;
  }
  
  return resultado;  
} 

 