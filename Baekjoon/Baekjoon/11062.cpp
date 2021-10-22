#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int card[1000];
int dp[1000][1000];
int N;

int solution(int left, int right) {
	bool turn = (N - (right - left)) % 2;
	int& ret = dp[left][right];
	if (ret != -1)
		return ret;

	if (left == right) {
		if (turn) {
			return ret = card[left];
		}
		else {
			return ret = 0;
		}
	}

	if (turn) {
		return ret = max(solution(left + 1, right) + card[left], solution(left, right - 1) + card[right]);
	}
	else {
		return ret = min(solution(left + 1, right), solution(left, right - 1));
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> card[i];
		}
		cout << solution(0, N - 1) << '\n';;
	}

	return 0;
}