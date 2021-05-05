#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, c;
vector<int> vec;

int start(int left, int right) {
	int mid = (right + left) / 2;
	if (left > right)
		return mid;
	int wifi = 1;
	int num = vec[0] + mid;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] >= num) {
			num = vec[i] + mid;
			wifi++;
		}
	}
	if (wifi < c) {
		return start(left, mid-1);
	}
	else
		return start(mid+1, right);
}

int main() {
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());


	cout << start(1, vec[n - 1]) << '\n';

	return 0;
}