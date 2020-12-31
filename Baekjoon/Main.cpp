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

using namespace std;

void search(bool field[][52], int x, int y) {
	if (field[y][x]) {
		field[y][x] = false;
		search(field, x - 1, y);
		search(field, x + 1, y);
		search(field, x, y + 1);
		search(field, x, y - 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T, N, M, K;
	cin >> T;
	
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> M >> N >> K;
		bool field[52][52] = { false };
		int count = 0;

		// 배추의 위치 입력
		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[y + 1][x + 1] = true;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i + 1][j + 1]) {
					search(field, j + 1, i + 1);
					count++;
				}
			}
		}
		cout << count << '\n';
	}

	return 0;
}