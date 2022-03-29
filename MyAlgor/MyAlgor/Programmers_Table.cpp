#include <bits/stdc++.h>

using namespace std;

int cur;
stack<int> st;

// 연결 리스트 node
struct Node {
  int num;
  Node* prev;
  Node* next;
  Node(int num):num(num),prev(NULL),next(NULL){};
};

vector<Node*> v;

string solution(int n, int k, vector<string> cmd) {
  string answer(n,'O');
    
  // 연결리스트 생성 및 연결
  v = vector<Node*>(n);
    
  for(int i=0;i<n;i++)
    v[i] = new Node(i);
    
  v[0]->next = v[1];
  v[n-1]->prev = v[n-2];
    
  for(int i=1;i<n-1;i++){
    v[i]->next = v[i+1];
    v[i]->prev = v[i-1];
  }
    
  cur = k;

  for(string s : cmd){
    if(s[0] == 'D') {
      int x = stoi(s.substr(2));

      while(x--) {
        cur = v[cur]->next->num;
      }
    }
    
    if(s[0] == 'U') {
      int x = stoi(s.substr(2));

      while(x--) {
        cur = v[cur]->prev->num;
      }
    }

    if(s[0]=='C'){
      st.push(cur);

      if(v[cur]->prev != NULL) {
        v[cur]->prev->next = v[cur]->next;
      }

      if(v[cur]->next != NULL){
        v[cur]->next->prev = v[cur]->prev;
        cur = v[cur]->next->num;
        continue;
      }
      
      cur = v[cur]->prev->num;
    }

    if(s[0]=='Z'){
      int top = st.top(); 
      st.pop();

      if(v[top]->prev != NULL)
        v[top]->prev->next = v[top];

      if(v[top]->next != NULL)
        v[top]->next->prev = v[top];
    }
  }
    
  priority_queue<int, vector<int>, greater<int>> pq;
  while(st.size()) {
    pq.push(st.top());
    st.pop();
  }

  for(int i = 0; i < n; i++) {
    if(pq.size() && i == pq.top()) {
      answer[i] = 'X';
      pq.pop();
    }
  }

  return answer;
}