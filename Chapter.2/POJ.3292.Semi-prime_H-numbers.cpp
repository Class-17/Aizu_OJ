#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 1;

vector<int> primes, nums;

void sieve() {
    bitset<maxn + 1> st;
    for (int i = 5; i <= maxn; i += 4) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
        primes.push_back(i);
    }
}

void init() {
    int n = primes.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (primes[j] > maxn / primes[i]) break;
            nums.push_back(primes[i] * primes[j]);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
}

int main() {
    sieve();
    init();
    int h;
    while (scanf("%d", &h) != EOF && h != 0) {
        int cnt = upper_bound(nums.begin(), nums.end(), h) - nums.begin();
        printf("%d %d\n", h, cnt);
    }
    return 0;
}