#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000000000
int n, l;
vector<int> vec;
vector<pair<int, int>> arr;

// n이 집합 S의 원소인지 확인하는 함수
bool check(int num) {
	for (int i = 0; i < vec.size(); i++)
		if (vec[i] == num)
			return true;
	return false;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
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

	for (int z = 1; z <= max(n, vec[l-1]); z++) {
		int left = 0, right = 1000000000; // n은 left와 right의 사이에 존재
		if (check(z)) // n인 집합 S에 포함되어 있는 경우 좋은 구간은 존재x
			arr.push_back({z, 0});
		else {
			if (z > vec[l - 1])
				arr.push_back({ z, MAX });
			else {
				for (int i = 0; i < l; i++) {
					if (vec[i] < z)
						left = max(vec[i], left); // n보다 작은 집합 S의 원소 중 최댓값
					else if (vec[i] > z)
						right = min(vec[i], right); // n보다 큰 집합 S의 원소 중 최솟값
				}
				arr.push_back({ z, (z - left - 1) * (right - z) + right - 1 - z }); // (left 초과 n 미만의 수) * (n 이상 right 미만의 수) + (n 초과 right 미만의 수)
			}
		}
	}
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].first << ' ';
	}
	return 0;
}