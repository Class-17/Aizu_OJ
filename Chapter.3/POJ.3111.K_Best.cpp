#include <cstdio>
#include <algorithm>
using namespace std;

#define eps 1e-7

const int maxn = 1e5;

int n, k, v[maxn], w[maxn], idx[maxn];

double x;

bool comp(const int &a, const int &b) {
    return v[a] * 1.0 - x * w[a] > v[b] * 1.0 - x * w[b];
}

bool check(double curr) {
    x = curr;
    sort(idx, idx + n, comp);
    double sum = 0;
    for (int i = 0; i < k; ++i)
        sum += v[idx[i]] * 1.0 - x * w[idx[i]];
    return sum > -eps;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", v + i, w + i);
    for (int i = 0; i < n; ++i)
        idx[i] = i;
    double lo = 0, hi = 1e7;
    while (hi - lo > eps) {
        double mid = lo + (hi - lo) / 2;;
        if (check(mid)) lo = mid;
        else            hi = mid;
    }
    for (int i = 0; i < k; ++i)
        printf("%d%c", idx[i] + 1, (i + 1 < k ? ' ' : '\n'));
    return 0;
}