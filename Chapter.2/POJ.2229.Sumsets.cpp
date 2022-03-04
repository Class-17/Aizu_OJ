#include <cstdio>

const int MOD = 1e9;
const int MAXN = 1e6 + 1;

int main() {
    int N;
    scanf("%d", &N);
    int p[20] = {1}, cnt[MAXN] = {1};
    for (int i = 1; i < 20; ++i)
        p[i] = p[i - 1] * 2;
    for (int i = 0; i < 20; ++i)
        for (int j = p[i]; j <= N; ++j)
            cnt[j] = (cnt[j] + cnt[j - p[i]]) % MOD;
    printf("%d\n", cnt[N]);
    return 0;
}
