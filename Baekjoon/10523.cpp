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

using namespace std;

typedef long long int lli;

vector<pair<int, int>> vertex;

double getSlope(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) return 0;
	return (double)(B.first - A.first) / (double)(B.second - A.second);
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> ran(0, 2147483647);

	int n, p;
	cin >> n;
	cin >> p;

	vertex.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> vertex[i].first >> vertex[i].second;
	}

	for (int i = 1; i <= 500; i++) {
		int j = ran(rd) % n + 1;
		int k = ran(rd) % n + 1;
		int count = 0;
		int x, y;

		if (vertex[j].first == vertex[k].first) {
			x = vertex[j].first;

			for (int v = 1; v <= n; v++) {
				if (vertex[v].first == x) count++;
			}
		}
		else if (vertex[j].second == vertex[k].second) {
			y = vertex[j].second;

			for (int v = 1; v <= n; v++) {
				if (vertex[v].second == y) count++;
			}
		}
		else {
			double slope = getSlope(vertex[j], vertex[k]);

			for (int v = 1; v <= n; v++) {
				if (v == j || v == k) {
					count++;
					continue;
				}
				if (slope == getSlope(vertex[j], vertex[v])) count++;
			}
		}

		if (count >= (double)(p * 0.01 * n)) {
			cout << "possible\n";
			return 0;
		}
	}

	cout << "impossible\n";

	return 0;
}