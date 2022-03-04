#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

const int maxv = 1000;
const int maxe = 1e4 * 2;
const int inf = 1e9;

struct edge {
    int a, b, w;
} es[maxe];

int n, ml, md;

int d[maxv + 1];

bool is_update(int &x, int y) {
    if (x <= y) return false;
    x = y;
    return true;
}

bool bellman_ford(int s, int dest) {
    fill(d, d + n + 1, inf);
    d[s] = 0;
    bool update = false;
    for (int i = 0; i <= n; ++i) {
        update = false;
        for (int i = 2; i < n; ++i)
            if (d[i] < inf && is_update(d[i - 1], d[i])) 
                update = true;
        for (int i = 0; i < ml + md; ++i)
            if (d[es[i].a] < inf && is_update(d[es[i].b], d[es[i].a] + es[i].w))
                update = true;
    }
    return update;
}


int main() {
    scanf("%d %d %d", &n, &ml, &md);
    for (int i = 0; i < ml; ++i)
        scanf("%d %d %d", &es[i].a, &es[i].b, &es[i].w);
    for (int i = ml; i < ml + md; ++i) {
        scanf("%d %d %d", &es[i].b, &es[i].a, &es[i].w);
        es[i].w *= -1;
    }
    int res;
    if (bellman_ford(1, n)) res = -1;
    else if (d[n] == inf)   res = -2;
    else                    res = d[n];
    printf("%d\n", res);
    return 0;
}