#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int> > vt;
int r, c, k;
int answer = -1;

bool comp(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

void sort_row (int row_size, int col_size) {
  int max_size = 0;

  for(int i=0;i<row_size;i++) {
    vector<pair<int, int> > pr;
    map<int, int> m;
    for(int j=0;j<col_size;j++) {
      if(vt[i][j] != 0) m[vt[i][j]]++;
    }
    for(auto x: m) {
      pr.push_back(make_pair(x.first, x.second));
    }
    sort(pr.begin(), pr.end(), comp);
    vt[i].clear();
    for(auto x: pr) {
      vt[i].push_back(x.first);
      vt[i].push_back(x.second);
    }
    if(max_size < vt[i].size()) {
      max_size = vt[i].size();
    }
  }
  for(int i=0;i<row_size;i++) {
    int s = vt[i].size();
    if (s > 100) {
      for(int j=0;j<s-100;j++) {
        vt[i].pop_back();
      }
    } else {
      for(int j=0;j<max_size-s;j++) {
        vt[i].push_back(0);
      }
    }
  }


}

void sort_col (int row_size, int col_size) {
  int max_size = 0;
  vector<vector<int> > new_vecs;
  vector<vector<int> > result;
  for(int j=0;j<col_size;j++) {
    vector<pair<int, int> > pr;
    map<int, int> m;
    vector<int> new_vec;
    for(int i=0;i<row_size;i++) {
      if(vt[i][j] != 0) m[vt[i][j]]++;
    }
    for(auto x: m) {
      pr.push_back(make_pair(x.first, x.second));
    }
    sort(pr.begin(), pr.end(), comp);
    
    for(auto x: pr) {
      new_vec.push_back(x.first);
      new_vec.push_back(x.second);
    }

    if(max_size < new_vec.size()) {
      max_size = new_vec.size();
    }

    new_vecs.push_back(new_vec);
  }

  for(int i=0;i<new_vecs.size();i++) {
    int s = new_vecs[i].size();
    if (s > 100) {
      for(int j=0;j<s-100;j++) {
        new_vecs[i].pop_back();
      }
    } else {
      for(int j=0;j<max_size-s;j++) {
        new_vecs[i].push_back(0);
      }
    }
  }
  for(int i=0;i<new_vecs[0].size();i++) {
    int s = new_vecs.size();
    vector<int> temp;
    for(int j=0;j<s;j++) {
      temp.push_back(new_vecs[j][i]);
    }
    result.push_back(temp);
  }

  vt = result;
}

int main() {
  scanf("%d %d %d", &r, &c, &k);

  for(int i=0;i<3;i++) {
    vector<int> temp;
    for(int j=0;j<3;j++) {
      int n;
      scanf("%d", &n);
      temp.push_back(n);
    }
    vt.push_back(temp);
  }

  int time = 0;
  while(time <= 100) {
    int row_size = vt.size();
    int col_size = vt[0].size();
    
    if(r <= row_size && c <= col_size && vt[r-1][c-1] == k) {
      answer = time;
      break;
    }

    if(row_size >= col_size) {
      sort_row(row_size, col_size);
    } else {
      sort_col(row_size, col_size);
    }

    time++;
  }

  if(time == 101) answer = -1;
  printf("%d\n", answer);
}