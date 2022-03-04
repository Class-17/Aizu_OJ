#include <cstdio>
#include <vector>

using namespace std;

void check(vector<vector<int> > &dp, vector<vector<int> > &curr, int tree) {
    for (int i = 0; i < dp[0].size(); ++i)
        if (dp[tree][i] >= 0)
            curr[tree][i] = max(dp[tree][i] + 1, curr[tree][i]);
    for (int i = 1; i < dp[0].size(); ++i)
        if (dp[(tree + 1) % 2][i - 1] >= 0)
            curr[tree][i] = max(dp[(tree + 1) % 2][i - 1] + 1, curr[tree][i]);
    for (int i = 0; i < dp[0].size(); ++i)
        curr[(tree + 1) % 2][i] = dp[(tree + 1) % 2][i];
}

int main() {
	int T, W;
    scanf("%d %d", &T, &W);
    vector<vector<int> > dp(2, vector<int>(W + 1, -1));
    dp[0][0] = dp[1][1] = 0;
    for (int i = 0; i < T; ++i) {
        vector<vector<int> > curr(2, vector<int>(W + 1));
        int tree;
        scanf("%d", &tree);
        check(dp, curr, tree - 1);
        dp = curr;
    }
	int res = 0;
    for (int i = 0; i <= W; ++i)
        res = max(max(dp[0][i], dp[1][i]), res);
    printf("%d\n", res);
	return 0;
}