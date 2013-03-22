#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 250

void str_reverse(char *, char *);
void str_clear(char *);

int main()
{
  int i,n;
  scanf("%i", &n);

  char rev_a[BUFF_SIZE], rev_b[BUFF_SIZE];
  char str_a[BUFF_SIZE], str_b[BUFF_SIZE];
  char sum[BUFF_SIZE], rev_sum[BUFF_SIZE];

  for (i=0; i<n; i++) {
    str_clear(rev_a);
    str_clear(rev_b);
    scanf("%s%s", rev_a, rev_b);

    str_clear(str_a);
    str_clear(str_b);
    str_reverse(rev_a, str_a);
    str_reverse(rev_b, str_b);

    str_clear(sum);
    str_clear(rev_sum);
    sprintf(sum, "%i", atoi(str_a) + atoi(str_b));
    str_reverse(sum, rev_sum);

    printf("%i\n", atoi(rev_sum));
  }

  return 0;
}

void str_clear(char *astring)
{
  int i;
  for (i=0; i<BUFF_SIZE; ++i)
    astring[i] = '\0';
}

void str_reverse(char *astring, char *reversed)
{
  int i,n=strlen(astring);
  for (i=0; i<n; i++)
    reversed[n-1-i] = astring[i];
}
