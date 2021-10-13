#include <iostream>
#include <queue>
using namespace std;

struct compare{
  bool operator()(int a, int b) {
    if(abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
  }
};

int n;
priority_queue<int, vector<int>, compare> q;

int main() {
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int x;
    scanf("%d", &x);
    if(x==0) {
      if(q.empty()) {
        printf("0\n");
      }
      else {
        printf("%d\n", q.top());
        q.pop();
      }
    }
    else {
      q.push(x);
    }
  }
}