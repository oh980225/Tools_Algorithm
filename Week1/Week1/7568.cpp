#include<bits/stdc++.h>

using namespace std;

int n, x, y;
vector<int> ans;
vector<pair<int, int>> p;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		p.push_back(pair<int, int>(x, y));
	}

	for (int i = 0; i < n; i++) {
		auto cur = p[i];
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			auto other = p[j];
			if (cur.first < other.first) {
				if (cur.second < other.second)
					cnt++;
			}
		}
		ans.push_back(cnt);
	}

	for (auto element : ans) {
		cout << element << " ";
	}

	return 0;
}