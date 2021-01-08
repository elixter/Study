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

map<int, int> step;

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	long long int A, B;
	cin >> A >> B;

	queue<long long int> q;
	q.push(A);
	step[A] = 0;

	if (A == B) {
		cout << 1 << '\n';
		return 0;
	}

	while (!q.empty()) {
		long long int current = q.front();
		q.pop();
		long long int calc_a = current * (long long int)2;
		long long int calc_b = current * (long long int)10 + 1;

		if (calc_a <= B) {
			if (calc_a == B) {
				cout << step[current] + 2 << '\n';
				return 0;
			}
			else {
				if (step.find(calc_a) == step.end()) {
					q.push(calc_a);
					step[calc_a] = step[current] + 1;
				}
				else {
					step[calc_a] = min(step[current] + 1, step[calc_a]);
				}
			}
		}
		if (calc_b <= B) {
			if (calc_b == B) {
				cout << step[current] + 2 << '\n';
				return 0;
			}
			else {
				if (step.find(calc_b) == step.end()) {
					q.push(calc_b);
					step[calc_b] = step[current] + 1;
				}
				else {
					step[calc_b] = min(step[current] + 1, step[calc_b]);
				}
			}
		}
	}

	cout << -1 << '\n';

	return 0;
}