#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1000;
const int dirs[][2] = {0, 1, 1, 0, 0, -1, -1, 0};

int w, h, n, x1[maxn], x2[maxn], y1[maxn], y2[maxn];
bool mat[maxn * 6][maxn * 6];

int compress(int *l, int *r, int len) {
    vector<int> p;
    for (int i = 0; i < n; ++i)
        for (int d = -1; d <= 1; ++d) {
            int pl = l[i] + d, pr = r[i] + d;
            if (0 <= pl && pl <= len) p.push_back(pl);
            if (0 <= pr && pr <= len) p.push_back(pr);
        }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    for (int i = 0; i < n; ++i) {
        l[i] = find(p.begin(), p.end(), l[i]) - p.begin();
        r[i] = find(p.begin(), p.end(), r[i]) - p.begin();
    }
    return p.size();
}

void dfs(int r, int c) {
    mat[r][c] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = r + dirs[i][0], ny = c + dirs[i][1];
        if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
        if (mat[nx][ny]) continue;
        dfs(nx, ny);
     }
}

int main() {
    while (~scanf("%d%d", &w, &h) && w + h) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
            --x2[i]; --y2[i];
        }
        w = compress(x1, x2, w - 1);
        h = compress(y1, y2, h - 1);
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < n; ++i)
            for (int x = x1[i]; x <= x2[i]; ++x)
                for (int y = y1[i]; y <=y2[i]; ++y)
                    mat[x][y] = 1;
        int area = 0;
        for (int x = 0; x < w; ++x)
            for (int y = 0; y < h; ++y) {
                if (mat[x][y]) continue;
                dfs(x, y);
                ++area;
            }
        printf("%d\n", area);
    }
    return 0;
}
