#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

// 내림차순 sort에 사용할 compare함수
bool compare(int a, int b) {
	return a > b;
}

int main() {
	int ans = 0; // 모든 화물을 옮기는데 걸리는 최소 시간
	cin >> n;
	vector<int> limit(n); // 크레인의 무게 제한
	vector<int> p(n); // 각 크레인이 들 수 있는 화물의 수(limit이 작은 크레인부터 시작해서 이미 포함된 화물은 제외하고 count)
	for (int i = 0; i < n; i++)
		cin >> limit[i];
	cin >> m;
	vector<int> weight(m); // 각 화물의 무게
	for (int i = 0; i < m; i++)
		cin >> weight[i];
	sort(limit.begin(), limit.end()); // 오름차순 정렬
	sort(weight.begin(), weight.end(), compare); // 내림차순 정렬
	if (limit.back() < weight.front()) // 최대 무게를 들 수 있는 크레인이 가장 무거운 화물을 들 수 없다면 -1 출력
		cout << -1 << '\n';
	else {
		// 각 크레인이 들 수 있는 화물의 수 확인
		for (int i = 0; i < n; i++) {
			for (int j = weight.size() - 1; j >= 0; j--) {
				if (limit[i] >= weight[j]) {
					p[i]++;
					weight.pop_back();
				}
				else
					break;
			}
		}
		while (m > 0) { // 남은 물건이 없을 때까지 반복
			ans++; // 시간 경과
			for (int i = n - 1; i >= 0; i--) { // 가장 무거운 화물을 들 수 있는 크레인부터 가장 가벼운 무게를 들 수 있는 크레인까지 확인
				if (p[i] > 0) { // 해당 크레인이 화물이 있으면
					p[i]--; // 해당 화물 이동
					m--; // 남은 화물 수 -1
				}
				else { // 해당 크레인이 들 화물이 없으면
					for (int j = i - 1; j >= 0; j--) { // 더 적은 무게를 들 수 있는 크레인의 화물을 대신 옮겨줌
						if (p[j] > 0) {
							p[j]--;
							m--;
							break;
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}