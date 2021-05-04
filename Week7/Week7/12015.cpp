#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<int> a;
vector<int> answer;

// lower_bound 응용 문제!(증가하는 부분 수열)
int main() {
	cin >> n;
	a.resize(n);
	answer.push_back(-1);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (auto element : a) {
		int back = answer.back();
		if (back < element) {
			answer.push_back(element);
			ans++;
		}
		else {
			vector<int>::iterator it = lower_bound(answer.begin(), answer.end(), element);
			*it = element;
		}
	}

	cout << ans;

	return 0;
}