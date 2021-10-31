#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int r, c;
char forest[50][51];
pair<int, int> dest;
pair<int, int> src;
queue< pair<int, int> > water;
queue< pair<int, int> > moves;
int visit[50][50] = {0, };
int water_visit[50][50] = {0, };
int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};
int answer = 1;

bool check_rc(int param_r, int param_c){
  return 0 <= param_r && param_r < r && 0 <= param_c && param_c < c;
}

int bfs() {
  while(!moves.empty()) {
    int water_size = water.size();

    for(int i=0;i<water_size;i++){

      pair<int, int> cur_water = water.front();
      water.pop();
      for(int j=0;j<4;j++){
        int new_r, new_c;
        new_r = cur_water.first + dr[j];
        new_c = cur_water.second + dc[j];
        if(!check_rc(new_r, new_c)) continue;
        if(forest[new_r][new_c] == 'D' || forest[new_r][new_c] == 'X' || water_visit[new_r][new_c] != 0) continue;
        water_visit[new_r][new_c] = water_visit[cur_water.first][cur_water.second] + 1;
        water.push(make_pair(new_r, new_c));
      }
    }
    int moves_size = moves.size();
    for(int i=0;i<moves_size;i++){
      pair<int,int> cur_move = moves.front();
      moves.pop();
      for(int j=0;j<4;j++){
        int new_r, new_c;
        new_r = cur_move.first + dr[j];
        new_c = cur_move.second + dc[j];
        if(!check_rc(new_r, new_c)) continue;
        if(forest[new_r][new_c] == 'X' || water_visit[new_r][new_c] != 0 || visit[new_r][new_c]!=0) continue;
        if(forest[new_r][new_c] == 'D') {
          answer = visit[cur_move.first][cur_move.second] + 1;
          answer--;
          return answer;
        }
        else {
          visit[new_r][new_c] = visit[cur_move.first][cur_move.second] + 1;
          moves.push(make_pair(new_r, new_c));
        }
      }
    }
  
  }
  return 0;
}


int main(){
  scanf("%d %d", &r, &c);
  for (int i = 0 ; i < r ; i++) {
    scanf("%s", forest[i]);
  }
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(forest[i][j] == 'D') {
        dest = make_pair(i, j);
      } else if(forest[i][j] == 'S') {
        moves.push(make_pair(i, j));
        visit[i][j] = 1;
      } else if(forest[i][j] == '*') {
        water.push(make_pair(i, j));
        water_visit[i][j] = 1;
      }
    }
  }
  int ans = bfs();
  if(ans == 0) printf("KAKTUS\n");
  else printf("%d\n", ans);
}