#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int dp[501][501]; // dp[i][j] : i번째 행렬~j번째을 곱할때 사용하는 최소 곱셈 횟수
pair<int, int> arr[501];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}

	for (int d = 1; d < n; d++) { // dp[i][j]에서 j-i값
		for (int i = 1; d + i <= n; i++) {
			int j = d + i;
			dp[i][j] = INT_MAX;
			for (int mid = i; mid < j; mid++) { // i번째 행렬과 j번째 행렬 사이에 mid번째 행렬을 두어 dp[i][mid] 와 dp[mid+1][j]를 구하고 이 둘을 곱함(i와 j사이의 모든 수를 순회)
				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + arr[i].first * arr[mid].second * arr[j].second);
			}
		}
	}
	cout << dp[1][n] << '\n';

	return 0;
}