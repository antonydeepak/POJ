#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 50

void str_reverse(char *, char *);
void setup(void);
void teardown(void);

char *rev_a, *rev_b;
char *str_a, *str_b;
char *sum, *rev_sum;

int main()
{
  int i,n;
  scanf("%i", &n);

  for (i=0; i<n; i++) {
    setup();

    scanf("%s%s", rev_a, rev_b);

    str_reverse(rev_a, str_a);
    str_reverse(rev_b, str_b);

    sprintf(sum, "%i", atoi(str_a) + atoi(str_b));
    str_reverse(sum, rev_sum);
    printf("%i\n", atoi(rev_sum));

    teardown();
  }
  return 0;
}

void setup()
{
  rev_a = malloc(BUFF_SIZE * sizeof(char));
  rev_b = malloc(BUFF_SIZE * sizeof(char));
  str_a = malloc(BUFF_SIZE * sizeof(char));
  str_b = malloc(BUFF_SIZE * sizeof(char));
  sum = malloc(BUFF_SIZE * sizeof(char));
  rev_sum = malloc(BUFF_SIZE * sizeof(char));
}

void teardown()
{
  free(rev_a);
  free(rev_b);
  free(str_a);
  free(str_b);
  free(sum);
  free(rev_sum);
}

void str_reverse(char *astring, char *reversed)
{
  int i,n=strlen(astring);
  for (i=0; i<n; i++)
    reversed[n-1-i] = astring[i];
}
