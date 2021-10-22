#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	int cnt['z' - 'a' + 1] = { 0, }; // 'A'~'Z'의 개수를 0으로 초기화
	cin >> s;

	for (int i = 0; i < s.size(); i++) { // 문자열 s를 탐색하며 각 알파벳의 개수 증가
		if (s[i] >= 'a' && s[i] <= 'z') {
			cnt[s[i] - 'a']++; 
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			cnt[s[i] - 'A']++;
		}
	}

	int big = cnt[0]; // 'A'의 개수를 최대값으로 초기화
	int index = 0; // 개수가 최대인 알파벳의 index 저장
	bool flag = false; // 개수가 최대인 알파벳이 여러개인지 확인

	for (int i = 1; i < 'z' - 'a' + 1; i++) { // 26개 알파벳 탐색
		if (cnt[i] == big && big != 0) { // 개수가 같은 알파벳이 있고 그 수가 0이 아닐 경우 flag를 true로 변경
			flag = true;
			continue;
		}
		if (cnt[i] > big) { // 더 큰 수가 나오면 최댓값과 index 변경, flag를 false로 변경
			flag = false;
			big = cnt[i];
			index = i;
		}
	}
	if (flag) // flag가 true일 경우 최댓값인 알파벳이 여러 개이므로 '?' 출력
		cout << '?' << '\n';
	else // false일 경우 알파벳 출력
		cout << (char)('A' + index) << '\n';

	return 0;
}