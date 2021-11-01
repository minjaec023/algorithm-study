#include <iostream>
#include <queue>
#include <map>

using namespace std;


int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
map<string, bool> visit;

bool check_scope(int x, int y) {
    return x>=0 && x < 3 && y>=0 && y<3;
}

int main() {
    string dest = "123456780";
    string str = "";
    int answer = -1;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++){
            char c;
            cin >> c;
            str += c;
        }
    }   
    queue<pair<string, char> > q;
    q.push(make_pair(str, 0));
    visit[str] = true;

    while(!q.empty()) {
        string cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cur == dest && (answer == -1  || answer > cnt)) {
            answer = cnt;
            continue;
        }

        int index = cur.find('0');
        int x = index/3;
        int y = index%3;
        for(int i=0;i<4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            string temp = cur;
            if(check_scope(nx, ny)) {
                swap(temp[x*3+y], temp[nx*3+ny]);
                if(!visit[temp]) {
                    visit[temp] = true;
                    q.push(make_pair(temp, cnt+1));
                }
            }
        }
    }
    cout << answer << endl;
}