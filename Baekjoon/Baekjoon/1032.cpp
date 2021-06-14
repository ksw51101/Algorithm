#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> vec;
string ans = "";

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}
	int len = vec[0].size();

	for (int i = 0; i < len; i++) {
		bool flag = true;
		for (int j = 1; j < n; j++) {
			if (vec[j][i] != vec[j - 1][i]) // i번째 문자가 모두 같으면 flag는 true를 유지, 하나라도 다르면 false로 변경
				flag = false;
		}
		if (flag) // i번째 문자가 모두 같으면 해당 문자를 그대로 사용
			ans += vec[0][i];
		else // 하나라도 다르면 ? 사용
			ans += '?';
	}
	cout << ans << '\n';

	return 0;
}