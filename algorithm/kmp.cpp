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

// 문자열의 최대 길이.
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

    // 패턴을 찾은 횟수, 패턴의 index vector, 실패함수를 초기화하는 함수.
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

    // 패턴찾기
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

    // 중복을 피할 경우의 패턴 찾기
    void notOverlapRun() {
        int j = 0;
        for (int i = 0; i < _s.length(); i++) {
            while (j > 0 && _s[i] != _p[j]) j = _failFunction[j - 1];
            if (_s[i] == _p[j]) {
                if (j == _p.length() - 1) {
                    // 중복을 피할 경우 패턴을 찾으면 다시 패턴의 처음 index부터 같은 패턴을 찾아간다.
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