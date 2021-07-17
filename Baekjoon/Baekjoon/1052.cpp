#include <iostream>
#include <bitset>
using namespace std;

int n, k;

// 물병을 최대한 합쳐 수를 최소로 줄였을 때의 물병 수를 구하는 함수
int cnt(bitset<32> bs) {
	int temp = 0;
	for (int i = 0; i < 32; i++) {
		if (bs[i])
			temp++;
	}
	return temp;
}

int main() {
	int ans = 0;

	cin >> n >> k;

	while (1) {
		bitset<32> bs(n);
		if (cnt(bs) <= k) // 목표값 k 이하일 경우 break
			break;
		ans++;
		n++;
	}
	cout << ans << '\n';

	return 0;
}