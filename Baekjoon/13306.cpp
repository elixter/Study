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

int set[200051];
int origin[200051];

int find(int x) {
	if (x == set[x]) return x;
	else return set[x] = find(set[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	set[x] = y;
}

struct Input {
	int x, a, b;
};

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;

	for (int i = 0; i <= N; i++) {
		set[i] = i;
	}

	for (int i = 1; i < N; i++) {
		int tmp;
		cin >> origin[i + 1];
	}

	vector<string> ans;
	vector<Input> input;

	for (int i = 0; i < N + Q - 1; i++) {
		int x, a, b;
		cin >> x;
		if (x == 0) {
			cin >> a;
			input.push_back({ x, a, -1 });
		}
		else {
			cin >> a >> b;
			input.push_back({ x, a, b });
		}
	}

	for (int i = N + Q - 2; i >= 0; i--) {
		int x = input[i].x;
		int a = input[i].a;
		int b = input[i].b;
		if (x == 0) {
			merge(a, origin[a]);
		}
		else {
			if (find(a) == find(b)) ans.push_back("YES");
			else ans.push_back("NO");
		}
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}

	return 0;
}