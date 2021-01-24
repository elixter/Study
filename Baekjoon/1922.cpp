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
int minSpan = 0;

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

struct conn {
	int x1, x2, edge;
};

bool compare(conn a, conn b) {
	return a.edge < b.edge;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}

	vector<conn> connections;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		connections.push_back({ a, b, c });
	}

	sort(connections.begin(), connections.end(), compare);

	for (int i = 0; i < M; i++) {
		int x1 = connections[i].x1, x2 = connections[i].x2;
		if (find(x1) != find(x2)) {
			merge(x1, x2);
			minSpan += connections[i].edge;
		}
	}

	cout << minSpan << '\n';

	return 0;
}