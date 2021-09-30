#include <iostream>
#include <string>
using namespace std;

string n;
int ans;

// 규칙대로 num을 바꾸는 함수
string solution(string num) {
	if (num.size() == 1) // 한자리 수면 앞에 '0'을 붙임
		num = "0" + num;
	int sum = num[0] - '0' + num[1] - '0'; // 두 수를 더함
	sum %= 10; // 제일 오른쪽 수를 구함
		
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