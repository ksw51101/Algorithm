#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int dp[501][501]; // dp[i][j] : i��° ���~j��°�� ���Ҷ� ����ϴ� �ּ� ���� Ƚ��
pair<int, int> arr[501];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		arr[i] = { a, b };
	}

	for (int d = 1; d < n; d++) { // dp[i][j]���� j-i��
		for (int i = 1; d + i <= n; i++) {
			int j = d + i;
			dp[i][j] = INT_MAX;
			for (int mid = i; mid < j; mid++) { // i��° ��İ� j��° ��� ���̿� mid��° ����� �ξ� dp[i][mid] �� dp[mid+1][j]�� ���ϰ� �� ���� ����(i�� j������ ��� ���� ��ȸ)
				dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + arr[i].first * arr[mid].second * arr[j].second);
			}
		}
	}
	cout << dp[1][n] << '\n';

	return 0;
}