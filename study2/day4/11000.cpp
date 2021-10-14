#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct comp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
  }
};

struct comp2 {
  bool operator()(int a, int b) {
    return a > b;
  }
};

int n;
vector<int> vt;
priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq;
priority_queue<int, vector<int>, comp2> pq2;

int main() {
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    pq.push(make_pair(s, t));
  }
  while(!pq.empty()) {
    pair<int, int> cur = pq.top();
    pq.pop();
    if(pq2.empty()) {
      pq2.push(cur.second);
    }
    else{
      bool check = false;
      int top = pq2.top();
      if(top <= cur.first) {
        pq2.pop();
      }
      pq2.push(cur.second);
    }
  }
  int answer = pq2.size();
  printf("%d\n", answer);
}