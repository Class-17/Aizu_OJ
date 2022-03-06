#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5;

int _, n, s, arr[maxn];

int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d %d", &n, &s);
        for (int i = 0; i < n; ++i)
            scanf("%d", arr + i);
        int min_len = n + 1;
        int sum = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            sum += arr[i];
            while (j <= i && sum - arr[j] >= s) 
                sum -= arr[j++];
            if (sum >= s)
                min_len = min(min_len, i - j + 1);
        }
        printf("%d\n", min_len <= n ? min_len : 0);
    }
    return 0;
}