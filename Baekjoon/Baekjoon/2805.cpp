#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, l, r, maximum = 0, ans = 0;
vector<int> vec;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		vec.push_back(temp);
		maximum = max(maximum, temp);
	}

	l = 1, r = maximum;

	// 이분탐색
	while (l <= r) {
		long long mid = (l + r) / 2, len = 0;
		for (int i = 0; i < n; i++) {
			if (vec[i] > mid)
				len += vec[i] - mid; // 가져가게 되는 나무의 길이
		}
		if (len >= m) { // 충분한 길이를 얻었으면 자르는 길이를 늘려 다시 시도
			l = mid + 1;
			ans = max(ans, mid);
		}
		else { // 길이가 부족하다면 자르는 길이를 줄여 얻게 되는 길이를 늘림
			r = mid - 1;
		}
	}
	cout << ans << '\n';

	return 0;
}