#include <bits/stdc++.h>

using namespace std;

int N, M, K;
map<int, int> db;
map<int, int> minusDb;

void input() {
  cin >> N >> M >> K;

  int key, value;
  for(int i = 0; i < N; i++) {
    cin >> key >> value;
    db[key] = value;
    minusDb[-key] = value;
  }
}

void save(int key, int value) {
  
}

pair<int, int> select(int key) {
  auto upIdx = db.lower_bound(key);
  auto downIdx = minusDb.lower_bound(-key);
  int upDiff = abs(upIdx->first - key);
  int downDiff = abs(downIdx->first + key);
  if(upIdx == downIdx) 
    return {key, db[upIdx->first]};

  if(K < upDiff && K < downDiff) 
    return {-1, -1};

  if(upIdx != downIdx && upDiff == downDiff) 
    return {-2, -2};

  if(downDiff < upDiff)
    return {-downIdx->first, downIdx->second};

  return {upIdx->first, upIdx->second};
}

void update(int key, int value) {
  auto selected = select(key);

  if(selected.first < 0) {
    return;
  }

  db[selected.first] = value;
  minusDb[-selected.first] = value;
}

void command() {
  int cmdNum, key, value;
  cin >> cmdNum >> key;

  auto upIdx = db.lower_bound(key);
  auto downIdx = minusDb.lower_bound(-key);
  int upDiff = abs(upIdx->first - key);
  int downDiff = abs(downIdx->first + key);

  switch (cmdNum) {
  case 1:
  {
    cin >> value;
    db[key] = value;
    minusDb[-key] = value;
    break;
  }
  case 2:
  {
    cin >> value;
    if(upDiff < downDiff) {
      if(upDiff <= K) {
        upIdx->second = value;
        minusDb[-(upIdx->first)] = value;
      }
    }
    if(upDiff > downDiff) {
      if(downDiff <= K) {
        downIdx->second = value;
        db[-(downIdx->first)] = value;
      }
    }
    break;
  }
  case 3:
  {
    if(upIdx->first != -downIdx->first && upDiff == downDiff) {
      cout << "?" << '\n';
      break;
    }

    if(K < upDiff && K < downDiff) {
      cout << -1 << '\n';
      break;
    }
    if(upDiff < downDiff) {
      cout << upIdx->second << '\n';
      break;
    }

    cout << downIdx->second << '\n';
    break;
  }
  
  default:
    break;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();

  while(M--) {
    command();
  }

  return 0;
}