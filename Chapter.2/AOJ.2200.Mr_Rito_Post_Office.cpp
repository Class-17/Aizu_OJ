#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxv = 200;
const int maxr = 1000;
const int inf = 0x3f3f3f3f;

void floyd(int d[][maxv], int n) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)) {
        if (n + m == 0) break;
        int dl[maxv][maxv], ds[maxv][maxv];
        memset(dl, 0x3f, sizeof dl);
        memset(ds, 0x3f, sizeof ds);
        for (int i = 0; i < m; ++i) {
            int x, y, l;
            char sl;
            scanf("%d %d %d %c\n", &x, &y, &l, &sl);
            if (sl == 'L')
                dl[x - 1][y - 1] = dl[y - 1][x - 1] = min(dl[x - 1][y - 1], l);
            else
                ds[x - 1][y - 1] = ds[y - 1][x - 1] = min(ds[x - 1][y - 1], l);
        }
        for (int i = 0; i < n; ++i)
            dl[i][i] = ds[i][i] = 0;
        floyd(dl, n);
        floyd(ds, n);
        int r;
        scanf("%d", &r);
        int seq[maxr + 1];
        for (int i = 1; i <= r; ++i) {
            scanf("%d", seq + i);
            seq[i]--;
        }
        int dp[maxr + 1][maxv];
        memset(dp, 0x3f, sizeof dp);
        for (int i = 0; i < n; ++i)
            dp[1][i] = ds[seq[1]][i] + dl[i][seq[1]];
        for (int k = 2; k <= r; ++k)
            for (int i = 0; i < n; ++i) {
                if (dl[i][seq[k]] >= inf) continue;
                for (int j = 0; j < n; ++j) {
                    if (dp[k - 1][j] >= inf) continue;
                    if (i != j && max(max(dl[seq[k - 1]][j], ds[j][i]), dl[i][seq[k]]) < inf)
                        dp[k][i] = min(dp[k - 1][j] + dl[seq[k - 1]][j] + ds[j][i] + dl[i][seq[k]], dp[k][i]);
                    else if (i == j && dl[seq[k - 1]][seq[k]] < inf)
                        dp[k][i] = min(dp[k - 1][j] + dl[seq[k - 1]][seq[k]], dp[k][i]);
                }
            }
        int min_time = inf;
        for (int i = 0; i < n; ++i)
            min_time = min(dp[r][i], min_time);
        printf("%d\n", min_time);
    }
    return 0;
}