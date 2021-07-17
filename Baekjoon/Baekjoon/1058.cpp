#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000000
int n;

// 플로이드 워셜 알고리즘
void solution(vector<vector<int>> &a) {
	int size = a.size();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
}

int main() {
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(n, MAX)); // 초기값 무한대로 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			char temp;
			cin >> temp;
			if (i == j) // 자신에게의 거리는 0
				vec[i][j] = 0;
			if(temp=='Y') // 친구인 경우 거리는 1
				vec[i][j] = 1;
		}

	solution(vec);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (vec[i][j] == 1 || vec[i][j] == 2) // 둘이 친구이거나 한단계 건너 친구일 경우 cnt++
				cnt++;
		}
		ans = max(ans, cnt); // 최댓값으로 수정
	}
	cout << ans << '\n';

	return 0;
}