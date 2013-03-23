#include <stdio.h>
#include <math.h>

float compute_caliber(float, int);

int main()
{
  int n, i, rounds;
  float cylinder;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%f%d", &cylinder, &rounds);
    printf("Scenario %d:\n", i+1);
    printf("%.3f\n\n", compute_caliber(cylinder, rounds));
  }
  return 0;
}

float compute_caliber(float cylinder, int rounds)
{
  return cylinder / (1 + (1/sin(M_PI/rounds)));
}
