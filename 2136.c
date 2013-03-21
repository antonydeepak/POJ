#include <stdio.h>
#include <ctype.h>

int count_characters(int *counts)
{
  char ch, depth=0;
  while ((ch = getchar()) != EOF) {
    if (isupper(ch)) {
      counts[ch-'A'] += 1;
      if (counts[ch-'A'] > depth)
        depth = counts[ch-'A'];
    }
  }
  return depth;
}

void print_histogram(int *counts, int depth)
{
  char i,j,c;
  for (i=depth; i>0; i--) {
    for (j=0; j<26; ++j) {
      if (counts[j] >= i) printf("*");
      else printf(" ");
      if (j != 25) printf(" ");
    }
    printf("\n");
  }
  for (i=0; i<26; ++i) {
    printf("%c", i + 'A');
    if (i != 25) printf(" ");
  }
  printf("\n");
}

int main()
{
  int counts[26] = { 0 };
  int depth = count_characters(counts);
  print_histogram(counts, depth);
  return 0;
}
