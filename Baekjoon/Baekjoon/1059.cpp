#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int> vec;

// n이 집합 S의 원소인지 확인하는 함수
bool check() {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == n)
			return true;
	return false;
}

int main() {
	cin >> l;
	for (int i = 0; i < l; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end()); // 오름차순 정렬

	cin >> n;

	int left = 0, right = 1000; // n은 left와 right의 사이에 존재
	if (check()) // n인 집합 S에 포함되어 있는 경우 좋은 구간은 존재x
		cout << 0 << "\n";
	else {
		for (int i = 0; i < l; i++) {
			if (vec[i] < n)
				left = max(vec[i], left); // n보다 작은 집합 S의 원소 중 최댓값
			else if (vec[i] > n)
				right = min(vec[i], right); // n보다 큰 집합 S의 원소 중 최솟값
		}
		cout << (n - left - 1) * (right - n) + right - 1 - n << '\n'; // (left 초과 n 미만의 수) * (n 이상 right 미만의 수) + (n 초과 right 미만의 수)
	}
	return 0;
}