#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

const int maxn = 1 << 20;

vector<int> primes;

void sieve() {
    bitset<maxn + 1> st;
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
        primes.push_back(i);
    }
}

int main() {
    sieve();
    int x, len = primes.size();
    while (scanf("%d", &x) != EOF) {
        vector<int> divs;
        for (int i = 0; i < len && x > 1; ++i) {
            int curr = 0;
            while (x % primes[i] == 0) {
                x /= primes[i];
                curr++;
            }
            if (curr > 0)
                divs.push_back(curr);
        }
        int sum = 0, m = divs.size();
        for (int i = 0; i < m; ++i)
            sum += divs[i];
        ll tt = 1;
        for (int i = 2; i <= sum; ++i)
            tt *= i;
        for (int i = 0; i < m; ++i) {
            for (int j = 2; j <= divs[i]; ++j)
                tt /= j;
        }
        printf("%d %lld\n", sum, tt);
    }
    return 0;
}