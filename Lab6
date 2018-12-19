#include <stdio.h>
#include <stdlib.h>

void quickSort (int start, int end, int *a){
    int w, x, i, j;
    i = start;
    j = end;
    x = a[(start + end)/2];
    while (i < j){
        while(a[i] < x)
            i++;
        while(a[j] > x)
            j--;
        if(i <= j) {
            w = a[i];
            a[i] = a[j];
            a[j] = w;
            i++;
            j--;
    }

    if (start < j)  quickSort(start, j, a);
    if (i < end) quickSort(i, end, a);
    }
}

int main() {
    int *a;
    int l, q, start = 0, end;
    scanf("%d",l);
    end = l - 1;
    a = (int*)malloc(l * sizeof(int));
    for (int i = 0; i < l; i++)
        scanf("%d", &a[i]);

    quickSort(start, end, l);

    for (int i = 0; i < l; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}
