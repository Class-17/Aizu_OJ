#include <cstdio>
#include <algorithm>

#define MAXN 10
#define MAXM 10000

int main() {
    int N, M;
    while (scanf("%d %d", &N, &M)) {
        if (N == 0 && M == 0) break;
        int mat[MAXN][MAXM], columns[MAXM] = {0};
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                scanf("%d", &mat[i][j]);
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                columns[i] |= (mat[j][i] << j);
        int max_sum = 0;
        for (int state = (1 << N) - 1; state >= 0; --state) {
            int sum = 0;
            for (int i = 0; i < M; ++i) {
                int x = state ^ columns[i];
                int curr = 0;
                while (x) {
                    x &= (x - 1);
                    curr++;
                }
                sum += std::max(curr, N - curr);
            }
            max_sum = std::max(sum, max_sum);
        }
        printf("%d\n", max_sum);
    }
    return 0;
}