#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, temp;
vector<int> vec;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}

	// 이분탐색을 위한 vector 정렬
	sort(vec.begin(), vec.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		vector<int>::iterator lower = lower_bound(vec.begin(), vec.end(), temp); // 처음 temp 이상인 값이 나오는 iterator
		vector<int>::iterator upper = upper_bound(vec.begin(), vec.end(), temp); // 처음 temp 초과인 값이 나오는 iterator

		// 두 iterator의 차이를 통한 결과 출력
		cout << upper - lower << ' '; 
	}

	return 0;
}