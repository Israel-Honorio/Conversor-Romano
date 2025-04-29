#include "romanos.hpp"
#include <string.h>

int romanos_para_decimal(char const * num_romano)
{
  // Verifica se é um algarismo válido
  for (int i = 0; num_romano[i] != '\0'; i++) {
    if (num_romano[i] != 'I' && 
        num_romano[i] != 'V' && 
        num_romano[i] != 'X' && 
        num_romano[i] != 'L' && 
        num_romano[i] != 'C' && 
        num_romano[i] != 'D' && 
        num_romano[i] != 'M') {
      return -1;
    }
  }

  if (strcmp(num_romano, "I") == 0) {
    return 1;
  } else if (strcmp(num_romano, "V") == 0) {
    return 5;
  } else if (strcmp(num_romano, "X") == 0) {
    return 10;
  } else if (strcmp(num_romano, "L") == 0) {
    return 50;
  } else if (strcmp(num_romano, "C") == 0) {
    return 100;
  } else if (strcmp(num_romano, "D") == 0) {
    return 500;
  } else if (strcmp(num_romano, "M") == 0) {
    return 1000;
  }
  
  return 0; 
}
 