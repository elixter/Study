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
#include <regex>
#include <cstring>

using namespace std;

constexpr int MAXN = 1050;
constexpr int MAXM = 100050;
constexpr int INF = INT_MAX;

int N, M;
int dist[MAXN];

vector<pair<int, int>> adj[MAXN];

struct cmp {
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	fill_n(dist, MAXN, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int cur = pq.top().first;
		int curDist = pq.top().second;
		pq.pop();

		if (dist[cur] < curDist) continue;

		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].first;
			int nDist = adj[cur][i].second;

			if (dist[next] > dist[cur] + nDist) {
				dist[next] = dist[cur] + nDist;
				pq.push({ next, dist[next] });
			}
		}
	}
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, d; cin >> a >> b >> d;
		adj[a].push_back({ b, d });
	}

	int start, end; cin >> start >> end;

	dijkstra(start);

	cout << dist[end] << '\n';

	return 0;
}