#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int map[1000][1000];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool visited[1000][1000][32];

vector<int> answer;

bool scope_check(int x, int y) {
    return x>=0 && x<n && y>=0 && y < m;
}


int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%1d", &map[i][j]);
        }
    }
  
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int a = q.front().second.second;
      
        q.pop();
        if(x == n-1 && y == m-1) {
            answer.push_back(cnt);
            break;
        }

        if(a == 0) {
            for(int i=0;i<4;i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(scope_check(nx, ny) && map[nx][ny]==1 && !visited[nx][ny][a+1]) {
                    visited[nx][ny][a+1] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, a+1)));
                }
            }
        }
        for(int i=0;i<4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(scope_check(nx, ny) && map[nx][ny]==0 && !visited[nx][ny][a]) {
                visited[nx][ny][a] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, a)));
            }
        }
    }
    if(answer.empty()) cout << -1 << endl;
    else cout << answer[0] + 1 << endl;
}