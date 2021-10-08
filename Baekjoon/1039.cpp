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
constexpr int INF = MAXN + 1;

bool visit[MAXN][10];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    char tmpN[MAXN];
    sprintf(tmpN, "%d", n);

    string strN = tmpN;

    queue<pair<string, int>> q;
    int result = -1;

    q.push({ strN, 0 });
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        string curNum = cur.first;
        int intCurNum = stoi(curNum);
        int depth = cur.second;

        if (cur.first[0] == '0') continue;
        if (depth == k) {
            result = max(result, intCurNum);
            continue;
        }
        if (visit[intCurNum][depth]) continue;
        visit[intCurNum][depth] = true;

        for (int i = 0; i < curNum.length() - 1; i++) {
            for (int j = i + 1; j < curNum.length(); j++) {
                string tmp = curNum;
                swap(tmp[i], tmp[j]);
                q.push({ tmp, depth + 1 });
            }
        }
    }

    cout << result;

    return 0;
}
