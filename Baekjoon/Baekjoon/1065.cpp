#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		string temp = to_string(i);

		if (temp.size() == 1 || temp.size() == 2) { // �� �ڸ� �� �Ǵ� �� �ڸ� ���� ��� �׻� ��������
			cnt++;
			continue;
		}
		int gap = temp[0] - temp[1]; // ���� ���ڸ� ���� �� ���� ���� ���̸� gap���� ����
		for (int j = 1; j < temp.size(); j++) {
			if (j == temp.size() - 1) // ���� ���ڸ� ������ ���̰� ��� �����Ƿ� ��������
				cnt++;
			else if (temp[j] - temp[j + 1] != gap) // �� ���� ���� gap�� �ٸ� ��� ��������x
				break;
		}
	}
	cout << cnt << '\n';
		
	return 0;
}