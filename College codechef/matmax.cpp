#include <iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int testcase;
  cin >> testcase;

  while (testcase--) {
    int nope, mope;
    cin >> nope >> mope;

    int maxdiff = INT_MIN;

    for (int i = 0; i < nope; i++) {
      int mini = INT_MAX;
      int maxi = INT_MIN;

      for (int j = 0; j < mope; j++) {
        int value;
        cin >> value;

        mini = min(mini, value);
        maxi = max(maxi, value);
      }

      maxdiff = max(maxdiff, maxi - mini);
    }

    cout << maxdiff << endl;
  }

  return 0;
}