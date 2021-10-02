#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int cnt;
deque<pair<int, int> > con;
vector<int> conveyor;

bool check() {
  int sum = 0;
  for(auto x: con) {
    if(x.first == 0) sum++;
    if(sum >= k) {
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d %d", &n, &k);
  for(int i=0;i<n*2;i++) {
    int num;
    scanf("%d", &num);
    con.push_back(make_pair(num, 0));
    conveyor.push_back(num);
  }
  cnt = 1;
  while(true) {
    con.push_front(con.back());
    con.pop_back();

    if(con[n-1].second != 0) {
      con[n-1].second = 0;
    }

    for(int i=n-2;i>=0;i--) {
      if(con[i].second == 1 && con[i+1].second != 1 && con[i+1].first > 0) {
        con[i+1].second = 1;
        con[i+1].first -= 1;
        con[i].second = 0;
      }
    }

    if(con.front().first != 0 && con.front().second == 0) {
      con.front().second = 1;
      con.front().first -= 1;
    }
    if(con[n-1].second != 0) {
      con[n-1].second = 0;
    }
    if(check()) break;
    cnt++;
  }

  cout << cnt << endl;
}