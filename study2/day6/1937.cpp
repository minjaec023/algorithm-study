#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int n, answer;
int forest[500][500];
int d[500][500];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool scope_check(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

int dfs(int x, int y) {
    if(d[x][y] != 0) return d[x][y];
    d[x][y] = 1;

    for(int i=0;i<4;i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(scope_check(nx, ny) && forest[x][y] < forest[nx][ny]) {
            d[x][y] = d[x][y] > dfs(nx, ny)+1 ? d[x][y] : dfs(nx, ny) + 1;
        }
    }

    return d[x][y];
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &forest[i][j]);
            d[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int temp = dfs(i, j);
            answer = answer > temp ? answer : temp;
        }
    }
    cout << answer << endl;
}

/*

1 2 3 4
8 7 6 5
12 11 10 9
16 15 14 13



*/