#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, ans;
int arr[52][52];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int main() {
	cin >> n >> m;

	int maximum = 0; // 최대 높이 저장
	for (int i = 1; i <= n; i++) // (1,1)부터 (n,m)까지 값 저장
		for (int j = 1; j <= m; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp - '0';
			maximum = max(maximum, arr[i][j]);
		}

	for (int level = 2; level <= maximum; level++) { // 물의 높이를 2부터 최대값까지 올림
		queue<pair<int, int>> q;
		arr[0][0] = level;
		q.push({ 0, 0 }); // (0,0)부터 BFS 시작

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) { // 네 방향 중 맵을 벗어나지 않고 현재 물의 높이보다 작은 곳이 있으면 그 곳의 물 높이를 1 올리고 queue에 넣음
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				if (nx >= 0 && ny >= 0 && nx <= n + 1 && ny <= m + 1) {
					if (arr[nx][ny] < level) {
						arr[nx][ny] = level;
						q.push({ nx, ny });
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) { // 현재 잠긴 높이보다 낮은 곳은 물이 들어갈 수 있으므로 ans+=1
			for (int j = 1; j <= m; j++) {
				if (arr[i][j] < level) {
					ans++;
					arr[i][j]++;
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}