#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> vec;

int main() {
	cin >> n>>c;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	// 이분탐색을 위한 vector 정렬
	sort(vec.begin(), vec.end());

	int start = 1; // 집이 겹치는 경우는 없으므로 가능한 최소 거리는 1
	int end = vec.back() - vec.front(); // 최대 거리는 마지막 집과 첫번째 집과의 거리
	int ans = 0;

	while (start<=end) {
		int mid = (start + end) / 2; // 두 집사이의 최소거리
		int now = vec[0]; // 마지막으로 공유기가 설치된 집의 위치(첫번째 집은 설치되어 있다고 가정)
		int cnt = 1; // 설치된 공유기의 개수

		for (int i = 1; i < vec.size(); i++) {
			if (vec[i] < now + mid) continue; // 마지막으로 공유기가 설치된 집과의 거리가 최소거리보다 작은 경우 continue
			now = vec[i];
			cnt++;
		}
		if (cnt < c) // c개의 공유기가 설치되지 못했다면 최소거리를 줄여 다시 시도
			end = mid - 1;
		else { // c개 이상의 공유기가 설치되었다면 최소거리를 늘려 시도
			start = mid + 1;
			ans = mid;
		}
	}
	cout << ans << '\n';

	return 0;
}
