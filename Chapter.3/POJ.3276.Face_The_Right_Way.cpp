#include <cstdio>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 5000;

int n;

bitset<maxn> st;

int check(int k) {
    bitset<maxn> rv;
    int sum = 0, cnt = 0;
    for (int i = 0; i + k <= n; ++i) {
        if ((st[i] + sum) % 2) {
            rv[i] = 1;
            ++sum;
            ++cnt;
        }
        if (i - k + 1 >= 0)
            sum -= rv[i - k + 1];
    }
    for (int i = n - k + 1; i < n; ++i) {
        if ((st[i] + sum) % 2) return -1;
        if (i - k + 1 >= 0)
            sum -= rv[i - k + 1];
    }
    return cnt;
}

int main() {
    scanf("%d%*c", &n);
    for (int i = 0; i < n; ++i) {
        char ch;
        scanf("%c%*c", &ch);
        st[i] = ch == 'B';
    }
    int k = 1, m = n;
    for (int i = 1; i <= n; ++i) {
        int curr = check(i);
        if (curr >= 0 && curr < m) {
            k = i;
            m = curr;
        }
    }
    printf("%d %d\n", k, m);
    return 0;
}