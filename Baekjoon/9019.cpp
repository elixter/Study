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



int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	int tenpow[5] = { 1000, 100, 10, 1, 0 };

	for (int test_case = 0; test_case < T; test_case++) {
		int A, B;
		cin >> A >> B;

		string reg[10000] = { "" };
		bool visit[10000] = { false };
		queue<int> q;
		q.push(A);

		visit[A] = true;
		while (1) {
			int current = q.front();
			q.pop();

			// Operator D
			int D = current * 2 % 10000;
			if (D == B) {
				cout << reg[current] + "D" + '\n';
				break;
			}
			else {
				if (!visit[D]) {
					visit[D] = true;
					q.push(D);
					reg[D] = reg[current] + "D";
				}
			}

			// Operator S
			int S = current - 1;
			if (S == -1) S = 9999;
			if (S == B) {
				cout << reg[current] + "S" + '\n';
				break;
			}
			else {
				if (!visit[S]) {
					visit[S] = true;
					q.push(S);
					reg[S] = reg[current] + "S";
				}
			}

			// Operator L
			int L = (current / 1000) + (current % 1000 * 10);

			if (L == B) {
				cout << reg[current] + "L" + '\n';
				break;
			}
			else {
				if (!visit[L]) {
					visit[L] = true;
					q.push(L);
					reg[L] = reg[current] + "L";
				}
			}

			// Operator R
			int R = (1000 * (current % 10)) + (current / 10);

			if (R == B) {
				cout << reg[current] + "R" + '\n';
				break;
			}
			else {
				if (!visit[R]) {
					visit[R] = true;
					q.push(R);
					reg[R] = reg[current] + "R";
				}
			}
		}
	}

	return 0;
}