#include <stdio.h>
#include "tinycalc.h"

/* put your application code in this file. */

int main(void) {

  printf("\nWelcome to TinyCalc!\n\n Enter an operation <+, - , *, /, ^>");
  printf(" followed by operand\n\n Enter 'q' or 'Q' to quit.\n\n");
  printf(" Enter 'm' or 'M' followed by location (0-4) to load a previous\n");
  printf(" result from memory.");
  printf("\n>");

  char operator;
  double operand;
  tc_memory_t mem;
  double previous_calculation = 0.0;
  int i = 0;
  
  while (i < TC_MEM_SZ) {
    mem.vals[i] = 0.0;
    i++;
  }

  mem.most_recent = 0;

  while (read_command(&operator, &operand) != TC_COMMAND_QUIT) {

    if (operator == 'm' || operator == 'M') {

      
      previous_calculation = mem_read(mem, operand);
	
    } else {

      execute_calculation(operator, operand, &previous_calculation);
      mem_save(&mem, previous_calculation);
    } 

    printf("%.2lf", previous_calculation);
  }
  
  return(0);
}
