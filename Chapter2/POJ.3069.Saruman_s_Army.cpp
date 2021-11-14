#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 1000

int main() {
    int R, N, a[MAXN];
    while (scanf("%d %d", &R, &N)) {
        if (R == -1 && N == -1) break;
        for (int i = 0; i < N; ++i)
            scanf("%d", &a[i]);
        sort(a, a + N);
        int p = 0, cnt = 0;
        while (p < N) {
            int mid = upper_bound(a + p, a + N, a[p] + R) - a - 1;
            int right = upper_bound(a + mid, a + N, a[mid] + R) - a;
            p = right;
            cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
