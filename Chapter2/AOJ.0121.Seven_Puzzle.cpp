#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

const int dirs[] = {1, -1, 4, -4};

int main() {
    queue<string> q;
    map<string, int> dp;
    q.push("01234567");
    dp["01234567"] = 0;
    while (!q.empty()) {
        string x = q.front();
        q.pop();
        int p = x.find('0');
        for (int i = 0; i < 4; ++i) {
            int np = p + dirs[i];
            if (np < 0 || np >= 8 || p == 3 && 
                np == 4 || p == 4 && np == 3) continue;
            int dist = dp[x] + 1;
            swap(x[p], x[np]);
            if (dp.find(x) == dp.end()) {
                dp[x] = dist;
                q.push(x);
            }
            swap(x[p], x[np]);
        }
    }
    string seq = "01234567";
    while (cin >> seq[0]) {
        for (int i = 1; i < 8; ++i)
            cin >> seq[i];
        cout << dp[seq] << endl;
    }
    return 0;
}