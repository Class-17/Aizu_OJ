#include <cstdio>

typedef long long ll;

ll pow(ll a, ll p, ll mod) {
    ll res = 1;
    while (p > 0) {
        if (p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

bool f(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int main() {
    int p, a;
    while (scanf("%d %d", &p, &a) != EOF && p + a != 0) {
        printf("%s\n", (pow(a, p, p) == a && !f(p) ? "yes" : "no"));
    }
    return 0;
}