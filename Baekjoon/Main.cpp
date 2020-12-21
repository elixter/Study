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

int main() {
	ios::sync_with_stdio(0);

	int N;			// Number of players
	cin >> N;
	int stairs[301] = { 0 };
	int dp[301] = { 0 };
	
	
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}

	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
	}

	cout << dp[N] << '\n';

	return 0;
}