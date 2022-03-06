#include <cstdio>
#include <algorithm>

using namespace std;

const int n = 20;

int bits = 0, bit;

int count(int x) {
    int flip = x << 1;
    int cnt = x;
    for (int i = 2; i <= n + 1; ++i) {
        int curr = (bits >> (i - 1) & 1) ^ (flip >> (i - 1) & 1) ^ (flip >> (i - 2) & 1);
        flip |= curr << i;
        if (curr) ++cnt;
    }
    return (flip >> (n + 1) & 1) ? n : cnt;
}

int main() {
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &bit);
        bits |= bit << i;
    }
    printf("%d\n", min(count(0), count(1)));
    return 0;
}