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

int find(int x, int parent[]) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = find(parent[x], parent);
	}
}

void uni(int x, int y, int parent[]) {
	x = find(x, parent);
	y = find(y, parent);

	if (x != y) {
		parent[y] = x;
		if (x < y) parent[y] = x;
		else parent[x] = y;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int G, P;
	cin >> G;
	cin >> P;
	vector<int> g;
	int parent[100001] = { 0 };

	for (int i = 0; i < P; i++) {
		int tmp;
		cin >> tmp;
		g.push_back(tmp);
	}

	for (int i = 0; i <= G; i++) {
		parent[i] = i;
	}

	int result = 0;
	for (int i = 0; i < P; i++) {
		int k = find(g[i], parent);
		if (k == 0) break;
		uni(k - 1, k, parent);
		result++;
	}

	cout << result;

	return 0;
}