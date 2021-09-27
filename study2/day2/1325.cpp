#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> computers[10001];
bool check[10001];
vector<int> answers;
int cnt;
int max_val = -1;

void dfs(int node) {
  check[node] = true;
  int len = computers[node].size();

  for(int i=0;i<len;i++) {
    if(!check[computers[node][i]]) {
      cnt++;
      dfs(computers[node][i]);
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);

  for(int i=0;i<m;i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    computers[b].push_back(a);
  }

  for(int i=1;i<=n;i++) {
    cnt = 0;
    fill(check, check+n+1, false);
    dfs(i);
    if(cnt > max_val) {
      max_val = cnt;
      answers.clear();
      answers.push_back(i);
    }
    else if(cnt == max_val) {
      answers.push_back(i);
    }
  }

  sort(answers.begin(), answers.end());

  for(auto x: answers) {
    printf("%d ", x);
  }

  printf("\n");
}