#include <cstdio>

const int MAXN = 1e5;

int find(int ds[], int x) {
    if (ds[x] == x) return x;
    return find(ds, ds[x]);
}

int main() {
    int N, Q;
    while (scanf("%d %d", &N, &Q)) {
        if (N == 0 && Q == 0) break;
        int ds[MAXN + 1] = {1, 1};
        for (int i = 2; i <= N; ++i)
            scanf("%d\n", &ds[i]);
        long long res = 0;
        for (int i = 0; i < Q; ++i) {
            char op; int v;
            scanf("%c %d\n", &op, &v);
            if (op == 'M') ds[v] = v;
            else  res += find(ds, v);
        }
        printf("%lld\n", res);
    }
    return 0;
}