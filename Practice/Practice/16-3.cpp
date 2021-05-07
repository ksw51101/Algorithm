#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> t;
vector<int> p;
int dp[16];
int maxValue;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t.push_back(x);
        p.push_back(y);
    }

    for (int i = n - 1; i >= 0; i--) {
        int time = t[i] + i;
        if (time <= n) {
            dp[i] = max(p[i] + dp[time], maxValue);
            maxValue = dp[i];
        }
        else dp[i] = maxValue;
    }
    cout << maxValue << '\n';
}