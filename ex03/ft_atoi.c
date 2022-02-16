#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


unsigned int is_space(char ch)
{
  return (ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v' || ch == ' ');
}

int jump_spaces(char **str, char **str_end) 
{
  int signals;
  unsigned int stop;

  signals = 1;
  stop = 0;
  while (**str_end)
  {
    if (!(**str_end >= '0' && **str_end <= '9'))
    {
      if (stop)
        break ;
      if (**str_end == '+' || **str_end == '-')
        if (**str_end == '-')
          signals *= -1;
      (*str_end)++;
      (*str)++;
      continue;
    }
    (*str_end)++;
    stop = 1;
  }
  (*str_end)--;
  return (signals);
}

int ft_atoi(char *str) {
  char *str_end;
  int mult;
  int result;

  str_end = str;
  mult = 1;
  result = 0;
  unsigned int t = jump_spaces(&str, &str_end);
  while (str_end >= str) 
  {
     int aux = *str_end - '0';
     result += aux * mult; 
     mult *= 10; 
     str_end--; 
   }
  return (result * t); 
}

