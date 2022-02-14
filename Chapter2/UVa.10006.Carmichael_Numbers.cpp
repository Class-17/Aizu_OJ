#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;

const int maxn = 65000;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

bitset<maxn + 1> st;

void sieve() {
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
    }
}

bool check(int n) {
    if (!st[n]) return false;
    for (int i = 2; i < n; ++i)
        if (mod_pow(i, n, n) != i) return false;
    return true;
}

int main() {
    int n;
    sieve();
    while (scanf("%d", &n) != EOF && n != 0) {
        if (check(n))
            printf("The number %d is a Carmichael number.\n", n);
        else
            printf("%d is normal.\n", n);
    }
    return 0;
}