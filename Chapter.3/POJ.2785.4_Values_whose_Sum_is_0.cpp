#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 4000;

int n, a[maxn], b[maxn], c[maxn], d[maxn];
int ab[maxn * maxn];

ll count() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
           ab[i * n + j] = a[i] + b[j];
    sort(ab, ab + n * n);
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int t = -(c[i] + d[j]);
            cnt += upper_bound(ab, ab + n * n, t) - lower_bound(ab, ab + n * n, t);
        }
    return cnt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d%d%d", a + i, b + i, c + i, d + i);
    printf("%lld\n", count());
    return 0;
}