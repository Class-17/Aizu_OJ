#include <cstdio>
#include <algorithm>

#define ll long long

const int MAXN = 100000;

struct cow {
    ll t, d;
    bool operator < (const cow &c) const {
        return t * c.d < d * c.t;
    }
} cows[MAXN];

int main() {
    int N;
    scanf("%d", &N);
    ll sum = 0;
    for (int i = 0; i < N; ++i)
        scanf("%lld %lld", &cows[i].t, &cows[i].d);
    std::sort(cows, cows + N);
    ll res = 0, t = 0;
    for (int i = 0; i < N; ++i) {
        res += t * cows[i].d;
        t += cows[i].t * 2;
    }
    printf("%lld\n", res);
    return 0;
}