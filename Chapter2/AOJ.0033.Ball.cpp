#include <cstdio>

#define MAXN 10

int balls[MAXN], a[MAXN], b[MAXN];

bool check(int seq[], int n) {
    for (int i = 1; i < n; ++i)
        if (seq[i] < seq[i - 1]) return false;
    return true;
}

bool dfs(int p, int i, int j) {
    if (p == MAXN)
        return check(a, i) && check(b, j);
    a[i] = balls[p];
    if (dfs(p + 1, i + 1, j)) return true;
    b[j] = balls[p];
    if (dfs(p + 1, i, j + 1)) return true;
    return false;
}

int main() {
    int _;
    scanf("%d", &_);
    while (_--) {
        for (int i = 0; i < MAXN; ++i)
            scanf("%d", &balls[i]);
        printf("%s\n", dfs(0, 0, 0) ? "YES" : "NO");
    }
    return 0;
}