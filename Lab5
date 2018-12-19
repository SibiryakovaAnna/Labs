#include <stdio.h>
#include <stdlib.h>

void sift(int *a, int i, int N){
    int max_c, k = 0;
  while ((i * 2 <= N) && (!k))
  {
    if (i * 2 == N){
      max_c = i * 2;
      } else
    if (a[i * 2] > a[i * 2 + 1])
      max_c = i * 2;
    else
      max_c = i * 2 + 1;

    if (a[i] < a[max_c])
    {
      int t = a[i];
      a[i] = a[max_c];
      a[max_c] = t;
      i = max_c;
    }
    else
      k = 1;
  }

}

void heapSort(int *a, int N){
    int i,t;
    for (i = N/2; i >= 0; i--){
        sift(a, i, N-1);
    }
    for (i = N-1; i > 0; i--){
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        sift(a, 0, i-1);
    }
}

int main()
{
    int *a;
    int l;
    scanf("%d", &l);
    a = (int*)malloc(l * sizeof(int));
    for(int i = 0; i < l; i++)
        scanf("%d", &a[i]);

    heapSort(a, l);

    for(int i = 0; i < l; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}
