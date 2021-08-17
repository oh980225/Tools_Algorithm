#include <bits/stdc++.h>

using namespace std;

string memo[105][105];

string stringCal(string num1, string num2) {
	string result = "";
	int sum = 0;
	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += (num1.back() - '0');
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += (num2.back() - '0');
			num2.pop_back();
		}
		result.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string comb(int n, int m) {
	if (n == m || m == 0) {
		return "1";
	}
	string &result = memo[n][m];
	if (result != "") {
		return result;
	}
	return result = stringCal(comb(n - 1, m - 1), comb(n - 1, m));
}

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	cout << comb(n, m);

	return 0;
}