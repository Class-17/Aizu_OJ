#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

const int maxn = 1e4;

vector<int> primes;

int n, len;

void sieve() {
    bitset<maxn + 1> st;
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
        primes.push_back(i);
    }
    len = primes.size();
}

int count() {
    int cnt = 0, sum = 0;
    for (int i = 0, j = 0; i < len; ++i) {
        while (j < len && sum < n)
            sum += primes[j++];
        if (sum == n) ++cnt;
        sum -= primes[i];
    }
    return cnt;
}

int main() {
    sieve();
    while (~scanf("%d", &n) && n)
        printf("%d\n", count());
    return 0;
}