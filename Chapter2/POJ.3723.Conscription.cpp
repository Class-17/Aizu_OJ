#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxr = 1e4 * 5;

struct edge {
    int x, y, d;
    bool operator < (const edge &e) const {
        return d < e.d;
    }
};

int find(int ds[], int x) {
    if (ds[x] < 0) return x;
    return ds[x] = find(ds, ds[x]);
}

bool unite(int ds[], int x, int y) {
    x = find(ds, x), y = find(ds, y);
    if (x == y) return false;
    if (ds[x] > ds[y]) swap(x, y);
    ds[x] += ds[y];
    ds[y] = x;
    return true;
}

int kruskal(edge collec[], int n) {
    sort(collec, collec + n);
    int ds[maxr];
    memset(ds, -1, sizeof ds);
    int sum = 0;
    for (int i = 0; i < n; ++i)
        if (unite(ds, collec[i].x, collec[i].y))
            sum += collec[i].d;
    return sum;
}


int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int n, m, r;
        scanf("%d %d %d", &n, &m, &r);
        edge collec[maxr];
        for (int i = 0; i < r; ++i) {
            int x, y, d;
            scanf("%d %d %d", &x, &y, &d);
            collec[i] = edge{x, y + n, -d};
        }
        printf("%d\n", (n + m) * 10000 + kruskal(collec, r));
    }
    return 0;
}