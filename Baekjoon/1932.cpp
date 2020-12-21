//// 백준알고리즘 1932번 정수 삼각형
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <climits>
//#include <cmath>
//#include <unordered_set> 
//
//using namespace std;
//
//int max(const int a, const int b) {
//	if (a > b) return a;
//	else return b;
//}
//
//int tri[500][500] = { 0 };
//int dp[500][500] = { 0 };
//
//int main() {
//	ios::sync_with_stdio(0);
//
//	int N;
//	cin >> N;
//
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j <= i; j++) {
//			cin >> tri[i][j];
//			if (i == N - 1) {
//				dp[i][j] = tri[i][j];
//			}
//		}
//	}
//
//	for (int i = N - 2; i >= 0; i--) {
//		for (int j = i; j >= 0; j--) {
//			dp[i][j] = tri[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
//		}
//	}
//
//	cout << dp[0][0] << '\n';
//
//	return 0;
//}