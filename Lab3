#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c_hash(unsigned char *pat, int len){
    long hash = 0;
	for (int i = 0; i < len; i++)
		hash += (pat[i] % 3) * (pow(3, i));
	return hash;
}

int main(){
    unsigned char p[17], s[17], st;
    fgets(p, 17, stdin);
    int l = strlen(p) - 1;
    fgets (s, l + 1, stdin);
    int maxstep = pow(3, l - 1);
    int hash_p = c_hash(p, l);
    printf("%d ", hash_p);
    int hash_s = c_hash(s, l);

    for (int i = 0; feof(stdin) == 0; i++){
        if (hash_s == hash_p){
            for (int j = 0; j < l; j++){
                printf("%d ", j + i + 1);
                if (p[j] != s[(i + j)%l])
                    break;
            }
        }
        st = fgetc(stdin);
        hash_s = (hash_s - (s[i%l] % 3)) / 3 + ((st % 3) * maxstep);
        s[i%l] = st;
    }

    return 0;
}
