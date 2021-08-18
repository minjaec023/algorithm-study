#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, num;
  vector<pair<int, int> > balloons;
  scanf("%d", &n);
  
  for(int i=0;i<n;i++) {
    scanf("%d", &num);
    balloons.push_back(make_pair(num, i+1));
  }
  int index = 0;
  
  while(true) {
    printf("%d ", balloons[index].second);
    int value = balloons[index].first;

    balloons.erase(balloons.begin()+index);
    if(balloons.empty()) break;

    int len = balloons.size();
    
    index += value;
    
    if(value < 0) {
      if(index < 0) while(index<0) index += len;
    }
    else index = (index-1)%len;
  }

  return 0;
}