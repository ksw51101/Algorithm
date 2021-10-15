#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;
int len;

// �� ���ڿ� s1, s2�� ���̸� ���ϴ� �Լ�
int check(string s1, string s2) {
	int cnt = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] != s2[i])
			cnt++;
	}
	return cnt;
}
 
int main() {
	cin >> A >> B;
	len = B.size() - A.size(); // �� ���ڿ��� ������ ����
	
	int minimum = 50;
	for (int i = 0; i <= len; i++) {
		string temp = B.substr(i, A.size()); // temp : B�� i��° ���ں��� A�� ���̸�ŭ �ڸ� ���ڿ�
		minimum = min(minimum, check(temp, A)); // ������ �ּڰ��� ����
	}
	cout << minimum << '\n'; // �������� �˸��� ���ĺ��� �յڷ� �߰��ϸ� ���� minimum�� �ּ� ���̰� ��

	return 0;
}