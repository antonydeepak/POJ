#include <stdio.h>

int main()
{
  unsigned int i,j,n,ways=0;
  long int remain;
  scanf("%u", &n);

  for (i=n; i!=0; --i) {
    remain = n;
    for (j=i; remain>0; --j)
      remain -= j;
    if (remain == 0)
      ++ways;
  }

  printf("%u\n", ways);
  return 0;
}
