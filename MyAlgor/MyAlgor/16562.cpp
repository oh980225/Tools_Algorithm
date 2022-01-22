#include <bits/stdc++.h>

using namespace std;

int N, M, k;
int costArr[10001];

class UnionFind {
public:
	vector<int> p;

public:
	void init(int n) {
		p.resize(n + 1);
		for (int i = 0; i < p.size(); i++) 
			p[i] = i;
	}

	int Find(int x) {
		if (x == p[x])
			return p[x];
		return p[x] = Find(p[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) {
			if (costArr[y] < costArr[x]) 
				p[x] = y;
			else 
				p[y] = x;
	  }
  }
};

int main() {
  cin >> N >> M >> k;

  int cost;
  for(int i = 1; i <= N; i++) {
    cin >> cost;
    costArr[i] = cost;
  }

  UnionFind u;
  u.init(N);

  int first, second;
  for(int i = 0; i < M; i++) {
    cin >> first >> second;
    u.Union(first, second);
  }

  int result = 0;
  for(int i = 1; i <= N; i++) {
    if(u.p[i] == i)
      result += costArr[u.p[i]];
  }

  if(result <= k) {
    cout << result;
    return 0;
  }

  cout << "Oh no";
  return 0;
}