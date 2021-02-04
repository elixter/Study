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
constexpr int MAX_LEN = 2500;

class KMP {
private:
    string _s;
    string _p;
    int _hitCnt = 0;
    vector<int> _idx;
    int _failFunction[MAX_LEN] = { 0, };
public:
    inline string getS() { return _s; }
    inline string getP() { return _p; }
    inline int getHitCount() { return _hitCnt; }
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
            if (_s[i] == _p[j]) {
                if (j == _p.length() - 1) {
                    _hitCnt++;
                    _idx.push_back(i - _p.length() + 1);
                    j = _failFunction[j - 1];
                }
                else j++;
            }
        }
    }

    // �ߺ��� ���� ����� ���� ã��
    void notOverlapRun() {
        int j = 0;
        for (int i = 0; i < _s.length(); i++) {
            while (j > 0 && _s[i] != _p[j]) j = _failFunction[j - 1];
            if (_s[i] == _p[j]) {
                if (j == _p.length() - 1) {
                    // �ߺ��� ���� ��� ������ ã���� �ٽ� ������ ó�� index���� ���� ������ ã�ư���.
                    _idx.push_back(i - _p.size() + 1);
                    _hitCnt++;
                    j = 0;
                }
                else j++;
            }
        }
    }
};

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string S, P;
    getline(cin, S);
    getline(cin, P);

    KMP kmp;

    kmp.setS(S.c_str());
    kmp.setP(P.c_str());
    kmp.makeFailFunction();
    kmp.notOverlapRun();

    cout << kmp.getIndexVec().size();

    return 0;
}