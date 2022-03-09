#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 35;

ll n, arr[maxn], 
pair<ll, int> ps[1 << maxn / 2];

void solve() {
    int ln = n / 2, rn = n - ln;
    for (int i = (1 << ln) - 1; i >= 0; --i) {
        ll sum = 0, cnt = __builtin_popcount(i);
        for (int j = 0; j < ln; ++j)
            if (i >> j & 1) sum += arr[j];
        ps[i] = {sum, cnt};
    }
    sort(ps, ps + (1 << ln));
    int m = 1;
    for (int i = 1; i < (1 << ln); ++i) {
        if (ps[i].first == ps[i - 1].first) continue;
        ps[m++] = ps[i];
    }
    ll min_sum = 1e17, res_cnt;
    for (int i = (1 << rn) - 1; i >= 0; --i) {
        ll sum = 0, cnt = __builtin_popcount(i);
        for (int j = 0; j < rn; ++j)
            if (i >> j & 1) sum += arr[j + ln];
        int t = -sum;
        int p = lower_bound(ps, ps + m, t) - ps;
        if (p > 0) --p;
        int q = p;
        for (int i = p + 1; i <= p + 2; ++i)
            if (abs(ps[i].first + sum) < abs(ps[q].first + sum))
                q = i;
        sum += ps[q].first;
        cnt += ps[q].second;
        if (
    } 
}

int main() {
    while (~scanf("%lld", &n) && n) {
        for (int i = 0; i < n; ++i)
            scanf("%lld", arr + i);
        solve();
    }
    return 0;
}
