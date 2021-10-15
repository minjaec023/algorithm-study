#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<deque<int> > vt;
int k;
int answer;

// 시계방향으로 돌리기
void turn_clock(int index) {
  int temp = vt[index].back();
  vt[index].pop_back();
  vt[index].push_front(temp);
}

// 반시계방향으로 돌리기
void turn_aclock(int index) {
  int temp = vt[index].front();
  vt[index].pop_front();
  vt[index].push_back(temp);
}


int main() {
  for(int i=0;i<4;i++) {
    string str;
    deque<int> temp;
    cin >> str;
    for(int j=0;j<str.size();j++) {
      temp.push_back(int(str[j]-'0'));
    }
    vt.push_back(temp);
  }
  scanf("%d", &k);
  for(int i=0;i<k;i++) {
    int num, dir;
    scanf("%d %d", &num, &dir);
    num -= 1;
    // 돌릴 정보 시계 1 반시계 -1
    vector<pair<int, int> > turns;
    turns.push_back(make_pair(num, dir));

    int prev_six = vt[num][6];
    int prev_two = vt[num][2];

    // 왼쪽 탐색
    int left_dir = dir;
    for(int j=num-1;j>=0;j--) {
      if(prev_six == vt[j][2]) break;
      prev_six = vt[j][6];
      if(left_dir == 1) {
        turns.push_back(make_pair(j, -1));
        left_dir = -1;
      }
      else {
        turns.push_back(make_pair(j, 1));
        left_dir = 1;
      }
    }

    // 오른쪽 탐색
    int right_dir = dir;
    for(int j=num+1;j<vt.size();j++) {
      if(prev_two == vt[j][6]) break;
      prev_two = vt[j][2];
      if(right_dir == 1) {
        turns.push_back(make_pair(j, -1));
        right_dir = -1;
      }
      else {
        turns.push_back(make_pair(j, 1));
        right_dir = 1;
      }
    }
    for(auto x: turns) {
      if(x.second == 1) {
        turn_clock(x.first);
      }
      else {
        turn_aclock(x.first);
      }
    }
  }

  if(vt[0][0] == 1) answer += 1;
  if(vt[1][0] == 1) answer += 2;
  if(vt[2][0] == 1) answer += 4;
  if(vt[3][0] == 1) answer += 8;
  printf("%d\n", answer);
}