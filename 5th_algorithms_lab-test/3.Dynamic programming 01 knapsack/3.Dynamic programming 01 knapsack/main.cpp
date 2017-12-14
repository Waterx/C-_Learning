#include<stdio.h>

int max(int a, int b) {
	if (a >= b)
		return a;
	else if (a < b)
		return b;
}

int main() {
	int c = 10;
	int n = 5;
	int m[5][10] = { 0, 0, 0, 0, 0 };
	int w[5] = { 2, 2, 6, 5, 4 };
	int v[5] = { 6, 3, 5, 4, 6 };
	int x[5] = { 0 };

	for (int j = 0; j < c; j++) {
		if (1 + j - w[n - 1] >= 0)
			m[n - 1][j] = v[n - 1];
		else
			m[n - 1][j] = 0;
	}
	//依次求解m[i][j],0<=i<n,0<=j<=c
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < c; j++) {
			if (j + 1< w[i])
				m[i][j] = m[i + 1][j];
			else
				m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}
	}

	//求x[i]，从m[1][c]开始
	int j = c - 1;
	int i = 0;
	for (i = 0; i < n - 1; i++) {
		if (m[i][j] == m[i + 1][j]) {
			x[i] = 0;
		}
		else {
			x[i] = 1;
			j = j - w[i];
		}
	}

	if (m[i][j] > 0)
		x[i] = 1;
	else
		x[i] = 0;


	return 0;
}