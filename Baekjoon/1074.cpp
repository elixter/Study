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
//void division(int n, int top_left, int top_left_r, int top_left_c, int r, int c) {
//	if (top_left_r == r && top_left_c == c) {
//		cout << top_left << '\n';
//		exit(0);
//	}
//	int minus1pow = pow(2, n - 1);
//	int next_top_left = 0;
//	if (n > 0) {
//		if (r >= top_left_r + minus1pow) {
//			if (c >= top_left_c + minus1pow) {
//				next_top_left = top_left + pow(minus1pow, 2) * 3;
//				division(n - 1, next_top_left, top_left_r + minus1pow, top_left_c + minus1pow, r, c);
//			}
//			else {
//				next_top_left = top_left + pow(minus1pow, 2) * 2;
//				division(n - 1, next_top_left, top_left_r + minus1pow, top_left_c, r, c);
//			}
//		}
//		else {
//			if (c >= top_left_c + minus1pow) {
//				next_top_left = top_left + pow(minus1pow, 2);
//				division(n - 1, next_top_left, top_left_r, top_left_c + minus1pow, r, c);
//			}
//			else {
//				division(n - 1, top_left, top_left_r, top_left_c, r, c);
//			}
//		}
//	}
//}
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(0);
//
//	// น้มุ 1074 Z
//	int N, r, c;
//	cin >> N >> r >> c;
//
//	division(N, 0, 0, 0, r, c);
//
//	return 0;
//}