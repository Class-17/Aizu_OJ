#include <cstdio>
#include <utility>
#include <algorithm>
#include <functional>

#define fi first
#define se second

using namespace std;

const int MAXN = 20;

typedef pair<int, int> PII;

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    PII a[MAXN];
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &a[i].fi, &a[i].se);
    sort(a, a + N, greater<PII>());
    int res = 0;
    while (true) {
        int cnt[MAXN], t = C;
        for (int i = 0; i < N; ++i) {
            cnt[i] = min(a[i].se, t / a[i].fi);
            t -= cnt[i] * a[i].fi;
        }
        if (t > 0) {
            for (int i = N - 1; i >= 0; --i) {
                if (a[i].se > cnt[i]) {
                    t -= a[i].fi;
                    cnt[i]++;
                    break;
                }
            }
        }
        if (t > 0) break;
        int num = 1000000;
        for (int i = 0; i < N; ++i)
            if (cnt[i] > 0)
                num = min(num, a[i].se / cnt[i]);
        res += num;
        for (int i = 0; i < N; ++i)
            if (cnt[i] > 0)
                a[i].se -= num * cnt[i];
    }
    printf("%d\n", res);
    return 0;
}