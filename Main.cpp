#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

int min(const int a, const int b) {
	if (a < b) return a;
	else return b;
}

int check(vector<string> board, int width, int height) {
	int b_start = 0;		// 검정으로 시작하는경우 다시 칠해야하는 정사각형 수
	int w_start = 0;		// 흰색으로 시작하는경우 다시 칠해야하는 정사각형 수

	for (int i = height; i < height + 8; i++) {
		for (int j = width; j < width + 8; j++) {
			if ((i - height) % 2 == 0) {
				if ((j - width) % 2 == 0) {
					if (board[i][j] == 'B') w_start++;
					else b_start++;
				}
				else {
					if (board[i][j] == 'W') w_start++;
					else b_start++;
				}
			}
			else {
				if ((j - width) % 2 == 0) {
					if (board[i][j] == 'W') w_start++;
					else b_start++;
				}
				else {
					if (board[i][j] == 'B') w_start++;
					else b_start++;
				}
			}
		}
	}

	return min(b_start, w_start);
}

int main() {
	ios::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;
	vector<string> board;

	int change = 64;			// 바꿔야하는 정사각형 개수

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		board.push_back(tmp);
	}

	for (int height = 0; height <= N - 8; height++) {
		int tmp_change = 0;
		for (int width = 0; width <= M - 8; width++) {
			tmp_change = check(board, width, height);
			if (tmp_change < change) change = tmp_change;
		}
		
	}

	cout << change << endl;

	return 0;
}