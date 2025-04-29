#include "romanos.hpp"
#include <string.h>

int romanos_para_decimal(char const * num_romano)
{
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
 