#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 350;

int main() {
    int N, a[MAXN][MAXN] = {0};
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            scanf("%d", &a[i][j]);
    for (int i = N - 2; i >= 0; --i)
        for (int j = 0; j <= i; ++j)
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
    printf("%d\n", a[0][0]);
    return 0;
}
