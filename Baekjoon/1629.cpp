#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int lli;

lli solution(int n, int pow, int mod) {
	if (pow == 1) return n % mod;
	else if (pow == 0) return 1 % mod;
	lli result;
	lli tmp = solution(n, pow / 2, mod);
	if (pow % 2 == 0) {
		result = tmp * tmp % mod;
	}
	else {
		result = tmp * solution(n, pow / 2 + 1, mod) % mod;
	}
	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << solution(a, b, c);

	return 0;
}