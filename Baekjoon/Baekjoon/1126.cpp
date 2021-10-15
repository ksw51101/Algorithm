#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> vec;
int dp[50][500001]; // dp[i][j] : i번째까지의 블록을 모두 사용했을 때 두 탑의 높이의 차이가 j인 경우 높은 탑의 최대값

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

	dp[0][0] = 0; // 안쌓았을 경우 최대높이는 0
	dp[0][vec[0]] = vec[0]; // 첫 블록을 쌓으면 차이는 vec[0]이고 최대높이도 vec[0]

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j] == -1) continue; // 이전까지의 블록을 사용하여 높이차이가 j인 경우가 없으면 continue

			dp[i][j] = max(dp[i][j], dp[i - 1][j]); // 현재 블록을 사용하지 않는 경우

			dp[i][j + vec[i]] = max(dp[i][j + vec[i]], dp[i - 1][j] + vec[i]); // 현재 블록을 높은 탑에 사용하는 경우

			// 현재 블록을 낮은 탑에 사용하는 경우
			if (j >= vec[i]) { // 높은 탑이 바뀌지 않는 경우
				dp[i][j - vec[i]] = max(dp[i][j - vec[i]], dp[i - 1][j]);
			}
			else { // 높은 탑이 바뀌는 경우
				dp[i][vec[i] - j] = max(dp[i][vec[i] - j], dp[i - 1][j] - j + vec[i]);
			}
		}
	}
	if (dp[n - 1][0] == 0) // 블록을 모두 사용하였을 때 높이가 같은 탑이 없는 경우(블록을 아예 사용하지 않았을 경우 0이됨)
		cout << -1 << '\n';
	else
		cout << dp[n - 1][0] << '\n';


	return 0;
}