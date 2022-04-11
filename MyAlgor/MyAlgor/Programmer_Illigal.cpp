#include <bits/stdc++.h>
using namespace std;
 
bool chk[8];
int banSize, userSize;
set<string> s;
 
void dfs(int index, string res, vector<string> user_id, vector<string> banned_id) {
  if (index == banSize) {
    sort(res.begin(), res.end());
    s.insert(res);
    return;
  }
 
  string bid = banned_id[index];
  int bidlen = bid.size();
 
  for (int i = 0; i < userSize; i++) {
    string uid = user_id[i];
 
    if (uid.size() != bidlen) continue;
    if (chk[i]) continue;

    bool flag = true;
    for (int j = 0; j < bidlen; j++) {
      if (bid[j] == '*') continue;
      
      if (uid[j] != bid[j]) {
        flag = false;
        break;
      }
    }

    if (flag) {
      chk[i] = true;
      dfs(index + 1, res + to_string(i), user_id, banned_id);
      chk[i] = false;
    }
  }
}
 
 
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    userSize = user_id.size();
    banSize = banned_id.size();
 
    dfs(0, "", user_id, banned_id);

    answer = s.size();
    return answer;
}