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

int set[1001];
int sz[1001];

int find(int x) {
	if (x == set[x]) return x;
	else return set[x] = find(set[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y);
	set[y] = x;
	sz[x] += sz[y];
}

struct Edge {
	int x1, x2, edge;
};

bool compare1(Edge a, Edge b) {
	return a.edge < b.edge;
}

bool compare2(Edge a, Edge b) {
	return a.edge > b.edge;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int n, m, k;
	while (1) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) break;

		int minSpan = 0;
		int maxSpan = 0;

		for (int i = 0; i <= n; i++) {
			set[i] = i;
		}

		vector<Edge> E;	// Edges

		for (int i = 0; i < m; i++) {
			char color;
			int x1, x2, c;
			cin >> color >> x1 >> x2;
			if (color == 'B') c = 1;
			else c = 0;
			E.push_back({ x1, x2, c });
		}

		sort(E.begin(), E.end(), compare1);

		for (int i = 0; i < m; i++) {
			int x1 = E[i].x1, x2 = E[i].x2;
			if (find(x1) != find(x2)) {
				merge(x1, x2);
				minSpan += E[i].edge;
			}
		}

		// initialize set.
		for (int i = 0; i <= n; i++) {
			set[i] = i;
			sz[i] = 0;
		}

		sort(E.begin(), E.end(), compare2);

		for (int i = 0; i < m; i++) {
			int x1 = E[i].x1, x2 = E[i].x2;
			if (find(x1) != find(x2)) {
				merge(x1, x2);
				maxSpan += E[i].edge;
			}
		}

		if (k <= maxSpan && k >= minSpan) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}