#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	getline(cin, s); // ������ ������ �Է�
	
	int cnt = 0; // ������ ����(�Ǿ�, �ǵ� ����)
	if (s != " ") { // �Է��� " "�� ��� �ܾ��� ������ 0
		for (int i = 0; i < s.size(); i++)
			if (s[i] == ' ') {
				if (i != 0 && i != s.size() - 1) // ������ �Ǿ�, �ǵڰ� �ƴϸ� cnt++
					cnt++;
			}
		cnt++; // �ܾ��� ������ ������ ����+1
	}
	cout << cnt << '\n';

	return 0;
}