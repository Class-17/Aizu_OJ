#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int c = 100000;

ll n, m;

ll check(ll x) {
    ll sum = 0;
    for (ll j = 1; j <= n; ++j) {
        int lo = 1, hi = n + 1;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2; 
            ll num = mid * mid + c * mid + j * j - c * j + mid * j;
            if (num <= x) lo = mid + 1;
            else          hi = mid;
        }
        sum += lo - 1;
    }
    return sum;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        scanf("%lld %lld", &n, &m);
        ll lo = 1 + c + 1 - c + 1;
        ll hi = n * n + c * n + 1 - c + n + 1;
        for (ll j = 2; j <= n; ++j) {
            lo = min(lo, 1 + c + j * j - c * j + j);
            hi = max(hi, n * n + c * n + j * j - c * j + n * j + 1);
        }
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(mid) < m) lo = mid + 1;
            else                hi = mid;
        }
        printf("%lld\n", lo);
    }
    return 0;
}