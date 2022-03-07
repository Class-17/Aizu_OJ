#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;
const int maxn = 1000;

int n, arr[maxn];
pair<int, int> ps[maxn * maxn];

int find_d(int len) {
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == j) continue;
            pair<int, int> x(arr[i] - arr[j], 0);
            pair<int, int> y(arr[i] - arr[j] + 1, 0);
            int lo = lower_bound(ps, ps + len, x) - ps;
            int hi = upper_bound(ps, ps + len, y) - ps;
            while (lo < hi) {
                int a = ps[lo].second / n, b = ps[lo].second % n;
                if (a != i && a != j && b != i && b != j)
                    return arr[i];
                ++lo;
            }
        }
    }
    return -1;
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        sort(arr, arr + n);
        int len = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                ps[len++] = {arr[i] + arr[j], i * n + j};
        sort(ps, ps + len);
        int d = find_d(len);
        if (d == -1)
            printf("no solution\n");
        else
            printf("%d\n", d);
    }
    return 0;
}