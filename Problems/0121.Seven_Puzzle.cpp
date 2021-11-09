#include <cstdio>
#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int dirs[] = {1, -1, 4, -4};

int find_zero(string &seq) {
    for (int i = 0; i < 8; ++i)
        if (seq[i] == '0') return i;
    return -1;
}

int bfs(string &seq) {
    queue<string> q;
    unordered_set<string> memo;
    q.push(seq);
    memo.insert(seq);
    int dist = 0;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
            string x = q.front();
            q.pop();
            printf("%s\n", x.c_str());
            if (x == "01234567") return dist;
            int p = find_zero(x);
            for (int i = 0; i < 4; ++i) {
                int np = p + dirs[i];
                if (np < 0 || np >= 8) continue;
                swap(x[p], x[np]);
                if (memo.find(x) == memo.end()) {
                    q.push(x);
                    memo.insert(x);
                }
                swap(x[p], x[np]);
            }
        }
        dist++;
    }
    return -1;
}

int main() {
    string seq = "01234567";
    char x, _;
    while (scanf("%c%c", &x, &_)) {
        seq[0] = x;
        for (int i = 1; i < 8; ++i) {
            scanf("%c%c", &x, &_);
            seq[i] = x;
        }
        printf("%d\n", bfs(seq));
    }
    return 0;
}
