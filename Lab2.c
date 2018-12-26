#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void table(unsigned char* p, int* shift_t) {
    int len_p = strlen(p);
	for (int i = 0; i < 256; i++)
		shift_t[i] = len_p;
	for (int i = 0; i < len_p - 1; i++)
		shift_t[p[i]] = len_p - 1 - i;
}

void make_shift(int shift, unsigned char* s) {
    int len_s = strlen(s);
	for (int i = 0; i < shift; i++)
		s[i] = s[len_s - shift + i];
}

int s_get(int shift, unsigned char* s) {
	int k = fread(&s[shift], 1, (17 - shift - 1), stdin);
	s[shift + k] = '\0';
	if (k == 17 - shift - 1) return 1;
	return 0;
}

int search(int* shift_t, unsigned char* p, unsigned char* s, int* k) {
    int len_s = strlen(s);
    int len_p = strlen(p);
	int t = 0;
	while (len_s - t >= len_p) {
		int i = len_p;
		do {
			printf("%d ", *k + t + i);
			i--;
		} while (s[t + i] == p[i] && i > 0);
		t += shift_t[s[t + len_p - 1]];
	}
	*k += t;
	return len_s - t;
}

void BM(int* shift_t, unsigned char* p, unsigned char* s) {
	int t = 1, shift = 0, k = 0;
	while (t == 1) {
		t = s_get(shift, s);
		shift = search(shift_t, p, s, &k);
		make_shift(shift, s);
	}
}

int main() {

	unsigned char s[17], p[17];
	int shift_t[256];
	scanf("%[^\n]", p);
	getchar();
    int len_s = strlen(s);
    int len_p = strlen(p);
    table(p, shift_t);
	BM(shift_t, p, s);
	return 0;
}
