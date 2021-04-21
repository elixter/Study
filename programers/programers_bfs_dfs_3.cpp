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


using namespace std;

typedef long long int lli;

constexpr int MAXN = 205;

int parent[MAXN];

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    map<string, int> m;

    int len = words.size();
    for (int i = 0; i < len; i++) {
        m[words[i]] = 1;
    }

    int wordLen = begin.length();

    queue<pair<int, string>> q;

    q.push({ 0, begin });

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < wordLen; i++) {
            string tmp = cur.second;
            for (int j = 0; j < len; j++) {
                tmp[i] = words[j][i];

                if (tmp == target) {
                    answer = cur.first + 1;
                    return answer;
                }
                if (m.find(tmp) != m.end() && m[tmp] != 2) {
                    m[tmp] = 2;
                    q.push({ cur.first + 1, tmp });
                }
            }
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" });

    return 0;
}

