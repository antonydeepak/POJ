#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 50

void str_reverse(char *);
void setup(void);
void teardown(void);

char *str_a, *str_b, *sum;

int main()
{
  int i,n;
  scanf("%i", &n);

  for (i=0; i<n; i++) {
    setup();
    scanf("%s%s", str_a, str_b);

    str_reverse(str_a);
    str_reverse(str_b);

    sprintf(sum, "%i", atoi(str_a) + atoi(str_b));
    str_reverse(sum);
    printf("%i\n", atoi(sum));

    teardown();
  }
  return 0;
}

void setup()
{
  str_a = malloc(BUFF_SIZE * sizeof(char));
  str_b = malloc(BUFF_SIZE * sizeof(char));
  sum = malloc(BUFF_SIZE * sizeof(char));
}

void teardown()
{
  free(str_a);
  free(str_b);
  free(sum);
}

void str_reverse(char *astring)
{
  int i,n=strlen(astring);
  char temp;
  for (i=0; i<n/2; i++) {
    temp = astring[i];
    astring[i] = astring[n-1-i];
    astring[n-1-i] = temp;
  }
}
