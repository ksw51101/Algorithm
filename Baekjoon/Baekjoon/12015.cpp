#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans = 0;

int main() {
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (vec.empty() || temp > vec.back()) // vec의 마지막 값보다 temp가 클 경우 그냥 추가
			vec.push_back(temp);
		else { // vec의 마지막 값보다 temp가 작을 경우 이분탐색을 통해 찾은 temp 이상인 첫 index의 값을 temp로 치환(vec은 항상 정렬되어 있으므로 가능)
			auto iter = lower_bound(vec.begin(), vec.end(), temp);
			*iter = temp;
		}
	}
	cout << vec.size() << '\n';
	
	return 0;
}