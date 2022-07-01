// x -> x + 1, x - 1, 2x
#include<bits/stdc++.h>

using namespace std;

int N, K;
int chk[100001];
int pre[100001];

int main() {
  cin >> N >> K;
  
  memset(chk, -1, sizeof(chk));
  queue<int> q;
  chk[N] = 0;
  pre[N] = N;
  q.push(N);
  
  while(q.size()) {
    auto cur = q.front();
    q.pop();
    
    if(cur == K) {
      break;
    }

    if(chk[cur + 1] == -1 && 0 <= cur + 1 && cur + 1 <= 100000) {
      chk[cur + 1] = chk[cur] + 1;
      pre[cur + 1] = cur;
      q.push(cur + 1);
    }

    if(chk[cur - 1] == -1 && 0 <= cur - 1 && cur - 1 <= 100000) {
      chk[cur - 1] = chk[cur] + 1;
      pre[cur - 1] = cur;
      q.push(cur - 1);
    }

    if(chk[cur * 2] == -1 && 0 <= cur * 2 && cur * 2 <= 100000) {
      chk[cur * 2] = chk[cur] + 1;
      pre[cur * 2] = cur;
      q.push(cur * 2);
    }
  }

  cout << chk[K] << '\n';

  vector<int> ans;  
  int idx = K;
  while(idx != N) {
    ans.push_back(idx);
    idx = pre[idx];
  }
  ans.push_back(N);

  for(int i = ans.size() - 1; 0 <= i; i--) {
    cout << ans[i] << " ";
  }

  return 0;
}