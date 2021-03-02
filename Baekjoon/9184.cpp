#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <unordered_set> 
#include <map>
#include <unordered_map>
#include <utility>
#include <stack>
#include <queue>
#include <random>
#include <cstring>
#include <chrono>
#include <numeric>

using namespace std;

typedef long long int lli;

int dp[21][21][21] = { 0, };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int a, b, c;

	dp[0][0][0] = 1;

	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) {
				if (i == 0 || j == 0 || k == 0) {
					dp[i][j][k] = 1;
				}
				else if (i < j && j < k) {
					dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
				}
				else {
					dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	while (1) {
		cin >> a >> b >> c;
		int res = 0;
		if (a == -1 && b == -1 && c == -1) return 0;
		if (a <= 0 || b <= 0 || c <= 0) res = 1;
		else if (a > 20 || b > 20 || c > 20) res = dp[20][20][20];
		else res = dp[a][b][c];

		cout << "w(" << a << ", " << b << ", " << c << ") = " << res << '\n';
	}

	return 0;
}