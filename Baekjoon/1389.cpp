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

bool check(bool visit[101], int n) {
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) return false;
	}
	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	int adj[101][101] = { 0 };
	int cost[101][101] = { 0 };
	int bacon[101] = { 0 };

	// input
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}


	for (int k = 1; k <= N; k++) {
		// k is start vertex.
		bool visit[101] = { false };
		queue<int> q;
		q.push(k);
		visit[k] = true;

		// Repeat while visit every vertices.
		while (!check(visit, N)) {
			int current = q.front();
			q.pop();
			for (int i = 1; i <= N; i++) {
				if (adj[current][i] != 0) {
					if (!visit[i]) {
						q.push(i);
						visit[i] = true;
						// cost of k to i = cost of k to current + cost of current to i.
						cost[k][i] = cost[k][current] + adj[current][i];
					}
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			bacon[k] += cost[k][i];
		}
	}

	int min = bacon[1];
	int min_idx = 1;
	for (int i = 2; i <= N; i++) {
		if (min > bacon[i]) {
			min = bacon[i];
			min_idx = i;
		}
	}

	cout << min_idx << '\n';

	return 0;
}