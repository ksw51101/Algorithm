#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

int main() {

	while (1) {
		stack<char> s;
		bool ans = true;
		getline(cin, str);
		if (str == ".")
			break;
		for (int i = 0; i < str.size(); i++) {
			char temp = str[i];
			if (temp == '(')
				s.push(temp);
			else if (temp == ')') {
				if (s.empty() || s.top() == '[') {
					ans = false;
					break;
				}
				else if (s.top() == '(')
					s.pop();
			}
			else if (temp == '[')
				s.push(temp);
			else if (temp == ']') {
				if (s.empty() || s.top() == '(') {
					ans = false;
					break;
				}
				else if (s.top() == '[')
					s.pop();
			}
		}
		if (ans && s.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}

	return 0;
}