#include <cstdio>

const int maxn = 1e5;

int arr[maxn], n, m;

int check(int x) {
    int cnt = 0, p = 0;
    while (p < n) {
        int curr = 0;
        if (arr[p] > x) return m + 1;
        while (p < n && curr + arr[p] <= x)
            curr += arr[p++];
        cnt++;
    }
    return cnt;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid) > m) lo = mid + 1;
        else                hi = mid;
    }
    printf("%d\n", lo);
    return 0;
}