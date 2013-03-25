#include <stdio.h>

int count_factors(int, int);

int main()
{
  int n,i,k;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &k);
    printf("%d\n", count_factors(k,5));
  }
  return 0;
}

int count_factors(int k, int factor)
{
  int times,prod=1,factors=0;
  for (times=0; prod<k; times++) {
    prod *= factor;
    factors += k/prod;
  }
  return factors;
}
