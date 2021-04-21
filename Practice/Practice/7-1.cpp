#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, target, input, result;
vector<int> vec;

int search(int begin, int end) {
	int mid = (end - begin) / 2 + begin;
	if (begin > end)
		return -1;
	else if (vec[mid] == target)
		return mid;
	else if (vec[mid] > target)
		return search(begin, mid - 1);
	else
		return search(mid + 1, end);
}

int main() {
	cin >> n >> target;

	for (int i = 0; i < n; i++) {
		cin >> input;
		vec.push_back(input);
	}

	result = search(0, n - 1);
	if (result == -1)
		cout << target << "이 존재하지 않습니다." << '\n';
	else
		cout << result + 1 << '\n';

	return 0;
}