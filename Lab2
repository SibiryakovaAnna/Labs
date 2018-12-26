#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void table(char* p, int* shift_table, int* len_p) {
	for (int i = 0; i < 256; i++)
		shift_table[i] = len_p;
	for (int i = 0; i < len_p - 1; i++)
		shift_table[p[i]] = len_p - i - 1;
}

void make_shift(int* shift, char* s, int* len_s) {
	for (int i = 0; i < shift; i++)
		s[i] = s[len_s - shift + i];
}


int search(int* shift_table, char* p, char* s, int* k, int* len_s, int* len_p) {
	int t = 0;
	while (len_s - t >= len_p) {
		int i = len_p;
		do {
			printf("%d", k + t + i);
			i--;
		} while (s[t + i] == p[i] && i > 0);
	}
	k += t;
	return len_s - t;
}

void BM(int* shift_table, char* p,char* s, int* len_s, int* len_p) {
	int t = 1,shift = 0,k = 0;
	while (t) {
		t = fgets(s, 20, stdin);
		shift = search(shift_table, p, s, k, len_s, len_p);
		make_shift(shift, s, len_s);
	}
}

int main() {
	char s[20], p[20];
	int shift_table[256];
	fgets(p, 20, stdin);

	int len_s = strlen(s);
	int len_p = strlen(p);

    table(p, shift_table, len_p);
	BM(shift_table, p, s, len_s, len_p);
	return 0;
}
