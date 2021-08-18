#include <iostream>
#include <deque>
#include <queue>
using namespace std;

deque<int> d;
queue<int> positions;

int count_dist() {
  int dist = 0;
  for(auto x: d) {
    if(x == positions.front()) break;
    else dist++;
  }
  return dist;
}

int main() {
  int n, m, pos;
  int count = 0;
  scanf("%d %d", &n, &m);
  
  for(int i=0;i<m;i++){
    scanf("%d", &pos);
    positions.push(pos);
  }
  
  for(int i=0;i<n;i++){
    d.push_back(i+1);
  }

  while(!positions.empty()){
    if(positions.front() == d.front()) {
      positions.pop();
      d.pop_front();
      continue;
    }
    int dist = count_dist();
    
    // left
    if(dist <= d.size()/2) {
      int temp = d.front();
      d.pop_front();
      d.push_back(temp);
      count++;
    }
    // right
    else {
      int temp = d.back();
      d.pop_back();
      d.push_front(temp);
      count++;
    }
  }
  printf("%d\n", count);
}