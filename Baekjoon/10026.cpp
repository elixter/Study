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

vector<string> colorMap;
int nonColorWeak = 0;
int colorWeak = 0;
int visit[102][102];

void dfs(char prev, int x, int y, bool weak) {
	if (colorMap[y][x] != 'X') {
		// Red-green color weak.
		if (weak) {
			if (visit[y][x] != 1) {
				if (prev == 'R' || prev == 'G') {
					// If same color, check visit.
					if (colorMap[y][x] == 'R' || colorMap[y][x] == 'G') visit[y][x] = 1;
					else return;
				}
				else if (prev == 'B') {
					if (colorMap[y][x] == 'B') visit[y][x] = 1;
					else return;
				}
				dfs(colorMap[y][x], x + 1, y, true);
				dfs(colorMap[y][x], x, y + 1, true);
				dfs(colorMap[y][x], x - 1, y, true);
				dfs(colorMap[y][x], x, y - 1, true);
			}

		}

		// Non red-green color weak.
		else {
			if (visit[y][x] != 2) {
				if (prev == 'R') {
					if (colorMap[y][x] == 'R') visit[y][x] = 2;
					else return;
				}
				else if (prev == 'G') {
					if (colorMap[y][x] == 'G') visit[y][x] = 2;
					else return;
				}
				else if (prev == 'B') {
					if (colorMap[y][x] == 'B') visit[y][x] = 2;
					else return;
				}
				dfs(colorMap[y][x], x + 1, y, false);
				dfs(colorMap[y][x], x, y + 1, false);
				dfs(colorMap[y][x], x - 1, y, false);
				dfs(colorMap[y][x], x, y - 1, false);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;
	colorMap.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		colorMap.push_back("X" + tmp + "X");
	}
	colorMap.push_back("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");

	// Travasal color weak.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] != 1) {
				colorWeak++;
				dfs(colorMap[i][j], j, i, true);
			}
		}
	}


	// Travasal noncolor weak.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j] != 2) {
				nonColorWeak++;
				dfs(colorMap[i][j], j, i, false);
			}
		}
	}

	cout << nonColorWeak << " " << colorWeak << '\n';

	return 0;
}