#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string s;
vector<char> vec;
int sum = 0;

int main() {
	cin >> s;
	
	for (int i = 0; i < s.length(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			vec.push_back(s[i]);
		else if (s[i] >= '0' && s[i] <= '9')
			sum += s[i] - '0';
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i];
	cout << sum << '\n';

	return 0;
}