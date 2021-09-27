#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  while(true) {
    vector<int> s;
    vector<int> temp;
    int k;
    scanf("%d", &k);
    if(k == 0) break;
    for(int i=0;i<k;i++) {
      int n;
      scanf("%d", &n);
      s.push_back(n);
    }
    for(int i=0;i<6;i++) {
      temp.push_back(1);
    }
    for(int i=0;i<k-6;i++) {
      temp.push_back(0);
    }
    do {
      for(int i=0;i<s.size();++i) {
        if(temp[i] == 1) printf("%d ", s[i]);
      }
      printf("\n");
    } while(prev_permutation(temp.begin(), temp.end()));
    printf("\n");
  }
}