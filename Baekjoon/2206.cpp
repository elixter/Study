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

constexpr int MAXNM = 1050;

int maze[MAXNM][MAXNM];
bool visit[MAXNM][MAXNM][2];
int N, M;
int dist = 0;

typedef pair<int, int> coord;

struct node {
	coord ij;
	bool bk;
	int dist;
};

queue<node> q;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	vector<string> strBoard;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		strBoard.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			maze[i + 1][j + 1] = strBoard[i][j] - '0';
		}
	}

	int dist = INT_MAX;
	bool reach = false;

	q.push({ {1, 1}, false, 1 });

	while (!q.empty()) {
		auto current = q.front();
		q.pop();

		int i = current.ij.first;
		int j = current.ij.second;

		if (i <= 0 || j <= 0 || i > N || j > M) continue;
		if (i == N && j == M) {
			dist = min(dist, current.dist);
			reach = true;
			continue;
		}

		if (visit[i][j][current.bk]) continue;
		visit[i][j][current.bk] = true;

		// breaked wall already.
		if (current.bk) {
			if (maze[i][j + 1] != 1) q.push({ {i, j + 1}, true, current.dist + 1 });
			if (maze[i][j - 1] != 1) q.push({ {i, j - 1}, true, current.dist + 1 });
			if (maze[i + 1][j] != 1) q.push({ {i + 1, j}, true, current.dist + 1 });
			if (maze[i - 1][j] != 1) q.push({ {i - 1, j}, true, current.dist + 1 });
		}
		// didn't break wall yet.
		else {
			// right
			if (maze[i][j + 1] == 1) {
				q.push({ {i, j + 1}, true, current.dist + 1 });
			}
			else {
				q.push({ {i, j + 1}, false, current.dist + 1 });
			}

			// left
			if (maze[i][j - 1] == 1) {
				q.push({ {i, j - 1}, true, current.dist + 1 });
			}
			else {
				q.push({ {i, j - 1}, false, current.dist + 1 });
			}

			// up
			if (maze[i + 1][j] == 1) {
				q.push({ {i + 1, j}, true, current.dist + 1 });
			}
			else {
				q.push({ {i + 1, j}, false, current.dist + 1 });
			}

			// down
			if (maze[i - 1][j] == 1) {
				q.push({ {i - 1, j}, true, current.dist + 1 });
			}
			else {
				q.push({ {i - 1, j}, false, current.dist + 1 });
			}
		}
	}

	if (!reach) cout << -1 << '\n';
	else cout << dist << '\n';

	return 0;
}