#include <iostream>
#include <map>
using namespace std;

int n;
int answer;
map<int, int> m;

int check_strke (int q, int answer) {
  int strike = 0;
  for(int i=0;i<3;i++) {
    if(to_string(q)[i] == to_string(answer)[i]) strike++;
  }
  return strike;
}

int check_ball_strike (int q, int answer) {
  int ball = 0;
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(i != j && to_string(q)[i] == to_string(answer)[j]) ball++;
    }
  }
  return ball;
}

bool is_include(int n) {
  map<int, int> temp;
  for(int i=0;i<3;i++) {
    if(to_string(n)[i] == '0') return true;
    temp[to_string(n)[i]]++;
  }
  if(temp.size() != 3) return true;
  return false;
}

int main() {
  scanf("%d", &n);
  for(int i=0;i<n;i++) {
    int q, strike, ball;
    scanf("%d %d %d", &q, &strike, &ball);
    for(int j=123;j<=987;j++) {
      if(is_include(j)) continue;
      if(check_strke(q, j) == strike && check_ball_strike(q, j) == ball) {
        m[j]++;
      }
    }
  }
  for(auto x: m) {
    if(x.second == n) answer++;
  }
  printf("%d\n", answer);
}