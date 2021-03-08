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

constexpr int MAXN = 205;

int parent[MAXN] = { 0, };
int sz[MAXN] = { 0, };
vector<int> stops;

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (x > y) swap(x, y);
	parent[y] = x;
	sz[x] += sz[y];

	return;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	srand(time(NULL));

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			if (tmp == 0) continue;
			merge(i, j);
		}
	}

	for (int m = 0; m < M; m++) {
		int place; cin >> place;
		stops.push_back(place);
	}

	int prev = stops[0];
	bool conn = false;
	for (int i = 1; i < stops.size(); i++) {
		if (find(prev) != find(stops[i])) {
			conn = false;
			cout << "NO\n";
			return 0;
		}
		prev = stops[i];
		conn = true;
	}

	if (conn) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}