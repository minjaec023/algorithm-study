#include <iostream>
using namespace std;

int t;

int main() {
    scanf("%d", &t);
    for(int i=0;i<t;i++) {
        int dp[10001] = {};
        int n, m;
        int coins[21];
        scanf("%d", &n);
        for(int j=1;j<=n;j++) {
            scanf("%d", &coins[j]);
        }
        scanf("%d", &m);

        dp[0] = 1;

        for(int j=1;j<=n;j++) {
            for(int k=coins[j];k<=m;k++) {
                dp[k] += dp[k-coins[j]];
            }
        }
        cout << dp[m] << endl;
    }
}