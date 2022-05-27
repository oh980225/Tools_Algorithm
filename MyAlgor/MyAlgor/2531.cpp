#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
int ans;
int chk[3005];

void checkTypeCnt(int typeCnt) {
  if(chk[c]) {
    ans = max(ans, typeCnt);
  } else {
    ans = max(ans, typeCnt + 1);
  }
}

int main() {
  cin >> N >> d >> k >> c;

  vector<int> sushi;

  int type;
  for(int i = 0; i < N; i++) {
    cin >> type;
    sushi.push_back(type);
  }

  for(int i = 0; i < N; i++) {
    sushi.push_back(sushi[i]);
  }

  int l = 0;
  int r = l + k - 1;
  int typeCnt = 0;
  for(int i = 0; i < k; i++) {
    if(!chk[sushi[i]]) {
      typeCnt++;
    }

    chk[sushi[i]]++;
  }

  checkTypeCnt(typeCnt);
  while(l < N) {
    chk[sushi[l]]--;
    if(!chk[sushi[l]]) {
      typeCnt--;
    }
    l++;

    if(!chk[sushi[r + 1]]) {
      typeCnt++;
    }
    chk[sushi[r + 1]]++;
    r++;

    checkTypeCnt(typeCnt);
  }

  cout << ans;

  return 0;
}