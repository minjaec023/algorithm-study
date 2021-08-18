#include <iostream>
#include <stack>
using namespace std;

stack<char> st;

int main() {
  string str;
  string answer = "";
  cin >> str;
  for(auto x: str) {
    // 알파벳이면 바로 결괏값에 추가
    if(x>=65 && x <97) {
      answer += x;
    }
    else {
      // '(' 라면 스택에 추가
      if(x == '(') {
        st.push(x);
      }
      // ')' 라면 스택에 '('가 나올 때까지 pop해서 answer에 추가
      else if(x == ')') {
        while(true) {
          if(st.top()=='(') {
            st.pop();
            break;
          }
          answer += st.top();
          st.pop();
        }
      }
      // '*' 나 '/' 라면 스택 확인후 같은 우선순위 연산자가 있으면 pop하고 answer에 추가
      // 스택에 Push
      else if(x == '*' || x == '/') {
        if(!st.empty() && (st.top() == '*' || st.top() == '/')) {
          answer += st.top();
          st.pop();
        }
        st.push(x);
      }

      // '+' 나 '-' 라면 우선순위가 더 낮은 것들이 없으므로 스택에 있는 연산자들 모두 pop해서 answer에 추가
      // 단 괄호가 있는 경우 현재 연산자가 우선순위가 더 높으므로 '(' 가 발견될 때까지만 pop해서 answer에 추가
      else {
        if(st.empty()) st.push(x);
        else {
          while(!st.empty() && st.top() != '(') {
            answer += st.top();
            st.pop();
          }
          st.push(x);
        }
      }
    }
  }

  // 스택에 남은 연산자들 모두 pop해서 answer에 추가
  while(!st.empty()) {
    answer += st.top();
    st.pop();
  }
  cout << answer << endl;
}