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

vector<pair<int, int>> adj[100001];

const lli MOD = 1000000007;

lli dfs(int parent, int current, lli& result) {
	// result : Global result;
	// _result : Local result;
	lli _result = 1;
	if (adj[current].size() == 0) return _result;
	for (auto ch : adj[current]) {
		if (parent == ch.first) continue;
		lli tmp = ch.second * dfs(current, ch.first, result) % MOD;
		result += _result * tmp % MOD;
		result %= MOD;
		_result += tmp;
		_result %= MOD;
	}
	return _result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(pair<int, int>(b, w));
		adj[b].push_back(pair<int, int>(a, w));
	}
	lli result = 0;
	dfs(0, 1, result);

	cout << result << '\n';

	return 0;
}