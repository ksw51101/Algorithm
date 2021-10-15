#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> vec;
int dp[50][500001]; // dp[i][j] : i��°������ ����� ��� ������� �� �� ž�� ������ ���̰� j�� ��� ���� ž�� �ִ밪

int main() {
	cin >> n;
	int m = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		m += temp;
		vec.emplace_back(temp);
	}
	fill(&dp[0][0], &dp[50][500001], -1);

	dp[0][0] = 0; // �Ƚ׾��� ��� �ִ���̴� 0
	dp[0][vec[0]] = vec[0]; // ù ����� ������ ���̴� vec[0]�̰� �ִ���̵� vec[0]

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == -1) continue; // ���������� ����� ����Ͽ� �������̰� j�� ��찡 ������ continue

			dp[i][j] = max(dp[i][j], dp[i - 1][j]); // ���� ����� ������� �ʴ� ���

			dp[i][j + vec[i]] = max(dp[i][j + vec[i]], dp[i - 1][j] + vec[i]); // ���� ����� ���� ž�� ����ϴ� ���

			// ���� ����� ���� ž�� ����ϴ� ���
			if (j >= vec[i]) { // ���� ž�� �ٲ��� �ʴ� ���
				dp[i][j - vec[i]] = max(dp[i][j - vec[i]], dp[i - 1][j]);
			}
			else { // ���� ž�� �ٲ�� ���
				dp[i][vec[i] - j] = max(dp[i][vec[i] - j], dp[i - 1][j] - j + vec[i]);
			}
		}
	}
	if (dp[n - 1][0] == 0) // ����� ��� ����Ͽ��� �� ���̰� ���� ž�� ���� ���(����� �ƿ� ������� �ʾ��� ��� 0�̵�)
		cout << -1 << '\n';
	else
		cout << dp[n - 1][0] << '\n';


	return 0;
}