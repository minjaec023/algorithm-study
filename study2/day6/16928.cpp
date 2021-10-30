#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int board[101];
int dp[101];

int main() {
    scanf("%d %d", &n, &m);
    for(int i=0;i<n+m;i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        board[x] = y;
    }
    queue<int> q;
    q.push(1);
    dp[1] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=1;i<=6;i++) {
            int next = cur + i;
            if(next > 100) continue;

            if(board[next] != 0) {
                next = board[next];
            }
            if(dp[next] == 0) {
                dp[next] = dp[cur] + 1;
                q.push(next); 
            }
        }
    }
    cout << dp[100] << endl;
}