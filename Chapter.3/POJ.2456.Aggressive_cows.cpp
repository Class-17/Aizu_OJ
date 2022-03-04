#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int arr[maxn], n, c;

bool check(int x) {
    int cnt = 0, p = 0;
    while (p < n) {
        int np = p + 1;
        while (np < n && arr[np] - arr[p] < x) np++;
        p = np;
        cnt++;
    }
    return cnt >= c;
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; ++i)
        scanf("%d", arr + i);
    sort(arr, arr + n);
    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) lo = mid;
        else            hi = mid - 1;
    }
    printf("%d\n", lo);
    return 0;
}