#include <iostream>
#include <vector>
#include <map>
using namespace std;

int r, c, n;
vector<string> vec;
map<pair<int, int>, int> m;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void print_vec () {
  for(auto x: vec) {
    cout << x << endl;
  }
}

void update_map () {
  vector<pair<int, int> > temp;
  for(auto x: m) {
    if(x.second > 0) {
      temp.push_back(make_pair(x.first.first, x.first.second));
    }
  }
  for(auto x: temp) {
    m[make_pair(x.first, x.second)]--;
  }
}

bool check_scope (int i, int j) {
  return i >= 0 && i < r && j >= 0 && j < c;
}

void full_bomb () {
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(vec[i][j] == '.') {
        vec[i][j] = 'O';
        m[make_pair(i, j)] = 3;
      }
    }
  }
}

void burst () {
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(m[make_pair(i, j)] == 0) {
        vec[i][j] = '.';
        for(int k=0;k<4;k++) {
          int new_i = i + dir[k][0];
          int new_j = j + dir[k][1];
          if(check_scope(new_i, new_j)) {
            vec[new_i][new_j] = '.';
          }
        }
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &r, &c, &n);
  for(int i=0;i<r;i++) {
    string temp;
    cin >> temp;
    vec.push_back(temp);
  }
  
  for(int i=0;i<r;i++) {
    for(int j=0;j<c;j++) {
      if(vec[i][j] == 'O') {
        m[make_pair(i, j)] = 3;
      }
      else m[make_pair(i, j)] = -1;
    }
  }

  for(int i=1;i<=n;i++) {
    update_map();
    if(i % 2 == 1) burst();
    else full_bomb();
  }

  print_vec();

}