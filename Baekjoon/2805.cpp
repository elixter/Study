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
#include <cstring>
#include <chrono>
#include <numeric>
#include <regex>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

constexpr int MAXN = 1'000'000;
constexpr ll MAXM = 2'000'000'000;

int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ll> tree;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        tree.push_back(tmp);
    }

    sort(tree.begin(), tree.end());

    ll start = 0;
    ll end = tree[n - 1];

    ll answer = 0;

    while (start <= end) {
        ll mid = (start + end) / 2;

        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += max((ll)0, tree[i] - mid);
        }

        if (cnt >= m) {
            start = mid + 1;
            answer = max(mid, answer);
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
