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

using namespace std;

int dp[151][100501] = { 0 };

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	int w[151] = { 0 };
	int v[151] = { 0 };

	for (int i = 1; i <= N; i++) {
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j >= w[i]) dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K] << '\n';

	return 0;
}