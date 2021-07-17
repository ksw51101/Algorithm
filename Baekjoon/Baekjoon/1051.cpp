#include <iostream>
using namespace std;

int n, m, ans = 0;
char arr[50][50];

// n * m �� ������� Ȯ���ϴ� �Լ�
bool check(int x, int y, int size) {
	int nx[] = { x, x + size, x + size };
	int ny[] = { y + size, y, y + size };
	for (int i = 0; i < 3; i++) {
		if (nx[i] < 0 || ny[i] < 0 || nx[i] >= n || ny[i] >= m)
			return false;
	}
	return true;
}

void solution(int x, int y) {
	char num = arr[x][y]; // (x, y)�� ����
	int size = ans + 1; // ���� ū ���簢���� ã�� �����̹Ƿ� ������ �ִ밪+1 ���� ����
	while (1) {
		if (check(x, y, size)) { // ������� ���簢���� ���簢�� ���� �ȿ� �ְ� �� �������� ���ڰ� ������ ũ�⸦ Ű��
			if (num == arr[x + size][y] && num == arr[x][y + size] && num == arr[x + size][y + size])
				ans = size;
			size++;
		}
		else // ���� ���̸� break
			break;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			solution(i, j);
		}
	}

	cout << (ans + 1) * (ans + 1) << '\n';
	return 0;
}