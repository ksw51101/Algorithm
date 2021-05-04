#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int pos;
		cin >> pos;
		vec.push_back(pos);
	}
	sort(vec.begin(), vec.end());
	if (n % 2 == 1)
		cout << vec[n % 2] << '\n';
	else
		cout << vec[(n - 1) % 2] << '\n';

	return 0;
}