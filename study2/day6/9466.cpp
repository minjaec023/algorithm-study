#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#define MAX 100001
using namespace std;

int t, n;
int m[MAX];
bool visit[MAX];
bool done[MAX];
int cnt;

void dfs(int node) {
    visit[node] = true;
    int next = m[node];
    if(!visit[next]) dfs(next);
    else {
        if(!done[next]) {
            for(int i=next;i != node; i = m[i]) {
                cnt++;
            }
            cnt++;
        }
    }
    done[node] = true;
}

int main() {
    scanf("%d", &t);
    for(int i=0;i<t;i++) {
        scanf("%d", &n);
        memset(visit, false, sizeof(visit));
        memset(done, false, sizeof(done));
        cnt = 0;

        for(int j=0;j<n;j++) {
            int num;
            scanf("%d", &num);
            m[j+1] = num;
        }
 
        for(int j=0;j<n;j++) {
            if(!visit[j+1]) dfs(j+1);
        }
        printf("%d\n", n-cnt);
    }
}