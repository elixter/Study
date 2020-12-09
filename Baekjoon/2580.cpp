//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <map>
//#include <cmath>
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//#define SUDOKU_SIZE 9
//
//class coord {
//public:
//	int x;
//	int y;
//	coord(int x, int y) : x(x), y(y) {};
//};
//
//bool sudoku_check(int arr[SUDOKU_SIZE][SUDOKU_SIZE], int idxx, int idxy /* 입력 위치의 인덱스 */) {
//	// horizontal, vertical check
//	bool nominee_h[SUDOKU_SIZE + 1] = { false };
//	bool nominee_v[SUDOKU_SIZE + 1] = { false };
//	for (int i = 0; i < SUDOKU_SIZE; i++) {
//
//		if (nominee_h[arr[idxy][i]] || nominee_v[arr[i][idxx]]) {
//			return false;
//		}
//		if (arr[idxy][i] != 0) {
//			nominee_h[arr[idxy][i]] = true;
//		}
//		if (arr[i][idxx] != 0) {
//			nominee_v[arr[i][idxx]] = true;
//		}
//	}
//
//	// 9 area check
//	bool nominee[SUDOKU_SIZE + 1] = { false };
//	int areax = (int)(idxx / 3) * 3;
//	int areay = (int)(idxy / 3) * 3;
//	for (int i = areay; i < areay + 3; i++) {
//		for (int j = areax; j < areax + 3; j++) {
//			if (nominee[arr[i][j]]) {
//				return false;
//			}
//			if (arr[i][j] != 0) {
//				nominee[arr[i][j]] = true;
//			}
//		}
//	}
//
//	return true;
//}
//
//void back_tracking(int arr[SUDOKU_SIZE][SUDOKU_SIZE], int n, vector<coord> coords) {
//	// N이 0인 좌표들을 모아둔 vector보다 크면 return.
//	if (coords.size() < n) {
//		return;
//	}
//	int x = coords[n].x;
//	int y = coords[n].y;
//
//	if (arr[y][x] != 0) return;
//
//	for (int i = 1; i <= SUDOKU_SIZE; i++) {
//		arr[y][x] = i;
//		bool sudo_ck = sudoku_check(arr, x, y);
//		if (coords.size() - 1 == n && sudo_ck) {
//			for (int j = 0; j < SUDOKU_SIZE; j++) {
//				for (int k = 0; k < SUDOKU_SIZE; k++) {
//					cout << arr[j][k] << " ";
//				}
//				cout << '\n';
//			}
//			exit(0);
//		}
//		if (sudo_ck) {
//			back_tracking(arr, n + 1, coords);
//		}
//		arr[y][x] = 0;
//	}
//}
//
//// 백트래킹 스도쿠문제
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int sudoku[9][9] = { {0}, };
//
//	vector<coord> coords;
//
//	for (int i = 0; i < SUDOKU_SIZE; i++) {
//		for (int j = 0; j < SUDOKU_SIZE; j++) {
//			cin >> sudoku[i][j];
//			if (sudoku[i][j] == 0) {
//				coords.emplace_back(coord(j, i));
//			}
//		}
//	}
//
//	back_tracking(sudoku, 0, coords);
//
//	return 0;
//}