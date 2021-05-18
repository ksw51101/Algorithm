#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, arr[100000];
stack<int> s;
vector<char> vec;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int index = 0;
	for (int j = 1; j <= n; j++) {
		vec.push_back('+');
		s.push(j);

		if (s.top() == arr[index])
			while (s.top() == arr[index]) {
				vec.push_back('-');
				s.pop();
				index++;
				if (s.empty())
					break;
			}
	}
	if (!s.empty())
		cout << "NO" << '\n';
	else
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << '\n';

	return 0;
}