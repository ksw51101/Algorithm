#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int T, arr[501];
int dp[501][501]; // dp[i][j] : i��°��~j��°����� ��ġ�� �ּ� ���
int sum[501]; // 1��°��~i��°������� �� 

int main() {
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int k;
		cin >> k;

		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i]; 
		}

		for (int d = 1; d < k; d++) { // dp[i][j]���� j-i��
			for (int i = 1; i + d <= k; i++) {
				int j = i + d;
				dp[i][j] = INT_MAX;
				for (int mid = i; mid < j; mid++) { // i��°��� j��°�� ���̿� mid��° ���� �ξ� dp[i][mid] �� dp[mid+1][j]�� ���ϰ� �� ���� i~j���� ����� ��ģ sum[j]-sum[i-1]���� ��ħ(i�� j������ ��� ���� ��ȸ)
					dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j] + sum[j] - sum[i - 1]);
				}

			}
		}
		cout << dp[1][k] << '\n';
	}

	return 0;
}