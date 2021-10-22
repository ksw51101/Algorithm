#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int cnt['z' - 'a' + 1] = { 0, }; // 'A'~'Z'�� ������ 0���� �ʱ�ȭ
	cin >> s;

	for (int i = 0; i < s.size(); i++) { // ���ڿ� s�� Ž���ϸ� �� ���ĺ��� ���� ����
		if (s[i] >= 'a' && s[i] <= 'z') {
			cnt[s[i] - 'a']++; 
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			cnt[s[i] - 'A']++;
		}
	}

	int big = cnt[0]; // 'A'�� ������ �ִ밪���� �ʱ�ȭ
	int index = 0; // ������ �ִ��� ���ĺ��� index ����
	bool flag = false; // ������ �ִ��� ���ĺ��� ���������� Ȯ��

	for (int i = 1; i < 'z' - 'a' + 1; i++) { // 26�� ���ĺ� Ž��
		if (cnt[i] == big && big != 0) { // ������ ���� ���ĺ��� �ְ� �� ���� 0�� �ƴ� ��� flag�� true�� ����
			flag = true;
			continue;
		}
		if (cnt[i] > big) { // �� ū ���� ������ �ִ񰪰� index ����, flag�� false�� ����
			flag = false;
			big = cnt[i];
			index = i;
		}
	}
	if (flag) // flag�� true�� ��� �ִ��� ���ĺ��� ���� ���̹Ƿ� '?' ���
		cout << '?' << '\n';
	else // false�� ��� ���ĺ� ���
		cout << (char)('A' + index) << '\n';

	return 0;
}