#include <cstdio>

const int MAXN = 1e6 + 1;
const int MOD = 1e9;

int main() {
    int N, dp[MAXN] = {1};
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        dp[i++] = dp[i - 1];
        dp[i] = (dp[i - 1] + dp[i >> 1]) % MOD; 
    }
    printf("%d\n", dp[N]);
    return 0;
}
