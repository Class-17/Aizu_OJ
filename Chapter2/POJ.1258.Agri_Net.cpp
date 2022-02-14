#include <cstdio>
#include <cstring>
#include <bitset>
#include <algorithm>
using namespace std;

const int maxn = 100;

int prime(int n, int g[][maxn]) {
    int d[maxn];
    memset(d, 0x3f, sizeof d);
    d[0] = 0;
    bitset<maxn> memo;
    int cost = 0;
    while (true) {
        int v = -1;
        for (int i = 0; i < n; ++i)
            if (!memo[i] && (v == -1 || d[i] < d[v])) v = i;
        if (v == -1) break;
        memo[v] = true;
        cost += d[v];
        for (int i = 0; i < n; ++i)
            d[i] = min(g[v][i], d[i]);
    }
    return cost;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int g[maxn][maxn];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                scanf("%d", &g[i][j]);
        printf("%d\n", prime(n, g));
    }
    return 0;
}