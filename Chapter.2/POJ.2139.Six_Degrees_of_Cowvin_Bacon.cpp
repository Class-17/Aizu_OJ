#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 300;

const int inf = 1e5;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int g[maxn][maxn];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            g[i][j] = inf;
    for (int i = 0; i < m; ++i) {
        int num;
        scanf("%d", &num);
        vector<int> seq(num);
        for (int j = 0; j < num; ++j)
            scanf("%d", &seq[j]);
        for (int a = 0; a < num; ++a)
            for (int b = 0; b < num; ++b)
                g[seq[a] - 1][seq[b] - 1] = 1;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][k] + g[k][j], g[i][j]);
    int min_dist = inf;
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        for (int j = 0; j < n; ++j)
            if (j != i) curr += g[i][j];
        min_dist = min(curr, min_dist);
    }
    printf("%d\n", min_dist * 100 / (n - 1));
    return 0;
}