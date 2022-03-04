#include <cstdio>
#include <algorithm>
using namespace std;

const int maxm = 2010;

int dp[maxm][maxm] = {0};

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    char s[maxm + 1];
    scanf("%s\n", s);
    int w[128] = {0};
    for (int i = 0; i < n; ++i) {
        char ch;
        int a, b;
        scanf("%c %d %d\n", &ch, &a, &b);
        w[ch] = min(a, b);
    }
    for (int i = 0; i + 1 < m; ++i)
        dp[i][i + 1] = (s[i] == s[i + 1] ? 0 : min(w[s[i]], w[s[i + 1]]));
    for (int i = 2; i < m; ++i)
        for (int j = 0; j + i < m; ++j)
            if (s[j] == s[j + 1])
                dp[j][j + i] = dp[j - 1][j + i - 1];
            else
                dp[j][j + i] = min(dp[j][j + i - 1] + w[s[j + i]], w[s[j]] + dp[j + 1][j + i]);
    printf("%d\n", dp[0][m - 1]);
    return 0;
}