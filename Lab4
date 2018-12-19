#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char *a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

long int P(char *a, int n) {
    int i = n - 1;
    while (i > 0 && a[i - 1] >= a[i])
        i--;
    if (!i)
        return 0;
    int j = n - 1;
    while (a[j] <= a[i - 1])
        j--;
    swap(a, i - 1, j);
    j = n - 1;

    while (i++ < j--)
        swap(a, i, j);
    return 1;
}

int l(int n){
    if ( n == 1 )
        return 1;
return n*l(n-1);
}


int main()
{
    long int n;
    unsigned char a[11];
    unsigned char b[11];
    scanf("%s", a);
    scanf("%d", &n);
    int len = strlen(a);

    char max = a[0];
    int v=0, w=0;
    int t = 0;
    if (n > len) n = l(len)-1;
    for (int i  = 0; i < len; i++) {
           if((a[i] > '9') || (a[i] < '0'))
                w++;
         }

     for (int i  = 1; i < len; i++) {
        if(a[i] == a[i-1])
                v++;
         }

    if (v!=0 || w!=0) {
        printf("bad input");
    } else{

        for (int i = 0; i < len; i++){
            if (a[i] > max)
                max = a[i];
        }
        if (max == a[0]) return 0; else{


            for (int i = 0; i < n; i++){
                    if ((a[i]=='0')&&(len==1)) return 0;
                    b[i] = a[i];
            if (P(a, len)==1)
                printf("%s\n", a);

            }
        }
    }
    return 0;
}
