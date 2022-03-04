#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 1e6 - 1;

void sieve(vector<int> &primes) {
    bitset<maxn + 1> st;
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
        primes.push_back(i);
    }
}

int main() {
    int n;
    vector<int> primes;
    sieve(primes);
    while (scanf("%d", &n) != EOF) {
        int cnt = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
        printf("%d\n", cnt);
    }
    return 0;
}