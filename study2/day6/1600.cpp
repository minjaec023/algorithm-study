#include <queue>
#include <map>
#include <iostream>

using namespace std;
int k;
int w, h;
int horse_move[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, -1}, {2, 1}};
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int m[201][201];
vector<int> answer;
int horse_cnt;
bool visited[200][200][31];

bool check_scope(int x, int y) {
    return x>=0 && x < h && y>=0 && y < w;
}


int main() {
    scanf("%d", &k);
    scanf("%d %d", &w, &h);

    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            scanf("%d", &m[i][j]);
        }
    }
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    visited[0][0][0] = true;

    while(q.empty() == 0) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second.first;
        int num = q.front().second.second;
        q.pop();
        if(x==h-1 && y==w-1) {
            answer.push_back(cnt);
            break;
        }
        if(num < k) {
            for(int i=0;i<8;i++) {
                int nx = x + horse_move[i][0];
                int ny = y + horse_move[i][1];
                if(check_scope(nx, ny) && m[nx][ny] != 1 && !visited[nx][ny][num+1]) {
                    visited[nx][ny][num+1] = true;
                    q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, num+1)));
                }
            }
        }
        for(int i=0;i<4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(check_scope(nx, ny) && m[nx][ny] !=1 && !visited[nx][ny][num]){
                visited[nx][ny][num] = true;
                q.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, num)));
            }
        }
    }
    if(answer.empty()) cout << -1 << endl;
    else cout << answer[0] << endl;
}