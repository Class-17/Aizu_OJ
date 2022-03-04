#include <cstdio>
#include <cmath>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ll x, y;
    while (scanf("%lld %lld", &x, &y) != EOF) {
        y /= x;
        ll a = sqrt(y);
        while (a >= 0 && (y % a || gcd(a, y / a) != 1)) a--;
        printf("%lld %lld\n", a * x, y / a * x);
    }   
    return 0; 
}