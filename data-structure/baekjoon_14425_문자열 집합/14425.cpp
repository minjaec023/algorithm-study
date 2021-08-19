#include <iostream>
#include <set>
using namespace std;

int main() {
  int n, m;
  int cnt = 0;
  set<string> s;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    string temp;
    cin >> temp;
    s.insert(temp);
  }
  for(int i=0;i<m;i++) {
    string temp;
    cin >> temp;
    if(s.find(temp) != s.end()) cnt++;
  }
  cout << cnt << endl;
}