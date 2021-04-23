#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[100000], ans = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int fear;
		cin >> fear;
		arr[i] = fear;
	}
	sort(arr, arr + n);

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt++;
		if (arr[i] == cnt) {
			ans++;
			cnt = 0;
		}
	}
	cout << ans << '\n';


	return 0;
}