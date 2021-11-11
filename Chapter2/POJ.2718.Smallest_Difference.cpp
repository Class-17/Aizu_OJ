#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int get_val(int a[], int n) {
    if (a[0] == 0 && n > 1) return -1;
    int val = 0;
    for (int i = 0; i < n; ++i)
        val = val * 10 + a[i];
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; (cin >> _).get();
    while (_--) {
        string s;
        getline(cin, s);
        int a[10];
        for (int i = 0; i < s.size(); i += 2)
            a[i / 2] = s[i] - '0';
        int n = (s.size() + 1) / 2;
        int min_diff = 1e9;
        do {
            for (int len = n / 2; len <= (n + 1) / 2; ++len) {
                int x = get_val(a, len);
                int y = get_val(a + len, n - len);
                if (x >= 0 && y >= 0)
                    min_diff = min(abs(x - y), min_diff);
                if (n % 2 == 0) break;
            }
        } while (next_permutation(a, a + n));
        cout << min_diff << endl;
    }
    return 0;
}