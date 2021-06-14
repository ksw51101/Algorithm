#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int r, c, ans = 0;
int len[750][750][2]; // len[i][j][0] : ���� �Ʒ����� ����, len[i][j][1] : ������ �Ʒ����� ����
string arr[750];

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> arr[i];

	// ����� �Ʒ����� ������ ���� �Ʒ����� ����, ������ �Ʒ����� ���̸� ����
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

	// ����� ���� 1�̸� ����, ������ �� ���� ���� �ִ�ũ��� ���� �ٿ����� ���̾Ƹ�尡 �ִ��� üũ
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '1') {
				for (int k = min(len[i][j][0], len[i][j][1]); k >= 1; k--) { // k�� ���̾Ƹ�� ũ��
					int nx = i + k - 1; // �������� ����, ������ �������� ��
					int nyl = j - k + 1; // �������� ���� �������� ��
					int nyr = j + k - 1; // �������� ������ �������� ��
					if (nx >= r || nyl < 0 || nyr >= c) continue;
					if (len[nx][nyl][1] >= k && len[nx][nyr][0] >= k) { // ���� �������� ������ �Ʒ����� ����, ������ �������� ���� �Ʒ����� ���̰� k�̻��̸� ���̾Ƹ�� ����
						ans = max(ans, k); // �ִ� ���̾Ƹ�� ũ�� ����
						break;
					}
				}
			}
		}
	}
	cout << ans << '\n';

	return 0;
}