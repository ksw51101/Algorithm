#include <iostream>
#include <string>
using namespace std;

string l, r;
int ans;

int main() {
	cin >> l >> r;

	if (l.size() != r.size()) // �ڸ����� �ٸ��� '8'�� 0���� ��찡 ����
		ans = 0;
	else {
		int cnt = 0;
		for (int i = 0; i < l.size(); i++) { // �ڸ����� ������ �� �տ������� ���� �ٸ� ���� ���ö������� '8'�� ������ ����
			if (l[i] != r[i])
				break;
			if (l[i] == '8') cnt++;				
		}
		ans = cnt;
	}
	cout << ans << '\n';

	return 0;
}