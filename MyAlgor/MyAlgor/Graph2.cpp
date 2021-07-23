#include <string>
#include <vector>

using namespace std;
int adj[105][105];
int chk[105];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    memset(adj, 0x3f, sizeof(adj));

    for (auto result : results) 
        adj[result[0]][result[1]] = 1;

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) {
				int next = adj[i][k] + adj[k][j];
				if (adj[i][j] > next) 
					adj[i][j] = next;
			}

	for (int i = 1; i <= n; i++) {
		int cnt = 1;

		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (!chk[j] && adj[i][j] != 1061109567) {
				chk[j] = 1;
				cnt++;
			}
		}

		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (!chk[j] && adj[j][i] != 1061109567) {
				chk[j] = 1;
				cnt++;
			}
		}

		if (cnt == n) {
			answer++;
		}

		memset(chk, 0, sizeof(chk));
	}

    return answer;
}

int main() {
	vector<vector<int>> results;
	vector<int> r1 = { 4, 3 };
	vector<int> r2 = { 4, 2 };
	vector<int> r3 = { 3, 2 };
	vector<int> r4 = { 1, 2 };
	vector<int> r5 = { 2, 5 };
	results.push_back(r1);
	results.push_back(r2);
	results.push_back(r3);
	results.push_back(r4);
	results.push_back(r5);

	printf("%d", solution(5, results));

    return 0;
}