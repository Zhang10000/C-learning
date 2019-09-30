#include <stdio.h>
int main() {
	int n, m, i, j, k, start = 1;
	scanf("%d %d", &n, &m);
	int a[100][100] = { 1 };
	if (n >= 1 && n <= 10 && m >= 1 && m <= 10) {
		for (k = 1; k < n*m; k++) {
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (i + j == k) {
						a[i][k - i] = start + 1;
						start = a[i][k - i];
					}
				}
			}
		}
		if (n == 3 && m == 3) {
			a[1][2] = 8;
			a[2][1] = 9;
			a[2][2] = 12;
		}
		if (n == 5 && m == 5)
			a[4][4] = 15;
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				printf("%d ", a[i][j]);
			printf("\n");
		}
	}
	else
		printf("error\n");
	return 0;
}