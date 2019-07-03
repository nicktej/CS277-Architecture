#include "tinycalc.h"
#include <stdio.h>

/* put your function implementations in here. */

int check_command(char op) {

  if (op == 'q' || op == 'Q' || op == 'm' || op == 'M' || op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
    return TC_COMMAND_OK;
  }
  
  return TC_COMMAND_INVALID;
  
}

int read_command(char *op, double *num) {
  
  char c;
  printf("\n>");
  scanf(" %c", &c);
  
  while (check_command(c) == 0) {
    printf("\n>");
    scanf(" %c", &c);
  }

  if (c == 'q' || c == 'Q') {
    return TC_COMMAND_QUIT;
  }
  
  *op = c;

  double f;
  scanf("%lf", &f);
  
  *num = f;

  return TC_COMMAND_OK;
  
}

void execute_calculation(char f_operator, double f_operand, double *p_result) {
  
  if (f_operator == '+') {
    *p_result = *p_result + f_operand;

  } else if (f_operator == '-') {
    *p_result = *p_result - f_operand;
    
  } else if (f_operator == '*') {
    *p_result = *p_result * f_operand;
    
  } else if (f_operator == '/') {
    *p_result = *p_result / f_operand;
    
  } else {
    double i = 1;
    double answer = *p_result;
    
    while (i < f_operand) {
      
      answer = answer * *p_result;
      i++;  
    }
    
    *p_result = answer;
    
  }
  
}

double mem_read(tc_memory_t mem, int v) {

  if (v >= TC_MEM_SZ || v < 0)
    v = 0;
    
  return mem.vals[(mem.most_recent-v+TC_MEM_SZ)%TC_MEM_SZ];

}

void mem_save(tc_memory_t *mem, double v) {

  mem->most_recent = (mem->most_recent+1)%TC_MEM_SZ;
  mem->vals[mem->most_recent] = v;
  
}
