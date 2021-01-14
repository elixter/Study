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

typedef long long int lli;

lli dp[33][33] = { 0 };

void IthBinary(int n, int l, lli i, string& binary) {
	if (n == 0) return;
	if (l == 0) {
		for (int i = 0; i < n; i++) {
			binary += '0';
		}
		return;
	}
	lli binarynl = 0;

	// Number of n - 1 length of binary of number of 1 is l.
	for (int i = 0; i <= l; i++) {
		binarynl += dp[n - 1][i];
	}
	// if i is larger than binarynl, it means n th number must be 1.
	// else n th number must be 0.
	if (i <= binarynl) {
		binary += '0';
		IthBinary(n - 1, l, i, binary);
	}
	else {
		binary += '1';
		IthBinary(n - 1, l - 1, i - binarynl, binary);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	lli N, L, I;
	cin >> N >> L >> I;

	dp[0][0] = 1;
	// n C 0 or n C n is always 1.
	for (int i = 1; i <= 32; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	string binary;
	IthBinary(N, L, I, binary);

	cout << binary << '\n';

	return 0;
}