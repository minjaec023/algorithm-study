#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int> q;

int main() {
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int num;
    scanf("%d", &num);
    if(num==0) {
      if(q.empty()) {
        printf("-1\n");
      }
      else {
        printf("%d\n", q.top());
        q.pop();
      }
    }
    else {
      for(int j=0;j<num;j++) {
        int present;
        scanf("%d", &present);
        q.push(present);
      }
    }
  }
}