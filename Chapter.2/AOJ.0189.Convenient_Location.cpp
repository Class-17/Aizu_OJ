#include <cstdio>
#include <algorithm>

using namespace std;

const int maxv = 10;
const int inf = 1e4;

void floyd(int d[][maxv], int n) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);    
}

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        int g[maxv][maxv];
        for (int i = 0; i < maxv; ++i)
            for (int j = 0; j < maxv; ++j)
                g[i][j] = inf;
        for (int i = 0; i < maxv; ++i)
            g[i][i] = 0;
        int v = 0;
        for (int i = 0; i < n; ++i) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            g[a][b] = g[b][a] = w;
            v = max(max(a, b) + 1, v);
        }
        floyd(g, v);
        int pos = -1, sum = inf * maxv * maxv;
        for (int i = 0; i < v; ++i) {
            int curr = 0;
            for (int j = 0; j < v; ++j)
                curr += g[i][j];
            if (curr < sum) {
                sum = curr;
                pos = i;
            }
        }
        printf("%d %d\n", pos, sum);
    }
    return 0;
}