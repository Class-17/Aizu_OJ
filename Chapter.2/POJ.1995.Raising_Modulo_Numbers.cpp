#include <cstdio>

typedef long long ll;

ll pow(ll a, ll p, ll mod) {
    ll res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int m, h;
        scanf("%d %d", &m, &h);
        ll res = 0;
        for (int i = 0; i < h; ++i) {
            int a, p;
            scanf("%d %d", &a, &p);
            res = (res + pow(a, p, m)) % m;
        }
        printf("%lld\n", res);
    }
    return 0;
}