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

typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int N;
	lli W;

	cin >> N >> W;

	vector<int> S;
	vector<int> Q;
	vector<pair<double, int>> k;	// S / Q.
	vector<pair<int, int>> ans;

	for (int i = 0; i < N; i++) {
		int s, q;
		cin >> s >> q;
		S.push_back(s);
		Q.push_back(q);
		k.push_back({ (double)s / q, i });
	}
	sort(k.begin(), k.end());

	lli q_sum = 0;
	priority_queue<int> employed;
	int num_employed = 0;
	lli q_sum_ans = 0;
	int idx_ans = 0;
	double k_ans = 0;

	// First, employing all workers that s / q is same or k.
	// Second, if total wage is higher than budget W, fire workers from higher wage to lower wage.
	// Priority queue employed's size is number of employed workers.
	for (int i = 0; i < N; i++) {
		int idx = k[i].second;
		q_sum += Q[idx];
		employed.push(Q[idx]);
		while (q_sum * k[i].first > W) {
			q_sum -= employed.top();
			employed.pop();
		}

		if (employed.size() > num_employed || (employed.size() == num_employed && q_sum * k[i].first < q_sum_ans * k_ans)) {
			num_employed = employed.size();
			idx_ans = i;
			q_sum_ans = q_sum;
			k_ans = k[i].first;
		}
	}

	for (int i = 0; i <= idx_ans; i++) {
		ans.push_back({ Q[k[i].second], k[i].second });
	}
	sort(ans.begin(), ans.end());

	cout << num_employed << '\n';
	for (int i = 0; i < num_employed; i++) {
		cout << ans[i].second + 1 << '\n';
	}

	return 0;
}