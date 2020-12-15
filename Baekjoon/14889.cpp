//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//#include <climits>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(0);
//
//	int N;			// Number of players
//	cin >> N;
//
//	bool select[20] = { 0 };
//	int stats[20][20] = { 0 };
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> stats[i][j];
//		}
//	}
//
//	// 조합 생성을 위한 배열 초기화 => nCn/2
//	for (int i = 0; i < N / 2; i++) {
//		select[i] = 1;
//	}
//
//	// 선수 등번호
//	int number[20];
//	int min = INT_MAX;
//	do {
//		for (int i = 0, s = 0, l = N / 2; i < N; i++) {
//			if (select[i]) number[s++] = i;
//			else number[l++] = i;
//		}
//
//		int start = 0; int link = 0;
//		for (int i = 0; i < N / 2 - 1; i++) {
//			for (int j = i + 1; j < N / 2; j++) {
//				start += stats[number[i]][number[j]] + stats[number[j]][number[i]];
//				link += stats[number[i + N / 2]][number[j + N / 2]] + stats[number[j + N / 2]][number[i + N / 2]];
//			}
//		}
//		int diff = abs(start - link);
//		if (diff == 0) {
//			cout << 0 << '\n';
//			return 0;
//		}
//		if (diff < min) min = diff;
//	} while (prev_permutation(select, select + N));
//
//	cout << min << '\n';
//
//	return 0;
//}