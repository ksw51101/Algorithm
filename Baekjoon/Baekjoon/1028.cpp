#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c, ans = 0;
int len[750][750][2]; // len[i][j][0] : 왼쪽 아래로의 길이, len[i][j][1] : 오른쪽 아래로의 길이
string arr[750];

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> arr[i];

	// 행렬의 아래부터 시작해 왼쪽 아래로의 길이, 오른쪽 아래로의 길이를 구함
	for (int i = r - 1; i >= 0; i--)
		for (int j = c - 1; j >= 0; j--) {
			if (arr[i][j] == '1') {
				if (i + 1 >= r) {
					len[i][j][0] = 1;
					len[i][j][1] = 1;
				}
				else  if (j - 1 < 0) {
					len[i][j][0] = 1;
					len[i][j][1] = len[i + 1][j + 1][1] + 1;
				}
				else if (j + 1 >= c) {
					len[i][j][1] = 1;
					len[i][j][0] = len[i + 1][j - 1][0] + 1;
				}
				else {
					len[i][j][1] = len[i + 1][j + 1][1] + 1;
					len[i][j][0] = len[i + 1][j - 1][0] + 1;
				}
			}
		}

	// 행렬의 값이 1이면 왼쪽, 오른쪽 중 작은 값을 최대크기로 놓고 줄여가며 다이아몬드가 있는지 체크
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '1') {
				for (int k = min(len[i][j][0], len[i][j][1]); k >= 1; k--) { // k는 다이아몬드 크기
					int nx = i + k - 1; // 마름모의 왼쪽, 오른쪽 꼭짓점의 행
					int nyl = j - k + 1; // 마름모의 왼쪽 꼭짓점의 열
					int nyr = j + k - 1; // 마름모의 오른쪽 꼭짓점의 열
					if (nx >= r || nyl < 0 || nyr >= c) continue;
					if (len[nx][nyl][1] >= k && len[nx][nyr][0] >= k) { // 왼쪽 꼭짓점의 오른쪽 아래로의 길이, 오른쪽 꼭짓점의 왼쪽 아래로의 길이가 k이상이면 다이아몬드 성립
						ans = max(ans, k); // 최대 다이아몬드 크기 갱신
						break;
					}
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}