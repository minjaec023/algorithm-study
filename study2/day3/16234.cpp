#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;

int n, l, r;
int m[51][51]; 
int cnt;
map<pair<int, int>, int> visited;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<set<pair<int, int> > > lists;

bool scope_check(int x, int y) {
  return x>=0 && x<n && y>=0 && y<n;
}

bool connect_check(int curx, int cury, int next_x, int next_y) {
  int diff = abs(m[curx][cury]-m[next_x][next_y]);
  return diff >= l && diff <= r;
}

void bfs(int x, int y) {
  set<pair<int, int> > list;
  queue<pair<int, int> > q;
  bool check = false;
  q.push(make_pair(x, y));
  visited[make_pair(x, y)] = 1;
  list.insert(make_pair(x, y));
  while(!q.empty()) {
    int curx = q.front().first;
    int cury = q.front().second;
    q.pop();
    for(int i=0;i<4;i++) {
      int next_x = curx + dir[i][0];
      int next_y = cury + dir[i][1];
      if(visited[make_pair(next_x, next_y)]==0 && scope_check(next_x, next_y) && connect_check(curx, cury, next_x, next_y)) {
        check = true;
        visited[make_pair(next_x, next_y)] = 1;
        list.insert(make_pair(next_x, next_y));
        q.push(make_pair(next_x, next_y));
      }
    }
  }
  if(check) lists.push_back(list);
}

void print_map () {
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cout << m[i][j] << ' ';
    }
    cout << endl;
  }
}


int main() {
  scanf("%d %d %d", &n, &l, &r);
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      scanf("%d", &m[i][j]);
    }
  }
  

  while(true) {
    lists.clear();
    visited.clear();

    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(visited[make_pair(i, j)] == 0) bfs(i, j);
      }
    }
    if(lists.empty()) break;

    for(auto x: lists) {
      int len = x.size();
      int sum = 0;
      for(auto y: x) {
        sum += m[y.first][y.second];
      }
      int new_per = sum / len;
      for(auto y: x) {
        m[y.first][y.second] = new_per;
      }
    }
    cnt++;
  }

  cout << cnt << endl;
}