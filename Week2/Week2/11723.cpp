#include<bits/stdc++.h>

using namespace std;

int s;
int m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	string str;
	int x;
	for (int i = 0; i < m; i++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			if (!(s & 1 << x)) {
				s = s | (1 << x);
			}
			continue;
		}
		if (str == "remove") {
			cin >> x;
			if (s & 1 << x) {
				s = s & ~(1 << x);
			}
			continue;
		}
		if (str == "all") {
			s = (1 << 21) - 1;
			continue;
		}
		if (str == "empty") {
			s = 0;
			continue;
		}
		if (str == "toggle") {
			cin >> x;
			s = s ^ (1 << x);
			continue;
		}
		if (str == "check") {
			cin >> x;
			if (s & 1 << x) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
			continue;
		}
	}

	return 0;
}