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

int main(int argc, char** argv) {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++) {
		string cmd; cin >> cmd;
		int n; cin >> n;
		string strArr; cin >> strArr;
		vector<int> arr;
		bool reverse = false;
		bool error = false;

		int l = 0, r = max(0, n);

		int lArr = strArr.length();
		strArr = strArr.substr(1, lArr - 2);

		char* tok = strtok((char*)strArr.c_str(), ",");
		while (tok != nullptr) {
			int tmp;
			tmp = stoi(tok);
			arr.push_back(tmp);
			tok = strtok(NULL, ",");
		}

		int lCmd = cmd.length();
		for (int i = 0; i < lCmd; i++) {
			if (cmd[i] == 'D') {
				if (reverse) r--;
				else l++;
				if (l > r) {
					cout << "error" << '\n';
					error = true;
					break;
				}
			}
			else if (cmd[i] == 'R') {
				reverse = !reverse;
			}
		}

		if (error) continue;

		cout << "[";
		if (reverse) {
			for (int i = r - 1; i >= l; i--) {
				cout << arr[i];
				if (i != l) {
					cout << ",";
				}
			}
		}
		else {
			for (int i = l; i < r; i++) {
				cout << arr[i];
				if (i != r - 1) {
					cout << ",";
				}
			}
		}
		cout << "]" << '\n';
	}

	return 0;
}