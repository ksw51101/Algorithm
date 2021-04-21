#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
int ans;

void binary(int left, int right, int m) {
	if (left > right)
		return;
	int mid = (right + left) / 2;
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) 
		if (vec[i] - mid > 0)
			sum += vec[i] - mid;
	if (sum < m)
		binary(left, mid - 1, m);
	else {
		ans = mid;
		binary(mid + 1, right, m);
	}
}

int main() {
	int n, m, num, max_length = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> num;
		max_length = max(max_length, num);
		vec.push_back(num);
	}
	binary(0, max_length, m);
	cout << ans << '\n';

	return 0;
}