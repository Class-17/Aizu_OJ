#include <cstdio>
#include <cstring>

const int maxn = 5, maxm = 6, inf = maxn * maxm;
const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int mat[maxn], flip[maxn], res[maxn];

int f(int r, int c) {
    int x = (mat[r] >> c & 1) ^ (flip[r] >> c & 1);
    for (int i = 0; i < 4; ++i) {
        int rr = r + dirs[i][0], cc = c + dirs[i][1];
        if (rr >= 0 && rr < maxn && cc >= 0 && cc < maxm)
            x ^= flip[rr] >> cc & 1;
    }
    return x;
}

int count() {
    for (int r = 1; r < maxn; ++r)
        for (int c = 0; c < maxm; ++c)
            flip[r] |= f(r - 1, c) << c;
    for (int c = 0; c < maxm; ++c)
       if (f(maxn - 1, c)) return inf;
    int cnt = 0;
    for (int r = 0; r < maxn; ++r)
        cnt += __builtin_popcount(flip[r]);
    return cnt;
}

void solve() {
    int moves = inf;
    for (int i = 0; i < (1 << maxm); ++i) {
        memset(flip, 0, sizeof flip);
        for (int j = 0; j < maxm; ++j)
            flip[0] |= i & 1 << j;
        int curr = count();
        if (curr < moves) {
            memcpy(res, flip, sizeof flip);
            moves = curr;
        }
    }
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < maxm; ++j)
            printf("%d%c", (res[i] >> j & 1), (j + 1 < maxm ? ' ' : '\n'));
}

int main() {
    int __;
    scanf("%d", &__);
    for (int _ = 1; _ <= __; ++_) {
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < maxn; ++i)
            for (int j = 0; j < maxm; ++j) {
                int x; scanf("%d", &x);
                mat[i] |= x << j;
            }
        printf("PUZZLE #%d\n", _);
        solve();
    }
    return 0;
}