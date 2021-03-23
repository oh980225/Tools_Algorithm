#include <bits/stdc++.h>

using namespace std;

struct LOG {
	int x1, x2, num;
};

int n, q;
vector<LOG> logV;
vector<LOG> seq;
int result[100001];

bool compare(LOG a, LOG b) {
	return a.x1 < b.x1;
}

int main() {
	scanf_s("%d %d", &n, &q);

	for (int i = 0; i < n; i++) {
		int x1, x2, y;
		scanf_s("%d %d %d", &x1, &x2, &y);
		seq.push_back({ x1, x2, i + 1});
	}

	sort(seq.begin(), seq.end(), compare);
	
	int idx = 1;
	for (auto& element : seq) {
		if (logV.empty()) {
			logV.push_back({ element.x1, element.x2, element.num });
			result[element.num] = idx;
		}
		else if (element.x1 <= logV.back().x2) {
			logV.back().x2 = max(element.x2, logV.back().x2);
			result[element.num] = idx;
		}
		else {
			logV.push_back({ element.x1, element.x2, element.num });
			idx++;
			result[element.num] = idx;
		}
	}

	for (int i = 0; i < q; i++) {
		int f, s;
		scanf_s("%d %d", &f, &s);
		if (result[f] == result[s])
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}