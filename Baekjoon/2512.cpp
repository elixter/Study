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

constexpr int MAXN = 10000;
constexpr int MAXM = 1000000000;

int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> request;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        request.push_back(tmp);
    }
    cin >> m;

    sort(request.begin(), request.end());

    ll start = 0;
    ll end = request[n - 1];

    ll answer = 0;

    while (start <= end) {
        ll mid = (start + end) / 2;

        ll sum = 0;
        for (int i = 0; i < n; i++) {
            sum += min((ll)request[i], mid);
        }

        if (sum <= m) {
            start = mid + 1;
            answer = max(mid, answer);
        }
        
        if (sum > m) {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}

