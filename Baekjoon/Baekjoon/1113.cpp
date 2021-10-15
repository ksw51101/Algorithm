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

	int maximum = 0; // �ִ� ���� ����
	for (int i = 1; i <= n; i++) // (1,1)���� (n,m)���� �� ����
		for (int j = 1; j <= m; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp - '0';
			maximum = max(maximum, arr[i][j]);
		}

	for (int level = 2; level <= maximum; level++) { // ���� ���̸� 2���� �ִ밪���� �ø�
		queue<pair<int, int>> q;
		arr[0][0] = level;
		q.push({ 0, 0 }); // (0,0)���� BFS ����

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int dir = 0; dir < 4; dir++) { // �� ���� �� ���� ����� �ʰ� ���� ���� ���̺��� ���� ���� ������ �� ���� �� ���̸� 1 �ø��� queue�� ����
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
		for (int i = 1; i <= n; i++) { // ���� ��� ���̺��� ���� ���� ���� �� �� �����Ƿ� ans+=1
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