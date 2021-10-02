#include <iostream>
#include <vector>
using namespace std;

int r, c;
vector<string> map;
vector<string> new_map;
vector<pair<int, int> > vt;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool scope_check(int x, int y) {
  return x>=0 && x<r && y>=0 && y<c;
}


bool check_dir(int x, int y) {
  int sum = 0;
  for(int i=0;i<4;i++) {
    int new_x = x + dir[i][0];
    int new_y = y + dir[i][1];
    if(scope_check(new_x, new_y) && map[new_x][new_y] == 'X') {
      sum++;
    }
  }
  return sum <= 1 ? true : false;
}

int main() {
  scanf("%d %d", &r, &c);
  for(int i=0;i<r;i++) {
    string str;
    cin >> str;
    map.push_back(str);
  }
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(map[i][j] == 'X' && check_dir(i, j)) {
        vt.push_back(make_pair(i, j));
      }
    }
  }
  for(auto x: vt) {
    map[x.first][x.second] = '.';
  }

  int begin_col = 100, end_col = -1, begin_row = 100, end_row = -1;
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(map[i][j] == 'X') {
        if(begin_col > j) {
          begin_col = j;
        }
        if(begin_row > i) {
          begin_row = i;
        }
        if(end_col < j) {
          end_col = j;
        }
        if(end_row < i) {
          end_row = i;
        }
      }
    }
  }
  for(int i=begin_row;i<=end_row;i++) {
    string temp = "";
    for(int j=begin_col;j<=end_col;j++) {
      temp += map[i][j];
    }
    new_map.push_back(temp);
  }

  for(int i=0;i<new_map.size();i++) {
    cout << new_map[i] << endl;
  }
}