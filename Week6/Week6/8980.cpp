#include <bits/stdc++.h>

using namespace std;

int n, c, m, ans;
int capacity[2001];

struct BOX {
	int s, e, num;
};

vector<BOX> box;

bool compare(BOX a, BOX b) {
	return a.e == b.e ? a.s < b.s : a.e < b.e;
}

int main() {
	scanf_s("%d %d", &n, &c);
	scanf_s("%d", &m);

	box.resize(m);

	for (int i = 0; i < m; i++) 
		scanf_s("%d %d %d", &box[i].s, &box[i].e, &box[i].num);

	sort(box.begin(), box.end(), compare);

	for (int i = 0; i < m; i++) {
		int cnt = 0;

		for (int j = box[i].s; j < box[i].e; j++) {
			cnt = max(cnt, capacity[j]);
		}

		int left = min(box[i].num, c - cnt);
		ans += left;

		for (int j = box[i].s; j < box[i].e; j++)
			capacity[j] += left;
	}

	printf("%d", ans);

	return 0;
}
