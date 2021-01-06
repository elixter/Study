//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <climits>
//#include <cmath>
//#include <unordered_set> 
//#include <map>
//#include <unordered_map>
//#include <utility>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//void bfs(int adj[][1001], int N, int v) {
//	// param adj : adjust matrix
//	// param N : number of vertices
//	// param v : start vertex
//	bool visit[1001] = { false };
//	queue<int> q;
//	q.push(v);
//	visit[v] = true;
//
//	while (!q.empty()) {
//		int current = q.front();
//		q.pop();
//
//		cout << current << " ";
//
//		for (int i = 0; i <= N; i++) {
//			if (adj[current][i] != 0) {
//				if (!visit[i]) {
//					q.push(i);
//					visit[i] = true;
//				}
//			}
//		}
//	}
//	cout << '\n';
//}
//
//void dfs(int adj[][1001], int N, int v) {
//	// param adj : adjust matrix
//	// param N : number of vertices
//	// param v : start vertex
//	static bool dfs_visit[1001] = { false };
//	dfs_visit[v] = true;
//
//	cout << v << " ";
//
//	for (int i = 0; i <= N; i++) {
//		if (adj[v][i] != 0) {
//			if (!dfs_visit[i]) {
//				dfs(adj, N, i);
//			}
//		}
//	}
//}
//
//int adj[1001][1001] = { 0 };
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(0);
//
//	// 1260 DFS¿Í BFS
//	int N, M, V;
//	cin >> N >> M >> V;
//
//	for (int i = 0; i < M; i++) {
//		int s, d;		// start, destination.
//		cin >> s >> d;
//		adj[s][d] = 1;
//		adj[d][s] = 1;
//	}
//
//	dfs(adj, N, V);
//	cout << '\n';
//	bfs(adj, N, V);
//
//
//	return 0;
//}