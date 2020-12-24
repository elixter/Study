#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cmath>
#include <unordered_set> 

using namespace std;

int max(const int a, const int b) {
	if (a > b) return a;
	else return b;
}

long long dp[101][10] = { 0 };

#define MOD 1000000000

int main() {
	ios::sync_with_stdio(0);

	int N; 
	cin >> N;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
	dp[2][0] = 1, dp[2][1] = 1, dp[2][2] = 2, dp[2][3] = 2, dp[2][4] = 2, dp[2][4] = 2,
		dp[2][5] = 2, dp[2][6] = 2, dp[2][7] = 2, dp[2][8] = 2, dp[2][9] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i][0] = dp[i - 1][1] % MOD;
		dp[i][9] = dp[i - 1][8] % MOD;
		for (int j = 1; j <= 8; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
		}
	}
	
	long long result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[N][i];
	}

	cout << result % MOD << '\n';

	return 0;
}