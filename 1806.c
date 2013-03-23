#include <stdio.h>
#define abs(x) ((x) >= 0 ? (x) : -1*(x))

void print_slices(int);

int main()
{
  int i,n,dim;
  scanf("%d", &n);
  for (i=0; i<n; i++) {
    printf("Scenario #%d:\n", i+1);
    scanf("%d", &dim);
    print_slices(dim);
  }
  return 0;
}

void print_slices(int dim)
{
  int x, y, z, dist, mid=dim+1;
  for (z=-1*dim; z<=dim; z++) {
    printf("slice #%d:\n", mid+z);
    for (x=-1*dim; x<=dim; x++) {
      for (y=-1*dim; y<=dim; y++) {
        dist = abs(x) + abs(y) + abs(z);
        if (dist > dim)
          printf(".");
        else
          printf("%d", dist);
      }
      printf("\n");
    }
  }
  printf("\n");
}
