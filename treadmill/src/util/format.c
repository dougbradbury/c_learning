#include <stdlib.h>
#include <stdio.h>

char * ftoa(char *a, double f, int precision)
{
  long p[] = {0,10,100,1000,10000,100000,1000000,10000000,100000000};

  char *ret = a;
  int heiltal = (int)f;
  sprintf(a, "%d", heiltal);
  while (*a != '\0') a++;
  *a++ = '.';
  int desimal = abs((long)((f - heiltal) * p[precision]));
  sprintf(a, "%d", desimal);
  return ret;
}
