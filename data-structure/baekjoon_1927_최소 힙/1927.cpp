#include <iostream>
#include <queue>
using namespace std;

struct compare{
  bool operator()(int x, int y) {
    return x > y;
  }
};

int main() {
  priority_queue<int, vector<int>, compare> pq;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    scanf("%d", &x);
    if(x == 0) {
      if(pq.empty()) printf("0\n");
      else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    }
    else pq.push(x); 
  }
}