#include <iostream>
using namespace std;

int main() {
	int cnt = 0; // ������ �����ϴ� ���� ��

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			char temp;
			cin >> temp;
			if (temp == 'F' && !((i + j) % 2)) // ���� �����ְ� ��� ���� ���� ¦���̸� ���ĭ�̹Ƿ� cnt++
				cnt++;
		}
	cout << cnt << '\n';

	return 0;
}