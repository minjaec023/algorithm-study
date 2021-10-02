#include <iostream>
#include <vector>
#include <map>
using namespace std;

char l, r;
string str;
map<char, pair<int, int> > m;
int answer;

int main() {
  scanf("%c %c", &l, &r);
  cin >> str;

  m['q'] = make_pair(0, 0); 
  m['w'] = make_pair(0, 1); 
  m['e'] = make_pair(0, 2); 
  m['r'] = make_pair(0, 3); 
  m['t'] = make_pair(0, 4); 
  m['y'] = make_pair(0, 5); 
  m['u'] = make_pair(0, 6); 
  m['i'] = make_pair(0, 7); 
  m['o'] = make_pair(0, 8); 
  m['p'] = make_pair(0, 9); 
  m['a'] = make_pair(1, 0); 
  m['s'] = make_pair(1, 1); 
  m['d'] = make_pair(1, 2);
  m['f'] = make_pair(1, 3); 
  m['g'] = make_pair(1, 4); 
  m['h'] = make_pair(1, 5); 
  m['j'] = make_pair(1, 6); 
  m['k'] = make_pair(1, 7); 
  m['l'] = make_pair(1, 8);
  m['z'] = make_pair(2, 0); 
  m['x'] = make_pair(2, 1); 
  m['c'] = make_pair(2, 2); 
  m['v'] = make_pair(2, 3); 
  m['b'] = make_pair(2, 4); 
  m['n'] = make_pair(2, 5); 
  m['m'] = make_pair(2, 6); 

  for(int i=0;i<str.size();i++) {
    answer++;
    if(str[i] == 'q' || str[i] == 'w' || str[i] == 'e' || str[i] == 'r' || str[i] == 't' || str[i] == 'a' || str[i] == 's' || str[i] == 'd' || str[i] == 'f' || str[i] == 'g' || str[i] == 'z' || str[i] == 'x' || str[i] == 'c' || str[i] == 'v') {
      answer += abs(m[l].first - m[str[i]].first) + abs(m[l].second - m[str[i]].second);
      l = str[i];
    }
    else {
      answer += abs(m[r].first - m[str[i]].first) + abs(m[r].second - m[str[i]].second);
      r = str[i];
    }
  }
  cout << answer << endl;

}