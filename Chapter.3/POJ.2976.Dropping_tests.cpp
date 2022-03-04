#include <cstdio>
#include <algorithm>
using namespace std;

#define eps 1e-7

const int maxn = 1000;

int n, k, a[maxn], b[maxn], idx[maxn];

double x;

bool comp(const int &i, const int &j) {
    return a[i] * 1.0 - x * b[i] > a[j] * 1.0 - x * b[j];
}

bool check(double curr) {
    x = curr;
    sort(idx, idx + n, comp);
    double sum = 0;
    for (int i = 0; i < n - k; ++i)
        sum += a[idx[i]] * 1.0 - x * b[idx[i]];
    return sum > -eps;
}

int main() {
    while (scanf("%d %d", &n, &k) != EOF && n + k != 0) {
        for (int i = 0; i < n; ++i)
            scanf("%d", a + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", b + i);
        for (int i = 0; i < n; ++i)
            idx[i] = i;
        double lo = 0, hi = 100;
        while (hi - lo > eps) {
            double mid = lo + (hi - lo) / 2;;
            if (check(mid / 100)) lo = mid;
            else                  hi = mid;
        }
        printf("%.0f\n", lo);
    }
    return 0;
}