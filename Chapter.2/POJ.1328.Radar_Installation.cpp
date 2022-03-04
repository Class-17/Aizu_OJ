#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;

#define MAXN 1000
#define PDD pair<double, double>

PDD itvs[MAXN];

int N, D;

int solve() {
    for (int i = 0; i < N; ++i) {
        double x = itvs[i].first, y = itvs[i].second;
        if (y > D) return -1;
        itvs[i].second = x - sqrt(D * D - y * y);
        itvs[i].first = x + sqrt(D * D - y * y);
    }
    sort(itvs, itvs + N);
    int cnt = 1;
    double t = itvs[0].first;
    for (int i = 1; i < N; ++i)
        if (itvs[i].second > t) {
            cnt++;
            t = itvs[i].first;
        }
    return cnt;
}

int main() {
    int _ = 1;
    while (scanf("%d %d", &N, &D)) {
        if (N == 0 && D == 0) break;
        for (int i = 0; i < N; ++i)
            scanf("%lf %lf", &itvs[i].first, &itvs[i].second);
        printf("Case %d: %d\n", _++, solve());
    }
    return 0;
}