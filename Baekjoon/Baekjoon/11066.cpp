#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int T, arr[501];
int dp[501][501]; // dp[i][j] : i번째장~j번째장까지 합치는 최소 비용
int sum[501]; // 1번째장~i번째장까지의 합 

int main() {
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int k;
		cin >> k;

		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i]; 
		}

		for (int d = 1; d < k; d++) { // dp[i][j]에서 j-i값
			for (int i = 1; i + d <= k; i++) {
				int j = i + d;
				dp[i][j] = INT_MAX;
				for (int mid = i; mid < j; mid++) { // i번째장과 j번째장 사이에 mid번째 장을 두어 dp[i][mid] 와 dp[mid+1][j]를 구하고 이 둘을 i~j장의 비용을 합친 sum[j]-sum[i-1]으로 합침(i와 j사이의 모든 수를 순회)
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
				}

			}
		}
		cout << dp[1][k] << '\n';
	}

	return 0;
}