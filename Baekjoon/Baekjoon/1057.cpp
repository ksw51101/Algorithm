#include <iostream>
using namespace std;

int n, num1, num2, r;

// ���尡 �ö� �� ������ ��ȣ�� �����ϴ� �Լ�
void change(int& num) {
	if (num % 2)
		num = num / 2 + 1;
	else
		num = num / 2;
}

int main() {
	cin >> n >> num1 >> num2;
	r = 1; // 1������� ����

	if (num1 > num2)
		swap(num1, num2);
	while (1) {
		if (num1 % 2 && num1 + 1 == num2) // �����ΰ� ���Ѽ��� ����ϴ� ���忡�� ���� ����
			break;
		r++; // ���� ����
		change(num1); // num1�� ������ ��ȣ ����
		change(num2); // num2�� ������ ��ȣ ����
	}
	cout << r << '\n';

	return 0;
}