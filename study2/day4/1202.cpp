#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct comp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  }
};

int n, k;
long long answer;
multiset<int> ms;
priority_queue<pair<int, int>, vector<pair<int, int> >, comp> pq1;

int main() {
  scanf("%d %d", &n, &k);
  for(int i=0;i<n;i++) {
    int m, v;
    scanf("%d %d", &m, &v);
    pq1.push(make_pair(m, v));
  }
  for(int i=0;i<k;i++) {
    int c;
    scanf("%d", &c);
    ms.insert(c);
  }
  int cnt = 0;
  while(!pq1.empty()) {
    int weight = pq1.top().first;
    int value = pq1.top().second;
    pq1.pop();
    auto it = ms.lower_bound(weight);
    if(it != ms.end()) {
      answer += value;
      ms.erase(it);
    }
  }
  printf("%lld\n", answer);
}
