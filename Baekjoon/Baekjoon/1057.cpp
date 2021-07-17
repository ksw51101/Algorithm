#include <iostream>
using namespace std;

int n, num1, num2, r;

// 라운드가 올라갈 때 참가자 번호를 수정하는 함수
void change(int& num) {
	if (num % 2)
		num = num / 2 + 1;
	else
		num = num / 2;
}

int main() {
	cin >> n >> num1 >> num2;
	r = 1; // 1라운드부터 시작

	if (num1 > num2)
		swap(num1, num2);
	while (1) {
		if (num1 % 2 && num1 + 1 == num2) // 김지민과 임한수가 대결하는 라운드에서 루프 종료
			break;
		r++; // 라운드 증가
		change(num1); // num1의 참가자 번호 수정
		change(num2); // num2의 참가자 번호 수정
	}
	cout << r << '\n';

	return 0;
}