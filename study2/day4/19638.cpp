#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int n, h, t;

int main() {
  scanf("%d %d %d", &n, &h, &t);
  for(int i=0;i<n;i++) {
    int temp;
    scanf("%d", &temp);
    pq.push(temp);
  }
  int i;
  for(i=0;i<t;i++){
    int top = pq.top();
    if(top < h) break;
    if(top == 1) continue;
    pq.pop();
    pq.push(top/2);
  }
  int top = pq.top();
  if(top < h) {
    printf("YES\n");
    printf("%d\n", i);
  }
  else {
    printf("NO\n");
    printf("%d\n", top);
  }
}