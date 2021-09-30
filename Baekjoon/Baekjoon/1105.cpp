#include <iostream>
#include <string>
using namespace std;

string l, r;
int ans;

int main() {
	cin >> l >> r;

	if (l.size() != r.size()) // 자리수가 다르면 '8'이 0개인 경우가 존재
		ans = 0;
	else {
		int cnt = 0;
		for (int i = 0; i < l.size(); i++) { // 자리수가 같으면 맨 앞에서부터 서로 다른 수가 나올때까지의 '8'의 개수가 정답
			if (l[i] != r[i])
				break;
			if (l[i] == '8') cnt++;				
		}
		ans = cnt;
	}
	cout << ans << '\n';

	return 0;
}