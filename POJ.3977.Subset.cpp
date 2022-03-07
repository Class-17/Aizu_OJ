#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int maxn = 35;

ll n, arr[maxn], min_val = 1e17, res_cnt;;
pll ps[1 << (maxn / 2)], bs[1 << ((maxn + 1) / 2)];

ll f(ll x) {
    return x > 0 ? x : -x;
}

bool compp(const pll &a, const pll &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool compb(const pll &a, const pll &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void enum_sol(int len, int d, pll *sum, bool(*comp)(const pll &, const pll &)) {
    for (int i = (1 << len) - 1; i > 0; --i) {
        ll curr = 0, cnt = __builtin_popcount(i);
        for (int j = 0; j < len; ++j)
            if (i >> j & 1) curr += arr[j + d];
        sum[i] = {curr, cnt};
        if (!cnt || f(curr) > min_val) continue;
        min_val = f(curr);
        res_cnt = cnt;
    }
    sort(sum + 1, sum + (1 << len), comp);
}

int main() {
    while (~scanf("%lld", &n) && n) {
        for (int i = 0; i < n; ++i)
            scanf("%lld", arr + i);
        min_val = 1e17;
        int ln = n / 2, rn = (n + 1) / 2;
        enum_sol(ln, 0, ps, compp);
        enum_sol(rn, ln, bs, compb);
        int i = 1, j = 1;
        while (i < (1 << ln) && j < (1 << rn)) {
            ll sum = ps[i].first + bs[j].first;
            ll cnt = ps[i].second + bs[j].second;
            if (f(sum) < min_val || f(sum) == min_val && cnt < res_cnt) {
                min_val = f(sum);
                res_cnt = cnt;
            }
            if (sum <= 0) ++i;
            if (sum >= 0) ++j;
        }
        printf("%lld %lld\n", min_val, res_cnt);
    }
    return 0;
}