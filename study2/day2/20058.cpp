#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;

int n, q;
int map_size;
vector<int> magic;
int map[100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int total_ice;
bool check[100][100];
int max_val = -1;

bool scope_check(int x, int y) {
  return x >= 0 && x < map_size && y >= 0 && y < map_size;
}


vector<vector<int> > move(vector<vector <int> > square, int n) {
  vector<vector<int> > new_square;
  for(int i=0;i<n;i++) {
    vector<int> temp;
    for(int j=0;j<n;j++){
      temp.push_back(0);
    }
    new_square.push_back(temp);
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      new_square[j][n-i-1] = square[i][j];
    }
  }
  return new_square;
}

void rotate(int n) {
  int square_size = pow(2, n);

  // 쪼개기
  for(int i=0;i<map_size;i+=square_size) {
    for(int j=0;j<map_size;j+=square_size) {
      // 부분사각형 만들기
      vector<vector<int> > square;
      for(int k=i;k<i+square_size;k++) {
        vector<int> temp;
        for(int l=j;l<j+square_size;l++) {
          temp.push_back(map[k][l]);
        }
        square.push_back(temp);
      }
      // 회전
      vector<vector<int> > new_square = move(square, square_size);

      // 재배치
      for(int k=i;k<i+square_size;k++) {
        for(int l=j;l<j+square_size;l++) {
          map[k][l] = new_square[k-i][l-j];
        }
      }
    }
  }
}


void melt() {
  vector<pair<int, int> > temp;
  // 상하좌우 확인
  for(int i=0;i<map_size;i++) {
    for(int j=0;j<map_size;j++) {
      int ice = 0;
      for(int k=0;k<4;k++) {
        int x = i+dir[k][0];
        int y = j+dir[k][1];
        if(scope_check(x, y)) {
          if(map[x][y] > 0) ice++;
        }
      }
      if(ice < 3) temp.push_back(make_pair(i, j));
    }
  }

  for(auto x: temp) {
    map[x.first][x.second] -= 1;
  }
}

int bfs(int x, int y) {
  int sum = 0;
  queue<pair<int,int> > q;
  q.push(make_pair(x, y));
  check[x][y] = true;
  while(!q.empty()) {
    int curx = q.front().first;
    int cury = q.front().second;
    sum++;
    q.pop();
    for(int k=0;k<4;k++) {
      int next_x = curx+dir[k][0];
      int next_y = cury+dir[k][1];
      if(scope_check(next_x, next_y) && map[next_x][next_y] > 0 && !check[next_x][next_y]) {
        check[next_x][next_y] = true;
        q.push(make_pair(next_x, next_y));
      }
    }
  }
  return sum;
}

void find_max() {
  for(int i=0;i<map_size;i++) {
    for(int j=0;j<map_size;j++) {
      if(map[i][j] > 0 && !check[i][j]) {
        int sum = bfs(i, j);
        if(sum > max_val) max_val = sum;
      }
    }
  }
}

void print_map() {
  cout << endl;
  for(int i=0;i<map_size;i++) {
    for(int j=0;j<map_size;j++) {
      cout << map[i][j] <<' ';
    }
    cout << endl;
  }
}

int main() {
  scanf("%d %d", &n, &q);
  map_size = pow(2, n);
  for(int i=0;i<map_size;i++) {
    for(int j=0;j<map_size;j++) {
      scanf("%d", &map[i][j]);
    }
  }
  for(int i=0;i<q;i++) {
    int m;
    scanf("%d", &m);
    magic.push_back(m);
  }

  for(int i=0;i<map_size;i++) {
    for(int j=0;j<map_size;j++) {
      check[i][j] = false;
    }
  }
  for(auto x: magic) {
    rotate(x);
    melt();
  }

  for(int i=0;i<map_size;i++) {
    for(int j=0;j<map_size;j++) {
      if(map[i][j] > 0) total_ice+= map[i][j];
    }
  }

  find_max();
  if(max_val == -1) max_val = 0;
  cout << total_ice << endl;
  cout << max_val << endl;
}