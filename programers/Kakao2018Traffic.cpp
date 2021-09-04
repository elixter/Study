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

struct Node {
    double start, end;
};

struct cmp {
    bool operator() (Node a, Node b) {
        if (a.start < b.start) return true;
        else if (a.start == b.start)
            return a.end < b.end;
        else return false;
    }
};

Node convertTime(string log) {
    double hh, mm;
    double ss, duration;
    sscanf(log.c_str(), "2016-09-15 %lf:%lf:%lf %lfs", &hh, &mm, &ss, &duration);

    double start = 0, end = 0;
    end += (double)hh * (double)3600.0;
    end += (double)mm * (double)60.0;
    end += ss;

    start = end - duration;
    start += 0.001;

    return Node{ start, end };
}

bool rangeCheck(double start, double end, double point) {
    return start <= point && end > point;
}

int solution(vector<string> lines) {
    int answer = 0;

    vector<Node> logs;

    for (auto line : lines) {
        logs.push_back(convertTime(line));
    }

    sort(logs.begin(), logs.end(), cmp());

    for (int i = 0; i < logs.size(); i++) {
        double current = logs[i].start;

        int tmp = 0;
        for (int j = 0; j < logs.size(); j++) {
            if (rangeCheck(logs[j].start, logs[j].end + 1, current)) tmp++;
        }
        answer = max(answer, tmp);

        current = logs[i].end;
        tmp = 0;
        for (int j = 0; j < logs.size(); j++) {
            if (rangeCheck(logs[j].start, logs[j].end + 1, current)) tmp++;
        }
        answer = max(answer, tmp);
    }

    return answer;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);


    cout << solution({ "2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s" });

    return 0;
}