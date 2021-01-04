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
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(0);
//
//	// 백준 1697 숨바꼭질
//	int N, K;
//	cin >> N >> K;
//
//	queue<int> q1;
//	queue<int> q2;
//
//	bool visited[200001] = { false };
//
//	int second = 0;
//
//	q1.push(N);
//	visited[N] = true;
//
//	if (N == K) {
//		cout << 0 << '\n';
//		return 0;
//	}
//
//	while (!q1.empty() || !q2.empty()) {
//		second++;
//		if (q2.empty()) {
//			while (!q1.empty()) {
//				int current = q1.front();
//				q1.pop();
//				int a = current - 1;
//				int b = current + 1;
//				int c = current * 2;
//				if (a == K || b == K || c == K) {
//					cout << second << '\n';
//					return 0;
//				}
//				if (a >= 0 && !visited[a]) {
//					q2.push(a);
//					visited[a] = true;
//				}
//				if (b <= 100000 && !visited[b]) {
//					q2.push(b);
//					visited[b] = true;
//				}
//				if (c <= 200000 && !visited[c]) {
//					q2.push(c);
//					visited[c] = true;
//				}
//			}
//		}
//		else {
//			while (!q2.empty()) {
//
//				int current = q2.front();
//				q2.pop();
//				int a = current - 1;
//				int b = current + 1;
//				int c = current * 2;
//				if (a == K || b == K || c == K) {
//					cout << second << '\n';
//					return 0;
//				}
//				if (a >= 0 && !visited[a]) {
//					q1.push(a);
//					visited[a] = true;
//				}
//				if (b <= 100000 && !visited[b]) {
//					q1.push(b);
//					visited[b] = true;
//				}
//				if (c <= 200000 && !visited[c]) {
//					q1.push(c);
//					visited[c] = true;
//				}
//			}
//		}
//	}
//
//	cout << second << '\n';
//
//	return 0;
//}