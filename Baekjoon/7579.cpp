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

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	int c[101] = { 0 };
	int m[101] = { 0 };
	int sum_c = 0;

	for (int i = 1; i <= N; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum_c += c[i];
	}

	int dp[10001] = { 0 };

	for (int i = 0; i <= N; i++) {
		for (int j = sum_c; j >= c[i]; j--) {
			dp[j] = max(dp[j - c[i]] + m[i], dp[j]);
		}
	}

	for (int i = 0; i <= sum_c; i++) {
		if (dp[i] >= M) {
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}