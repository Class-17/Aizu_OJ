#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 5e4;

int w[maxn], s[maxn], idx[maxn], n;

bool comp(const int &a, const int &b) {
    return max(w[a] - s[b], -s[a]) < max(w[b] - s[a], -s[b]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", w + i, s + i);
    for (int i = 0; i < n; ++i)
        idx[i] = i;
    sort(idx, idx + n, comp);
    int res = -1e9, prew = 0;
    for (int i = 0; i < n; ++i) {
        res = max(prew - s[idx[i]], res);
        prew += w[idx[i]];
    }
    printf("%d\n", res);
    return 0;
}