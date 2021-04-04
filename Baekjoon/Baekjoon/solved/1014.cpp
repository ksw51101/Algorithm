#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int T, N, M, ans;
char arr[11][10];
int dp[15][1025];

bool broken(int line, int bit) {
	for (int i = 0; i < M; i++) {
		if (arr[line][i] == 'x' && ((1 << (M - i - 1)) & bit) == (1 << (M - i - 1)))
			return false;
	}
	return true;
}

bool front(int bit, int fbit) {
	for (int i = 0; i < M; i++) {
		if ((1 << i) & fbit) {
			if (i > 0 && ((1 << (i - 1)) & bit)) return false;
			if ((1 << (i + 1) & bit)) return false;
		}
	}
	return true;
}

bool line_check(int line) {
	for (int i = 0; i < M - 1; i++) {
		if ((line & (3 << i)) == (3 << i))
			return false;
	}
	return true;
}

int main() {
	
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		ans = 0;
		memset(dp, 0, sizeof(dp));

		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[j][k];
			}
		}
		vector<pair<int, int>> set;
		for (int j = 0; j < pow(2, M); j++) {
			if (line_check(j)) {
				int cnt = 0;
				for (int k = 0; k < M; k++) {
					if (((1 << k) & j) == (1 << k))
						cnt++;
				}
				set.push_back(make_pair(j, cnt));
			}
		}

		for (int j = 1; j <= N; j++) {
			for (pair<int, int> bit : set) {
				if (!broken(j, bit.first)) 
					continue;
				for (pair<int, int> fbit : set) {
					if (front(bit.first, fbit.first)) {
						dp[j][bit.first] = max(dp[j][bit.first], dp[j - 1][fbit.first] + bit.second);
						ans = max(ans, dp[j][bit.first]);
					}
				}
			}
		}

		cout << ans << endl;
	}
	return 0;
}
