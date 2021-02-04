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

using namespace std;

// ���ڿ��� �ִ� ����.
constexpr int MAX_LEN = 1000050;

class KMP {
private:
    string _s;
    string _p;
    int _hitCnt = 0;
    vector<int> _idx;
    int _failFunction[MAX_LEN] = { 0 };
public:
    inline string getS() { return _s; }
    inline string getP() { return _p; }
    inline int getHitCount() { return _hitCnt; }
    inline int* getFailFunction() { return _failFunction; }
    inline vector<int> getIndexVec() { return _idx; }
    inline void setS(string s) { _s = s; }
    inline void setP(string p) { _p = p; }

    // ������ ã�� Ƚ��, ������ index vector, �����Լ��� �ʱ�ȭ�ϴ� �Լ�.
    void clear() {
        _hitCnt = 0;
        _idx.clear();
        int ffClear[MAX_LEN] = { 0, };
        copy(ffClear, ffClear + MAX_LEN, _failFunction);
    }

    void makeFailFunction() {
        int j = 0;
        for (int i = 1; i < _p.length(); i++) {
            while (j > 0 && _p[i] != _p[j]) j = _failFunction[j - 1];
            if (_p[i] == _p[j]) _failFunction[i] = ++j;
        }
    }

    // ����ã��
    void run() {
        int j = 0;
        for (int i = 0; i < _s.length(); i++) {
            while (j > 0 && _s[i] != _p[j]) j = _failFunction[j - 1];
            if (_s[i] == _p[j]) j++;
            if (j == _p.length()) {
                _hitCnt++;
                _idx.push_back(i - j + 1);
                j = _failFunction[j - 1];
            }
        }
    }

    // �ߺ��� ���� ����� ���� ã��
    void notOverlapRun() {
        int j = 0;
        for (int i = 0; i < _s.length(); i++) {
            while (j > 0 && _s[i] != _p[j]) j = _failFunction[j - 1];
            if (_s[i] == _p[j]) j++;
            if (j == _p.length()) {
                // �ߺ��� ���� ��� ������ ã���� �ٽ� ������ ó�� index���� ���� ������ ã�ư���.
                _idx.push_back(i - _p.size() + 1);
                _hitCnt++;
                j = 0;
            }
        }
    }
};

int gcd(int a, int b) {
    int tmp, n;
    if (a < b) swap(a, b);

    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);



    int N;
    cin >> N;
    for (int t = 0; t < N; t++) {

        string A, W, S;
        cin >> A >> W >> S;

        priority_queue<int, vector<int>, greater<int>> pq;
        map<char, int> idx;
        for (int i = 0; i < A.length(); i++) {
            idx[A[i]] = i;
        }

        string tmp = W;

        for (int i = 0; i < A.length(); i++) {
            for (int j = 0; j < W.length(); j++) {
                tmp[j] = A[(idx[W[j]] + i) % A.length()];
            }
            KMP kmp;
            kmp.setS(S);
            kmp.setP(tmp);
            kmp.makeFailFunction();
            kmp.run();
            if (kmp.getHitCount() == 1) pq.push(i);
        }

        if (pq.size() == 0) cout << "no solution\n";
        else if (pq.size() == 1) cout << "unique: " << pq.top() << '\n';
        else {
            cout << "ambiguous: ";
            while (!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << '\n';
        }
    }

    return 0;
}