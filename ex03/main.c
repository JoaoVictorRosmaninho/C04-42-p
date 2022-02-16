#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int ft_atoi(char *str);


int main(void) {
  printf("%d\n", ft_atoi("  --96+  --521")); 
  printf("%d\n", ft_atoi("-6+71"));
  printf("%d\n", ft_atoi("---6+71"));
  printf("%d\n", ft_atoi("-6517++1"));
  printf("%d\n", ft_atoi("6  5asas71"));
  printf("%d\n", ft_atoi("---------"));
  printf("%d\n", ft_atoi("---ggf555--"));
  printf("%d\n", ft_atoi("-2147483648"));
  printf("%d\n", ft_atoi("2147483647"));
  printf("%d\n", ft_atoi(" ---+--+1234ab567"));  
}
