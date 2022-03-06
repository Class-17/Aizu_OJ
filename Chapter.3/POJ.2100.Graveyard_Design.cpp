#include <cstdio>

typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    int cnt = 0, l[int(1e5)], r[int(1e5)];
    for (ll i = 1, j = 1, sum = 0; i * i <= n; ++i) {
        while (j * j <= n && sum < n) {
            sum += j * j;
            ++j;
        }
        if (sum == n) {
            l[cnt] = i;
            r[cnt] = j - 1;
            ++cnt;
        }
        sum -= i * i;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d ", r[i] - l[i] + 1);
        for (int j = l[i]; j <= r[i]; ++j)
            printf("%d%c", j, (j < r[i] ? ' ' : '\n'));
    }
    return 0;
}