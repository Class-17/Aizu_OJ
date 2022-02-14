#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxv = 1e3;
const int maxe = 2e4;

struct edge {
    int a, b, w;
    bool operator < (const edge &x) const {
        return w > x.w;
    }
} es[maxe];

int dsu[maxv + 1];

int find(int x) {
    if (dsu[x] < 0) return x;
    return dsu[x] = find(dsu[x]);
}

int unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    return true;
}

int kruskal(int n, int m) {
    sort(es, es + m);
    memset(dsu, -1, sizeof dsu);
    int cost = 0;
    for (int i = 0; i < m; ++i)
        if (unite(es[i].a, es[i].b))
            cost += es[i].w;
    for (int i = 2; i <= n; ++i)
        if (find(i) != find(1)) return -1;
    return cost;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d %d %d", &es[i].a, &es[i].b, &es[i].w);
    printf("%d\n", kruskal(n, m));
    return 0;
}