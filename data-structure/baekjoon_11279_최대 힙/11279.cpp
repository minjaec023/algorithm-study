#include <iostream>
#include <queue>
using namespace std;

int main() {
  priority_queue<int> pq;
  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    int x;
    scanf("%d", &x);
    if(x == 0) {
      if(pq.empty()) {
        printf("0\n");
        continue;
      }
      printf("%d\n", pq.top());
      pq.pop();
    }
    else {
      pq.push(x);
    }
  }
}