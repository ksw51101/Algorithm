#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
long long maximum = 0, l, r, ans = 0;
vector<int> vec;

int main() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		long long temp;
		cin >> temp;
		vec.push_back(temp);
		maximum = max(maximum, temp);
	}
	l = 1, r = maximum;

	// 이분탐색
	while (r >= l) {
		long long len = (r + l) / 2;
		int num = 0;
		for (int i = 0; i < k; i++)
			num += vec[i] / len; // 자르기 전의 각각의 랜선에서 얻게 되는 랜선의 수
		if (num < n) // 개수가 목표치보다 작을 경우 자르는 길이를 줄여서 개수를 늘림
			r = len - 1;
		else { // 개수가 목표치 이상일 경우 자르는 길이를 늘려서 시도
			l = len + 1;
			ans = max(ans, len);
		}
	}
	cout << ans << '\n';

	return 0;
}