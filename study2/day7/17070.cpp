#include <iostream>

using namespace std;

int n;
int home[16][16];
int cnt;

bool check_scope(int x, int y) {
    return x>=0 && x<n && y>=0 && y<n;
}

void recursive (int x, int y, int dir) {
    if(x == n-1 && y == n-1) {
        cnt++;
        return;
    }

    int nx, ny;

    // 가로
    if(dir == 0) {
        nx = x;
        ny = y + 1;
        if(check_scope(nx, ny) && home[nx][ny] != 1) {
            recursive(nx, ny, 0);
        }
        nx = x + 1;
        ny = y + 1;
        if(check_scope(nx, ny) && home[nx][ny] != 1 && home[nx-1][ny] != 1 && home[nx][ny-1] != 1) {
            recursive(nx, ny, 2);
        }
    }
    // 세로
    else if(dir == 1) {
        nx = x + 1;
        ny = y;
        if(check_scope(nx, ny) && home[nx][ny] != 1) {
            recursive(nx, ny, 1);
        }
        nx = x + 1;
        ny = y + 1;
        if(check_scope(nx, ny) && home[nx][ny] != 1 && home[nx-1][ny] != 1 && home[nx][ny-1] != 1) {
            recursive(nx, ny, 2);
        }
    }
    // 대각선
    else {
        nx = x;
        ny = y + 1;
        if(check_scope(nx, ny) && home[nx][ny] != 1) {
            recursive(nx, ny, 0);
        }
        nx = x + 1;
        ny = y;
        if(check_scope(nx, ny) && home[nx][ny] != 1) {
            recursive(nx, ny, 1);
        }
        nx = x + 1;
        ny = y + 1;
        if(check_scope(nx, ny) && home[nx][ny] != 1 && home[nx-1][ny] != 1 && home[nx][ny-1] != 1) {
            recursive(nx, ny, 2);
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &home[i][j]);
        }
    }
    recursive(0, 1, 0);
    printf("%d\n", cnt);
}