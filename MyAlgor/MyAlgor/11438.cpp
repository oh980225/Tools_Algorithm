#include <bits/stdc++.h>
using namespace std;

const int MAX = 18;
int N, M;
int parents[100001][MAX];
int depth[100001];
vector<int> adj[100001];

void bfs() {
  depth[1] = 1;
  queue<int> q;
  q.push(1);
  while(q.size()) {
    int cur = q.front();
    q.pop();

    for(int i = 0; i < adj[cur].size(); i++) {
      int temp = adj[cur][i];
      if(!depth[temp]) {
        depth[temp] = depth[cur] + 1;
			  parents[temp][0] = cur;
        q.push(temp);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;
  int from, to;
  for (int i = 0; i < N-1; ++i){
	  cin >> from >> to;
	  adj[from].push_back(to);
	  adj[to].push_back(from);
  }

  bfs();

  for (int j = 0; j < MAX - 1; ++j){
	  for (int i = 1; i <= N; ++i){
		  int k = parents[i][j];
		  if(k)
       parents[i][j+1] = parents[k][j];
	  }
  }

  cin >> M;

  for (int i = 0; i < M; ++i){
	  cin >> from >> to;

    // from의 깊이가 무조건 더 크거나 같다 
	  if(depth[from] < depth[to]) 
      swap(from,to);

	  int diff = depth[from] - depth[to];

    // 높이 맞춰주기 (이진수로 표현하는 것을 응용)
	  int j = 0;
	  while(diff){
		  if(diff % 2) {
			  from = parents[from][j];
		  }
		  j++;
		  diff /= 2;
	  }

    if(from == to) {
      cout  << from << '\n';
      continue;
    }

		for (int j = MAX - 1; j>=0; j--){
		 if(parents[from][j] != parents[to][j]){
		    from = parents[from][j];
		    to = parents[to][j];
		  }			
		}
		from = parents[from][0];  
	  cout << from << '\n';
	}
  return 0;
}