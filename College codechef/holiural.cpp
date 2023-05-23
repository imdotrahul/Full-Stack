#include <iostream>
#include<algorithm>
#include<math.h>
#include<stack>
using namespace std;

long long calculateMinimum(int dist[], int ra[], int n, int k) {
    long long minimumCost = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        long long cost = static_cast<long long>(dist[i]) * k + ra[i];
        minimumCost = min(minimumCost, cost);
    }

    return minimumCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int da[n];
        for (int i = 0; i < n; ++i) {
            cin >> da[i];
        }

        int ra[n];
        for (int i = 0; i < n; ++i) {
            cin >> ra[i];
        }

        long long minimumCost = calculateMinimum(da, ra, n, k);
        cout << minimumCost <<endl;
    }

    return 0;
}