#include <cstdio>
#include <queue>
using namespace std;

#define MAXN 1000

const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

char mat[MAXN][MAXN + 1];

int H, W, N;

int bfs(int &r, int &c, char t) {
    queue<pair<int, int> > q;
    q.push(make_pair(r, c));
    bool memo[MAXN][MAXN] = {false};
    memo[r][c] = true;
    int dist = 0;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = p.first + dirs[i][0];
                int nc = p.second + dirs[i][1];
                if (nr < 0 || nr >= H || nc < 0 || nc >= W || 
                    mat[nr][nc] == 'X' || memo[nr][nc]) continue;
                if (mat[nr][nc] == t) {
                    r = nr, c = nc;
                    return dist + 1;
                }
                q.push(make_pair(nr, nc));
                memo[nr][nc] = true;
            }
        }
        dist++;
    }
    return -1;
}

void solve() {
    int r, c;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            if (mat[i][j] == 'S')
                r = i, c = j;
        }
    int step = 0;
    for (int i = 0; i < N; ++i) {
        step += bfs(r, c, i + 1 + '0');
    }
    printf("%d\n", step);
}

int main() {
    scanf("%d %d %d", &H, &W, &N);
    for (int i = 0; i < H; ++i)
        scanf("%s", mat[i]);
    solve();
    return 0;
}
