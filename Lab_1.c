#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  long int n = 0, pow = 10, num = 0, i = 0;
  double sm = 0.0, mx = 0.0, mn = 0.0, randn = 0.0, temp = 0.0;
  double* mas;
  double* masC;
  printf("n=");
  scanf("%d", &n);
  if (n <= 0)
  {
    printf("Error: n must be greater than 0. Press Enter to exit.");
    scanf("%d", &n);
    return 0;
  }
  printf("min=");
  scanf("%lf", &mn);
  printf("max=");
  scanf("%lf", &mx);
  if (mn > mx)
  {
    printf("Error: min > max. Press Enter to exit.");
    scanf("%d", &n);
    return 0;
  }
  mas = (double*)malloc(n * sizeof(double));
  if (mas == 0)
  {
    printf("Error while generating array. Press Enter to exit.");
    scanf("%d", &n);
    return 0;
  }
  masC = (double*)malloc(n * sizeof(double));
  pow = (long int)exp(((int)log10(n)+1) * log(10));
  printf("Numbers generated:\n");
  for(i = 0; i < n; i++)
  {
    randn = (double)rand() / RAND_MAX * (mx - mn) + mn;
    mas[i] = randn;
    masC[i] = randn;
    printf("%lf\n", randn);
  }
  for(i = 0; i < n; i++)
  {
    num = abs((long int)(modf(mas[i], &temp) * pow));
    if ((num > pow - 1) && (num % 10 == 0))
    {
      num = (int)(num / 10);
    }
    if (num < n)
    {
      sm -= masC[num];
      masC[num] = 0;
    }
  }
  for(i = 0; i < n; i++)
  {
    sm = sm + masC[i];
  }
  free(mas);
  free(masC);
  printf("Sum = %lf\n", sm);
  scanf("%d", &n);
}