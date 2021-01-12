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

int w[10001] = { 0 };
lli dp[10001][2] = { 0 };	// [][1] : select, [][0] : not select.
vector<int> adj[10001];
bool isSelect[10001] = { false };
bool visit[10001] = { false };

void dfs(int parent, int current) {
	lli select_current = 0;
	lli nSelect_current = 0;
	for (int ch : adj[current]) {
		if (ch != parent) {
			dfs(current, ch);
			select_current += dp[ch][0];
			nSelect_current += max(dp[ch][0], dp[ch][1]);
		}
	}
	dp[current][1] = select_current + w[current];
	dp[current][0] = nSelect_current;
}

void check(int start, int select) {
	if (select == 1) {
		isSelect[start] = true;
		for (int ch : adj[start]) {
			if (!visit[ch]) {
				visit[ch] = true;
				check(ch, 0);
			}
		}
	}
	else {
		for (int ch : adj[start]) {
			if (!visit[ch]) {
				visit[ch] = true;
				if (dp[ch][1] > dp[ch][0]) {
					check(ch, 1);
				}
				else {
					check(ch, 0);
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, 1);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	if (dp[1][0] > dp[1][1]) {
		check(1, 0);
	}
	else {
		check(1, 1);
	}
	for (int i = 0; i <= N; i++) {
		if (isSelect[i]) cout << i << " ";
	}
	cout << '\n';

	return 0;
}