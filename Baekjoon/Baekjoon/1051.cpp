#include <iostream>
using namespace std;

int n, m, ans = 0;
char arr[50][50];

// n * m 을 벗어나는지 확인하는 함수
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
	char num = arr[x][y]; // (x, y)의 숫자
	int size = ans + 1; // 가장 큰 정사각형을 찾는 문제이므로 현재의 최대값+1 부터 시작
	while (1) {
		if (check(x, y, size)) { // 만들어진 정사각형이 직사각형 범위 안에 있고 각 꼭짓점의 숫자가 같으면 크기를 키움
			if (num == arr[x + size][y] && num == arr[x][y + size] && num == arr[x + size][y + size])
				ans = size;
			size++;
		}
		else // 범위 밖이면 break
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