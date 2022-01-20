#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> tree[50001];
int dep[50001];
bool chk[50001];
int parent[50001];

void findEqualParent(int f, int s) {
  if(dep[f] != dep[s]) {
    if(dep[f] < dep[s]) 
      while(dep[f] != dep[s]) 
        s = parent[s];
    if(dep[f] > dep[s]) 
      while(dep[f] != dep[s]) 
        f = parent[f];
  }

  while(f != s) {
    f = parent[f];
    s = parent[s];
  }

  cout << f << endl;
}

int main() {
  cin >> N;

  int first, second;
  for(int i = 0; i < N - 1; i++) {
    cin >> first >> second;
    tree[first].push_back(second);
    tree[second].push_back(first);
  }

  queue<int> q;
  q.push(1);
  chk[1] = true;
  parent[1] = 1;

  while(q.size()) {
    int cur = q.front();
    q.pop();

    for(int i = 0; i < tree[cur].size(); i++) {
      if(!chk[tree[cur][i]]) {
        chk[tree[cur][i]] = true;
        dep[tree[cur][i]] = dep[cur] + 1;
        parent[tree[cur][i]] = cur;
        q.push(tree[cur][i]);
      }
    }
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> first >> second;
    findEqualParent(first, second);
  }
  return 0;
}