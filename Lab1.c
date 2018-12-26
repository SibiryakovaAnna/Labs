#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void char_b(char* b, double* bb, int l) {
	for (int i = 0; i < l; i++) {
		if (((b[i] - 48) < 10) && ((b[i] - 48) >= 0))
            bb[i] = b[i] - 46;
		if (((b[i] - 65) < 6) && ((b[i] - 65) >= 0))
            bb[i] = b[i] - 53;
		if (((b[i] - 97) < 6) && ((b[i] - 97) >= 0))
            bb[i] = b[i] - 85;
		if (b[i] == 46) bb[i] = 1;
	}
}
void b_char(int* aa, char* a) {
  int i = 0;
	while (aa[i] != -2) {
		if (aa[i] < 10)
            a[i] = aa[i] + 48;
		if (aa[i] >= 10)
            a[i] = aa[i] + 55;
		if (aa[i] == -1)
            a[i] = aa[i] + 47;
		printf("%c", a[i]);
		i++;
	}
}

long long int i_pow(int p1, int n) {
	long long int pr = p1;
	for (int i = 1; i < n; i++)
		pr = pr*p1;
	return pr;
}
double d_pow(int p1, int n) {
	double pr = p1;
	for (int i = 1; i<n; i++)
		pr = pr*p1;
	return pr;
}

long long int b_to_dec(double* bb, double* num1, int p1, int l) {
	int s, pp = 1000, c = 0;
	 for (int i = 0; i < l; i++)
            bb[i] = bb[i] - 2;
	long long int num2;
	for (int i = 0; i < l; i++) {
		if (bb[i] == -1) {
			pp = i;
			c++;
		}
	}
	if (pp == l - 1) s = -1;
	if (pp == 0) s = -1;
	if (pp == 1000) s = 1;
	if ((pp < l - 1) && (pp > 0)) s = 0;
	if (c > 1) s = -1;
	if (s == 1) {
        num2 = bb[l - 1];
        for (int i = l - 2; i >= 0; i--) {
		long long int t = bb[i] * i_pow(p1, l - 1 - i);
		num2 += t;
        }
		num1[0] = -2;
	}
	if (s == 0) {
		num2 = bb[pp - 1];
        for (int i = pp - 2; i >= 0; i--) {
		long long int t = bb[i] * i_pow(p1, pp - 1 - i);
		num2 += t;
	}
        for (int i = pp + 1; i < l; i++) {
		double k = bb[i] / d_pow(p1, i - pp);
		num1[0] += k;
		}
	}
	return num2;
}

void swap(int array[], int l) {
	int t;
	for (int i = 0; i <= l/2; i++) {
		t = array[i];
		array[i] = array[l - i];
		array[l - i] = t;
	}
}

void dec_to_b(int* aa, double* num1, long long int num2, int p2) {
	long long int left, quot;
	int i = 0;
	int pp = 0;
	double num = num1[0];
	while (num2 >= p2) {
		quot = num2 / p2;
		left = num2 - quot * p2;
		aa[i] = left;
		i++;
		num2 = quot;
	}
	aa[i] = num2;
	swap(aa, i);
	if (num != -2) {
		i++;
		aa[i] = -1;
		pp = i;
		do {
			i++;
			num = num * p2;
			aa[i] = num;
			num = num - aa[i];
		} while (num > 0);
	}
	if ((i - pp) > 12) 
    aa[pp + 13] = -2;
	else aa[i + 1] = -2;
}

int main() {
    char b[16], a[16];
	int  p1, p2;

    scanf("%d", &p1);
    scanf("%d", &p2);
    scanf("%s", b);

    int l = strlen(b);
    double bb[16];
    char_b(b, bb, l);

    int k = 0;
	for (int i = 0; i < l; i++)
		if (bb[i] > p1 + 1)
            k++;

	int t = 0;
	if ((l == 4) && (b[0] == '0' && b[1] == '.' && b[2] == '.' && b[3] == '0')) t++;
	if ((l == 3) && (b[0] == '0' && b[1] == '.' && b[2] == '0')) t++;
	if ((l == 2) && (b[0] == '0' || b[0] == '.')&&(b[1] == '0' || b[1] == '.')) t++;
	if ((l == 1) && (b[0] == '.')) t++;

	if (((p1 >= 2) || (p1 <= 16)) && ((p2 >= 2) || (p2 <= 16)) && (p1 != 1) && (p2 != 1) && (k == 0) && ( t != 1)){
			int aa[64];
            double b_double[14] = {};
			long long int b_int = b_to_dec(bb, b_double, p1, l);
				dec_to_b(aa, b_double, b_int, p2);
				b_char(aa, a);
		}
		else printf("bad input");

	return 0;
}
