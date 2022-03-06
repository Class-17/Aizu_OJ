#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int n, k, t;

pair<int, int> arr[maxn + 1];

void solve() {
    int lo = 0, hi = 0, sum = 2e9 + 1;
    int i = 0, j = 1;
    while (i < j && j <= n) {
        int curr = arr[j].first - arr[i].first;
        if (abs(curr - t) < abs(sum - t)) {
            sum = curr;
            lo = arr[i].second;
            hi = arr[j].second;
        }
        if (curr == t) break;
        else if (curr > t) {
            ++i;
            if (i == j) ++j;
        }
        else ++j;
    }
    if (lo > hi) swap(lo, hi);
    printf("%d %d %d\n", sum, lo + 1, hi);
}

int main() {
    while (~scanf("%d %d", &n, &k) && n + k != 0) {
        arr[0].first = arr[0].second = 0;
        for (int i = 1; i <= n; ++i) {
            int num;
            scanf("%d", &num);
            arr[i].first = arr[i - 1].first + num;
            arr[i].second = i;
        }
        sort(arr, arr + n + 1);
        for (int i = 0; i < k; ++i) {
            scanf("%d", &t);
            solve();
        }
    }
    return 0;
}