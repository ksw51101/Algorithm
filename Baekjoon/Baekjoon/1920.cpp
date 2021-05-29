#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	// 이분탐색을 위해 vector 정렬
	sort(vec.begin(), vec.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;

		vector<int>::iterator iter = lower_bound(vec.begin(), vec.end(), temp);

		// temp 이상인 첫 번째 값이 temp와 다르다면 vec 안에 없다.
		if (iter == vec.end() || *iter != temp)	
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}

	return 0;
}