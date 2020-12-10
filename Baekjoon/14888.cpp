//#define _CRT_SECURE_NO_WARNINGS
//
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//bool compare(long long a, long long b) {
//	return a > b;
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//
//	int N;
//	cin >> N;
//	vector<long long> A;
//	for (int i = 0; i < N; i++) {
//		long long tmp;
//		cin >> tmp;
//		A.push_back(tmp);
//	}
//	vector<long long> vec_res;
//	vector<int> op;			// operator
//	for (int i = 0; i < 4; i++) {
//		int tmp;
//		cin >> tmp;
//		switch (i) {
//		case(0):
//			for (int j = 0; j < tmp; j++) {
//				op.push_back(i);
//			}
//			break;
//		case(1):
//			for (int j = 0; j < tmp; j++) {
//				op.push_back(i);
//			}
//			break;
//		case(2):
//			for (int j = 0; j < tmp; j++) {
//				op.push_back(i);
//			}
//			break;
//		case(3):
//			for (int j = 0; j < tmp; j++) {
//				op.push_back(i);
//			}
//			break;
//		}
//	}
//
//	do {
//		long long result = A[0];
//		for (int i = 1; i < A.size(); i++) {
//			switch (op[i - 1]) {
//			case(0):
//				result += A[i];
//				break;
//			case(1):
//				result -= A[i];
//				break;
//			case(2):
//				result *= A[i];
//				break;
//			case(3):
//				result /= A[i];
//				break;
//			}
//		}
//		vec_res.push_back(result);
//	} while (next_permutation(op.begin(), op.end()));
//
//	sort(vec_res.begin(), vec_res.end(), compare);
//
//	cout << vec_res[0] << '\n';
//	cout << vec_res[vec_res.size() - 1] << '\n';
//
//	return 0;
//}