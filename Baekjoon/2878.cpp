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

int64_t MOD = pow(2, 64);

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	priority_queue<int> pq;
	int M, N;
	cin >> M >> N;
	lli total_friend_candy = -M;
	vector<lli> candy;
	lli anger = 0;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		candy.push_back(tmp);
		total_friend_candy += tmp;
	}

	sort(candy.begin(), candy.end());
	for (int i = 0; i < N; i++) {
		lli distrib = min(candy[i], total_friend_candy / (N - i));
		anger += distrib * distrib;
		total_friend_candy -= distrib;
	}

	cout << anger << '\n';

	return 0;
}