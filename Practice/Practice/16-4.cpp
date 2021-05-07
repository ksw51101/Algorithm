#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[2000], dp[2000];

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	cout << n - ans << '\n';
	return 0;
}