#include <iostream>
#include <string>
using namespace std;

string s;

int main() {
	getline(cin, s); // 공백을 포함한 입력
	
	int cnt = 0; // 공백의 개수(맨앞, 맨뒤 제외)
	if (s != " ") { // 입력이 " "일 경우 단어의 개수는 0
		for (int i = 0; i < s.size(); i++)
			if (s[i] == ' ') {
				if (i != 0 && i != s.size() - 1) // 공백이 맨앞, 맨뒤가 아니면 cnt++
					cnt++;
			}
		cnt++; // 단어의 개수는 공백의 개수+1
	}
	cout << cnt << '\n';

	return 0;
}