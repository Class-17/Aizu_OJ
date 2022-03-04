#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct edge {
    int s, e, t;
};

const int maxv = 500;
const int maxe = 2700;
const int inf = 1e8;

bool bellman_ford(edge es[], int v, int e) {
    int d[maxv] = {0};
    for (int i = 0; i < v; ++i)
        for (int j = 0; j < e; ++j)
            if (d[es[j].s] + es[j].t < d[es[j].e]) {
                d[es[j].e] = d[es[j].s] + es[j].t;
                if (i == v - 1) return true;
            }
    return false;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        int n, m, w;
        scanf("%d %d %d", &n, &m, &w);
        edge es[maxe * 2];
        for (int i = 0; i < m + w; ++i) {
            int s, e, t;
            scanf("%d %d %d", &s, &e, &t);
            if (i >= m) t *= -1;
            es[i].s = es[i + m + w].e = s - 1;
            es[i].e = es[i + m + w].s = e - 1;
            es[i].t = es[i + m + w].t = t;
        }
        printf("%s\n", (bellman_ford(es, n, m * 2 + w) ? "YES" : "NO"));
    }
    return 0;
}