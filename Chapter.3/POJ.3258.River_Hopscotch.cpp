#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5e4 + 2;

int arr[maxn], l, n, m;

int check(int x) {
    int cnt = 0, p = 0;
    while (p < n) {
        int np = lower_bound(arr + p, arr + n, arr[p] + x) - arr;
        cnt += np - p - 1;
        p = np;
    }
    return cnt;
}

int main() {
    scanf("%d %d %d", &l, &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    arr[n] = 0;
    arr[n + 1] = l;
    n += 2;
    sort(arr, arr + n);
    int lo = 1, hi = l;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check(mid) <= m) lo = mid;
        else                 hi = mid - 1;
    }
    printf("%d\n", lo);
    return 0;
}