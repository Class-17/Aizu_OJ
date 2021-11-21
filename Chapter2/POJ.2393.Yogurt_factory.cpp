#include <cstdio>
#include <algorithm>
#define MAXN 10000

int main() {
    int N, S;
    scanf("%d %d", &N, &S);
    long long c[MAXN], y[MAXN];
    long long cost = 5000, res = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld", c + i, y + i);
        cost = std::min(cost + S, c[i]);
        res += cost * y[i];
    }
    printf("%lld\n", res);
    return 0;
}