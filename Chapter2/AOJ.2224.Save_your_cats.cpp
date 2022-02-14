#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

const int maxv = 1e4;
const int maxe = 1e6;

struct edge {
    int a, b;
    double w;
    bool operator < (const edge &a) const {
        return w > a.w;
    }
} es[maxe];

int dsu[maxv + 1];

int find(int x) {
    if (dsu[x] < 0) return x;
    return dsu[x] = find(dsu[x]);
}

bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
    return true;
}

double kruskal(int n, int m) {
    sort(es, es + m);
    memset(dsu, -1, sizeof dsu);
    double cost = 0;
    for (int i = 0; i < m; ++i)
        if (unite(es[i].a, es[i].b))
            cost += es[i].w;
    return cost;
}

double d(pair<int, int> &a, pair<int ,int>& b) {
    double x = abs(a.first - b.first);
    double y = abs(a.second - b.second);
    return sqrt(x * x + y * y);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    pair<int, int> p[maxv + 1];
    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &p[i].first, &p[i].second);
    double sum = 0.0;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &es[i].a, &es[i].b);
        es[i].w = d(p[es[i].a], p[es[i].b]);
        sum += es[i].w;
    }
    printf("%.3f\n", sum - kruskal(n, m));
    return 0;
}