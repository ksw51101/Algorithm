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
			if (vec[j][i] != vec[j - 1][i]) // i��° ���ڰ� ��� ������ flag�� true�� ����, �ϳ��� �ٸ��� false�� ����
				flag = false;
		}
		if (flag) // i��° ���ڰ� ��� ������ �ش� ���ڸ� �״�� ���
			ans += vec[0][i];
		else // �ϳ��� �ٸ��� ? ���
			ans += '?';
	}
	cout << ans << '\n';

	return 0;
}