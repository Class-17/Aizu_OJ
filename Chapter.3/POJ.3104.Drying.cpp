#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int arr[maxn], n, k;

bool check(int x) {
    long long cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += ceil(max(arr[i] - x, 0) * 1.0 / (k - 1));
    return cnt <= x;
}

signed main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    scanf("%d", &k);
    int max_val = 0;
    for (int i = 0; i < n; ++i)
        max_val = max(max_val, arr[i]);
    int lo = 0, hi = max_val;
    if (k > 1) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (!check(mid)) lo = mid + 1;
            else             hi = mid;
        }
    }
    printf("%d\n", hi);
    return 0;
}