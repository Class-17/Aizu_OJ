#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 1e5;

int n, arr[maxn];

ll check(int x) {
    ll cnt = 0;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(arr + i + 1, arr + n, arr[i] + x) - arr;
        cnt += j - i - 1;
    }
    return cnt;
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        sort(arr, arr + n);
        ll t = (1LL * n * (n - 1) / 2 + 1) / 2;
        int lo = 0, hi = 1LL << 31 - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid) < t) lo = mid + 1;
            else                hi = mid;
        }
        printf("%d\n", lo);
    }
    return 0;
}