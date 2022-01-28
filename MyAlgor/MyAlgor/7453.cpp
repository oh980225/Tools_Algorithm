#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;
vector<int> B;
vector<int> C;
vector<int> D;
vector<int> AB;
vector<int> CD;
typedef long long ll;
ll result = 0;

int main() {
  cin >> N;

  int a, b, c, d;
  for(int i = 0; i < N; i++) {
    cin >> a >> b >> c >> d;
    A.push_back(a);
    B.push_back(b);
    C.push_back(c);
    D.push_back(d);
  }

  for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++) 
      AB.push_back(A[i] + B[j]);

  for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++) 
      CD.push_back(-(C[i] + D[j]));

  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  int l, r = 0;
  for(auto element : AB) {
    int l = lower_bound(CD.begin(), CD.end(), element) - CD.begin();
    if(CD[l] == element) {
      int r = upper_bound(CD.begin(), CD.end(), element) - CD.begin();
      result += (r - l);
    }
  }

  cout << result;

  return 0;
}