#include <stdio.h>

double get_next(void);
int run_sum(double);

int main()
{
  double lim;
  int n;
  while (lim = get_next()) {
    n = run_sum(lim);
    printf("%d card(s)\n", n);
  }
  return 0;
}

int run_sum(double lim) {
  int n=1;
  double sum=0.0;
  for (n=1; ; n++) {
    sum += 1.0/(n+1);
    if (sum > lim)
      break;
  }
  return n;
}

double get_next()
{
  double next;
  scanf("%lf", &next);
  return next;
}
