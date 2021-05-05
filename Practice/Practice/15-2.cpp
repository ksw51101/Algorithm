#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> vec;

int binary(int left, int right) {
	if (left > right)
		return -1;
	int mid = right - left;
	if (vec[mid] == mid)
		return mid;
	else if (vec[mid] < mid) {
		return binary(mid + 1, right);
	}
	else
		return binary(left, mid - 1);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cout << binary(0, vec.size() - 1) << '\n';

	return 0;
}