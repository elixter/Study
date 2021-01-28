#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

typedef long long int lli;

const auto MOD = 10000;

void matmul(int a[2][2], int b[2][2])
{
	int x = a[0][0] * b[0][0] +
		a[0][1] * b[1][0];
	int y = a[0][0] * b[0][1] +
		a[0][1] * b[1][1];
	int z = a[1][0] * b[0][0] +
		a[1][1] * b[1][0];
	int w = a[1][0] * b[0][1] +
		a[1][1] * b[1][1];

	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = w;
}

void power(int mat[2][2], int n) {
	int i;
	int tmpMat[2][2] = { {1, 1},
					  {1, 0} };

	for (int i = 2; i <= n; i++) {
		matmul(mat, tmpMat);
	}
}

void solution(int mat[2][2], int n) {
	int tmpMat1[2][2] = { {1, 1},
					  {1, 0} };
	int tmpMat2[2][2] = { {1, 1},
						  {1, 0} };

	if (n == 0) return;
	if (n == 1) return;
	if (n % 2 == 1) {
		solution(tmpMat1, n / 2), solution(tmpMat2, n / 2 + 1);
		matmul(tmpMat1, tmpMat2);
	}
	else {
		solution(tmpMat1, n / 2);
		matmul(tmpMat1, tmpMat1);
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			mat[i][j] = tmpMat1[i][j] % MOD;
		}
	}
}


int fib(int mat[2][2], int n) {
	if (n == 0) return 0;
	solution(mat, n - 1);
	return mat[0][0];
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	lli n;
	while (1) {
		cin >> n;
		int mat[2][2] = { {1, 1},
					  {1, 0} };

		if (n == -1) break;
		cout << fib(mat, n) % MOD << '\n';
	}

	return 0;
}