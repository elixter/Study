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

int set[50001];

int find(int x) {
	if (x == set[x]) return x;
	else return set[x] = find(set[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	set[x] = y;
}

struct Node {
	int x1, x2, w;
};

bool compare(Node a, Node b) {
	return a.w > b.w;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int p, w;
	cin >> p >> w;

	int v, c;
	cin >> v >> c;

	vector<Node> inputs;

	for (int i = 0; i <= p; i++) {
		set[i] = i;
	}

	for (int i = 0; i < w; i++) {
		int x1, x2, w;
		cin >> x1 >> x2 >> w;
		inputs.push_back({ x1, x2 ,w });
	}

	sort(inputs.begin(), inputs.end(), compare);

	int min = 50001;

	for (int i = 0; i < w; i++) {
		int x1, x2, w;
		x1 = inputs[i].x1;
		x2 = inputs[i].x2;
		w = inputs[i].w;

		merge(x1, x2);
		if (w < min) min = w;
		if (find(v) == find(c)) break;
	}

	cout << min;

	return 0;
}