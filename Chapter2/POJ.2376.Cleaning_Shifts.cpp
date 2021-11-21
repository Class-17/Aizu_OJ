#include <cstdio>
#include <utility>
#include <algorithm>

#define MAXN 25000

int main() {
    int N, T;
    scanf("%d %d", &N, &T);
    std::pair<int, int> itvs[MAXN];
    for (int i = 0; i < N; ++i)
        scanf("%d %d", &itvs[i].first, &itvs[i].second);
    std::sort(itvs, itvs + N);
    int cnt = 0, p = 0, time = 1;
    while (time <= T) {
        int nt = -1;
        while (p < N && itvs[p].first <= time)
            nt = std::max(itvs[p++].second, nt);
        if (nt == -1) break;
        time = nt + 1;
        cnt++;
    }
    printf("%d\n", time > T ? cnt : -1);
    return 0;
}