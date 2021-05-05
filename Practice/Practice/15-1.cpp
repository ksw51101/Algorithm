#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x;
vector<int> vec;

int main() {
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	vector<int>::iterator upper = upper_bound(vec.begin(), vec.end(), x);
	vector<int>::iterator lower = lower_bound(vec.begin(), vec.end(), x);

	int ans = upper - lower;
	if (ans == 0)
		cout << -1 << '\n';
	else
		cout << ans << '\n';

	return 0;
}