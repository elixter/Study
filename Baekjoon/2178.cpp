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

using namespace std;

typedef long long int lli;

constexpr int MAXNM = 100;
constexpr int INF = 10050;

int maze[MAXNM][MAXNM] = { 0, };
int visit[MAXNM][MAXNM] = { 0, };

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    cin.ignore();

    for (int i = 0; i < N; i++) {
        string tmp; getline(cin, tmp);
        int len = tmp.length();
        for (int j = 0; j < len; j++) {
            maze[i][j] = tmp[j] - '0';
            visit[i][j] = INF;
        }
    }

    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    visit[0][0] = 1;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int tmp = visit[current.first][current.second] + 1;

        if (current.first < N - 1 && maze[current.first + 1][current.second] != 0 && tmp < visit[current.first + 1][current.second]) {
            visit[current.first + 1][current.second] = tmp;
            q.push({ current.first + 1, current.second });
        }
        if (current.second < M - 1 && maze[current.first][current.second + 1] != 0 && tmp < visit[current.first][current.second + 1]) {
            visit[current.first][current.second + 1] = tmp;
            q.push({ current.first, current.second + 1 });
        }
        if (current.first > 0 && maze[current.first - 1][current.second] != 0 && tmp < visit[current.first - 1][current.second]) {
            visit[current.first - 1][current.second] = tmp;
            q.push({ current.first - 1, current.second });
        }
        if (current.second > 0 && maze[current.first][current.second - 1] != 0 && tmp < visit[current.first][current.second - 1]) {
            visit[current.first][current.second - 1] = tmp;
            q.push({ current.first, current.second - 1 });
        }

    }

    cout << visit[N - 1][M - 1] << '\n';

    return 0;
}