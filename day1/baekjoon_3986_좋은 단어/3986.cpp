#include <iostream>
#include <stack>
using namespace std;

int main() {
  int n;
  int count = 0;
  string str;
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    stack<char> st;
    cin >> str;
    for(auto x: str) {
      if(st.empty() || st.top() != x) {
        st.push(x);
      }
      else st.pop();
    }
    if(st.empty()) count++;
  }
  printf("%d\n", count);
}