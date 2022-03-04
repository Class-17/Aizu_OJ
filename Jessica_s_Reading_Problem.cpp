#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int maxn = 1e6;

int n, arr[maxn];

map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
        mp[arr[i]] = 0;
    }
    int min_len = n, sum = mp.size(), curr = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < n && curr < sum)
            if (++mp[arr[j++]] == 1) ++curr;
        if (curr <  sum) break;
        min_len = min(min_len, j - i);
        if (--mp[arr[i]] == 0) --curr;
    }
    printf("%d\n", min_len);
    return 0;
}
