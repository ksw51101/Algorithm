#include <iostream>
#include <string>
using namespace std;

string n;
int ans;

// ��Ģ��� num�� �ٲٴ� �Լ�
string solution(string num) {
	if (num.size() == 1) // ���ڸ� ���� �տ� '0'�� ����
		num = "0" + num;
	int sum = num[0] - '0' + num[1] - '0'; // �� ���� ����
	sum %= 10; // ���� ������ ���� ����
		
	num = num[1] + to_string(sum);

	return num;
}

int main() {
	cin >> n;

	string temp = n;
	if (n.size() == 1)
		n = "0" + n;
	while (1) {
		ans++;
		if (solution(temp) == n)
			break;
		temp = solution(temp);
	}
	cout << ans << '\n';

	return 0;
}