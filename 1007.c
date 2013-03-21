#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFSIZE 100

typedef struct {
  char sequence[BUFFSIZE];
  int inversions;
} Seqinv;

int count_inversions(char *);

int main()
{
  int i,hole,l,n;
  scanf("%d%d", &l, &n);

  char astring[l];
  Seqinv **ptr = malloc(n * sizeof(Seqinv *));

  hole = 0;
  for (i=0; i<n; i++) {
    scanf("%s", astring);

    Seqinv *current = (Seqinv *)malloc(sizeof(Seqinv));
    strcpy(current->sequence, astring);
    current->inversions = count_inversions(astring);

    for (hole=0; hole<i; ++hole) {
      if (current->inversions >= ptr[hole]->inversions)
        continue;
      else {
        Seqinv *temp = ptr[hole];
        ptr[hole] = current;
        current = temp;
      }
    }
    ptr[hole] = current;
  }
  
  for (i=0; i<n; i++) {
    printf("%s\n", ptr[i]->sequence);
    free(ptr[i]);
  }

  free(ptr);
  return 0;
}

int count_inversions(char *astring)
{
  int i, j, n=0;
  for (i=0; ;i++) {
    if (!astring[i]) break;
    for (j=i+1; ; j++) {
      if (!astring[j]) break;
      if (astring[i] > astring[j]) n++;
    }
  }
  return n;
}
