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

constexpr int MAXN = 100'000;
constexpr int MAXVAL = 1'000'000'000;

int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ll> liquid;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        liquid.push_back(tmp);
    }

    sort(liquid.begin(), liquid.end());

    ll start = 0;
    ll end = n - 1;

    ll answer = 0;
    ll assemble = 2 * MAXVAL;

    int liq1 = 0;
    int liq2 = n - 1;

    while (start < end) {
        ll sum = liquid[start] + liquid[end];
        if (sum == 0) {
            cout << liquid[start] << " " << liquid[end];
            return 0;
        }

        if (sum > 0) {
            if (abs(assemble) > abs(sum)) {
                assemble = sum;
                liq1 = start;
                liq2 = end;
            }
            end--;
        }
        else {
            if (abs(assemble) > abs(sum)) {
                assemble = sum;
                liq1 = start;
                liq2 = end;
            }
            start++;
        }
    }

    cout << liquid[liq1] << " " << liquid[liq2];

    return 0;
}
