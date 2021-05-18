#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k;

	cin >> k;
	stack<int> s;
	for (int i = 0; i < k; i++) {
		int temp;
		cin >> temp;
		if (temp != 0) 
			s.push(temp);
		else {
			s.pop();
		}
	}
	int sum = 0;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		sum += s.top();
		s.pop();
	}
	cout << sum << '\n';

	return 0;
}