#include <cstdio>

#define eps 1e-7

const double inf = 1e6;

int n;

double a;

double check(double x) {
    double i = a, j = x, k;
    for (int _ = 2; _ < n; ++_) {
        if (j < -eps) return -1;
        k = (j + 1) * 2 - i;
        i = j;
        j = k;
    }
    return k;
}

int main() {
    scanf("%d %lf", &n, &a);
    double lo = -inf, hi = inf;
    while (hi - lo > eps) {
        double mid = lo + (hi - lo) / 2;
        if (check(mid) < -eps) lo = mid;
        else                   hi = mid;
    }
    double res = check(hi);
    if (res < 0) res = 0;
    printf("%.2f\n", res);
    return 0;
}