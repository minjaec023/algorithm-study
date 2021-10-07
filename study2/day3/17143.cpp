#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r, c, m;
int answer;
vector<vector<int> > sharks;
map<pair<int, int>, vector<int> > grid;
bool check[10001];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; 

bool comp(int a, int b) {
  return sharks[a][4] > sharks[b][4];
}

bool scope_check(int x, int y) {
  return x>=0 && x<r && y>=0 && y<c;
}

void catch_shark(int c) {
  for(int i=0;i<r;i++) {
    if(!grid[make_pair(i, c)].empty()) {

      answer += sharks[grid[make_pair(i, c)][0]][4];
      check[grid[make_pair(i, c)][0]] = 0;
      grid[make_pair(i, c)].clear();
      break;
    }
  }
}

void move_shark(int index) {
  int conv_d;
  int d = sharks[index][3];
  int x = sharks[index][0];
  int y = sharks[index][1];
  if(d==0) conv_d = 1;
  else if(d==1) conv_d = 0;
  else if(d==2) conv_d = 3;
  else conv_d = 2;

  int s = sharks[index][2];

  int new_x, new_y;
  int new_d;
  // 아래
  if(d==1){
    int dif = s+x;
    int q = dif/(r-1);
    int m = dif%(r-1);
    // 방향 바뀜
    if(q%2!=0 && m != 0) {
      new_d = conv_d;
      new_x = r-1-m;
      new_y = y;
    }
    // 방향 안바뀜
    else if(q%2!=0 && m==0){
      new_d = d;
      new_x = r-1;
      new_y = y;
    }
    else {
      new_d = d;
      new_x = m;
      new_y = y;
    }
  } 
  // 위
  else if(d==0) {
    int dif = s+(r-x-1);
    int q = dif/(r-1);
    int m = dif%(r-1);
    // 방향 바뀜
    if(q%2!=0 && m != 0) {
      new_d = conv_d;
      new_x = m;
      new_y = y;
    }
    // 방향 안바뀜
    else if(q%2!=0 && m==0){
      new_d = d;
      new_x = 0;
      new_y = y;
    }
    else {
      new_d = d;
      new_x = r-1-m;
      new_y = y;
    }
  }
  // 오른
  else if(d==2) {
    int dif = s+y;
    int q = dif/(c-1);
    int m = dif%(c-1);
    // 방향 바뀜
    if(q%2!=0 && m != 0) {
      new_d = conv_d;
      new_x = x;
      new_y = c-1-m;
    }
    // 방향 안바뀜
    else if(q%2!=0 && m==0){
      new_d = d;
      new_x = x;
      new_y = c-1;
    }
    else {
      new_d = d;
      new_x = x;
      new_y = m;
    }
  }
  // 왼
  else {
    int dif = s+(c-y-1);
    int q = dif/(c-1);
    int m = dif%(c-1);
    // 방향 바뀜
    if(q%2!=0 && m != 0) {
      new_d = conv_d;
      new_x = x;
      new_y = m;
    }
    // 방향 안바뀜
    else if(q%2!=0 && m==0){
      new_d = d;
      new_x = x;
      new_y = 0;
    }
    else {
      new_d = d;
      new_x = x;
      new_y = c-1-m;
    }
  }
    sharks[index][0] = new_x;
    sharks[index][1] = new_y;
    sharks[index][3] = new_d;
}

void one_shark(int x, int y) {
  
  vector<int> shark_list = grid[make_pair(x, y)];
  if(shark_list.size() > 1) {
    vector<int> temp;
    sort(shark_list.begin(), shark_list.end(), comp);
    int max_size = sharks[shark_list[0]][4];
    for(auto x: shark_list) {
      if(sharks[x][4] != max_size) {
        check[x] = 0;
      }
    }
    temp.push_back(shark_list[0]);
    grid[make_pair(x, y)] = temp;
  }
}

void print_grid () {
  cout << endl;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++) {
      if(grid[make_pair(i, j)].empty()) {
        cout << '-' << ' ';
      }
      else cout << grid[make_pair(i, j)][0] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void update_grid() {
  grid.clear();

  for(int i=0;i<sharks.size();i++) {
    if(check[i] == 1) {
      grid[make_pair(sharks[i][0], sharks[i][1])].push_back(i);
    }
  }
}

int main() {
  scanf("%d %d %d", &r, &c, &m);
  for(int i=0;i<m;i++) {
    vector<int> temp;
    int xr, xc, s, d, z;
    scanf("%d %d %d %d %d", &xr, &xc, &s, &d, &z);
    xr -= 1;
    xc -= 1;
    temp.push_back(xr);
    temp.push_back(xc);
    temp.push_back(s);
    temp.push_back(d-1);
    temp.push_back(z);
    sharks.push_back(temp);
    grid[make_pair(xr, xc)].push_back(i);
    check[i] = 1;
  }

  for(int i=0;i<c;i++) {
    catch_shark(i);
    for(int j=0;j<sharks.size();j++) {
      move_shark(j);
    }
    update_grid();
    for(int j=0;j<r;j++) {
      for(int k=0;k<c;k++) {
        one_shark(j, k);
      }
    }
    update_grid();
  }
  printf("%d\n", answer);
}
/*
방향
0 1 2 3
위 아래 오른 왼

반대방향
1 0 3 2
아래 위 오른 왼

괄호 안은 속력
아래(1) 오른(1)
아래(1) 오른(2)

(1,1) 잡힙 -> 사이즈 1


*/