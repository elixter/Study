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

constexpr int MAXK = 10000;
constexpr int MAXN = 1'000'000;
constexpr int MAXLEN = INT_MAX - 1;

int k, n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> utp;
    
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        utp.push_back(tmp);
    }

    sort(utp.begin(), utp.end());

    ll start = 1;
    ll end = utp[k - 1];

    ll answer = 0;

    while (start <= end) {
        ll mid = (start + end) / 2;
        if (mid == 0) break;

        ll cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += (ll)utp[i] / mid;
        }

        if (cnt >= n) {
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
