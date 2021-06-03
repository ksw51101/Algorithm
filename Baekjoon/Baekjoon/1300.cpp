#include <iostream>
#include <algorithm>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;

	int start = 1, end = k, ans = 0;

	// 이분탐색
	while (start <= end) {
		int mid = (start + end) / 2;
		long long num = 0;

		// mid 이하인 숫자의 개수 찾기
		for (int i = 1; i <= n; i++) 
			num += min(n, mid / i);

		if (num < k) { // mid 이하의 숫자의 개수가 k보다 작을 경우 답이 될 수 없으므로 start를 늘려서 다시 시도
			start = mid + 1;
		}
		else { // mid 이하의 숫자의 개수가 k이상일 경우 답이 될 수 있으므로 ans에 저장 후 end를 줄여서 더 작은 수가 있는지 확인
			end = mid - 1;
			ans = mid;
		}
	}
	cout << ans << '\n';

	return 0;
}