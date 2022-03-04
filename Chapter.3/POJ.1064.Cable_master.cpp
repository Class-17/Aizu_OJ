#include <cstdio>
#include <vector>
#include <cmath>    

using namespace std;

int check(vector<double> &cables, double x) {
    int cnt = 0;
    for (int i = 0; i < cables.size(); ++i)
        cnt += cables[i] / x;
    return cnt;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<double> cables(n);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &cables[i]);
    double lo = 0.0, hi = 100000.0;
    for (int i = 0; i < 100; ++i) {
        double mid = lo + (hi - lo) / 2;
        if (check(cables, mid) >= k) lo = mid;
        else                         hi = mid;
    }
    printf("%.2f\n", floor(lo * 100) / 100);
    return 0;
}