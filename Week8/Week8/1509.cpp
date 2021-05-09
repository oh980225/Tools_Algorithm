#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo1[2501][2501];
ll memo2[2501];
string str;

int isPal(int s, int e) {
	ll &res = memo1[s][e];
	if (res != -1)
		return res;
	if (s >= e)
		return 1;
	if (str[s] == str[e])
		return res = isPal(s + 1, e - 1);
	else
		return res = 0;
}

int main() {
	cin >> str;
	int n = str.size();
	str = '*' + str;
	memset(memo1, -1, sizeof(memo1));
	memset(memo2, -1, sizeof(memo2));

	memo2[0] = 0;
	for (int i = 1; i <= n; i++) {
		memo2[i] = memo2[i - 1] + 1;
		for (int j = 1; j < i; j++) {
			if (!isPal(j, i))
				continue;
			memo2[i] = min(memo2[i], memo2[j - 1] + 1);
		}
	}

	cout << memo2[n];

	return 0;
}