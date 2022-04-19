#include <bits/stdc++.h>

using namespace std;

vector<int> leftV;
vector<int> rightV;
vector<int> parent;
int root;
int cnt;

int dfs(int cur, int limit, vector<int>& num) {
  int l = 0;
  int r = 0;

  if(leftV[cur] != -1) {
    l = dfs(leftV[cur], limit, num);
  }

  if(rightV[cur] != -1) {
    r = dfs(rightV[cur], limit, num);
  }

  if(num[cur] + l + r <= limit) {
    return num[cur] + l + r;
  }

  if(num[cur] + min(l,r) <= limit) {
    cnt++;
    return num[cur] + min(l,r);
  }

  cnt += 2;
  return num[cur];
}

int splitGroup(int limit, vector<int>& num) {
  cnt = 1;
  dfs(root, limit, num);
  return cnt;
}

int solution(int k, vector<int> num, vector<vector<int>> links) {
  int answer = 0;
  int numSize = num.size();
  leftV.resize(numSize);
  rightV.resize(numSize);
  parent = vector<int>(numSize, -1);

  for(int i = 0; i < links.size(); i++) {
    leftV[i] = links[i][0];
    rightV[i] = links[i][1];
    
    if(leftV[i] != -1) {
      parent[leftV[i]] = i;
    }

    if(rightV[i] != -1) {
      parent[rightV[i]] = i;
    }
  }

  for(int i = 0; i < numSize; i++) {
    if(parent[i] == -1) {
      root = i;
      break;
    }
  }

  int l = 0;
  int r = 1e8 + 1;
  for(int i = 0; i < numSize; i++) {
    l = max(l, num[i]);
  }

  while(l <= r) {
    int mid = (l + r) / 2;
    int groupCount = splitGroup(mid, num);
    if(groupCount <= k) {
      answer = mid;
      r = mid - 1;
      continue;
    }

    l = mid + 1;
  }

  return answer;
}