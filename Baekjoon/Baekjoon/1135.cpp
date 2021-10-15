#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
vector<int> vec[50];

bool cmp(int a, int b) {
	return a > b;
}

int DFS(int num) {
	if (vec[num].empty()) // 직속부하가 없으면 return 0
		return 0;

	vector<int> order(vec[num].size()); // 내림차순으로 정렬하기 위한 vector

	for (int i = 0; i < vec[num].size(); i++) { // num번 직원의 모든 직속부하에 대해 DFS 실행
		order[i] = DFS(vec[num][i]);
	}
	sort(order.begin(), order.end(), cmp); // 최하위 직원까지 전달하는데 걸리는 시간을 내림차순으로 정렬

	int ret = 0;
	for (int i = 0; i < order.size(); i++) // num번 직원의 메시지 전달 시간 = (전달하는 순서(시간) + 전달당한 직원의 메시지 전달 시간)중 최대값
		ret = max(ret, order[i] + i + 1);

	return ret;
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (i == 0) // 0번직원은 패스
			continue;
		vec[temp].emplace_back(i); // temp번째 직원의 직속부하에 i 추가
	}

	cout << DFS(0) << '\n'; // 최상위 직원부터 시작

	return 0;
}