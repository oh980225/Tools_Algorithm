#include <bits/stdc++.h>

using namespace std;

int N, M;
int ind[1001];
vector<int> adj[1001];
int result[1001];

void input() {
  cin >> N >> M;
  int first, second;
  for(int i = 0; i < M; i++) {
    cin >> first >> second;
    ind[second]++;
    adj[first].push_back(second);
  }
}

void calClass() {
  queue<pair<int, int>> q;

  for(int i = 1; i <= N; i++) 
    if(!ind[i]) 
      q.push({i, 1});

  while(!q.empty()) {
    auto curClass = q.front();
    q.pop();
    result[curClass.first] = curClass.second;

    for(int i = 0; i < adj[curClass.first].size(); i++) {
			int next = adj[curClass.first][i];
			ind[next]--;
			if (ind[next] == 0)
				q.push({next, curClass.second + 1});
		}
  }
}

void output() {
  for(int i = 1; i <= N; i++)
    cout << result[i] << " ";
}

int main() {
  input();

  calClass();

  output();

  return 0;
}